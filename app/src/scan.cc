
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
            case Parser::ELSE:
                cout << "ELSE: " << text << endl;
                break;
            case Parser::IF:
                cout << "IF: " << text << endl;
                break;
            case Parser::RETURN:
                cout << "RETURN: " << text << endl;
                break;
            case Parser::INT:
                cout << "INT: " << text << endl;
                break;
            case Parser::VOID:
                cout << "VOID: " << text << endl;
                break;
            case Parser::WHILE:
                cout << "WHILE: " << text << endl;
                break;
            case Parser::LT:
                cout << "LT: " << text << endl;
                break;
            case Parser::LE:
                cout << "LE: " << text << endl;
                break;
            case Parser::GT:
                cout << "GT: " << text << endl;
                break;
            case Parser::GE:
                cout << "GE: " << text << endl;
                break;
            case Parser::EQ:
                cout << "EQ: " << text << endl;
                break;
            case Parser::NE:
                cout << "NE: " << text << endl;
                break;
            case Parser::COMMA:
                cout << "COMMA: " << text << endl;
                break;
            case Parser::SEMICOLON:
                cout << "SEMICOLON: " << text << endl;
                break;
            case Parser::ADD:
                cout << "ADD: " << text << endl;
                break;
            case Parser::SUB:
                cout << "SUB: " << text << endl;
                break;
            case Parser::MUL:
                cout << "MUL: " << text << endl;
                break;
            case Parser::DIV:
                cout << "DIV: " << text << endl;
                break;
            case Parser::ASSIGN:
                cout << "ASSIGN: " << text << endl;
                break;
            case Parser::LEFTP:
                cout << "LEFTP: " << text << endl;
                break;
            case Parser::RIGHTP:
                cout << "RIGHTP: " << text << endl;
                break;
            case Parser::LEFTS:
                cout << "LEFTS: " << text << endl;
                break;
            case Parser::RIGHTS:
                cout << "RIGHTS: " << text << endl;
                break;
            case Parser::LEFTB:
                cout << "LEFTB: " << text << endl;
                break;
            case Parser::RIGHTB:
                cout << "RIGHTB: " << text << endl;
                break;
            case Parser::ID:
                cout << "ID: " << text << endl;
                break;
            case Parser::NUM:
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