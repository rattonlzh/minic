%{
#include "globals.h"
#include "util.h"

#include "y.tab.h"

/* 在yylex()每一次识别一个token后，语义执行之前，都将执行该宏中的代码，
 * 把当前token的行信息和该token第一个和最后一个字符所在列信息填入YYLTYPE结构体，
 * 用于yyerror打印错误信息的位置。
 */
int yycolumn = 1;
#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = lineno; \
                        yylloc.first_column = yycolumn;	\
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

/* 为bison提供行号信息 */
/* %option yylineno */

INTEGER [0-9]+
IDENTIFIER [A-Za-z]+
WHITESPACE [ \t]+
NEWLINE (\r\n)|[\r\n]
%%

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
"/*"              { /* 多行注释 */
                    char c; char d;
                    c = input();
                    if(c != EOF) {
                        do {
                            d = c;
                            c = input();
                            if (c == EOF) break;
                            if (c == '\n') lineno++;
                            } while (!(d == '*' && c == '/'));
                    }
                    yycolumn = 1;
                  }

{NEWLINE}         { yycolumn = 1; lineno++; }
{WHITESPACE}           { /* \x20 空格; \r 回车 */ }
.                 { fprintf(listing, "Error: \"%s\"\n\t at Line %d\n", yytext, lineno); return ERROR; }

%%

/*
 * "{"[^}\n]*"}"                      {}
 * \/\*(?:[^\*]|\*+[^\/\*])*\*+\/     {}
 */

 
TokenType getToken(void) {
    char tokenString[MAXTOKENLEN+1];
    tokenString[MAXTOKENLEN]='\0';

    static int firstTime;
    firstTime = TRUE;
    TokenType curToken;
    if (firstTime) {
        firstTime = FALSE;
        lineno++;
        yyin = source;
        yyout = listing;
    }
    curToken = yylex();
    strncpy(tokenString, yytext, MAXTOKENLEN);
    if (TraceScan) {
        fprintf(listing, "\t%d: ", lineno);
        printToken(curToken, tokenString);
    }
    return curToken;
}


/*
int main(int argc,char **argv) {
    ++argv;
    --argc;
    if (argc > 0) 
        yyin = fopen(argv[0], "r");
    else 
        yyin = stdin;
    yylex();
    return 0;
}
*/

/* 这一函数在文件（或输入）的末尾调用。
 * 如果函数的返回值是1，就停止解析。 
*/
int yywrap()
{
    return 1;
}