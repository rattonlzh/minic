#include "util.h"

/**
 * @brief 打印词法符号
 * 
 * @param token 
 * @param tokenString 
 */
void printToken(TokenType token, const char *tokenString)
{
    switch (token)
    {
    case IF:
    case ELSE:
    case WHILE:
    case RETURN:
    case INT:
    case VOID:
        fprintf(listing, "reserved word: %s\n", tokenString);
        break;
    case ASSIGN:
    case EQ:
    case NEQ:
    case LTEQ:
    case GTEQ:
    case LT:
    case GT:
    case PLUS:
    case MINUS:
    case TIMES:
    case OVER:
        fprintf(listing, "operator: %s\n", tokenString);
        break;
    case LP:
    case RP:
    case LB:
    case RB:
    case LC:
    case RC:
    case SEMI:
    case COMMA:
        fprintf(listing, "punctuation: %s\n", tokenString);
        break;
    case ID:
        fprintf(listing, "ID: %s\n", tokenString);
        break;
    case NUM:
        fprintf(listing, "NUM: %s\n", tokenString);
        break;
    case ERROR:
        fprintf(listing, "ERROR: %s\n", tokenString);
        break;
    case ENDFILE:
        fprintf(listing, "<<EOF>>\n");
        break;

    default: /* should never happen */
        fprintf(listing, "Unknown token: %d\n", token);
    }
}

/* 新建 语句节点 */
TreeNode *newStmtNode(StmtKind kind)
{
    TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
    int i;
    if (t == NULL)
    {
        fprintf(listing, "Out of memory error at line %d\n", lineno);
    }
    else
    {
        for (i = 0; i < MAXCHILDREN; i++)
        {
            t->child[i] = NULL;
        }
        t->sibling = NULL;
        t->nodekind = StmtK;
        t->kind.stmt = kind;
        t->lineno = lineno;
    }
    return t;
}

/* 新建 表达式节点 */
TreeNode *newExpNode(ExpKind kind)
{
    TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
    int i;
    if (t == NULL)
    {
        fprintf(listing, "Out of memory error at line %d\n", lineno);
    }
    else
    {
        for (i = 0; i < MAXCHILDREN; i++)
        {
            t->child[i] = NULL;
        }
        t->sibling = NULL;
        t->nodekind = ExpK;
        t->kind.stmt = kind;
        t->lineno = lineno;
        t->type = Void;
    }
    return t;
}

/* 新建 定义节点 */
TreeNode *newDeclNode(DeclKind kind)
{
    TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
    int i;
    if (t == NULL)
    {
        fprintf(listing, "Out of memory error at line %d\n", lineno);
    }
    else
    {
        for (i = 0; i < MAXCHILDREN; i++)
        {
            t->child[i] = NULL;
        }
        t->sibling = NULL;
        t->nodekind = DeclK;
        t->kind.stmt = kind;
        t->lineno = lineno;
    }
    return t;
}

/* 新建 参数节点 */
TreeNode *newParamNode(ParamKind kind)
{
    TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
    int i;
    if (t == NULL)
    {
        fprintf(listing, "Out of memory error at line %d\n", lineno);
    }
    else
    {
        for (i = 0; i < MAXCHILDREN; i++)
        {
            t->child[i] = NULL;
        }
        t->sibling = NULL;
        t->nodekind = ParamK;
        t->kind.stmt = kind;
        t->lineno = lineno;
    }
    return t;
}

/* 新建 类型节点 */
TreeNode *newTypeNode(TypeKind kind)
{
    TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
    int i;
    if (t == NULL)
    {
        fprintf(listing, "Out of memory error at line %d\n", lineno);
    }
    else
    {
        for (i = 0; i < MAXCHILDREN; i++)
        {
            t->child[i] = NULL;
        }
        t->sibling = NULL;
        t->nodekind = TypeK;
        t->kind.stmt = kind;
        t->lineno = lineno;
    }
    return t;
}

/**
 * @brief 打印语法树显示的缩进格式
 * 
 * @param closed 
 * @param k 
 */
static void printIndent(int closed[], int k)
{
    if (k <= 0)
        return;
    for (int i = 0; i < k; i++)
    {
        if (closed[i])
        {
            fprintf(listing, "    ");
        }
        else
        {
            fprintf(listing, "│   ");
        }
    }
    if (closed[k])
    {
        fprintf(listing, "└── ");
    }
    else
    {
        fprintf(listing, "├── ");
    }
}

/**
 * @brief 打印语法树的辅助函数
 * 
 * @param tree 
 * @param closed 
 * @param level 
 * @param isLast
 */
void printTreeHelper(TreeNode *tree, int closed[], int level, int isLast)
{
    if (!tree)
    {
        return;
    }
    int i;
    // 正确打印语法树的连接线的关键是确定当前节点是否为同层的最后一个节点(简称末节点)
    // 先考虑兄弟节点的问题,如果当前节点存在sibling节点,那么
    // 它一定不是末节点;如果本节点不是末节点,则本节点的兄弟链表的尾节点也一定不是末节点
    int old = isLast;
    while (tree)
    {
        if (tree->sibling)
        {
            closed[level] = FALSE;
        } else
        {
            if (isLast)
            {
                closed[level] = TRUE;
            }else 
            {
                closed[level] = FALSE;
            }
            if (!old)
            {
                closed[level] = FALSE;
            }
        }
        printIndent(closed, level);
        
        switch (tree->nodekind)
        {
        case StmtK:
        {
            switch (tree->kind.stmt)
            {
            case IfK:
                fprintf(listing, "If\n");
                break;
            case IterK:
                fprintf(listing, "While\n");
                break;
            case RetK:
                fprintf(listing, "Return\n");
                break;
            case CompK:
                fprintf(listing, "Compound Statment\n");
                break;
            default:
                fprintf(listing, "Unknown StmtNode kind\n");
                break;
            }
        }
        break;

        case ExpK:
        {
            switch (tree->kind.exp)
            {
            case AssignK:
                fprintf(listing, "Assign\n");
                break;
            case CallK:
                fprintf(listing, "Call function: %s\n",
                        tree->attr.name);
                break;
            case OpK:
                fprintf(listing, "Op: ");
                printToken(tree->attr.op, "\0");
                break;
            case ConstK:
                fprintf(listing, "Const: %d\n", tree->attr.val);
                break;
            case IdK:
                fprintf(listing, "Id: %s\n", tree->attr.name);
                break;
            case ArrIdK:
                fprintf(listing, "Array Id: %s\n", tree->attr.name);
                break;

            default:
                fprintf(listing, "Unknown ExpNode kind\n");
                break;
            }
        }
        break;

        case DeclK:
        {
            switch (tree->kind.decl)
            {
            case VarK:
                fprintf(listing, "VarDec: %s\n", tree->attr.name);
                break;
            case FuncK:
                fprintf(listing, "FuncDec: %s\n", tree->attr.name);
                break;
            case ArrVarK:
                fprintf(listing, "ArrVarDec: %s, len: %d\n",
                        tree->attr.arr.name, tree->attr.arr.size);
                break;

            default:
                fprintf(listing, "Unknown DecNode kind\n");
                break;
            }
        }
        break;

        case ParamK:
        {
            switch (tree->kind.param)
            {
            case ArrParamK:
                fprintf(listing, "Array Parameter: %s\n",
                        tree->attr.name);
                break;
            case NonArrParamK:
                fprintf(listing, "Parameter: %s\n",
                        tree->attr.name);
                break;

            default:
                fprintf(listing, "Unknown ParamNode kind\n");
                break;
            }
        }
        break;

        case TypeK:
        {
            switch (tree->kind.type)
            {
            case TypeNameK:
            {
                fprintf(listing, "Type: ");
                switch (tree->attr.type)
                {
                case INT:
                    fprintf(listing, "int\n");
                    break;
                case VOID:
                    fprintf(listing, "void\n");
                    break;
                }
            }
            break;

            default:
                fprintf(listing, "Unknown TypeNode kind\n");
                break;
            }
        }
        break;

        default:
            fprintf(listing, "Unknown ExpNode kind\n");
            break;
        }


        int last = -1;
        for (i = MAXCHILDREN - 1; i >= 0; --i)
        {
            if (tree->child[i])
            {
                last = i;
                break;
            }
        }
        // 遍历所有孩子结点
        for (i = 0; i < MAXCHILDREN; i++)
        {
            if (i == 1 && tree->nodekind == DeclK && tree->kind.decl == FuncK &&
                tree->child[i]->attr.type == VOID)
                continue; // 跳过参数为void的函数
            if (i == last)
            {
                printTreeHelper(tree->child[i], closed, level + 1, TRUE);
            }
            else
            {
                printTreeHelper(tree->child[i], closed, level + 1, FALSE);
            }
        }
        tree = tree->sibling;
        isLast = TRUE;// 兄弟节点没有父节点信息,只需要判断sibling节点,因此设isLast为TRUE
    }
}

/**
 * @brief 打印语法树的包装函数
 * 
 * @param tree 语法树根节点
 */
void printTree(TreeNode *tree)
{
#define MAX_LEVEL 64
    // 第i个元素表示当前节点是否是第i层的最后一个节点
    int closed[MAX_LEVEL];
    for (size_t i = 0; i < MAX_LEVEL; i++)
    {
        closed[i] = TRUE;
    }
    fprintf(listing, "    Program\n");
    printTreeHelper(tree, closed, 1, TRUE);
}

/**
 * @brief 返回str的字符串长度,如果在[0,max)的下标范围内找不到结束符或max小于等于0,则返回-1
 * 
 * @param str 字符数组
 * @param max 数组可以容纳的字符个数
 * @return int 
 */
int len(char str[], int max)
{
    if (max <= 0)
    {
        return -1;
    }
    int cnt = 0;
    while (cnt < max && str[cnt] != '\0')
    {
        ++cnt;
    }

    if (cnt == max)
    {
        return -1;
    }
    return cnt;
}