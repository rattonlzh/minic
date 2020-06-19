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

extern FILE* source; /* source code text file */
extern FILE* listing; /* listing output text file */
extern FILE* code; /* code text file for TM simulator */

extern int lineno; /* source line number for listing */

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

/* EchoSource = TRUE causes the source program to
 * be echoed to the listing file with line numbers
 * during parsing
 */
extern int EchoSource;

/* TraceScan = TRUE causes token information to be
 * printed to the listing file as each token is
 * recognized by the scanner
 */
extern int TraceScan; // 打印token

/* TraceParse = TRUE causes the syntax tree to be
 * printed to the listing file in linearized form
 * (using indents for children)
 */
extern int TraceParse; // 打印语法树

/* TraceAnalyze = TRUE causes symbol table inserts
 * and lookups to be reported to the listing file
 */
extern int TraceAnalyze; // 打印符号表和类型检查结果

/* TraceCode = TRUE causes comments to be written
 * to the TM code file as code is generated
 */
extern int TraceCode;

/* Error = TRUE prevents further passes if an error occurs */
extern int Error; 

#endif