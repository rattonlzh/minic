/*
 * @Copyright: Copyright (c) 2020 SCNU Compiler Principle Project Group. All rights reserved.
 * @FilePath: /minic/symtab.h
 * @Description: 符号表的声明文件
 * @Version: 1.0
 * @Author: Liang Zehao, Zhang Yongbiao
 * @Date: 2020-06-17 12:52:55
 * @LastEditTime: 2020-06-18 22:26:43
 * @LastEditors: Liang Zehao
 */ 

#ifndef _SYMTAB_H_
#define _SYMTAB_H_

#include "globals.h"

/**
 * @brief 符号表(哈希表)大小
 * 
 */
#define SIZE 211

/**
 * @brief 1个符号的行号列表
 * 
 */
typedef struct LineListRec
   { int lineno;
     struct LineListRec * next;
   } * LineList;

/**
 * @brief 哈希表的一个桶(链表形势), 记录符号信息
 * 
 */
typedef struct BucketListRec
   { char * name;
     LineList lines;// 所有出现的行号
     TreeNode *treeNode;
     int memloc ; // 虚拟内存位置
     struct BucketListRec * next;
   } * BucketList;

/**
 * @brief 作用域结构
 * 
 */
typedef struct ScopeRec
   { char * funcName;
     int nestedLevel; // 作用域的嵌套深度
     struct ScopeRec * parent;
     BucketList hashTable[SIZE];
   } * Scope;

/**
 * @brief 全局作用域
 * 
 */
Scope globalScope;

/**
 * @brief 创建作用域
 * 
 * @param funcName 
 * @return Scope 
 */
Scope sc_create(char *funcName);

/**
 * @brief 栈顶作用域
 * 
 * @return Scope 
 */
Scope sc_top( void );

/**
 * @brief pop栈顶作用域
 * 
 */
void sc_pop( void );
/**
 * @brief push栈顶作用域
 * 
 * @param scope 
 */
void sc_push( Scope scope );

/**
 * @brief 添加内存位置
 * 
 * @return int 
 */
int addLocation( void );

/**
 * @brief 在当前作用域的符号表中找名字为name的符号
 * 
 * @param name 
 * @return BucketList 
 */
BucketList st_bucket(char* name);

/**
 * @brief 返回当前符号的作用域
 *
 * @param name
 * @return Scope
 */
Scope st_scope(char* name);

/**
 * @brief 找到栈顶作用域符号表中名字为name的符号的内存位置
 * 
 * @param name 
 * @return int 
 */
int st_lookup(char* name);

/**
 * @brief 查找栈顶作用域的符号表中名字为name的符号的内存位置,找不到则返回-1
 * 
 * @param name 
 * @return int 
 */
int st_lookup_top(char* name);

/**
 * @brief 在当前作用域插入一个符号
 * 
 * @param name 符号名
 * @param lineno 符号所在的行号
 * @param loc 符号的内存位置
 * @param treeNode 符号对应的树节点
 */
void st_insert(char* name, int lineno, int loc, TreeNode* treeNode);

/**
 * @brief 给name符号添加行号
 * 
 * @param name 
 * @param lineno 
 */
void st_add_lineno(char* name, int lineno);

/**
 * @brief 打印符号表
 * 
 * @param listing 
 */
void printSymTab(FILE * listing);

#endif
