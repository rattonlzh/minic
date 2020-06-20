/*
 * @Copyright: Copyright (c) 2020 SCNU Compiler Principle Project Group. All rights reserved.
 * @FilePath: /minic/analyze.h
 * @Description: 声明构造符号表和类型检查的函数
 * @Version: 1.0
 * @Author: Liang Zehao, Zhang Yongbiao
 * @Date: 2020-06-17 12:52:55
 * @LastEditTime: 2020-06-18 22:28:09
 * @LastEditors: Liang Zehao
 */ 


#ifndef _ANALYZE_H_
#define _ANALYZE_H_

/*构造符号表*/
void buildSymtab(TreeNode *);

/*类型检查*/
void typeCheck(TreeNode *);

#endif
