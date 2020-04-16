
/*
 *Copyright (c) 2020 scnu-17-cs-ratton&bill
 *Filename: driver.cc
 *Description: lex源文件,通过正则表达式和动作函数定义词法,使用flexc++工具编译生成扫描器的C++类
 *Version : 1.2
 *Author: 梁泽浩
 *Created date: 4月15日
 */
#include "Scanner.ih"
#include <fstream>
using namespace std;

int main(int argc, char **argv)
{
    // 程序名本身就算1个参数
    if (1 == argc)
    {
        cout << "缺少输入文件！" << endl;
        return 0;
    }

    string infile(argv[1]);
    string outfile("lex.out");
    if (argc == 3) {
        outfile = argv[2];
    }
    ofstream fout(outfile);
    Scanner scanner(infile, "-"); // define a Scanner object
    try
    {
        while (int token = scanner.lex()) // get all tokens
        {
            string const &text = scanner.matched();
            switch (token)
            {
            case Parser::ELSE:
                fout << "ELSE: " << text << endl;
                break;
            case Parser::IF:
                fout << "IF: " << text << endl;
                break;
            case Parser::RETURN:
                fout << "RETURN: " << text << endl;
                break;
            case Parser::INT:
                fout << "INT: " << text << endl;
                break;
            case Parser::VOID:
                fout << "VOID: " << text << endl;
                break;
            case Parser::WHILE:
                fout << "WHILE: " << text << endl;
                break;
            case Parser::LT:
                fout << "LT: " << text << endl;
                break;
            case Parser::LE:
                fout << "LE: " << text << endl;
                break;
            case Parser::GT:
                fout << "GT: " << text << endl;
                break;
            case Parser::GE:
                fout << "GE: " << text << endl;
                break;
            case Parser::EQ:
                fout << "EQ: " << text << endl;
                break;
            case Parser::NE:
                fout << "NE: " << text << endl;
                break;
            case Parser::COMMA:
                fout << "COMMA: " << text << endl;
                break;
            case Parser::SEMICOLON:
                fout << "SEMICOLON: " << text << endl;
                break;
            case Parser::ADD:
                fout << "ADD: " << text << endl;
                break;
            case Parser::SUB:
                fout << "SUB: " << text << endl;
                break;
            case Parser::MUL:
                fout << "MUL: " << text << endl;
                break;
            case Parser::DIV:
                fout << "DIV: " << text << endl;
                break;
            case Parser::ASSIGN:
                fout << "ASSIGN: " << text << endl;
                break;
            case Parser::LEFTP:
                fout << "LEFTP: " << text << endl;
                break;
            case Parser::RIGHTP:
                fout << "RIGHTP: " << text << endl;
                break;
            case Parser::LEFTS:
                fout << "LEFTS: " << text << endl;
                break;
            case Parser::RIGHTS:
                fout << "RIGHTS: " << text << endl;
                break;
            case Parser::LEFTB:
                fout << "LEFTB: " << text << endl;
                break;
            case Parser::RIGHTB:
                fout << "RIGHTB: " << text << endl;
                break;
            case Parser::ID:
                fout << "ID: " << text << endl;
                break;
            case Parser::NUM:
                fout << "NUM: " << text << endl;
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