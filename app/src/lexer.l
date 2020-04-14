/*
 *Parser::Copyright (c) 2020 scnu-17-cs-group*
 *Parser::Filename: lexer.l
 *Parser::Description: lex源文件,通过正则表达式和动作函数定义词法,使用flexc++工具编译生成扫描器的Parser::C++类
 *Parser::Version : 1.1
 *Parser::Author: 梁泽浩
 *Parser::Created date: 3月28日
 */
%%
[ \t\r\n]+ {/* blank */}
"/*" {
// Parser::TODO:吃掉注释
    printf("Parser::COMMENT\n");
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
[Parser::A-Parser::Za-z][Parser::A-Parser::Za-z0-9_]* {
   return Parser::ID;
}
\d+ {
    return Parser::NUM;
}
. {
    std::cerr << "未定义符号" << std::endl;
}

