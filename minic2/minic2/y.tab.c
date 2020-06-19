/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 3 "parser.y"

/* 在.y文件中加入％locations，bison加入－d编译后的.h符号表文件中
 * 会多出一个YYLTYPE结构体定义和一个该结构体类型的全局变量yylloc，
 * 这样，.l文件include该.h文件后，该结构体类型就可以被flex知道，
 * 且flex可以向yylloc里面填入信息。
 */

/*distinguishes Yacc output from other code files*/
#define YYPARSER 

#include "globals.h"
#include "util.h"

/*extern int  yylineno; 提供当前的行数信息*/
extern char *yytext; /*匹配模式的文本存储在这一变量中（char*）*/
extern FILE *yyin; /*FILE*类型，指向lexer正在解析的当前文件*/

//#define YYSTYPE TokenStruct

TreeNode * parseTree; /*stores syntax tree for later return*/
void yyerror(const char* message, ...);


/* Line 371 of yacc.c  */
#line 92 "y.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ERROR = 258,
     IF = 259,
     ELSE = 260,
     INT = 261,
     VOID = 262,
     WHILE = 263,
     RETURN = 264,
     ID = 265,
     NUM = 266,
     ASSIGN = 267,
     EQ = 268,
     NEQ = 269,
     LTEQ = 270,
     GTEQ = 271,
     LT = 272,
     GT = 273,
     PLUS = 274,
     MINUS = 275,
     TIMES = 276,
     OVER = 277,
     LP = 278,
     RP = 279,
     LB = 280,
     RB = 281,
     LC = 282,
     RC = 283,
     SEMI = 284,
     COMMA = 285,
     NOT = 286,
     UMINUS = 287,
     WITHOUT_ELSE = 288
   };
#endif
/* Tokens.  */
#define ERROR 258
#define IF 259
#define ELSE 260
#define INT 261
#define VOID 262
#define WHILE 263
#define RETURN 264
#define ID 265
#define NUM 266
#define ASSIGN 267
#define EQ 268
#define NEQ 269
#define LTEQ 270
#define GTEQ 271
#define LT 272
#define GT 273
#define PLUS 274
#define MINUS 275
#define TIMES 276
#define OVER 277
#define LP 278
#define RP 279
#define LB 280
#define RB 281
#define LC 282
#define RC 283
#define SEMI 284
#define COMMA 285
#define NOT 286
#define UMINUS 287
#define WITHOUT_ELSE 288



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 27 "parser.y"
 
	struct treeNode * node;
    int op; 
	int val; 
	char name[256];


/* Line 387 of yacc.c  */
#line 209 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;
extern YYLTYPE yylloc;
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 250 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   97

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNRULES -- Number of states.  */
#define YYNSTATES  107

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    18,    19,
      27,    29,    31,    32,    40,    42,    44,    48,    50,    53,
      54,    60,    65,    68,    69,    72,    73,    75,    77,    79,
      81,    83,    86,    88,    94,   102,   108,   111,   115,   119,
     121,   123,   124,   130,   134,   136,   138,   140,   142,   144,
     146,   148,   152,   154,   156,   158,   162,   164,   166,   168,
     172,   174,   176,   178,   179,   185,   187,   188,   192
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      35,     0,    -1,    36,    -1,    36,    37,    -1,    37,    -1,
      38,    -1,    41,    -1,    40,    10,    29,    -1,    -1,    40,
      10,    25,    11,    39,    26,    29,    -1,     6,    -1,     7,
      -1,    -1,    40,    10,    42,    23,    43,    24,    47,    -1,
      44,    -1,     7,    -1,    44,    30,    45,    -1,    45,    -1,
      40,    10,    -1,    -1,    40,    10,    46,    25,    26,    -1,
      27,    48,    49,    28,    -1,    48,    38,    -1,    -1,    49,
      50,    -1,    -1,    51,    -1,    47,    -1,    52,    -1,    53,
      -1,    54,    -1,    55,    29,    -1,    29,    -1,     4,    23,
      55,    24,    50,    -1,     4,    23,    55,    24,    50,     5,
      50,    -1,     8,    23,    55,    24,    50,    -1,     9,    29,
      -1,     9,    55,    29,    -1,    56,    12,    55,    -1,    58,
      -1,    10,    -1,    -1,    10,    57,    25,    55,    26,    -1,
      60,    59,    60,    -1,    60,    -1,    13,    -1,    14,    -1,
      15,    -1,    16,    -1,    17,    -1,    18,    -1,    60,    61,
      62,    -1,    62,    -1,    19,    -1,    20,    -1,    62,    63,
      64,    -1,    64,    -1,    21,    -1,    22,    -1,    23,    55,
      24,    -1,    56,    -1,    65,    -1,    11,    -1,    -1,    10,
      66,    23,    67,    24,    -1,    68,    -1,    -1,    68,    30,
      55,    -1,    55,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    73,    73,    80,    91,    95,    96,   100,   108,   107,
     120,   121,   126,   125,   141,   142,   146,   157,   161,   168,
     167,   177,   186,   197,   201,   212,   221,   222,   223,   224,
     225,   229,   230,   235,   241,   253,   262,   263,   271,   277,
     281,   287,   286,   300,   307,   311,   312,   313,   314,   315,
     316,   320,   327,   331,   332,   336,   343,   347,   348,   352,
     353,   354,   355,   361,   360,   373,   374,   379,   390
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ERROR", "IF", "ELSE", "INT", "VOID",
  "WHILE", "RETURN", "ID", "NUM", "ASSIGN", "EQ", "NEQ", "LTEQ", "GTEQ",
  "LT", "GT", "PLUS", "MINUS", "TIMES", "OVER", "LP", "RP", "LB", "RB",
  "LC", "RC", "SEMI", "COMMA", "NOT", "UMINUS", "WITHOUT_ELSE", "$accept",
  "program", "declaration_list", "declaration", "var_declaration", "@1",
  "type_specifier", "fun_declaration", "@2", "params", "param_list",
  "param", "@3", "compound_stmt", "local_declarations", "statement_list",
  "statement", "expression_stmt", "selection_stmt", "iteration_stmt",
  "return_stmt", "expression", "var", "@4", "simple_expression", "relop",
  "additive_expression", "addop", "term", "mulop", "factor", "call", "@5",
  "args", "arg_list", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    34,    35,    36,    36,    37,    37,    38,    39,    38,
      40,    40,    42,    41,    43,    43,    44,    44,    45,    46,
      45,    47,    48,    48,    49,    49,    50,    50,    50,    50,
      50,    51,    51,    52,    52,    53,    54,    54,    55,    55,
      56,    57,    56,    58,    58,    59,    59,    59,    59,    59,
      59,    60,    60,    61,    61,    62,    62,    63,    63,    64,
      64,    64,    64,    66,    65,    67,    67,    68,    68
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     0,     7,
       1,     1,     0,     7,     1,     1,     3,     1,     2,     0,
       5,     4,     2,     0,     2,     0,     1,     1,     1,     1,
       1,     2,     1,     5,     7,     5,     2,     3,     3,     1,
       1,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     0,     5,     1,     0,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    10,    11,     0,     2,     4,     5,     0,     6,     1,
       3,    12,     0,     7,     0,     8,     0,     0,    11,     0,
       0,    14,    17,     0,    18,     0,     0,     9,     0,    23,
      13,    16,     0,    25,    20,    22,     0,     0,     0,     0,
       0,     0,    40,    62,     0,    21,    32,    27,    24,    26,
      28,    29,    30,     0,    60,    39,    44,    52,    56,    61,
       0,     0,    36,     0,     0,     0,     0,    31,     0,    45,
      46,    47,    48,    49,    50,    53,    54,     0,     0,    57,
      58,     0,     0,     0,    37,     0,    66,    59,    38,    60,
      43,    51,    55,     0,     0,     0,    68,     0,    65,    33,
      35,    42,    64,     0,     0,    67,    34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    17,     7,     8,    14,    20,
      21,    22,    28,    47,    33,    37,    48,    49,    50,    51,
      52,    53,    54,    64,    55,    77,    56,    78,    57,    81,
      58,    59,    65,    97,    98
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -87
static const yytype_int8 yypact[] =
{
      41,   -87,   -87,    15,    41,   -87,   -87,    -9,   -87,   -87,
     -87,    17,     6,   -87,     2,   -87,    45,     7,    25,    31,
      29,    42,   -87,    26,    46,    34,    41,   -87,    48,   -87,
     -87,   -87,    49,    41,   -87,   -87,    64,     1,    17,    53,
      54,     3,   -21,   -87,    11,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,    51,    66,   -87,    50,    36,   -87,   -87,
      11,    11,   -87,    52,    57,    56,    59,   -87,    11,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,    11,    11,   -87,
     -87,    11,    60,    61,   -87,    11,    11,   -87,   -87,   -87,
      40,    36,   -87,    27,    27,    62,   -87,    63,    65,    81,
     -87,   -87,   -87,    11,    27,   -87,   -87
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -87,   -87,   -87,    85,    58,   -87,   -10,   -87,   -87,   -87,
     -87,    67,   -87,    69,   -87,   -87,   -86,   -87,   -87,   -87,
     -87,   -41,   -38,   -87,   -87,   -87,    13,   -87,    14,   -87,
      16,   -87,   -87,   -87,   -87
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -64
static const yytype_int8 yytable[] =
{
      63,    11,   -63,    66,   -41,    39,    19,    99,   100,    40,
      41,    42,    43,    42,    43,     9,    19,    15,   106,    82,
      83,    42,    43,    36,    44,    16,    44,    88,    29,    45,
      46,    39,    62,    23,    44,    40,    41,    42,    43,    89,
      89,    24,    12,    89,    95,    96,    13,     1,     2,   -15,
      44,     1,    18,    25,    29,    27,    46,    79,    80,    75,
      76,    29,   105,    69,    70,    71,    72,    73,    74,    75,
      76,   -19,    26,    32,    38,    34,    60,    61,    68,    86,
      67,    84,    85,    87,    93,    94,   104,   102,   101,    10,
      90,    35,    91,    31,    30,   103,     0,    92
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-87)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
      41,    10,    23,    44,    25,     4,    16,    93,    94,     8,
       9,    10,    11,    10,    11,     0,    26,    11,   104,    60,
      61,    10,    11,    33,    23,    23,    23,    68,    27,    28,
      29,     4,    29,    26,    23,     8,     9,    10,    11,    77,
      78,    10,    25,    81,    85,    86,    29,     6,     7,    24,
      23,     6,     7,    24,    27,    29,    29,    21,    22,    19,
      20,    27,   103,    13,    14,    15,    16,    17,    18,    19,
      20,    25,    30,    25,    10,    26,    23,    23,    12,    23,
      29,    29,    25,    24,    24,    24,     5,    24,    26,     4,
      77,    33,    78,    26,    25,    30,    -1,    81
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,    35,    36,    37,    38,    40,    41,     0,
      37,    10,    25,    29,    42,    11,    23,    39,     7,    40,
      43,    44,    45,    26,    10,    24,    30,    29,    46,    27,
      47,    45,    25,    48,    26,    38,    40,    49,    10,     4,
       8,     9,    10,    11,    23,    28,    29,    47,    50,    51,
      52,    53,    54,    55,    56,    58,    60,    62,    64,    65,
      23,    23,    29,    55,    57,    66,    55,    29,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    59,    61,    21,
      22,    63,    55,    55,    29,    25,    23,    24,    55,    56,
      60,    62,    64,    24,    24,    55,    55,    67,    68,    50,
      50,    26,    24,    30,     5,    55,    50
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

__attribute__((__unused__))
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
#else
static unsigned
yy_location_print_ (yyo, yylocp)
    FILE *yyo;
    YYLTYPE const * const yylocp;
#endif
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += fprintf (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += fprintf (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += fprintf (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += fprintf (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += fprintf (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;


/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 74 "parser.y"
    {	parseTree = (yyvsp[(1) - (1)].node); 
			YYACCEPT; /* 在动作中使yyparse()以一个零值立即返回，显示成功。*/ 
		}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 81 "parser.y"
    { 
					TreeNode * t = (yyvsp[(1) - (2)].node);
					if (t != NULL) {
						while (t->sibling != NULL) t = (TreeNode *) t->sibling;
						t->sibling = (yyvsp[(2) - (2)].node);
						(yyval.node) = (yyvsp[(1) - (2)].node);
					} else {
						(yyval.node) = (yyvsp[(2) - (2)].node);
					}
				}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 91 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 95 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 96 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 101 "parser.y"
    {
					(yyval.node) = (TreeNode *) newDeclNode(VarK);
					(yyval.node)->child[0] = (yyvsp[(1) - (3)].node);
					(yyval.node)->lineno = lineno;
					strcpy((yyval.node)->attr.name, (yyvsp[(2) - (3)].name));
				}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 108 "parser.y"
    {
					// 如果有NUM应立刻用一个变量暂存因为后面的识别会把TokenValue覆盖掉
					(yyval.node) = (TreeNode *) newDeclNode(ArrVarK);
					(yyval.node)->child[0] = (yyvsp[(1) - (4)].node);
					(yyval.node)->lineno = lineno;
					strcpy((yyval.node)->attr.arr.name, (yyvsp[(2) - (4)].name));
					(yyval.node)->attr.arr.size = (yyvsp[(4) - (4)].val);
				}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 116 "parser.y"
    { (yyval.node) = (yyvsp[(5) - (7)].node); }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 120 "parser.y"
    { (yyval.node) = newTypeNode(TypeNameK); (yyval.node)->attr.type = INT; }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 121 "parser.y"
    { (yyval.node) = newTypeNode(TypeNameK); (yyval.node)->attr.type = VOID; }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 126 "parser.y"
    {
					(yyval.node) = (TreeNode *) newDeclNode(FuncK);
					(yyval.node)->lineno = lineno;
					strcpy((yyval.node)->attr.name, (yyvsp[(2) - (2)].name));
				}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 132 "parser.y"
    {
					(yyval.node) = (yyvsp[(3) - (7)].node);
					(yyval.node)->child[0] = (yyvsp[(1) - (7)].node); /* return type */
					(yyval.node)->child[1] = (yyvsp[(5) - (7)].node); /* parameters */
					(yyval.node)->child[2] = (yyvsp[(7) - (7)].node); /* body */
				}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 141 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 142 "parser.y"
    { (yyval.node) = newTypeNode(TypeNameK); (yyval.node)->attr.type = VOID; }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 147 "parser.y"
    {
				TreeNode *t = (yyvsp[(1) - (3)].node);
				if (t != NULL) {
					while (t->sibling != NULL) t = (TreeNode *) t->sibling;
					t->sibling = (yyvsp[(3) - (3)].node);
					(yyval.node) = (yyvsp[(1) - (3)].node);
				} else {
					(yyval.node) = (yyvsp[(3) - (3)].node);
				}
			}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 157 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 162 "parser.y"
    {
			(yyval.node) = (TreeNode *) newParamNode(NonArrParamK);
			(yyval.node)->child[0] = (yyvsp[(1) - (2)].node);
			strcpy((yyval.node)->attr.name, (yyvsp[(2) - (2)].name));
		}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 168 "parser.y"
    {
			(yyval.node) = (TreeNode *) newParamNode(ArrParamK);
			(yyval.node)->child[0] = (yyvsp[(1) - (2)].node);
			strcpy((yyval.node)->attr.name, (yyvsp[(2) - (2)].name)); // TODO 修改 数组
		}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 173 "parser.y"
    { (yyval.node) = (yyvsp[(3) - (5)].node); }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 178 "parser.y"
    {
					(yyval.node) = newStmtNode(CompK);
                	(yyval.node)->child[0] = (yyvsp[(2) - (4)].node); /* local variable declarations */
                	(yyval.node)->child[1] = (yyvsp[(3) - (4)].node); /* statements */
				}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 187 "parser.y"
    {
						TreeNode *t = (yyvsp[(1) - (2)].node);
						if (t != NULL) {
							while (t->sibling != NULL) t = (TreeNode *) t->sibling;
							t->sibling = (yyvsp[(2) - (2)].node);
							(yyval.node) = (yyvsp[(1) - (2)].node);
						} else {
							(yyval.node) = (yyvsp[(2) - (2)].node);
						}
					}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 197 "parser.y"
    { (yyval.node) = NULL; }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 202 "parser.y"
    {
					TreeNode *t = (yyvsp[(1) - (2)].node);
					if (t != NULL) {
						while (t->sibling != NULL) t = (TreeNode *) t->sibling;
						t->sibling = (yyvsp[(2) - (2)].node);
						(yyval.node) = (yyvsp[(1) - (2)].node);
					} else {
						(yyval.node) = (yyvsp[(2) - (2)].node);
					}
				}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 212 "parser.y"
    { (yyval.node) = NULL; }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 221 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 222 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 223 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 224 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 225 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 229 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 230 "parser.y"
    { (yyval.node) = NULL; }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 236 "parser.y"
    {
					(yyval.node) = (TreeNode *) newStmtNode(IfK);
					(yyval.node)->child[0] = (yyvsp[(3) - (5)].node);
					(yyval.node)->child[1] = (yyvsp[(5) - (5)].node);
				}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 242 "parser.y"
    {
					(yyval.node) = (TreeNode *) newStmtNode(IfK);
					(yyval.node)->child[0] = (yyvsp[(3) - (7)].node);
					(yyval.node)->child[1] = (yyvsp[(5) - (7)].node);
					(yyval.node)->child[2] = (yyvsp[(7) - (7)].node);
					// $$->sibling = $7;
					// $$->sibling->kind = IfK;
				}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 254 "parser.y"
    {
					(yyval.node) = (TreeNode *) newStmtNode(IterK);
					(yyval.node)->child[0] = (yyvsp[(3) - (5)].node);
					(yyval.node)->child[1] = (yyvsp[(5) - (5)].node);
				}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 262 "parser.y"
    { (yyval.node) = (TreeNode *) newStmtNode(RetK); }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 264 "parser.y"
    {
				(yyval.node) = (TreeNode *) newStmtNode(RetK);
				(yyval.node)->child[0] = (yyvsp[(2) - (3)].node);
			}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 272 "parser.y"
    {
				(yyval.node) = (TreeNode *) newExpNode(AssignK);
				(yyval.node)->child[0] = (yyvsp[(1) - (3)].node);
				(yyval.node)->child[1] = (yyvsp[(3) - (3)].node);
			}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 277 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 282 "parser.y"
    {
		(yyval.node) = (TreeNode *) newExpNode(IdK);
		strcpy((yyval.node)->attr.name, (yyvsp[(1) - (1)].name));
	}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 287 "parser.y"
    {
		(yyval.node) = (TreeNode *) newExpNode(ArrIdK);
		strcpy((yyval.node)->attr.name, (yyvsp[(1) - (1)].name)); // TODO 修改 数组
	}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 292 "parser.y"
    {
		(yyval.node) = (yyvsp[(2) - (5)].node);
		(yyval.node)->child[0] = (yyvsp[(4) - (5)].node); 
	}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 301 "parser.y"
    {
						(yyval.node) = (TreeNode *) newExpNode(OpK);
						(yyval.node)->attr.op = (yyvsp[(2) - (3)].op);
						(yyval.node)->child[0] = (yyvsp[(1) - (3)].node);
						(yyval.node)->child[1] = (yyvsp[(3) - (3)].node);
					}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 307 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 311 "parser.y"
    { (yyval.op) = EQ; }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 312 "parser.y"
    { (yyval.op) = NEQ; }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 313 "parser.y"
    { (yyval.op) = LTEQ; }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 314 "parser.y"
    { (yyval.op) = GTEQ; }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 315 "parser.y"
    { (yyval.op) = LT; }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 316 "parser.y"
    { (yyval.op) = GT; }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 321 "parser.y"
    {
						(yyval.node) = (TreeNode *) newExpNode(OpK);
						(yyval.node)->attr.op = (yyvsp[(2) - (3)].op);
						(yyval.node)->child[0] = (yyvsp[(1) - (3)].node);
						(yyval.node)->child[1] = (yyvsp[(3) - (3)].node);
					}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 327 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 331 "parser.y"
    { (yyval.op) = PLUS; }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 332 "parser.y"
    { (yyval.op) = MINUS; }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 337 "parser.y"
    {
			(yyval.node) = (TreeNode *) newExpNode(OpK);
			(yyval.node)->attr.op = (yyvsp[(2) - (3)].op);
			(yyval.node)->child[0] = (yyvsp[(1) - (3)].node);
			(yyval.node)->child[1] = (yyvsp[(3) - (3)].node);
		}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 343 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 347 "parser.y"
    { (yyval.op) = TIMES; }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 348 "parser.y"
    { (yyval.op) = OVER; }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 352 "parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 353 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 354 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 355 "parser.y"
    { (yyval.node) = (TreeNode *) newExpNode(ConstK);
				(yyval.node)->attr.val = (yyvsp[(1) - (1)].val); }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 361 "parser.y"
    {
		(yyval.node) = (TreeNode *) newExpNode(CallK);
		strcpy((yyval.node)->attr.name, (yyvsp[(1) - (1)].name));
	}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 366 "parser.y"
    {
		(yyval.node) = (yyvsp[(2) - (5)].node);
		(yyval.node)->child[0] = (yyvsp[(4) - (5)].node); 
	}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 373 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 374 "parser.y"
    { (yyval.node) = NULL; }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 380 "parser.y"
    {
			TreeNode *t = (yyvsp[(1) - (3)].node);
			if (t != NULL) {
				while (t->sibling != NULL) t = (TreeNode *) t->sibling;
				t->sibling = (yyvsp[(3) - (3)].node);
				(yyval.node) = (yyvsp[(1) - (3)].node);
			} else {
				(yyval.node) = (yyvsp[(3) - (3)].node);
			}
		}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 390 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;


/* Line 1792 of yacc.c  */
#line 2189 "y.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 393 "parser.y"



/*
int yylex(void) { return getToken(); }
*/

/**
 * @name: parse
 * @msg: 在main函数中调用，进行语法分析，生成语法树
 * @param {FILE *} source 语法分析的源文件
 * @return: TreeNode * 语法树
 */
TreeNode * parse( FILE * source ) {
	yyin = source;
	yyparse();
	return parseTree;
}

/**
 * @name: yyerror
 * @msg: 打印语法分析错误的具体位置和出错原因
 * @param {const char* message, ...} 
 * @return: 
 */
#include<stdarg.h> 
void yyerror(const char* message, ...)
{
	fprintf(listing, "Error at Line %d Column %d: ", yylloc.first_line, yylloc.first_column);
	va_list ap; // 指向参数的指针
    va_start(ap, message); // 宏初始化
	vfprintf(listing, message, ap);
	va_end(ap);
    fprintf(listing, ".\n");
	Error = TRUE;
}

/*
int main(int argc, char *argv[])
{
    yyin = fopen(argv[1], "r");
    yylineno = 1;
    yyparse();
	printTree(parseTree);
    return 0;
}
*/