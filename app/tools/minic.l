%{
#include "y.tab.h"
#include <stdio.h>
#include <string.h>
%}

letter [a-zA-Z]
digit [0-9]
ID {letter}+
NUM {digit}+
whitespace [' '\n\t]
comment \/\*([^\*]*\*+[^*/])+\/|\/\*([^\*]*\*+\/
/*注释的正则表达式很可能有问题,重点测试这个 */
%%
{ID} {
    yylval = strdup(yytext);
    return ID;
    }
{NUM} {
    yylval = strdup(yytext);
    return NUM;
}
{comment} {
    printf("this is a comment:%s", yytext);
}
else {
    return ELSE;
}
if {
    return IF;
}
int {
    return INT;
}
return {
    return RETURN;
} 
void {
    return VOID;
}
while {
    return WHILE;
}

%%
int yywrap()
{
return 1;
}
