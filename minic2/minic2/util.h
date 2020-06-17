#include "globals.h"

#ifndef _UTIL_H_
#define _UTIL_H_

TreeNode * parse( FILE * );

/* Procedure printToken prints a token 
 * and its lexeme to the listing file
 */
void printToken(TokenType, const char *);

/* 新建 语句节点 */
TreeNode * newStmtNode(StmtKind);

/* 新建 表达式节点 */
TreeNode * newExpNode(ExpKind);

/* 新建 定义节点 */
TreeNode * newDeclNode(DeclKind);

/* 新建 参数节点 */
TreeNode * newParamNode(ParamKind);

/* 新建 类型节点 */
TreeNode * newTypeNode(TypeKind);

/* Function copyString allocates and makes a new
 * copy of an existing string
 */
char * copyString(char *);

/* procedure printTree prints a syntax tree to the 
 * listing file
 */
void printTree(TreeNode *);

#endif