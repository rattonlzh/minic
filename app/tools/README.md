# 构建说明
编辑好`minic.l`和`minic.y`文件后,输入构建命令`lex minic.l && yacc minic.y`产生`lex.yy.c`,`y.tab.h`,`y.tab.c`三个文件
在主函数中调用`yyparse()`开始语法分析过程
gcc编译命令`gcc lex.yy.c -o scanner`
# LEX和YACC的简单理解
lex源文件示例如下:
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
解释:
编译lex文件可以自动生成yylex()的定义, 不断获取输入,直到遇到结束符,遇到结束符后调用`yywrap()`,返回1是停止解析,可以在`yywrap()`用文件指针指向其他文件,继续解析

yacc源文件例子
``` yacc
%{
#include <stdio.h>
%}
%token SIMPLE IF ELSE
%%
S ; stmnt
;
stmnt : SIMPLE
| if_stmnt
;
if_stmnt : IF stmnt
{ printf("simple if\n");}
| IF stmnt ELSE stmnt
{ printf("if_then_else\n");}
;
%%
int yylex() 
{
    int c;
    c=getchar();
    if (c= =EOF) return 0;
    else switch(c) 
        {
            case ’i’: return IF;
            case ’s’: return SIMPLE;
            case ’e’: return ELSE;
            default: return c;
        }
}
```
注意:
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
`%prec`后面跟一个token名字或者一个字符,`%prec`放在语法规则后面,action或者`;`之前,如下
``` yacc
%left ’+’ ’–’
%left ’*’ ’/’
%%
expr : expr ’+’ expr
| expr ’–’ expr
| expr ’*’ expr
| expr ’/’ expr
| ’–’ expr %prec ’*’
| NAME
;
```
此操作将`expr : ’–’ expr`规则的优先级视为与`*`的优先级一致

出错处理:
``` yacc
stat : error
{
....
yyerrok ;
yyclearin;
}
;
```
如果规约出错进行一些处理,然后使用宏`yyerrok ;`告诉yacc错误处理完毕可以继续工作
`yyclearin ;`将旧的向前查看的字符清除

词法分析的难点在于注释的正则表达式
yacc中不允许名字带有`-`,这个要注意

错误提示:
```
declaration_list:declaration_list declaration
| declaration
;
```
误写成了
```
declaration_list:declaration_list declaration
;
```
会提示
```
minic.y:7.1-7: fatal error: start symbol program does not derive any sentence
program:declaration_list
```
可能是其中一个非终结符对应的产生式规则有问题