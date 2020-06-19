/*
 * @Copyright: Copyright (c) 2020 SCNU Compiler Principle Project Group. All rights reserved.
 * @FilePath: /minic/symtab.c
 * @Description: 符号表的实现文件
 * @Version: 1.0
 * @Author: Liang Zehao, Zhang Yongbiao
 * @Date: 2020-06-17 12:52:55
 * @LastEditTime: 2020-06-18 22:29:36
 * @LastEditors: Liang Zehao
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "globals.h"
#include "symtab.h"

#define MAX_SCOPE 1000

// 做hash时移位的位数
#define SHIFT 4

/**
 * @brief 计算key的hashcode
 * 
 * @param key 
 * @return int 
 */
static int hash(char *key)
{
    int temp = 0;
    int i = 0;
    while (key[i] != '\0')
    {
        temp = ((temp << SHIFT) + key[i]) % SIZE;
        ++i;
    }
    return temp;
}

/**
 * @brief 作用域的临时栈
 * 
 */
static Scope scopeStack[MAX_SCOPE];
static int nScopeStack = 0;

/**
 * @brief 作用域范围
 * 
 */
static Scope scopes[MAX_SCOPE];
static int nScope = 0;

/**
 * @brief location[i]表示第i个作用域开辟的"内存"个数
 * 
 */
static int location[MAX_SCOPE];

/**
 * @brief 创建作用域
 * 
 * @param funcName 
 * @return Scope 
 */
Scope sc_create(char *funcName)
{
    Scope newScope;

    newScope = (Scope)malloc(sizeof(struct ScopeRec));
    newScope->funcName = funcName;
    newScope->nestedLevel = nScopeStack;
    newScope->parent = sc_top();
    //
    for (int i = 0; i < 211; i++)
        newScope->hashTable[i] = NULL;

    scopes[nScope++] = newScope;

    return newScope;
}

/**
 * @brief 当前作用域
 * 
 * @return Scope 
 */
Scope sc_top(void)
{
    return scopeStack[nScopeStack - 1];
}

/**
 * @brief pop当前作用域
 * 
 */
void sc_pop(void)
{
    //printf("pop %s\n", sc_top()->funcName);
    --nScopeStack;
}

/**
 * @brief 将作用域入栈顶
 * 
 * @param scope 
 */
void sc_push(Scope scope)
{
    scopeStack[nScopeStack] = scope;
    location[nScopeStack++] = 0;
    //printf("push %s\n", scope->funcName);
}

/**
 * @brief 添加当前作用域的符号内存位置个数
 * 
 * @return int 
 */
int addLocation(void)
{
    return location[nScopeStack - 1]++;
}

/**
 * @brief 在当前作用域及其祖先作用域的符号表中找名字为name的符号
 * 
 * @param name 
 * @return BucketList 
 */
BucketList st_bucket(char *name)
{
    int h = hash(name);
    Scope sc = sc_top();
    while (sc)
    {
        BucketList l = sc->hashTable[h];
        while ((l != NULL) && (strcmp(name, l->name) != 0))
            l = l->next;
        if (l != NULL)
            return l;
        sc = sc->parent;
    }
    return NULL;
}

/**
 * @brief 返回当前符号的作用域
 *
 * @param name
 * @return Scope
 */
Scope st_scope(char* name)
{
    int h = hash(name);
    Scope sc = sc_top();
    while (sc) {
        BucketList l = sc->hashTable[h];
        while ((l != NULL) && (strcmp(name, l->name) != 0))
            l = l->next;
        if (l != NULL) return sc;
        sc = sc->parent;
    }
    return NULL;
}

/**
 * @brief 找到当前作用域及祖先作用域的符号表中名字为name的符号的内存位置，找不到则返回-1，可用于类型检查
 * 
 * @param name 
 * @return int 
 */
int st_lookup(char *name)
{
    BucketList l = st_bucket(name);
    if (l != NULL)
        return l->memloc;
    return -1;
}

/**
 * @brief 查找当前作用域的符号表中名字为name的符号的内存位置,找不到则返回-1
 * 
 * @param name 
 * @return int 
 */
int st_lookup_top(char *name)
{
    int h = hash(name);
    Scope sc = sc_top();
    while (sc)
    {
        BucketList l = sc->hashTable[h];

        while ((l != NULL) && (strcmp(name, l->name) != 0))
            l = l->next;
        if (l != NULL)
            return l->memloc;
        break;
    }
    return -1;
}

/**
 * @brief 在当前作用域插入一个符号
 * 
 * @param name 符号名
 * @param lineno 符号所在的行号
 * @param loc 符号的内存位置
 * @param treeNode 符号对应的树节点
 */
void st_insert(char *name, int lineno, int loc, TreeNode *treeNode)
{
    int h = hash(name);
    Scope top = sc_top();
    BucketList l = top->hashTable[h];
    while ((l != NULL) && (strcmp(name, l->name) != 0))
        l = l->next;
    l = (BucketList)malloc(sizeof(struct BucketListRec));
    l->name = name;
    l->treeNode = treeNode;
    l->lines = (LineList)malloc(sizeof(struct LineListRec));
    l->lines->lineno = lineno;
    l->memloc = loc;
    l->lines->next = NULL;
    l->next = top->hashTable[h];
    top->hashTable[h] = l;
}

/**
 * @brief 给当前作用域添加符号的新行号
 * 
 * @param name 
 * @param lineno 
 */
void st_add_lineno(char *name, int lineno)
{
    BucketList l = st_bucket(name);
    LineList ll = l->lines;
    while (ll->next != NULL)
        ll = ll->next;
    ll->next = (LineList)malloc(sizeof(struct LineListRec));
    ll->next->lineno = lineno;
    ll->next->next = NULL;
}

/**
 * @brief 测试符号表是否为空,如果不为空则返回1,否则返回0
 * 
 * @param hashTable 
 * @param listing 
 * @return int 
 */
int testSymTab(BucketList *hashTable, FILE *listing)
{
    for (int j = 0; j < SIZE; ++j)
        if (hashTable[j] != NULL)
            return 1;
    return 0;
}

/**
 * @brief 打印一个作用域的符号表的所有符号
 * 
 * @param hashTable 
 * @param listing 
 */
void printSymTabRows(BucketList *hashTable, FILE *listing)
{

    for (int j = 0; j < SIZE; ++j)
    {
        if (hashTable[j] != NULL)
        {
            BucketList l = hashTable[j];
            TreeNode *node = l->treeNode;

            while (l != NULL)
            {
                LineList t = l->lines;

                fprintf(listing, "%-12s ", l->name);

                switch (node->nodekind)
                {
                case DeclK:
                    switch (node->kind.decl)
                    {
                    case FuncK:
                        fprintf(listing, "Function     ");
                        break;
                    case VarK:
                        fprintf(listing, "Variable     ");
                        break;
                    case ArrVarK:
                        fprintf(listing, "Array Var    ");
                        break;
                    default:
                        break;
                    }
                    break;
                case ParamK:
                    switch (node->kind.param)
                    {
                    case NonArrParamK:
                        fprintf(listing, "Variable     ");
                        break;
                    case ArrParamK:
                        fprintf(listing, "Array Var    ");
                        break;
                    default:
                        break;
                    }
                    break;
                default:
                    break;
                }

                switch (node->type)
                {
                case Void:
                    fprintf(listing, "Void       ");
                    break;
                case Integer:
                    fprintf(listing, "Integer    ");
                    break;
                case Boolean:
                    fprintf(listing, "Boolean    ");
                    break;
                case Array:
                    fprintf(listing, "Array      ");
                    break;
                default:
                    break;
                }

                while (t != NULL)
                {
                    fprintf(listing, "%4d ", t->lineno);
                    t = t->next;
                }

                fprintf(listing, "\n");
                l = l->next;
            }
        }
    }
}

/**
 * @brief 打印完整的符号表
 * 
 * @param listing 
 */
void printSymTab(FILE *listing)
{
    fprintf(listing, "Sym.Name     Sym.Type     Data Type    Line Numbers\n");
    fprintf(listing, "---------------------------------------------------------\n");
    fputc('\n', listing);

    for (int i = 0; i < nScope; ++i)
    {
        BucketList *hashTable = scopes[i]->hashTable;

        if (testSymTab(hashTable, listing) == 1)
        {
            if (i == 0)
                fprintf(listing, "<Global scope> ");
            else
                fprintf(listing, "<Func %s scope> ", scopes[i]->funcName);

            fprintf(listing, "(Nested level: %d)\n", scopes[i]->nestedLevel);

            printSymTabRows(hashTable, listing);
            fputc('\n', listing);
        }
    }
    fprintf(listing, "---------------------------------------------------------\n");
}
