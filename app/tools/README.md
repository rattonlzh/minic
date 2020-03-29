``` lex
%{
    #include <stdio.h> 
    int wordCount = 0;
%}
chars [A-za-z\_\'\.\"]
numbers ([0-9])+
delim [" "\n\t]
whitespace {delim}+
words {chars}+
%%
{words} { wordCount++; /*increase the word count by one*/ 
printf(" No of words:%d\n", wordCount);}
{whitespace} { /* do nothing*/ }
{numbers} { /* one may want to add some processing here*/ }
%%
void main()
{
    yylex(); /* start the analysis*/
    printf(" No of words:%d\n", wordCount);
}
int yywrap()
{
    return 0;
}
```
自动生成yylex()的定义, 不断获取输入,直到遇到结束符,遇到结束符后调用`yywrap()`,返回1是停止解析,可以在`yywrap()`用文件指针指向其他文件,继续解析
``` y
%{
typedef char* string;
#define YYSTYLE string
%}
%token ID NUM keyword
%start declaration-list
%%
declaration-list : declaration-list declaration | fun-declaration
program : declaration-list {printf("program started.\n");}
var-declaration : type-specifier ID; | type-specifier ID[NUM];
type-specifier : int|void
fun-declaration : type-specifier ID (params) compound-stmt
params : param-list|void
param-list : param-list, param | param
param : type-specifier ID | type-specifier ID[]
compound-stmt : { local-declarations statement-list }
local-declarations : local-declarations var-declaration | empty
statement-list : statement-list statement | empty
statement : expression-stmt | compound-stmt | selection-stmt | iteration-stmt | return-stmt
expression-stmt : expression; | ;
selection-stmt : if (expression) statement | if (expression) statement else statement
iteration-stmt : while (expression) statement
return-stmt : return; | return expression;
expression : var = expression | simple-expression
var : ID | ID[expression]
simple-expression : additive-expression relop additive-expression | additive-expression
relop : <= | < | > | >= | == | !=
additive-expression : additive-expression addop term | term
addop term | term
addop : + | -
term : term mulop factor | factor
mulop : * | /
factor : (expression) | var | call | NUM
call : ID(args)
args : arg-list | empty
empty : ""
arg-list : arg-list, expression | expression
%%
void main()
{
    yyparse();
}
int yyerror(char* msg)
{
    printf("Error: %s
    encountered at line number:%d\n", msg, yylineno);
}
```
token名字不能起c语言的特殊符号(如if之类的关键字,否则会解析出错)
yyparse()会不断调用yylex()获取token直到yylex()遇到结束符.
在yacc源文件中
%left ’+’ ’–’
%left ’*’ ’/’
`%left`表示左结合,同一行声明的操作符的优先级相同,对于多行的声明,越往下,优先级越高,如`*`,`/`在`+`,`-`的下面,显式指出了`*`,`/`的优先级比上面的`+`,`-`高
`%right`表示右结合,`%nonassoc`表示不允许结合,如`%nonassoc '<'`表示 A < B < C的表达是不被允许的
对于悬挂else问题,yacc默认使用LALR分析,会向前查看一个字符隐式解决冲突,但是在生成c文件时依然会汇报存在移进规约冲突的诊断信息,如不想看到此诊断信息,可以显式解决冲突,如果不改造文法,最简单的方式是使用`%prec`提高某个规则的优先级,遇到歧义的时候优先匹配此规则,例子如下
``` yacc
if_stmnt : IF stmnt %prec REDUCE
{ printf("simple if");}
| IF stmnt ELSE stmnt
{ printf("if_then_else");}
;
```

``` yacc
stat : error
{
....
yyerrok ;
yyclearin;
}
;
```
如果规约出错进行一些处理,然后使用宏`yyerrok ;`告诉yacc错误处理完毕了继续工作吧
`yyclearin ;`将旧的向前查看的字符清除

词法分析的难点在于注释的正则表达式