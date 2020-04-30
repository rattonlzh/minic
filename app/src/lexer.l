/**
 * @file: lexer.l
 * @author: Liang Zehao
 * @brief: lex源文件,通过正则表达式和动作函数定义词法,使用flexc++工具编译生成扫描器的C++类
 *
 * @version : 1.4
 * @date: 2020.04.24 
 *
 * @copyright Copyright (c) 2020
 *
 */
%%
[ \t\r\n]+ // nothing to do
"/*" {
// 吃掉注释
size_t ch = 0;
// 不断获取输入
while (ch = get__()) {
    // 如果读到*， 则把后面连续的*都取走，如果第一个非*字符是/,说明匹配到了*/,注释结束
    if (ch == '*') {
        while((ch = get__()) == '*')
            ;
        if (ch == '/' || ch == 0) {
            break;
        }
    }

}
}
"else" {
   return ParserBase::ELSE;
}
"if" {
    return ParserBase::IF;
}
"int" {
    return ParserBase::INT;
}
"return" {
    return ParserBase::RETURN;
} 
"void" {
    return ParserBase::VOID;
}
"while" {
    return ParserBase::WHILE;
}
"=" {
    return ParserBase::ASSIGN;
}
">" {
    return ParserBase::GT;
}
">=" {
    return ParserBase::GE;
}
"<" {
    return ParserBase::LT;
}
"<=" {
    return ParserBase::LE;
}
"==" {
    return ParserBase::EQ;
}
"!=" {
    return ParserBase::NE;
}
"(" {
    return ParserBase::LEFTP;
}
")" {
    return ParserBase::RIGHTP;
}
"[" {
    return ParserBase::LEFTS;
}
"]" {
    return ParserBase::RIGHTS;
}
"{" {
    return ParserBase::LEFTB;
}
"}" {
    return ParserBase::RIGHTB;
}
"," {
    return ParserBase::COMMA;
}
";" {
    return ParserBase::SEMICOLON;
}
"+" {
    return ParserBase::ADD;
}
"-" {
    return ParserBase::SUB;
}
"*" {
    return ParserBase::MUL;
}
"/" {
    return ParserBase::DIV;
}
[A-Za-z]+ {
   return ParserBase::ID;
}
[0-9]+ {
    return ParserBase::NUM;
}
. {
    throw std::invalid_argument("遇到未定义符号！");
}

