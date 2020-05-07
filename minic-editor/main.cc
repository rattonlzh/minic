/**
 * @file main.cc
 * @author Liang Zehao
 * @brief 窗体主函数入口
 * 
 * @version 0.1
 * @date 2020-05-05
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "editor.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Editor w;
    w.show();
    return a.exec();
}
