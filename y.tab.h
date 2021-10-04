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
    DOT = 258,
    LINE = 259,
    FALSE = 260,
    NONE = 261,
    TRUE = 262,
    LAND = 263,
    BREAK = 264,
    CONTINUE = 265,
    ELIF = 266,
    DEL = 267,
    ELSE = 268,
    FOR = 269,
    IF = 270,
    IN = 271,
    NOT = 272,
    LOR = 273,
    INPUT = 274,
    PRINT = 275,
    INT = 276,
    FLOAT = 277,
    STR = 278,
    LIST = 279,
    SPLIT = 280,
    MAP = 281,
    APPEND = 282,
    POP = 283,
    INSERT = 284,
    LEN = 285,
    ID = 286,
    CINT = 287,
    CFLOAT = 288,
    SEMI = 289,
    COMMA = 290,
    CSTR = 291,
    EPOP = 292,
    MUL = 293,
    DIV = 294,
    FDIV = 295,
    MOD = 296,
    ADD = 297,
    SUB = 298,
    ASOP = 299,
    G = 300,
    L = 301,
    GE = 302,
    LE = 303,
    EOP = 304,
    NEOP = 305,
    XOR = 306,
    BAND = 307,
    BOR = 308,
    LPAREN = 309,
    RPAREN = 310,
    LBRACKET = 311,
    RBRACKET = 312,
    RANGE = 313,
    COLON = 314
  };
#endif
/* Tokens.  */
#define DOT 258
#define LINE 259
#define FALSE 260
#define NONE 261
#define TRUE 262
#define LAND 263
#define BREAK 264
#define CONTINUE 265
#define ELIF 266
#define DEL 267
#define ELSE 268
#define FOR 269
#define IF 270
#define IN 271
#define NOT 272
#define LOR 273
#define INPUT 274
#define PRINT 275
#define INT 276
#define FLOAT 277
#define STR 278
#define LIST 279
#define SPLIT 280
#define MAP 281
#define APPEND 282
#define POP 283
#define INSERT 284
#define LEN 285
#define ID 286
#define CINT 287
#define CFLOAT 288
#define SEMI 289
#define COMMA 290
#define CSTR 291
#define EPOP 292
#define MUL 293
#define DIV 294
#define FDIV 295
#define MOD 296
#define ADD 297
#define SUB 298
#define ASOP 299
#define G 300
#define L 301
#define GE 302
#define LE 303
#define EOP 304
#define NEOP 305
#define XOR 306
#define BAND 307
#define BOR 308
#define LPAREN 309
#define RPAREN 310
#define LBRACKET 311
#define RBRACKET 312
#define RANGE 313
#define COLON 314

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 109 "python.y"
 struct{char value[1024]; int type;struct Node *node;char lhs[1024]  ;char code[1024];char begin[1024]; char end[1024];}ctype; char val[1024]; 

#line 178 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
