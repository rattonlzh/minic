/*
 * @Copyright: Copyright (c) 2020 SCNU Compiler Principle Project Group. All rights reserved.
 * @FilePath: /minic/minic2/minic/src/code.h
 * @Description: 用于辅助生成中间代码的函数声明文件
 * @Version: 1.0
 * @Author: Liang Zehao, Zhang Yongbiao
 * @Date: 2020-06-17 12:52:55
 * @LastEditTime: 2020-06-19 10:55:54
 * @LastEditors: Zhang Yongbiao
 */ 

#ifndef _CODE_H_
#define _CODE_H_

/* pc = program counter  */
#define  pc 7

/* mp = "memory pointer"
 * 指向临时变量内存空间的顶部
 */
#define  mp 6

/* gp = "global pointer"
  * 通常指向全局变量的内存空间的底部
  */
#define gp 5

/* 累加器*/
#define  ac 0

/* 第二个累加器 */
#define  ac1 1

/* 输出中间代码的方法 */

/* 输出注释*/
void emitComment( char * c );

/* 输出寄存器型指令
 * op = the opcode
 * r = target register
 * s = 1st source register
 * t = 2nd source register
 * c = a comment to be printed if TraceCode is TRUE
 */
void emitRO( char *op, int r, int s, int t, char *c);

/* 输出寄存器-内存型指令
 * op = the opcode
 * r = target register
 * d = the offset
 * s = the base register
 * c = a comment to be printed if TraceCode is TRUE
 */
void emitRM( char * op, int r, int d, int s, char *c);

/* 跳过输出指定数量的指令，并返回当前输出指令的序号*/
int emitSkip( int howMany);

/* 将当前输出指令的序号置为指定序号，以输出之前跳过的指令*/
void emitBackup( int loc);

/* 将当前输出指令的序号恢复为正常的当前最大的序号*/
void emitRestore(void);

/* 将绝对位置转化为相对位置并输出指定的转移型指令
 * op = the opcode
 * r = target register
 * a = the absolute location in memory
 * c = a comment to be printed if TraceCode is TRUE
 */
void emitRM_Abs( char *op, int r, int a, char * c);

#endif
