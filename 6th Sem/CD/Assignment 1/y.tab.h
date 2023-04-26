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
    HEADER = 258,
    MAIN = 259,
    IF = 260,
    ELSE = 261,
    WHILE = 262,
    FOR = 263,
    ASSGN = 264,
    ID = 265,
    NUM = 266,
    PLUS = 267,
    DOT = 268,
    MINUS = 269,
    STAR = 270,
    DIVIDE = 271,
    SEMICOLON = 272,
    LEFT_PAREN = 273,
    BANG = 274,
    RIGHT_PAREN = 275,
    AND_AND = 276,
    PLUS_PLUS = 277,
    TRUE = 278,
    FALSE = 279,
    MINUS_MINUS = 280,
    OR_OR = 281,
    LEFT_BRACE = 282,
    RIGHT_BRACE = 283,
    COMMA = 284,
    INT = 285,
    FLOAT = 286,
    DOUBLE = 287,
    CHAR = 288,
    GREATER = 289,
    LESSER = 290,
    EQCOMP = 291,
    NOTEQ = 292,
    GREATEREQ = 293,
    LESSEREQ = 294,
    LEFT_SQ = 295,
    RIGHT_SQ = 296
  };
#endif
/* Tokens.  */
#define HEADER 258
#define MAIN 259
#define IF 260
#define ELSE 261
#define WHILE 262
#define FOR 263
#define ASSGN 264
#define ID 265
#define NUM 266
#define PLUS 267
#define DOT 268
#define MINUS 269
#define STAR 270
#define DIVIDE 271
#define SEMICOLON 272
#define LEFT_PAREN 273
#define BANG 274
#define RIGHT_PAREN 275
#define AND_AND 276
#define PLUS_PLUS 277
#define TRUE 278
#define FALSE 279
#define MINUS_MINUS 280
#define OR_OR 281
#define LEFT_BRACE 282
#define RIGHT_BRACE 283
#define COMMA 284
#define INT 285
#define FLOAT 286
#define DOUBLE 287
#define CHAR 288
#define GREATER 289
#define LESSER 290
#define EQCOMP 291
#define NOTEQ 292
#define GREATEREQ 293
#define LESSEREQ 294
#define LEFT_SQ 295
#define RIGHT_SQ 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
