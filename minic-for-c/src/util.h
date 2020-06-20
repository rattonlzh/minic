/*
 * @Copyright (c) 2020 SCNU Compiler Principle Project Group. All rights reserved.
 * @FilePath: /minic/util.h
 * @Description: 
 * @Version: 1.0
 * @Author: Liang Zehao, Zhang Yongbiao
 * @Date: 2020-06-17 12:52:55
 * @LastEditTime: 2020-06-18 22:25:05
 * @LastEditors: Liang Zehao
 */ 

#include "globals.h"

#ifndef _UTIL_H_
#define _UTIL_H_

// 鎵ц璇硶鍒嗘瀽,鐢熸垚璇硶鏍�
TreeNode * parse( FILE * );

/* Procedure printToken prints a token 
 * and its lexeme to the listing file
 */
void printToken(TokenType, const char *);

/* 鏂板缓 璇彞鑺傜偣 */
TreeNode * newStmtNode(StmtKind);

/* 鏂板缓 琛ㄨ揪寮忚妭鐐� */
TreeNode * newExpNode(ExpKind);

/* 鏂板缓 瀹氫箟鑺傜偣 */
TreeNode * newDeclNode(DeclKind);

/* 鏂板缓 鍙傛暟鑺傜偣 */
TreeNode * newParamNode(ParamKind);

/* 鏂板缓 绫诲瀷鑺傜偣 */
TreeNode * newTypeNode(TypeKind);

/* Function copyString allocates and makes a new
 * copy of an existing string
 */
char * copyString(char *);

void printTreeHelper(TreeNode *, int[], int, int);

/* procedure printTree prints a syntax tree to the 
 * listing file
 */
void printTree(TreeNode *);

/**
 * @brief 杩斿洖str鐨勫瓧绗︿覆闀垮害,濡傛灉鍦╗0,max)鐨勪笅鏍囪寖鍥村唴鎵句笉鍒扮粨鏉熺鎴杕ax灏忎簬绛変簬0,鍒欒繑鍥�-1
 * 
 * @param str 瀛楃鏁扮粍
 * @param max 鏁扮粍鍙互瀹圭撼鐨勫瓧绗︿釜鏁�
 * @return int 瀛楃涓查暱搴�
 */
int len(char str[], int max);

TokenType getToken(void);

void init(void);
#endif