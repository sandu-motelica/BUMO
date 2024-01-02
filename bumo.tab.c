/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
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
class VarList variabile;
void checkVarDecl(const string& name,const string& type,const string& value, bool ct, int line);
void checkVarIsDecl(const string& name,const string& value, int line);
bool toBool(const string& val);

#line 86 "bumo.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_BUMO_TAB_H_INCLUDED
# define YY_YY_BUMO_TAB_H_INCLUDED
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
    FOR = 277,
    WHILE = 278,
    IDENTIFIER = 279,
    TYPE = 280,
    STRING_VALUE = 281,
    CHAR_VALUE = 282,
    BOOL_VALUE = 283,
    INT_VALUE = 284,
    REAL_VALUE = 285,
    SUB = 286,
    MUL = 287,
    DIV = 288
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "bumo.y"

    char* str;
    int intval;
    float ftval;
    bool bval;

#line 179 "bumo.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BUMO_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   318

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  227

#define YYUNDEFTOK  2
#define YYMAXUTOK   288


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      39,    40,     2,     2,    41,     2,    34,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    36,    35,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    47,    47,    51,    54,    55,    59,    60,    64,    67,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      83,    87,    88,    91,    95,    96,    99,   100,   104,   106,
     107,   108,   109,   113,   114,   115,   116,   117,   118,   119,
     128,   129,   132,   133,   136,   139,   140,   141,   144,   145,
     148,   149,   150,   151,   152,   153,   154,   156,   157,   158,
     159,   160,   161,   163,   164,   165,   166,   167,   168,   171,
     172,   173,   174,   175,   176,   180,   181,   182,   183,   184,
     185,   186,   187,   191,   192,   193,   194,   195
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ASSIGN", "PROGR", "BGIN", "END",
  "CONST", "FUNCTION", "ADD", "AND", "NOT", "OR", "IF", "ELSE", "THEN",
  "EQ", "NQ", "GT", "LT", "LE", "GE", "FOR", "WHILE", "IDENTIFIER", "TYPE",
  "STRING_VALUE", "CHAR_VALUE", "BOOL_VALUE", "INT_VALUE", "REAL_VALUE",
  "SUB", "MUL", "DIV", "'.'", "';'", "':'", "'{'", "'}'", "'('", "')'",
  "','", "'['", "']'", "$accept", "st", "name", "declarations",
  "declaration", "var_declaration", "function_declaration", "param",
  "block", "valoare_str", "dimensiune", "statements", "statement",
  "if_statement", "for_statement", "while_statement", "expression",
  "condition", "list", "int_expr", "real_expr", "bool_expr",
  "relativ_expr", "relativ_condition", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,    46,    59,    58,   123,   125,    40,
      41,    44,    91,    93
};
# endif

#define YYPACT_NINF (-124)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       2,    12,    18,    96,    -9,  -124,    24,    34,    79,   129,
      96,  -124,  -124,  -124,    92,   101,   130,   161,  -124,   139,
     135,    10,   137,   141,   143,    -1,   163,   161,   161,   161,
     161,     0,   151,   152,   178,  -124,   182,    14,    77,   186,
      77,   178,   227,   202,  -124,  -124,  -124,  -124,   178,   243,
     209,   213,    16,  -124,  -124,  -124,  -124,  -124,  -124,   138,
     207,   166,   181,    44,   218,   228,  -124,    77,    77,   226,
     239,   257,  -124,   107,     1,   240,   233,   187,   194,   117,
     252,  -124,   248,   200,   206,   123,   247,   245,   260,    16,
     134,    38,    99,    19,  -124,    -7,    -7,    -7,    -7,  -124,
      -6,    -6,    -6,    -6,  -124,    16,    16,  -124,   246,   252,
     257,   107,   105,   131,    41,   272,    -7,    -7,    -7,    -7,
      -7,    -7,    16,    16,    77,    77,   138,   264,   285,  -124,
    -124,  -124,  -124,    61,   258,   212,   219,  -124,  -124,  -124,
    -124,   252,  -124,   285,  -124,  -124,  -124,    -7,    33,    33,
    -124,  -124,    -6,   191,   191,  -124,  -124,   280,  -124,   265,
    -124,   115,   231,   244,  -124,   259,   231,   231,   231,   231,
     231,   231,  -124,  -124,   257,   283,  -124,   262,   231,   244,
     134,   295,   161,  -124,  -124,  -124,  -124,   153,  -124,   256,
     266,   252,   161,    77,   138,   294,   267,  -124,  -124,  -124,
     231,   244,   268,   269,   270,   273,  -124,   289,   286,    77,
    -124,   274,   304,   277,   161,   138,   290,   271,   275,   310,
    -124,   285,   138,  -124,   276,   285,  -124
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     4,     0,     1,     0,     0,     0,     0,
       4,     6,     7,     3,     0,     0,     0,    28,     5,     0,
       0,     0,     0,     0,     0,     0,     0,    28,    28,    28,
      28,     0,     0,     0,     0,     8,     0,     0,     0,     0,
       0,     0,     0,     0,    29,    30,    31,    32,     0,     0,
       0,     0,     0,    74,    25,    24,    73,    62,    68,     0,
       0,     0,     0,     0,     0,     0,     9,     0,     0,     0,
       0,    48,    87,    49,     0,     0,     0,     0,     0,     0,
       0,     2,     0,     0,     0,     0,     0,    21,     0,     0,
      71,     0,     0,     0,    13,     0,     0,     0,     0,    11,
       0,     0,     0,     0,    12,     0,     0,    14,    26,    50,
      71,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    36,
      33,    34,    35,     0,     0,     0,     0,    18,    16,    17,
      19,    50,    22,     0,    61,    67,    72,     0,    57,    58,
      59,    60,     0,    63,    64,    65,    66,    69,    70,     0,
      53,     0,    51,    52,    86,     0,    77,    78,    81,    82,
      79,    80,    75,    76,     0,    83,    84,     0,    46,    47,
      45,     0,    28,    44,    37,    38,    39,     0,    20,     0,
       0,     0,    28,     0,     0,     0,     0,    27,    10,    56,
      54,    55,     0,     0,     0,     0,    15,    40,     0,     0,
      23,     0,     0,     0,    28,     0,     0,     0,     0,     0,
      41,     0,     0,    42,     0,     0,    43
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -124,  -124,  -124,   307,  -124,  -124,  -124,  -124,  -123,   -13,
      49,   -19,  -124,  -124,  -124,  -124,   -43,   -39,   177,   -34,
       9,   -29,  -124,   -52
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,    10,    11,    12,    33,   183,   160,
      37,    26,    27,    28,    29,    30,   177,    69,   161,    70,
     179,    71,    72,    73
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      61,    75,    41,    48,   126,    63,     1,    77,    44,    45,
      46,    47,    79,    34,    83,   111,   114,    65,     5,    85,
     188,    60,    57,    90,    58,    91,    13,    52,    76,   105,
      93,   106,   147,   152,   112,    82,     4,   127,   110,   113,
      53,    36,    36,    62,    56,    35,   135,    95,    14,    66,
      78,   124,    36,   125,   105,    89,   106,    84,    15,   146,
      93,   148,   149,   150,   151,    97,    98,   134,    92,    96,
      97,    98,   175,   176,    42,   162,   157,   158,   144,   107,
      49,   164,   166,   167,   168,   169,   170,   171,    67,   136,
      57,    58,   178,   172,   173,   174,   174,   180,   223,    91,
     133,    53,   226,     6,     7,    56,    57,   162,   100,   153,
     154,   155,   156,    91,    95,    16,    68,   124,   163,   125,
       8,   116,   117,   118,   119,   120,   121,   105,    19,   106,
     101,   102,   103,   105,    17,   106,    96,    97,    98,   145,
      20,   105,    92,   106,   105,   144,   106,   122,   123,    52,
     163,   204,   132,   190,   203,    21,   191,   200,   140,    32,
     178,    92,    53,   195,    31,   180,    56,    57,    58,    43,
     213,   146,   218,   202,    22,    95,    38,    59,   199,   224,
      39,   178,    40,    23,    24,    25,   180,    50,   178,    52,
     100,   196,    51,   180,   191,   217,    95,    96,    97,    98,
     201,    99,    53,   100,    54,    55,    56,    57,    58,    95,
      74,    64,   101,   102,   103,   100,   104,    59,    96,    97,
      98,    95,   130,   102,   103,   101,   102,   103,   100,   131,
      80,    96,    97,    98,    87,   138,    81,   101,   102,   103,
      95,   139,    94,    96,    97,    98,    86,   185,    95,    88,
     101,   102,   103,   100,   186,   116,   117,   118,   119,   120,
     121,   108,    96,    97,    98,   109,   115,   105,   129,   106,
      96,    97,    98,   122,   123,   101,   102,   103,    54,    55,
     128,    57,    58,   137,   141,   143,   142,   165,   159,   181,
     182,   133,   106,   184,   189,   125,   192,   193,   194,   197,
     205,   198,   206,   211,   208,   209,   207,   215,   210,   220,
     212,   214,   216,   222,   219,   221,   225,    18,   187
};

static const yytype_uint8 yycheck[] =
{
      34,    40,     3,     3,     3,    34,     4,    41,    27,    28,
      29,    30,    41,     3,    48,    67,    68,     3,     0,    48,
     143,    34,    29,    52,    30,    59,    35,    11,    41,    10,
      59,    12,    39,    39,    68,    48,    24,    36,    67,    68,
      24,    42,    42,    34,    28,    35,    80,     9,    24,    35,
      41,    10,    42,    12,    10,    39,    12,    48,    24,    40,
      89,    95,    96,    97,    98,    32,    33,    80,    59,    31,
      32,    33,   124,   125,    25,   109,   105,   106,    40,    35,
      31,    40,   116,   117,   118,   119,   120,   121,    11,    80,
      29,    30,   126,   122,   123,   124,   125,   126,   221,   133,
      39,    24,   225,     7,     8,    28,    29,   141,     9,   100,
     101,   102,   103,   147,     9,    36,    39,    10,   109,    12,
      24,    16,    17,    18,    19,    20,    21,    10,    36,    12,
      31,    32,    33,    10,     5,    12,    31,    32,    33,    40,
      39,    10,   133,    12,    10,    40,    12,    16,    17,    11,
     141,   194,    35,    38,   193,    25,    41,   191,    35,    24,
     194,   152,    24,   182,    25,   194,    28,    29,    30,     6,
     209,    40,   215,   192,    13,     9,    39,    39,   191,   222,
      39,   215,    39,    22,    23,    24,   215,    36,   222,    11,
       9,    38,    40,   222,    41,   214,     9,    31,    32,    33,
     191,    35,    24,     9,    26,    27,    28,    29,    30,     9,
      24,    29,    31,    32,    33,     9,    35,    39,    31,    32,
      33,     9,    35,    32,    33,    31,    32,    33,     9,    35,
       3,    31,    32,    33,    25,    35,    34,    31,    32,    33,
       9,    35,    35,    31,    32,    33,     3,    35,     9,    36,
      31,    32,    33,     9,    35,    16,    17,    18,    19,    20,
      21,    43,    31,    32,    33,    37,    40,    10,    35,    12,
      31,    32,    33,    16,    17,    31,    32,    33,    26,    27,
      40,    29,    30,    35,    37,    25,    41,    15,    42,    25,
       5,    39,    12,    35,    29,    12,    37,    35,     3,    43,
       6,    35,    35,    14,    35,    35,    38,     3,    35,    38,
      24,    37,    35,     3,    24,    40,    40,    10,   141
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,    45,    46,    24,     0,     7,     8,    24,    47,
      48,    49,    50,    35,    24,    24,    36,     5,    47,    36,
      39,    25,    13,    22,    23,    24,    55,    56,    57,    58,
      59,    25,    24,    51,     3,    35,    42,    54,    39,    39,
      39,     3,    54,     6,    55,    55,    55,    55,     3,    54,
      36,    40,    11,    24,    26,    27,    28,    29,    30,    39,
      53,    63,    64,    65,    29,     3,    35,    11,    39,    61,
      63,    65,    66,    67,    24,    61,    53,    63,    64,    65,
       3,    34,    53,    63,    64,    65,     3,    25,    36,    39,
      65,    63,    64,    65,    35,     9,    31,    32,    33,    35,
       9,    31,    32,    33,    35,    10,    12,    35,    43,    37,
      65,    67,    63,    65,    67,    40,    16,    17,    18,    19,
      20,    21,    16,    17,    10,    12,     3,    36,    40,    35,
      35,    35,    35,    39,    53,    63,    64,    35,    35,    35,
      35,    37,    41,    25,    40,    40,    40,    39,    63,    63,
      63,    63,    39,    64,    64,    64,    64,    65,    65,    42,
      53,    62,    63,    64,    40,    15,    63,    63,    63,    63,
      63,    63,    65,    65,    65,    67,    67,    60,    63,    64,
      65,    25,     5,    52,    35,    35,    35,    62,    52,    29,
      38,    41,    37,    35,     3,    55,    38,    43,    35,    53,
      63,    64,    55,    61,    60,     6,    35,    38,    35,    35,
      35,    14,    24,    61,    37,     3,    35,    55,    60,    24,
      38,    40,     3,    52,    60,    40,    52
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    47,    47,    48,    48,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      50,    51,    51,    52,    53,    53,    54,    54,    55,    55,
      55,    55,    55,    56,    56,    56,    56,    56,    56,    56,
      57,    57,    58,    58,    59,    60,    60,    60,    61,    61,
      62,    62,    62,    62,    62,    62,    62,    63,    63,    63,
      63,    63,    63,    64,    64,    64,    64,    64,    64,    65,
      65,    65,    65,    65,    65,    66,    66,    66,    66,    66,
      66,    66,    66,    67,    67,    67,    67,    67
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     6,     3,     0,     2,     1,     1,     4,     5,
       9,     6,     6,     6,     6,    10,     7,     7,     7,     7,
       8,     3,     4,     4,     1,     1,     3,     6,     0,     2,
       2,     2,     2,     4,     4,     4,     4,     5,     5,     5,
       8,    12,    13,    15,     5,     1,     1,     1,     1,     1,
       0,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     3,     3,     1,     3,
       3,     2,     3,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
      yychar = yylex ();
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

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
#line 47 "bumo.y"
                                             {printf("The programme is correct!\n");}
#line 1513 "bumo.tab.c"
    break;

  case 8:
#line 64 "bumo.y"
                            { if(!variabile.declareVariable((yyvsp[-3].str), (yyvsp[-1].str),false)){
            fprintf(stderr, "%d: Error: Variable %s is already defined\n",yylineno, (yyvsp[-3].str));
            exit(EXIT_FAILURE); }}
#line 1521 "bumo.tab.c"
    break;

  case 9:
#line 67 "bumo.y"
                                         { if(!variabile.declareVariable((yyvsp[-4].str), (yyvsp[-2].str),false)){
            fprintf(stderr, "%d: Error: Variable %s is already defined\n",yylineno, (yyvsp[-4].str));
            exit(EXIT_FAILURE); }}
#line 1529 "bumo.tab.c"
    break;

  case 11:
#line 71 "bumo.y"
                                               { checkVarDecl((yyvsp[-5].str),(yyvsp[-3].str),to_string((yyvsp[-1].intval)),false,yylineno); }
#line 1535 "bumo.tab.c"
    break;

  case 12:
#line 72 "bumo.y"
                                               { checkVarDecl((yyvsp[-5].str),(yyvsp[-3].str),to_string((yyvsp[-1].ftval)),false,yylineno); }
#line 1541 "bumo.tab.c"
    break;

  case 13:
#line 73 "bumo.y"
                                                 { checkVarDecl((yyvsp[-5].str),(yyvsp[-3].str),(yyvsp[-1].str),false,yylineno); }
#line 1547 "bumo.tab.c"
    break;

  case 14:
#line 74 "bumo.y"
                                               { checkVarDecl((yyvsp[-5].str),(yyvsp[-3].str),(yyvsp[-1].bval) ? "true" : "false",false,yylineno); }
#line 1553 "bumo.tab.c"
    break;

  case 16:
#line 76 "bumo.y"
                                                     { checkVarDecl((yyvsp[-5].str),(yyvsp[-3].str),to_string((yyvsp[-1].intval)),true,yylineno); }
#line 1559 "bumo.tab.c"
    break;

  case 17:
#line 77 "bumo.y"
                                                     { checkVarDecl((yyvsp[-5].str),(yyvsp[-3].str),to_string((yyvsp[-1].ftval)),true,yylineno); }
#line 1565 "bumo.tab.c"
    break;

  case 18:
#line 78 "bumo.y"
                                                       { checkVarDecl((yyvsp[-5].str),(yyvsp[-3].str),(yyvsp[-1].str),true,yylineno); }
#line 1571 "bumo.tab.c"
    break;

  case 19:
#line 79 "bumo.y"
                                                     { checkVarDecl((yyvsp[-5].str),(yyvsp[-3].str),(yyvsp[-1].bval) ? "true" : "false",true,yylineno); }
#line 1577 "bumo.tab.c"
    break;

  case 24:
#line 95 "bumo.y"
                   {(yyval.str) = (yyvsp[0].str);}
#line 1583 "bumo.tab.c"
    break;

  case 25:
#line 96 "bumo.y"
                    {(yyval.str) = (yyvsp[0].str);}
#line 1589 "bumo.tab.c"
    break;

  case 33:
#line 113 "bumo.y"
                                     {checkVarIsDecl((yyvsp[-3].str),to_string((yyvsp[-1].intval)),yylineno);}
#line 1595 "bumo.tab.c"
    break;

  case 34:
#line 114 "bumo.y"
                                       {checkVarIsDecl((yyvsp[-3].str),to_string((yyvsp[-1].ftval)),yylineno);}
#line 1601 "bumo.tab.c"
    break;

  case 35:
#line 115 "bumo.y"
                                       {checkVarIsDecl((yyvsp[-3].str),(yyvsp[-1].bval) ? "true" : "false",yylineno);}
#line 1607 "bumo.tab.c"
    break;

  case 36:
#line 116 "bumo.y"
                                         {checkVarIsDecl((yyvsp[-3].str),(yyvsp[-1].str),yylineno);}
#line 1613 "bumo.tab.c"
    break;

  case 57:
#line 156 "bumo.y"
                                   {(yyval.intval) = (yyvsp[-2].intval) + (yyvsp[0].intval);}
#line 1619 "bumo.tab.c"
    break;

  case 58:
#line 157 "bumo.y"
                            {(yyval.intval) = (yyvsp[-2].intval) - (yyvsp[0].intval);}
#line 1625 "bumo.tab.c"
    break;

  case 59:
#line 158 "bumo.y"
                            {(yyval.intval) = (yyvsp[-2].intval) * (yyvsp[0].intval);}
#line 1631 "bumo.tab.c"
    break;

  case 60:
#line 159 "bumo.y"
                            {(yyval.intval) = (yyvsp[-2].intval) / (yyvsp[0].intval);}
#line 1637 "bumo.tab.c"
    break;

  case 61:
#line 160 "bumo.y"
                      {(yyval.intval) = (yyvsp[-1].intval); }
#line 1643 "bumo.tab.c"
    break;

  case 62:
#line 161 "bumo.y"
               {(yyval.intval) = (yyvsp[0].intval);}
#line 1649 "bumo.tab.c"
    break;

  case 63:
#line 163 "bumo.y"
                                      {(yyval.ftval) = (yyvsp[-2].ftval) + (yyvsp[0].ftval);}
#line 1655 "bumo.tab.c"
    break;

  case 64:
#line 164 "bumo.y"
                              {(yyval.ftval) = (yyvsp[-2].ftval) - (yyvsp[0].ftval);}
#line 1661 "bumo.tab.c"
    break;

  case 65:
#line 165 "bumo.y"
                              {(yyval.ftval) = (yyvsp[-2].ftval) * (yyvsp[0].ftval);}
#line 1667 "bumo.tab.c"
    break;

  case 66:
#line 166 "bumo.y"
                              {(yyval.ftval) = (yyvsp[-2].ftval) / (yyvsp[0].ftval);}
#line 1673 "bumo.tab.c"
    break;

  case 67:
#line 167 "bumo.y"
                       {(yyval.ftval) = (yyvsp[-1].ftval); }
#line 1679 "bumo.tab.c"
    break;

  case 68:
#line 168 "bumo.y"
                {(yyval.ftval) = (yyvsp[0].ftval);}
#line 1685 "bumo.tab.c"
    break;

  case 69:
#line 171 "bumo.y"
                                      {  (yyval.bval) = (yyvsp[-2].bval) && (yyvsp[0].bval);}
#line 1691 "bumo.tab.c"
    break;

  case 70:
#line 172 "bumo.y"
                             {(yyval.bval) = (yyvsp[-2].bval) || (yyvsp[0].bval);}
#line 1697 "bumo.tab.c"
    break;

  case 71:
#line 173 "bumo.y"
                    {(yyval.bval) = !(yyvsp[0].bval);}
#line 1703 "bumo.tab.c"
    break;

  case 72:
#line 174 "bumo.y"
                       {(yyval.bval) = (yyvsp[-1].bval); }
#line 1709 "bumo.tab.c"
    break;

  case 73:
#line 175 "bumo.y"
                {(yyval.bval) = toBool((yyvsp[0].str)); }
#line 1715 "bumo.tab.c"
    break;

  case 74:
#line 176 "bumo.y"
                {(yyval.bval) = toBool((yyvsp[0].str));}
#line 1721 "bumo.tab.c"
    break;

  case 75:
#line 180 "bumo.y"
                           {(yyval.bval) = ((yyvsp[-2].bval) == (yyvsp[0].bval));}
#line 1727 "bumo.tab.c"
    break;

  case 76:
#line 181 "bumo.y"
                             {(yyval.bval) = ((yyvsp[-2].bval) != (yyvsp[0].bval));}
#line 1733 "bumo.tab.c"
    break;

  case 77:
#line 182 "bumo.y"
                           {(yyval.bval) = ((yyvsp[-2].intval) == (yyvsp[0].intval));}
#line 1739 "bumo.tab.c"
    break;

  case 78:
#line 183 "bumo.y"
                           {(yyval.bval) = ((yyvsp[-2].intval) != (yyvsp[0].intval));}
#line 1745 "bumo.tab.c"
    break;

  case 79:
#line 184 "bumo.y"
                           {(yyval.bval) = ((yyvsp[-2].intval) <= (yyvsp[0].intval));}
#line 1751 "bumo.tab.c"
    break;

  case 80:
#line 185 "bumo.y"
                           {(yyval.bval) = ((yyvsp[-2].intval) >= (yyvsp[0].intval));}
#line 1757 "bumo.tab.c"
    break;

  case 81:
#line 186 "bumo.y"
                           {(yyval.bval) = ((yyvsp[-2].intval) > (yyvsp[0].intval));}
#line 1763 "bumo.tab.c"
    break;

  case 82:
#line 187 "bumo.y"
                           {(yyval.bval) = ((yyvsp[-2].intval) > (yyvsp[0].intval));}
#line 1769 "bumo.tab.c"
    break;

  case 83:
#line 191 "bumo.y"
                                             {  (yyval.bval) = (yyvsp[-2].bval) && (yyvsp[0].bval);}
#line 1775 "bumo.tab.c"
    break;

  case 84:
#line 192 "bumo.y"
                                               {(yyval.bval) = (yyvsp[-2].bval) || (yyvsp[0].bval);}
#line 1781 "bumo.tab.c"
    break;

  case 85:
#line 193 "bumo.y"
                              {(yyval.bval) = !(yyvsp[0].bval);}
#line 1787 "bumo.tab.c"
    break;

  case 86:
#line 194 "bumo.y"
                                 {(yyval.bval) = (yyvsp[-1].bval); }
#line 1793 "bumo.tab.c"
    break;

  case 87:
#line 195 "bumo.y"
                    {(yyval.bval) = (yyvsp[0].bval); }
#line 1799 "bumo.tab.c"
    break;


#line 1803 "bumo.tab.c"

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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
                      yytoken, &yylval);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
  return yyresult;
}
#line 198 "bumo.y"

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

int main(int argc, char** argv){
     yyin=fopen(argv[1],"r");
     yyparse();    
} 
