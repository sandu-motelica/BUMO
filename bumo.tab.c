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
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ASSIGN = 258,
     PROGR = 259,
     BGIN = 260,
     END = 261,
     CONST = 262,
     FUNCTION = 263,
     ADD = 264,
     AND = 265,
     NOT = 266,
     OR = 267,
     IF = 268,
     ELSE = 269,
     THEN = 270,
     EQ = 271,
     NQ = 272,
     GT = 273,
     LT = 274,
     LE = 275,
     GE = 276,
     IDENTIFIER = 277,
     TYPE = 278,
     STRING_VALUE = 279,
     CHAR_VALUE = 280,
     BOOL_VALUE = 281,
     INT_VALUE = 282,
     REAL_VALUE = 283,
     SUB = 284,
     DIV = 285,
     MUL = 286
   };
#endif
/* Tokens.  */
#define ASSIGN 258
#define PROGR 259
#define BGIN 260
#define END 261
#define CONST 262
#define FUNCTION 263
#define ADD 264
#define AND 265
#define NOT 266
#define OR 267
#define IF 268
#define ELSE 269
#define THEN 270
#define EQ 271
#define NQ 272
#define GT 273
#define LT 274
#define LE 275
#define GE 276
#define IDENTIFIER 277
#define TYPE 278
#define STRING_VALUE 279
#define CHAR_VALUE 280
#define BOOL_VALUE 281
#define INT_VALUE 282
#define REAL_VALUE 283
#define SUB 284
#define DIV 285
#define MUL 286




/* Copy the first part of user declarations.  */
#line 1 "bumo.y"

#include <iostream>
#include <vector>
#include <stdbool.h>
#include "VarList.h"
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yylex();
void yyerror(const char * s);
void createTable(const string& name,const string& type,const string& value, bool ct);
void initTable();
void clearTable();
class VarList variabile;
void checkVarDecl(const string& name,const string& type,const string& value, bool ct, int line);
void checkVarIsDecl(const string& name,const string& value, int line);
bool toBool(const string& val);

#define FILE_NAME "table.txt"


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
#line 22 "bumo.y"
{
    char* str;
    int intval;
    float ftval;
    bool bval;
}
/* Line 193 of yacc.c.  */
#line 186 "bumo.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 199 "bumo.tab.c"

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
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   251

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNRULES -- Number of states.  */
#define YYNSTATES  178

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
      37,    38,     2,     2,    39,     2,    32,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    34,    33,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    36,     2,     2,     2,     2,
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
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    10,    14,    15,    18,    20,    22,    27,
      33,    43,    50,    57,    64,    71,    82,    90,    98,   106,
     114,   123,   127,   132,   137,   139,   141,   145,   152,   153,
     156,   159,   164,   169,   174,   179,   184,   190,   196,   202,
     211,   224,   226,   228,   229,   231,   233,   235,   239,   243,
     247,   251,   255,   259,   263,   267,   269,   273,   277,   281,
     285,   289,   291,   295,   299,   302,   306,   308,   312,   316,
     320,   324,   328,   332,   336
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,    44,    45,     5,    53,     6,    32,    -1,
       4,    22,    33,    -1,    -1,    46,    45,    -1,    47,    -1,
      48,    -1,    22,    34,    23,    33,    -1,    22,    34,    23,
      52,    33,    -1,    22,    34,    23,    52,     3,    35,    57,
      36,    33,    -1,    22,    34,    23,     3,    58,    33,    -1,
      22,    34,    23,     3,    59,    33,    -1,    22,    34,    23,
       3,    51,    33,    -1,    22,    34,    23,     3,    60,    33,
      -1,     7,    22,    34,    23,    52,     3,    35,    57,    36,
      33,    -1,     7,    22,    34,    23,     3,    58,    33,    -1,
       7,    22,    34,    23,     3,    59,    33,    -1,     7,    22,
      34,    23,     3,    51,    33,    -1,     7,    22,    34,    23,
       3,    60,    33,    -1,     8,    22,    37,    49,    38,    34,
      23,    50,    -1,    22,    34,    23,    -1,    22,    34,    23,
      39,    -1,     5,    45,     6,    33,    -1,    25,    -1,    24,
      -1,    40,    27,    41,    -1,    40,    27,    41,    40,    27,
      41,    -1,    -1,    54,    53,    -1,    55,    53,    -1,    22,
       3,    22,    33,    -1,    22,     3,    58,    33,    -1,    22,
       3,    59,    33,    -1,    22,     3,    60,    33,    -1,    22,
       3,    51,    33,    -1,    22,    52,     3,    51,    33,    -1,
      22,    52,     3,    58,    33,    -1,    22,    52,     3,    59,
      33,    -1,    13,    37,    56,    38,    15,    35,    53,    36,
      -1,    13,    37,    56,    38,    15,    35,    53,    36,    14,
      35,    53,    36,    -1,    60,    -1,    61,    -1,    -1,    58,
      -1,    28,    -1,    51,    -1,    57,    39,    58,    -1,    57,
      39,    28,    -1,    57,    39,    51,    -1,    58,     9,    58,
      -1,    58,    29,    58,    -1,    58,    31,    58,    -1,    58,
      30,    58,    -1,    37,    58,    38,    -1,    27,    -1,    59,
       9,    59,    -1,    59,    29,    59,    -1,    59,    31,    59,
      -1,    59,    30,    59,    -1,    37,    59,    38,    -1,    28,
      -1,    60,    10,    60,    -1,    60,    12,    60,    -1,    11,
      60,    -1,    37,    60,    38,    -1,    26,    -1,    60,    16,
      60,    -1,    60,    17,    60,    -1,    58,    16,    58,    -1,
      58,    17,    58,    -1,    58,    20,    58,    -1,    58,    21,
      58,    -1,    58,    18,    58,    -1,    58,    19,    58,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    53,    53,    57,    60,    61,    65,    66,    70,    73,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      89,    93,    94,    97,   101,   102,   105,   106,   109,   111,
     112,   116,   117,   118,   119,   120,   121,   122,   123,   126,
     127,   131,   132,   134,   135,   136,   137,   138,   139,   140,
     142,   143,   144,   145,   146,   147,   149,   150,   151,   152,
     153,   154,   156,   157,   158,   159,   160,   163,   164,   165,
     166,   167,   168,   169,   170
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ASSIGN", "PROGR", "BGIN", "END",
  "CONST", "FUNCTION", "ADD", "AND", "NOT", "OR", "IF", "ELSE", "THEN",
  "EQ", "NQ", "GT", "LT", "LE", "GE", "IDENTIFIER", "TYPE", "STRING_VALUE",
  "CHAR_VALUE", "BOOL_VALUE", "INT_VALUE", "REAL_VALUE", "SUB", "DIV",
  "MUL", "'.'", "';'", "':'", "'{'", "'}'", "'('", "')'", "','", "'['",
  "']'", "$accept", "st", "name", "declarations", "declaration",
  "var_declaration", "function_declaration", "param", "block",
  "valoare_str", "dimensiune", "statements", "statement", "if_statement",
  "condition", "list", "int_expr", "real_expr", "bool_expr",
  "relativ_expr", 0
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
     285,   286,    46,    59,    58,   123,   125,    40,    41,    44,
      91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    45,    45,    46,    46,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      48,    49,    49,    50,    51,    51,    52,    52,    53,    53,
      53,    54,    54,    54,    54,    54,    54,    54,    54,    55,
      55,    56,    56,    57,    57,    57,    57,    57,    57,    57,
      58,    58,    58,    58,    58,    58,    59,    59,    59,    59,
      59,    59,    60,    60,    60,    60,    60,    61,    61,    61,
      61,    61,    61,    61,    61
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     3,     0,     2,     1,     1,     4,     5,
       9,     6,     6,     6,     6,    10,     7,     7,     7,     7,
       8,     3,     4,     4,     1,     1,     3,     6,     0,     2,
       2,     4,     4,     4,     4,     4,     5,     5,     5,     8,
      12,     1,     1,     0,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     3,
       3,     1,     3,     3,     2,     3,     1,     3,     3,     3,
       3,     3,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     4,     0,     1,     0,     0,     0,     0,
       4,     6,     7,     3,     0,     0,     0,    28,     5,     0,
       0,     0,     0,     0,     0,    28,    28,     0,     0,     0,
       0,     8,     0,     0,     0,     0,     0,     0,    29,    30,
       0,     0,     0,     0,     0,    25,    24,    66,    55,    61,
       0,     0,     0,     0,     0,     0,     0,     9,     0,     0,
       0,    41,    42,     0,     0,     0,     0,     0,     0,     2,
       0,     0,     0,     0,     0,    21,     0,     0,    64,     0,
       0,     0,    13,     0,     0,     0,     0,    11,     0,     0,
       0,     0,    12,     0,     0,    14,    26,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    31,    35,    32,
      33,    34,     0,     0,     0,     0,    18,    16,    17,    19,
      43,    22,     0,    54,    60,    65,     0,    50,    51,    53,
      52,     0,    56,    57,    59,    58,    62,    63,     0,    45,
      46,     0,    44,     0,    69,    70,    73,    74,    71,    72,
      67,    68,    36,    37,    38,     0,     4,    20,     0,     0,
       0,    28,     0,     0,    27,    10,    48,    49,    47,     0,
      15,     0,    39,    23,     0,    28,     0,    40
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,    10,    11,    12,    29,   157,   140,
      33,    24,    25,    26,    59,   141,    79,    80,    81,    62
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -28
static const yytype_int16 yypact[] =
{
      30,    16,    39,    73,    49,   -28,    74,    97,    21,   117,
      73,   -28,   -28,   -28,    91,    90,   106,     8,   -28,   107,
     113,     7,   118,     9,   152,     8,     8,    14,   125,   127,
      83,   -28,   153,     2,    87,    75,   166,   156,   -28,   -28,
      83,   192,   175,   162,   105,   -28,   -28,   -28,   -28,   -28,
      78,   167,   108,   114,    36,   158,   170,   -28,    87,   163,
     173,   218,   -28,   178,   183,   123,   131,   116,   185,   -28,
     186,   137,   142,   164,   191,   193,   202,   105,    33,    22,
      54,    12,   -28,    -9,    -9,    -9,    -9,   -28,    -5,    -5,
      -5,    -5,   -28,   105,   105,   -28,   189,   190,   216,    -9,
      -9,    -9,    -9,    -9,    -9,   105,   105,   -28,   -28,   -28,
     -28,   -28,    -1,   203,   148,   154,   -28,   -28,   -28,   -28,
     190,   -28,   232,   -28,   -28,   -28,    -9,    31,    31,   -28,
     -28,    -5,    57,    57,   -28,   -28,   226,   -28,   212,   -28,
     -28,    32,   177,   205,   177,   177,   177,   177,   177,   177,
      33,    33,   -28,   -28,   -28,    82,    73,   -28,   200,   209,
     196,     8,   210,   238,   -28,   -28,   -28,   -28,   177,   211,
     -28,   213,   231,   -28,   214,     8,   215,   -28
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -28,   -28,   -28,    -8,   -28,   -28,   -28,   -28,   -28,   -26,
      10,   -25,   -28,   -28,   -28,   128,   -27,   -24,   -15,   -28
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      38,    39,    18,    52,    51,    56,    53,    60,    65,    64,
      30,    66,    35,    71,    70,    54,    72,    40,    48,    61,
      67,    22,    93,    49,    94,    73,    48,    49,   126,    78,
      23,    83,   131,    36,     1,    57,   112,    41,     4,     5,
      31,   114,   113,    93,   115,    94,    93,    32,    94,    32,
     125,    84,    85,    86,    32,    16,   127,   128,   129,   130,
     123,    85,    86,    88,   132,   133,   134,   135,   159,    95,
     142,   160,   144,   145,   146,   147,   148,   149,   136,   137,
       6,     7,    13,    89,    90,    91,    44,    90,    91,    44,
     150,   151,   124,   142,    44,     8,    14,    63,    44,    45,
      46,    47,    48,    49,    47,    48,    49,    45,    46,    47,
      48,    49,    50,    47,    48,    50,    44,    83,   162,    15,
      50,   160,    17,    88,    58,    19,    93,    20,    94,    21,
      27,    47,    83,   168,   167,    28,   169,    84,    85,    86,
      88,    87,    77,    89,    90,    91,    83,    92,   163,   111,
     176,    88,    84,    85,    86,    34,   109,    83,    37,    42,
      89,    90,    91,    88,   110,    43,    84,    85,    86,    68,
     117,    89,    90,    91,    93,   118,    94,    84,    85,    86,
      55,   153,    83,    89,    90,    91,    83,   154,    69,    99,
     100,   101,   102,   103,   104,    74,    76,   119,    75,    96,
      82,    98,    84,    85,    86,    97,    84,    85,    86,    45,
      46,   107,    48,    49,    45,    46,   108,    48,   139,   116,
      45,    46,   112,    48,   166,   122,   120,   126,    93,   138,
      94,   143,   121,   126,   105,   106,   152,   156,    94,   158,
     161,   164,   165,   170,   171,   174,   173,   172,   155,   175,
       0,   177
};

static const yytype_int16 yycheck[] =
{
      25,    26,    10,    30,    30,     3,    30,    34,    35,    35,
       3,    35,     3,    40,    40,    30,    40,     3,    27,    34,
      35,    13,    10,    28,    12,    40,    27,    28,    37,    44,
      22,     9,    37,    23,     4,    33,    37,    27,    22,     0,
      33,    68,    68,    10,    68,    12,    10,    40,    12,    40,
      38,    29,    30,    31,    40,    34,    83,    84,    85,    86,
      38,    30,    31,     9,    88,    89,    90,    91,    36,    33,
      97,    39,    99,   100,   101,   102,   103,   104,    93,    94,
       7,     8,    33,    29,    30,    31,    11,    30,    31,    11,
     105,   106,    38,   120,    11,    22,    22,    22,    11,    24,
      25,    26,    27,    28,    26,    27,    28,    24,    25,    26,
      27,    28,    37,    26,    27,    37,    11,     9,    36,    22,
      37,    39,     5,     9,    37,    34,    10,    37,    12,    23,
      23,    26,     9,   160,   160,    22,   161,    29,    30,    31,
       9,    33,    37,    29,    30,    31,     9,    33,   156,    33,
     175,     9,    29,    30,    31,    37,    33,     9,     6,    34,
      29,    30,    31,     9,    33,    38,    29,    30,    31,     3,
      33,    29,    30,    31,    10,    33,    12,    29,    30,    31,
      27,    33,     9,    29,    30,    31,     9,    33,    32,    16,
      17,    18,    19,    20,    21,     3,    34,    33,    23,    41,
      33,    38,    29,    30,    31,    35,    29,    30,    31,    24,
      25,    33,    27,    28,    24,    25,    33,    27,    28,    33,
      24,    25,    37,    27,    28,    23,    35,    37,    10,    40,
      12,    15,    39,    37,    16,    17,    33,     5,    12,    27,
      35,    41,    33,    33,     6,    14,    33,    36,   120,    35,
      -1,    36
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    43,    44,    22,     0,     7,     8,    22,    45,
      46,    47,    48,    33,    22,    22,    34,     5,    45,    34,
      37,    23,    13,    22,    53,    54,    55,    23,    22,    49,
       3,    33,    40,    52,    37,     3,    52,     6,    53,    53,
       3,    52,    34,    38,    11,    24,    25,    26,    27,    28,
      37,    51,    58,    59,    60,    27,     3,    33,    37,    56,
      58,    60,    61,    22,    51,    58,    59,    60,     3,    32,
      51,    58,    59,    60,     3,    23,    34,    37,    60,    58,
      59,    60,    33,     9,    29,    30,    31,    33,     9,    29,
      30,    31,    33,    10,    12,    33,    41,    35,    38,    16,
      17,    18,    19,    20,    21,    16,    17,    33,    33,    33,
      33,    33,    37,    51,    58,    59,    33,    33,    33,    33,
      35,    39,    23,    38,    38,    38,    37,    58,    58,    58,
      58,    37,    59,    59,    59,    59,    60,    60,    40,    28,
      51,    57,    58,    15,    58,    58,    58,    58,    58,    58,
      60,    60,    33,    33,    33,    57,     5,    50,    27,    36,
      39,    35,    36,    45,    41,    33,    28,    51,    58,    53,
      33,     6,    36,    33,    14,    35,    53,    36
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
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
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

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



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


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


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

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

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 53 "bumo.y"
    {printf("The programme is correct!\n");;}
    break;

  case 8:
#line 70 "bumo.y"
    { if(!variabile.declareVariable((yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].str),false)){
            fprintf(stderr, "%d: Error: Variable %s is already defined\n",yylineno, (yyvsp[(1) - (4)].str));
            exit(EXIT_FAILURE); };}
    break;

  case 9:
#line 73 "bumo.y"
    { if(!variabile.declareVariable((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str),false)){
            fprintf(stderr, "%d: Error: Variable %s is already defined\n",yylineno, (yyvsp[(1) - (5)].str));
            exit(EXIT_FAILURE); };}
    break;

  case 11:
#line 77 "bumo.y"
    { checkVarDecl((yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].str),to_string((yyvsp[(5) - (6)].intval)),false,yylineno); ;}
    break;

  case 12:
#line 78 "bumo.y"
    { checkVarDecl((yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].str),to_string((yyvsp[(5) - (6)].ftval)),false,yylineno); ;}
    break;

  case 13:
#line 79 "bumo.y"
    { checkVarDecl((yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str),false,yylineno); ;}
    break;

  case 14:
#line 80 "bumo.y"
    { checkVarDecl((yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].bval) ? "true" : "false",false,yylineno); ;}
    break;

  case 16:
#line 82 "bumo.y"
    { checkVarDecl((yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),to_string((yyvsp[(6) - (7)].intval)),true,yylineno); ;}
    break;

  case 17:
#line 83 "bumo.y"
    { checkVarDecl((yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),to_string((yyvsp[(6) - (7)].ftval)),true,yylineno); ;}
    break;

  case 18:
#line 84 "bumo.y"
    { checkVarDecl((yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(6) - (7)].str),true,yylineno); ;}
    break;

  case 19:
#line 85 "bumo.y"
    { checkVarDecl((yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(6) - (7)].bval) ? "true" : "false",true,yylineno); ;}
    break;

  case 24:
#line 101 "bumo.y"
    {(yyval.str) = (yyvsp[(1) - (1)].str);;}
    break;

  case 25:
#line 102 "bumo.y"
    {(yyval.str) = (yyvsp[(1) - (1)].str);;}
    break;

  case 32:
#line 117 "bumo.y"
    {checkVarIsDecl((yyvsp[(1) - (4)].str),to_string((yyvsp[(3) - (4)].intval)),yylineno);;}
    break;

  case 33:
#line 118 "bumo.y"
    {checkVarIsDecl((yyvsp[(1) - (4)].str),to_string((yyvsp[(3) - (4)].ftval)),yylineno);;}
    break;

  case 34:
#line 119 "bumo.y"
    {checkVarIsDecl((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].bval) ? "true" : "false",yylineno);;}
    break;

  case 35:
#line 120 "bumo.y"
    {checkVarIsDecl((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str),yylineno);;}
    break;

  case 50:
#line 142 "bumo.y"
    {(yyval.intval) = (yyvsp[(1) - (3)].intval) + (yyvsp[(3) - (3)].intval);;}
    break;

  case 51:
#line 143 "bumo.y"
    {(yyval.intval) = (yyvsp[(1) - (3)].intval) - (yyvsp[(3) - (3)].intval);;}
    break;

  case 52:
#line 144 "bumo.y"
    {(yyval.intval) = (yyvsp[(1) - (3)].intval) * (yyvsp[(3) - (3)].intval);;}
    break;

  case 53:
#line 145 "bumo.y"
    {(yyval.intval) = (yyvsp[(1) - (3)].intval) / (yyvsp[(3) - (3)].intval);;}
    break;

  case 54:
#line 146 "bumo.y"
    {(yyval.intval) = (yyvsp[(2) - (3)].intval); ;}
    break;

  case 55:
#line 147 "bumo.y"
    {(yyval.intval) = (yyvsp[(1) - (1)].intval);;}
    break;

  case 56:
#line 149 "bumo.y"
    {(yyval.ftval) = (yyvsp[(1) - (3)].ftval) + (yyvsp[(3) - (3)].ftval);;}
    break;

  case 57:
#line 150 "bumo.y"
    {(yyval.ftval) = (yyvsp[(1) - (3)].ftval) - (yyvsp[(3) - (3)].ftval);;}
    break;

  case 58:
#line 151 "bumo.y"
    {(yyval.ftval) = (yyvsp[(1) - (3)].ftval) * (yyvsp[(3) - (3)].ftval);;}
    break;

  case 59:
#line 152 "bumo.y"
    {(yyval.ftval) = (yyvsp[(1) - (3)].ftval) / (yyvsp[(3) - (3)].ftval);;}
    break;

  case 60:
#line 153 "bumo.y"
    {(yyval.ftval) = (yyvsp[(2) - (3)].ftval); ;}
    break;

  case 61:
#line 154 "bumo.y"
    {(yyval.ftval) = (yyvsp[(1) - (1)].ftval);;}
    break;

  case 62:
#line 156 "bumo.y"
    {  (yyval.bval) = (yyvsp[(1) - (3)].bval) && (yyvsp[(3) - (3)].bval);;}
    break;

  case 63:
#line 157 "bumo.y"
    {(yyval.bval) = (yyvsp[(1) - (3)].bval) || (yyvsp[(3) - (3)].bval);;}
    break;

  case 64:
#line 158 "bumo.y"
    {(yyval.bval) = !(yyvsp[(2) - (2)].bval);;}
    break;

  case 65:
#line 159 "bumo.y"
    {(yyval.bval) = (yyvsp[(2) - (3)].bval); ;}
    break;

  case 66:
#line 160 "bumo.y"
    {(yyval.bval) = toBool((yyvsp[(1) - (1)].str));;}
    break;

  case 67:
#line 163 "bumo.y"
    {(yyval.bval) = ((yyvsp[(1) - (3)].bval) == (yyvsp[(3) - (3)].bval));;}
    break;

  case 68:
#line 164 "bumo.y"
    {(yyval.bval) = ((yyvsp[(1) - (3)].bval) != (yyvsp[(3) - (3)].bval));;}
    break;

  case 69:
#line 165 "bumo.y"
    {(yyval.bval) = ((yyvsp[(1) - (3)].intval) == (yyvsp[(3) - (3)].intval));;}
    break;

  case 70:
#line 166 "bumo.y"
    {(yyval.bval) = ((yyvsp[(1) - (3)].intval) != (yyvsp[(3) - (3)].intval));;}
    break;

  case 71:
#line 167 "bumo.y"
    {(yyval.bval) = ((yyvsp[(1) - (3)].intval) <= (yyvsp[(3) - (3)].intval));;}
    break;

  case 72:
#line 168 "bumo.y"
    {(yyval.bval) = ((yyvsp[(1) - (3)].intval) >= (yyvsp[(3) - (3)].intval));;}
    break;

  case 73:
#line 169 "bumo.y"
    {(yyval.bval) = ((yyvsp[(1) - (3)].intval) > (yyvsp[(3) - (3)].intval));;}
    break;

  case 74:
#line 170 "bumo.y"
    {(yyval.bval) = ((yyvsp[(1) - (3)].intval) > (yyvsp[(3) - (3)].intval));;}
    break;


/* Line 1267 of yacc.c.  */
#line 1771 "bumo.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


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
		      yytoken, &yylval);
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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


#line 172 "bumo.y"

void yyerror(const char * s){
printf("error: %s at line:%d\n",s,yylineno);
}

void checkVarDecl(const string& name,const string& type,const string& value, bool ct,int line){
    if(!variabile.declareVariable(name, type,ct)){
            fprintf(stderr, "%d: Error: Variable %s is already defined\n",line, name.c_str());
            exit(EXIT_FAILURE); }
    if(!variabile.isCompatibleValue(type,value)){
        fprintf(stderr, "%d: Error: Invalid value for variable '%s' of type %s\n",line, name.c_str(),type.c_str());
        exit(EXIT_FAILURE); 
    }
    createTable(name,type, value,ct);
}
void checkVarIsDecl(const string& name,const string& value, int line){
    if(variabile.isConstant(name)){
        fprintf(stderr, "%d: Error: Constant %s can't be changed\n",line, name.c_str());
        exit(EXIT_FAILURE);
    }
    if(variabile.IsDeclareVariable(name,value)==3){
        fprintf(stderr, "%d: Error: Variable %s is not defined\n",line, name.c_str());
        exit(EXIT_FAILURE); }
    else if(variabile.IsDeclareVariable(name,value)==2){
        fprintf(stderr, "%d: Error: Invalid value for variable '%s'\n",line, name.c_str());
        exit(EXIT_FAILURE); 
    }
}
bool toBool(const string& val){
    if(val == "true") return true;
    return false;
}

void createTable(const string& name,const string& type,const string& value, bool ct) {
    FILE *file = fopen(FILE_NAME, "a");

    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
    }

    fprintf(file, "%s       %s       %s        %s  ", name.c_str(),type.c_str(),value.c_str(), ct ? "true" : "false");
     fprintf(file, "\n");

    // Close the file
    fclose(file);

}

void initTable() {
     FILE *file = fopen(FILE_NAME, "a");
       if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
    }
    fprintf(file, "ID       TIP       VAL        CONST");
    fprintf(file, "\n");

    // Close the file
    fclose(file);
}

void clearTable() {
     // Specify the file path

    // Use the remove function to delete the file
    if (remove(FILE_NAME) != 0) {
        perror("Error deleting file");
    }

    printf("File %s deleted successfully.\n", FILE_NAME);
}

int main(int argc, char** argv){
    clearTable();
     initTable();
     yyin=fopen(argv[1],"r");
     yyparse();    
} 

