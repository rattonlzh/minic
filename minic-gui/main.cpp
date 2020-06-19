/*
 * @Copyright: Copyright (c) 2020 SCNU authors. All right reserved.
 * @FilePath: /minic/minic-gui/main.cpp
 * @Description: gui程序的主函数入口
 * @Version: 1.0
 * @Author: Liang Zehao, Zhang Yongbiao
 * @Date: 2020-05-08 11:47:38
 * @LastEditTime: 2020-06-19 08:52:44
 * @LastEditors: Liang Zehao
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
