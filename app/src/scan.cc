
/**
 * @file scan.cc
 * @author Liang Zehao
 * @brief 词法扫描器的入口函数
 * 
 * @version 1.2
 * @date 2020-04-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "Scanner.ih"
#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    // 程序名本身就算1个参数
    if (1 == argc)
    {
        cout << "请指定输入文件" << endl;
        return 0;
    }

    string infile = argv[1];

    Scanner scanner(infile, "-"); // define a Scanner object
    try
    {
        while (int token = scanner.lex()) // get all tokens
        {
            string const &text = scanner.matched();
            switch (token)
            {
            case ParserBase::ELSE:
                cout << "ELSE: " << text << endl;
                break;
            case ParserBase::IF:
                cout << "IF: " << text << endl;
                break;
            case ParserBase::RETURN:
                cout << "RETURN: " << text << endl;
                break;
            case ParserBase::INT:
                cout << "INT: " << text << endl;
                break;
            case ParserBase::VOID:
                cout << "VOID: " << text << endl;
                break;
            case ParserBase::WHILE:
                cout << "WHILE: " << text << endl;
                break;
            case ParserBase::LT:
                cout << "LT: " << text << endl;
                break;
            case ParserBase::LE:
                cout << "LE: " << text << endl;
                break;
            case ParserBase::GT:
                cout << "GT: " << text << endl;
                break;
            case ParserBase::GE:
                cout << "GE: " << text << endl;
                break;
            case ParserBase::EQ:
                cout << "EQ: " << text << endl;
                break;
            case ParserBase::NE:
                cout << "NE: " << text << endl;
                break;
            case ParserBase::COMMA:
                cout << "COMMA: " << text << endl;
                break;
            case ParserBase::SEMICOLON:
                cout << "SEMICOLON: " << text << endl;
                break;
            case ParserBase::ADD:
                cout << "ADD: " << text << endl;
                break;
            case ParserBase::SUB:
                cout << "SUB: " << text << endl;
                break;
            case ParserBase::MUL:
                cout << "MUL: " << text << endl;
                break;
            case ParserBase::DIV:
                cout << "DIV: " << text << endl;
                break;
            case ParserBase::ASSIGN:
                cout << "ASSIGN: " << text << endl;
                break;
            case ParserBase::LEFTP:
                cout << "LEFTP: " << text << endl;
                break;
            case ParserBase::RIGHTP:
                cout << "RIGHTP: " << text << endl;
                break;
            case ParserBase::LEFTS:
                cout << "LEFTS: " << text << endl;
                break;
            case ParserBase::RIGHTS:
                cout << "RIGHTS: " << text << endl;
                break;
            case ParserBase::LEFTB:
                cout << "LEFTB: " << text << endl;
                break;
            case ParserBase::RIGHTB:
                cout << "RIGHTB: " << text << endl;
                break;
            case ParserBase::ID:
                cout << "ID: " << text << endl;
                break;
            case ParserBase::NUM:
                cout << "NUM: " << text << endl;
                break;
            default:
                cerr << "程序出错" << std::endl;
                break;
            }
        }
    }
    catch (const std::exception &e)
    {
        cerr << e.what() << '\n';
        return 0;
    }

    return 0;
}