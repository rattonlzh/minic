
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
                cout << scanner.lineNr() << "\t" << "ELSE: " << text << endl;
                break;
            case ParserBase::IF:
                cout << scanner.lineNr() << "\t" << "IF: " << text << endl;
                break;
            case ParserBase::RETURN:
                cout << scanner.lineNr() << "\t" << "RETURN: " << text << endl;
                break;
            case ParserBase::INT:
                cout << scanner.lineNr() << "\t" << "INT: " << text << endl;
                break;
            case ParserBase::VOID:
                cout << scanner.lineNr() << "\t" << "VOID: " << text << endl;
                break;
            case ParserBase::WHILE:
                cout << scanner.lineNr() << "\t" << "WHILE: " << text << endl;
                break;
            case ParserBase::LT:
                cout << scanner.lineNr() << "\t" << "LT: " << text << endl;
                break;
            case ParserBase::LE:
                cout << scanner.lineNr() << "\t" << "LE: " << text << endl;
                break;
            case ParserBase::GT:
                cout << scanner.lineNr() << "\t" << "GT: " << text << endl;
                break;
            case ParserBase::GE:
                cout << scanner.lineNr() << "\t" << "GE: " << text << endl;
                break;
            case ParserBase::EQ:
                cout << scanner.lineNr() << "\t" << "EQ: " << text << endl;
                break;
            case ParserBase::NE:
                cout << scanner.lineNr() << "\t" << "NE: " << text << endl;
                break;
            case ParserBase::COMMA:
                cout << scanner.lineNr() << "\t" << "COMMA: " << text << endl;
                break;
            case ParserBase::SEMICOLON:
                cout << scanner.lineNr() << "\t" << "SEMICOLON: " << text << endl;
                break;
            case ParserBase::ADD:
                cout << scanner.lineNr() << "\t" << "ADD: " << text << endl;
                break;
            case ParserBase::SUB:
                cout << scanner.lineNr() << "\t" << "SUB: " << text << endl;
                break;
            case ParserBase::MUL:
                cout << scanner.lineNr() << "\t" << "MUL: " << text << endl;
                break;
            case ParserBase::DIV:
                cout << scanner.lineNr() << "\t" << "DIV: " << text << endl;
                break;
            case ParserBase::ASSIGN:
                cout << scanner.lineNr() << "\t" << "ASSIGN: " << text << endl;
                break;
            case ParserBase::LEFTP:
                cout << scanner.lineNr() << "\t" << "LEFTP: " << text << endl;
                break;
            case ParserBase::RIGHTP:
                cout << scanner.lineNr() << "\t" << "RIGHTP: " << text << endl;
                break;
            case ParserBase::LEFTS:
                cout << scanner.lineNr() << "\t" << "LEFTS: " << text << endl;
                break;
            case ParserBase::RIGHTS:
                cout << scanner.lineNr() << "\t" << "RIGHTS: " << text << endl;
                break;
            case ParserBase::LEFTB:
                cout << scanner.lineNr() << "\t" << "LEFTB: " << text << endl;
                break;
            case ParserBase::RIGHTB:
                cout << scanner.lineNr() << "\t" << "RIGHTB: " << text << endl;
                break;
            case ParserBase::ID:
                cout << scanner.lineNr() << "\t" << "ID: " << text << endl;
                break;
            case ParserBase::NUM:
                cout << scanner.lineNr() << "\t" << "NUM: " << text << endl;
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