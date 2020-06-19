/****************************************************/
/* File: analyze.h                                  */
/* Semantic analyzer interface for TINY compiler    */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#ifndef _ANALYZE_H_
#define _ANALYZE_H_

/*������ű�*/
void buildSymtab(TreeNode *);

/*���ͼ��*/
void typeCheck(TreeNode *);

#endif
