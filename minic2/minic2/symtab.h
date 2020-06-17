#ifndef _SYMTAB_H_
#define _SYMTAB_H_

#include "globals.h"

/*��ϣ��Ĵ�С*/
#define SIZE 211

/*��¼�������ֵ�ÿ���к�*/
typedef struct LineListRec
   { int lineno;
     struct LineListRec * next;
   } * LineList;

/*��ϣ�������������Ϣ*/
typedef struct BucketListRec
   { char * name;
     LineList lines;
     TreeNode *treeNode;
     int memloc ; /*��ű������ڴ�λ��*/
     struct BucketListRec * next;
   } * BucketList;

/*������*/
typedef struct ScopeRec
   { char * funcName;
     int nestedLevel; /*Ƕ����ȣ�ȫ��������Ϊ0*/
     struct ScopeRec * parent;
     BucketList hashTable[SIZE];
   } * Scope;

/*ȫ��������*/
Scope globalScope;

/*�½�������*/
Scope sc_create(char *funcName);

/*������������ʱջ�Ķ���������*/
Scope sc_top( void );

void sc_pop( void );
void sc_push( Scope scope );

/*����ڴ�λ��*/
int addLocation( void );

/*���ر������ڵĹ�ϣ��*/
BucketList st_bucket(char* name);

/*���ұ����Ƿ��Ѵ����ڷ��ű��������򷵻�-1*/
int st_lookup(char* name);

/*���ұ����Ƿ����������������ʱջ�Ķ�����������*/
int st_lookup_top(char* name);

/* ���������Ϣ�����ű���
 * loc = memory location ֻ��һ��ʼ����
 */
void st_insert(char* name, int lineno, int loc, TreeNode* treeNode);

/*��ӱ�������λ�õ��к�*/
void st_add_lineno(char* name, int lineno);

/*��ӡ��ʽ���ķ��ű�*/
void printSymTab(FILE * listing);

#endif
