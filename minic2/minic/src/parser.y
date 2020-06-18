/**
 * Copyright: Copyright (c) 2020 SCNU Compiler Principle Project Group. All rights reserved.
 * FilePath: /minic/parser.y
 * Description: 定义minic的产生式及产生式规则的yacc语法文件,包含了构造语法树的动作
 * Version: 1.0
 * Author: Liang Zehao, Zhang Yongbiao
 * Date: 2020-06-17 12:52:55
 * LastEditTime: 2020-06-18 22:27:05
 * LastEditors: Liang Zehao
 */

%error-verbose
%locations
/* 在.y文件中加入％locations，bison加入－d编译后的.h符号表文件中
 * 会多出一个YYLTYPE结构体定义和一个该结构体类型的全局变量yylloc，
 * 这样，.l文件include该.h文件后，该结构体类型就可以被flex知道，
 * 且flex可以向yylloc里面填入信息。
 */
%{
/*distinguishes Yacc output from other code files*/
#define YYPARSER 

#include "globals.h"
#include "util.h"

/*extern int  yylineno; 提供当前的行数信息*/
extern char *yytext; /*匹配模式的文本存储在这一变量中（char*）*/
extern FILE *yyin; /*FILE*类型，指向lexer正在解析的当前文件*/

//#define YYSTYPE TokenStruct

TreeNode * parseTree; /*stores syntax tree for later return*/
void yyerror(const char* message, ...);

%}

%union { 
	struct treeNode * node;
    int op; 
	int val; 
	char name[256];
};

// %type 定义非终结符的语义值类型
%type<node> program declaration_list declaration 
%type<node> var_declaration type_specifier fun_declaration compound_stmt
%type<node> params param_list param
%type<node> local_declarations statement_list statement
%type<node> expression_stmt selection_stmt iteration_stmt return_stmt
%type<node> expression var simple_expression additive_expression
%type<node> term factor call args arg_list

%type<op> relop addop mulop

/* %token 定义终结符的语义值类型
 * bison带-d编译时，生成的*.tab.h中给这些单词进行编码，
 * 可在.l中包含*.tab.h使用这些单词种类码
 */
%token ERROR
%token IF ELSE INT VOID WHILE RETURN
%token<name> ID 
%token<val> NUM
%token ASSIGN
%token EQ NEQ LTEQ GTEQ LT GT
%token PLUS MINUS TIMES OVER
%token LP RP LB RB LC RC
%token SEMI COMMA
%token PLUS MINUS
%token TIMES OVER
%token EQ NEQ LTEQ GTEQ LT GT
%token ASSIGN

// 不可结合
%nonassoc WITHOUT_ELSE /*解决二义性*/
%nonassoc ELSE

%%

 /*1、开始符 program→ declaration-list */
program: declaration_list 
		{	parseTree = $1; 
			YYACCEPT; /* 在动作中使yyparse()以一个零值立即返回，显示成功。*/ 
		}
		;

 /*2、声明列表 declaration-list→ declaration-list declaration | declaration */
declaration_list: declaration_list declaration 
				{ 
					TreeNode * t = $1;
					if (t != NULL) {
						while (t->sibling != NULL) t = (TreeNode *) t->sibling;
						t->sibling = $2;
						$$ = $1;
					} else {
						$$ = $2;
					}
				}
				| declaration { $$ = $1; }
				;

 /*3、声明 declaration→ var-declaration | fun-declaration */
declaration: var_declaration { $$ = $1; }
			| fun_declaration { $$ = $1; }
			;

 /*4、变量声明 var-declaration→ type-specifier ID; | type-specifier ID[NUM]; */
var_declaration: type_specifier ID SEMI
				{
					$$ = (TreeNode *) newDeclNode(VarK);
					$$->child[0] = $1;
					$$->lineno = lineno;
					strcpy($$->attr.name, $2);
				}
				| type_specifier ID LB NUM RB SEMI
				{
					$$ = (TreeNode *) newDeclNode(ArrVarK);
					$$->child[0] = $1;
					$$->lineno = lineno;
					strcpy($$->attr.arr.name, $2);
					$$->attr.arr.size = $4;
				}
				;

 /*5、类型说明 type-specifier→ int | void  */
type_specifier: INT { $$ = newTypeNode(TypeNameK); $$->attr.type = INT; }
				| VOID { $$ = newTypeNode(TypeNameK); $$->attr.type = VOID; }
				;

 /*6、函数声明 fun-declaration→ type-specifier ID( params ) compound-stmt */
fun_declaration: type_specifier ID LP params RP compound_stmt
				{
					$$ = (TreeNode *) newDeclNode(FuncK);
					$$->lineno = lineno;
					strcpy($$->attr.name, $2);
					$$->child[0] = $1; /* return type */
					$$->child[1] = $4; /* parameters */
					$$->child[2] = $6; /* body */
				}
				;

 /*7、函数参数 params→ param-list | void */
params: param_list { $$ = $1; }
		| VOID { $$ = newTypeNode(TypeNameK); $$->attr.type = VOID; }
		;

 /*8、参数列表 param-list→ param-list, param | param */
param_list: param_list COMMA param
			{
				TreeNode *t = $1;
				if (t != NULL) {
					while (t->sibling != NULL) t = (TreeNode *) t->sibling;
					t->sibling = $3;
					$$ = $1;
				} else {
					$$ = $3;
				}
			}
			| param { $$ = $1; }
			;

 /*9、参数 param→ type-specifier ID | type-specifier ID[] */
param: type_specifier ID 
		{
			$$ = (TreeNode *) newParamNode(NonArrParamK);
			$$->child[0] = $1;
			strcpy($$->attr.name, $2);
		}
		| type_specifier ID LB RB { 
            $$ = (TreeNode *) newParamNode(ArrParamK);
			$$->child[0] = $1;
			strcpy($$->attr.name, $2); 
        };

 /*10、复合语句 compound-stmt→ { local-declarations statement-list } */
compound_stmt: LC local_declarations statement_list RC
				{
					$$ = newStmtNode(CompK);
                	$$->child[0] = $2; /* local variable declarations */
                	$$->child[1] = $3; /* statements */
				}
				;

 /*11、局部声明 local-declarations→ local-declarations var-declaration | empty */
local_declarations: local_declarations var_declaration
					{
						TreeNode *t = $1;
						if (t != NULL) {
							while (t->sibling != NULL) t = (TreeNode *) t->sibling;
							t->sibling = $2;
							$$ = $1;
						} else {
							$$ = $2;
						}
					}
					| { $$ = NULL; }
					;

 /*12、语句列表 statement-list→ statement-list statement | empty */
statement_list: statement_list statement
				{
					TreeNode *t = $1;
					if (t != NULL) {
						while (t->sibling != NULL) t = (TreeNode *) t->sibling;
						t->sibling = $2;
						$$ = $1;
					} else {
						$$ = $2;
					}
				}
				| { $$ = NULL; }
				;

 /*13、语句 statement→ expression-stmt  
						| compound-stmt  
						| selection-stmt  
						| iteration-stmt  
						| return-stmt
						*/
statement: expression_stmt { $$ = $1; }
			| compound_stmt { $$ = $1; }
			| selection_stmt { $$ = $1; }
			| iteration_stmt { $$ = $1; }
			| return_stmt { $$ = $1; }
			;

 /*14、表达式语句expression-stmt→ expression; | ; */
expression_stmt: expression SEMI { $$ = $1; }
				| SEMI { $$ = NULL; }
				;

 /*15、选择语句 selection-stmt→ if(expression) statement  
								| if(expression)statement else statement */
selection_stmt: IF LP expression RP statement %prec WITHOUT_ELSE
				{
					$$ = (TreeNode *) newStmtNode(IfK);
					$$->child[0] = $3;
					$$->child[1] = $5;
				}
				| IF LP expression RP statement ELSE statement
				{
					$$ = (TreeNode *) newStmtNode(IfK);
					$$->child[0] = $3;
					$$->child[1] = $5;
					$$->child[2] = $7;
					// $$->sibling = $7;
					// $$->sibling->kind = IfK;
				}
				;

 /*16、迭代语句 iteration-stmt→ while (expression) statement */
iteration_stmt: WHILE LP expression RP statement
				{
					$$ = (TreeNode *) newStmtNode(IterK);
					$$->child[0] = $3;
					$$->child[1] = $5;
				}
				;

 /*17、返回语句 return-stmt→ return ; | return expression; */
return_stmt: RETURN SEMI { $$ = (TreeNode *) newStmtNode(RetK); }
			| RETURN expression SEMI
			{
				$$ = (TreeNode *) newStmtNode(RetK);
				$$->child[0] = $2;
			}
			;

 /*18、表达式 expression→ var = expression | simple-expression */
expression: var ASSIGN expression
			{
				$$ = (TreeNode *) newExpNode(AssignK);
				$$->child[0] = $1;
				$$->child[1] = $3;
			}
			| simple_expression { $$ = $1; }
			;

 /*19、变量 var→ ID | ID[expression] */
var: ID 
	{
		$$ = (TreeNode *) newExpNode(IdK);
		strcpy($$->attr.name, $1);
	}
	| ID LB expression RB
	{
		$$ = (TreeNode *) newExpNode(ArrIdK);
		strcpy($$->attr.name, $1); 
		$$->child[0] = $3; 
	}
	;

 /*20、简单表达式 simple-expression→ additive-expression relop additive-expression  
									| additive-expression */
simple_expression: additive_expression relop additive_expression
					{
						$$ = (TreeNode *) newExpNode(OpK);
						$$->attr.op = $2;
						$$->child[0] = $1;
						$$->child[1] = $3;
					}
					| additive_expression { $$ = $1; }
					;

 /*21、关系操作符 relop→ <= | < | > | >= | == | != */
relop: EQ { $$ = EQ; }
	| NEQ { $$ = NEQ; }
	| LTEQ { $$ = LTEQ; }
	| GTEQ { $$ = GTEQ; }
	| LT { $$ = LT; }
	| GT { $$ = GT; }
	;

 /*22、additive-expression→ additive-expression addop term | term */
additive_expression: additive_expression addop term
					{
						$$ = (TreeNode *) newExpNode(OpK);
						$$->attr.op = $2;
						$$->child[0] = $1;
						$$->child[1] = $3;
					}
					| term { $$ = $1; }
					;

 /*23、adop→ + | - */
addop: PLUS { $$ = PLUS; }
		| MINUS { $$ = MINUS; }
		;

 /*24、term→ term mulop factor | factor */
term: term mulop factor
		{
			$$ = (TreeNode *) newExpNode(OpK);
			$$->attr.op = $2;
			$$->child[0] = $1;
			$$->child[1] = $3;
		}
		| factor { $$ = $1; }
		;

 /*25、mulop→ * | / */
mulop: TIMES { $$ = TIMES; }
		| OVER { $$ = OVER; }
		;

 /*26、factor→ (expression) | var | call | NUM */
factor: LP expression RP { $$ = $2; }
		| var { $$ = $1; }
		| call { $$ = $1; }
		| NUM { $$ = (TreeNode *) newExpNode(ConstK);
				$$->attr.val = $1; }
		;

 /*27、函数调用 call→ ID(args) */
call: ID 
	{
		$<node>$ = (TreeNode *) newExpNode(CallK);
		strcpy($<node>$->attr.name, $1);
	}
	LP args RP
	{
		$$ = $<node>2;
		$$->child[0] = $4; 
	}
	;

 /*28、args→ arg-list | empty */
args: arg_list { $$ = $1; }
		| { $$ = NULL; }
		;
		

 /*29、arg-list→ arg-list, expression | expression */
arg_list: arg_list COMMA expression
		{
			TreeNode *t = $1;
			if (t != NULL) {
				while (t->sibling != NULL) t = (TreeNode *) t->sibling;
				t->sibling = $3;
				$$ = $1;
			} else {
				$$ = $3;
			}
		}
		| expression { $$ = $1; }
		;

%%


/**
 * @brief 在main函数中调用，进行语法分析，生成语法树
 * @param {FILE *} source 语法分析的源文件
 * @return: TreeNode * 语法树
 */
TreeNode * parse( FILE * source ) {
	yyin = source;
	yyparse();
	return parseTree;
}

/**
 * @brief 打印语法分析错误的具体位置和出错原因
 * @param {const char* message, ...} 
 * @return: 
 */
#include<stdarg.h> 
void yyerror(const char* message, ...)
{
	fprintf(listing, "Error at Line %d Column %d: ", yylloc.first_line, yylloc.first_column);
	va_list ap; // 指向参数的指针
    va_start(ap, message); // 宏初始化
	vfprintf(listing, message, ap);
	va_end(ap);
    fprintf(listing, ".\n");
	Error = TRUE;
}

