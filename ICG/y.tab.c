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

int label_count = 0;
int temp_count = 0;

SymbolTable symbolTable;

vector<SymbolInfo*>declaration_list_vector;
vector<pair<string,string>>parameter_list_vector;
vector<SymbolInfo*>argument_list_vector;

vector<string> variable_declaration;
vector<string> func_variable_declaration;
vector<pair<string,int>> array_declarartion;//variable/function/array
string currentFunction;

void yyerror(const char *s)
{
 	fprintf(errorout,"Error at line no %d :  %s\n\n",line_count,s);
	error_count++;
}

char *newLabel()
{
	char *lb= new char[4];
	strcpy(lb,"L");
	char b[3];
	sprintf(b,"%d", label_count);
	label_count++;
	strcat(lb,b);
	return lb;
}

char *newTemp()
{
	char *t= new char[4];
	strcpy(t,"t");
	char b[3];
	sprintf(b,"%d", temp_count);
	temp_count++;
	strcat(t,b);
	return t;
}

void optimizeCode(FILE *asmfile);
void chomp( string &s);


#line 131 "y.tab.c" /* yacc.c:339  */

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
#line 66 "1605084.y" /* yacc.c:355  */

        SymbolInfo* symbol;

#line 259 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 276 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   143

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  121

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
       0,    96,    96,   182,   191,   202,   212,   221,   232,   325,
     387,   386,   560,   559,   731,   744,   755,   766,   781,   781,
     811,   827,   874,   885,   895,   907,   925,   942,   958,   975,
     986,   999,  1008,  1018,  1028,  1061,  1088,  1119,  1149,  1174,
    1205,  1213,  1228,  1261,  1321,  1334,  1389,  1404,  1472,  1485,
    1554,  1568,  1611,  1625,  1705,  1735,  1761,  1778,  1805,  1876,
    1889,  1908,  1926,  1962,  2000,  2013,  2020,  2040
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
  "func_definition", "$@1", "$@2", "parameter_list", "compound_statement",
  "$@3", "var_declaration", "type_specifier", "declaration_list",
  "statements", "statement", "expression_statement", "variable",
  "expression", "logic_expression", "rel_expression", "simple_expression",
  "term", "unary_expression", "factor", "argument_list", "arguments", YY_NULLPTR
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

#define YYPACT_NINF -63

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-63)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      15,   -63,   -63,   -63,    18,    15,   -63,   -63,   -63,   -63,
      -2,   -63,   -63,     1,    42,    91,    16,   -63,    26,     0,
     -17,    47,    23,    17,   -63,    31,    32,    15,   -63,   -63,
      70,    51,   -63,   -63,    31,    73,    45,   -63,   101,   -63,
     -63,   -63,    14,   -63,   -63,     9,    62,    64,    67,     9,
       9,   -63,     9,    68,   -63,   -63,    88,    63,   -63,   -63,
      43,    72,   -63,    92,    44,    99,   -63,   -63,     9,     9,
      60,   -63,     9,    53,     9,    75,    85,   -63,   115,    84,
     -63,   -63,   -63,   -63,     9,   -63,     9,     9,     9,     9,
     -63,    90,    89,    93,    94,    53,    96,   -63,   -63,    98,
     -63,   -63,    99,   124,   -63,   -63,     9,   -63,   101,     9,
     101,   100,   -63,   120,   103,   -63,   -63,   101,   101,   -63,
     -63
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    22,    23,    24,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    27,     0,     0,     0,    21,     0,    12,
       0,    17,     0,    25,     9,     0,    10,     0,    16,    28,
       0,    18,    13,     8,     0,    15,     0,    20,     0,    11,
      14,    26,    42,    60,    61,     0,     0,     0,     0,     0,
       0,    40,     0,     0,    33,    31,     0,     0,    29,    32,
      57,     0,    44,    46,    48,    50,    52,    56,    65,     0,
      57,    54,     0,     0,     0,     0,     0,    55,     0,    27,
      19,    30,    62,    63,     0,    41,     0,     0,     0,     0,
      67,     0,    64,     0,     0,     0,     0,    39,    59,     0,
      45,    47,    51,    49,    53,    58,     0,    43,     0,     0,
       0,     0,    66,    35,     0,    37,    38,     0,     0,    36,
      34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -63,   -63,   -63,   131,   -63,   -63,   -63,   -63,   -63,    -8,
     -63,    22,     4,   -63,   -63,   -55,   -62,   -45,   -44,   -60,
      56,    55,    52,   -42,   -63,   -63,   -63
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    34,    25,    20,    54,
      38,    55,    56,    14,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    91,    92
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      70,    13,    81,    71,    10,    75,    76,    70,    90,    10,
      77,    95,    42,    43,    44,    26,    45,    32,    11,    21,
      22,    27,     9,    70,   100,    93,    39,     9,    94,    23,
      96,    35,    15,   109,     1,     2,    16,    24,     3,    70,
      50,    70,    70,    70,    70,    68,   112,   104,    52,    69,
      28,    87,    30,   113,    88,   115,    42,    43,    44,    29,
      45,    70,   119,   120,    31,   114,    42,    43,    44,    33,
      45,    82,    83,    84,    36,    46,    40,    47,    48,    17,
      18,    41,     1,     2,    50,    37,     3,    49,    82,    83,
      51,    79,    52,    72,    50,    73,    31,    80,    74,    78,
      51,    86,    52,    53,    42,    43,    44,    89,    45,    85,
       1,     2,    97,    46,     3,    47,    48,    98,    99,    16,
       1,     2,   105,    19,     3,    49,   108,   106,   110,   107,
     111,    87,    50,   117,    31,   118,    12,   116,    51,   102,
      52,    53,   101,   103
};

static const yytype_uint8 yycheck[] =
{
      45,     3,    57,    45,     0,    49,    50,    52,    68,     5,
      52,    73,     3,     4,     5,    32,     7,    25,     0,    15,
       4,    38,     0,    68,    84,    69,    34,     5,    72,     3,
      74,    27,    31,    95,    19,    20,    35,    37,    23,    84,
      31,    86,    87,    88,    89,    31,   106,    89,    39,    35,
       3,     7,    35,   108,    10,   110,     3,     4,     5,    36,
       7,   106,   117,   118,    33,   109,     3,     4,     5,    37,
       7,    28,    29,    30,     4,    12,     3,    14,    15,    37,
      38,    36,    19,    20,    31,    34,    23,    24,    28,    29,
      37,     3,    39,    31,    31,    31,    33,    34,    31,    31,
      37,     9,    39,    40,     3,     4,     5,     8,     7,    37,
      19,    20,    37,    12,    23,    14,    15,    32,     3,    35,
      19,    20,    32,    32,    23,    24,    32,    38,    32,    36,
      32,     7,    31,    13,    33,    32,     5,    37,    37,    87,
      39,    40,    86,    88
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    19,    20,    23,    44,    45,    46,    47,    48,    54,
      55,     0,    46,     3,    56,    31,    35,    37,    38,    32,
      51,    55,     4,     3,    37,    50,    32,    38,     3,    36,
      35,    33,    52,    37,    49,    55,     4,    34,    53,    52,
       3,    36,     3,     4,     5,     7,    12,    14,    15,    24,
      31,    37,    39,    40,    52,    54,    55,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    31,    35,
      60,    66,    31,    31,    31,    61,    61,    66,    31,     3,
      34,    58,    28,    29,    30,    37,     9,     7,    10,     8,
      62,    68,    69,    61,    61,    59,    61,    37,    32,     3,
      62,    63,    65,    64,    66,    32,    38,    36,    32,    59,
      32,    32,    62,    58,    61,    58,    37,    13,    32,    58,
      58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    46,    47,    47,
      49,    48,    50,    48,    51,    51,    51,    51,    53,    52,
      52,    54,    55,    55,    55,    56,    56,    56,    56,    57,
      57,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      59,    59,    60,    60,    61,    61,    62,    62,    63,    63,
      64,    64,    65,    65,    66,    66,    66,    67,    67,    67,
      67,    67,    67,    67,    68,    68,    69,    69
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       0,     7,     0,     6,     4,     3,     2,     1,     0,     4,
       2,     3,     1,     1,     1,     3,     6,     1,     4,     1,
       2,     1,     1,     1,     7,     5,     7,     5,     5,     3,
       1,     2,     1,     4,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     2,     2,     1,     1,     4,     3,
       1,     1,     2,     2,     1,     0,     3,     1
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
#line 97 "1605084.y" /* yacc.c:1646  */
    {
		//fprintf(logout,"At line no : %d start : program\n",line_count);

		//fprintf(logout,"%s\n\n",$1->get_symbol_name().c_str());
		(yyval.symbol) = new SymbolInfo();
		(yyval.symbol)->set_symbol_name((yyvsp[0].symbol)->get_symbol_name());

		if(error_count == 0)
		{
			string temp_code = "";
			temp_code += ".MODEL SMALL\n";
			temp_code += ".STACK 100H\n";
			temp_code += ".DATA \n";

			for(int i=0;i<variable_declaration.size();i++)
			{
				temp_code += variable_declaration[i]+" dw ?\n";
			}

			for(int i=0;i<array_declarartion.size();i++)
			{
				temp_code += array_declarartion[i].first+" dw "+to_string(array_declarartion[i].second)+" dup(?)\n";
			}

			(yyvsp[0].symbol)->code = temp_code + ".CODE\n"+(yyvsp[0].symbol)->code;
			
			(yyvsp[0].symbol)->code += "OUTDEC PROC\n";
			(yyvsp[0].symbol)->code += "PUSH AX\n";
			(yyvsp[0].symbol)->code += "PUSH BX\n";
			(yyvsp[0].symbol)->code += "PUSH CX\n";
			(yyvsp[0].symbol)->code += "PUSH DX\n";
			(yyvsp[0].symbol)->code += "CMP AX, 0\n";
			(yyvsp[0].symbol)->code += "JGE BEGIN\n";
			(yyvsp[0].symbol)->code += "PUSH AX\n";
			(yyvsp[0].symbol)->code += "MOV DL, '-'\n";
			(yyvsp[0].symbol)->code += "MOV AH, 2\n";
			(yyvsp[0].symbol)->code += "INT 21H\n";
			(yyvsp[0].symbol)->code += "POP AX\n";
			(yyvsp[0].symbol)->code += "NEG AX\n\n";

			(yyvsp[0].symbol)->code += "BEGIN:\n";
			(yyvsp[0].symbol)->code += "XOR CX, CX\n";
			(yyvsp[0].symbol)->code += "MOV BX, 10\n\n";

			(yyvsp[0].symbol)->code += "REPEATATION:\n";
			(yyvsp[0].symbol)->code += "XOR DX, DX\n";
			(yyvsp[0].symbol)->code += "DIV BX\n";
			(yyvsp[0].symbol)->code += "PUSH DX\n";
			(yyvsp[0].symbol)->code += "INC CX\n";
			(yyvsp[0].symbol)->code += "OR AX, AX\n";
			(yyvsp[0].symbol)->code += "JNE REPEATATION\n";
			(yyvsp[0].symbol)->code += "MOV AH, 2\n\n";

			(yyvsp[0].symbol)->code += "LOOP_PRINT:\n";
			(yyvsp[0].symbol)->code += "POP DX\n";
			(yyvsp[0].symbol)->code += "ADD DL, 30H\n";
			(yyvsp[0].symbol)->code += "INT 21H\n";
			(yyvsp[0].symbol)->code += "LOOP LOOP_PRINT\n\n";

			(yyvsp[0].symbol)->code += "MOV AH, 2\n";
			(yyvsp[0].symbol)->code += "MOV DL, 10\n";
			(yyvsp[0].symbol)->code += "INT 21H\n\n";

			(yyvsp[0].symbol)->code += "MOV DL, 13\n";
			(yyvsp[0].symbol)->code += "INT 21H\n\n";

			(yyvsp[0].symbol)->code += "POP DX\n";
			(yyvsp[0].symbol)->code += "POP CX\n";
			(yyvsp[0].symbol)->code += "POP BX\n";
			(yyvsp[0].symbol)->code += "POP AX\n";

			(yyvsp[0].symbol)->code += "RET\n";
			(yyvsp[0].symbol)->code += "OUTDEC ENDP\n";
			(yyvsp[0].symbol)->code += "END MAIN\n\n";

			FILE *asmfile = fopen("1605084_code.asm","w");
			fprintf(asmfile,"%s\n",(yyvsp[0].symbol)->code.c_str());
			fclose(asmfile);
			//add optimization later
			asmfile = fopen("1605084_code.asm","r");
			optimizeCode(asmfile);
		}
	}
#line 1527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 183 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d program : program unit\n",line_count);
			
			//fprintf(logout,"%s\n%s\n\n",$1->get_symbol_name().c_str(),$2->get_symbol_name().c_str());
			(yyval.symbol) = new SymbolInfo();
			(yyval.symbol)->set_symbol_name((yyvsp[-1].symbol)->get_symbol_name().append((yyvsp[0].symbol)->get_symbol_name()));
			(yyval.symbol)->code = (yyvsp[-1].symbol)->code + (yyvsp[0].symbol)->code;
		}
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 192 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d program : unit\n",line_count);
			
			//fprintf(logout,"%s\n\n",$1->get_symbol_name().c_str());
			(yyval.symbol) = new SymbolInfo();
			(yyval.symbol)->set_symbol_name((yyvsp[0].symbol)->get_symbol_name());
			(yyval.symbol)->code = (yyvsp[0].symbol)->code;
		}
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 203 "1605084.y" /* yacc.c:1646  */
    {
		//fprintf(logout,"At line no : %d unit : var_declaration\n",line_count);
		
		//fprintf(logout,"%s\n\n",$1->get_symbol_name().c_str());
		(yyval.symbol) = new SymbolInfo();
		(yyval.symbol)->set_symbol_name((yyvsp[0].symbol)->get_symbol_name());	

		(yyval.symbol)->code = (yyvsp[0].symbol)->code;
	}
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 213 "1605084.y" /* yacc.c:1646  */
    {
		//fprintf(logout,"At line no : %d unit : func_declaration\n",line_count);
		
		//fprintf(logout,"%s\n\n",$1->get_symbol_name().c_str());
		(yyval.symbol) = new SymbolInfo();
		(yyval.symbol)->set_symbol_name((yyvsp[0].symbol)->get_symbol_name());	
		(yyval.symbol)->code = (yyvsp[0].symbol)->code;
	}
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 222 "1605084.y" /* yacc.c:1646  */
    {
		//fprintf(logout,"At line no : %d unit : func definition\n",line_count);
		
		//fprintf(logout,"%s\n\n",$1->get_symbol_name().c_str());
		(yyval.symbol) = new SymbolInfo();
		(yyval.symbol)->set_symbol_name((yyvsp[0].symbol)->get_symbol_name());	
		(yyval.symbol)->code = (yyvsp[0].symbol)->code;
	}
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 233 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n",line_count);

			(yyval.symbol) = new SymbolInfo();		
			string s = (yyvsp[-5].symbol)->get_symbol_name()+(yyvsp[-4].symbol)->get_symbol_name()+"("+(yyvsp[-2].symbol)->get_symbol_name()+");\n";
			(yyval.symbol)->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

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
						symb->para_list.push_back(make_pair(parameter_list_vector[i].first,parameter_list_vector[i].second+to_string(symbolTable.getNextScopeTableID())));
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
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 326 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n",line_count);
			
			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[-4].symbol)->get_symbol_name()+(yyvsp[-3].symbol)->get_symbol_name()+"();\n";
			(yyval.symbol)->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

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
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 387 "1605084.y" /* yacc.c:1646  */
    {
				
				SymbolInfo* symb = symbolTable.lookUp((yyvsp[-3].symbol)->get_symbol_name());

				if(symb == NULL) //function not found
				{
					SymbolInfo* symb = new SymbolInfo();
					symb->set_symbol_name((yyvsp[-3].symbol)->get_symbol_name());
					symb->set_symbol_type((yyvsp[-4].symbol)->get_symbol_type());
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
							symb->para_list.push_back(make_pair(parameter_list_vector[i].first,parameter_list_vector[i].second+to_string(symbolTable.getNextScopeTableID())));
						}
						symbolTable.insert(symb);
						currentFunction = (yyvsp[-3].symbol)->get_symbol_name();
						//cout<<"Func definition :"<<currentFunction<<endl;
						variable_declaration.push_back(currentFunction+"_return");
					}
					//parameter_list_vector.clear();
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
								symbolTable.lookUp((yyvsp[-3].symbol)->get_symbol_name())->is_function_defined = true;
								currentFunction = (yyvsp[-3].symbol)->get_symbol_name();
								//cout<<"Func definition :"<<currentFunction<<endl;
								variable_declaration.push_back(currentFunction+"_return");		
							}

						}
						else if(symb->is_function_defined == true)
						{
							fprintf(errorout,"Error at line no : %d  Function already defined.\n\n",line_count);
							error_count++;
						}	
						//parameter_list_vector.clear();
				
					}
					else
					{
						fprintf(errorout,"Error at line no : %d  Variable/array of same name already exits\n\n",line_count);
						error_count++;
					}
				}
				 
			
			}
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 492 "1605084.y" /* yacc.c:1646  */
    {

				(yyval.symbol) = new SymbolInfo();
				string s = (yyvsp[-6].symbol)->get_symbol_name()+(yyvsp[-5].symbol)->get_symbol_name()+"("+(yyvsp[-3].symbol)->get_symbol_name()+")\n"+(yyvsp[0].symbol)->get_symbol_name();
				(yyval.symbol)->set_symbol_name(s);
				//fprintf(logout,"%s\n\n",s.c_str());

				(yyval.symbol)->code = (yyvsp[-5].symbol)->get_symbol_name()+" PROC\n";
				(yyval.symbol)->set_symbol_type((yyvsp[-6].symbol)->get_symbol_type());


				if((yyvsp[-5].symbol)->get_symbol_name() == "main")
				{
					(yyval.symbol)->code += "MOV AX, @DATA\n";
					(yyval.symbol)->code += "MOV DS, AX\n";
					(yyval.symbol)->code += (yyvsp[0].symbol)->code;
					(yyval.symbol)->code += "LReturn"+currentFunction+":\n";
					(yyval.symbol)->code += "MOV AH, 4CH\n";
					(yyval.symbol)->code += "INT 21H\n";
				}
				else
				{
					for(int i=0;i<func_variable_declaration.size();i++)
					{
						symbolTable.lookUp((yyvsp[-5].symbol)->get_symbol_name())->func_var_list.push_back(func_variable_declaration[i]);
					}
					func_variable_declaration.clear();
					string temp_code = (yyval.symbol)->code;
					temp_code += "PUSH AX\n";
					temp_code += "PUSH BX\n";
					temp_code += "PUSH CX\n";
					temp_code += "PUSH DX\n";

					SymbolInfo* check = symbolTable.lookUp((yyvsp[-5].symbol)->get_symbol_name());
					for(int i=0;i<check->para_list.size();i++)
					{
						temp_code += "PUSH "+check->para_list[i].second+"\n";
					}

					for(int i=0;i<check->func_var_list.size();i++)
					{
						temp_code += "PUSH "+check->func_var_list[i]+"\n";
					}
					temp_code += (yyvsp[0].symbol)->code + "LReturn"+currentFunction+":\n";

					for(int i=check->func_var_list.size()-1;i>-1;i--)
					{
						temp_code += "POP "+check->func_var_list[i]+"\n";
					}
					for(int i=check->para_list.size()-1;i>-1;i--)
					{
						temp_code += "POP "+check->para_list[i].second+"\n";
					}

					temp_code += "POP DX\n";
					temp_code += "POP CX\n";
					temp_code += "POP BX\n";
					temp_code += "POP AX\n";
					temp_code += "RET\n";

					(yyval.symbol)->code = temp_code + (yyvsp[-5].symbol)->get_symbol_name()+" ENDP\n";

					
				}
				parameter_list_vector.clear();
	
			}
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 560 "1605084.y" /* yacc.c:1646  */
    {
				SymbolInfo* symb = symbolTable.lookUp((yyvsp[-2].symbol)->get_symbol_name());

				if(symb == NULL) //function not found
				{
					SymbolInfo* symb = new SymbolInfo();
					symb->set_symbol_name((yyvsp[-2].symbol)->get_symbol_name());
					symb->set_symbol_type((yyvsp[-3].symbol)->get_symbol_type());
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
							symb->para_list.push_back(make_pair(parameter_list_vector[i].first,parameter_list_vector[i].second+to_string(symbolTable.getNextScopeTableID())));
						}
						symbolTable.insert(symb);
						currentFunction = (yyvsp[-2].symbol)->get_symbol_name();
						//cout<<"Func definition :"<<currentFunction<<endl;
						variable_declaration.push_back(currentFunction+"_return");
					}
					//parameter_list_vector.clear();
				}
				else
				{
					if(symb->get_symbol_class() == "FUNCTION")
					{
						//previously not defined
						if(symb->is_function_defined == false && symb->is_function_declared == true)
						{
							int check_error = 0;
							if(symb->get_symbol_type() != (yyvsp[-3].symbol)->get_symbol_type())
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
								symbolTable.lookUp((yyvsp[-2].symbol)->get_symbol_name())->is_function_defined = true;
								currentFunction = (yyvsp[-2].symbol)->get_symbol_name();
								//cout<<"Func definition :"<<currentFunction<<endl;
								variable_declaration.push_back(currentFunction+"_return");		
							}

						}
						else if(symb->is_function_defined == true)
						{
							fprintf(errorout,"Error at line no : %d  Function already defined.\n\n",line_count);
							error_count++;
						}	
						//parameter_list_vector.clear();
				
					}
					else
					{
						fprintf(errorout,"Error at line no : %d  Variable/array of same name already exits\n\n",line_count);
						error_count++;
					}
				}

			}
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 664 "1605084.y" /* yacc.c:1646  */
    {

					(yyval.symbol) = new SymbolInfo();
					string s = (yyvsp[-5].symbol)->get_symbol_name()+(yyvsp[-4].symbol)->get_symbol_name()+"()\n"+(yyvsp[0].symbol)->get_symbol_name();
					(yyval.symbol)->set_symbol_name(s);
					//fprintf(logout,"%s\n\n",s.c_str());

					(yyval.symbol)->code = (yyvsp[-4].symbol)->get_symbol_name()+" PROC\n";
					(yyval.symbol)->set_symbol_type((yyvsp[-5].symbol)->get_symbol_type());


					if((yyvsp[-4].symbol)->get_symbol_name() == "main")
					{
						(yyval.symbol)->code += "MOV AX, @DATA\n";
						(yyval.symbol)->code += "MOV DS, AX\n";
						(yyval.symbol)->code += (yyvsp[0].symbol)->code;
						(yyval.symbol)->code += "LReturn"+currentFunction+":\n";
						(yyval.symbol)->code += "MOV AH, 4CH\n";
						(yyval.symbol)->code += "INT 21H\n";
					}
					else
					{
						for(int i=0;i<func_variable_declaration.size();i++)
						{
							symbolTable.lookUp((yyvsp[-4].symbol)->get_symbol_name())->func_var_list.push_back(func_variable_declaration[i]);
						}
						func_variable_declaration.clear();
						string temp_code = (yyval.symbol)->code;
						temp_code += "PUSH AX\n";
						temp_code += "PUSH BX\n";
						temp_code += "PUSH CX\n";
						temp_code += "PUSH DX\n";

						SymbolInfo* check = symbolTable.lookUp((yyvsp[-4].symbol)->get_symbol_name());
						for(int i=0;i<check->para_list.size();i++)
						{
							temp_code += "PUSH "+check->para_list[i].second+"\n";
						}

						for(int i=0;i<check->func_var_list.size();i++)
						{
							temp_code += "PUSH "+check->func_var_list[i]+"\n";
						}
						temp_code += (yyvsp[0].symbol)->code + "LReturn"+currentFunction+":\n";

						for(int i=0;i<check->func_var_list.size();i++)
						{
							temp_code += "POP "+check->func_var_list[i]+"\n";
						}
						for(int i=0;i<check->para_list.size();i++)
						{
							temp_code += "POP "+check->para_list[i].second+"\n";
						}

						temp_code += "POP DX\n";
						temp_code += "POP CX\n";
						temp_code += "POP BX\n";
						temp_code += "POP AX\n";
						temp_code += "RET\n";

						(yyval.symbol)->code = temp_code + (yyvsp[-4].symbol)->get_symbol_name()+" ENDP\n";
					}
					parameter_list_vector.clear();
			}
#line 2114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 732 "1605084.y" /* yacc.c:1646  */
    {
				//fprintf(logout,"At line no : %d parameter_list : parameter_list COMMA type_specifier ID\n",line_count);

				(yyval.symbol) = new SymbolInfo();
				string s = (yyvsp[-3].symbol)->get_symbol_name()+","+(yyvsp[-1].symbol)->get_symbol_name()+(yyvsp[0].symbol)->get_symbol_name();
				(yyval.symbol)->set_symbol_name(s);
				//fprintf(logout,"%s\n\n",s.c_str());

				parameter_list_vector.push_back(make_pair((yyvsp[-1].symbol)->get_symbol_type(),(yyvsp[0].symbol)->get_symbol_name()));


			}
#line 2131 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 745 "1605084.y" /* yacc.c:1646  */
    {
				//fprintf(logout,"At line no : %d parameter_list : parameter_list COMMA type_specifier\n",line_count);

				(yyval.symbol) = new SymbolInfo();
				string s = (yyvsp[-2].symbol)->get_symbol_name()+","+(yyvsp[0].symbol)->get_symbol_name();
				(yyval.symbol)->set_symbol_name(s);
				//fprintf(logout,"%s\n\n",s.c_str());

				parameter_list_vector.push_back(make_pair((yyvsp[0].symbol)->get_symbol_type(),"NIL"));
			}
#line 2146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 756 "1605084.y" /* yacc.c:1646  */
    {
				//fprintf(logout,"At line no : %d parameter_list : type_specifier ID\n",line_count);

				(yyval.symbol) = new SymbolInfo();
				string s = (yyvsp[-1].symbol)->get_symbol_name()+(yyvsp[0].symbol)->get_symbol_name();
				(yyval.symbol)->set_symbol_name(s);
				//fprintf(logout,"%s\n\n",s.c_str());

				parameter_list_vector.push_back(make_pair((yyvsp[-1].symbol)->get_symbol_type(),(yyvsp[0].symbol)->get_symbol_name()));
			}
#line 2161 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 767 "1605084.y" /* yacc.c:1646  */
    {
				//fprintf(logout,"At line no : %d parameter_list : type_specifier\n",line_count);

				(yyval.symbol) = new SymbolInfo();
				string s = (yyvsp[0].symbol)->get_symbol_name();
				(yyval.symbol)->set_symbol_name(s);
				//fprintf(logout,"%s\n\n",s.c_str());

				parameter_list_vector.push_back(make_pair((yyvsp[0].symbol)->get_symbol_type(),"NIL"));

			}
#line 2177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 781 "1605084.y" /* yacc.c:1646  */
    {
					symbolTable.enterScope(10);

					for(int i=0;i<parameter_list_vector.size();i++)
					{
						SymbolInfo* symb = new SymbolInfo();
						symb->set_symbol_type(parameter_list_vector[i].first);
						symb->set_symbol_name(parameter_list_vector[i].second);
						symb->set_symbol_class("VARIABLE");
						symbolTable.insert(symb);

						variable_declaration.push_back(parameter_list_vector[i].second+to_string(symbolTable.getCurrentScopeTableID()));
					}
					//confusion
				}
#line 2197 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 796 "1605084.y" /* yacc.c:1646  */
    {
				//fprintf(logout,"At line no : %d compound_statement : LCURL statements RCURL\n",line_count);

				(yyval.symbol) = new SymbolInfo();	
				string s = "{\n"+(yyvsp[-1].symbol)->get_symbol_name()+"\n}\n";
				(yyval.symbol)->set_symbol_name(s);

				(yyval.symbol)->code = (yyvsp[-1].symbol)->code;

				//fprintf(logout,"%s\n\n",s.c_str());

				
				symbolTable.printAll();
				symbolTable.exitScope();
			}
#line 2217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 812 "1605084.y" /* yacc.c:1646  */
    {
				//fprintf(logout,"At line no : %d compound_statement : LCURL RCURL\n",line_count);
				(yyval.symbol) = new SymbolInfo();
				string s = "{}\n";
				(yyval.symbol)->set_symbol_name(s);
				//fprintf(logout,"%s\n\n",s.c_str());

				symbolTable.enterScope(10);

				//symbolTable.printAll();
				symbolTable.exitScope();

			}
#line 2235 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 828 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d var_declaration : type_specifier declaration_list SEMICOLON\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[-2].symbol)->get_symbol_name()+(yyvsp[-1].symbol)->get_symbol_name()+";";
			(yyval.symbol)->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());


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
					if(declaration_list_vector[i]->get_symbol_class() == "ARRAY")
					{
						array_declarartion.push_back(make_pair(declaration_list_vector[i]->get_symbol_name()+to_string(symbolTable.getCurrentScopeTableID()),declaration_list_vector[i]->ara_size));
					}
					else
					{
						variable_declaration.push_back(declaration_list_vector[i]->get_symbol_name()+to_string(symbolTable.getCurrentScopeTableID()));
						func_variable_declaration.push_back(declaration_list_vector[i]->get_symbol_name()+to_string(symbolTable.getCurrentScopeTableID()));
					}
				}
				else if(symbolTable.insert(declaration_list_vector[i]) == false)
				{
					error_count++;
					fprintf(errorout,"Error at line no : %d  Multiple declaration of variable/array %s\n\n",line_count,declaration_list_vector[i]->get_symbol_name().c_str());
				}
			}
			declaration_list_vector.clear();

		}
#line 2284 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 875 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d type_specifier : INT\n",line_count);
			
			SymbolInfo* s = new SymbolInfo();
			s->set_symbol_name("int ");
			s->set_symbol_type("INT");
			(yyval.symbol) = s;
			//fprintf(logout,"%s\n\n",$$->get_symbol_name().c_str());
			
		}
#line 2299 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 886 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d type_specifier : FLOAT\n",line_count);

			SymbolInfo* s = new SymbolInfo();
			s->set_symbol_name("float ");
			s->set_symbol_type("FLOAT");
			(yyval.symbol) = s;
			//fprintf(logout,"%s \n\n",$$->get_symbol_name().c_str());
		}
#line 2313 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 896 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d type_specifier : VOID\n",line_count);
			
			SymbolInfo* s = new SymbolInfo();
			s->set_symbol_name("void ");
			s->set_symbol_type("VOID");
			(yyval.symbol) = s;
			//fprintf(logout,"%s \n\n",$$->get_symbol_name().c_str());
		}
#line 2327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 908 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d declaration_list : declaration_list COMMA ID\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[-2].symbol)->get_symbol_name()+","+(yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			
			SymbolInfo* symb = new SymbolInfo();
			symb->set_symbol_name((yyvsp[0].symbol)->get_symbol_name());
			symb->set_symbol_class("VARIABLE"); 

			declaration_list_vector.push_back(symb);

				
		}
#line 2349 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 926 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[-5].symbol)->get_symbol_name()+","+(yyvsp[-3].symbol)->get_symbol_name()+"["+(yyvsp[-1].symbol)->get_symbol_name()+"]";
			(yyval.symbol)->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			SymbolInfo* symb = new SymbolInfo();
			symb->set_symbol_class("ARRAY");
			symb->set_symbol_name((yyvsp[-3].symbol)->get_symbol_name());
			symb->ara_size = atoi((yyvsp[-1].symbol)->get_symbol_name().c_str());

			declaration_list_vector.push_back(symb);

		}
#line 2370 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 943 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d declaration_list : ID\n",line_count);
			
			(yyval.symbol) = new SymbolInfo();
			(yyval.symbol)->set_symbol_name((yyvsp[0].symbol)->get_symbol_name());
			//fprintf(logout,"%s\n\n",$$->get_symbol_name().c_str());
			

			SymbolInfo* symb = new SymbolInfo();
			symb->set_symbol_name((yyvsp[0].symbol)->get_symbol_name());
			symb->set_symbol_class("VARIABLE"); 

			declaration_list_vector.push_back(symb);	
			
		}
#line 2390 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 959 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d declaration_list : ID LTHIRD CONST_INT RTHIRD\n",line_count);
			
			(yyval.symbol) = new SymbolInfo();
			(yyval.symbol)->set_symbol_name((yyvsp[-3].symbol)->get_symbol_name()+"["+(yyvsp[-1].symbol)->get_symbol_name()+"]");
			//fprintf(logout,"%s\n\n",$$->get_symbol_name().c_str());

			SymbolInfo* symb = new SymbolInfo();
			symb->set_symbol_class("ARRAY");
			symb->set_symbol_name((yyvsp[-3].symbol)->get_symbol_name());
			symb->ara_size = atoi((yyvsp[-1].symbol)->get_symbol_name().c_str());

			declaration_list_vector.push_back(symb);
		}
#line 2409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 976 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d statements : statement\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			(yyval.symbol)->code = (yyvsp[0].symbol)->code;
		}
#line 2424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 987 "1605084.y" /* yacc.c:1646  */
    {
				//fprintf(logout,"At line no : %d statements : statements statement\n",line_count);

				(yyval.symbol) = new SymbolInfo();
				string s = (yyvsp[-1].symbol)->get_symbol_name()+"\n"+(yyvsp[0].symbol)->get_symbol_name();
				(yyval.symbol)->set_symbol_name(s);
				//fprintf(logout,"%s\n\n",s.c_str());

				(yyval.symbol)->code = (yyvsp[-1].symbol)->code + (yyvsp[0].symbol)->code;
		}
#line 2439 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 1000 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d statement : var_declaration\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());
		}
#line 2452 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 1009 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d statement : expression_statement\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());
			(yyval.symbol)->code = (yyvsp[0].symbol)->code;
		}
#line 2466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 1019 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d statement : compound_statement\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());
			(yyval.symbol)->code = (yyvsp[0].symbol)->code;
		}
#line 2480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 1029 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = "for("+(yyvsp[-4].symbol)->get_symbol_name()+" "+(yyvsp[-3].symbol)->get_symbol_name()+" "+(yyvsp[-2].symbol)->get_symbol_name()+")\n"+(yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			if((yyvsp[-4].symbol)->get_symbol_type() == "VOID" || (yyvsp[-3].symbol)->get_symbol_type() == "VOID" || (yyvsp[-2].symbol)->get_symbol_type() == "VOID")
			{
				fprintf(errorout,"Error at line no : %d   Type Mismatch \n\n",line_count);
				error_count++;
			} 
			else
			{
				string temp_code = (yyvsp[-4].symbol)->code;

				char *label1 = newLabel();
				char *label2 = newLabel();

				temp_code += string(label1)+":\n";
				temp_code += (yyvsp[-3].symbol)->code;
				temp_code += "MOV AX, "+(yyvsp[-3].symbol)->get_symbol_value()+"\n";
				temp_code += "CMP AX, 0\n";
				temp_code += "JE "+string(label2)+"\n";
				temp_code += (yyvsp[0].symbol)->code;
				temp_code += (yyvsp[-2].symbol)->code;
				temp_code += string(label2)+":\n";
				(yyval.symbol)->code = temp_code;

			}
		}
#line 2517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 1062 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d statement : IF LPAREN expression RPAREN statement\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = "if("+(yyvsp[-2].symbol)->get_symbol_name()+")\n"+(yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			
			if((yyvsp[-2].symbol)->get_symbol_type() == "VOID")
			{
				fprintf(errorout,"Error at line no : %d   Type Mismatch \n\n",line_count);
				error_count++;
			}
			else
			{
				string temp_code = (yyvsp[-2].symbol)->code;
				char *label = newLabel();
				temp_code += "MOV AX, "+(yyvsp[-2].symbol)->get_symbol_value()+"\n";
				temp_code += "CMP AX, 0\n";
				temp_code += "JE "+string(label)+"\n";
				temp_code += (yyvsp[0].symbol)->code;
				temp_code += string(label)+":\n";
				(yyval.symbol)->code = temp_code;
			}
		}
#line 2548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 1089 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d statement : IF LPAREN expression RPAREN statement ELSE statement\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = "if("+(yyvsp[-4].symbol)->get_symbol_name()+")\n"+"else\n"+(yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			if((yyvsp[-4].symbol)->get_symbol_type() == "VOID")
			{
				fprintf(errorout,"Error at line no : %d   Type Mismatch \n\n",line_count);
				error_count++;
			}
			else
			{
				string temp_code = (yyvsp[-4].symbol)->code;
				char *label1 = newLabel();
				char *label2 = newLabel();
				temp_code += "MOV AX, "+(yyvsp[-4].symbol)->get_symbol_value()+"\n";
				temp_code += "CMP AX, 0\n";
				temp_code += "JE "+string(label1)+"\n";
				temp_code += (yyvsp[-2].symbol)->code;
				temp_code += "JMP "+string(label2)+"\n";
				temp_code += string(label1)+":\n";
				temp_code += (yyvsp[0].symbol)->code;
				temp_code += string(label2)+":\n";
				(yyval.symbol)->code = temp_code;
			}

		}
#line 2583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 1120 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d statement : WHILE LPAREN expression RPAREN statement\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = "while("+(yyvsp[-2].symbol)->get_symbol_name()+")\n"+(yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			if((yyvsp[-2].symbol)->get_symbol_type() == "VOID")
			{
				fprintf(errorout,"Error at line no : %d   Type Mismatch \n\n",line_count);
				error_count++;
			}
			else
			{
				string temp_code = "";
				char *label1 = newLabel();
				char *label2 = newLabel();
				temp_code += string(label1)+":\n";
				temp_code += (yyvsp[-2].symbol)->code;
				temp_code += "MOV AX, "+(yyvsp[-2].symbol)->get_symbol_value()+"\n";
				temp_code += "CMP AX, 0\n";
				temp_code += "JE "+string(label2)+"\n";
				temp_code += (yyvsp[0].symbol)->code;
				temp_code += "JMP "+string(label1)+"\n";
				temp_code += string(label2)+":\n";	
				(yyval.symbol)->code = temp_code;
			}		
		}
#line 2617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 1150 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = "println("+(yyvsp[-2].symbol)->get_symbol_name()+");";
			(yyval.symbol)->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());


			//confusion
			string temp_code = "";
			if(symbolTable.lookUpScopeTableID((yyvsp[-2].symbol)->get_symbol_name()) == -1000)
			{
				fprintf(errorout,"Error at line no : %d  Undeclared variable %s\n",line_count,(yyvsp[-2].symbol)->get_symbol_name().c_str());
			}
			else
			{
				temp_code += "MOV AX, "+(yyvsp[-2].symbol)->get_symbol_name()+to_string(symbolTable.lookUpScopeTableID((yyvsp[-2].symbol)->get_symbol_name()))+"\n";
				temp_code += "CALL OUTDEC\n";
			}
			(yyval.symbol)->code = temp_code;


		}
#line 2646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 1175 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d statement : RETURN expression SEMICOLON\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s ="return "+(yyvsp[-1].symbol)->get_symbol_name()+";";
			(yyval.symbol)->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			if((yyvsp[-1].symbol)->get_symbol_type() == "VOID")
			{
				fprintf(errorout,"Error at line no : %d   Type mismatch(return type can't be void) \n\n",line_count);
				error_count++;
			}
			else
			{
				string temp_code = (yyvsp[-1].symbol)->code;
				temp_code += "MOV AX, "+(yyvsp[-1].symbol)->get_symbol_value()+"\n";
				//cout<<"Return er moddhe : "<<currentFunction<<endl;
				temp_code += "MOV "+currentFunction+"_return, AX\n";
				//cout<<temp_code<<endl;
			    temp_code += "JMP LReturn"+currentFunction+"\n";
				//cout<<temp_code<<endl;

				(yyval.symbol)->code = temp_code;

			}

		}
#line 2679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 1206 "1605084.y" /* yacc.c:1646  */
    {
				//fprintf(logout,"At line no : %d expression_statement : SEMICOLON\n",line_count);

				(yyval.symbol) = new SymbolInfo();
				(yyval.symbol)->set_symbol_name(";");
				//fprintf(logout,"; \n\n");	
			}
#line 2691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 1214 "1605084.y" /* yacc.c:1646  */
    {
				//fprintf(logout,"At line no : %d expression_statement : expression SEMICOLON\n",line_count);
				
				(yyval.symbol) = new SymbolInfo();
				string s = (yyvsp[-1].symbol)->get_symbol_name()+";";
				(yyval.symbol)->set_symbol_name(s);
				//fprintf(logout,"%s\n\n",s.c_str());

				(yyval.symbol)->code = (yyvsp[-1].symbol)->code;
				(yyval.symbol)->set_symbol_value((yyvsp[-1].symbol)->get_symbol_value());

			}
#line 2708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 1229 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d variable : ID\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			SymbolInfo* check = symbolTable.lookUp((yyvsp[0].symbol)->get_symbol_name());
			
			if(check != NULL)
			{
				(yyval.symbol)->set_symbol_type(check->get_symbol_type());
			 
				(yyval.symbol)->set_symbol_value((yyvsp[0].symbol)->get_symbol_name()+to_string(symbolTable.lookUpScopeTableID((yyvsp[0].symbol)->get_symbol_name())));
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
#line 2745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 1262 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d variable : ID LTHIRD expression RTHIRD\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[-3].symbol)->get_symbol_name()+"["+(yyvsp[-1].symbol)->get_symbol_name()+"]";
			(yyval.symbol)->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			SymbolInfo* check = symbolTable.lookUp((yyvsp[-3].symbol)->get_symbol_name());

			if(check != NULL)
			{
				(yyval.symbol)->set_symbol_type(check->get_symbol_type());
				int err = 0;
				if((yyvsp[-1].symbol)->get_symbol_type() != "INT")
				{
					(yyval.symbol)->set_symbol_value((yyvsp[-3].symbol)->get_symbol_name()+to_string(symbolTable.lookUpScopeTableID((yyvsp[-3].symbol)->get_symbol_name())));
					error_count++;
					fprintf(errorout,"Error at line : %d   Non-integer Array Index\n\n",line_count);
					err = 1;
				}
				//seg fault
				else if(check->get_symbol_class() != "ARRAY")
				{
					error_count++;
					fprintf(errorout,"Error at line no : %d   Type mismatch(%s is not an array)\n\n",line_count,check->get_symbol_name().c_str());
					err = 1;
				}
				/*cout<<$3->get_symbol_name()<<endl;
				int size = atoi($3->get_symbol_name().c_str());
				cout<<check->ara_size<<endl;
				if(size > check->ara_size)
				{
					error_count++;
					fprintf(errorout,"Error at line no : %d   Array index out of bound\n\n",line_count);
				}*/

				if(err == 0)
				{
					string temp_code = (yyvsp[-1].symbol)->code;
					temp_code += "MOV BX, "+(yyvsp[-1].symbol)->get_symbol_value()+"\n";
					temp_code += "ADD BX, BX\n";
					(yyval.symbol)->set_symbol_value((yyvsp[-3].symbol)->get_symbol_name()+to_string(symbolTable.lookUpScopeTableID((yyvsp[-3].symbol)->get_symbol_name())));
					(yyval.symbol)->code = temp_code;
				}
				

			}
			else if(check == NULL)
			{	
				(yyval.symbol)->set_symbol_type("INT");
				error_count++;
				fprintf(errorout,"Error at line no : %d  Undeclared array %s\n\n",line_count,(yyvsp[-3].symbol)->get_symbol_name().c_str());
			}
				
		}
#line 2806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 1322 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d expression : logic_expression\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			(yyval.symbol)->set_symbol_type((yyvsp[0].symbol)->get_symbol_type());
			(yyval.symbol)->set_symbol_value((yyvsp[0].symbol)->get_symbol_value());
			(yyval.symbol)->code = (yyvsp[0].symbol)->code;
		}
#line 2823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 1335 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d expression : variable ASSIGNOP logic_expression\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[-2].symbol)->get_symbol_name()+" = "+(yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());


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

			string temp_code = (yyvsp[-2].symbol)->code +(yyvsp[0].symbol)->code;
			temp_code += "MOV AX, "+(yyvsp[0].symbol)->get_symbol_value()+"\n";
			
			if((yyvsp[-2].symbol)->get_symbol_class() != "ARRAY")
			{
				temp_code += "MOV "+(yyvsp[-2].symbol)->get_symbol_value()+", AX\n";
			}
			else
			{
				temp_code += "MOV "+(yyvsp[-2].symbol)->get_symbol_value()+"[BX], AX\n";
			}

			(yyval.symbol)->set_symbol_value((yyvsp[-2].symbol)->get_symbol_value());
			(yyval.symbol)->code = temp_code;		
		}
#line 2880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 1390 "1605084.y" /* yacc.c:1646  */
    {
				//fprintf(logout,"At line no : %d logic_expression : rel_expression\n",line_count);
			
				(yyval.symbol) = new SymbolInfo();
				string s = (yyvsp[0].symbol)->get_symbol_name();
				(yyval.symbol)->set_symbol_name(s);
				//fprintf(logout,"%s\n\n",s.c_str());

				(yyval.symbol)->set_symbol_type((yyvsp[0].symbol)->get_symbol_type());
				(yyval.symbol)->set_symbol_value((yyvsp[0].symbol)->get_symbol_value());
				(yyval.symbol)->code = (yyvsp[0].symbol)->code;

					
			}
#line 2899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 1405 "1605084.y" /* yacc.c:1646  */
    {
				//fprintf(logout,"At line no : %d logic_expression : rel_expression LOGICOP rel_expression\n",line_count);
			
				(yyval.symbol) = new SymbolInfo();
				string s = (yyvsp[-2].symbol)->get_symbol_name()+" "+(yyvsp[-1].symbol)->get_symbol_name()+" "+(yyvsp[0].symbol)->get_symbol_name();
				(yyval.symbol)->set_symbol_name(s);
				//fprintf(logout,"%s\n\n",s.c_str());

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
				else
				{
					string temp_code = (yyvsp[-2].symbol)->code + (yyvsp[0].symbol)->code;
					char *temp = newTemp();
					char *label1 = newLabel();
					char *label2 = newLabel();
					char *label3 = newLabel();

					if((yyvsp[-1].symbol)->get_symbol_name() == "||")
					{
						temp_code += "MOV AX, "+(yyvsp[-2].symbol)->get_symbol_value()+"\n";
						temp_code += "CMP AX, 0\n";
						temp_code += "JNE "+string(label2)+"\n";
						temp_code += "MOV AX, "+(yyvsp[0].symbol)->get_symbol_value()+"\n";
						temp_code += "CMP AX, 0\n";
						temp_code += "JNE "+string(label2)+"\n";
						temp_code += string(label1)+":\n";
						temp_code += "MOV "+string(temp)+", 0\n";
						temp_code += "JMP "+string(label3)+"\n";
						temp_code += string(label2)+":\n";
						temp_code += "MOV "+string(temp)+", 1\n";
						temp_code += string(label3)+":\n";

					}
					else
					{
						temp_code += "MOV AX, "+(yyvsp[-2].symbol)->get_symbol_value()+"\n";
						temp_code += "CMP AX, 0\n";
						temp_code += "JE "+string(label2)+"\n";
						temp_code += "MOV AX, "+(yyvsp[0].symbol)->get_symbol_value()+"\n";
						temp_code += "CMP AX, 0\n";
						temp_code += "JE "+string(label2)+"\n";
						temp_code += string(label1)+":\n";
						temp_code += "MOV "+string(temp)+", 1\n";
						temp_code += "JMP "+string(label3)+"\n";
						temp_code += string(label2)+":\n";
						temp_code += "MOV "+string(temp)+", 0\n";
						temp_code += string(label3)+":\n";
					}
					
					(yyval.symbol)->set_symbol_value(string(temp));
					variable_declaration.push_back(string(temp));
					(yyval.symbol)->code = temp_code;
				}
			}
#line 2969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 1473 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d rel_expression : simple_expression\n",line_count);
		
			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			(yyval.symbol)->set_symbol_type((yyvsp[0].symbol)->get_symbol_type());
			(yyval.symbol)->set_symbol_value((yyvsp[0].symbol)->get_symbol_value());
			(yyval.symbol)->code = (yyvsp[0].symbol)->code;
		}
#line 2986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 1486 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d rel_expression : simple_expression RELOP simple_expression\n",line_count);
		
			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[-2].symbol)->get_symbol_name()+" "+(yyvsp[-1].symbol)->get_symbol_name()+" "+(yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			

			//confusion change bison
			if((yyvsp[-2].symbol)->get_symbol_type()=="FLOAT" || (yyvsp[0].symbol)->get_symbol_type()=="FLOAT")
			{
				fprintf(errorout,"Error at line no : %d  Type conversion to integer(RELOP)\n\n",line_count);
				error_count++;
				
			}
			/*else if($1->get_symbol_type()=="FLOAT" && $3->get_symbol_type()=="INT")
			{
				fprintf(errorout,"Error at line no : %d  Type conversion to integer(RELOP)\n\n",line_count);
				error_count++;
			}*/

			(yyval.symbol)->set_symbol_type("INT");

			string temp_code = (yyvsp[-2].symbol)->code + (yyvsp[0].symbol)->code;
			temp_code += "MOV AX, " + (yyvsp[-2].symbol)->get_symbol_value()+"\n";
			//cout<<"rel ho"<<temp_code<<endl;
			temp_code += "CMP AX, " + (yyvsp[0].symbol)->get_symbol_value()+"\n";
			char *temp = newTemp();
			char *label1 = newLabel();
			char *label2 = newLabel();

			if((yyvsp[-1].symbol)->get_symbol_name() == "<")
			{
				temp_code += "JL " + string(label1)+"\n";
			}
			else if((yyvsp[-1].symbol)->get_symbol_name() == "<=")
			{
				temp_code += "JLE " + string(label1)+"\n";
			}
			else if((yyvsp[-1].symbol)->get_symbol_name() == ">")
			{
				temp_code += "JG " + string(label1)+"\n";
			}
			else if((yyvsp[-1].symbol)->get_symbol_name() == ">=")
			{
				temp_code += "JGE " + string(label1)+"\n";
			}
			else if((yyvsp[-1].symbol)->get_symbol_name() == "==")
			{
				temp_code += "JE " + string(label1)+"\n";
			}
			else if((yyvsp[-1].symbol)->get_symbol_name() == "!=")
			{
				temp_code += "JNE " + string(label1)+"\n";
			}
			
			temp_code += "MOV "+string(temp) +", 0\n";
			temp_code += "JMP "+string(label2) +"\n";
			temp_code += string(label1)+":\nMOV "+string(temp)+", 1\n";
			temp_code += string(label2)+":\n";
			variable_declaration.push_back(string(temp));
			(yyval.symbol)->set_symbol_value(string(temp));
			(yyval.symbol)->code = temp_code;
		}
#line 3057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 1555 "1605084.y" /* yacc.c:1646  */
    {
				//fprintf(logout,"At line no : %d simple_expression : term\n",line_count);

				(yyval.symbol) = new SymbolInfo();
				string s = (yyvsp[0].symbol)->get_symbol_name();
				(yyval.symbol)->set_symbol_name(s);
				//fprintf(logout,"%s\n\n",s.c_str());

				(yyval.symbol)->set_symbol_type((yyvsp[0].symbol)->get_symbol_type());
				(yyval.symbol)->set_symbol_value((yyvsp[0].symbol)->get_symbol_value());
				(yyval.symbol)->code = (yyvsp[0].symbol)->code;

			}
#line 3075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 1569 "1605084.y" /* yacc.c:1646  */
    {
				//fprintf(logout,"At line no : %d simple_expression : simple_expression ADDOP term\n",line_count);

				(yyval.symbol) = new SymbolInfo();
				string s = (yyvsp[-2].symbol)->get_symbol_name()+" "+(yyvsp[-1].symbol)->get_symbol_name()+" "+(yyvsp[0].symbol)->get_symbol_name();
				(yyval.symbol)->set_symbol_name(s);
				//fprintf(logout,"%s\n\n",s.c_str());
				
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

				string temp_code = (yyvsp[-2].symbol)->code + (yyvsp[0].symbol)->code;
				temp_code += "MOV AX, "+(yyvsp[-2].symbol)->get_symbol_value()+"\n";
				char *temp = newTemp();
				if((yyvsp[-1].symbol)->get_symbol_name() == "+")
				{
					temp_code += "ADD AX, "+(yyvsp[0].symbol)->get_symbol_value()+"\n";
				}
				else if((yyvsp[-1].symbol)->get_symbol_name() == "-")
				{
					temp_code += "SUB AX, "+(yyvsp[0].symbol)->get_symbol_value()+"\n";
				}
				temp_code += "MOV "+string(temp)+", AX\n";
				(yyval.symbol)->set_symbol_value(string(temp));
				(yyval.symbol)->code = temp_code;
				variable_declaration.push_back(string(temp));
								
			}
#line 3120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 1612 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d term : unary_expression\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			(yyval.symbol)->set_symbol_type((yyvsp[0].symbol)->get_symbol_type());
			(yyval.symbol)->set_symbol_value((yyvsp[0].symbol)->get_symbol_value());
			(yyval.symbol)->code = (yyvsp[0].symbol)->code;
		
		}
#line 3138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 1626 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d term : term MULOP unary_expression\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[-2].symbol)->get_symbol_name()+" "+(yyvsp[-1].symbol)->get_symbol_name()+" "+(yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());


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


				string temp_code = (yyvsp[-2].symbol)->code+(yyvsp[0].symbol)->code;
				char *temp = newTemp();
				temp_code += "MOV AX, "+(yyvsp[-2].symbol)->get_symbol_value()+"\n";
				temp_code += "MOV BX, "+(yyvsp[0].symbol)->get_symbol_value()+"\n";
				temp_code += "MOV DX, 0\n";
				temp_code += "DIV BX\n";
				temp_code += "MOV "+string(temp)+", DX\n";
				(yyval.symbol)->set_symbol_value(string(temp));
				(yyval.symbol)->code = temp_code;
				variable_declaration.push_back(string(temp));

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

				if((yyvsp[-1].symbol)->get_symbol_name() == "/")
				{
					string temp_code = (yyvsp[-2].symbol)->code+(yyvsp[0].symbol)->code;
					char *temp = newTemp();
					temp_code += "MOV AX, "+(yyvsp[-2].symbol)->get_symbol_value()+"\n";
					temp_code += "MOV BX, "+(yyvsp[0].symbol)->get_symbol_value()+"\n";
					temp_code += "DIV BX\n";
					temp_code += "MOV "+string(temp)+", AX\n";
					(yyval.symbol)->set_symbol_value(string(temp));
					(yyval.symbol)->code = temp_code;
					variable_declaration.push_back(string(temp));
				}
				else
				{
					string temp_code = (yyvsp[-2].symbol)->code+(yyvsp[0].symbol)->code;
					char *temp = newTemp();
					temp_code += "MOV AX, "+(yyvsp[-2].symbol)->get_symbol_value()+"\n";
					temp_code += "MOV BX, "+(yyvsp[0].symbol)->get_symbol_value()+"\n";
					temp_code += "MUL BX\n";
					temp_code += "MOV "+string(temp)+", AX\n";
					(yyval.symbol)->set_symbol_value(string(temp));
					(yyval.symbol)->code = temp_code;
					variable_declaration.push_back(string(temp));
				}
			}
		}
#line 3220 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 1706 "1605084.y" /* yacc.c:1646  */
    {
				//fprintf(logout,"At line no : %d unary_expression : ADDOP unary_expression\n",line_count);

				(yyval.symbol) = new SymbolInfo();
				string s = (yyvsp[-1].symbol)->get_symbol_name()+(yyvsp[0].symbol)->get_symbol_name();
				(yyval.symbol)->set_symbol_name(s);
				//fprintf(logout,"%s\n\n",s.c_str());
				
				if((yyvsp[0].symbol)->get_symbol_type() == "VOID")
				{
					fprintf(errorout,"Error at line no : %d  Type mismatch(ADDOP)\n\n",line_count);
					error_count++;
					(yyval.symbol)->set_symbol_type("INT");
				}
				else
				{
					(yyval.symbol)->set_symbol_type((yyvsp[0].symbol)->get_symbol_type());
					string temp_code = (yyvsp[0].symbol)->code;
					if((yyvsp[-1].symbol)->get_symbol_name() == "-")
					{
						temp_code += "MOV AX, "+(yyvsp[0].symbol)->get_symbol_value()+"\n";
						temp_code += "NEG AX\n";
						temp_code += "MOV "+(yyvsp[0].symbol)->get_symbol_value()+", AX\n";
					}
					(yyval.symbol)->set_symbol_value((yyvsp[0].symbol)->get_symbol_value());
					(yyval.symbol)->code = temp_code;
				}
				
			}
#line 3254 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 1736 "1605084.y" /* yacc.c:1646  */
    {
				//fprintf(logout,"At line no : %d unary_expression : NOT unary_expression\n",line_count);

				(yyval.symbol) = new SymbolInfo();
				string s = "!"+(yyvsp[0].symbol)->get_symbol_name();
				(yyval.symbol)->set_symbol_name(s);
				//fprintf(logout,"%s\n\n",s.c_str());

				if((yyvsp[0].symbol)->get_symbol_type() == "VOID")
				{
					fprintf(errorout,"Error at line no : %d  Type mismatch(NOT)\n\n",line_count);
					error_count++;
					(yyval.symbol)->set_symbol_type("INT");
				}
				else
				{
					(yyval.symbol)->set_symbol_type((yyvsp[0].symbol)->get_symbol_type());
					string temp_code = (yyvsp[0].symbol)->code;
					temp_code += "MOV AX, "+(yyvsp[0].symbol)->get_symbol_value()+"\n";
					temp_code += "NOT AX\n";
					temp_code += "MOV "+(yyvsp[0].symbol)->get_symbol_value()+", AX\n";
					(yyval.symbol)->set_symbol_value((yyval.symbol)->get_symbol_value());
					(yyval.symbol)->code = temp_code;
				}
			}
#line 3284 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1762 "1605084.y" /* yacc.c:1646  */
    {
				//fprintf(logout,"At line no : %d unary_expression : factor\n",line_count);

				(yyval.symbol) = new SymbolInfo();
				string s = (yyvsp[0].symbol)->get_symbol_name();
				(yyval.symbol)->set_symbol_name(s);
				//fprintf(logout,"%s\n\n",s.c_str());

				
				(yyval.symbol)->set_symbol_type((yyvsp[0].symbol)->get_symbol_type());
				(yyval.symbol)->code = (yyvsp[0].symbol)->code;
				(yyval.symbol)->set_symbol_value((yyvsp[0].symbol)->get_symbol_value());

			}
#line 3303 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1779 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d factor : variable\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			(yyval.symbol)->set_symbol_type((yyvsp[0].symbol)->get_symbol_type());

			string temp_code = (yyvsp[0].symbol)->code ;

			if((yyvsp[0].symbol)->get_symbol_type() == "ARRAY")
			{
				char *temp = newTemp();
				temp_code += "MOV AX, "+(yyvsp[0].symbol)->get_symbol_value()+"[BX]\n";
				temp_code += "MOV "+string(temp)+", AX\n";
				variable_declaration.push_back(string(temp));
				(yyval.symbol)->set_symbol_value(string(temp));
			}
			else{
				(yyval.symbol)->set_symbol_value((yyvsp[0].symbol)->get_symbol_value());
			}
			(yyval.symbol)->code = temp_code;

		}
#line 3334 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1806 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d factor : ID LPAREN argument_list RPAREN\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[-3].symbol)->get_symbol_name()+"("+(yyvsp[-1].symbol)->get_symbol_name()+")";
			(yyval.symbol)->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());
	
			SymbolInfo* symb = symbolTable.lookUp((yyvsp[-3].symbol)->get_symbol_name());


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
						string temp_code = (yyvsp[-1].symbol)->code;
						for(int i=0;i<argument_list_vector.size();i++)
						{
							temp_code += "MOV AX, "+argument_list_vector[i]->get_symbol_value()+"\n";
							//cout<<"argument:"<<argument_list_vector[i]->get_symbol_value()<<endl;
							temp_code += "MOV "+symbolTable.lookUp((yyvsp[-3].symbol)->get_symbol_name())->para_list[i].second+", AX\n";
							//cout<<symbolTable.lookUp($1->get_symbol_name())->para_list[i].second<<endl;
							//confusion
							if(argument_list_vector[i]->get_symbol_type() != symb->para_list[i].first)
							{
								fprintf(errorout,"Error at line no : %d  Function Argument Type Mismatch\n\n",line_count);
								error_count++;
							}		
						}

						temp_code += "CALL "+(yyvsp[-3].symbol)->get_symbol_name()+"\n";
						temp_code += "MOV AX, "+(yyvsp[-3].symbol)->get_symbol_name()+"_return\n";
						char *temp = newTemp();
						temp_code += "MOV "+string(temp)+", AX\n";
						(yyval.symbol)->set_symbol_value(temp);
						(yyval.symbol)->code = temp_code;
						variable_declaration.push_back(string(temp));

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
#line 3409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1877 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d factor : LPAREN expression RPAREN\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = "("+(yyvsp[-1].symbol)->get_symbol_name()+")";
			(yyval.symbol)->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			(yyval.symbol)->set_symbol_type((yyvsp[-1].symbol)->get_symbol_type());
			(yyval.symbol)->code = (yyvsp[-1].symbol)->code;
			(yyval.symbol)->set_symbol_value((yyvsp[-1].symbol)->get_symbol_value());
		}
#line 3426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1890 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d factor : CONST_INT\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			(yyval.symbol)->set_symbol_type("INT");	

			char *temp = newTemp();
			string temp_code = "";
			temp_code += "MOV "+string(temp)+", "+(yyvsp[0].symbol)->get_symbol_name()+"\n";
			(yyval.symbol)->code = temp_code;
			(yyval.symbol)->set_symbol_value(string(temp));
			variable_declaration.push_back(string(temp));

		}
#line 3449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1909 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d factor : CONST_FLOAT\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			(yyval.symbol)->set_symbol_type("FLOAT");

			char *temp = newTemp();
			string temp_code = "";
			temp_code += "MOV "+string(temp)+", "+(yyvsp[0].symbol)->get_symbol_name()+"\n";
			(yyval.symbol)->code = temp_code;
			(yyval.symbol)->set_symbol_value(string(temp));
			variable_declaration.push_back(string(temp));
		}
#line 3471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1927 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d factor : variable INCOP\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[-1].symbol)->get_symbol_name()+"++";
			(yyval.symbol)->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			(yyval.symbol)->set_symbol_type((yyvsp[-1].symbol)->get_symbol_type());

			char *temp = newTemp();
			string temp_code = "";
			if((yyvsp[-1].symbol)->get_symbol_class() == "ARRAY")
			{
				temp_code += "MOV AX, "+(yyvsp[-1].symbol)->get_symbol_value()+"[BX]\n";
			}
			else
			{
				temp_code += "MOV AX, "+(yyvsp[-1].symbol)->get_symbol_value()+"\n";
			}
			temp_code += "MOV "+string(temp)+", AX\n";

			if((yyvsp[-1].symbol)->get_symbol_class() == "ARRAY")
			{
				temp_code += "MOV AX, "+(yyvsp[-1].symbol)->get_symbol_value()+"[BX]\n";
				temp_code += "INC AX\n";
				temp_code += "MOV "+(yyvsp[-1].symbol)->get_symbol_value()+"[BX],AX\n";
			}
			else{
				temp_code += "INC "+(yyvsp[-1].symbol)->get_symbol_value()+"\n";
			}
			variable_declaration.push_back(string(temp));
			(yyval.symbol)->code = temp_code;
			(yyval.symbol)->set_symbol_value(string(temp));
		}
#line 3511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1963 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d factor : variable DECOP\n",line_count);
		    
			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[-1].symbol)->get_symbol_name()+"--";
			(yyval.symbol)->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			(yyval.symbol)->set_symbol_type((yyvsp[-1].symbol)->get_symbol_type());

			char *temp = newTemp();
			string temp_code = "";
			if((yyvsp[-1].symbol)->get_symbol_class() == "ARRAY")
			{
				temp_code += "MOV AX, "+(yyvsp[-1].symbol)->get_symbol_value()+"[BX]\n";
			}
			else
			{
				temp_code += "MOV AX, "+(yyvsp[-1].symbol)->get_symbol_value()+"\n";
			}
			temp_code += "MOV "+string(temp)+", AX\n";

			if((yyvsp[-1].symbol)->get_symbol_class() == "ARRAY")
			{
				temp_code += "MOV AX, "+(yyvsp[-1].symbol)->get_symbol_value()+"[BX]\n";
				temp_code += "DEC AX\n";
				temp_code += "MOV "+(yyvsp[-1].symbol)->get_symbol_value()+"[BX],AX\n";
			}
			else{
				temp_code += "DEC "+(yyvsp[-1].symbol)->get_symbol_value()+"\n";
			}
			variable_declaration.push_back(string(temp));
			(yyval.symbol)->code = temp_code;
			(yyval.symbol)->set_symbol_value(string(temp));
		}
#line 3551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 2001 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d argument_list : arguments\n",line_count);

			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			(yyval.symbol)->code = (yyvsp[0].symbol)->code;

		}
#line 3567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 2013 "1605084.y" /* yacc.c:1646  */
    { 
			(yyval.symbol) = new SymbolInfo(); 
			//fprintf(logout,"At line no : %d  argument_list : (empty) \n\n",line_count);
			(yyval.symbol)->set_symbol_name("");
		}
#line 3577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 2021 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d arguments : arguments COMMA logic_expression\n",line_count);
			
			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[-2].symbol)->get_symbol_name()+","+(yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			SymbolInfo* symb = new SymbolInfo();
			symb->set_symbol_name((yyvsp[0].symbol)->get_symbol_name());
			symb->set_symbol_type((yyvsp[0].symbol)->get_symbol_type());
			symb->set_symbol_class("VARIABLE");//argument = variable
			symb->set_symbol_value((yyvsp[0].symbol)->get_symbol_value());


			argument_list_vector.push_back(symb);

			(yyval.symbol)->code = (yyvsp[-2].symbol)->code+(yyvsp[0].symbol)->code;
		}
#line 3601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 2041 "1605084.y" /* yacc.c:1646  */
    {
			//fprintf(logout,"At line no : %d arguments : logic_expression\n",line_count);
		    
			(yyval.symbol) = new SymbolInfo();
			string s = (yyvsp[0].symbol)->get_symbol_name();
			(yyval.symbol)->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			SymbolInfo* symb = new SymbolInfo();
			symb->set_symbol_name((yyvsp[0].symbol)->get_symbol_name());
			symb->set_symbol_type((yyvsp[0].symbol)->get_symbol_type());
			symb->set_symbol_class("VARIABLE");
			symb->set_symbol_value((yyvsp[0].symbol)->get_symbol_value());

			argument_list_vector.push_back(symb);

			(yyval.symbol)->code = (yyvsp[0].symbol)->code;

		}
#line 3625 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3629 "y.tab.c" /* yacc.c:1646  */
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
#line 2064 "1605084.y" /* yacc.c:1906  */

void optimizeCode(FILE *asmfile)
{
	FILE* optimizedFile = fopen("1605084_Code.asm","w");
	char* line = NULL;
	size_t len = 0;

	vector<string>unoptimizedFileVector;
	while ((getline(&line, &len, asmfile)) != -1)
	{
		unoptimizedFileVector.push_back(string(line));
	}
	bool *duplicateCheck = new bool[unoptimizedFileVector.size()];
	for(int i=0;i<unoptimizedFileVector.size();i++)
	{
		duplicateCheck[i] = false;
	}

	for(int i=0;i<unoptimizedFileVector.size();i++)
	{
		if(unoptimizedFileVector[i].find("MOV") == 0)
		{
			if(unoptimizedFileVector[i+1].find("MOV") == 0)
			{
				int pos = 0;
				string s1,s2;
			
				s1 = unoptimizedFileVector[i];
				s2 = unoptimizedFileVector[i+1];
				chomp(s1);//erase new line from string
				chomp(s2);
				//cout<<s1;


				string line1_secondPart,line2_secondPart;
				while ((pos = s1.find(" ")) != string::npos) 
				{
					//line1_firstPart = s1.substr(0, pos);//MOV
					//cout<<line1_firstPart<<endl;
					line1_secondPart = s1.substr(pos+1,s1.size()-1);
					
					//cout<<line1_secondPart;
					break;
				}
				pos = 0;
				while ((pos = s2.find(" ")) != string::npos) 
				{
					//line2_firstPart = s2.substr(0, pos);//MOV
					//cout<<line1_firstPart<<endl;
					line2_secondPart = s2.substr(pos+1,s2.size()-1);
					//line2_secondPart '\n';
					//cout<<line1_secondPart;
					break;
				}

				string s3,s4,s5,s6;
				pos =0;
				while ((pos = line1_secondPart.find(", ")) != string::npos) 
				{
					//cout<<"hi"<<endl;
					s3 = line1_secondPart.substr(0, pos);
					//cout<<line1_firstPart<<endl;
					s4 = line1_secondPart.substr(pos+2,line1_secondPart.size()-1);
					
					break;
					
				}
				pos =0;
				while ((pos = line2_secondPart.find(", ")) != string::npos) 
				{
					s5 = line2_secondPart.substr(0, pos);
					//cout<<line1_firstPart<<endl;
					s6 = line2_secondPart.substr(pos+2,line1_secondPart.size()-1);
					
					break;
				}
				
				if(s3==s6 && s4 == s5)
				{
					/*cout<<"duplicate "<<endl;
					cout<<s3<<endl;
					cout<<s4<<endl;
					cout<<s5<<endl;
					cout<<s6<<endl;*/
					duplicateCheck[i+1] = true;
				}
			}
			if(duplicateCheck[i] == false)
			{
				fprintf(optimizedFile,"%s",unoptimizedFileVector[i].c_str());
			}
		}
		else
		{
			fprintf(optimizedFile,"%s",unoptimizedFileVector[i].c_str());
		}
		
		
	}
	fclose(asmfile);
	fclose(optimizedFile);


}
void chomp( string &s)
{
		int pos;
		if((pos=s.find('\n')) != string::npos)
		{
			s.erase(pos);
		}
}
int main(int argc,char *argv[])
{

	if((fp=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}
	
	errorout = fopen("1605084_log.txt","w");
    //logout = fopen("1605084_log.txt","w");

	yyin=fp;
	symbolTable.enterScope(10);
	yyparse();

	//fprintf(logout,"\n\nSymbol Table :\n\n");
	//symbolTable.printAll();
	fprintf(errorout,"\nTotal lines : %d\n",line_count);
	fprintf(errorout,"\nTotal errros : %d\n",error_count);
	//fprintf(errorout,"\nTotal errros : %d\n",error_count);
	fclose(fp);
	fclose(errorout);
	//fclose(logout);
	
	return 0;
}

