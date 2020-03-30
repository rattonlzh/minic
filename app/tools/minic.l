/*
 *Copyright (c) 2020 scnu-17-cs-group*
 *Filename: minic.l
 *Description: lex源文件,通过正则表达式和动作函数定义词法,使用lex工具编译生成lex.yy.c文件
 *Version : 1.0
 *Author: 梁泽浩
 *Created date: 3月28日
 */
%{
#define YYSTYPE char*
#include "y.tab.h"
#include <stdio.h>
#include <string.h>
#define MYECHO(a) printf("%s : %s\n", yytext, a);

%}

letter [a-zA-Z]
digit [0-9]
ID {letter}+
NUM {digit}+
whitespace [" "\n\t]
undefined .
/*注释的正则表达式很可能有问题,重点测试这个" */
%%
{whitespace} {/* blank */}
"/*" {
    int c;
    while ((c = input()) != 0) {
        if (c == '*') {
            if (( c = input()) == '/' || c == 0) {
                break;
            }
        }
    }
    printf("COMMENT\n");

}
"else" {
    MYECHO("ELSE")
    return ELSE;
}
"if" {
    MYECHO("IF")
    return IF;
}
"int" {
    MYECHO("INT")
    return INT;
}
"return" {
    MYECHO("RETURN")
    return RETURN;
} 
"void" {
    MYECHO("VOID")
    return VOID;
}
"while" {
    MYECHO("WHILE")
    return WHILE;
}
"=" {
    MYECHO("ASSIGN")
    return ASSIGN;
}
">" {
    MYECHO("GT")
    return GT;
}
">=" {
    MYECHO("GE")
    return GE;
}
"<" {
    MYECHO("LT")
    return LT;
}
"<=" {
    MYECHO("LE")
    return LE;
}
"==" {
    MYECHO("EQ")
    return EQ;
}
"!=" {
    MYECHO("NE")
    return NE;
}
"(" {
    MYECHO("LEFTP")
    return LEFTP;
}
")" {
    MYECHO("RIGHTP")
    return RIGHTP;
}
"[" {
    MYECHO("LEFTS")
    return LEFTS;
}
"]" {
    MYECHO("RIGHTS")
    return RIGHTS;
}
"{" {
    MYECHO("LEFTB")
    return LEFTB;
}
"}" {
    MYECHO("RIGHTB")
    return RIGHTB;
}
"," {
    MYECHO("COMMA")
    return COMMA;
}
";" {
    MYECHO("SEMICOLON")
    return SEMICOLON;
}
"+" {
    MYECHO("ADD")
    return ADD;
}
"-" {
    MYECHO("SUB")
    return SUB;
}
"*" {
    MYECHO("MUL")
    return MUL;
}
"/" {
    MYECHO("DIV")
    return DIV;
}
{ID} {
    yylval = strdup(yytext);
    MYECHO("ID")
    return ID;
}
{NUM} {
    yylval = strdup(yytext);
    MYECHO("NUM")
    return NUM;
}
{undefined} {
    MYECHO("UNDEFINED")
}
%%
int yywrap()
{
    return 1;
}
