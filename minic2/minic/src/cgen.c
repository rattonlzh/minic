/*
 * @Copyright: Copyright (c) 2020 SCNU Compiler Principle Project Group. All rights reserved.
 * @FilePath: /minic/cgen.c
 * @Description: 生成中间代码的实现
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

//全局变量的偏移量，其值的大小等于全职变量的数量的相反数
static int globalOffset = 0;
//当前函数的局部变量偏移量，从-2开始是为了预留位置分别存储当前mp的值和函数返回的地址
static int localOffset = initFO;

/* 当前作用域下的参数的数量 */
static int numOfParams = 0;

/* 用于标记是否为函数 */
static int isInFunc = FALSE;

/* 用于记录主函数的入口位置 */
static int mainFuncLoc = 0;

/* 中间代码生成函数的声明 */
static void cGen (TreeNode * tree);

/* 获取当前作用块下有多少数量的变量，用于计算当前函数的局部变量偏移量 */
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

/* 生成语句节点的中间代码 */
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

        /* 恢复偏移量 */
        localOffset += offset;

        if (TraceCode) emitComment("<- compound");

        break;

      case IfK:
        if (TraceCode) emitComment("-> if");

        p1 = tree->child[0];
        p2 = tree->child[1];
        p3 = tree->child[2];

        /* 生成测试语句的中间代码 */
        cGen(p1);

        savedLoc1 = emitSkip(1);
        emitComment("if: jump to else belongs here");

        /* 生成then子句的中间代码 */
        cGen(p2);

        savedLoc2 = emitSkip(1);
        emitComment("if: jump to end belongs here");

        /* 回填条件错误的中间代码 */
        currentLoc = emitSkip(0);
        emitBackup(savedLoc1);
        emitRM_Abs("JEQ",ac,currentLoc,"if: jmp to else");
        emitRestore();

        /* 生成else子句的中间代码 */
        cGen(p3);

        /* 立即转移语句的中间代码 */
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

        /* 生成test子句的中间代码 */
        cGen(p1);

        savedLoc2 = emitSkip(1);
        emitComment("while: jump to end belongs here");

        /* 生成循环体的中间代码 */
        cGen(p2);

        /* 回填跳转到测试语句的中间代码 */
        emitRM_Abs("LDA",pc,savedLoc1,"while: jmp back to test");

        /* 回填条件错误的中间代码 */
        currentLoc = emitSkip(0);
        emitBackup(savedLoc2);
        emitRM_Abs("JEQ",ac,currentLoc,"while: jmp to end");
        emitRestore();

        if (TraceCode)  emitComment("<- iter.");

        break;

      case RetK:
        if (TraceCode) emitComment("-> return");

        p1 = tree->child[0];

        /* 生成表达式的中间代码 */
        cGen(p1);
        emitRM("LD",pc,retFO,mp,"return: to caller");

        if (TraceCode) emitComment("<- return");

        break;
      default:
         break;
    }
} /* genStmt */

/* 生成表达式节点的中间代码 */
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

        /* 生成左操作数的中间代码，要记录左操作数的地址，设置lhs为true */
        genExp(p1, TRUE);

        /* 存储左操作数的地址 */
        emitRM("ST", ac, localOffset--, mp, "assign: push left (address)");

        /* 生成右操作数的中间代码 */
        cGen(p2);

        /* 装载左操作数的地址 */
        emitRM("LD", ac1, ++localOffset, mp, "assign: load left (address)");

        emitRM("ST", ac, 0, ac1, "assign: store value");

        if (TraceCode) emitComment("<- assign");
        break; /* assign_k */

    case OpK:
        if (TraceCode) emitComment("-> Op");

        p1 = tree->child[0];
        p2 = tree->child[1];

        /* 生成左操作数的中间代码 */
        cGen(p1);

        /* 存储左操作数的值 */
        emitRM("ST", ac, localOffset--, mp, "op: push left");

        /* 生成有操作数的中间代码 */
        cGen(p2);

        /* 装载左操作数的值 */
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

                /* 存储数组的基址 */
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

            /* 生成数组下标的中间代码 */
            p1 = tree->child[0];
            cGen(p1);
            /* 得到正确的地址t */
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
            /* 生成参数的中间代码 */
            if (p1->type == Array)
                genExp(p1, TRUE);
            else
                genExp(p1, FALSE);

            /* 保存参数的值 */
            emitRM("ST", ac, localOffset + initFO - (numOfArgs++), mp, "call: push argument");

            p1 = p1->sibling;
        }

        if (strcmp(tree->attr.name, "input") == 0) {
            /* 生成输入语句的中间代码 */
            emitRO("IN", ac, 0, 0, "read integer value");
        }
        else if (strcmp(tree->attr.name, "output") == 0) {
            /* 生成输出语句的中间代码 */
            emitRM("LD", ac, localOffset + initFO, mp, "load arg to ac");
            emitRO("OUT", ac, 0, 0, "write ac");
        }
        else {
            /* 保存当前的mp值 */
            emitRM("ST", mp, localOffset + ofpFO, mp, "call: store current mp");
            /* 计算新的mp值 */
            emitRM("LDA", mp, localOffset, mp, "call: push new frame");
            /* 计算函数返回的地址 */
            emitRM("LDA", ac, 1, pc, "call: save return in ac");

            /* 生成函数跳转语句的中间的代码 */
            loc = -(st_lookup(tree->attr.name) - 2);
            emitRM("LD", pc, loc, gp, "call: relative jump to function entry");

            /* 取出保存好的当前的mp值 */
            emitRM("LD", mp, ofpFO, mp, "call: pop current frame");
        }

        if (TraceCode)  emitComment("<- Call");

        break;

    default:
        break;
    }
}

/* 生成声明节点的中间代码 */
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

    /* 函数保存的位置 */
    loc = -(st_lookup(tree->attr.name)-2);
    loadFuncLoc = emitSkip(1);
    emitRM("ST", ac1, loc, gp, "func: store the location of func. entry");

    --globalOffset;

    /* 跳转到下个函数的声明处 */
    jmpLoc = emitSkip(1);
    emitComment(
        "func: unconditional jump to next declaration belongs here");

    /* 函数开始执行的入口 */
    funcBodyLoc = emitSkip(0);
    emitComment("func: function body starts here");

    /* 回填函数保存的位置 */
    emitBackup(loadFuncLoc);
    emitRM("LDC", ac1, funcBodyLoc, 0, "func: load function location");
    emitRestore();

    /* 保存函数的返回地址 */
    emitRM("ST", ac, retFO, mp, "func: store return address");

    /* 计算局部变量的偏移量和参数的数量 */
    localOffset = initFO;
    numOfParams = 0;
    cGen(p1);

    /* 生成函数体的中间代码 */
    if (strcmp(tree->attr.name, "main") == 0)
      mainFuncLoc = funcBodyLoc;

    cGen(p2);

    /* 通过函数保存的返回值返回 */
    emitRM("LD", pc, retFO, mp, "func: load pc with return address");

    /* 回填跳转到下个函数的声明处 */
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

/* 生成参数节点的中间代码 */
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

/* 通过此函数遍历语法树节点以生成相应的中间代码 */
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

/*用于调用主函数*/
void genMainCall() {
  if (TraceCode) emitComment("-> Call");

  /* 保存当前的mp值 */
  emitRM("ST", mp, globalOffset, mp, "call: store current mp");
  /* 计算得到新的mp值 */
  emitRM("LDA", mp, globalOffset, mp, "call: push new frame");
  /* 计算函数的返回地址 */
  emitRM("LDA", ac, 1, pc, "call: save return in ac");
  /* 跳转到main函数 */
  emitRM("LDC", pc, mainFuncLoc, 0, "call: unconditional jump to main() entry");
  /* 取出保存好的当前的mp值 */
  emitRM("LD", mp, ofpFO, mp, "call: pop current frame");

  if (TraceCode) emitComment("<- Call");
}

/**********************************************/
/* 输出中间代码的主程序 */
/**********************************************/
/* 供外部调用的生成中间代码的接口 */
void codeGen(TreeNode* syntaxTree, char* codefile)
{
    char* s = malloc(strlen(codefile) + 7);
    strcpy(s, "File: ");
    strcat(s, codefile);
    emitComment("TINY Compilation to TM Code");
    emitComment(s);
    /* 生成标准段的中间代码 */
    emitComment("Standard prelude:");
    emitRM("LD",gp,0,ac,"load gp with maxaddress");
    emitRM("LDA",mp,0,gp,"copy gp to mp");
    emitRM("ST", ac, 0, ac, "clear location 0");
    emitComment("End of standard prelude.");

    sc_push(globalScope);
    cGen(syntaxTree);
    sc_pop();

    /* 调用主函数 */
    genMainCall();

    emitComment("End of execution.");
    emitRO("HALT", 0, 0, 0, "");
}
