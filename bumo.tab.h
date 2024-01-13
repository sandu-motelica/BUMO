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
     MET = 289,
     CONSTRUCTOR = 290,
     NEW = 291,
     IDENTIFIER = 292,
     TYPE = 293,
     STRING_VALUE = 294,
     CHAR_VALUE = 295,
     BOOL_VALUE = 296,
     INT_VALUE = 297,
     REAL_VALUE = 298,
     MOD = 299,
     UMINUS = 300
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
#define SUB 265
#define DIV 266
#define MUL 267
#define AND 268
#define NOT 269
#define OR 270
#define IF 271
#define ELSE 272
#define THEN 273
#define EQ 274
#define NQ 275
#define GT 276
#define LT 277
#define LE 278
#define GE 279
#define FOR 280
#define WHILE 281
#define EVAL 282
#define TYPEOF 283
#define RETURN 284
#define CLASS 285
#define TYPES 286
#define VAR 287
#define FUNCT 288
#define MET 289
#define CONSTRUCTOR 290
#define NEW 291
#define IDENTIFIER 292
#define TYPE 293
#define STRING_VALUE 294
#define CHAR_VALUE 295
#define BOOL_VALUE 296
#define INT_VALUE 297
#define REAL_VALUE 298
#define MOD 299
#define UMINUS 300




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 37 "bumo.y"
{
    char* str;
    int intval;
    float ftval;
    bool bval;
}
/* Line 1529 of yacc.c.  */
#line 146 "bumo.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

