#include "globals.h"
#include "symtab.h"
#include "analyze.h"
#include "util.h"

// 语义分析过程中当前处理的函数名
static char *funcName;

/*记录是否保存了语句体外的作用域*/
static int preserveLastScope = FALSE;

/* 遍历语法树
 * 用前序遍历执行preProc
 * 用后序遍历执行postProc
 */
static void traverse(TreeNode *t, void (*preProc)(TreeNode *), void (*postProc)(TreeNode *))
{
    if (t != NULL)
    {
        preProc(t);
        {
            int i;
            for (i = 0; i < MAXCHILDREN; i++)
                traverse(t->child[i], preProc, postProc);
        }
        postProc(t);
        traverse(t->sibling, preProc, postProc);
    }
}

/* 什么都没组的函数，暂时没有用到
 * nullProc is a do-nothing procedure to
 * generate preorder-only or postorder-only
 * traversals from traverse
 */
static void nullProc(TreeNode *t)
{
    if (t == NULL)
        return;
    else
        return;
}

/*将input和output函数插入到符号表中*/
static void insertIOFunc(void)
{
    TreeNode *func;
    TreeNode *typeSpec;
    TreeNode *param;
    TreeNode *compStmt;

    func = newDeclNode(FuncK);

    typeSpec = newTypeNode(TypeNameK);
    typeSpec->attr.type = INT;
    func->type = Integer;

    compStmt = newStmtNode(CompK);
    compStmt->child[0] = NULL; // no local var
    compStmt->child[1] = NULL; // no stmt

    func->lineno = 0;
    strcpy(func->attr.name, "input");
    func->child[0] = typeSpec;
    func->child[1] = NULL; // no param
    func->child[2] = compStmt;
    /* 因为声明不在源文件中出现，所以行号设为-1*/
    st_insert("input", -1, addLocation(), func);

    func = newDeclNode(FuncK);

    typeSpec = newTypeNode(TypeNameK);
    typeSpec->attr.type = VOID;
    func->type = Void;

    param = newParamNode(NonArrParamK);
    strcpy(param->attr.name, "arg");
    param->child[0] = newTypeNode(TypeNameK);
    param->child[0]->attr.type = INT;

    compStmt = newStmtNode(CompK);
    compStmt->child[0] = NULL; // no local var
    compStmt->child[1] = NULL; // no stmt

    func->lineno = 0;
    strcpy(func->attr.name, "output");
    func->child[0] = typeSpec;
    func->child[1] = param;
    func->child[2] = compStmt;

    st_insert("output", -1, addLocation(), func);
}

/*符号错误的输出函数，提示错误所在行号和错误信息*/
static void symbolError(TreeNode *t, char *message)
{
    fprintf(listing, "Symbol error at line %d: %s\n", t->lineno, message);
    Error = TRUE;
}

/* 将语法树节点的相关信息插入到符号表中
 * 同时也会有用的信息保存到语法树节点中
 */
static void insertNode(TreeNode *t)
{
    switch (t->nodekind)
    {
    case StmtK:
        switch (t->kind.stmt)
        {
        case CompK:

            if (preserveLastScope)
            {
                preserveLastScope = FALSE;
            }
            else
            {
                Scope scope = sc_create(funcName);
                sc_push(scope);
            }
            t->attr.scope = sc_top();
            break;
        default:
            break;
        }
        break;
    case ExpK:
        switch (t->kind.exp)
        {
        case IdK:
        case ArrIdK:
        case CallK:
            // 如果当前无法在相关的作用域中找到符号，则打印错误信息提示符号未声明
            if (st_lookup(t->attr.name) == -1)
                symbolError(t, "undelcared symbol");
            else
                st_add_lineno(t->attr.name, t->lineno);
            break;
        default:
            break;
        }
        break;
    case DeclK:
        switch (t->kind.decl)
        {
        case FuncK:
            funcName = t->attr.name;
            // 如果声明的函数已经在前面被定义则报错
            if (st_lookup_top(funcName) != -1)
            {
                symbolError(t, "function already declared");
                break;
            }
            // 插入符号
            st_insert(funcName, t->lineno, addLocation(), t);
            // 创建并进入函数作用域
            sc_push(sc_create(funcName));
            preserveLastScope = TRUE;
            switch (t->child[0]->attr.type)
            {
            case INT:
                t->type = Integer;
                break;
            case VOID:
            default:
                t->type = Void;
                break;
            }
            break;
        case VarK:
        case ArrVarK:
        {
            char *name;

            if (t->child[0]->attr.type == VOID)
            {
                symbolError(t, "variable should have non-void type");
                break;
            }

            if (t->kind.decl == VarK)
            {
                name = t->attr.name;
                t->type = Integer;
            }
            else
            {
                name = t->attr.arr.name;
                t->type = Array;
            }

            if (st_lookup_top(name) == -1)
                st_insert(name, t->lineno, addLocation(), t);
            else
                symbolError(t, "symbol already declared for current scope");
        }
        break;
        default:
            break;
        }
        break;
    case ParamK:
        if (t->child[0]->attr.type == VOID)
            symbolError(t->child[0], "void type parameter is not allowed");
        if (st_lookup(t->attr.name) == -1)
        {
            st_insert(t->attr.name, t->lineno, addLocation(), t);
            if (t->kind.param == NonArrParamK)
                t->type = Integer;
            else
                t->type = Array;
        }
        else
            symbolError(t, "symbol already declared for current scope");
        break;
    default:
        break;
    }
}

static void afterInsertNode(TreeNode *t)
{
    switch (t->nodekind)
    {
    case StmtK:
        switch (t->kind.stmt)
        {
        case CompK:
            //   函数体结束是，作用域失效，需要pop
            sc_pop();
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

/* 建立符号表 */
void buildSymtab(TreeNode *syntaxTree)
{
    // 创建全局作用域
    globalScope = sc_create(NULL);
    sc_push(globalScope);
    insertIOFunc();
    traverse(syntaxTree, insertNode, afterInsertNode);
    sc_pop();
    if (TraceAnalyze)
    {
        fprintf(listing, "\nSymbol table:\n\n");
        printSymTab(listing);
    }
}

/*类型错误的输出函数*/
static void typeError(TreeNode *t, char *message)
{
    fprintf(listing, "Type error at line %d: %s\n", t->lineno, message);
    Error = TRUE;
}

static void beforeCheckNode(TreeNode *t)
{
    switch (t->nodekind)
    {
    case DeclK:
        switch (t->kind.decl)
        {
        case FuncK:
            funcName = t->attr.name;
            break;
        default:
            break;
        }
        break;
    case StmtK:
        switch (t->kind.stmt)
        {
        case CompK:
            sc_push(t->attr.scope);
            break;
        default:
            break;
        }
    default:
        break;
    }
}

/* 配合语法树对应节点的信息对符号表进行类型检查
 * 同时也会有用的信息保存到语法树节点中
 */
static void checkNode(TreeNode *t)
{
    switch (t->nodekind)
    {
    case StmtK:
        switch (t->kind.stmt)
        {
        case CompK:
            sc_pop();
            break;
            //case IterK:
            //  if (t->child[0]->type == Void)
            //    typeError(t->child[0],"while test has void value");
            //  break;
        case RetK:
        {
            const TreeNode *funcDecl =
                st_bucket(funcName)->treeNode;
            const ExpType funcType = funcDecl->type;
            const TreeNode *expr = t->child[0];

            if (funcType == Void &&
                (expr != NULL && expr->type != Void))
            {
                typeError(t, "expected no return value");
            }
            else if (funcType == Integer &&
                     (expr == NULL || expr->type == Void))
            {
                typeError(t, "expected return value");
            }
        }
        break;
        default:
            break;
        }
        break;
    case ExpK:
        switch (t->kind.exp)
        {
        case AssignK:
        case OpK:
            if (t->child[0]->type != Integer)
                typeError(t->child[0], "type error of the left operand");
            else if (t->child[1]->type != Integer)
                typeError(t->child[1], "type error of the right operand");
            else
                t->type = Integer;
            break;
        case ConstK:
            t->type = Integer;
            break;
        case IdK:
        case ArrIdK:
        {
            char *symbolName = t->attr.name;
            const BucketList bucket =
                st_bucket(symbolName);
            TreeNode *symbolDecl = NULL;

            if (bucket == NULL)
                break;
            symbolDecl = bucket->treeNode;

            if (t->kind.exp == ArrIdK)
            {
                if (symbolDecl->kind.decl != ArrVarK &&
                    symbolDecl->kind.param != ArrParamK)
                    typeError(t, "expected array symbol");
                else if (t->child[0]->type != Integer)
                    typeError(t, "index expression should have integer type");
                else
                    t->type = Integer;
            }
            else
            {
                t->type = symbolDecl->type;
            }
        }
        break;
        case CallK:
        {
            char *callingFuncName = t->attr.name;
            const TreeNode *funcDecl =
                st_bucket(callingFuncName)->treeNode;
            TreeNode *arg;
            TreeNode *param;

            if (funcDecl == NULL)
                break;

            arg = t->child[0];
            param = funcDecl->child[1];

            if (funcDecl->kind.decl != FuncK)
            {
                typeError(t, "expected function symbol");
                break;
            }

            while (arg != NULL)
            {
                if (param == NULL)
                    typeError(arg, "the number of parameters is wrong");
                else if (arg->type == Array &&
                         param->type != Array)
                    typeError(arg, "expected non-array value");
                else if (arg->type == Integer &&
                         param->type == Array)
                    typeError(arg, "expected array value");
                else if (arg->type == Void)
                    typeError(arg, "void value cannot be passed as an argument");
                else
                {
                    arg = arg->sibling;
                    param = param->sibling;
                    continue;
                }
                break;
            }

            if (arg == NULL && param != NULL)
                typeError(t->child[0], "the number of parameters is wrong");

            t->type = funcDecl->type;
        }
        break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

void typeCheck(TreeNode *syntaxTree)
{
    sc_push(globalScope);
    traverse(syntaxTree, beforeCheckNode, checkNode);
    sc_pop();
}
