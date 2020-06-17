#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "globals.h"
#include "symtab.h"

#define MAX_SCOPE 1000

/* SHIFT是哈希函数的移位数*/
#define SHIFT 4

/*哈希函数*/
static int hash ( char * key )
{ int temp = 0;
  int i = 0;
  while (key[i] != '\0')
  { temp = ((temp << SHIFT) + key[i]) % SIZE;
    ++i;
  }
  return temp;
}

/*作用域临时栈，临时存放当前作用域的父级作用域，便于执行嵌套作用域相关的操作*/
static Scope scopeStack[MAX_SCOPE];
static int nScopeStack = 0;

/*所有作用域真正保存的地方，也是真正的总符号表*/
static Scope scopes[MAX_SCOPE];
static int nScope = 0;

/*模拟的内存位置*/
static int location[MAX_SCOPE];

/*新建名字为funcName的作用域*/
Scope sc_create(char* funcName)
{
    Scope newScope;

    newScope = (Scope)malloc(sizeof(struct ScopeRec));
    newScope->funcName = funcName;
    newScope->nestedLevel = nScopeStack;
    newScope->parent = sc_top();
    // 初始化散列表
    for (int i = 0; i < 211; i++)
        newScope->hashTable[i] = NULL;

    scopes[nScope++] = newScope;

    return newScope;
}

/* 返回当前作用域 */
Scope sc_top( void )
{ return scopeStack[nScopeStack - 1];
}

/* 移除当前作用域 */
void sc_pop( void )
{
  //printf("pop %s\n", sc_top()->funcName);
  --nScopeStack;
}

/* push一个作用域到栈顶，同时把作用域保存到数组中 */
void sc_push( Scope scope )
{ scopeStack[nScopeStack] = scope;
  location[nScopeStack++] = 0;
  //printf("push %s\n", scope->funcName);
}

/* 返回当前作用域新分配的内存位置 */
int addLocation(void)
{
    return location[nScopeStack - 1]++;
}

/* 在当前作用域查找名字为name的符号信息，如果找不到则到父级作用域找，直到找到后返回符号或者全都找不到返回NULL */
BucketList st_bucket( char * name )
{ int h = hash(name);
  Scope sc = sc_top();
  while(sc) {
    BucketList l = sc->hashTable[h];
    while ((l != NULL) && (strcmp(name,l->name) != 0))
      l = l->next;
    if (l != NULL) return l;
    sc = sc->parent;
  }
  return NULL;
}

/* 查找名字为name的符号的变量的存放位置*/
int st_lookup ( char * name )
{ BucketList l = st_bucket(name);
  if (l != NULL) return l->memloc;
  return -1;
}

/**在当前作用域的符号表中查找key为l->name的元素，如果找到则返回变量的存放的位置，否则返回-1*/
int st_lookup_top (char * name)
{ int h = hash(name);
  Scope sc = sc_top();
  while(sc) {
    BucketList l = sc->hashTable[h];

    while ((l != NULL) && (strcmp(name,l->name) != 0))
      l = l->next;
    if (l != NULL) return l->memloc;
    break;
  }
  return -1;
}

/*往当前作用域插入符号*/
void st_insert(char* name, int lineno, int loc, TreeNode* treeNode)
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

/* 给符号增加行号*/
void st_add_lineno(char * name, int lineno)
{ BucketList l = st_bucket(name);
  LineList ll = l->lines;
  while (ll->next != NULL) ll = ll->next;
  ll->next = (LineList) malloc(sizeof(struct LineListRec));
  ll->next->lineno = lineno;
  ll->next->next = NULL;
}

/*测试该作用域是否有声明的变量*/
int testSymTab(BucketList* hashTable, FILE* listing) {
    for (int j = 0; j < SIZE; ++j)
        if (hashTable[j] != NULL)
            return 1;
    return 0;
}

/*打印散列表中出现的所有符号*/
void printSymTabRows(BucketList* hashTable, FILE* listing) {

    for (int j = 0; j < SIZE; ++j)
    {
        if (hashTable[j] != NULL)
        {
            BucketList l = hashTable[j];
            TreeNode* node = l->treeNode;

            while (l != NULL)
            {
                LineList t = l->lines;

                fprintf(listing, "%-12s ", l->name);

                switch (node->nodekind) {
                case DeclK:
                    switch (node->kind.decl) {
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
                    switch (node->kind.param) {
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

                switch (node->type) {
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

/*打印所有作用域的符号表*/
void printSymTab(FILE* listing)
{
    fprintf(listing, "Sym.Name     Sym.Type     Data Type    Line Numbers\n");
    fprintf(listing, "---------------------------------------------------------\n");
    fputc('\n', listing);

    for (int i = 0; i < nScope; ++i) {
        BucketList* hashTable = scopes[i]->hashTable;

        if (testSymTab(hashTable, listing) == 1) {
            if (i == 0)
                fprintf(listing, "<global scope> ");
            else
                fprintf(listing, "function name: %s ", scopes[i]->funcName);

            fprintf(listing,"(nested level: %d)\n",scopes[i]->nestedLevel);

            printSymTabRows(hashTable, listing);
            fputc('\n', listing);
        }
    }
    fprintf(listing, "---------------------------------------------------------\n");
}
