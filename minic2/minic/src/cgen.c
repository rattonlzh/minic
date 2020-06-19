/*
 * @Copyright: Copyright (c) 2020 SCNU Compiler Principle Project Group. All rights reserved.
 * @FilePath: /minic/cgen.c
 * @Description: �����м�����ʵ��
 * @Version: 1.0
 * @Author: Liang Zehao, Zhang Yongbiao
 * @Date: 2020-06-17 12:52:55
 * @LastEditTime: 2020-06-18 20:23:57
 * @LastEditors: Zhang Yongbiao
 */

#include "globals.h"
#include "symtab.h"
#include "code.h"
#include "cgen.h"

static char buffer[1000];

#define ofpFO 0
#define retFO -1
#define initFO -2

//ȫ�ֱ�����ƫ��������ֵ�Ĵ�С����ȫְ�������������෴��
static int globalOffset = 0;
//��ǰ�����ľֲ�����ƫ��������-2��ʼ��Ϊ��Ԥ��λ�÷ֱ�洢��ǰmp��ֵ�ͺ������صĵ�ַ
static int localOffset = initFO;

/* ��ǰ�������µĲ��������� */
static int numOfParams = 0;

/* ���ڱ���Ƿ�Ϊ���� */
static int isInFunc = FALSE;

/* ���ڼ�¼�����������λ�� */
static int mainFuncLoc = 0;

/* �м�������ɺ��������� */
static void cGen (TreeNode * tree);

/* ��ȡ��ǰ���ÿ����ж��������ı��������ڼ��㵱ǰ�����ľֲ�����ƫ���� */
static int getBlockOffset(TreeNode *list) {
  int offset = 0;

  if (list == NULL) {
  } else if (list->nodekind == DeclK) {
    TreeNode *node = list;
    while (node != NULL) {
      switch (node->kind.decl) {
      case VarK:
        ++offset;
        break;
      case ArrVarK:
        offset += node->attr.arr.size;
        break;
      default:
        break;
      }
      node = node->sibling;
    }
  } else if (list->nodekind == ParamK) {
    TreeNode *node = list;
    while (node != NULL) {
      ++offset;
      node = node->sibling;
    }
  }

  return offset;
}

/* �������ڵ���м���� */
static void genStmt( TreeNode * tree )
{ TreeNode * p1, * p2, * p3;
  int savedLoc1,savedLoc2,currentLoc;
  int loc;
  int offset;
  switch (tree->kind.stmt) {

      case CompK:
        if (TraceCode) emitComment("-> compound");

        p1 = tree->child[0];
        p2 = tree->child[1];

        offset = getBlockOffset(p1);
        localOffset -= offset;

        sc_push(tree->attr.scope);

        cGen(p2);

        sc_pop();

        /* �ָ�ƫ���� */
        localOffset += offset;

        if (TraceCode) emitComment("<- compound");

        break;

      case IfK:
        if (TraceCode) emitComment("-> if");

        p1 = tree->child[0];
        p2 = tree->child[1];
        p3 = tree->child[2];

        /* ���ɲ��������м���� */
        cGen(p1);

        savedLoc1 = emitSkip(1);
        emitComment("if: jump to else belongs here");

        /* ����then�Ӿ���м���� */
        cGen(p2);

        savedLoc2 = emitSkip(1);
        emitComment("if: jump to end belongs here");

        /* ��������������м���� */
        currentLoc = emitSkip(0);
        emitBackup(savedLoc1);
        emitRM_Abs("JEQ",ac,currentLoc,"if: jmp to else");
        emitRestore();

        /* ����else�Ӿ���м���� */
        cGen(p3);

        /* ����ת�������м���� */
        currentLoc = emitSkip(0);
        emitBackup(savedLoc2);
        emitRM_Abs("LDA",pc,currentLoc,"jmp to end");
        emitRestore();
        if (TraceCode)  emitComment("<- if");

        break;

      case IterK:
        if (TraceCode) emitComment("-> iter.");

        p1 = tree->child[0];
        p2 = tree->child[1];

        savedLoc1 = emitSkip(0);
        emitComment("while: jump after body comes back here");

        /* ����test�Ӿ���м���� */
        cGen(p1);

        savedLoc2 = emitSkip(1);
        emitComment("while: jump to end belongs here");

        /* ����ѭ������м���� */
        cGen(p2);

        /* ������ת�����������м���� */
        emitRM_Abs("LDA",pc,savedLoc1,"while: jmp back to test");

        /* ��������������м���� */
        currentLoc = emitSkip(0);
        emitBackup(savedLoc2);
        emitRM_Abs("JEQ",ac,currentLoc,"while: jmp to end");
        emitRestore();

        if (TraceCode)  emitComment("<- iter.");

        break;

      case RetK:
        if (TraceCode) emitComment("-> return");

        p1 = tree->child[0];

        /* ���ɱ��ʽ���м���� */
        cGen(p1);
        emitRM("LD",pc,retFO,mp,"return: to caller");

        if (TraceCode) emitComment("<- return");

        break;
      default:
         break;
    }
} /* genStmt */

/* ���ɱ��ʽ�ڵ���м���� */
static void genExp(TreeNode* tree, int lhs)
{
    int loc;
    int varOffset, baseReg;
    int numOfArgs;
    TreeNode* p1, * p2;
    switch (tree->kind.exp) {
    case AssignK:
        if (TraceCode) emitComment("-> assign");

        p1 = tree->child[0];
        p2 = tree->child[1];

        /* ��������������м���룬Ҫ��¼��������ĵ�ַ������lhsΪtrue */
        genExp(p1, TRUE);

        /* �洢��������ĵ�ַ */
        emitRM("ST", ac, localOffset--, mp, "assign: push left (address)");

        /* �����Ҳ��������м���� */
        cGen(p2);

        /* װ����������ĵ�ַ */
        emitRM("LD", ac1, ++localOffset, mp, "assign: load left (address)");

        emitRM("ST", ac, 0, ac1, "assign: store value");

        if (TraceCode) emitComment("<- assign");
        break; /* assign_k */

    case OpK:
        if (TraceCode) emitComment("-> Op");

        p1 = tree->child[0];
        p2 = tree->child[1];

        /* ��������������м���� */
        cGen(p1);

        /* �洢���������ֵ */
        emitRM("ST", ac, localOffset--, mp, "op: push left");

        /* �����в��������м���� */
        cGen(p2);

        /* װ�����������ֵ */
        emitRM("LD", ac1, ++localOffset, mp, "op: load left");

        switch (tree->attr.op) {
        case PLUS:
            emitRO("ADD", ac, ac1, ac, "op +");
            break;
        case MINUS:
            emitRO("SUB", ac, ac1, ac, "op -");
            break;
        case TIMES:
            emitRO("MUL", ac, ac1, ac, "op *");
            break;
        case OVER:
            emitRO("DIV", ac, ac1, ac, "op /");
            break;
        case LT:
            emitRO("SUB", ac, ac1, ac, "op <");
            emitRM("JLT", ac, 2, pc, "br if true");
            emitRM("LDC", ac, 0, ac, "false case");
            emitRM("LDA", pc, 1, pc, "unconditional jmp");
            emitRM("LDC", ac, 1, ac, "true case");
            break;
        case LTEQ:
            emitRO("SUB", ac, ac1, ac, "op <=");
            emitRM("JLE", ac, 2, pc, "br if true");
            emitRM("LDC", ac, 0, ac, "false case");
            emitRM("LDA", pc, 1, pc, "unconditional jmp");
            emitRM("LDC", ac, 1, ac, "true case");
            break;
        case GT:
            emitRO("SUB", ac, ac1, ac, "op >");
            emitRM("JGT", ac, 2, pc, "br if true");
            emitRM("LDC", ac, 0, ac, "false case");
            emitRM("LDA", pc, 1, pc, "unconditional jmp");
            emitRM("LDC", ac, 1, ac, "true case");
            break;
        case GTEQ:
            emitRO("SUB", ac, ac1, ac, "op >=");
            emitRM("JGE", ac, 2, pc, "br if true");
            emitRM("LDC", ac, 0, ac, "false case");
            emitRM("LDA", pc, 1, pc, "unconditional jmp");
            emitRM("LDC", ac, 1, ac, "true case");
            break;
        case EQ:
            emitRO("SUB", ac, ac1, ac, "op ==");
            emitRM("JEQ", ac, 2, pc, "br if true");
            emitRM("LDC", ac, 0, ac, "false case");
            emitRM("LDA", pc, 1, pc, "unconditional jmp");
            emitRM("LDC", ac, 1, ac, "true case");
            break;
        case NEQ:
            emitRO("SUB", ac, ac1, ac, "op !=");
            emitRM("JNE", ac, 2, pc, "br if true");
            emitRM("LDC", ac, 0, ac, "false case");
            emitRM("LDA", pc, 1, pc, "unconditional jmp");
            emitRM("LDC", ac, 1, ac, "true case");
            break;
        default:
            emitComment("BUG: Unknown operator");
            break;
        }

        if (TraceCode)  emitComment("<- Op");

        break;

    case ConstK:
        if (TraceCode) emitComment("-> Const");
        emitRM("LDC", ac, tree->attr.val, 0, "load const");
        if (TraceCode)  emitComment("<- Const");
        break;

    case IdK:
    case ArrIdK:
        if (TraceCode) {
            sprintf(buffer, "-> Id (%s)", tree->attr.name);
            emitComment(buffer);
        }

        loc = -1;
        if (globalScope == st_scope(tree->attr.name)) {
            varOffset = -(st_lookup(tree->attr.name) - 2);
        }
        else {
            loc = st_lookup(tree->attr.name);
            varOffset = initFO - loc;
        }

        /* generate code to load varOffset */
        emitRM("LDC", ac, varOffset, 0, "id: load varOffset");

        if (tree->kind.exp == ArrIdK) {
            if (loc >= 0 && loc < numOfParams) {

                /* �洢����Ļ�ַ */
                emitRO("ADD", ac, mp, ac, "id: load the memory address of base address of array to ac");
                emitRO("LD", ac, 0, ac, "id: load the base address of array to ac");
            }
            else {
                if (loc >= 0)
                    emitRO("ADD", ac, mp, ac, "id: calculate the address");
                else
                    emitRO("ADD", ac, gp, ac, "id: calculate the address");
            }

            emitRM("ST", ac, localOffset--, mp, "id: push base address");

            /* ���������±���м���� */
            p1 = tree->child[0];
            cGen(p1);
            /* �õ���ȷ�ĵ�ַt */
            emitRM("LD", ac1, ++localOffset, mp, "id: pop base address");
            emitRO("SUB", ac, ac1, ac, "id: calculate element address with index");
        }
        else {
            if (loc >= 0)
                emitRO("ADD", ac, mp, ac, "id: calculate the address");
            else
                emitRO("ADD", ac, gp, ac, "id: calculate the address");
        }

        if (lhs) {
            TreeNode* symbolDecl = st_bucket(tree->attr.name)->treeNode;
            if (tree->kind.exp == IdK && symbolDecl->nodekind == ParamK && symbolDecl->kind.param == ArrParamK)
                emitRM("LD", ac, 0, ac, "id: load the base address of array to ac");
            else
                emitRM("LDA", ac, 0, ac, "load id address");
        }
        else {
            emitRM("LD", ac, 0, ac, "load id value");
        }

        if (TraceCode)  emitComment("<- Id");

        break;

    case CallK:
        if (TraceCode) emitComment("-> Call");

        numOfArgs = 0;

        p1 = tree->child[0];

        while (p1 != NULL) {
            /* ���ɲ������м���� */
            if (p1->type == Array)
                genExp(p1, TRUE);
            else
                genExp(p1, FALSE);

            /* ���������ֵ */
            emitRM("ST", ac, localOffset + initFO - (numOfArgs++), mp, "call: push argument");

            p1 = p1->sibling;
        }

        if (strcmp(tree->attr.name, "input") == 0) {
            /* �������������м���� */
            emitRO("IN", ac, 0, 0, "read integer value");
        }
        else if (strcmp(tree->attr.name, "output") == 0) {
            /* ������������м���� */
            emitRM("LD", ac, localOffset + initFO, mp, "load arg to ac");
            emitRO("OUT", ac, 0, 0, "write ac");
        }
        else {
            /* ���浱ǰ��mpֵ */
            emitRM("ST", mp, localOffset + ofpFO, mp, "call: store current mp");
            /* �����µ�mpֵ */
            emitRM("LDA", mp, localOffset, mp, "call: push new frame");
            /* ���㺯�����صĵ�ַ */
            emitRM("LDA", ac, 1, pc, "call: save return in ac");

            /* ���ɺ�����ת�����м�Ĵ��� */
            loc = -(st_lookup(tree->attr.name) - 2);
            emitRM("LD", pc, loc, gp, "call: relative jump to function entry");

            /* ȡ������õĵ�ǰ��mpֵ */
            emitRM("LD", mp, ofpFO, mp, "call: pop current frame");
        }

        if (TraceCode)  emitComment("<- Call");

        break;

    default:
        break;
    }
}

/* ���������ڵ���м���� */
static void genDecl( TreeNode * tree)
{ TreeNode * p1, * p2;
  int loadFuncLoc,jmpLoc,funcBodyLoc,nextDeclLoc;
  int loc;
  int size;

  switch (tree->kind.decl) {
  case FuncK:
      if (TraceCode) {
          sprintf(buffer, "-> Function (%s)", tree->attr.name);
          emitComment(buffer);
      }

    p1 = tree->child[1];
    p2 = tree->child[2];

    isInFunc = TRUE;

    /* ���������λ�� */
    loc = -(st_lookup(tree->attr.name)-2);
    loadFuncLoc = emitSkip(1);
    emitRM("ST", ac1, loc, gp, "func: store the location of func. entry");

    --globalOffset;

    /* ��ת���¸������������� */
    jmpLoc = emitSkip(1);
    emitComment(
        "func: unconditional jump to next declaration belongs here");

    /* ������ʼִ�е���� */
    funcBodyLoc = emitSkip(0);
    emitComment("func: function body starts here");

    /* ����������λ�� */
    emitBackup(loadFuncLoc);
    emitRM("LDC", ac1, funcBodyLoc, 0, "func: load function location");
    emitRestore();

    /* ���溯���ķ��ص�ַ */
    emitRM("ST", ac, retFO, mp, "func: store return address");

    /* ����ֲ�������ƫ�����Ͳ��������� */
    localOffset = initFO;
    numOfParams = 0;
    cGen(p1);

    /* ���ɺ�������м���� */
    if (strcmp(tree->attr.name, "main") == 0)
      mainFuncLoc = funcBodyLoc;

    cGen(p2);

    /* ͨ����������ķ���ֵ���� */
    emitRM("LD", pc, retFO, mp, "func: load pc with return address");

    /* ������ת���¸������������� */
    nextDeclLoc = emitSkip(0);
    emitBackup(jmpLoc);
    emitRM_Abs("LDA", pc, nextDeclLoc,
        "func: unconditional jump to next declaration");
    emitRestore();

    isInFunc = FALSE;

    if (TraceCode) {
        sprintf(buffer, "<- Function (%s)", tree->attr.name);
      emitComment(buffer);
    }

    break;

  case VarK:
  case ArrVarK:
    if (TraceCode) emitComment("-> var. decl.");

    if (tree->kind.decl == ArrVarK)
      size = tree->attr.arr.size;
    else
      size = 1;

    if (isInFunc == TRUE)
      localOffset -= size;
    else
      globalOffset -= size;

    if (TraceCode) emitComment("<- var. decl.");
    break;

  default:
     break;
  }
}

/* ���ɲ����ڵ���м���� */
static void genParam( TreeNode * tree)
{ switch (tree->kind.stmt) {

  case ArrParamK:
  case NonArrParamK:
    if (TraceCode) emitComment("-> param");
    emitComment(tree->attr.name);

    --localOffset;
    ++numOfParams;

    if (TraceCode) emitComment("<- param");

    break;

  default:
     break;
  }
}

/* ͨ���˺��������﷨���ڵ���������Ӧ���м���� */
static void cGen( TreeNode * tree )
{ if (tree != NULL)
  { switch (tree->nodekind) {
      case StmtK:
        genStmt(tree);
        break;
      case ExpK:
        genExp(tree, FALSE);
        break;
      case DeclK:
        genDecl(tree);
        break;
      case ParamK:
        genParam(tree);
        break;
      default:
        break;
    }
    cGen(tree->sibling);
  }
}

/*���ڵ���������*/
void genMainCall() {
  if (TraceCode) emitComment("-> Call");

  /* ���浱ǰ��mpֵ */
  emitRM("ST", mp, globalOffset, mp, "call: store current mp");
  /* ����õ��µ�mpֵ */
  emitRM("LDA", mp, globalOffset, mp, "call: push new frame");
  /* ���㺯���ķ��ص�ַ */
  emitRM("LDA", ac, 1, pc, "call: save return in ac");
  /* ��ת��main���� */
  emitRM("LDC", pc, mainFuncLoc, 0, "call: unconditional jump to main() entry");
  /* ȡ������õĵ�ǰ��mpֵ */
  emitRM("LD", mp, ofpFO, mp, "call: pop current frame");

  if (TraceCode) emitComment("<- Call");
}

/**********************************************/
/* ����м����������� */
/**********************************************/
/* ���ⲿ���õ������м����Ľӿ� */
void codeGen(TreeNode* syntaxTree, char* codefile)
{
    char* s = malloc(strlen(codefile) + 7);
    strcpy(s, "File: ");
    strcat(s, codefile);
    emitComment("TINY Compilation to TM Code");
    emitComment(s);
    /* ���ɱ�׼�ε��м���� */
    emitComment("Standard prelude:");
    emitRM("LD",gp,0,ac,"load gp with maxaddress");
    emitRM("LDA",mp,0,gp,"copy gp to mp");
    emitRM("ST", ac, 0, ac, "clear location 0");
    emitComment("End of standard prelude.");

    sc_push(globalScope);
    cGen(syntaxTree);
    sc_pop();

    /* ���������� */
    genMainCall();

    emitComment("End of execution.");
    emitRO("HALT", 0, 0, 0, "");
}
