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
     DIV = 287,
     MUL = 288
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
#define FOR 277
#define WHILE 278
#define IDENTIFIER 279
#define TYPE 280
#define STRING_VALUE 281
#define CHAR_VALUE 282
#define BOOL_VALUE 283
#define INT_VALUE 284
#define REAL_VALUE 285
#define SUB 286
#define DIV 287
#define MUL 288




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 23 "bumo.y"
{
    char* str;
    int intval;
    float ftval;
    bool bval;
}
/* Line 1529 of yacc.c.  */
#line 122 "bumo.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

