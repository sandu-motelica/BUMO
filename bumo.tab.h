/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
    SUB = 265,
    DIV = 266,
    MUL = 267,
    AND = 268,
    NOT = 269,
    OR = 270,
    IF = 271,
    ELSE = 272,
    THEN = 273,
    EQ = 274,
    NQ = 275,
    GT = 276,
    LT = 277,
    LE = 278,
    GE = 279,
    FOR = 280,
    WHILE = 281,
    EVAL = 282,
    TYPEOF = 283,
    RETURN = 284,
    CLASS = 285,
    TYPES = 286,
    VAR = 287,
    FUNCT = 288,
    IDENTIFIER = 289,
    TYPE = 290,
    STRING_VALUE = 291,
    CHAR_VALUE = 292,
    BOOL_VALUE = 293,
    INT_VALUE = 294,
    REAL_VALUE = 295,
    MOD = 296,
    UMINUS = 297
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 36 "bumo.y"

    char* str;
    int intval;
    float ftval;
    bool bval;

#line 107 "bumo.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BUMO_TAB_H_INCLUDED  */
