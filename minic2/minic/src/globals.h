/*
 * @Copyright: Copyright (c) 2020 SCNU Compiler Principle Project Group. All rights reserved.
 * @FilePath: /minic/src/globals.h
 * @Description: 定义了一些全局变量的外部声明
 * @Version: 1.0
 * @Author: Liang Zehao, Zhang Yongbiao
 * @Date: 2020-06-17 12:52:55
 * @LastEditTime: 2020-06-18 23:46:35
 * @LastEditors: Liang Zehao
 */ 

#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* Yacc/Bison在内部为token生成自己的值。其他文件可以通过包含
 * 使用Yacc/Bison选项-d(“generate header”)生成的tab.h文件来访问这些值。
 * YYPARSER标记阻止将tab.h包含到Yacc/Bison输出本身中
 */
#ifndef YYPARSER

/* the name of the following file may change */
#include "y.tab.h"

/* ENDFILE is implicitly(隐式) defined by Yacc/Bison,
 * and not included in the tab.h file
 */
#define ENDFILE 0

#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

extern FILE* source; /* minic源文件的输入流 */
extern FILE* listing; /* minic编译器的输出流 */
extern FILE* code; /* 中间代码的写出流 */

extern int lineno; /* 保存当前扫描的符号所在的行号 */

/**************************************************/
/***********   Syntax tree for parsing ************/
/**************************************************/

typedef enum {StmtK, ExpK, DeclK, ParamK, TypeK} NodeKind; /*结点类型*/

typedef enum {IfK, IterK, RetK, CompK} StmtKind; /*语句节点*/
typedef enum {AssignK, CallK, OpK, ConstK, IdK, ArrIdK} ExpKind; /*表达式节点*/
typedef enum {FuncK, VarK, ArrVarK} DeclKind; /*声明节点*/
typedef enum {ArrParamK, NonArrParamK} ParamKind; /*参数节点*/
typedef enum {TypeNameK} TypeKind; /*类型节点，具体的类型存于下方语法树节点的attr.name中*/

typedef enum { Void, Integer, Boolean, Array} ExpType; /* 在语义分析的类型检查中使用*/

#define MAXCHILDREN 3 /*一个结点最多有三个子结点*/
#define MAXTOKENLEN 256 /*变量名长度*/

struct ScopeRec; /*作用域*/

typedef int TokenType;

typedef struct arrayAttr /*数组的属性*/
{
    TokenType type;
    char      name[MAXTOKENLEN];
    int       size;
} ArrayAttr;

typedef struct treeNode  /*定义语法树结点结构*/
{
    struct treeNode* child[MAXCHILDREN];
    struct treeNode* sibling;

    int lineno;

    NodeKind nodekind; /*节点类型*/

    union { StmtKind stmt;
            ExpKind exp;
            DeclKind decl;
            ParamKind param;
            TypeKind type; } kind; /*对应节点类型下的再细分类型*/

    union { TokenType op;    /*运算符号的token值*/
            TokenType type;  /*变量类型*/
            int       val;   /*num的值*/
            char      name[MAXTOKENLEN]; /*id的名称*/
            ArrayAttr arr;   /*数组的属性*/
            struct ScopeRec * scope; } attr; /*节点的属性*/

    ExpType type;  /* 在语义分析的类型检查中使用 */
} TreeNode ;

/**************************************************/
/***********   Flags for tracing       ************/
/**************************************************/

/**
 * @brief 如果为TRUE则打印扫描到的符号
 * 
 */
extern int TraceScan; 

/**
 * @brief 如果为TRUE则打印语法树
 * 
 */
extern int TraceParse;

/**
 * @brief 如果为TRUE则进行类型检查和打印符号表
 * 
 */
extern int TraceAnalyze; // 打印符号表和类型检查结果

/**
 * @brief 如果为TRUE则生成中间代码
 * 
 */
extern int TraceCode;

/**
 * @brief 如果出现错误则设为TRUE
 * 
 */
extern int Error; 

#endif