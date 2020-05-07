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
#include <fstream>
using namespace std;
/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char** argv)
{
    /**
     * @brief 
     * 
     */
    int a;
    if (argc == 1) {
        cout << "请指定输入文件" << endl;
        return 0;
    }
    // 标准输入流重定向为文件流
	// freopen(argv[1],"r",stdin); 
    ifstream f(argv[1]);
    if (!f.good()) {
        cerr << "文件打开失败" << endl;
        return 1;
    }
    cin.rdbuf(f.rdbuf());
    Parser parser;
    int statusCode = parser.parse();
    return statusCode;
}