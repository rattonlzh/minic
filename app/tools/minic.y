/*
 *Copyright (c) 2020 scnu-17-cs-group*
 *Filename: minic.y
 *Description: 定义语法和语义动作的yacc源文件
 *Version : 1.0
 *Author: 梁泽浩
 *Created date: 2020-03-29
 */
%{
    extern int yylineno;
%}
%token ELSE IF RETURN INT VOID WHILE ID NUM  LT LE GT GE EQ NE LEFTP RIGHTP LEFTS RIGHTS LEFTB RIGHTB COMMA SEMICOLON ADD SUB MUL DIV
%right ASSIGN
%%
program:declaration_list
;
declaration_list:declaration_list declaration
| declaration
;
declaration:var_declaration 
| fun_declaration
;
var_declaration:type_specifier ID SEMICOLON
| type_specifier ID[NUM]
;
type_specifier:INT
|VOID
;
fun_declaration:type_specifier ID LEFTP params RIGHTP compound_stmt
;
params:param_list
|VOID
;
param_list:param_list COMMA param 
| param
;
param:type_specifier ID 
| type_specifier ID LEFTS RIGHTS
;
compound_stmt:LEFTB local_declarations statement_list RIGHTB
;
local_declarations:local_declarations var_declaration 
| empty
;
statement_list:statement_list statement 
| empty
;
statement:expression_stmt 
| compound_stmt 
| selection_stmt 
| iteration_stmt 
| return_stmt
;
expression_stmt:expression SEMICOLON 
| SEMICOLON
;
selection_stmt:IF LEFTP expression RIGHTP statement 
| IF LEFTP expression RIGHTP statement ELSE statement
;
iteration_stmt:WHILE LEFTP expression RIGHTP statement
;
return_stmt:RETURN SEMICOLON 
| RETURN expression SEMICOLON
;
expression:var ASSIGN expression 
| simple_expression
;
var:ID 
| ID LEFTS expression RIGHTS
;
simple_expression:additive_expression relop additive_expression 
| additive_expression
;
relop:LE 
| LT 
| GT 
| GE 
| EQ 
| NE
;
additive_expression:additive_expression addop term 
| term addop term 
| term
;
addop:ADD
| SUB
;
term:term mulop factor 
| factor
;
mulop:MUL 
| DIV
;
factor:LEFTP expression RIGHTP 
| var 
| call 
| NUM
;
call:ID LEFTP args RIGHTP
;
args:arg_list | empty
;

arg_list:arg_list COMMA expression 
| expression
;
empty: ;
%%

int yyerror(char* msg)
{
    printf("Error:%s encountered at line number:%d\n", msg, yylineno);
    return 1;
}
