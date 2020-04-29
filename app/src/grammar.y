/**
 * @file grammar.y
 * @author Liang Zehao
 * @brief 定义语法分析需要的产生式，开始产生式，终端符号，非终端符号和语义动作
 * 
 * @version 0.1
 * @date 2020.04.21
 * 
 * @copyright Copyright (c) 2020
 *
 */
%no-lines
%scanner Scanner.ih
%token ELSE IF RETURN INT VOID WHILE ID NUM LEFTP RIGHTP LEFTS RIGHTS LEFTB RIGHTB COMMA SEMICOLON ADD SUB MUL DIV
%right ASSIGN
%nonassoc LT LE GT GE EQ NE
/**
 * 在ParserBase.h中插入头文件
 */
%baseclass-preinclude TreeUtil.h
/**
 * 定义非终结符和终结符的语义类型
 */
%stype TreeNode*

%%
program:
    declaration_list {
        $$ = TreeUtil::buildTree("程序", {$1});
        TreeUtil::printTree($$);
        TreeUtil::destroyTree($$);
    }
;

declaration_list:
    declaration_list declaration {
        $$ = TreeUtil::mergeTree($1, $2);
        
    }
    | declaration {
        $$ = $1;

    }
;

declaration:
    var_declaration {
        $$ = $1;

    }
    | fun_declaration {
        $$ = $1;
    }
;

var_declaration:
    type_specifier id SEMICOLON {
        $$ = TreeUtil::buildTree("变量声明", {$1, $2});

    }
    | type_specifier id LEFTS num RIGHTS SEMICOLON {
        $1->content += "[" + $4->content + "]";
        $$ = TreeUtil::buildTree("变量声明", {$1,$2});

    }
;

type_specifier:
    INT { 
        $$ = TreeUtil::buildTree("int");
    }
    | VOID { 
        $$ = TreeUtil::buildTree("void");
    }
;

fun_declaration:
    type_specifier id LEFTP params RIGHTP compound_stmt {
        TreeNode* tmp = TreeUtil::buildTree("参数", {$4});
        $$ = TreeUtil::buildTree("函数声明", {$1, $2, tmp, $6});
    }
;
params: 
    param_list {
        $$ = $1;
    }
    | VOID {
        $$ = TreeUtil::buildTree("void");
    }
;
param_list:
    param_list COMMA param {
        $$ = TreeUtil::mergeTree($1, $3);
    }
    | param {
        $$ = $1;
    }
;
param:
    type_specifier id {
        $$ = TreeUtil::buildTree("变量声明", {$1, $2});
    }
    | type_specifier id LEFTS RIGHTS {
        $1->content += "[]";
        $$ = TreeUtil::buildTree("变量声明", {$1, $2});
    }
;

compound_stmt:
    LEFTB local_declarations statement_list RIGHTB {
        $$ = TreeUtil::buildTree("{}", {$2, $3});
    }
;

local_declarations:
    local_declarations var_declaration {
        $$ = TreeUtil::mergeTree($1, $2);
    }
    | empty {
        $$ = nullptr;
    }
;

statement_list:
    statement_list statement {
        $$ = TreeUtil::mergeTree($1, $2);
    }
    | empty {
        $$ = nullptr;
    }
;

statement:
    expression_stmt {
        $$ = $1;
    }
    | compound_stmt {
        $$ = $1;
    }
    | selection_stmt {
        $$ = $1;
    }
    | iteration_stmt {
        $$ = $1;
    }
    | return_stmt {
        $$ = $1;
    }
;

expression_stmt:
    expression SEMICOLON {
        $$ = $1;
    }
    | SEMICOLON {
        $$ = nullptr;
    }
;

selection_stmt:
    IF LEFTP expression RIGHTP statement {
        $$ = TreeUtil::buildTree("if", {$3, $5});
    }
    | IF LEFTP expression RIGHTP statement ELSE statement {

        $$ = TreeUtil::buildTree("if", {$3, $5, $7});
    }
;

iteration_stmt:
    WHILE LEFTP expression RIGHTP statement {
        $$ = TreeUtil::buildTree("while", {$3, $5});
    }
;

return_stmt:
    RETURN SEMICOLON {
        $$ = TreeUtil::buildTree("return");
    }
    | RETURN expression SEMICOLON {
        $$ = TreeUtil::buildTree("return", {$2});
    }
;

expression:
    var ASSIGN expression {
        $$ = TreeUtil::buildTree("=", {$1, $3});
    }
    | simple_expression {
        $$ = $1;
    }
;

var:
    id {
        $$ = $1;
    } 
    | id LEFTS expression RIGHTS {
        $$ = TreeUtil::buildTree("[]", {$1, $3});
    }
;
simple_expression:
    additive_expression relop additive_expression {
        $$ = TreeUtil::buildTree($2, {$1, $3});
    }
    | additive_expression {
        $$ = $1;
    }
;
relop:
    LE { 
        $$ = TreeUtil::buildTree("<=");
    }
    | LT { 
        $$ = TreeUtil::buildTree("<");
    }
    | GT {
        $$ = TreeUtil::buildTree(">");
    }
    | GE {
        $$ = TreeUtil::buildTree(">=");
    }
    | EQ {
        $$ = TreeUtil::buildTree("==");
    }
    | NE {
        $$ = TreeUtil::buildTree("!=");
    }
;
additive_expression:
    additive_expression addop term {
        $$ = TreeUtil::buildTree($2, {$1, $3});
    }
    | term  {
        $$ = $1;
    }
;
addop:
    ADD { 
        $$ = TreeUtil::buildTree("+");
    }
    | SUB { 
        $$ = TreeUtil::buildTree("-");
    }
;

term:
    term mulop factor {
        $$ = TreeUtil::buildTree($2, {$1,$3});
    }
    | factor {
        $$ = $1;
    }
;

mulop:
    MUL {
        $$ = TreeUtil::buildTree("*");
    }
    | DIV {
        $$ = TreeUtil::buildTree("/");
    }
;

factor:
    LEFTP expression RIGHTP {
        $$ = $2;
    }
    | var {
        $$ = $1;
    }
    | call {
        $$ = $1;
    }
    | num { 
        $$ = $1;
    }
;

call:
    id LEFTP args RIGHTP {
        $$ = TreeUtil::buildTree("call", {$1, $3});
    }
;

args:
    arg_list {
        $$ = TreeUtil::buildTree("参数", {$1});
    }
    | //empty 
;

arg_list:
    arg_list COMMA expression {
        $$ = TreeUtil::mergeTree($1, $3);
    }
    | expression {
        $$ = $1;
    }
;

id:
    ID {
        $$ = TreeUtil::buildTree(d_scanner.matched());
    }
;

num:
    NUM {
        $$ = TreeUtil::buildTree(d_scanner.matched());
    }
;

empty:
    // empty
;