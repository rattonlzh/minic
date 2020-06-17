#include "globals.h"
#include "util.h"

/* set NO_PARSE to TRUE to get a scanner-only compiler */
#define NO_PARSE FALSE

/* set NO_ANALYZE to TRUE to get a parser-only compiler */
#define NO_ANALYZE FALSE

/* set NO_CODE to TRUE to get a compiler that does not generate code */
#define NO_CODE FALSE

#if !NO_PARSE
#include "y.tab.h"
#if !NO_ANALYZE
#include "analyze.h"
#if !NO_CODE
#include "cgen.h"
#endif
#endif
#endif

/* allocate global variables */
int lineno = 1;
FILE * source;
FILE * listing;
FILE * code;

/* allocate and set tracing flags */
int EchoSource   = FALSE;
int TraceScan    = TRUE;
int TraceParse   = TRUE;
int TraceAnalyze = TRUE;
int TraceCode    = FALSE;

int Error = FALSE;



int main( int argc, char * argv[] )
{
	if (argc != 2) { 
		fprintf(stderr, "usage: %s <filename>\n", argv[0]);
		exit(1);
	}

	TreeNode * syntaxTree;

	char pgm[120];
	strcpy(pgm, argv[1]);
	if (strchr(pgm, '.') == NULL)
		strcat(pgm, ".mc");

	source = fopen(pgm, "r");
	if (source == NULL) { 
		fprintf(stderr, "File %s not found\n", pgm);
		exit(1);
	}

	listing = stdout;
	fprintf(listing, "\nMINIC COMPILATION: %s\n\n", pgm);
	if (TraceScan) {
		while (getToken() != ENDFILE);// 打印词法符号
	}

#if NO_PARSE
	while (getToken() != ENDFILE);// 打印词法符号
#else
	syntaxTree = parse(source);
	if (!Error) {
		if (TraceParse) {
			fprintf(listing, "Syntax tree:\n");
			printTree(syntaxTree);
		}
	}
#if !NO_ANALYZE
	if (!Error)
	{
		if (TraceAnalyze) fprintf(listing, "\nBuilding Symbol Table...\n");
		buildSymtab(syntaxTree);
		if (TraceAnalyze) fprintf(listing, "\nChecking Types...\n");
		typeCheck(syntaxTree);
		if (TraceAnalyze) fprintf(listing, "\nType Checking Finished\n");
	}
#if !NO_CODE
	if (!Error)
	{
		char* codefile;
		int fnlen = strcspn(pgm, ".");
		codefile = (char*)calloc(fnlen + 4, sizeof(char));
		strncpy(codefile, pgm, fnlen);
		strcat(codefile, ".tm");
		code = fopen(codefile, "w");
		if (code == NULL)
		{
			printf("Unable to open %s\n", codefile);
			exit(1);
		}
		codeGen(syntaxTree, codefile);
		fclose(code);
	}
#endif
#endif
#endif
	fclose(source);
	return 0;
}