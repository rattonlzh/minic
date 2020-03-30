#include "lex.yy.h"
void main()
{
    // 持续从标准输入获取字符并解析
    while (yylex() != 0)
        ;
}