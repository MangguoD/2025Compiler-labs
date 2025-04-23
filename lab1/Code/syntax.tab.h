/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     FLOAT = 259,
     ID = 260,
     RELOP = 261,
     TYPE = 262,
     ASSIGNOP = 263,
     PLUS = 264,
     MINUS = 265,
     STAR = 266,
     DIV = 267,
     IF = 268,
     ELSE = 269,
     WHILE = 270,
     RETURN = 271,
     STRUCT = 272,
     AND = 273,
     OR = 274,
     NOT = 275,
     SEMI = 276,
     COMMA = 277,
     LP = 278,
     RP = 279,
     LC = 280,
     LB = 281,
     RB = 282,
     RC = 283,
     DOT = 284,
     LOWER_THAN_NOT = 285,
     LOWER_THAN_ELSE = 286
   };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define ID 260
#define RELOP 261
#define TYPE 262
#define ASSIGNOP 263
#define PLUS 264
#define MINUS 265
#define STAR 266
#define DIV 267
#define IF 268
#define ELSE 269
#define WHILE 270
#define RETURN 271
#define STRUCT 272
#define AND 273
#define OR 274
#define NOT 275
#define SEMI 276
#define COMMA 277
#define LP 278
#define RP 279
#define LC 280
#define LB 281
#define RB 282
#define RC 283
#define DOT 284
#define LOWER_THAN_NOT 285
#define LOWER_THAN_ELSE 286




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 44 "syntax.y"
{
    struct Node *node;
    int intVal;
    float floatVal;
    char *strVal;
}
/* Line 1529 of yacc.c.  */
#line 118 "syntax.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

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

extern YYLTYPE yylloc;
