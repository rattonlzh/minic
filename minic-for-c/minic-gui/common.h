/*
 * @Copyright: Copyright (c) 2020 SCNU authors. All right reserved.
 * @FilePath: /minic/minic-editor/common.h
 * @Description: 声明结构体的头文件
 * @Version: 1.0
 * @Author: Liang Zehao, Zhang Yongbiao
 * @Date: 2020-05-08 11:47:38
 * @LastEditTime: 2020-06-19 00:38:53
 * @LastEditors: Liang Zehao
 */

#ifndef COMMON_H
#define COMMON_H
#include <QString>
 /**
  * @brief The CmdPath 结构体包含minic各个可执行程序的路径
  */
struct CmdPath {
    QString minicPath;
    QString tmPath;

};
#endif // COMMON_H
