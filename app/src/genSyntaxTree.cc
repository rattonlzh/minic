/**
 * @file genSyntaxTree.cc  
 * @author Liang Zehao
 * @brief 用于产生语法树的主函数
 * @version 0.1
 * @date 2020-04-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "Parser.ih"

int main(int argc, char** argv)
{

    Parser parser;
    return parser.parse();
    
}