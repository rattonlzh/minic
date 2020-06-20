/**
 * Copyright: Copyright (c) 2020 SCNU Compiler Principle Project Group. All rights reserved.
 * FilePath: /minic/scanner.l
 * Description: lex源文件,定义minic需要用到的终结符
 * Version: 1.0
 * Author: Liang Zehao, Zhang Yongbiao
 * Date: 2020-06-17 12:52:55
 * LastEditTime: 2020-06-18 22:26:56
 * LastEditors: Liang Zehao
 */

%{
#include "globals.h"
#include "util.h"
#include "y.tab.h"

/* 在yylex()每一次识别一个token后，语义执行之前，都将执行该宏中的代码，
 * 把当前token的行信息和该token第一个和最后一个字符所在列信息填入YYLTYPE结构体，
 * 用于yyerror打印错误信息的位置。
 */
int yycolumn = 1;
#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = lineno;\
yylloc.first_column = yycolumn;\
yylloc.last_column = yycolumn + yyleng - 1; \
yycolumn += yyleng;

/* 重定义 YYSTYPE */
typedef union { 
	TreeNode *node;
    TokenType op; 
	int val;
	char name[256];
} YYLVAL;
#define YYSTYPE YYLVAL

%}
/*不处理多个文件*/
%option noyywrap
INTEGER [0-9]+
IDENTIFIER [A-Za-z]+
WHITESPACE [ \t]+
NEWLINE (\r\n)|[\r\n]
COMMENT "/*"([^\*]|(\*)*[^\*/])*(\*)*"*/" 
%%
"/*"              {
// 吃掉注释
size_t ch = 0;
// 不断获取输入
while ((ch = input())) {
    // 如果读到*， 则把后面连续的*都取走，如果第一个非*字符是/,说明匹配到了*/,注释结束
    if (ch == '*') {
        while((ch = input()) == '*') {
            if (ch == '\n') {
                ++lineno;
                yycolumn = 1;
            }
        }
        if (ch == '/') {
            break;
        }
        if (ch == 0) {
            fprintf(listing, "comment started at %d does not end correctly", lineno);
            return ERROR;
        }
    }else if (ch == '\n') {
        ++lineno;
        yycolumn = 1;
    }

}
}
"void"            { return VOID; }
"int"             { return INT; }
"if"              { return IF; }
"else"            { return ELSE; }
"while"           { return WHILE; }
"return"          { return RETURN; }
"+"               { return PLUS; }
"-"               { return MINUS; }
"*"               { return TIMES; }
"/"               { return OVER; }
"<"               { return LT; }
"<="              { return LTEQ; }
">"               { return GT; }
">="              { return GTEQ; }
"=="              { return EQ; }
"!="              { return NEQ; }
"="               { return ASSIGN; }
","               { return COMMA; }
";"               { return SEMI; }
"("               { return LP; }
")"               { return RP; }
"["               { return LB; }
"]"               { return RB; }
"{"               { return LC; }
"}"               { return RC; }
{INTEGER}         { yylval.val = atoi(yytext); return NUM; }
{IDENTIFIER}      { strcpy(yylval.name, yytext); return ID; }
{WHITESPACE}      { /* do nothing */ }
{NEWLINE}         { ++lineno;yycolumn = 1;}
.                 { 
    fprintf(listing, "Error: \"%s\"\n\t at Line %d\n", yytext, lineno);
    return ERROR;
}

%%



 
TokenType getToken(void) {
    char tokenString[MAXTOKENLEN+1];
    tokenString[MAXTOKENLEN]='\0';
    TokenType curToken;
    curToken = yylex();
    strncpy(tokenString, yytext, MAXTOKENLEN);
    if (TraceScan) {
        fprintf(listing, " %d: ", lineno);
        printToken(curToken, tokenString);
    }
    return curToken;
}

void init()
{
    yyin = source;
    yyout = listing;
}

