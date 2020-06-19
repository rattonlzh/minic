/*
 * @Copyright: Copyright (c) 2020 SCNU Compiler Principle Project Group. All rights reserved.
 * @FilePath: /minic/cgen.h
 * @Description: 中间代码生成的头文件
 * @Version: 1.0
 * @Author: Liang Zehao, Zhang Yongbiao
 * @Date: 2020-06-17 12:52:55
 * @LastEditTime: 2020-06-18 22:27:54
 * @LastEditors: Zhang Yongbiao
 */



#ifndef _CGEN_H_
#define _CGEN_H_

/* 供外部调用的生成中间代码的接口*/
void codeGen(TreeNode * syntaxTree, char * codefile);

#endif
