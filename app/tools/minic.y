%{
#define YYSTYPE char* /*a Yacc variable which has the value of returned token */
extern int yylineno;
%}
%token ELSE IF RETURN INT VOID WHILE ID NUM
%%


%%

int yyerror(char* msg)
{
    printf("Error: %s encountered at line number:%d\n", msg, yylineno);
    return 1;
}
