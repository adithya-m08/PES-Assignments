
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

	#include "sym_tab.c"
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#define YYSTYPE char*
	int type=-1;	//initial declaration of type for symbol table
	char* vval="~";	//initial declaration of value for symbol table
	int vtype=-1;	//initial declaration for type checking for symbol table
	int scope=0;	//initial declaration for scope
	int err=0;	//Initial declaration for error
	void yyerror(char* s); // error handling function
	int yylex(); // declare the function performing lexical analysis
	int arraysize=1; //initial size of array
	extern int yylineno; // track the line number
	extern char* yytext; // track the token 



/* Line 189 of yacc.c  */
#line 93 "y.tab.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_INT = 258,
     T_CHAR = 259,
     T_DOUBLE = 260,
     T_WHILE = 261,
     T_INC = 262,
     T_DEC = 263,
     T_OROR = 264,
     T_ANDAND = 265,
     T_EQCOMP = 266,
     T_NOTEQUAL = 267,
     T_GREATEREQ = 268,
     T_LESSEREQ = 269,
     T_LEFTSHIFT = 270,
     T_RIGHTSHIFT = 271,
     T_PRINTLN = 272,
     T_STRING = 273,
     T_FLOAT = 274,
     T_BOOLEAN = 275,
     T_IF = 276,
     T_ELSE = 277,
     T_STRLITERAL = 278,
     T_DO = 279,
     T_INCLUDE = 280,
     T_HEADER = 281,
     T_MAIN = 282,
     T_ID = 283,
     T_NUM = 284,
     T_FOR = 285,
     T_OR = 286,
     T_AND = 287,
     T_INCR = 288,
     T_DECR = 289,
     T_IFX = 290
   };
#endif
/* Tokens.  */
#define T_INT 258
#define T_CHAR 259
#define T_DOUBLE 260
#define T_WHILE 261
#define T_INC 262
#define T_DEC 263
#define T_OROR 264
#define T_ANDAND 265
#define T_EQCOMP 266
#define T_NOTEQUAL 267
#define T_GREATEREQ 268
#define T_LESSEREQ 269
#define T_LEFTSHIFT 270
#define T_RIGHTSHIFT 271
#define T_PRINTLN 272
#define T_STRING 273
#define T_FLOAT 274
#define T_BOOLEAN 275
#define T_IF 276
#define T_ELSE 277
#define T_STRLITERAL 278
#define T_DO 279
#define T_INCLUDE 280
#define T_HEADER 281
#define T_MAIN 282
#define T_ID 283
#define T_NUM 284
#define T_FOR 285
#define T_OR 286
#define T_AND 287
#define T_INCR 288
#define T_DECR 289
#define T_IFX 290




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 205 "y.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  35
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   366

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNRULES -- Number of states.  */
#define YYNSTATES  163

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,     2,     2,     2,     2,     2,
      38,    39,    48,    46,    44,    47,     2,    49,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    37,
      35,    45,    36,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    41,     2,     2,     2,     2,
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
      51
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,    11,    14,    18,    22,    26,    29,
      32,    36,    37,    42,    43,    44,    59,    60,    64,    67,
      70,    73,    78,    79,    83,    85,    89,    91,    93,    95,
      97,    99,   100,   105,   109,   111,   115,   118,   121,   125,
     129,   131,   135,   139,   141,   145,   147,   149,   151,   153,
     155,   157,   159,   161,   163,   165,   167,   169,   171,   173,
     175,   177,   179,   181,   183,   184,   194,   196,   197,   200,
     201,   205,   208,   210,   213,   216,   217,   220,   223,   224,
     229,   230,   231,   239,   241,   245,   246,   251,   253,   255,
     261,   263,   265,   266,   271
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,    54,    -1,    25,    35,    26,    36,    54,
      -1,    76,    54,    -1,    60,    37,    54,    -1,    66,    37,
      54,    -1,    58,    37,    54,    -1,    56,    54,    -1,    85,
      54,    -1,    68,    37,    54,    -1,    -1,     1,    55,    37,
      54,    -1,    -1,    -1,    30,    38,    58,    37,    28,    72,
      68,    37,    68,    39,    40,    57,    79,    41,    -1,    -1,
      59,    65,    63,    -1,    65,    63,    -1,    65,    61,    -1,
      28,    62,    -1,    42,    29,    43,    62,    -1,    -1,    63,
      44,    64,    -1,    64,    -1,    28,    45,    68,    -1,    28,
      -1,     3,    -1,    19,    -1,     5,    -1,     4,    -1,    -1,
      28,    67,    45,    68,    -1,    68,    72,    69,    -1,    69,
      -1,    68,    73,    69,    -1,    69,    74,    -1,    69,    75,
      -1,    69,    46,    70,    -1,    69,    47,    70,    -1,    70,
      -1,    70,    48,    71,    -1,    70,    49,    71,    -1,    71,
      -1,    38,    68,    39,    -1,    28,    -1,    29,    -1,    23,
      -1,    14,    -1,    13,    -1,    35,    -1,    36,    -1,    11,
      -1,    12,    -1,    32,    -1,    31,    -1,    50,    -1,    33,
      -1,    34,    -1,    33,    -1,    34,    -1,    47,    -1,    46,
      -1,    50,    -1,    -1,    65,    27,    38,    78,    39,    40,
      77,    79,    41,    -1,    63,    -1,    -1,    81,    79,    -1,
      -1,    86,    80,    79,    -1,    56,    54,    -1,    85,    -1,
      68,    37,    -1,    58,    37,    -1,    -1,    60,    37,    -1,
      66,    37,    -1,    -1,    21,    88,    82,    79,    -1,    -1,
      -1,    21,    88,    83,    79,    84,    22,    79,    -1,    89,
      -1,    24,    86,    89,    -1,    -1,    40,    87,    79,    41,
      -1,    68,    -1,    66,    -1,     6,    38,    88,    39,    90,
      -1,    68,    -1,    66,    -1,    -1,    40,    91,    79,    41,
      -1,    37,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    27,    27,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    40,    41,    45,    45,    46,    46,    48,    49,
      51,    65,    66,    68,    69,    72,    86,    98,    99,   100,
     101,   105,   105,   117,   118,   119,   120,   124,   128,   140,
     152,   156,   168,   180,   183,   184,   210,   219,   230,   231,
     232,   233,   234,   235,   238,   239,   240,   243,   244,   247,
     248,   249,   250,   251,   254,   254,   258,   259,   265,   266,
     266,   267,   268,   269,   270,   271,   277,   278,   279,   279,
     280,   280,   280,   281,   284,   286,   286,   290,   291,   295,
     299,   300,   304,   304,   305
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_INT", "T_CHAR", "T_DOUBLE", "T_WHILE",
  "T_INC", "T_DEC", "T_OROR", "T_ANDAND", "T_EQCOMP", "T_NOTEQUAL",
  "T_GREATEREQ", "T_LESSEREQ", "T_LEFTSHIFT", "T_RIGHTSHIFT", "T_PRINTLN",
  "T_STRING", "T_FLOAT", "T_BOOLEAN", "T_IF", "T_ELSE", "T_STRLITERAL",
  "T_DO", "T_INCLUDE", "T_HEADER", "T_MAIN", "T_ID", "T_NUM", "T_FOR",
  "T_OR", "T_AND", "T_INCR", "T_DECR", "'<'", "'>'", "';'", "'('", "')'",
  "'{'", "'}'", "'['", "']'", "','", "'='", "'+'", "'-'", "'*'", "'/'",
  "'!'", "T_IFX", "$accept", "START", "PROG", "$@1", "FOR", "$@2",
  "DEC_ASGN", "$@3", "DECLR", "ARRAY", "BRACKET", "LISTVAR", "VAR", "TYPE",
  "ASSGN", "$@4", "EXPR", "E", "T", "F", "REL_OP", "LOGICAL_OP",
  "UNARY_OP", "UN_OP", "MAIN", "$@5", "EMPTY_LISTVAR", "STMT", "$@6",
  "STMT_NO_BLOCK", "$@7", "$@8", "$@9", "DO", "BLOCK", "$@10", "COND",
  "WHILE", "WHILE_2", "$@11", 0
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
     285,   286,   287,   288,   289,    60,    62,    59,    40,    41,
     123,   125,    91,    93,    44,    61,    43,    45,    42,    47,
      33,   290
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    54,    54,    54,    54,    54,    54,
      54,    55,    54,    54,    57,    56,    59,    58,    60,    60,
      61,    62,    62,    63,    63,    64,    64,    65,    65,    65,
      65,    67,    66,    68,    68,    68,    68,    68,    69,    69,
      69,    70,    70,    70,    71,    71,    71,    71,    72,    72,
      72,    72,    72,    72,    73,    73,    73,    74,    74,    75,
      75,    75,    75,    75,    77,    76,    78,    78,    79,    80,
      79,    79,    79,    79,    79,    79,    81,    81,    82,    81,
      83,    84,    81,    81,    85,    87,    86,    88,    88,    89,
      88,    88,    91,    90,    90
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     5,     2,     3,     3,     3,     2,     2,
       3,     0,     4,     0,     0,    14,     0,     3,     2,     2,
       2,     4,     0,     3,     1,     3,     1,     1,     1,     1,
       1,     0,     4,     3,     1,     3,     2,     2,     3,     3,
       1,     3,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     9,     1,     0,     2,     0,
       3,     2,     1,     2,     2,     0,     2,     2,     0,     4,
       0,     0,     7,     1,     3,     0,     4,     1,     1,     5,
       1,     1,     0,     4,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    11,    27,    30,    29,    28,    47,     0,     0,    45,
      46,     0,     0,     0,     2,     0,     0,     0,     0,     0,
       0,     0,    34,    40,    43,     0,     0,     0,    85,     0,
       0,     0,    16,    45,     0,     1,     8,     0,     0,     0,
       0,    22,    19,    18,    24,     0,    52,    53,    49,    48,
      55,    54,    50,    51,     0,    56,     0,     0,    57,    58,
      62,    61,    63,    36,    37,     0,     0,     4,     9,     0,
      75,     0,    84,     0,     0,     0,    44,     7,    26,    17,
       5,    67,     0,     0,    20,     0,     6,    10,    33,    35,
      38,    39,    41,    42,    12,     0,     0,     0,     0,     0,
       0,     0,     0,    75,    72,    69,    83,     0,     0,    32,
       0,    66,     0,     0,    25,    23,     0,     0,    88,    87,
      78,    71,    74,    76,    77,    73,    86,    68,    75,     0,
       3,     0,     0,    22,    75,    75,    70,     0,     0,    64,
      21,    79,    81,    94,    92,    89,     0,    75,     0,    75,
       0,     0,    75,     0,     0,    65,    82,    93,     0,    14,
      75,     0,    15
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    13,    14,    27,    15,   160,    16,    17,    18,    42,
      84,    43,    44,    19,    20,    31,    21,    22,    23,    24,
      56,    57,    63,    64,    25,   147,   112,   102,   128,   103,
     134,   135,   148,    26,   105,    70,   120,   106,   145,   149
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -98
static const yytype_int16 yypact[] =
{
     185,   -98,   -98,   -98,   -98,   -98,   -98,   -18,    -5,   -20,
     -98,    -6,    61,    39,   -98,   197,    14,     7,    16,   -14,
      29,   247,    23,   -15,   -98,   197,   197,    35,   -98,    54,
      50,    32,   -98,   -98,    93,   -98,   -98,   197,    51,   197,
      40,   -21,   -98,    44,   -98,   197,   -98,   -98,   -98,   -98,
     -98,   -98,   -98,   -98,   197,   -98,    61,    61,   -98,   -98,
      61,    61,   -98,   -98,   -98,    61,    61,   -98,   -98,   197,
     326,    56,   -98,    60,    61,    55,   -98,   -98,    57,    44,
     -98,    51,    71,    61,   -98,    51,   -98,   -98,     0,     0,
     -15,   -15,   -98,   -98,   -98,   216,   227,    66,    72,    80,
      73,   258,    70,   326,   -98,   -98,   -98,   216,   197,   303,
      85,    44,    76,    77,   303,   -98,    61,    61,   -98,   303,
     -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   326,    82,
     -98,     6,    87,    99,   326,   326,   -98,   -33,    61,   -98,
     -98,   -98,   -98,   -98,   -98,   -98,   274,   326,   120,   326,
      61,   106,   326,   108,   287,   -98,   -98,   -98,   111,   -98,
     326,   112,   -98
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -98,   -98,   -10,   -98,    27,   -98,    11,   -98,    31,   -98,
      19,   -36,    69,   -16,   -67,   -98,   -12,    -8,   -52,     9,
      25,   -98,   -98,   -98,   -98,   -98,   -98,   -97,   -98,   -98,
     -98,   -98,   -98,    47,   150,   -98,    62,   135,   -98,   -98
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -32
static const yytype_int16 yytable[] =
{
      34,    38,    79,   100,   143,    36,   127,   144,    90,    91,
       2,     3,     4,    40,    41,    67,    68,    46,    47,    48,
      49,    82,    28,   -26,    83,   -31,     5,    77,   118,    80,
      30,   136,    32,    65,    66,    86,   100,   141,   142,    35,
     118,    52,    53,    75,    87,   111,   116,   117,    88,    89,
     151,    37,   153,    39,    99,   156,    58,    59,   101,    94,
      71,   100,   109,   161,    90,    91,    45,   100,   100,    60,
      61,   114,    69,    62,    92,    93,    73,    74,    81,    78,
     100,    97,   100,   119,     6,   100,   121,    99,    85,    33,
      10,   101,   110,   100,   107,   119,   108,    96,   130,    12,
     113,    98,    83,   122,    46,    47,    48,    49,    41,   123,
     124,   126,    99,   131,    97,   132,   101,   104,    99,    99,
     133,   137,   101,   101,    50,    51,   146,   139,    52,    53,
      96,    99,    76,    99,    98,   101,    99,   101,   154,    97,
     101,    82,   152,    55,    99,    97,    97,   155,   101,   157,
     104,   159,   140,   162,   115,    96,   138,    29,    97,    98,
      97,    96,    96,    97,    72,    98,    98,     0,     0,   129,
       0,    97,     0,     0,    96,   104,    96,     0,    98,    96,
      98,   104,   104,    98,     0,   -13,     1,    96,     2,     3,
       4,    98,     0,     0,   104,     0,   104,   -13,     1,   104,
       2,     3,     4,   -13,     5,     0,     0,   104,     6,     7,
       8,     0,     0,     9,    10,    11,     5,     0,   -13,   -13,
       6,     7,     8,    12,     0,     9,    10,    11,     1,     0,
       2,     3,     4,   -13,     0,    12,     0,   -13,   -13,     6,
       0,     0,     0,     0,     9,    10,     5,     0,   -13,   -13,
       6,     7,     8,     0,    12,     9,    10,    11,    46,    47,
      48,    49,     0,     0,     0,    12,     0,   -13,   -13,    46,
      47,    48,    49,     0,     0,     0,     0,     0,    50,    51,
       0,     0,    52,    53,    54,    46,    47,    48,    49,    50,
      51,     0,     0,    52,    53,   125,     0,    55,    46,    47,
      48,    49,     0,     0,     0,    50,    51,     0,    55,    52,
      53,   150,     0,     0,    46,    47,    48,    49,    50,    51,
       0,     0,    52,    53,    55,     0,   158,     0,     0,     2,
       3,     4,    71,     0,    50,    51,     0,    55,    52,    53,
       0,     0,     0,     0,     0,     5,     0,    95,     0,     6,
       7,     0,     0,    55,     9,    10,    11,     0,     0,     0,
       0,     0,     0,     0,    12,     0,    28
};

static const yytype_int16 yycheck[] =
{
      12,    17,    38,    70,    37,    15,   103,    40,    60,    61,
       3,     4,     5,    27,    28,    25,    26,    11,    12,    13,
      14,    42,    40,    44,    45,    45,    19,    37,    95,    39,
      35,   128,    38,    48,    49,    45,   103,   134,   135,     0,
     107,    35,    36,    32,    54,    81,    46,    47,    56,    57,
     147,    37,   149,    37,    70,   152,    33,    34,    70,    69,
       6,   128,    74,   160,   116,   117,    37,   134,   135,    46,
      47,    83,    37,    50,    65,    66,    26,    45,    38,    28,
     147,    70,   149,    95,    23,   152,    96,   103,    44,    28,
      29,   103,    37,   160,    38,   107,    36,    70,   108,    38,
      29,    70,    45,    37,    11,    12,    13,    14,    28,    37,
      37,    41,   128,    28,   103,    39,   128,    70,   134,   135,
      43,    39,   134,   135,    31,    32,   138,    40,    35,    36,
     103,   147,    39,   149,   103,   147,   152,   149,   150,   128,
     152,    42,    22,    50,   160,   134,   135,    41,   160,    41,
     103,    40,   133,    41,    85,   128,   131,     7,   147,   128,
     149,   134,   135,   152,    29,   134,   135,    -1,    -1,   107,
      -1,   160,    -1,    -1,   147,   128,   149,    -1,   147,   152,
     149,   134,   135,   152,    -1,     0,     1,   160,     3,     4,
       5,   160,    -1,    -1,   147,    -1,   149,     0,     1,   152,
       3,     4,     5,     6,    19,    -1,    -1,   160,    23,    24,
      25,    -1,    -1,    28,    29,    30,    19,    -1,    21,    22,
      23,    24,    25,    38,    -1,    28,    29,    30,     1,    -1,
       3,     4,     5,     6,    -1,    38,    -1,    40,    41,    23,
      -1,    -1,    -1,    -1,    28,    29,    19,    -1,    21,    22,
      23,    24,    25,    -1,    38,    28,    29,    30,    11,    12,
      13,    14,    -1,    -1,    -1,    38,    -1,    40,    41,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    31,    32,
      -1,    -1,    35,    36,    37,    11,    12,    13,    14,    31,
      32,    -1,    -1,    35,    36,    37,    -1,    50,    11,    12,
      13,    14,    -1,    -1,    -1,    31,    32,    -1,    50,    35,
      36,    37,    -1,    -1,    11,    12,    13,    14,    31,    32,
      -1,    -1,    35,    36,    50,    -1,    39,    -1,    -1,     3,
       4,     5,     6,    -1,    31,    32,    -1,    50,    35,    36,
      -1,    -1,    -1,    -1,    -1,    19,    -1,    21,    -1,    23,
      24,    -1,    -1,    50,    28,    29,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    40
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,    19,    23,    24,    25,    28,
      29,    30,    38,    53,    54,    56,    58,    59,    60,    65,
      66,    68,    69,    70,    71,    76,    85,    55,    40,    86,
      35,    67,    38,    28,    68,     0,    54,    37,    65,    37,
      27,    28,    61,    63,    64,    37,    11,    12,    13,    14,
      31,    32,    35,    36,    37,    50,    72,    73,    33,    34,
      46,    47,    50,    74,    75,    48,    49,    54,    54,    37,
      87,     6,    89,    26,    45,    58,    39,    54,    28,    63,
      54,    38,    42,    45,    62,    44,    54,    54,    69,    69,
      70,    70,    71,    71,    54,    21,    56,    58,    60,    65,
      66,    68,    79,    81,    85,    86,    89,    38,    36,    68,
      37,    63,    78,    29,    68,    64,    46,    47,    66,    68,
      88,    54,    37,    37,    37,    37,    41,    79,    80,    88,
      54,    28,    39,    43,    82,    83,    79,    39,    72,    40,
      62,    79,    79,    37,    40,    90,    68,    77,    84,    91,
      37,    79,    22,    79,    68,    41,    79,    41,    39,    40,
      57,    79,    41
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
# if YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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

/* Line 1455 of yacc.c  */
#line 27 "parser.y"
    { if(err==0) printf("Valid syntax\n");
	 YYACCEPT; }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 40 "parser.y"
    {yyerrok;yyclearin;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 45 "parser.y"
    {scope++;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 46 "parser.y"
    {printf(" ");}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 51 "parser.y"
    {
		if(check_sym_tab((yyvsp[(1) - (2)])))	//if variable is in table then variable is being re-declared
				{
					printf("Variable %s already declared\n",(yyvsp[(1) - (2)]));
					yyerror((yyvsp[(1) - (2)]));
				}
				else
				{
				insert_symbol((yyvsp[(1) - (2)]),size(type)*arraysize,type,yylineno,scope);
				arraysize=1;	//revert to default for checking
				type=-1;
				}
		}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 65 "parser.y"
    { arraysize*=atoi((yyvsp[(2) - (4)]));}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 72 "parser.y"
    {
				if(check_sym_tab((yyvsp[(1) - (3)])))	//if variable is in table then variable is being re-declared
				{
					printf("Variable %s already declared\n",(yyvsp[(1) - (3)]));
					yyerror((yyvsp[(1) - (3)]));
				}
				else
				{
				insert_symbol((yyvsp[(1) - (3)]),size(type),type,yylineno,scope);
				insert_val((yyvsp[(1) - (3)]),vval,yylineno);
				vval="~";	//revert to default for checking
				type=-1;
				}
			}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 86 "parser.y"
    {
				if(check_sym_tab((yyvsp[(1) - (1)])))	//if variable is in table then variable is being re-declared
				{
					printf("Variable %s already declared\n",(yyvsp[(1) - (1)]));
					yyerror((yyvsp[(1) - (1)]));
				}
				else{
				insert_symbol((yyvsp[(1) - (1)]),size(type),type,yylineno,scope);
				type=-1;	//revert to default for checking
				}
			}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 98 "parser.y"
    {type = INT;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 99 "parser.y"
    {type = FLOAT;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 100 "parser.y"
    {type = DOUBLE;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 101 "parser.y"
    {type = CHAR;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 105 "parser.y"
    {type=retrieve_type((yyvsp[(1) - (1)]));}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 105 "parser.y"
    {
				if(!check_sym_tab((yyvsp[(1) - (4)])))	//if variable not declared then value cannot be assigned
				{
					printf("Variable %s not declared\n",(yyvsp[(1) - (4)]));
					yyerror((yyvsp[(1) - (4)]));
				}
				insert_val((yyvsp[(1) - (4)]),vval,yylineno);
				vval="~";		//to make sure previous values aren't inserted into other identifiers
				type=-1;		//revert to default for checking
			}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 118 "parser.y"
    {vval=(yyvsp[(1) - (1)]);}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 120 "parser.y"
    {
		int xyz=atoi(retrieve_val((yyvsp[(1) - (2)])))+1;
		sprintf((yyval),"%d",xyz);
	   }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 128 "parser.y"
    { 
			if(vtype==2)				//integer
				sprintf((yyval),"%d",(atoi((yyvsp[(1) - (3)]))+atoi((yyvsp[(3) - (3)]))));
			else if(vtype==3)			//float or double
				sprintf((yyval),"%lf",(atof((yyvsp[(1) - (3)]))+atof((yyvsp[(3) - (3)]))));
			else
			{
				printf("Character used in arithmetic\n");
				yyerror((yyval));
				(yyval)="~";
			}
		}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 140 "parser.y"
    { 
			if(vtype==2)				//integer
				sprintf((yyval),"%d",(atoi((yyvsp[(1) - (3)]))-atoi((yyvsp[(3) - (3)]))));
			else if(vtype==3)			//float or double
				sprintf((yyval),"%lf",(atof((yyvsp[(1) - (3)]))-atof((yyvsp[(3) - (3)]))));
			else
			{
				printf("Character used in arithmetic\n");
				yyerror((yyval));
				(yyval)="~";
			}
		}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 152 "parser.y"
    {(yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 156 "parser.y"
    { 
			if(vtype==2)				//integer
				sprintf((yyval),"%d",(atoi((yyvsp[(1) - (3)]))*atoi((yyvsp[(3) - (3)]))));
			else if(vtype==3)			//float or double
				sprintf((yyval),"%lf",(atof((yyvsp[(1) - (3)]))*atof((yyvsp[(3) - (3)]))));
			else
			{
				printf("Character used in arithmetic\n");
				yyerror((yyval));
				(yyval)="~";
			}
		}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 168 "parser.y"
    { 
			if(vtype==2)				//integer
				sprintf((yyval),"%d",(atoi((yyvsp[(1) - (3)]))/atoi((yyvsp[(3) - (3)]))));
			else if(vtype==3)			//float or double
				sprintf((yyval),"%lf",(atof((yyvsp[(1) - (3)]))/atof((yyvsp[(3) - (3)]))));
			else
			{
				printf("Character used in arithmetic\n");
				yyerror((yyval));
				(yyval)="~";
			}
		}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 180 "parser.y"
    {(yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 184 "parser.y"
    {
			if(check_sym_tab((yyvsp[(1) - (1)])))		//check if variable is in symbol table
			{
				char* check=retrieve_val((yyvsp[(1) - (1)]));
				if(check=="~")		//if variable has no value then can't be used for assignment
				{
					printf("Variable %s not initialised",(yyvsp[(1) - (1)]));
					yyerror((yyvsp[(1) - (1)]));
				}
				else
				{	
					(yyval)=strdup(check);
					vtype=type_check(check);	
					if(vtype!=type && type!=-1)	//checks for matching type
					{
						printf("Mismatch type\n");
						yyerror((yyvsp[(1) - (1)]));
					}	
				}
			}
			else
			{
					printf("Variable %s not declared\n",(yyvsp[(1) - (1)]));
					yyerror((yyvsp[(1) - (1)]));
			}
		}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 210 "parser.y"
    {
    			(yyval)=strdup((yyvsp[(1) - (1)])); 
    			vtype=type_check((yyvsp[(1) - (1)]));
    			if(vtype!=type && type!=-1)	//checks for matching type
			{
				printf("Mismatch type\n");
				yyerror((yyvsp[(1) - (1)]));
			}
		}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 219 "parser.y"
    {
    			(yyval)=strdup((yyvsp[(1) - (1)])); 
    			vtype=1;
			if(vtype!=type)		//checks for matching type
			{
				printf("Mismatch type\n");	
				yyerror((yyvsp[(1) - (1)]));
			}
		}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 254 "parser.y"
    {scope++;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 254 "parser.y"
    {scope--;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 266 "parser.y"
    {scope++;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 266 "parser.y"
    {scope--;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 279 "parser.y"
    {scope++;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 279 "parser.y"
    {scope--;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 280 "parser.y"
    {scope++;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 280 "parser.y"
    {scope--;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 286 "parser.y"
    {scope++;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 286 "parser.y"
    {scope--;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 304 "parser.y"
    {scope++;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 304 "parser.y"
    {scope--;}
    break;



/* Line 1455 of yacc.c  */
#line 1983 "y.tab.c"
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
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



/* Line 1675 of yacc.c  */
#line 308 "parser.y"



/* error handling function */
void yyerror(char* s)
{
	err+=1;
	//printf("Error :syntax error,line number:%d,token:%s \n",yylineno,yytext);
	printf("Error :%s,line number:%d,token:%s \n",s,yylineno,yytext);
}
int yywrap()
{
    return(1);
}

/* main function - calls the yyparse() function which will in turn drive yylex() as well */
int main(int argc, char* argv[])
{
	t=init_table();
	//printf("here \n");
	yyparse();
	display_sym_tab();
	return 0;

}

