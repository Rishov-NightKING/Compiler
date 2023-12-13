/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "1605084.y" /* yacc.c:339  */

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<bits/stdc++.h>
#include "1605084_symbolTable.h"


using namespace std;

int yyparse(void);
int yylex(void);
extern FILE *yyin;

FILE *fp;
FILE *errorout;
FILE *logout;

extern int line_count;
extern int error_count;

SymbolTable symbolTable;

vector<SymbolInfo*>declaration_list_vector;
vector<pair<string,string>>parameter_list_vector;
vector<SymbolInfo*>argument_list_vector;


void yyerror(const char *s)
{
 	fprintf(errorout,"Error at line no %d :  %s\n\n",line_count,s);
	error_count++;
}




#line 106 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
    ID = 258,
    CONST_INT = 259,
    CONST_FLOAT = 260,
    CONST_CHAR = 261,
    ADDOP = 262,
    MULOP = 263,
    LOGICOP = 264,
    RELOP = 265,
    STRING = 266,
    IF = 267,
    ELSE = 268,
    FOR = 269,
    WHILE = 270,
    DO = 271,
    BREAK = 272,
    CONTINUE = 273,
    INT = 274,
    FLOAT = 275,
    CHAR = 276,
    DOUBLE = 277,
    VOID = 278,
    RETURN = 279,
    SWITCH = 280,
    CASE = 281,
    DEFAULT = 282,
    INCOP = 283,
    DECOP = 284,
    ASSIGNOP = 285,
    LPAREN = 286,
    RPAREN = 287,
    LCURL = 288,
    RCURL = 289,
    LTHIRD = 290,
    RTHIRD = 291,
    SEMICOLON = 292,
    COMMA = 293,
    NOT = 294,
    PRINTLN = 295,
    BITOP = 296,
    ELSE_LOWER = 297
  };
#endif
/* Tokens.  */
#define ID 258
#define CONST_INT 259
#define CONST_FLOAT 260
#define CONST_CHAR 261
#define ADDOP 262
#define MULOP 263
#define LOGICOP 264
#define RELOP 265
#define STRING 266
#define IF 267
#define ELSE 268
#define FOR 269
#define WHILE 270
#define DO 271
#define BREAK 272
#define CONTINUE 273
#define INT 274
#define FLOAT 275
#define CHAR 276
#define DOUBLE 277
#define VOID 278
#define RETURN 279
#define SWITCH 280
#define CASE 281
#define DEFAULT 282
#define INCOP 283
#define DECOP 284
#define ASSIGNOP 285
#define LPAREN 286
#define RPAREN 287
#define LCURL 288
#define RCURL 289
#define LTHIRD 290
#define RTHIRD 291
#define SEMICOLON 292
#define COMMA 293
#define NOT 294
#define PRINTLN 295
#define BITOP 296
#define ELSE_LOWER 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 41 "1605084.y" /* yacc.c:355  */

        SymbolInfo* symbol;

#line 234 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 251 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   149

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  119

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    71,    71,    81,    89,    99,   107,   115,   125,   218,
     279,   387,   481,   494,   505,   516,   531,   531,   555,   566,
     610,   621,   631,   643,   661,   679,   695,   712,   721,   732,
     741,   750,   759,   774,   790,   805,   820,   829,   847,   855,
     867,   898,   944,   955,   995,  1008,  1032,  1043,  1068,  1079,
    1106,  1118,  1160,  1181,  1201,  1216,  1227,  1289,  1300,  1311,
    1322,  1333,  1346,  1357,  1364,  1381
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "CONST_INT", "CONST_FLOAT",
  "CONST_CHAR", "ADDOP", "MULOP", "LOGICOP", "RELOP", "STRING", "IF",
  "ELSE", "FOR", "WHILE", "DO", "BREAK", "CONTINUE", "INT", "FLOAT",
  "CHAR", "DOUBLE", "VOID", "RETURN", "SWITCH", "CASE", "DEFAULT", "INCOP",
  "DECOP", "ASSIGNOP", "LPAREN", "RPAREN", "LCURL", "RCURL", "LTHIRD",
  "RTHIRD", "SEMICOLON", "COMMA", "NOT", "PRINTLN", "BITOP", "ELSE_LOWER",
  "$accept", "start", "program", "unit", "func_declaration",
  "func_definition", "parameter_list", "compound_statement", "$@1",
  "var_declaration", "type_specifier", "declaration_list", "statements",
  "statement", "expression_statement", "variable", "expression",
  "logic_expression", "rel_expression", "simple_expression", "term",
  "unary_expression", "factor", "argument_list", "arguments", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297
};
# endif

#define YYPACT_NINF -68

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-68)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      33,   -68,   -68,   -68,    40,    33,   -68,   -68,   -68,   -68,
      51,   -68,   -68,     0,    54,     1,    57,   -68,    63,    14,
     -10,    70,    59,    41,    56,   -68,   -68,    38,    33,   -68,
     -68,    83,   -68,   103,   -68,   -68,    90,    61,    43,   -68,
     -68,    55,    69,    72,    78,    55,    55,   -68,    55,    80,
     -68,   -68,    98,    65,   -68,   -68,    53,    75,   -68,   104,
       2,   106,   -68,   -68,   -68,   -68,    55,    55,     9,   -68,
      55,    11,    55,    79,    87,   -68,   117,    86,   -68,   -68,
     -68,   -68,    55,   -68,    55,    55,    55,    55,   -68,    92,
      91,    89,    96,    11,    99,   -68,   -68,   100,   -68,   -68,
     106,   123,   -68,   -68,    55,   -68,   103,    55,   103,   101,
     -68,   120,   105,   -68,   -68,   103,   103,   -68,   -68
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    20,    21,    22,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    25,     0,     0,     0,    19,     0,     0,
       0,    15,     0,    23,    16,     9,    11,     0,     0,    14,
      26,     0,    18,     0,     8,    10,    13,     0,    40,    58,
      59,     0,     0,     0,     0,     0,     0,    38,     0,     0,
      31,    29,     0,     0,    27,    30,    55,     0,    42,    44,
      46,    48,    50,    54,    12,    24,    63,     0,    55,    52,
       0,     0,     0,     0,     0,    53,     0,    25,    17,    28,
      60,    61,     0,    39,     0,     0,     0,     0,    65,     0,
      62,     0,     0,     0,     0,    37,    57,     0,    43,    45,
      49,    47,    51,    56,     0,    41,     0,     0,     0,     0,
      64,    33,     0,    35,    36,     0,     0,    34,    32
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -68,   -68,   -68,   130,   -68,   -68,   -68,    -8,   -68,    29,
       8,   -68,   -68,   -51,   -67,   -41,   -40,   -65,    60,    62,
      64,   -38,   -68,   -68,   -68
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    20,    50,    33,    51,
      52,    14,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    89,    90
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      68,    88,    79,    69,    93,    73,    74,    68,    10,    85,
      75,    26,    86,    10,    38,    39,    40,    98,    41,    35,
       1,     2,    27,    21,     3,    68,   107,    91,    28,     9,
      92,    15,    94,    19,     9,    16,    36,    80,    81,   110,
      11,    68,    46,    68,    68,    68,    68,    24,    47,   102,
      48,    25,     1,     2,    13,   111,     3,   113,    38,    39,
      40,    22,    41,    68,   117,   118,    23,   112,    38,    39,
      40,    24,    41,    29,    66,    34,    31,    42,    67,    43,
      44,    80,    81,    82,     1,     2,    46,    37,     3,    45,
      32,    17,    18,    64,    48,    30,    46,    65,    24,    78,
      70,    77,    47,    71,    48,    49,    38,    39,    40,    72,
      41,    76,    83,    84,    87,    42,    95,    43,    44,    96,
      97,    16,     1,     2,   103,   105,     3,    45,   106,   104,
      85,   108,   109,   115,    46,    12,    24,   116,   114,     0,
      47,     0,    48,    49,    99,     0,     0,     0,   101,   100
};

static const yytype_int8 yycheck[] =
{
      41,    66,    53,    41,    71,    45,    46,    48,     0,     7,
      48,    19,    10,     5,     3,     4,     5,    82,     7,    27,
      19,    20,    32,    15,    23,    66,    93,    67,    38,     0,
      70,    31,    72,    32,     5,    35,    28,    28,    29,   104,
       0,    82,    31,    84,    85,    86,    87,    33,    37,    87,
      39,    37,    19,    20,     3,   106,    23,   108,     3,     4,
       5,     4,     7,   104,   115,   116,     3,   107,     3,     4,
       5,    33,     7,     3,    31,    37,    35,    12,    35,    14,
      15,    28,    29,    30,    19,    20,    31,     4,    23,    24,
      34,    37,    38,     3,    39,    36,    31,    36,    33,    34,
      31,     3,    37,    31,    39,    40,     3,     4,     5,    31,
       7,    31,    37,     9,     8,    12,    37,    14,    15,    32,
       3,    35,    19,    20,    32,    36,    23,    24,    32,    38,
       7,    32,    32,    13,    31,     5,    33,    32,    37,    -1,
      37,    -1,    39,    40,    84,    -1,    -1,    -1,    86,    85
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    19,    20,    23,    44,    45,    46,    47,    48,    52,
      53,     0,    46,     3,    54,    31,    35,    37,    38,    32,
      49,    53,     4,     3,    33,    37,    50,    32,    38,     3,
      36,    35,    34,    51,    37,    50,    53,     4,     3,     4,
       5,     7,    12,    14,    15,    24,    31,    37,    39,    40,
      50,    52,    53,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,     3,    36,    31,    35,    58,    64,
      31,    31,    31,    59,    59,    64,    31,     3,    34,    56,
      28,    29,    30,    37,     9,     7,    10,     8,    60,    66,
      67,    59,    59,    57,    59,    37,    32,     3,    60,    61,
      63,    62,    64,    32,    38,    36,    32,    57,    32,    32,
      60,    56,    59,    56,    37,    13,    32,    56,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    46,    47,    47,
      48,    48,    49,    49,    49,    49,    51,    50,    50,    52,
      53,    53,    53,    54,    54,    54,    54,    55,    55,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    57,    57,
      58,    58,    59,    59,    60,    60,    61,    61,    62,    62,
      63,    63,    64,    64,    64,    65,    65,    65,    65,    65,
      65,    65,    66,    66,    67,    67
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       6,     5,     4,     3,     2,     1,     0,     4,     2,     3,
       1,     1,     1,     3,     6,     1,     4,     1,     2,     1,
       1,     1,     7,     5,     7,     5,     5,     3,     1,     2,
       1,     4,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     2,     2,     1,     1,     4,     3,     1,     1,
       2,     2,     1,     0,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
#line 72 "1605084.y" /* yacc.c:1646  */
    {
		fprintf(logout,"At line no : %d start : program\n",line_count);

		fprintf(logout,"%s\n\n",(yyvsp[0].symbol)->get_symbol_name().c_str());
		(yyval.symbol) = new SymbolInfo();
		(yyval.symbol)->set_symbol_name((yyvsp[0].symbol)->get_symbol_name());
	}
#line 1423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 82 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d program : program unit\n",line_count);
			
			fprintf(logout,"%s\n%s\n\n",(yyvsp[-1].symbol)->get_symbol_name().c_str(),(yyvsp[0].symbol)->get_symbol_name().c_str());
			(yyval.symbol) = new SymbolInfo();
			(yyval.symbol)->set_symbol_name((yyvsp[-1].symbol)->get_symbol_name().append((yyvsp[0].symbol)->get_symbol_name()));
		}
#line 1435 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 90 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d program : unit\n",line_count);
			
			fprintf(logout,"%s\n\n",(yyvsp[0].symbol)->get_symbol_name().c_str());
			(yyval.symbol) = new SymbolInfo();
			(yyval.symbol)->set_symbol_name((yyvsp[0].symbol)->get_symbol_name());
		}
#line 1447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 100 "1605084.y" /* yacc.c:1646  */
    {
		fprintf(logout,"At line no : %d unit : var_declaration\n",line_count);
		
		fprintf(logout,"%s\n\n",(yyvsp[0].symbol)->get_symbol_name().c_str());
		(yyval.symbol) = new SymbolInfo();
		(yyval.symbol)->set_symbol_name((yyvsp[0].symbol)->get_symbol_name());	
	}
#line 1459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 108 "1605084.y" /* yacc.c:1646  */
    {
		fprintf(logout,"At line no : %d unit : func_declaration\n",line_count);
		
		fprintf(logout,"%s\n\n",(yyvsp[0].symbol)->get_symbol_name().c_str());
		(yyval.symbol) = new SymbolInfo();
		(yyval.symbol)->set_symbol_name((yyvsp[0].symbol)->get_symbol_name());	
	}
#line 1471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 116 "1605084.y" /* yacc.c:1646  */
    {
		fprintf(logout,"At line no : %d unit : func definition\n",line_count);
		
		fprintf(logout,"%s\n\n",(yyvsp[0].symbol)->get_symbol_name().c_str());
		(yyval.symbol) = new SymbolInfo();
		(yyval.symbol)->set_symbol_name((yyvsp[0].symbol)->get_symbol_name());	
	}
#line 1483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 126 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n",line_count);

			(yyval.symbol) = new SymbolInfo();		
			string s = (yyvsp[-5].symbol)->get_symbol_name()+(yyvsp[-4].symbol)->get_symbol_name()+"("+(yyvsp[-2].symbol)->get_symbol_name()+");\n";
			(yyval.symbol)->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			//$$->set_symbol_type($1->get_symbol_type());
			
			SymbolInfo* symb = symbolTable.lookUp((yyvsp[-4].symbol)->get_symbol_name());

		
			if(symb == NULL)
			{
				//cout<<"hi(parameter)"<<endl;
				
				SymbolInfo* symb = new SymbolInfo();
				
				symb->set_symbol_name((yyvsp[-4].symbol)->get_symbol_name());
				symb->set_symbol_type((yyvsp[-5].symbol)->get_symbol_type());
				symb->set_symbol_class("FUNCTION");
				//symbolTable.insert(symb);

				int check_error = 0;
				for(int i=0;i<parameter_list_vector.size();i++)
				{
					if(parameter_list_vector[i].first == "VOID")
					{
						fprintf(errorout,"Error at line no : %d  Function parameter can't be void\n\n",line_count);
						error_count++;
						check_error = 1;
					}
					
				}
				if(check_error == 0)
				{
					symb->is_function_declared = true;
					for(int i=0;i<parameter_list_vector.size();i++)
					{
						symb->para_list.push_back(make_pair(parameter_list_vector[i].first,parameter_list_vector[i].second));
					}
					symbolTable.insert(symb);
				}
				parameter_list_vector.clear();
			}
			else 
			{
				if(symb->get_symbol_class() == "FUNCTION")
				{
					//return type mismatch
					if(symb->get_symbol_type() != (yyvsp[-5].symbol)->get_symbol_type())
					{
						fprintf(errorout,"Error at line no : %d  Function Return Type Mismatch\n\n",line_count);
						error_count++;
					}
					if(parameter_list_vector.size() == symb->para_list.size())
					{
						for(int i=0;i<parameter_list_vector.size();i++)
						{
							if(parameter_list_vector[i].first != symb->para_list[i].first)
							{
								fprintf(errorout,"Error at line no : %d  Function Parameter Mismatch\n\n",line_count);
								error_count++;	
							}
						}
					}
					else if(symb->para_list.size() != parameter_list_vector.size())
					{
						fprintf(errorout,"Error at line no : %d  Conflict in number of parameters of function : %s \n\n",line_count,symb->get_symbol_name().c_str());
						error_count++;

					}
					
					for(int i=0;i<parameter_list_vector.size();i++)
					{
						if(parameter_list_vector[i].first == "VOID")
						{
							fprintf(errorout,"Error at line no : %d  Function parameter can't be void\n\n",line_count);
							error_count++;
						}
					}
					parameter_list_vector.clear();
				}
				else
				{
					fprintf(errorout,"Error at line no : %d  Variable/array of same name already exits\n\n",line_count);
					error_count++;
				}
			}

		}
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 219 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n",line_count);
			
			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[-4].symbol)->get_symbol_name()+(yyvsp[-3].symbol)->get_symbol_name()+"();\n";
			(yyval.symbol)->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			(yyval.symbol)->set_symbol_type((yyvsp[-4].symbol)->get_symbol_type());
			SymbolInfo* symb = symbolTable.lookUp((yyvsp[-3].symbol)->get_symbol_name());
			if(symb == NULL)
			{
				SymbolInfo* symb = new SymbolInfo();
				symb->is_function_declared = true;
				symb->set_symbol_name((yyvsp[-3].symbol)->get_symbol_name());
				symb->set_symbol_type((yyvsp[-4].symbol)->get_symbol_type());
				symb->set_symbol_class("FUNCTION");

				symbolTable.insert(symb);
				//confusion
				parameter_list_vector.clear();
			}
			else 
			{
				if(symb->get_symbol_class() == "FUNCTION")
				{
					if(symb->get_symbol_type() != (yyvsp[-4].symbol)->get_symbol_type())
					{
						fprintf(errorout,"Error at line no : %d  Function Return Type Mismatch\n\n",line_count);
						error_count++;
					}
					if(parameter_list_vector.size() == symb->para_list.size())
					{
						for(int i=0;i<parameter_list_vector.size();i++)
						{
							if(parameter_list_vector[i].first != symb->para_list[i].first)
							{
								fprintf(errorout,"Error at line no : %d  Function Parameter Mismatch\n\n",line_count);
								error_count++;	
							}
						}
					}
					else if(symb->para_list.size() != parameter_list_vector.size())
					{
						fprintf(errorout,"Error at line no : %d  Conflict in number of parameters of function : %s \n\n",line_count,symb->get_symbol_name().c_str());
						error_count++;

					}
					parameter_list_vector.clear();
				}
				else
				{
					fprintf(errorout,"Error at line no : %d  Variable/array of same name already exits\n\n",line_count);
					error_count++;
				}			
			}
			
		}
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 280 "1605084.y" /* yacc.c:1646  */
    {
				fprintf(logout,"At line no : %d func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n",line_count);

				(yyval.symbol) = new SymbolInfo();
				string s = (yyvsp[-5].symbol)->get_symbol_name()+(yyvsp[-4].symbol)->get_symbol_name()+"("+(yyvsp[-2].symbol)->get_symbol_name()+")\n"+(yyvsp[0].symbol)->get_symbol_name();
				(yyval.symbol)->set_symbol_name(s);
				fprintf(logout,"%s\n\n",s.c_str());


				SymbolInfo* symb = symbolTable.lookUp((yyvsp[-4].symbol)->get_symbol_name());

				if(symb == NULL) //function not found
				{
					SymbolInfo* symb = new SymbolInfo();
					symb->set_symbol_name((yyvsp[-4].symbol)->get_symbol_name());
					symb->set_symbol_type((yyvsp[-5].symbol)->get_symbol_type());
					symb->set_symbol_class("FUNCTION");
					symb->is_function_defined = true;
					symb->is_function_declared = true;

					int check_error = 0;
					for(int i=0;i<parameter_list_vector.size();i++)
					{
						if(parameter_list_vector[i].first == "VOID")
						{
							fprintf(errorout,"Error at line no : %d  Function parameter can't be void\n\n",line_count);
							error_count++;
							check_error = 1;
						}
					}
					if(check_error == 0)
					{
						for(int i=0;i<parameter_list_vector.size();i++)
						{
							symb->para_list.push_back(make_pair(parameter_list_vector[i].first,parameter_list_vector[i].second));
						}
						symbolTable.insert(symb);
					}

					parameter_list_vector.clear();
				}
				else
				{
					if(symb->get_symbol_class() == "FUNCTION")
					{
						//previously not defined
						if(symb->is_function_defined == false && symb->is_function_declared == true)
						{
							int check_error = 0;
							if(symb->get_symbol_type() != (yyvsp[-5].symbol)->get_symbol_type())
							{
								fprintf(errorout,"Error at line no : %d  Function Return Type Mismatch\n\n",line_count);
								error_count++;
								check_error = 1;
							}
							if(symb->para_list.size() != parameter_list_vector.size())
							{
								fprintf(errorout,"Error at line no : %d  Conflict in number of parameters of function : %s \n\n",line_count,symb->get_symbol_name().c_str());
								error_count++;
								check_error = 1;
							}
							else if(parameter_list_vector.size() == symb->para_list.size())
							{
								for(int i=0;i<parameter_list_vector.size();i++)
								{
									if(parameter_list_vector[i].first != symb->para_list[i].first)
									{
										fprintf(errorout,"Error at line no : %d  Function Parameter Mismatch\n\n",line_count);
										error_count++;
										check_error = 1;	
									}
								}
							}
					
							for(int i=0;i<parameter_list_vector.size();i++)
							{
								if(parameter_list_vector[i].first == "VOID")
								{
									fprintf(errorout,"Error at line no : %d  Function parameter can't be void\n\n",line_count);
									error_count++;
									check_error = 1;
								}
							}
							

							if(check_error == 0)
							{
								symbolTable.lookUp((yyvsp[-4].symbol)->get_symbol_name())->is_function_defined = true;
							}

						}
						else if(symb->is_function_defined == true)
						{
							fprintf(errorout,"Error at line no : %d  Function already defined.\n\n",line_count);
							error_count++;
						}	
						parameter_list_vector.clear();
				
					}
					else
					{
						fprintf(errorout,"Error at line no : %d  Variable/array of same name already exits\n\n",line_count);
						error_count++;
					}
					
				}
			}
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 388 "1605084.y" /* yacc.c:1646  */
    {
				fprintf(logout,"At line no : %d func_definition : type_specifier ID LPAREN RPAREN compound_statement\n",line_count);

				(yyval.symbol) = new SymbolInfo();
				string s = (yyvsp[-4].symbol)->get_symbol_name()+(yyvsp[-3].symbol)->get_symbol_name()+"()\n"+(yyvsp[0].symbol)->get_symbol_name();
				(yyval.symbol)->set_symbol_name(s);
				fprintf(logout,"%s\n\n",s.c_str());


				SymbolInfo* symb = symbolTable.lookUp((yyvsp[-3].symbol)->get_symbol_name());

				if(symb == NULL) //function not found
				{
					SymbolInfo* symb = new SymbolInfo();
					symb->set_symbol_name((yyvsp[-3].symbol)->get_symbol_name());
					symb->set_symbol_type((yyvsp[-4].symbol)->get_symbol_type());
					symb->set_symbol_class("FUNCTION");
					symb->is_function_defined = true;
					symb->is_function_declared = true;

					symbolTable.insert(symb);

					parameter_list_vector.clear();
				}
				else
				{
					if(symb->get_symbol_class() == "FUNCTION")
					{
						//previously not defined
						if(symb->is_function_defined == false && symb->is_function_declared == true)
						{
							int check_error = 0;
							if(symb->get_symbol_type() != (yyvsp[-4].symbol)->get_symbol_type())
							{
								fprintf(errorout,"Error at line no : %d  Function Return Type Mismatch\n\n",line_count);
								error_count++;
								check_error = 1;
							}
							if(symb->para_list.size() != parameter_list_vector.size())
							{
								fprintf(errorout,"Error at line no : %d  Conflict in number of parameters of function : %s \n\n",line_count,symb->get_symbol_name().c_str());
								error_count++;
								check_error = 1;
							}
							if(parameter_list_vector.size() == symb->para_list.size())
							{
								for(int i=0;i<parameter_list_vector.size();i++)
								{
									if(parameter_list_vector[i].first != symb->para_list[i].first)
									{
										fprintf(errorout,"Error at line no : %d  Function Parameter Mismatch\n\n",line_count);
										error_count++;
										check_error = 1;	
									}
								}
							}
					
							for(int i=0;i<parameter_list_vector.size();i++)
							{
								if(parameter_list_vector[i].first == "VOID")
								{
									fprintf(errorout,"Error at line no : %d  Function parameter can't be void\n\n",line_count);
									error_count++;
									check_error = 1;
								}
							}
							
							if(check_error == 0)
							{
								symbolTable.lookUp((yyvsp[-3].symbol)->get_symbol_name())->is_function_defined = true;
							}

						}
						else if(symb->is_function_defined == true)
						{
							fprintf(errorout,"Error at line no : %d  Function already defined.\n\n",line_count);
							error_count++;
						}	
						parameter_list_vector.clear();
						
					}
					else
					{
						fprintf(errorout,"Error at line no : %d  Variable/array of same name already exits\n\n",line_count);
						error_count++;
					}
					
				}
				
			}
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 482 "1605084.y" /* yacc.c:1646  */
    {
				fprintf(logout,"At line no : %d parameter_list : parameter_list COMMA type_specifier ID\n",line_count);

				(yyval.symbol) = new SymbolInfo();
				string s = (yyvsp[-3].symbol)->get_symbol_name()+","+(yyvsp[-1].symbol)->get_symbol_name()+(yyvsp[0].symbol)->get_symbol_name();
				(yyval.symbol)->set_symbol_name(s);
				fprintf(logout,"%s\n\n",s.c_str());

				parameter_list_vector.push_back(make_pair((yyvsp[-1].symbol)->get_symbol_type(),(yyvsp[0].symbol)->get_symbol_name()));


			}
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 495 "1605084.y" /* yacc.c:1646  */
    {
				fprintf(logout,"At line no : %d parameter_list : parameter_list COMMA type_specifier\n",line_count);

				(yyval.symbol) = new SymbolInfo();
				string s = (yyvsp[-2].symbol)->get_symbol_name()+","+(yyvsp[0].symbol)->get_symbol_name();
				(yyval.symbol)->set_symbol_name(s);
				fprintf(logout,"%s\n\n",s.c_str());

				parameter_list_vector.push_back(make_pair((yyvsp[0].symbol)->get_symbol_type(),"NIL"));
			}
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 506 "1605084.y" /* yacc.c:1646  */
    {
				fprintf(logout,"At line no : %d parameter_list : type_specifier ID\n",line_count);

				(yyval.symbol) = new SymbolInfo();
				string s = (yyvsp[-1].symbol)->get_symbol_name()+(yyvsp[0].symbol)->get_symbol_name();
				(yyval.symbol)->set_symbol_name(s);
				fprintf(logout,"%s\n\n",s.c_str());

				parameter_list_vector.push_back(make_pair((yyvsp[-1].symbol)->get_symbol_type(),(yyvsp[0].symbol)->get_symbol_name()));
			}
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 517 "1605084.y" /* yacc.c:1646  */
    {
				fprintf(logout,"At line no : %d parameter_list : type_specifier\n",line_count);

				(yyval.symbol) = new SymbolInfo();
				string s = (yyvsp[0].symbol)->get_symbol_name();
				(yyval.symbol)->set_symbol_name(s);
				fprintf(logout,"%s\n\n",s.c_str());

				parameter_list_vector.push_back(make_pair((yyvsp[0].symbol)->get_symbol_type(),"NIL"));

			}
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 531 "1605084.y" /* yacc.c:1646  */
    {
					symbolTable.enterScope(10);

					for(int i=0;i<parameter_list_vector.size();i++)
					{
						SymbolInfo* symb = new SymbolInfo();
						symb->set_symbol_type(parameter_list_vector[i].first);
						symb->set_symbol_name(parameter_list_vector[i].second);
						symb->set_symbol_class("VARIABLE");
						symbolTable.insert(symb);
					}
				}
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 543 "1605084.y" /* yacc.c:1646  */
    {
				fprintf(logout,"At line no : %d compound_statement : LCURL statements RCURL\n",line_count);

				(yyval.symbol) = new SymbolInfo();	
				string s = "{\n"+(yyvsp[-1].symbol)->get_symbol_name()+"\n}\n";
				(yyval.symbol)->set_symbol_name(s);
				fprintf(logout,"%s\n\n",s.c_str());

				
				symbolTable.printAll();
				symbolTable.exitScope();
			}
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 556 "1605084.y" /* yacc.c:1646  */
    {
				fprintf(logout,"At line no : %d compound_statement : LCURL RCURL\n",line_count);
				(yyval.symbol) = new SymbolInfo();
				string s = "{}\n";
				(yyval.symbol)->set_symbol_name(s);
				fprintf(logout,"%s\n\n",s.c_str());

			}
#line 1960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 567 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d var_declaration : type_specifier declaration_list SEMICOLON\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[-2].symbol)->get_symbol_name()+(yyvsp[-1].symbol)->get_symbol_name()+";";
			(yyval.symbol)->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());


			for(int i=0;i<declaration_list_vector.size();i++)
			{
				declaration_list_vector[i]->set_symbol_type((yyvsp[-2].symbol)->get_symbol_type());
					
			}

			for(int i=0;i<declaration_list_vector.size();i++)
			{
				declaration_list_vector[i]->set_symbol_type((yyvsp[-2].symbol)->get_symbol_type());
			}

			for(int i=0;i<declaration_list_vector.size();i++)
			{
				if(declaration_list_vector[i]->get_symbol_type() == "VOID")
				{
					fprintf(errorout,"Error at line no : %d  Variable/Array type can't be void\n\n",line_count);
					error_count++;
					continue;
				}
				else if(symbolTable.insert(declaration_list_vector[i]) == true)
				{

				}
				else if(symbolTable.insert(declaration_list_vector[i]) == false)
				{
					error_count++;
					fprintf(errorout,"Error at line no : %d  Multiple declaration of variable/array %s\n\n",line_count,declaration_list_vector[i]->get_symbol_name().c_str());
				}
			}
			declaration_list_vector.clear();

		}
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 611 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d type_specifier : INT\n",line_count);
			
			SymbolInfo* s = new SymbolInfo();
			s->set_symbol_name("int ");
			s->set_symbol_type("INT");
			(yyval.symbol) = s;
			fprintf(logout,"%s\n\n",(yyval.symbol)->get_symbol_name().c_str());
			
		}
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 622 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d type_specifier : FLOAT\n",line_count);

			SymbolInfo* s = new SymbolInfo();
			s->set_symbol_name("float ");
			s->set_symbol_type("FLOAT");
			(yyval.symbol) = s;
			fprintf(logout,"%s \n\n",(yyval.symbol)->get_symbol_name().c_str());
		}
#line 2035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 632 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d type_specifier : VOID\n",line_count);
			
			SymbolInfo* s = new SymbolInfo();
			s->set_symbol_name("void ");
			s->set_symbol_type("VOID");
			(yyval.symbol) = s;
			fprintf(logout,"%s \n\n",(yyval.symbol)->get_symbol_name().c_str());
		}
#line 2049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 644 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d declaration_list : declaration_list COMMA ID\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[-2].symbol)->get_symbol_name()+","+(yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			
			SymbolInfo* symb = new SymbolInfo();
			symb->set_symbol_name((yyvsp[0].symbol)->get_symbol_name());
			symb->set_symbol_class("VARIABLE"); 

			declaration_list_vector.push_back(symb);

				
		}
#line 2071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 662 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[-5].symbol)->get_symbol_name()+","+(yyvsp[-3].symbol)->get_symbol_name()+"["+(yyvsp[-1].symbol)->get_symbol_name()+"]";
			(yyval.symbol)->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			SymbolInfo* symb = new SymbolInfo();
			symb->set_symbol_class("ARRAY");
			symb->set_symbol_name((yyvsp[-3].symbol)->get_symbol_name());
			symb->ara_size = atoi((yyvsp[-1].symbol)->get_symbol_name().c_str());

			declaration_list_vector.push_back(symb);


		}
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 680 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d declaration_list : ID\n",line_count);
			
			(yyval.symbol) = new SymbolInfo();
			(yyval.symbol)->set_symbol_name((yyvsp[0].symbol)->get_symbol_name());
			fprintf(logout,"%s\n\n",(yyval.symbol)->get_symbol_name().c_str());
			

			SymbolInfo* symb = new SymbolInfo();
			symb->set_symbol_name((yyvsp[0].symbol)->get_symbol_name());
			symb->set_symbol_class("VARIABLE"); 

			declaration_list_vector.push_back(symb);	
			
		}
#line 2113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 696 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d declaration_list : ID LTHIRD CONST_INT RTHIRD\n",line_count);
			
			(yyval.symbol) = new SymbolInfo();
			(yyval.symbol)->set_symbol_name((yyvsp[-3].symbol)->get_symbol_name()+"["+(yyvsp[-1].symbol)->get_symbol_name()+"]");
			fprintf(logout,"%s\n\n",(yyval.symbol)->get_symbol_name().c_str());

			SymbolInfo* symb = new SymbolInfo();
			symb->set_symbol_class("ARRAY");
			symb->set_symbol_name((yyvsp[-3].symbol)->get_symbol_name());
			symb->ara_size = atoi((yyvsp[-1].symbol)->get_symbol_name().c_str());

			declaration_list_vector.push_back(symb);
		}
#line 2132 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 713 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d statements : statement\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());
		}
#line 2145 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 722 "1605084.y" /* yacc.c:1646  */
    {
				fprintf(logout,"At line no : %d statements : statements statement\n",line_count);

				(yyval.symbol) = new SymbolInfo();
				string s = (yyvsp[-1].symbol)->get_symbol_name()+"\n"+(yyvsp[0].symbol)->get_symbol_name();
				(yyval.symbol)->set_symbol_name(s);
				fprintf(logout,"%s\n\n",s.c_str());
		}
#line 2158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 733 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d statement : var_declaration\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());
		}
#line 2171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 742 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d statement : expression_statement\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());
		}
#line 2184 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 751 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d statement : compound_statement\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());
		}
#line 2197 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 760 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = "for("+(yyvsp[-4].symbol)->get_symbol_name()+" "+(yyvsp[-3].symbol)->get_symbol_name()+" "+(yyvsp[-2].symbol)->get_symbol_name()+")\n"+(yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			if((yyvsp[-4].symbol)->get_symbol_type() == "VOID" || (yyvsp[-3].symbol)->get_symbol_type() == "VOID" || (yyvsp[-2].symbol)->get_symbol_type() == "VOID")
			{
				fprintf(errorout,"Error at line no : %d   Type Mismatch \n\n",line_count);
				error_count++;
			} 
		}
#line 2216 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 775 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d statement : IF LPAREN expression RPAREN statement\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = "if("+(yyvsp[-2].symbol)->get_symbol_name()+")\n"+(yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			
			if((yyvsp[-2].symbol)->get_symbol_type() == "VOID")
			{
				fprintf(errorout,"Error at line no : %d   Type Mismatch \n\n",line_count);
				error_count++;
			}
		}
#line 2236 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 791 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d statement : IF LPAREN expression RPAREN statement ELSE statement\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = "if("+(yyvsp[-4].symbol)->get_symbol_name()+")\n"+"else\n"+(yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			if((yyvsp[-4].symbol)->get_symbol_type() == "VOID")
			{
				fprintf(errorout,"Error at line no : %d   Type Mismatch \n\n",line_count);
				error_count++;
			}
		}
#line 2255 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 806 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d statement : WHILE LPAREN expression RPAREN statement\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = "while("+(yyvsp[-2].symbol)->get_symbol_name()+")\n"+(yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			if((yyvsp[-2].symbol)->get_symbol_type() == "VOID")
			{
				fprintf(errorout,"Error at line no : %d   Type Mismatch \n\n",line_count);
				error_count++;
			}		
		}
#line 2274 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 821 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = "\n ("+(yyvsp[-2].symbol)->get_symbol_name()+");";
			(yyval.symbol)->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());
		}
#line 2287 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 830 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d statement : RETURN expression SEMICOLON\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s ="return "+(yyvsp[-1].symbol)->get_symbol_name()+";";
			(yyval.symbol)->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			if((yyvsp[-1].symbol)->get_symbol_type() == "VOID")
			{
				fprintf(errorout,"Error at line no : %d   Type mismatch(return type can't be void) \n\n",line_count);
				error_count++;
			}

		}
#line 2307 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 848 "1605084.y" /* yacc.c:1646  */
    {
				fprintf(logout,"At line no : %d expression_statement : SEMICOLON\n",line_count);

				(yyval.symbol) = new SymbolInfo();
				(yyval.symbol)->set_symbol_name(";");
				fprintf(logout,"; \n\n");	
			}
#line 2319 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 856 "1605084.y" /* yacc.c:1646  */
    {
				fprintf(logout,"At line no : %d expression_statement : expression SEMICOLON\n",line_count);
				
				(yyval.symbol) = new SymbolInfo();
				string s = (yyvsp[-1].symbol)->get_symbol_name()+";";
				(yyval.symbol)->set_symbol_name(s);
				fprintf(logout,"%s\n\n",s.c_str());

			}
#line 2333 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 868 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d variable : ID\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			SymbolInfo* check = symbolTable.lookUp((yyvsp[0].symbol)->get_symbol_name());
			
			if(check != NULL)
			{
				(yyval.symbol)->set_symbol_type(check->get_symbol_type());
				if(check->get_symbol_class() != "VARIABLE")
				{
					error_count++;
					fprintf(errorout,"Error at line no : %d   Type mismatch(%s is not a variable)\n\n",line_count,check->get_symbol_name().c_str());
				}
			}
			else if(check == NULL)
			{
				error_count++;
				fprintf(errorout,"Error at line no : %d  Undeclared variable %s\n\n",line_count,(yyvsp[0].symbol)->get_symbol_name().c_str());
				(yyval.symbol)->set_symbol_type("INT");
			}
			//seg fault
			
			
			
		}
#line 2368 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 899 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d variable : ID LTHIRD expression RTHIRD\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[-3].symbol)->get_symbol_name()+"["+(yyvsp[-1].symbol)->get_symbol_name()+"]";
			(yyval.symbol)->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			SymbolInfo* check = symbolTable.lookUp((yyvsp[-3].symbol)->get_symbol_name());

			if(check != NULL)
			{
				(yyval.symbol)->set_symbol_type(check->get_symbol_type());
				if((yyvsp[-1].symbol)->get_symbol_type() != "INT")
				{
					error_count++;
					fprintf(errorout,"Error at line : %d   Non-integer Array Index\n\n",line_count);

				}
				//seg fault
				else if(check->get_symbol_class() != "ARRAY")
				{
					error_count++;
					fprintf(errorout,"Error at line no : %d   Type mismatch(%s is not an array)\n\n",line_count,check->get_symbol_name().c_str());
				}
				/*cout<<$3->get_symbol_name()<<endl;
				int size = atoi($3->get_symbol_name().c_str());
				cout<<check->ara_size<<endl;
				if(size > check->ara_size)
				{
					error_count++;
					fprintf(errorout,"Error at line no : %d   Array index out of bound\n\n",line_count);
				}*/
			}
			else if(check == NULL)
			{	
				(yyval.symbol)->set_symbol_type("INT");
				error_count++;
				fprintf(errorout,"Error at line no : %d  Undeclared array %s\n\n",line_count,(yyvsp[-3].symbol)->get_symbol_name().c_str());
			}
				
		}
#line 2415 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 945 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d expression : logic_expression\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			(yyval.symbol)->set_symbol_type((yyvsp[0].symbol)->get_symbol_type());		
		}
#line 2430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 956 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d expression : variable ASSIGNOP logic_expression\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[-2].symbol)->get_symbol_name()+" = "+(yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());


			if((yyvsp[-2].symbol)->get_symbol_type() != (yyvsp[0].symbol)->get_symbol_type())
			{
				fprintf(errorout,"Error at line no : %d  Type mismatch(ASSIGNOP)\n\n",line_count);
				error_count++;
			}

			if((yyvsp[0].symbol)->get_symbol_type() == "VOID")
			{	
				fprintf(errorout,"Error at line no : %d   Void type can't be assigned to a variable\n\n",line_count);
				error_count++;
			}
			else if((yyvsp[-2].symbol)->get_symbol_type()=="INT" && (yyvsp[0].symbol)->get_symbol_type()=="FLOAT")
			{
				fprintf(errorout,"Error at line no : %d  Floating point number is assigned to an integer type variable\n\n",line_count);
				error_count++;
				(yyval.symbol)->set_symbol_type("INT");
			}
			else if((yyvsp[-2].symbol)->get_symbol_type()=="FLOAT" && (yyvsp[0].symbol)->get_symbol_type()=="INT")
			{
				fprintf(errorout,"Error at line no : %d  Integer number is assigned to an floating point type variable\n\n",line_count);
				error_count++;
				(yyval.symbol)->set_symbol_type("FLOAT");
			}
			else
			{
				(yyval.symbol)->set_symbol_type("INT");
			}		
		}
#line 2472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 996 "1605084.y" /* yacc.c:1646  */
    {
				fprintf(logout,"At line no : %d logic_expression : rel_expression\n",line_count);
			
				(yyval.symbol) = new SymbolInfo();
				string s = (yyvsp[0].symbol)->get_symbol_name();
				(yyval.symbol)->set_symbol_name(s);
				fprintf(logout,"%s\n\n",s.c_str());

				(yyval.symbol)->set_symbol_type((yyvsp[0].symbol)->get_symbol_type());

					
			}
#line 2489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 1009 "1605084.y" /* yacc.c:1646  */
    {
				fprintf(logout,"At line no : %d logic_expression : rel_expression LOGICOP rel_expression\n",line_count);
			
				(yyval.symbol) = new SymbolInfo();
				string s = (yyvsp[-2].symbol)->get_symbol_name()+" "+(yyvsp[-1].symbol)->get_symbol_name()+" "+(yyvsp[0].symbol)->get_symbol_name();
				(yyval.symbol)->set_symbol_name(s);
				fprintf(logout,"%s\n\n",s.c_str());

				(yyval.symbol)->set_symbol_type("INT");

				if((yyvsp[-2].symbol)->get_symbol_type()=="INT" && (yyvsp[0].symbol)->get_symbol_type()=="FLOAT")
				{
					fprintf(errorout,"Error at line no : %d  Type conversion to integer(LOGICOP)\n\n",line_count);
					error_count++;
				}
				else if((yyvsp[-2].symbol)->get_symbol_type()=="FLOAT" && (yyvsp[0].symbol)->get_symbol_type()=="INT")
				{
					fprintf(errorout,"Error at line no : %d  Type conversion to integer(LOGICOP)\n\n",line_count);
					error_count++;
				}
			}
#line 2515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 1033 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d rel_expression : simple_expression\n",line_count);
		
			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			(yyval.symbol)->set_symbol_type((yyvsp[0].symbol)->get_symbol_type());
		}
#line 2530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 1044 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d rel_expression : simple_expression RELOP simple_expression\n",line_count);
		
			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[-2].symbol)->get_symbol_name()+" "+(yyvsp[-1].symbol)->get_symbol_name()+" "+(yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			(yyval.symbol)->set_symbol_type("INT");

			if((yyvsp[-2].symbol)->get_symbol_type()=="INT" && (yyvsp[0].symbol)->get_symbol_type()=="FLOAT")
			{
				fprintf(errorout,"Error at line no : %d  Type conversion to integer(RELOP)\n\n",line_count);
				error_count++;
				
			}
			else if((yyvsp[-2].symbol)->get_symbol_type()=="FLOAT" && (yyvsp[0].symbol)->get_symbol_type()=="INT")
			{
				fprintf(errorout,"Error at line no : %d  Type conversion to integer(RELOP)\n\n",line_count);
				error_count++;
			}
		}
#line 2557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 1069 "1605084.y" /* yacc.c:1646  */
    {
				fprintf(logout,"At line no : %d simple_expression : term\n",line_count);

				(yyval.symbol) = new SymbolInfo();
				string s = (yyvsp[0].symbol)->get_symbol_name();
				(yyval.symbol)->set_symbol_name(s);
				fprintf(logout,"%s\n\n",s.c_str());

				(yyval.symbol)->set_symbol_type((yyvsp[0].symbol)->get_symbol_type());
			}
#line 2572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 1080 "1605084.y" /* yacc.c:1646  */
    {
				fprintf(logout,"At line no : %d simple_expression : simple_expression ADDOP term\n",line_count);

				(yyval.symbol) = new SymbolInfo();
				string s = (yyvsp[-2].symbol)->get_symbol_name()+" "+(yyvsp[-1].symbol)->get_symbol_name()+" "+(yyvsp[0].symbol)->get_symbol_name();
				(yyval.symbol)->set_symbol_name(s);
				fprintf(logout,"%s\n\n",s.c_str());
				
				if((yyvsp[-2].symbol)->get_symbol_type() == "VOID" || (yyvsp[0].symbol)->get_symbol_type() == "VOID")
				{
					fprintf(errorout,"Error at line no : %d  Type mismatch(Void type can't be used in ADD operations)\n\n",line_count);
					error_count++;
					(yyval.symbol)->set_symbol_type("INT");
				}
				if((yyvsp[-2].symbol)->get_symbol_type() == "FLOAT" || (yyvsp[0].symbol)->get_symbol_type() == "FLOAT")
				{
					(yyval.symbol)->set_symbol_type("FLOAT");	
				}
				else
				{
					(yyval.symbol)->set_symbol_type("INT");
				}
								
			}
#line 2601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 1107 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d term : unary_expression\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			(yyval.symbol)->set_symbol_type((yyvsp[0].symbol)->get_symbol_type());
		
		}
#line 2617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 1119 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d term : term MULOP unary_expression\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[-2].symbol)->get_symbol_name()+" "+(yyvsp[-1].symbol)->get_symbol_name()+" "+(yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());


			if((yyvsp[-2].symbol)->get_symbol_type() == "VOID" || (yyvsp[0].symbol)->get_symbol_type() == "VOID")
			{
				fprintf(errorout,"Error at line no : %d  Type mismatch(Void type can't be used in MUL operations)\n\n",line_count);
				error_count++;
				//confused
				(yyval.symbol)->set_symbol_type("INT");
			}
			else if((yyvsp[-1].symbol)->get_symbol_name() == "%")
			{
				if((yyvsp[-2].symbol)->get_symbol_type() == "FLOAT" || (yyvsp[0].symbol)->get_symbol_type() == "FLOAT")
				{
					fprintf(errorout,"Error at line no : %d  Both operand of modulus operator should be integer. \n\n",line_count);
					(yyval.symbol)->set_symbol_type("INT");
					error_count++;
				}
			} 
			else
			{
				if((yyvsp[-2].symbol)->get_symbol_type() == "FLOAT" || (yyvsp[0].symbol)->get_symbol_type() == "FLOAT")
				{
					//cout<<"hi float"<<endl;
					(yyval.symbol)->set_symbol_type("FLOAT");
				}
				else if((yyvsp[-2].symbol)->get_symbol_type() == "INT" && (yyvsp[0].symbol)->get_symbol_type() == "INT")
				{
					//cout<<"hi int"<<endl;
					(yyval.symbol)->set_symbol_type("INT");
				}
			}
		}
#line 2661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 1161 "1605084.y" /* yacc.c:1646  */
    {
				fprintf(logout,"At line no : %d unary_expression : ADDOP unary_expression\n",line_count);

				(yyval.symbol) = new SymbolInfo();
				string s = (yyvsp[-1].symbol)->get_symbol_name()+(yyvsp[0].symbol)->get_symbol_name();
				(yyval.symbol)->set_symbol_name(s);
				fprintf(logout,"%s\n\n",s.c_str());
				
				if((yyvsp[0].symbol)->get_symbol_type() == "VOID")
				{
					fprintf(errorout,"Error at line no : %d  Type mismatch(ADDOP)\n\n",line_count);
					error_count++;
					(yyval.symbol)->set_symbol_type("INT");
				}
				else
				{
					(yyval.symbol)->set_symbol_type((yyvsp[0].symbol)->get_symbol_type());
				}
				
			}
#line 2686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 1182 "1605084.y" /* yacc.c:1646  */
    {
				fprintf(logout,"At line no : %d unary_expression : NOT unary_expression\n",line_count);

				(yyval.symbol) = new SymbolInfo();
				string s = "!"+(yyvsp[0].symbol)->get_symbol_name();
				(yyval.symbol)->set_symbol_name(s);
				fprintf(logout,"%s\n\n",s.c_str());

				if((yyvsp[0].symbol)->get_symbol_type() == "VOID")
				{
					fprintf(errorout,"Error at line no : %d  Type mismatch(NOT)\n\n",line_count);
					error_count++;
					(yyval.symbol)->set_symbol_type("INT");
				}
				else
				{
					(yyval.symbol)->set_symbol_type((yyvsp[0].symbol)->get_symbol_type());
				}
			}
#line 2710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 1202 "1605084.y" /* yacc.c:1646  */
    {
				fprintf(logout,"At line no : %d unary_expression : factor\n",line_count);

				(yyval.symbol) = new SymbolInfo();
				string s = (yyvsp[0].symbol)->get_symbol_name();
				(yyval.symbol)->set_symbol_name(s);
				fprintf(logout,"%s\n\n",s.c_str());

				
				(yyval.symbol)->set_symbol_type((yyvsp[0].symbol)->get_symbol_type());

			}
#line 2727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 1217 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d factor : variable\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			(yyval.symbol)->set_symbol_type((yyvsp[0].symbol)->get_symbol_type());
		}
#line 2742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1228 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d factor : ID LPAREN argument_list RPAREN\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[-3].symbol)->get_symbol_name()+"("+(yyvsp[-1].symbol)->get_symbol_name()+")";
			(yyval.symbol)->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());
	
			SymbolInfo* symb = symbolTable.lookUp((yyvsp[-3].symbol)->get_symbol_name());

			/*cout<<symb->get_symbol_name()<<endl;
			for(int i=0;i<argument_list_vector.size();i++)
			{
				cout<<argument_list_vector[i]->get_symbol_name()<<endl;
			}*/


			if(symb == NULL)
			{
				fprintf(errorout,"Error at line no : %d  Function not defined or declared before\n\n",line_count);
				error_count++;
				//confusion
				(yyval.symbol)->set_symbol_type("INT");
			}
			else if(symb->get_symbol_class() == "FUNCTION")
			{
				(yyval.symbol)->set_symbol_type(symb->get_symbol_type());
				//if(symb->is_function_defined == true)
				//{
					if(symb->para_list.size() != argument_list_vector.size())
					{
						fprintf(errorout,"Error at line no : %d  Invalid number of arguments in the function\n\n",line_count);
						error_count++;
					}
					else
					{
						for(int i=0;i<argument_list_vector.size();i++)
						{
							if(argument_list_vector[i]->get_symbol_type() != symb->para_list[i].first)
							{
								fprintf(errorout,"Error at line no : %d  Function Argument Type Mismatch\n\n",line_count);
								error_count++;
							}		
						}
					}

				//}
				/*else
				{
					fprintf(errorout,"Error at line no : %d  Function should be defined before calling\n\n",line_count);
					error_count++;
				}*/
				
				argument_list_vector.clear();
			}
			else if(symb->get_symbol_class() != "FUNCTION")
			{
				fprintf(errorout,"Error at line no : %d  It's not a function\n\n",line_count);
				error_count++;
			}
		}
#line 2808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1290 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d factor : LPAREN expression RPAREN\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = "("+(yyvsp[-1].symbol)->get_symbol_name()+")";
			(yyval.symbol)->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			(yyval.symbol)->set_symbol_type((yyvsp[-1].symbol)->get_symbol_type());
		}
#line 2823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1301 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d factor : CONST_INT\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			(yyval.symbol)->set_symbol_type("INT");		
		}
#line 2838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1312 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d factor : CONST_FLOAT\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			(yyval.symbol)->set_symbol_type("FLOAT");
		}
#line 2853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1323 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d factor : variable INCOP\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[-1].symbol)->get_symbol_name()+"++";
			(yyval.symbol)->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			(yyval.symbol)->set_symbol_type((yyvsp[-1].symbol)->get_symbol_type());
		}
#line 2868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1334 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d factor : variable DECOP\n",line_count);
		    
			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[-1].symbol)->get_symbol_name()+"--";
			(yyval.symbol)->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			(yyval.symbol)->set_symbol_type((yyvsp[-1].symbol)->get_symbol_type());
		}
#line 2883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1347 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d argument_list : arguments\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

		}
#line 2897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1357 "1605084.y" /* yacc.c:1646  */
    { 
			(yyval.symbol) = new SymbolInfo(); 
			fprintf(logout,"At line no : %d  argument_list : (empty) \n\n",line_count);
			(yyval.symbol)->set_symbol_name("");
		}
#line 2907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1365 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d arguments : arguments COMMA logic_expression\n",line_count);
			
			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[-2].symbol)->get_symbol_name()+","+(yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			SymbolInfo* symb = new SymbolInfo();
			symb->set_symbol_name((yyvsp[0].symbol)->get_symbol_name());
			symb->set_symbol_type((yyvsp[0].symbol)->get_symbol_type());
			symb->set_symbol_class("VARIABLE");//argument = variable

			
			argument_list_vector.push_back(symb);
		}
#line 2928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1382 "1605084.y" /* yacc.c:1646  */
    {
			fprintf(logout,"At line no : %d arguments : logic_expression\n",line_count);
		    
			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			SymbolInfo* symb = new SymbolInfo();
			symb->set_symbol_name((yyvsp[0].symbol)->get_symbol_name());
			symb->set_symbol_type((yyvsp[0].symbol)->get_symbol_type());
			symb->set_symbol_class("VARIABLE");

			argument_list_vector.push_back(symb);
		}
#line 2948 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2952 "y.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
  return yyresult;
}
#line 1400 "1605084.y" /* yacc.c:1906  */

int main(int argc,char *argv[])
{

	if((fp=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}
	
	errorout = fopen("1605084_error.txt","w");
    logout = fopen("1605084_log.txt","w");

	yyin=fp;
	symbolTable.enterScope(10);
	yyparse();

	fprintf(logout,"\n\nSymbol Table :\n\n");
	symbolTable.printAll();
	fprintf(logout,"\nTotal lines : %d\n",line_count);
	fprintf(logout,"\nTotal errros : %d\n",error_count);
	fprintf(errorout,"\nTotal errros : %d\n",error_count);
	fclose(fp);
	fclose(errorout);
	fclose(logout);
	
	return 0;
}

