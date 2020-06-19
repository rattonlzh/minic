#ifndef _SYMTAB_H_
#define _SYMTAB_H_

#include "globals.h"

/*哈希表的大小*/
#define SIZE 211

/*记录变量出现的每个行号*/
typedef struct LineListRec
   { int lineno;
     struct LineListRec * next;
   } * LineList;

/*哈希表，保存变量的信息*/
typedef struct BucketListRec
   { char * name;
     LineList lines;
     TreeNode *treeNode;
     int memloc ; /*存放变量的内存位置*/
     struct BucketListRec * next;
   } * BucketList;

/*作用域*/
typedef struct ScopeRec
   { char * funcName;
     int nestedLevel; /*嵌套深度，全局作用域为0*/
     struct ScopeRec * parent;
     BucketList hashTable[SIZE];
   } * Scope;

/*全局作用域*/
Scope globalScope;

/*新建作用域*/
Scope sc_create(char *funcName);

/*返回作用域临时栈的顶部作用域*/
Scope sc_top( void );

void sc_pop( void );
void sc_push( Scope scope );

/*添加内存位置*/
int addLocation( void );

/*返回变量所在的哈希表*/
BucketList st_bucket(char* name);

/*查找变量是否已存在于符号表，不存在则返回-1*/
int st_lookup(char* name);

/*查找变量是否存在于在作用域临时栈的顶部作用域中*/
int st_lookup_top(char* name);

/* 插入变量信息到符号表中
 * loc = memory location 只在一开始插入
 */
void st_insert(char* name, int lineno, int loc, TreeNode* treeNode);

/*添加变量所在位置的行号*/
void st_add_lineno(char* name, int lineno);

/*打印格式化的符号表*/
void printSymTab(FILE * listing);

#endif
