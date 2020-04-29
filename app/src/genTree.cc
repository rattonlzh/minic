/**
 * @file genTree.cc  
 * @author Liang Zehao
 * @brief 用于产生语法树的主函数
 * 
 * @version 0.2
 * @date 2020-04-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "Parser.ih"
using namespace std;
int main(int argc, char** argv)
{
    if (argc == 1) {
        cout << "请指定输入文件" << endl;
        return 0;
    }
    // 标准输入流重定向为文件流
	freopen(argv[1],"r",stdin); 

    Parser parser;
    int statusCode = parser.parse();
    return statusCode;
}