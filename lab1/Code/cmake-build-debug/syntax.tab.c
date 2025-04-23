/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 1



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




/* Copy the first part of user declarations.  */
#line 2 "syntax.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"

void yyerror(const char *s);
extern int yylineno; // 来自 lexer.l
extern FILE *yyin;   // 输入文件
extern int yylex(void);
extern int hasLexicalError;

// 创建语法树节点
Node *createNode(char *name, int lineno) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (!node) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
    node->name = strdup(name);
    node->lineno = lineno;
    node->child = NULL;
    node->brother = NULL;
    return node;
}

// 处理语法报错
static int lastErrorLine = -1;
void yyerror(const char *s) {
    if (lastErrorLine != yylineno) {
        printf("Error type B at Line %d: %s\n", yylineno, s);
        lastErrorLine = yylineno;
    }
}

// 递归打印语法树
void printTree(Node *node, int indent) {
    if (!node) return;

    for (int i = 0; i < indent; ++i) printf("  ");

    if (!node->child) {
        // 是词法单元（终结符）
        if (strcmp(node->name, "ID") == 0 || strcmp(node->name, "TYPE") == 0) {
            printf("%s: %s\n", node->name, node->strVal);
        } else if (strcmp(node->name, "INT") == 0) {
            printf("%s: %d\n", node->name, node->intVal);
        } else if (strcmp(node->name, "FLOAT") == 0) {
            printf("%s: %f\n", node->name, node->floatVal);
        } else {
            printf("%s\n", node->name);  // 其他终结符，如 SEMI, LP 等
        }
    } else {
        // 是语法单元（非终结符）
        printf("%s (%d)\n", node->name, node->lineno);
    }

    printTree(node->child, indent + 1);
    printTree(node->brother, indent);
}


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 64 "syntax.y"
{
    struct Node *node;
}
/* Line 193 of yacc.c.  */
#line 224 "/Users/fengziyi/CLionProjects/untitled/cmake-build-debug/syntax.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
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


/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 249 "/Users/fengziyi/CLionProjects/untitled/cmake-build-debug/syntax.tab.c"

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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   314

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNRULES -- Number of states.  */
#define YYNSTATES  124

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    13,    16,    20,    23,
      25,    29,    33,    35,    37,    43,    46,    48,    50,    51,
      53,    56,    61,    66,    70,    72,    73,    76,    80,    84,
      88,    90,    92,    96,    98,   103,   108,   113,   117,   120,
     121,   124,   126,   130,   136,   144,   150,   153,   157,   161,
     165,   169,   173,   177,   181,   185,   189,   192,   195,   200,
     204,   209,   213,   215,   217,   219,   223
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      33,     0,    -1,    34,    -1,    35,    34,    -1,    -1,    37,
      36,    21,    -1,    37,    21,    -1,    37,    42,    49,    -1,
       1,    21,    -1,    48,    -1,    48,    22,    36,    -1,    48,
       1,    36,    -1,     7,    -1,    38,    -1,    17,    40,    25,
      41,    28,    -1,    17,    39,    -1,     5,    -1,     5,    -1,
      -1,    45,    -1,    45,    41,    -1,     5,    23,    43,    24,
      -1,     5,    23,     1,    24,    -1,    44,    22,    43,    -1,
      44,    -1,    -1,    37,    48,    -1,    37,    46,    21,    -1,
      37,     1,    21,    -1,    47,    22,    46,    -1,    47,    -1,
      48,    -1,    48,     8,    52,    -1,     5,    -1,    48,    26,
       3,    27,    -1,    48,    26,     1,    27,    -1,    25,    41,
      50,    28,    -1,    25,    50,    28,    -1,    51,    50,    -1,
      -1,    52,    21,    -1,    49,    -1,    16,    52,    21,    -1,
      13,    23,    52,    24,    51,    -1,    13,    23,    52,    24,
      51,    14,    51,    -1,    15,    23,    52,    24,    51,    -1,
       1,    21,    -1,    52,     8,    52,    -1,    52,    18,    52,
      -1,    52,    19,    52,    -1,    52,     6,    52,    -1,    52,
       9,    52,    -1,    52,    10,    52,    -1,    52,    11,    52,
      -1,    52,    12,    52,    -1,    23,    52,    24,    -1,    10,
      52,    -1,    20,    52,    -1,     5,    23,    53,    24,    -1,
       5,    23,    24,    -1,    52,    26,    52,    27,    -1,    52,
      29,     5,    -1,     5,    -1,     3,    -1,     4,    -1,    52,
      22,    53,    -1,    52,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    94,    94,   104,   105,   108,   114,   119,   125,   128,
     129,   135,   140,   144,   151,   165,   173,   180,   184,   190,
     194,   209,   222,   229,   235,   239,   245,   253,   259,   266,
     272,   279,   283,   292,   296,   304,   315,   327,   341,   346,
     352,   357,   361,   367,   375,   385,   393,   400,   406,   412,
     418,   424,   430,   436,   442,   448,   454,   459,   464,   471,
     477,   484,   490,   494,   498,   505,   511
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "ID", "RELOP", "TYPE",
  "ASSIGNOP", "PLUS", "MINUS", "STAR", "DIV", "IF", "ELSE", "WHILE",
  "RETURN", "STRUCT", "AND", "OR", "NOT", "SEMI", "COMMA", "LP", "RP",
  "LC", "LB", "RB", "RC", "DOT", "LOWER_THAN_NOT", "LOWER_THAN_ELSE",
  "$accept", "Program", "ExtDefList", "ExtDef", "ExtDecList", "Specifier",
  "StructSpecifier", "Tag", "OptTag", "DefList", "FunDec", "VarList",
  "ParamDec", "Def", "DecList", "Dec", "VarDec", "CompSt", "StmtList",
  "Stmt", "Exp", "Args", 0
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
     285,   286
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    35,    35,    36,
      36,    36,    37,    37,    38,    38,    39,    40,    40,    41,
      41,    42,    42,    43,    43,    43,    44,    45,    45,    46,
      46,    47,    47,    48,    48,    48,    49,    49,    50,    50,
      51,    51,    51,    51,    51,    51,    51,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    53,    53
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     2,     3,     2,     1,
       3,     3,     1,     1,     5,     2,     1,     1,     0,     1,
       2,     4,     4,     3,     1,     0,     2,     3,     3,     3,
       1,     1,     3,     1,     4,     4,     4,     3,     2,     0,
       2,     1,     3,     5,     7,     5,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     4,     3,
       4,     3,     1,     1,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    12,    18,     0,     2,     0,     0,    13,     8,
      16,    15,     0,     1,     3,    33,     6,     0,     0,     0,
       0,     0,     5,     0,     7,     0,     0,     0,     0,     0,
      19,     0,     0,     0,    24,     0,    63,    64,    62,     0,
       0,     0,     0,     0,     0,     0,    41,     0,     0,     0,
      33,    11,    10,     0,     0,     0,     0,    30,    31,    14,
      20,    22,    26,    21,    25,    46,     0,    56,     0,     0,
       0,    57,     0,     0,    37,    38,     0,     0,     0,     0,
       0,     0,     0,     0,    40,     0,     0,    35,    34,    28,
      27,     0,     0,    23,    59,    66,     0,     0,     0,    42,
      55,    36,    50,    47,    51,    52,    53,    54,    48,    49,
       0,    61,    29,    32,     0,    58,     0,     0,    60,    65,
      43,    45,     0,    44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    17,    28,     8,    11,    12,    29,
      18,    33,    34,    30,    56,    57,    19,    46,    47,    48,
      49,    96
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -55
static const yytype_int16 yypact[] =
{
     162,   -13,   -55,    29,    49,   -55,   162,    11,   -55,   -55,
      35,   -55,    55,   -55,   -55,    63,   -55,    66,    64,    56,
      28,   184,   -55,     8,   -55,    67,    67,    47,    46,    60,
      28,    68,    67,    70,    69,    78,   -55,   -55,    79,   291,
      88,    90,   291,   291,   291,    51,   -55,    73,    51,    98,
     -55,   -55,   -55,    87,    91,   104,   112,   113,    -6,   -55,
     -55,   -55,   108,   -55,    28,   -55,   283,    86,   291,   291,
     120,   -12,   142,   114,   -55,   -55,   291,   291,   291,   291,
     291,   291,   291,   291,   -55,   291,   131,   -55,   -55,   -55,
     -55,    67,   291,   -55,   -55,   164,   119,   186,   208,   -55,
     -55,   -55,   111,   252,    86,   -12,   -12,   -12,   263,   273,
     230,   -55,   -55,   252,   291,   -55,    80,    80,   -55,   -55,
     130,   -55,    80,   -55
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -55,   -55,   139,   -55,    33,     1,   -55,   -55,   -55,    -4,
     -55,    83,   -55,   -55,    65,   -55,   -22,   137,    25,   -54,
     -39,    43
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -40
static const yytype_int8 yytable[] =
{
      67,     7,    92,    70,    71,    72,    58,     7,     9,    35,
      62,    36,    37,    38,    85,     2,    15,    86,    39,    45,
      27,    40,    32,    41,    42,     3,    60,    95,    43,    97,
      98,    44,    16,    23,    10,     2,   -39,   102,   103,   104,
     105,   106,   107,   108,   109,     3,   110,    55,    53,    13,
      54,    50,    35,   113,    36,    37,    38,    25,    51,    52,
     -17,    39,   120,   121,    40,    32,    41,    42,   123,    58,
      73,    43,    50,    75,    44,    95,    23,    -9,    26,   -39,
      20,    35,    27,    36,    37,    38,    21,    22,    59,    23,
      39,    64,    61,    40,    63,    41,    42,    80,    81,    65,
      43,    74,    66,    44,    76,    23,    77,    78,    79,    80,
      81,    68,    85,    69,    87,    86,    82,    83,    88,    84,
      78,    79,    80,    81,    85,    89,    76,    86,    77,    78,
      79,    80,    81,    90,    27,    91,   111,    85,    82,    83,
      86,    99,   101,   115,   122,    14,    85,    93,    76,    86,
      77,    78,    79,    80,    81,    24,   112,   119,     0,     0,
      82,    83,    -4,     1,     0,     0,   100,     0,    85,     2,
      76,    86,    77,    78,    79,    80,    81,     0,     0,     3,
       0,     0,    82,    83,     0,    31,   114,     0,     0,     0,
      85,     2,    76,    86,    77,    78,    79,    80,    81,     0,
       0,     3,     0,     0,    82,    83,     0,     0,   -25,     0,
     116,     0,    85,     0,    76,    86,    77,    78,    79,    80,
      81,     0,     0,     0,     0,     0,    82,    83,     0,     0,
       0,     0,   117,     0,    85,     0,    76,    86,    77,    78,
      79,    80,    81,     0,     0,     0,     0,     0,    82,    83,
       0,     0,     0,     0,     0,     0,    85,   118,    76,    86,
      77,    78,    79,    80,    81,     0,     0,     0,     0,    76,
      82,    83,    78,    79,    80,    81,     0,     0,    85,    76,
       0,    86,    78,    79,    80,    81,    36,    37,    38,    85,
       0,    82,    86,    39,    36,    37,    38,     0,     0,    85,
       0,    39,    86,    43,     0,     0,    44,    94,     0,     0,
       0,    43,     0,     0,    44
};

static const yytype_int8 yycheck[] =
{
      39,     0,     8,    42,    43,    44,    28,     6,    21,     1,
      32,     3,     4,     5,    26,     7,     5,    29,    10,    23,
      26,    13,    21,    15,    16,    17,    30,    66,    20,    68,
      69,    23,    21,    25,     5,     7,    28,    76,    77,    78,
      79,    80,    81,    82,    83,    17,    85,     1,     1,     0,
       3,     5,     1,    92,     3,     4,     5,     1,    25,    26,
      25,    10,   116,   117,    13,    64,    15,    16,   122,    91,
      45,    20,     5,    48,    23,   114,    25,    21,    22,    28,
      25,     1,    26,     3,     4,     5,    23,    21,    28,    25,
      10,    22,    24,    13,    24,    15,    16,    11,    12,    21,
      20,    28,    23,    23,     6,    25,     8,     9,    10,    11,
      12,    23,    26,    23,    27,    29,    18,    19,    27,    21,
       9,    10,    11,    12,    26,    21,     6,    29,     8,     9,
      10,    11,    12,    21,    26,    22,     5,    26,    18,    19,
      29,    21,    28,    24,    14,     6,    26,    64,     6,    29,
       8,     9,    10,    11,    12,    18,    91,   114,    -1,    -1,
      18,    19,     0,     1,    -1,    -1,    24,    -1,    26,     7,
       6,    29,     8,     9,    10,    11,    12,    -1,    -1,    17,
      -1,    -1,    18,    19,    -1,     1,    22,    -1,    -1,    -1,
      26,     7,     6,    29,     8,     9,    10,    11,    12,    -1,
      -1,    17,    -1,    -1,    18,    19,    -1,    -1,    24,    -1,
      24,    -1,    26,    -1,     6,    29,     8,     9,    10,    11,
      12,    -1,    -1,    -1,    -1,    -1,    18,    19,    -1,    -1,
      -1,    -1,    24,    -1,    26,    -1,     6,    29,     8,     9,
      10,    11,    12,    -1,    -1,    -1,    -1,    -1,    18,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    27,     6,    29,
       8,     9,    10,    11,    12,    -1,    -1,    -1,    -1,     6,
      18,    19,     9,    10,    11,    12,    -1,    -1,    26,     6,
      -1,    29,     9,    10,    11,    12,     3,     4,     5,    26,
      -1,    18,    29,    10,     3,     4,     5,    -1,    -1,    26,
      -1,    10,    29,    20,    -1,    -1,    23,    24,    -1,    -1,
      -1,    20,    -1,    -1,    23
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     7,    17,    33,    34,    35,    37,    38,    21,
       5,    39,    40,     0,    34,     5,    21,    36,    42,    48,
      25,    23,    21,    25,    49,     1,    22,    26,    37,    41,
      45,     1,    37,    43,    44,     1,     3,     4,     5,    10,
      13,    15,    16,    20,    23,    41,    49,    50,    51,    52,
       5,    36,    36,     1,     3,     1,    46,    47,    48,    28,
      41,    24,    48,    24,    22,    21,    23,    52,    23,    23,
      52,    52,    52,    50,    28,    50,     6,     8,     9,    10,
      11,    12,    18,    19,    21,    26,    29,    27,    27,    21,
      21,    22,     8,    43,    24,    52,    53,    52,    52,    21,
      24,    28,    52,    52,    52,    52,    52,    52,    52,    52,
      52,     5,    46,    52,    22,    24,    24,    24,    27,    53,
      51,    51,    14,    51
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      fprintf (stderr, "\n");
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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


/* Prevent warnings from -Wmissing-prototypes.  */

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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;
#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
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
#line 94 "syntax.y"
    {
        (yyval.node) = createNode("Program", (yylsp[(1) - (1)]).first_line);
        (yyval.node)->child = (yyvsp[(1) - (1)].node);
        int indent = 0;
        if (!hasLexicalError){ // 通过全局变量判断是否需要打印语法树（没出现错误的情况下）
            printTree((yyval.node), indent);
        }
        ;}
    break;

  case 3:
#line 104 "syntax.y"
    { (yyval.node) = createNode("ExtDefList", (yylsp[(1) - (2)]).first_line); (yyval.node)->child = (yyvsp[(1) - (2)].node); (yyvsp[(1) - (2)].node)->brother = (yyvsp[(2) - (2)].node); ;}
    break;

  case 4:
#line 105 "syntax.y"
    { (yyval.node) = NULL; ;}
    break;

  case 5:
#line 108 "syntax.y"
    {
            (yyval.node) = createNode("ExtDef", (yylsp[(1) - (3)]).first_line);
            (yyval.node)->child = (yyvsp[(1) - (3)].node);
            (yyvsp[(1) - (3)].node)->brother = (yyvsp[(2) - (3)].node);
            (yyvsp[(2) - (3)].node)->brother = (yyvsp[(3) - (3)].node);
        ;}
    break;

  case 6:
#line 114 "syntax.y"
    {
           (yyval.node) = createNode("ExtDef", (yylsp[(1) - (2)]).first_line);
           (yyval.node)->child = (yyvsp[(1) - (2)].node);
           (yyvsp[(1) - (2)].node)->brother = (yyvsp[(2) - (2)].node);
      ;}
    break;

  case 7:
#line 119 "syntax.y"
    {
             (yyval.node) = createNode("ExtDef", (yylsp[(1) - (3)]).first_line);
             (yyval.node)->child = (yyvsp[(1) - (3)].node);
             (yyvsp[(1) - (3)].node)->brother = (yyvsp[(2) - (3)].node);
             (yyvsp[(2) - (3)].node)->brother = (yyvsp[(3) - (3)].node);
             ;}
    break;

  case 8:
#line 125 "syntax.y"
    { yyerrok; ;}
    break;

  case 9:
#line 128 "syntax.y"
    {(yyval.node) = createNode("ExtDecList", (yylsp[(1) - (1)]).first_line); (yyval.node)->child = (yyvsp[(1) - (1)].node);;}
    break;

  case 10:
#line 129 "syntax.y"
    {
              (yyval.node) = createNode("ExtDecList",(yylsp[(1) - (3)]).first_line);
              (yyval.node)->child = (yyvsp[(1) - (3)].node);
              (yyvsp[(1) - (3)].node) -> brother = (yyvsp[(2) - (3)].node);
              (yyvsp[(2) - (3)].node) -> brother = (yyvsp[(3) - (3)].node);
                                ;}
    break;

  case 11:
#line 135 "syntax.y"
    {
              yyerrok;
      ;}
    break;

  case 12:
#line 140 "syntax.y"
    {
        (yyval.node) = createNode("Specifier", (yylsp[(1) - (1)]).first_line);
        (yyval.node)->child = (yyvsp[(1) - (1)].node);
    ;}
    break;

  case 13:
#line 144 "syntax.y"
    {
        (yyval.node) = createNode("Specifier", (yylsp[(1) - (1)]).first_line);
        (yyval.node)->child = (yyvsp[(1) - (1)].node);
    ;}
    break;

  case 14:
#line 151 "syntax.y"
    {
            (yyval.node) = createNode("StructSpecifier", (yylsp[(1) - (5)]).first_line);
            (yyval.node)->child = (yyvsp[(1) - (5)].node);

            if ((yyvsp[(2) - (5)].node)) {
                (yyvsp[(1) - (5)].node)->brother = (yyvsp[(2) - (5)].node);
                (yyvsp[(2) - (5)].node)->brother = (yyvsp[(3) - (5)].node);
            } else {
                (yyvsp[(1) - (5)].node)->brother = (yyvsp[(3) - (5)].node);
            }

            (yyvsp[(3) - (5)].node)->brother = (yyvsp[(4) - (5)].node);
            (yyvsp[(4) - (5)].node)->brother = (yyvsp[(5) - (5)].node);
       ;}
    break;

  case 15:
#line 165 "syntax.y"
    {
            (yyval.node) = createNode("StructSpecifier", (yylsp[(1) - (2)]).first_line);
            (yyval.node)->child = (yyvsp[(1) - (2)].node);
            (yyvsp[(1) - (2)].node)->brother = (yyvsp[(2) - (2)].node);
       ;}
    break;

  case 16:
#line 173 "syntax.y"
    {
          (yyval.node) = createNode("Tag", (yylsp[(1) - (1)]).first_line);
          (yyval.node)->child = (yyvsp[(1) - (1)].node);
      ;}
    break;

  case 17:
#line 180 "syntax.y"
    {
          (yyval.node) = createNode("OptTag", (yylsp[(1) - (1)]).first_line);
          (yyval.node)->child = (yyvsp[(1) - (1)].node);
      ;}
    break;

  case 18:
#line 184 "syntax.y"
    {
          (yyval.node) = NULL;
      ;}
    break;

  case 19:
#line 190 "syntax.y"
    {
           (yyval.node) = createNode("DefList", (yylsp[(1) - (1)]).first_line);
           (yyval.node)->child = (yyvsp[(1) - (1)].node);
       ;}
    break;

  case 20:
#line 194 "syntax.y"
    {
            (yyval.node) = createNode("DefList", (yylsp[(1) - (2)]).first_line);
            (yyval.node)->child = (yyvsp[(1) - (2)].node);
            (yyvsp[(1) - (2)].node)->brother = (yyvsp[(2) - (2)].node);
       ;}
    break;

  case 21:
#line 209 "syntax.y"
    {
              (yyval.node) = createNode("FunDec", (yylsp[(1) - (4)]).first_line);
              (yyval.node) -> child = (yyvsp[(1) - (4)].node);
              // 需要注意避免VarList为空情况下的空指针
              if ((yyvsp[(3) - (4)].node)) {
                  (yyvsp[(1) - (4)].node)->brother = (yyvsp[(2) - (4)].node);
                  (yyvsp[(2) - (4)].node)->brother = (yyvsp[(3) - (4)].node);
                  (yyvsp[(3) - (4)].node)->brother = (yyvsp[(4) - (4)].node);
              } else {
                  (yyvsp[(1) - (4)].node)->brother = (yyvsp[(2) - (4)].node);
                  (yyvsp[(2) - (4)].node)->brother = (yyvsp[(4) - (4)].node);
              }
          ;}
    break;

  case 22:
#line 222 "syntax.y"
    {
          yyerrok;
          (yyval.node) = NULL;
      ;}
    break;

  case 23:
#line 229 "syntax.y"
    {
          (yyval.node) = createNode("VarList", (yylsp[(1) - (3)]).first_line);
          (yyval.node)->child = (yyvsp[(1) - (3)].node);
          (yyvsp[(1) - (3)].node)->brother = (yyvsp[(2) - (3)].node);
          (yyvsp[(2) - (3)].node)->brother = (yyvsp[(3) - (3)].node);
      ;}
    break;

  case 24:
#line 235 "syntax.y"
    {
          (yyval.node) = createNode("VarList", (yylsp[(1) - (1)]).first_line);
          (yyval.node)->child = (yyvsp[(1) - (1)].node);
      ;}
    break;

  case 25:
#line 239 "syntax.y"
    {
          (yyval.node) = NULL;
      ;}
    break;

  case 26:
#line 245 "syntax.y"
    {
          (yyval.node) = createNode("ParamDec", (yylsp[(1) - (2)]).first_line);
          (yyval.node)->child = (yyvsp[(1) - (2)].node);
          (yyvsp[(1) - (2)].node)->brother = (yyvsp[(2) - (2)].node);
      ;}
    break;

  case 27:
#line 253 "syntax.y"
    {
           (yyval.node) = createNode("Def", (yylsp[(1) - (3)]).first_line);
           (yyval.node)->child = (yyvsp[(1) - (3)].node);
           (yyvsp[(1) - (3)].node)->brother = (yyvsp[(2) - (3)].node);
           (yyvsp[(2) - (3)].node)->brother = (yyvsp[(3) - (3)].node);
       ;}
    break;

  case 28:
#line 259 "syntax.y"
    {
           yyerrok;
           (yyval.node) = NULL;
       ;}
    break;

  case 29:
#line 266 "syntax.y"
    {
          (yyval.node) = createNode("DecList", (yylsp[(1) - (3)]).first_line);
          (yyval.node)->child = (yyvsp[(1) - (3)].node);
          (yyvsp[(1) - (3)].node)->brother = (yyvsp[(2) - (3)].node);
          (yyvsp[(2) - (3)].node)->brother = (yyvsp[(3) - (3)].node);
      ;}
    break;

  case 30:
#line 272 "syntax.y"
    {
          (yyval.node) = createNode("DecList", (yylsp[(1) - (1)]).first_line);
          (yyval.node)->child = (yyvsp[(1) - (1)].node);
      ;}
    break;

  case 31:
#line 279 "syntax.y"
    {
          (yyval.node) = createNode("Dec", (yylsp[(1) - (1)]).first_line);
          (yyval.node)->child = (yyvsp[(1) - (1)].node);
      ;}
    break;

  case 32:
#line 283 "syntax.y"
    {
          (yyval.node) = createNode("Dec", (yylsp[(1) - (3)]).first_line);
          (yyval.node)->child = (yyvsp[(1) - (3)].node);
          (yyvsp[(1) - (3)].node)->brother = (yyvsp[(2) - (3)].node);
          (yyvsp[(1) - (3)].node)->brother->brother = (yyvsp[(3) - (3)].node);
      ;}
    break;

  case 33:
#line 292 "syntax.y"
    {
         (yyval.node) = createNode("VarDec", (yylsp[(1) - (1)]).first_line);
         (yyval.node)->child = (yyvsp[(1) - (1)].node);
     ;}
    break;

  case 34:
#line 296 "syntax.y"
    {
         (yyval.node) = createNode("VarDec", (yylsp[(1) - (4)]).first_line);
         (yyval.node)->child = (yyvsp[(1) - (4)].node);

         (yyvsp[(1) - (4)].node)->brother = (yyvsp[(2) - (4)].node);
         (yyvsp[(2) - (4)].node)->brother = (yyvsp[(3) - (4)].node);
         (yyvsp[(3) - (4)].node)->brother = (yyvsp[(4) - (4)].node);
     ;}
    break;

  case 35:
#line 304 "syntax.y"
    {
         yyerrok;
         (yyval.node) = createNode("VarDec", (yylsp[(1) - (4)]).first_line);
         (yyval.node)->child = (yyvsp[(1) - (4)].node);
         (yyvsp[(1) - (4)].node)->brother = (yyvsp[(2) - (4)].node);
         (yyvsp[(2) - (4)].node)->brother = (yyvsp[(4) - (4)].node);
     ;}
    break;

  case 36:
#line 315 "syntax.y"
    {
           (yyval.node) = createNode("CompSt", (yylsp[(1) - (4)]).first_line);
           (yyval.node)->child = (yyvsp[(1) - (4)].node);
           (yyvsp[(1) - (4)].node)->brother = (yyvsp[(2) - (4)].node);

           if ((yyvsp[(3) - (4)].node)) {
               (yyvsp[(2) - (4)].node)->brother = (yyvsp[(3) - (4)].node);
               (yyvsp[(3) - (4)].node)->brother = (yyvsp[(4) - (4)].node);
           }else{
               (yyvsp[(2) - (4)].node)->brother = (yyvsp[(4) - (4)].node);
           }
       ;}
    break;

  case 37:
#line 327 "syntax.y"
    {
           (yyval.node) = createNode("CompSt", (yylsp[(1) - (3)]).first_line);
           (yyval.node)->child = (yyvsp[(1) - (3)].node);

           if ((yyvsp[(2) - (3)].node)) {
               (yyvsp[(1) - (3)].node)->brother = (yyvsp[(2) - (3)].node);
               (yyvsp[(2) - (3)].node)->brother = (yyvsp[(3) - (3)].node);
           }else{
               (yyvsp[(1) - (3)].node)->brother = (yyvsp[(3) - (3)].node);
           }
       ;}
    break;

  case 38:
#line 341 "syntax.y"
    {
           (yyval.node) = createNode("StmtList", (yylsp[(1) - (2)]).first_line);
           (yyval.node)->child = (yyvsp[(1) - (2)].node);
           (yyvsp[(1) - (2)].node)->brother = (yyvsp[(2) - (2)].node);
       ;}
    break;

  case 39:
#line 346 "syntax.y"
    {
           (yyval.node) = NULL;
       ;}
    break;

  case 40:
#line 352 "syntax.y"
    {
           (yyval.node) = createNode("Stmt", (yylsp[(1) - (2)]).first_line);
           (yyval.node)->child = (yyvsp[(1) - (2)].node);
           (yyvsp[(1) - (2)].node)->brother = (yyvsp[(2) - (2)].node);
       ;}
    break;

  case 41:
#line 357 "syntax.y"
    {
           (yyval.node) = createNode("Stmt", (yylsp[(1) - (1)]).first_line);
           (yyval.node)->child = (yyvsp[(1) - (1)].node);
       ;}
    break;

  case 42:
#line 361 "syntax.y"
    {
           (yyval.node) = createNode("Stmt", (yylsp[(1) - (3)]).first_line);
           (yyval.node)->child = (yyvsp[(1) - (3)].node);
           (yyvsp[(1) - (3)].node)->brother = (yyvsp[(2) - (3)].node);
           (yyvsp[(2) - (3)].node)->brother = (yyvsp[(3) - (3)].node);
       ;}
    break;

  case 43:
#line 367 "syntax.y"
    {
           (yyval.node) = createNode("Stmt", (yylsp[(1) - (5)]).first_line);
           (yyval.node)->child = (yyvsp[(1) - (5)].node);
           (yyvsp[(1) - (5)].node)->brother = (yyvsp[(2) - (5)].node);
           (yyvsp[(2) - (5)].node)->brother = (yyvsp[(3) - (5)].node);
           (yyvsp[(3) - (5)].node)->brother = (yyvsp[(4) - (5)].node);
           (yyvsp[(4) - (5)].node)->brother = (yyvsp[(5) - (5)].node);
       ;}
    break;

  case 44:
#line 375 "syntax.y"
    {
           (yyval.node) = createNode("Stmt", (yylsp[(1) - (7)]).first_line);
           (yyval.node)->child = (yyvsp[(1) - (7)].node);
           (yyvsp[(1) - (7)].node)->brother = (yyvsp[(2) - (7)].node);
           (yyvsp[(2) - (7)].node)->brother = (yyvsp[(3) - (7)].node);
           (yyvsp[(3) - (7)].node)->brother = (yyvsp[(4) - (7)].node);
           (yyvsp[(4) - (7)].node)->brother = (yyvsp[(5) - (7)].node);
           (yyvsp[(5) - (7)].node)->brother = (yyvsp[(6) - (7)].node);
           (yyvsp[(6) - (7)].node)->brother = (yyvsp[(7) - (7)].node);
       ;}
    break;

  case 45:
#line 385 "syntax.y"
    {
           (yyval.node) = createNode("Stmt", (yylsp[(1) - (5)]).first_line);
           (yyval.node)->child = (yyvsp[(1) - (5)].node);
           (yyvsp[(1) - (5)].node)->brother = (yyvsp[(2) - (5)].node);
           (yyvsp[(2) - (5)].node)->brother = (yyvsp[(3) - (5)].node);
           (yyvsp[(3) - (5)].node)->brother = (yyvsp[(4) - (5)].node);
           (yyvsp[(4) - (5)].node)->brother = (yyvsp[(5) - (5)].node);
       ;}
    break;

  case 46:
#line 393 "syntax.y"
    {
           yyerrok;
           (yyval.node) = NULL;
       ;}
    break;

  case 47:
#line 400 "syntax.y"
    {
            (yyval.node) = createNode("Exp", (yylsp[(1) - (3)]).first_line);
            (yyval.node)->child = (yyvsp[(1) - (3)].node);
            (yyvsp[(1) - (3)].node)->brother = (yyvsp[(2) - (3)].node);
            (yyvsp[(2) - (3)].node)->brother = (yyvsp[(3) - (3)].node);
        ;}
    break;

  case 48:
#line 406 "syntax.y"
    {
            (yyval.node) = createNode("Exp", (yylsp[(1) - (3)]).first_line);
            (yyval.node)->child = (yyvsp[(1) - (3)].node);
            (yyvsp[(1) - (3)].node)->brother = (yyvsp[(2) - (3)].node);
            (yyvsp[(2) - (3)].node)->brother = (yyvsp[(3) - (3)].node);
        ;}
    break;

  case 49:
#line 412 "syntax.y"
    {
            (yyval.node) = createNode("Exp", (yylsp[(1) - (3)]).first_line);
            (yyval.node)->child = (yyvsp[(1) - (3)].node);
            (yyvsp[(1) - (3)].node)->brother = (yyvsp[(2) - (3)].node);
            (yyvsp[(2) - (3)].node)->brother = (yyvsp[(3) - (3)].node);
        ;}
    break;

  case 50:
#line 418 "syntax.y"
    {
            (yyval.node) = createNode("Exp", (yylsp[(1) - (3)]).first_line);
            (yyval.node)->child = (yyvsp[(1) - (3)].node);
            (yyvsp[(1) - (3)].node)->brother = (yyvsp[(2) - (3)].node);
            (yyvsp[(2) - (3)].node)->brother = (yyvsp[(3) - (3)].node);
        ;}
    break;

  case 51:
#line 424 "syntax.y"
    {
            (yyval.node) = createNode("Exp", (yylsp[(1) - (3)]).first_line);
            (yyval.node)->child = (yyvsp[(1) - (3)].node);
            (yyvsp[(1) - (3)].node)->brother = (yyvsp[(2) - (3)].node);
            (yyvsp[(2) - (3)].node)->brother = (yyvsp[(3) - (3)].node);
        ;}
    break;

  case 52:
#line 430 "syntax.y"
    {
            (yyval.node) = createNode("Exp", (yylsp[(1) - (3)]).first_line);
            (yyval.node)->child = (yyvsp[(1) - (3)].node);
            (yyvsp[(1) - (3)].node)->brother = (yyvsp[(2) - (3)].node);
            (yyvsp[(2) - (3)].node)->brother = (yyvsp[(3) - (3)].node);
        ;}
    break;

  case 53:
#line 436 "syntax.y"
    {
            (yyval.node) = createNode("Exp", (yylsp[(1) - (3)]).first_line);
            (yyval.node)->child = (yyvsp[(1) - (3)].node);
            (yyvsp[(1) - (3)].node)->brother = (yyvsp[(2) - (3)].node);
            (yyvsp[(2) - (3)].node)->brother = (yyvsp[(3) - (3)].node);
        ;}
    break;

  case 54:
#line 442 "syntax.y"
    {
            (yyval.node) = createNode("Exp", (yylsp[(1) - (3)]).first_line);
            (yyval.node)->child = (yyvsp[(1) - (3)].node);
            (yyvsp[(1) - (3)].node)->brother = (yyvsp[(2) - (3)].node);
            (yyvsp[(2) - (3)].node)->brother = (yyvsp[(3) - (3)].node);
        ;}
    break;

  case 55:
#line 448 "syntax.y"
    {
            (yyval.node) = createNode("Exp", (yylsp[(1) - (3)]).first_line);
            (yyval.node)->child = (yyvsp[(1) - (3)].node);
            (yyvsp[(1) - (3)].node)->brother = (yyvsp[(2) - (3)].node);
            (yyvsp[(2) - (3)].node)->brother = (yyvsp[(3) - (3)].node);
        ;}
    break;

  case 56:
#line 454 "syntax.y"
    {
            (yyval.node) = createNode("Exp", (yylsp[(1) - (2)]).first_line);
            (yyval.node)->child = (yyvsp[(1) - (2)].node);
            (yyvsp[(1) - (2)].node)->brother = (yyvsp[(2) - (2)].node);
        ;}
    break;

  case 57:
#line 459 "syntax.y"
    {
            (yyval.node) = createNode("Exp", (yylsp[(1) - (2)]).first_line);
            (yyval.node)->child = (yyvsp[(1) - (2)].node);
            (yyvsp[(1) - (2)].node)->brother = (yyvsp[(2) - (2)].node);
        ;}
    break;

  case 58:
#line 464 "syntax.y"
    {
            (yyval.node) = createNode("Exp", (yylsp[(1) - (4)]).first_line);
            (yyval.node)->child = (yyvsp[(1) - (4)].node);
            (yyvsp[(1) - (4)].node)->brother = (yyvsp[(2) - (4)].node);
            (yyvsp[(2) - (4)].node)->brother = (yyvsp[(3) - (4)].node);
            (yyvsp[(3) - (4)].node)->brother = (yyvsp[(4) - (4)].node);
        ;}
    break;

  case 59:
#line 471 "syntax.y"
    {
            (yyval.node) = createNode("Exp", (yylsp[(1) - (3)]).first_line);
            (yyval.node)->child = (yyvsp[(1) - (3)].node);
            (yyvsp[(1) - (3)].node)->brother = (yyvsp[(2) - (3)].node);
            (yyvsp[(2) - (3)].node)->brother = (yyvsp[(3) - (3)].node);
        ;}
    break;

  case 60:
#line 477 "syntax.y"
    {
            (yyval.node) = createNode("Exp", (yylsp[(1) - (4)]).first_line);
            (yyval.node)->child = (yyvsp[(1) - (4)].node);
            (yyvsp[(1) - (4)].node)->brother = (yyvsp[(2) - (4)].node);
            (yyvsp[(2) - (4)].node)->brother = (yyvsp[(3) - (4)].node);
            (yyvsp[(3) - (4)].node)->brother = (yyvsp[(4) - (4)].node);
        ;}
    break;

  case 61:
#line 484 "syntax.y"
    {
            (yyval.node) = createNode("Exp", (yylsp[(1) - (3)]).first_line);
            (yyval.node)->child = (yyvsp[(1) - (3)].node);
            (yyvsp[(1) - (3)].node)->brother = (yyvsp[(2) - (3)].node);
            (yyvsp[(2) - (3)].node)->brother = (yyvsp[(3) - (3)].node);
        ;}
    break;

  case 62:
#line 490 "syntax.y"
    {
            (yyval.node) = createNode("Exp", (yylsp[(1) - (1)]).first_line);
            (yyval.node)->child = (yyvsp[(1) - (1)].node);
        ;}
    break;

  case 63:
#line 494 "syntax.y"
    {
            (yyval.node) = createNode("Exp", (yylsp[(1) - (1)]).first_line);
            (yyval.node)->child = (yyvsp[(1) - (1)].node);
        ;}
    break;

  case 64:
#line 498 "syntax.y"
    {
            (yyval.node) = createNode("Exp", (yylsp[(1) - (1)]).first_line);
            (yyval.node)->child = (yyvsp[(1) - (1)].node);
        ;}
    break;

  case 65:
#line 505 "syntax.y"
    {
         (yyval.node) = createNode("Args", (yylsp[(1) - (3)]).first_line);
         (yyval.node)->child = (yyvsp[(1) - (3)].node);
         (yyvsp[(1) - (3)].node)->brother = (yyvsp[(2) - (3)].node);
         (yyvsp[(2) - (3)].node)->brother = (yyvsp[(3) - (3)].node);
     ;}
    break;

  case 66:
#line 511 "syntax.y"
    {
         (yyval.node) = createNode("Args", (yylsp[(1) - (1)]).first_line);
         (yyval.node)->child = (yyvsp[(1) - (1)].node);
     ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2229 "/Users/fengziyi/CLionProjects/untitled/cmake-build-debug/syntax.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  yyerror_range[0] = yylsp[1-yylen];
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
      if (yyn != YYPACT_NINF)
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
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


#line 516 "syntax.y"

