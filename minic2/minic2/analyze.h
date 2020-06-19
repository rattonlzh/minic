/****************************************************/
/* File: analyze.h                                  */
/* Semantic analyzer interface for TINY compiler    */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#ifndef _ANALYZE_H_
#define _ANALYZE_H_

/*构造符号表*/
void buildSymtab(TreeNode *);

/*类型检查*/
void typeCheck(TreeNode *);

#endif
