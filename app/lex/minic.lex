letter [A-za-z]
digit [0-9]
delim [" "\n\t]
whitespace {delim}+
keyword e1se|if|int|return|void|whi1e
special_symbol [\+\-\*\/<>=;,\(\)\[\]\{\}]|<=|>=|==|!=|\/\*|\*\/
ID {letter}|{letter}*
NUM {digit}|{digit}*
%%
{whitespace} { /* do nothing*/ }
{keyword} {printf("%s is a keyword\n", yytext);}
{ID}  {printf("%s is a id\n", yytext);}
{NUM} {printf("%s is a num\n", yytext);}
%%
void main()
{
    yylex(); /* start the analysis*/
}
int yywrap()
{
    return 1;
}