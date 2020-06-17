#include "util.h"


/* Procedure printToken prints a token 
 * and its lexeme to the listing file
 */
void printToken( TokenType token, const char* tokenString ) {
	switch (token) {
		case IF:    case ELSE:
		case WHILE: case RETURN: 
			fprintf(listing, "reserved word: %s\n", tokenString); 
			break;

		case INT:  fprintf(listing, "int\n"); break; 
		case VOID: fprintf(listing, "void\n"); break; 
			
		
		case ASSIGN: fprintf(listing, "=\n"); break;
		case EQ:    fprintf(listing, "==\n"); break;
		case NEQ:   fprintf(listing, "!=\n"); break;
		case LTEQ:  fprintf(listing, "<=\n"); break;
		case GTEQ:  fprintf(listing, ">=\n"); break;
		case LT:    fprintf(listing, "<\n");  break;
		case GT:    fprintf(listing, ">\n");  break;
		
		case PLUS:  fprintf(listing, "+\n"); break;
		case MINUS: fprintf(listing, "-\n"); break;
		case TIMES: fprintf(listing, "*\n"); break;
		case OVER:  fprintf(listing, "/\n"); break;

		case LP:  fprintf(listing, "(\n"); break;
		case RP:  fprintf(listing, ")\n"); break;
		case LB:  fprintf(listing, "[\n"); break;
		case RB:  fprintf(listing, "]\n"); break;
		case LC:  fprintf(listing, "{\n"); break;
		case RC:  fprintf(listing, "}\n"); break;

		case SEMI:  fprintf(listing, ";\n"); break;
		case COMMA: fprintf(listing, ",\n"); break;

		case ID:  fprintf(listing, "ID, name = %s\n", tokenString); break;
		case NUM: fprintf(listing, "NUM, val = %s\n", tokenString); break;
		
		case ERROR: fprintf(listing, "ERROR: %s\n", tokenString); break;
		
		case ENDFILE: fprintf(listing, "EOF\n"); break;

		default: /* should never happen */
      		fprintf(listing, "Unknown token: %d\n", token);
	}
}

/* 新建 语句节点 */
TreeNode * newStmtNode(StmtKind kind) {
	TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
	int i;
	if (t == NULL) {
		fprintf(listing, "Out of memory error at line %d\n", lineno);
	}
	else {
		for (i = 0; i < MAXCHILDREN; i++) { 
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
TreeNode * newExpNode(ExpKind kind) {
	TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
	int i;
	if (t == NULL) {
		fprintf(listing, "Out of memory error at line %d\n", lineno);
	}
	else {
		for (i = 0; i < MAXCHILDREN; i++) { 
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
TreeNode * newDeclNode(DeclKind kind) {
	TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
	int i;
	if (t == NULL) {
		fprintf(listing, "Out of memory error at line %d\n", lineno);
	}
	else {
		for (i = 0; i < MAXCHILDREN; i++) { 
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
TreeNode * newParamNode(ParamKind kind) {
	TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
	int i;
	if (t == NULL) {
		fprintf(listing, "Out of memory error at line %d\n", lineno);
	}
	else {
		for (i = 0; i < MAXCHILDREN; i++) { 
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
TreeNode * newTypeNode(TypeKind kind) {
	TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
	int i;
	if (t == NULL) {
		fprintf(listing, "Out of memory error at line %d\n", lineno);
	}
	else {
		for (i = 0; i < MAXCHILDREN; i++) { 
			t->child[i] = NULL;
		}
		t->sibling = NULL;
		t->nodekind = TypeK;
		t->kind.stmt = kind;
		t->lineno = lineno;
	}
	return t;
}


/* Variable indentno is used by printTree 
 * to store current number of spaces to indent */
static int indentno = 0;

/* macros to increase/decrease indentation */
#define INDENT indentno += 1
#define UNINDENT indentno -= 1

/* print indentation*/
static void printSpaces(void)
{
	int i;
	for (i = 0; i < indentno - 1; i++) {
		fprintf(listing, "│    ");
	}
	fprintf(listing, "└── ");
}

/* procedure printTree prints a syntax tree to the 
 * listing file using indentation to indicate subtrees
 */
void printTree(TreeNode* tree) {
	int i;
	INDENT;
	while (tree != NULL) {
		printSpaces();
		switch (tree->nodekind) {
		case StmtK: {
			switch (tree->kind.stmt)
			{
			case IfK:       fprintf(listing, "If\n");                break;
			case IterK:    fprintf(listing, "While\n");             break;
			case RetK:   fprintf(listing, "Return\n");            break;
			case CompK: fprintf(listing, "Compound Statment\n"); break;
			default:    fprintf(listing, "Unknown StmtNode kind\n"); break;
			}
		}
				  break;

		case ExpK: {
			switch (tree->kind.exp)
			{
			case AssignK:   fprintf(listing, "Assign\n");            break;
			case CallK:     fprintf(listing, "Call function: %s\n",
				tree->attr.name);    break;
			case OpK:     fprintf(listing, "Op: "); printToken(tree->attr.op, "\0"); break;
			case ConstK:  fprintf(listing, "Const: %d\n", tree->attr.val);      break;
			case IdK:     fprintf(listing, "Id: %s\n", tree->attr.name);     break;
			case ArrIdK:  fprintf(listing, "Array Id: %s\n", tree->attr.name);     break;

			default:      fprintf(listing, "Unknown ExpNode kind\n");                break;
			}
		}
				 break;

		case DeclK: {
			switch (tree->kind.decl)
			{
			case VarK:  fprintf(listing, "VarDec: %s\n", tree->attr.name); break;
			case FuncK: fprintf(listing, "FuncDec: %s\n", tree->attr.name); break;
			case ArrVarK:  fprintf(listing, "ArrVarDec: %s, len: %d\n",
				tree->attr.arr.name, tree->attr.arr.size); break;

			default:       fprintf(listing, "Unknown DecNode kind\n");         break;
			}
		}
				  break;

		case ParamK: {
			switch (tree->kind.param)
			{
			case ArrParamK:    fprintf(listing, "Array Parameter: %s\n",
				tree->attr.name);  break;
			case NonArrParamK: fprintf(listing, "Parameter: %s\n",
				tree->attr.name);  break;

			default: fprintf(listing, "Unknown ParamNode kind\n"); break;
			}
		}
				   break;

		case TypeK: {
			switch (tree->kind.type)
			{
			case TypeNameK: {
				fprintf(listing, "Type: ");
				switch (tree->attr.type)
				{
				case INT:  fprintf(listing, "int\n");  break;
				case VOID: fprintf(listing, "void\n"); break;
				}
			}
						  break;

			default: fprintf(listing, "Unknown TypeNode kind\n"); break;
			}
		}
				  break;

		default: fprintf(listing, "Unknown ExpNode kind\n"); break;
		}

		for (i = 0; i < MAXCHILDREN; i++) {
			if (i == 1 && tree->nodekind == DeclK && tree->kind.decl == FuncK &&
				tree->child[i]->attr.type == VOID) continue; // 跳过参数为void的函数
			printTree(tree->child[i]);
		}
		tree = tree->sibling;
	}
	UNINDENT;
}