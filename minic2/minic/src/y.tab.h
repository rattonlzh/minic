/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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
    WITHOUT_ELSE = 286
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
#define WITHOUT_ELSE 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 37 "parser.y" /* yacc.c:1909  */
 
	struct treeNode * node;
    int op; 
	int val; 
	char name[256];

#line 123 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
