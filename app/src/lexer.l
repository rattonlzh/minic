/*
 *Copyright (c) 2020 scnu-17-cs-ratton&bill
 *Filename: lexer.l
 *Description: lex源文件,通过正则表达式和动作函数定义词法,使用flexc++工具编译生成扫描器的C++类
 *Version : 1.2
 *Author: 梁泽浩
 *Created date: 3月28日
 */

%%
[ \t\r\n]+ // nothing to do
"/*" {
// TODO:吃掉注释
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
   return Parser::ELSE;
}
"if" {
    
    return Parser::IF;
}
"int" {
    
    return Parser::INT;
}
"return" {
    
    return Parser::RETURN;
} 
"void" {
    
    return Parser::VOID;
}
"while" {
    
    return Parser::WHILE;
}
"=" {
    
    return Parser::ASSIGN;
}
">" {
    
    return Parser::GT;
}
">=" {
    
    return Parser::GE;
}
"<" {
    
    return Parser::LT;
}
"<=" {
    
    return Parser::LE;
}
"==" {
    return Parser::EQ;
}
"!=" {
    return Parser::NE;
}
"(" {
    return Parser::LEFTP;
}
")" {
    return Parser::RIGHTP;
}
"[" {
    return Parser::LEFTS;
}
"]" {
    return Parser::RIGHTS;
}
"{" {
    return Parser::LEFTB;
}
"}" {
    return Parser::RIGHTB;
}
"," {
    return Parser::COMMA;
}
";" {
    return Parser::SEMICOLON;
}
"+" {
    return Parser::ADD;
}
"-" {
    return Parser::SUB;
}
"*" {
    return Parser::MUL;
}
"/" {
    return Parser::DIV;
}
[A-Za-z]+ {
   return Parser::ID;
}
[0-9]+ {
    return Parser::NUM;
}
. {
    throw std::invalid_argument("遇到未定义符号！");
}

