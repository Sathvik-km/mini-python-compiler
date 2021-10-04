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
#line 1 "python.y"
 
#include<stdio.h> 
#include<stdlib.h> 
#include "y.tab.h"
#include<string.h>

char temp_var[100];
int m = 0;        //string length for temp_var
int unop =0;
int paramno=0;
char final_out[1024];
void first_val(char *first, char *temp)
{
    int i=0;int n=strlen(first);
    while(i<n && first[i]!=',')
    {
      temp[i]=first[i];i++;
    }
}

void expand(char *str, char *temp)
{

  char *pt;int a=0,b=0,c=0,i=0; char buffer[1024]="";
  pt = strtok(str,",");
  if(pt==NULL)
  {
    if(strlen(str)==0)
    {
    strcat(temp,"");
    return;
    }
  }
  a=atoi(pt);
  pt = strtok(NULL,",");
  if(pt==NULL)
  {
    i=0;
    while(i<a-1)
    {
      sprintf(buffer,"%d",i);
      strcat(temp,buffer);strcat(temp,",");
      i++;
    }
    sprintf(buffer,"%d",i);
    strcat(temp,buffer);
    return;
  }
  b=atoi(pt);
  pt = strtok (NULL,",");
  if(pt==NULL)
  {
    i=a;
    while(i<b-1)
    {
      sprintf(buffer,"%d",i);
      strcat(temp,buffer);strcat(temp,",");
      i++;
    }
    sprintf(buffer,"%d",i);
    strcat(temp,buffer);
    return;
  }  
  c=atoi(pt);
  i=a;
  if(c>0)
  {
  while(i<b-c)
  {
    sprintf(buffer,"%d",i);
    strcat(temp,buffer);strcat(temp,",");
    i+=c;
  }
  sprintf(buffer,"%d",i);
  strcat(temp,buffer);
  return;
  }
  else 
  {

    while(i>b-c)
    {
      sprintf(buffer,"%d",i);
      strcat(temp,buffer);strcat(temp,",");
      i+=c;
    }
    sprintf(buffer,"%d",i);
    strcat(temp,buffer);
    return; 
  }

}

void len(char *val,char *temp)
{
  int t=strlen(val);
  t=t-t/2;
  sprintf(temp,"%d",t);
}

int tempno = 0, ln = 0; //temp variable no, label no
int exprno = -1; //expr no


#line 175 "y.tab.c"

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

#line 345 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





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
#define YYFINAL  66
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   174

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  142

#define YYUNDEFTOK  2
#define YYMAXUTOK   314


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   114,   114,   121,   127,   132,   136,   140,   145,   152,
     156,   161,   166,   170,   175,   180,   184,   189,   199,   208,
     207,   223,   234,   240,   239,   252,   276,   279,   289,   295,
     301,   308,   315,   322,   329,   336,   343,   359,   367,   371,
     378,   383,   391,   397,   403,   410,   435,   461,   489,   497,
     503,   518,   523,   539,   552,   567,   582,   588,   601,   616,
     622,   635,   644,   654,   661,   675,   691,   705,   720,   726,
     742,   758,   763,   767,   772,   784,   790
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DOT", "LINE", "FALSE", "NONE", "TRUE",
  "LAND", "BREAK", "CONTINUE", "ELIF", "DEL", "ELSE", "FOR", "IF", "IN",
  "NOT", "LOR", "INPUT", "PRINT", "INT", "FLOAT", "STR", "LIST", "SPLIT",
  "MAP", "APPEND", "POP", "INSERT", "LEN", "ID", "CINT", "CFLOAT", "SEMI",
  "COMMA", "CSTR", "EPOP", "MUL", "DIV", "FDIV", "MOD", "ADD", "SUB",
  "ASOP", "G", "L", "GE", "LE", "EOP", "NEOP", "XOR", "BAND", "BOR",
  "LPAREN", "RPAREN", "LBRACKET", "RBRACKET", "RANGE", "COLON", "$accept",
  "Start", "Translation_unit", "Stmt", "Assignment_stmt", "Simple_stmt",
  "Compound_stmt", "Jump_stmt", "Print_stmt", "Param_list", "If_stmt",
  "$@1", "Elif_stmt", "Else_stmt", "$@2", "For_stmt", "Iterable",
  "Expression_stmt", "Exp", "Const", "Primary_Exp", "Unary_Exp", "Pow_Exp",
  "Mul_Exp", "Add_Exp", "Bit_Exp", "Rel_Exp", "Eq_Exp", "In_Exp",
  "And_Exp", "Or_Exp", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
};
# endif

#define YYPACT_NINF (-57)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       3,   -57,   -57,   -57,   -57,   -57,   -28,    62,   116,   -43,
     -38,    -3,    20,    26,    28,    -2,   -57,   -57,   -57,   116,
     116,    62,    62,    37,    96,   -57,     3,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
      65,    15,   -36,    13,    25,   -12,    54,    91,   -57,    94,
     -57,    53,   -57,    58,    62,    62,    62,    62,    41,    62,
     -57,   -57,    60,   -30,   -57,    62,   -57,   -57,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    41,     3,   -57,
     -14,    64,    70,    71,    72,   -57,   -57,    62,   -57,     5,
     -57,    65,    65,    65,    65,    15,    15,   -36,   -36,   -36,
      13,    13,    13,    13,   -57,    25,    25,   -57,   -57,    69,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,     3,   106,
     -57,    62,   117,    73,    74,   -57,     3,   -57,   106,     3,
     -57,   -57
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    34,    35,    33,    14,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    37,    30,    31,    32,     0,
       0,     0,     0,     0,     0,     2,     4,     7,     5,     6,
      11,    10,    12,    13,    40,     9,    28,    38,    48,    49,
      51,    56,    59,    63,    68,    71,    73,    75,    29,     0,
      37,     0,    47,     0,     0,     0,     0,     0,     0,     0,
      46,    45,     0,     0,    18,     0,     1,     3,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    36,
       0,     0,     0,     0,     0,     8,    39,     0,    26,     0,
      50,    52,    53,    54,    55,    57,    58,    60,    61,    62,
      64,    66,    65,    67,    72,    69,    70,    74,    76,     0,
      19,    16,    42,    43,    44,    41,    17,    27,     0,    22,
      25,     0,     0,     0,     0,    20,     0,    23,    22,     0,
      21,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -57,   -57,   -25,   -57,   -57,   -57,   -57,   -57,   -57,   -35,
     -57,   -57,    -9,   -57,   -57,   -57,   -56,   -57,    -7,   -57,
      24,    63,     6,   -45,    31,     8,    17,   -57,    52,    51,
      55
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    24,    25,    26,    27,    28,    29,    30,    31,    63,
      32,   129,   132,   135,   139,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      51,    67,    94,    49,    82,    97,    73,    74,     1,     2,
       3,    53,     4,     5,    62,    64,    54,     6,     7,    90,
       8,    97,     9,    10,    11,    12,    13,    98,   105,   106,
      99,   119,    52,    14,    15,    16,    17,    83,    84,    18,
      97,   121,    59,    60,    61,    19,    20,    64,    91,    92,
      93,    55,    95,    69,    70,    71,    72,    21,    64,    22,
     127,    23,    85,   120,    75,    76,    77,     1,     2,     3,
      78,    79,    80,    81,    56,   101,   102,   103,   104,     8,
      57,     9,    58,    11,    12,    13,   110,   111,   112,   113,
     126,    65,    14,    50,    16,    17,    66,    22,    18,    23,
     115,   116,    68,   130,    19,    20,   107,   108,   109,    86,
      87,   138,    88,    89,   141,    96,    21,   131,    22,   122,
      23,     1,     2,     3,   133,   123,   124,   125,   128,   140,
     134,   100,   136,   137,   114,     9,   117,    11,    12,    13,
       0,   118,     0,     0,     0,     0,    14,    50,    16,    17,
       0,     0,    18,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,     0,    22,     0,    23
};

static const yytype_int16 yycheck[] =
{
       7,    26,    58,    31,    16,    35,    42,    43,     5,     6,
       7,    54,     9,    10,    21,    22,    54,    14,    15,    54,
      17,    35,    19,    20,    21,    22,    23,    57,    73,    74,
      65,    87,     8,    30,    31,    32,    33,    49,    50,    36,
      35,    55,    44,    19,    20,    42,    43,    54,    55,    56,
      57,    54,    59,    38,    39,    40,    41,    54,    65,    56,
      55,    58,     8,    88,    51,    52,    53,     5,     6,     7,
      45,    46,    47,    48,    54,    69,    70,    71,    72,    17,
      54,    19,    54,    21,    22,    23,    78,    79,    80,    81,
      97,    54,    30,    31,    32,    33,     0,    56,    36,    58,
      83,    84,    37,   128,    42,    43,    75,    76,    77,    18,
      16,   136,    59,    55,   139,    55,    54,    11,    56,    55,
      58,     5,     6,     7,   131,    55,    55,    55,    59,   138,
      13,    68,    59,    59,    82,    19,    85,    21,    22,    23,
      -1,    86,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    -1,    56,    -1,    58
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     6,     7,     9,    10,    14,    15,    17,    19,
      20,    21,    22,    23,    30,    31,    32,    33,    36,    42,
      43,    54,    56,    58,    61,    62,    63,    64,    65,    66,
      67,    68,    70,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    31,
      31,    78,    80,    54,    54,    54,    54,    54,    54,    44,
      80,    80,    78,    69,    78,    54,     0,    62,    37,    38,
      39,    40,    41,    42,    43,    51,    52,    53,    45,    46,
      47,    48,    16,    49,    50,     8,    18,    16,    59,    55,
      69,    78,    78,    78,    76,    78,    55,    35,    57,    69,
      81,    82,    82,    82,    82,    83,    83,    84,    84,    84,
      85,    85,    85,    85,    88,    86,    86,    89,    90,    76,
      62,    55,    55,    55,    55,    55,    78,    55,    59,    71,
      62,    11,    72,    78,    13,    73,    59,    59,    62,    74,
      72,    62
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    62,    62,    63,    63,    63,    64,    65,
      65,    65,    66,    66,    67,    67,    68,    69,    69,    71,
      70,    72,    72,    74,    73,    75,    76,    76,    77,    78,
      79,    79,    79,    79,    79,    79,    79,    80,    80,    80,
      80,    80,    80,    80,    80,    81,    81,    81,    81,    82,
      82,    83,    83,    83,    83,    83,    84,    84,    84,    85,
      85,    85,    85,    86,    86,    86,    86,    86,    87,    87,
      87,    88,    88,    89,    89,    90,    90
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     4,     3,     1,     0,
       7,     5,     0,     0,     4,     6,     3,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     3,
       1,     4,     4,     4,     4,     2,     2,     2,     1,     1,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     1,     3,     1,     3
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
#line 115 "python.y"
{
  //printf("Here's the start statement!\n");
  printf("%s",(yyvsp[0].ctype).code);
  //printf("End of start statement!\n");
}
#line 1636 "y.tab.c"
    break;

  case 3:
#line 122 "python.y"
{
  //printf("Here's the translation unit!\n");
  sprintf((yyval.ctype).code,"%s\n%s",(yyvsp[-1].ctype).code,(yyvsp[0].ctype).code); //sprintf: joining multiple parameters and storing the resultant string in one variable($$.code)
  //printf("End of translation unit!\n");
}
#line 1646 "y.tab.c"
    break;

  case 4:
#line 128 "python.y"
{
  strcpy((yyval.ctype).code,(yyvsp[0].ctype).code);
}
#line 1654 "y.tab.c"
    break;

  case 5:
#line 133 "python.y"
{
  strcpy((yyval.ctype).code,(yyvsp[0].ctype).code);
}
#line 1662 "y.tab.c"
    break;

  case 6:
#line 137 "python.y"
{
  strcpy((yyval.ctype).code,(yyvsp[0].ctype).code);
}
#line 1670 "y.tab.c"
    break;

  case 7:
#line 141 "python.y"
{
  strcpy((yyval.ctype).code,(yyvsp[0].ctype).code);
}
#line 1678 "y.tab.c"
    break;

  case 8:
#line 146 "python.y"
{
  char buff[3]="";
  sprintf(buff,"%d",(yyvsp[0].ctype).type); 
  insert("ID",(yyvsp[-2].ctype).value,buff,(yyvsp[0].ctype).value,-1); //inserting var entry to sym table
  sprintf((yyval.ctype).code,"\n=\t%s\t\t%s\n",(yyvsp[0].ctype).lhs,(yyvsp[-2].ctype).value);
}
#line 1689 "y.tab.c"
    break;

  case 9:
#line 153 "python.y"
{
  strcpy((yyval.ctype).code,(yyvsp[0].ctype).code);
}
#line 1697 "y.tab.c"
    break;

  case 10:
#line 157 "python.y"
{
  paramno=0;
  strcpy((yyval.ctype).code,(yyvsp[0].ctype).code);
}
#line 1706 "y.tab.c"
    break;

  case 11:
#line 162 "python.y"
{
  strcpy((yyval.ctype).code,(yyvsp[0].ctype).code);
}
#line 1714 "y.tab.c"
    break;

  case 12:
#line 167 "python.y"
{
  strcpy((yyval.ctype).code,(yyvsp[0].ctype).code);
}
#line 1722 "y.tab.c"
    break;

  case 13:
#line 171 "python.y"
{
  strcpy((yyval.ctype).code,(yyvsp[0].ctype).code);
}
#line 1730 "y.tab.c"
    break;

  case 14:
#line 176 "python.y"
{
  sprintf((yyval.ctype).code,"goto\t \t \tL%d",ln);

}
#line 1739 "y.tab.c"
    break;

  case 15:
#line 181 "python.y"
{
}
#line 1746 "y.tab.c"
    break;

  case 16:
#line 185 "python.y"
{
  sprintf((yyval.ctype).code,"%s\ncall\t \tprint\t%d\n",(yyvsp[-1].ctype).code,++paramno);
}
#line 1754 "y.tab.c"
    break;

  case 17:
#line 190 "python.y"
{
  //printf("reading range parameters\n");
  (yyval.ctype).type=50+(yyvsp[0].ctype).type;strcat((yyval.ctype).value,",");
  strcat((yyval.ctype).value,(yyvsp[0].ctype).value);
  sprintf((yyval.ctype).lhs,(yyvsp[-2].ctype).lhs);
  sprintf((yyval.ctype).code,"%s\n\t%s\nparam\t \t \t%s\n",(yyvsp[-2].ctype).code,(yyvsp[0].ctype).code,(yyvsp[0].ctype).lhs);
  paramno++;

}
#line 1768 "y.tab.c"
    break;

  case 18:
#line 200 "python.y"
{  
  sprintf((yyval.ctype).lhs,"%s",(yyvsp[0].ctype).lhs);
  sprintf((yyval.ctype).code,"%sParam\t\t\t%s\n",(yyvsp[0].ctype).code,(yyvsp[0].ctype).lhs);
  printf("%s", (yyvsp[0].ctype).code);
  //paramno++;
}
#line 1779 "y.tab.c"
    break;

  case 19:
#line 208 "python.y"
{
  //printf("Value of ln: %d",ln);
  char s[1024]="";
  sprintf(s, "L%d", ln);
  insert("Label",s,NULL,NULL,-1);
  printf("%s\n", (yyvsp[-2].ctype).code);
  printf("IfFalse\t t%d goto \t%s\n",tempno-1, s );
  printf("%s\n", (yyvsp[0].ctype).code);
  printf("Label %s\n", s);
  ln++;
}
#line 1795 "y.tab.c"
    break;

  case 20:
#line 219 "python.y"
{
	printf("%s\n", (yyvsp[0].ctype).code);
}
#line 1803 "y.tab.c"
    break;

  case 21:
#line 224 "python.y"
{
  char s[1024]="";
  sprintf(s, "L%d", ln);
  insert("Label",s,NULL,NULL,-1);
  printf("%s\n", (yyvsp[-3].ctype).code);
  printf("IfFalse \tt%d goto \t%s\n",tempno-1, s );
  printf("%s\n", (yyvsp[-1].ctype).code);
  printf("Label %s\n", s);
  ln++;
}
#line 1818 "y.tab.c"
    break;

  case 22:
#line 234 "python.y"
  {
  sprintf((yyval.ctype).begin,"L%d",ln);
  sprintf((yyval.ctype).end,"L%d",ln);
  }
#line 1827 "y.tab.c"
    break;

  case 23:
#line 240 "python.y"
{
  char s[1024]="";
  sprintf(s, "L%d", ln);
  //ln++;
  
  
}
#line 1839 "y.tab.c"
    break;

  case 24:
#line 247 "python.y"
{
	printf("%s\n", (yyvsp[0].ctype).code);
}
#line 1847 "y.tab.c"
    break;

  case 25:
#line 253 "python.y"
{
  char s[1024]="";
  char s1[1024]="";
  sprintf(s, "L%d", ln);
  sprintf(s1, "L%d", ln+1);
  insert("Label",s,NULL,NULL,-1);
  insert("for_out_Label",s1,NULL,NULL,-1);
  char temp[1024]="";
  first_val((yyvsp[-2].ctype).value,temp);
  char buff[3]="";
  sprintf(buff,"%d",(yyvsp[-2].ctype).type%10);
  insert("ID",(yyvsp[-4].ctype).value,buff,temp,-1);
  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s2[1024]="";
  sprintf(s2, "t%d", tempno-1);
  insert("Temp",s2,NULL,NULL,-1);
  sprintf((yyval.ctype).code,"%s",(yyvsp[-2].ctype).code);
  sprintf((yyval.ctype).code,"\n%sin\t%s\t%s\t%s\nIfFalse\t%s\tgoto\t%s\n\t\t\t\nLabel\t\t \t%s\n%s\ngoto\t\t\t%s\nLabel\t\t\tL%d",(yyvsp[-2].ctype).code, (yyvsp[-4].ctype).value,"RANGE", s2,s2,  s1 , s, (yyvsp[0].ctype).code,s, ln+1);
  ln+=2;
}
#line 1874 "y.tab.c"
    break;

  case 26:
#line 277 "python.y"
{
}
#line 1881 "y.tab.c"
    break;

  case 27:
#line 280 "python.y"
{
  (yyval.ctype).type=51;
  char temp[1024]="";
  char s1[1024]="";
  expand((yyvsp[-1].ctype).value,temp);
  strcpy((yyval.ctype).value,temp);
  sprintf((yyval.ctype).code,"%s",(yyvsp[-1].ctype).code);
}
#line 1894 "y.tab.c"
    break;

  case 28:
#line 290 "python.y"
{
  strcpy((yyval.ctype).code,(yyvsp[0].ctype).code);
  strcpy((yyval.ctype).lhs,(yyvsp[0].ctype).lhs);
}
#line 1903 "y.tab.c"
    break;

  case 29:
#line 296 "python.y"
{
  strcpy((yyval.ctype).code,(yyvsp[0].ctype).code);
  strcpy((yyval.ctype).lhs,(yyvsp[0].ctype).lhs);
}
#line 1912 "y.tab.c"
    break;

  case 30:
#line 302 "python.y"
{
  (yyval.ctype).type=1;
  strcpy((yyval.ctype).value,(yyvsp[0].val));
  sprintf((yyval.ctype).lhs,"%s",(yyvsp[0].val));
  exprno=0;
}
#line 1923 "y.tab.c"
    break;

  case 31:
#line 309 "python.y"
{
  (yyval.ctype).type=2;
  strcpy((yyval.ctype).value,(yyvsp[0].val));
  sprintf((yyval.ctype).lhs,"%s",(yyvsp[0].val));
  exprno=0;
}
#line 1934 "y.tab.c"
    break;

  case 32:
#line 316 "python.y"
{
  (yyval.ctype).type=3;
  strcpy((yyval.ctype).value,(yyvsp[0].val));
  sprintf((yyval.ctype).lhs,"%s",(yyvsp[0].val));
  exprno=0;
}
#line 1945 "y.tab.c"
    break;

  case 33:
#line 323 "python.y"
{
  (yyval.ctype).type=4;
  strcpy((yyval.ctype).value,(yyvsp[0].val));
  sprintf((yyval.ctype).lhs,"%s",(yyvsp[0].val));
  exprno=0;
}
#line 1956 "y.tab.c"
    break;

  case 34:
#line 330 "python.y"
{
  (yyval.ctype).type=4;
  strcpy((yyval.ctype).value,(yyvsp[0].val));
  sprintf((yyval.ctype).lhs,"%s",(yyvsp[0].val));
  exprno=0;
}
#line 1967 "y.tab.c"
    break;

  case 35:
#line 337 "python.y"
{
  (yyval.ctype).type=5;
  strcpy((yyval.ctype).value,(yyvsp[0].val));
  sprintf((yyval.ctype).lhs,"%s",(yyvsp[0].val));
  exprno=0;
}
#line 1978 "y.tab.c"
    break;

  case 36:
#line 344 "python.y"
{
  (yyval.ctype).type=3;
  strcpy((yyval.ctype).value,"");
  
  
  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);
  printf("call\t%s\tinput\t0\n",temp_var);
  sprintf((yyval.ctype).lhs,"%s",temp_var);
}
#line 1997 "y.tab.c"
    break;

  case 37:
#line 360 "python.y"
{
 
  (yyval.ctype)=(yyvsp[0].ctype); 
  
  sprintf((yyval.ctype).lhs,"%s",(yyvsp[0].ctype).value);
  exprno=0;
}
#line 2009 "y.tab.c"
    break;

  case 38:
#line 368 "python.y"
{
  (yyval.ctype)=(yyvsp[0].ctype);  
}
#line 2017 "y.tab.c"
    break;

  case 39:
#line 372 "python.y"
{
  (yyval.ctype)=(yyvsp[-1].ctype);
  strcpy((yyval.ctype).code,(yyvsp[-1].ctype).code);
  sprintf((yyval.ctype).lhs,"%s",temp_var);
  exprno=1;
}
#line 2028 "y.tab.c"
    break;

  case 40:
#line 379 "python.y"
{
  (yyval.ctype)=(yyvsp[0].ctype);
  
}
#line 2037 "y.tab.c"
    break;

  case 41:
#line 384 "python.y"
{
  (yyval.ctype).type=1;
  char buffer[10]="";
  len((yyvsp[-1].ctype).value,buffer) ;
  strcpy((yyval.ctype).value,buffer);
  
}
#line 2049 "y.tab.c"
    break;

  case 42:
#line 392 "python.y"
{
  (yyval.ctype).type=1;
  strcpy((yyval.ctype).value,(yyvsp[-1].ctype).value);
  
}
#line 2059 "y.tab.c"
    break;

  case 43:
#line 398 "python.y"
{
  (yyval.ctype).type=2;
  strcpy((yyval.ctype).value,(yyvsp[-1].ctype).value);
  
}
#line 2069 "y.tab.c"
    break;

  case 44:
#line 404 "python.y"
{
  (yyval.ctype).type=3;
  strcpy((yyval.ctype).value,(yyvsp[-1].ctype).value);
  
}
#line 2079 "y.tab.c"
    break;

  case 45:
#line 411 "python.y"
{
  (yyval.ctype).type=(yyvsp[0].ctype).type;
  char buffer[1024]="-";
  strcat(buffer,(yyvsp[0].ctype).value);
  strcpy((yyval.ctype).value,buffer);
  

  tempno++;
  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);
  sprintf((yyval.ctype).lhs,temp_var);

  printf("Uminus\t%s\t \t%s\n",(yyvsp[0].ctype).lhs,(yyval.ctype).lhs);
  sprintf((yyval.ctype).code,"Uminus\t%s\t \t%s\n",(yyvsp[0].ctype).lhs,(yyval.ctype).lhs);

  strcpy((yyval.ctype).lhs,(yyvsp[0].ctype).lhs);

  exprno=2;
  unop=1;
}
#line 2108 "y.tab.c"
    break;

  case 46:
#line 436 "python.y"
{

  strcpy((yyval.ctype).code,(yyvsp[0].ctype).lhs);


  exprno=2;
  unop=0;


  tempno++;
  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);
  sprintf((yyval.ctype).lhs,temp_var);
  sprintf((yyval.ctype).code,"%s = %s ",(yyval.ctype).lhs,(yyvsp[0].ctype).lhs);

  printf("Uplus\t%s\t \t%s\n",(yyvsp[0].ctype).lhs,(yyval.ctype).lhs);

  
  exprno=2;

}
#line 2138 "y.tab.c"
    break;

  case 47:
#line 462 "python.y"
{
  (yyval.ctype).type=(yyvsp[0].ctype).type;
  char buffer[1024]="-";
  strcat(buffer,(yyvsp[0].ctype).value);
  strcpy((yyval.ctype).value,buffer);
  
  

  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);
  strcpy((yyval.ctype).lhs,temp_var);
  sprintf((yyval.ctype).code,"%s = not %s ",temp_var,(yyvsp[0].ctype).lhs);

  printf("not\t%s\t\t%s\n",(yyvsp[0].ctype).lhs,(yyval.ctype).lhs);


  strcpy((yyval.ctype).code,(yyvsp[0].ctype).lhs);


  exprno=2;
  unop=2;

}
#line 2170 "y.tab.c"
    break;

  case 48:
#line 490 "python.y"
{
  

  strcpy((yyval.ctype).code,(yyvsp[0].ctype).code);
  strcpy((yyval.ctype).lhs,(yyvsp[0].ctype).lhs);
}
#line 2181 "y.tab.c"
    break;

  case 49:
#line 498 "python.y"
{
  
  strcpy((yyval.ctype).code,(yyvsp[0].ctype).code);

  }
#line 2191 "y.tab.c"
    break;

  case 50:
#line 504 "python.y"
{
  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);
  sprintf((yyval.ctype).lhs,temp_var);
  sprintf((yyval.ctype).code,"%s\n%s\n**\t%s\t%s\t%s\n",(yyvsp[-2].ctype).code,(yyvsp[0].ctype).code,(yyvsp[-2].ctype).lhs,(yyvsp[0].ctype).lhs,temp_var);


  exprno=1;
}
#line 2209 "y.tab.c"
    break;

  case 51:
#line 519 "python.y"
{
  strcpy((yyval.ctype).code,(yyvsp[0].ctype).code);
  strcpy((yyval.ctype).lhs,(yyvsp[0].ctype).lhs);
}
#line 2218 "y.tab.c"
    break;

  case 52:
#line 524 "python.y"
{
  

  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);
  sprintf((yyval.ctype).lhs,temp_var);
  sprintf((yyval.ctype).code,"%s\n%s\n*\t%s\t%s\t%s\n",(yyvsp[-2].ctype).code,(yyvsp[0].ctype).code,(yyvsp[-2].ctype).lhs,(yyvsp[0].ctype).lhs,temp_var);

  exprno=1;

}
#line 2238 "y.tab.c"
    break;

  case 53:
#line 540 "python.y"
{
  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);
  sprintf((yyval.ctype).lhs,temp_var);
  sprintf((yyval.ctype).code,"%s\n%s\n/\t%s\t%s\t%s\n",(yyvsp[-2].ctype).code,(yyvsp[0].ctype).code,(yyvsp[-2].ctype).lhs,(yyvsp[0].ctype).lhs,temp_var);
  printf("/\t%s\t%s\t%s\n",(yyvsp[-2].ctype).lhs,(yyvsp[0].ctype).code,temp_var);
  exprno=1;
}
#line 2255 "y.tab.c"
    break;

  case 54:
#line 553 "python.y"
{
  

  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);
  strcpy((yyval.ctype).lhs,temp_var);
  sprintf((yyval.ctype).code,"%s\n%s\n//\t%s\t%s\t%s\n",(yyvsp[-2].ctype).code,(yyvsp[0].ctype).code,(yyvsp[-2].ctype).lhs,(yyvsp[0].ctype).lhs,temp_var);


}
#line 2274 "y.tab.c"
    break;

  case 55:
#line 568 "python.y"
{
  

  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);
  strcpy((yyval.ctype).lhs,temp_var);
  sprintf((yyval.ctype).code,"%s = %s % %s",temp_var,(yyvsp[-2].ctype).lhs,(yyvsp[0].ctype).code);

}
#line 2292 "y.tab.c"
    break;

  case 56:
#line 583 "python.y"
{

  strcpy((yyval.ctype).code,(yyvsp[0].ctype).code);
  strcpy((yyval.ctype).lhs,(yyvsp[0].ctype).lhs);
}
#line 2302 "y.tab.c"
    break;

  case 57:
#line 589 "python.y"
{

  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);
  strcpy((yyval.ctype).lhs,temp_var);
  sprintf((yyval.ctype).code,"%s%s\n+\t%s\t%s\t%s\n",(yyvsp[-2].ctype).code,(yyvsp[0].ctype).code,(yyvsp[-2].ctype).lhs,(yyvsp[0].ctype).lhs,temp_var);
  exprno=1;
}
#line 2319 "y.tab.c"
    break;

  case 58:
#line 602 "python.y"
{

  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);
  sprintf((yyval.ctype).lhs,temp_var);
  sprintf((yyval.ctype).code,"%s\n%s\n-\t%s\t%s\t%s\n",(yyvsp[-2].ctype).code,(yyvsp[0].ctype).code,(yyvsp[-2].ctype).lhs,(yyvsp[0].ctype).lhs,temp_var);
  
  exprno=1;
}
#line 2337 "y.tab.c"
    break;

  case 59:
#line 617 "python.y"
{

  strcpy((yyval.ctype).code,(yyvsp[0].ctype).code);
  strcpy((yyval.ctype).lhs,(yyvsp[0].ctype).lhs);
}
#line 2347 "y.tab.c"
    break;

  case 60:
#line 623 "python.y"
{
  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);
  sprintf((yyval.ctype).lhs,temp_var);
  sprintf((yyval.ctype).code,"%s\n%s\n^\t%s\t%s\t%s\n",(yyvsp[-2].ctype).code,(yyvsp[0].ctype).code,(yyvsp[-2].ctype).lhs,(yyvsp[0].ctype).lhs,temp_var);
  exprno=1;

}
#line 2364 "y.tab.c"
    break;

  case 61:
#line 636 "python.y"
{
  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  sprintf((yyval.ctype).lhs,temp_var);
  sprintf((yyval.ctype).code,"%s\n%s\n&\t%s\t%s\t%s\n",(yyvsp[-2].ctype).code,(yyvsp[0].ctype).code,(yyvsp[-2].ctype).lhs,(yyvsp[0].ctype).lhs,temp_var);
  exprno=1;
}
#line 2377 "y.tab.c"
    break;

  case 62:
#line 645 "python.y"
{
  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  sprintf((yyval.ctype).lhs,temp_var);
  sprintf((yyval.ctype).code,"%s\n%s\n|\t%s\t%s\t%s\n",(yyvsp[-2].ctype).code,(yyvsp[0].ctype).code,(yyvsp[-2].ctype).lhs,(yyvsp[0].ctype).lhs,temp_var); 
  exprno=1;
}
#line 2390 "y.tab.c"
    break;

  case 63:
#line 655 "python.y"
{
  

  strcpy((yyval.ctype).code,(yyvsp[0].ctype).code);
  strcpy((yyval.ctype).lhs,(yyvsp[0].ctype).lhs);
}
#line 2401 "y.tab.c"
    break;

  case 64:
#line 662 "python.y"
{
  

  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);

  sprintf((yyval.ctype).code,">\t%s\t%s\t%s\n", (yyvsp[-2].ctype).lhs, (yyvsp[0].ctype).lhs, temp_var);
  strncpy((yyval.ctype).lhs, temp_var, m+1);
}
#line 2419 "y.tab.c"
    break;

  case 65:
#line 676 "python.y"
{
  


  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);


  sprintf((yyval.ctype).code,"%s\n%s\n>=\t%s\t%s\t%s\n", (yyvsp[-2].ctype).code, (yyvsp[0].ctype).code,(yyvsp[-2].ctype).lhs,(yyvsp[0].ctype).lhs, temp_var);
  strncpy((yyval.ctype).lhs, temp_var, m+1);
}
#line 2439 "y.tab.c"
    break;

  case 66:
#line 692 "python.y"
{
  

  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);

  sprintf((yyval.ctype).code,"%s\n%s\n<\t%s\t%s\t%s\n", (yyvsp[-2].ctype).code, (yyvsp[0].ctype).code,(yyvsp[-2].ctype).lhs,(yyvsp[0].ctype).lhs, temp_var);
  strncpy((yyval.ctype).lhs, temp_var, m+1);
}
#line 2457 "y.tab.c"
    break;

  case 67:
#line 706 "python.y"
{
  

  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);

  sprintf((yyval.ctype).code,"<=\t%s\t%s\t%s\n", (yyvsp[-2].ctype).code, (yyvsp[0].ctype).code, temp_var);
  strncpy((yyval.ctype).lhs, temp_var, m+1);
}
#line 2475 "y.tab.c"
    break;

  case 68:
#line 721 "python.y"
{
  

  strcpy((yyval.ctype).code,(yyvsp[0].ctype).code);
}
#line 2485 "y.tab.c"
    break;

  case 69:
#line 727 "python.y"
{
  

  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);



  strcpy((yyval.ctype).lhs,temp_var);
  sprintf((yyval.ctype).code,"%s\n%s\n==\t%s\t%s\t%s\n", (yyvsp[-2].ctype).code, (yyvsp[0].ctype).code,(yyvsp[-2].ctype).lhs,(yyvsp[0].ctype).lhs, temp_var);
}
#line 2505 "y.tab.c"
    break;

  case 70:
#line 743 "python.y"
{
  


  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);
  sprintf("%s\n%s\n!=\t%s\t%s\t%s\n", (yyvsp[-2].ctype).code, (yyvsp[0].ctype).code,(yyvsp[-2].ctype).lhs,(yyvsp[0].ctype).lhs, temp_var);

  strncpy((yyval.ctype).lhs, temp_var, m+1);   //check out
}
#line 2524 "y.tab.c"
    break;

  case 71:
#line 759 "python.y"
{
  strcpy((yyval.ctype).code,(yyvsp[0].ctype).code);
  strcpy((yyval.ctype).lhs,(yyvsp[0].ctype).lhs);
}
#line 2533 "y.tab.c"
    break;

  case 72:
#line 764 "python.y"
{ 
}
#line 2540 "y.tab.c"
    break;

  case 73:
#line 768 "python.y"
{
  strcpy((yyval.ctype).code,(yyvsp[0].ctype).code);
  strcpy((yyval.ctype).lhs,(yyvsp[0].ctype).lhs);
}
#line 2549 "y.tab.c"
    break;

  case 74:
#line 773 "python.y"
{
  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);
  strcpy((yyval.ctype).lhs,temp_var);
  sprintf((yyval.ctype).code,"%s%s\nand\t%s\t%s\t%s\n",(yyvsp[-2].ctype).code,(yyvsp[0].ctype).code,(yyvsp[-2].ctype).lhs,(yyvsp[0].ctype).lhs,temp_var);
}
#line 2564 "y.tab.c"
    break;

  case 75:
#line 785 "python.y"
{
  (yyval.ctype)=(yyvsp[0].ctype);  
  strcpy((yyval.ctype).code,(yyvsp[0].ctype).code);
  strcpy((yyval.ctype).lhs,(yyvsp[0].ctype).lhs);
}
#line 2574 "y.tab.c"
    break;

  case 76:
#line 791 "python.y"
{
  (yyval.ctype)=(yyvsp[-2].ctype);  
  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);
  strcpy((yyval.ctype).lhs,temp_var);
  sprintf((yyval.ctype).code,"%s%s\nor\t%s\t%s\t%s\n",(yyvsp[-2].ctype).code,(yyvsp[0].ctype).code,(yyvsp[-2].ctype).lhs,(yyvsp[0].ctype).lhs,temp_var);
}
#line 2590 "y.tab.c"
    break;


#line 2594 "y.tab.c"

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
#line 804 "python.y"
 
int yyerror(char *msg) 
{ 
  printf("Syntax Error\n"); 
  return 1;
} 
 
int main() 
{ 
  yyparse();  
  display_symbol();
  return 0;
}

// /\*(.|\n)*?\*/
// ^[ ]*?//.*
