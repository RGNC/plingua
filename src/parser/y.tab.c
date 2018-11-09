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
#line 26 "src/parser/plingua.y" /* yacc.c:339  */

#include <stdio.h> 
#include <parser/syntax_tree.hpp>
#include <parser/parser.hpp>

#define YYERROR_VERBOSE

#define yyerror(s) plingua::parser::PARSER.error(s,yylloc)


extern int yylex();

using namespace plingua::parser;


#line 82 "src/parser/y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_SRC_PARSER_Y_TAB_H_INCLUDED
# define YY_YY_SRC_PARSER_Y_TAB_H_INCLUDED
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
    MODEL = 258,
    ASIG = 259,
    SEPARATOR = 260,
    ID = 261,
    LESS_THAN = 262,
    GREATER_THAN = 263,
    DEF = 264,
    LPAR = 265,
    RPAR = 266,
    LBRACE = 267,
    RBRACE = 268,
    LET = 269,
    SYMBOL = 270,
    COMMA = 271,
    NON_NEGATIVE_LONG = 272,
    NON_NEGATIVE_DOUBLE = 273,
    DIFF = 274,
    SYSTEM = 275,
    PLUS = 276,
    MINUS = 277,
    MUL = 278,
    DIV = 279,
    MOD = 280,
    COLON = 281,
    LESS_OR_EQUAL_THAN = 282,
    GREATER_OR_EQUAL_THAN = 283,
    CALL = 284,
    LSQUARE = 285,
    RSQUARE = 286,
    QUOTE = 287,
    MU = 288,
    EMPTY = 289,
    MS = 290,
    LONG_RIGHT_ARROW = 291,
    SHORT_RIGHT_ARROW = 292,
    DOUBLE_COLON = 293,
    DISSOLUTION_SYMBOL = 294,
    LONG_DOUBLE_ARROW = 295,
    SHORT_DOUBLE_ARROW = 296,
    EQUAL = 297,
    AND = 298,
    OR = 299,
    NOT = 300,
    LABELS = 301,
    FEATURE = 302,
    EMU = 303,
    PROB_TYPE = 304,
    IF = 305,
    ELSE = 306,
    WHILE = 307,
    DO = 308,
    FOR = 309,
    INC = 310,
    DEC = 311,
    INC_BY = 312,
    DEC_BY = 313,
    MUL_BY = 314,
    DIV_BY = 315,
    MOD_BY = 316,
    BITWISE_OR = 317,
    BITWISE_AND = 318,
    BITWISE_NOT = 319,
    BITWISE_LEFT = 320,
    BITWISE_RIGHT = 321,
    BITWISE_XOR = 322,
    QUESTION_MARK = 323,
    BITWISE_LEFT_BY = 324,
    BITWISE_RIGHT_BY = 325,
    STRING = 326,
    AT_SYMBOL = 327,
    BITWISE_AND_BY = 328,
    BITWISE_OR_BY = 329,
    BITWISE_XOR_BY = 330,
    RETURN = 331,
    INTEGER_LITERAL = 332,
    DOUBLE_LITERAL = 333,
    STRING_LITERAL = 334,
    POST_INC = 335,
    POST_DEC = 336,
    ADD = 337,
    SUB = 338,
    DEFINITIONS = 339,
    ERROR = 340,
    MODULE = 341,
    VARIABLE = 342,
    ARGUMENTS = 343,
    PARAMETERS = 344,
    SENTENCES = 345,
    INCLUDE = 346,
    RANGES = 347,
    RANGE = 348,
    RULE = 349,
    INDEXES = 350,
    MEMBRANES = 351,
    MEMBRANE = 352,
    CHARGE = 353,
    LABEL = 354,
    MULTISET = 355,
    PATTERN = 356,
    RULES = 357,
    REXP_TYPE = 358,
    PROBABILITY = 359,
    PRIORITY = 360,
    PLINGUA = 361,
    ANONYMOUS_VARIABLE = 362,
    INT_TYPE = 363,
    LONG_TYPE = 364,
    DOUBLE_TYPE = 365,
    STRING_TYPE = 366,
    SYSTEM_CONSTANT = 367,
    MODEL_DEFINITION = 368,
    MODEL_BODY = 369,
    MODEL_ELEMENT = 370,
    SYSTEM_CALL = 371,
    INNER_MEMBRANE = 372,
    INNER_MEMBRANES = 373,
    OUTER_MEMBRANE = 374,
    OUTER_MEMBRANES = 375,
    RIGHT_HAND_RULE = 376,
    LEFT_HAND_RULE = 377
  };
#endif
/* Tokens.  */
#define MODEL 258
#define ASIG 259
#define SEPARATOR 260
#define ID 261
#define LESS_THAN 262
#define GREATER_THAN 263
#define DEF 264
#define LPAR 265
#define RPAR 266
#define LBRACE 267
#define RBRACE 268
#define LET 269
#define SYMBOL 270
#define COMMA 271
#define NON_NEGATIVE_LONG 272
#define NON_NEGATIVE_DOUBLE 273
#define DIFF 274
#define SYSTEM 275
#define PLUS 276
#define MINUS 277
#define MUL 278
#define DIV 279
#define MOD 280
#define COLON 281
#define LESS_OR_EQUAL_THAN 282
#define GREATER_OR_EQUAL_THAN 283
#define CALL 284
#define LSQUARE 285
#define RSQUARE 286
#define QUOTE 287
#define MU 288
#define EMPTY 289
#define MS 290
#define LONG_RIGHT_ARROW 291
#define SHORT_RIGHT_ARROW 292
#define DOUBLE_COLON 293
#define DISSOLUTION_SYMBOL 294
#define LONG_DOUBLE_ARROW 295
#define SHORT_DOUBLE_ARROW 296
#define EQUAL 297
#define AND 298
#define OR 299
#define NOT 300
#define LABELS 301
#define FEATURE 302
#define EMU 303
#define PROB_TYPE 304
#define IF 305
#define ELSE 306
#define WHILE 307
#define DO 308
#define FOR 309
#define INC 310
#define DEC 311
#define INC_BY 312
#define DEC_BY 313
#define MUL_BY 314
#define DIV_BY 315
#define MOD_BY 316
#define BITWISE_OR 317
#define BITWISE_AND 318
#define BITWISE_NOT 319
#define BITWISE_LEFT 320
#define BITWISE_RIGHT 321
#define BITWISE_XOR 322
#define QUESTION_MARK 323
#define BITWISE_LEFT_BY 324
#define BITWISE_RIGHT_BY 325
#define STRING 326
#define AT_SYMBOL 327
#define BITWISE_AND_BY 328
#define BITWISE_OR_BY 329
#define BITWISE_XOR_BY 330
#define RETURN 331
#define INTEGER_LITERAL 332
#define DOUBLE_LITERAL 333
#define STRING_LITERAL 334
#define POST_INC 335
#define POST_DEC 336
#define ADD 337
#define SUB 338
#define DEFINITIONS 339
#define ERROR 340
#define MODULE 341
#define VARIABLE 342
#define ARGUMENTS 343
#define PARAMETERS 344
#define SENTENCES 345
#define INCLUDE 346
#define RANGES 347
#define RANGE 348
#define RULE 349
#define INDEXES 350
#define MEMBRANES 351
#define MEMBRANE 352
#define CHARGE 353
#define LABEL 354
#define MULTISET 355
#define PATTERN 356
#define RULES 357
#define REXP_TYPE 358
#define PROBABILITY 359
#define PRIORITY 360
#define PLINGUA 361
#define ANONYMOUS_VARIABLE 362
#define INT_TYPE 363
#define LONG_TYPE 364
#define DOUBLE_TYPE 365
#define STRING_TYPE 366
#define SYSTEM_CONSTANT 367
#define MODEL_DEFINITION 368
#define MODEL_BODY 369
#define MODEL_ELEMENT 370
#define SYSTEM_CALL 371
#define INNER_MEMBRANE 372
#define INNER_MEMBRANES 373
#define OUTER_MEMBRANE 374
#define OUTER_MEMBRANES 375
#define RIGHT_HAND_RULE 376
#define LEFT_HAND_RULE 377

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 69 "src/parser/plingua.y" /* yacc.c:355  */

	long   longValue;
	double doubleValue;
	char*  stringValue;
	plingua::parser::Node* node;

#line 373 "src/parser/y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 404 "src/parser/y.tab.c" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  35
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1236

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  123
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  83
/* YYNRULES -- Number of rules.  */
#define YYNRULES  261
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  491

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   377

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   101,   101,   103,   104,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   120,   121,   124,   125,   126,
     129,   130,   131,   132,   133,   134,   138,   141,   142,   145,
     146,   149,   152,   153,   158,   161,   162,   165,   168,   169,
     172,   173,   176,   177,   178,   179,   182,   183,   186,   187,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     202,   205,   208,   211,   214,   218,   219,   222,   223,   226,
     227,   230,   231,   232,   233,   234,   235,   236,   240,   241,
     244,   247,   248,   249,   250,   253,   254,   255,   258,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   276,   277,   280,   283,   286,   287,   291,   292,   295,
     296,   299,   300,   304,   305,   308,   309,   310,   313,   314,
     318,   319,   324,   325,   326,   330,   331,   334,   335,   338,
     341,   344,   345,   346,   349,   350,   353,   354,   358,   359,
     363,   364,   365,   366,   367,   368,   371,   372,   376,   377,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   405,   406,   407,   410,   411,   412,   413,   416,
     417,   418,   419,   420,   423,   424,   425,   426,   427,   432,
     433,   437,   438,   441,   442,   446,   447,   448,   449,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   467,   468,   472,   473,   477,   478,   481,   482,   486,
     487,   490,   491,   492,   496,   497,   498,   499,   500,   503,
     504,   505,   509,   510,   511,   514,   515,   516,   517,   521,
     522,   523,   524,   525,   526,   527,   530,   531,   532,   536,
     537,   538,   539,   540,   543,   544,   545,   546,   547,   548,
     549,   550
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MODEL", "ASIG", "SEPARATOR", "ID",
  "LESS_THAN", "GREATER_THAN", "DEF", "LPAR", "RPAR", "LBRACE", "RBRACE",
  "LET", "SYMBOL", "COMMA", "NON_NEGATIVE_LONG", "NON_NEGATIVE_DOUBLE",
  "DIFF", "SYSTEM", "PLUS", "MINUS", "MUL", "DIV", "MOD", "COLON",
  "LESS_OR_EQUAL_THAN", "GREATER_OR_EQUAL_THAN", "CALL", "LSQUARE",
  "RSQUARE", "QUOTE", "MU", "EMPTY", "MS", "LONG_RIGHT_ARROW",
  "SHORT_RIGHT_ARROW", "DOUBLE_COLON", "DISSOLUTION_SYMBOL",
  "LONG_DOUBLE_ARROW", "SHORT_DOUBLE_ARROW", "EQUAL", "AND", "OR", "NOT",
  "LABELS", "FEATURE", "EMU", "PROB_TYPE", "IF", "ELSE", "WHILE", "DO",
  "FOR", "INC", "DEC", "INC_BY", "DEC_BY", "MUL_BY", "DIV_BY", "MOD_BY",
  "BITWISE_OR", "BITWISE_AND", "BITWISE_NOT", "BITWISE_LEFT",
  "BITWISE_RIGHT", "BITWISE_XOR", "QUESTION_MARK", "BITWISE_LEFT_BY",
  "BITWISE_RIGHT_BY", "STRING", "AT_SYMBOL", "BITWISE_AND_BY",
  "BITWISE_OR_BY", "BITWISE_XOR_BY", "RETURN", "INTEGER_LITERAL",
  "DOUBLE_LITERAL", "STRING_LITERAL", "POST_INC", "POST_DEC", "ADD", "SUB",
  "DEFINITIONS", "ERROR", "MODULE", "VARIABLE", "ARGUMENTS", "PARAMETERS",
  "SENTENCES", "INCLUDE", "RANGES", "RANGE", "RULE", "INDEXES",
  "MEMBRANES", "MEMBRANE", "CHARGE", "LABEL", "MULTISET", "PATTERN",
  "RULES", "REXP_TYPE", "PROBABILITY", "PRIORITY", "PLINGUA",
  "ANONYMOUS_VARIABLE", "INT_TYPE", "LONG_TYPE", "DOUBLE_TYPE",
  "STRING_TYPE", "SYSTEM_CONSTANT", "MODEL_DEFINITION", "MODEL_BODY",
  "MODEL_ELEMENT", "SYSTEM_CALL", "INNER_MEMBRANE", "INNER_MEMBRANES",
  "OUTER_MEMBRANE", "OUTER_MEMBRANES", "RIGHT_HAND_RULE", "LEFT_HAND_RULE",
  "$accept", "plingua", "definitions", "definition", "features", "feature",
  "type", "model_definition", "model_body", "model_element", "pattern",
  "rules", "model", "include", "id", "variable", "arguments", "module",
  "parameters", "sentences", "sentence", "if", "else", "while", "dowhile",
  "for", "ranges", "range", "rangeCmp", "instruction", "regular_call",
  "system_call", "call", "assignment", "simple_assignment", "increment",
  "anonymous", "initialMembraneStructure", "extendMembraneStructure",
  "membranes", "membrane", "multiset", "multiset0", "multiobject",
  "multiobject0", "lsquare", "lsquare0", "charge", "charge0", "rsquare",
  "rsquare0", "non_negative_long", "label", "initialMultiset", "labels",
  "asigOrIncBy", "rule", "probability", "priority", "ruleBody",
  "left_hand_rule", "right_hand_rule", "left_outer_membrane",
  "right_outer_membrane", "right_outer_membranes", "inner_membrane",
  "inner_membranes", "arrow", "expr", "expr80", "expr70", "expr66",
  "expr64", "expr62", "expr60", "expr50", "expr45", "expr40", "expr30",
  "expr20", "expr10", "expr5", "expr0", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377
};
# endif

#define YYPACT_NINF -374

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-374)))

#define YYTABLE_NINF -78

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     336,  -374,   267,  -374,    -2,    -2,    -2,    -2,     6,    95,
     122,  -374,  -374,  -374,  -374,  -374,    17,   897,  -374,    34,
    -374,  -374,    -2,    -2,   116,   111,  -374,   129,    48,  -374,
     244,   111,  -374,    -2,  -374,  -374,  -374,  1139,  1139,  -374,
    -374,  1139,  1139,  1139,  1139,  1139,  1139,  1139,  1139,  1139,
    1139,  -374,  1139,   126,   139,   310,   429,  -374,    -2,  1139,
      93,   150,   805,  -374,  -374,   124,  1139,  1139,  1139,    -2,
      -2,  1139,  -374,   339,   955,   348,  -374,  -374,  -374,  -374,
     138,   143,   148,   159,   170,    74,   110,   151,   219,   389,
    -374,  -374,  -374,  -374,  -374,  -374,  -374,  -374,  -374,  -374,
    -374,  -374,  -374,  -374,  -374,   333,    50,  -374,   216,  -374,
     274,   289,  -374,   312,  1108,  -374,  -374,  -374,  -374,  -374,
     303,   530,   261,  -374,   272,  -374,  -374,   365,   292,   299,
     575,   -21,   361,   105,  -374,   176,  -374,  -374,  -374,  -374,
    -374,  -374,   323,  -374,   349,   355,   362,   368,   371,    -2,
    -374,  -374,  -374,  -374,  -374,  -374,   630,  1139,  -374,  -374,
    1139,  1139,  1139,  1139,  1139,  1139,  1139,  1139,  1139,  1139,
    -374,  1139,  1139,  1139,  1139,  1139,  1139,  1139,  1139,  1139,
    1139,  1139,  1139,  1139,  1139,  1139,  1139,  1139,  1139,  1139,
    -374,  1139,  -374,  1139,  -374,    -2,    16,   495,   372,    -2,
     379,   383,  -374,  -374,   395,   167,   105,   365,  -374,   377,
    1069,   149,  -374,  -374,  1168,  -374,  -374,   331,  1139,    -2,
     344,  -374,  -374,  -374,  -374,   575,   403,  -374,  -374,   167,
     167,   167,   167,  -374,  -374,  -374,  -374,   325,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,  -374,
     143,   148,   159,   170,    74,   110,   110,   151,   151,   151,
     151,   219,   219,   389,   389,  -374,  -374,  -374,  -374,   151,
      83,   404,   263,  -374,  -374,   431,  1082,  -374,   396,   154,
      24,   430,   437,  1082,   442,  1082,   444,  1139,   623,   852,
    -374,  -374,  -374,  -374,  -374,  -374,    35,  -374,  -374,  -374,
    -374,  -374,  -374,  -374,  -374,   911,  -374,  -374,  -374,  -374,
    1139,  -374,  -374,  -374,   455,   365,   233,  -374,   858,   365,
     147,  -374,   255,  -374,  -374,   365,    -2,   366,  -374,   439,
      -2,   272,   750,  -374,  -374,   575,  -374,  -374,  -374,  -374,
    -374,  1139,   446,  -374,    16,  -374,   968,    -2,   452,  -374,
    -374,   322,   233,   233,  1139,  -374,  1139,   412,    -2,   460,
    -374,  -374,  -374,  1139,  -374,  1025,    75,   147,  1139,  -374,
    -374,  -374,   450,  -374,   365,   455,  -374,   365,  -374,  -374,
     365,   455,  -374,   365,   439,   737,   439,     5,   377,   511,
    -374,  -374,   750,   403,  -374,   151,    16,  -374,   114,  -374,
    -374,  -374,  -374,   287,   443,   337,   346,   458,   461,   464,
     470,  -374,   264,  -374,   465,   233,   455,  -374,   365,  -374,
      75,   147,  -374,   455,  -374,   365,  -374,    75,   147,  -374,
     468,  -374,   169,   193,  -374,   354,   287,  -374,  -374,  -374,
     423,    10,  1082,  1082,  1139,  1139,  -374,  -374,  -374,  -374,
      75,   147,  -374,  -374,  -374,  -374,    75,   147,  -374,  -374,
    -374,  -374,  -374,  -374,  -374,  -374,  -374,   322,  -374,  -374,
      70,  -374,  -374,   479,   486,  -374,  -374,  -374,  -374,  -374,
     476,  -374,   488,    -2,    70,  -374,  1156,   483,  -374,  1082,
    -374
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,    14,     0,    37,     0,     0,     0,     0,     0,     0,
       0,     4,     7,     8,     6,     5,    38,     0,     9,     0,
      85,    87,     0,     0,     0,     0,    86,     0,     0,    16,
      38,    18,    17,     0,    35,     1,     3,     0,     0,    99,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    12,     0,     0,     0,     0,     0,    10,     0,     0,
       0,     0,     0,   130,   255,     0,     0,     0,     0,     0,
       0,     0,   257,    38,   256,     0,   258,   259,   254,    41,
     210,   212,   214,   216,   218,   220,   223,   228,   231,   234,
     238,   245,   248,   253,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,   256,     0,    66,     0,    34,
       0,     0,    47,     0,     0,   122,   123,   119,   117,   114,
     101,     0,   115,   124,     0,   110,   113,     0,     0,     0,
       0,   140,     0,   173,    15,     0,    24,    25,    20,    21,
      22,    23,     0,    36,     0,     0,     0,     0,     0,     0,
     239,   240,   241,   243,   244,   242,     0,     0,   246,   247,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      39,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      13,     0,    69,     0,    70,     0,     0,     0,     0,     0,
       0,     0,   102,    31,     0,     0,     0,     0,   172,     0,
       0,     0,   179,   194,     0,   118,    33,   142,     0,     0,
     141,   195,   196,   197,   198,   150,   174,    11,    19,     0,
       0,     0,     0,   261,   260,    80,    78,     0,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,    40,
     211,   213,   215,   217,   219,   222,   221,   224,   226,   225,
     227,   229,   230,   232,   233,   235,   236,   237,    65,    67,
       0,     0,     0,    28,    30,     0,     0,    42,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   115,     0,
      49,    54,    55,    56,    57,    58,     0,    81,    82,    71,
      72,    73,    74,    75,    76,     0,    46,   149,   148,    32,
       0,   256,   116,   109,     0,     0,     0,   180,     0,     0,
       0,   191,     0,   181,   193,     0,     0,    38,   146,   143,
       0,   175,     0,   151,   190,   176,   249,   250,   251,   252,
      79,     0,     0,    26,     0,    59,     0,     0,     0,    83,
      84,     0,     0,     0,     0,    61,     0,     0,     0,     0,
      43,    48,    50,     0,    44,     0,     0,     0,     0,   131,
     132,   137,   129,   182,     0,     0,   152,     0,   192,   183,
       0,     0,   157,     0,   145,     0,   144,   177,   127,     0,
     184,   128,     0,   178,   189,    68,     0,    27,    52,   125,
     126,   121,   103,     0,     0,     0,     0,     0,     0,     0,
       0,    53,     0,    45,     0,     0,     0,   162,     0,   153,
       0,     0,   154,     0,   167,     0,   158,     0,     0,   159,
       0,   185,     0,     0,   186,     0,     0,   106,   107,   120,
       0,     0,     0,     0,     0,     0,    51,   133,   136,   163,
       0,     0,   164,   155,   156,   168,     0,     0,   169,   160,
     161,   147,   187,   188,    29,   105,   108,     0,   138,   139,
     135,    60,    62,     0,     0,   165,   166,   170,   171,   104,
     134,   112,     0,     0,     0,    63,     0,     0,   111,     0,
      64
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -374,  -374,  -374,   490,  -218,   445,   119,  -374,   115,   166,
    -374,  -374,  -374,  -374,   242,     0,   475,  -374,  -374,  -253,
    -274,  -374,  -374,  -374,  -374,  -374,   -57,   327,   249,  -374,
     141,  -176,  -374,   262,     1,    30,   400,  -374,  -374,  -374,
    -373,   417,  -374,   314,  -272,   -32,  -374,  -374,  -374,  -257,
     288,  -251,   107,  -374,    54,  -374,   -53,  -374,  -374,   401,
    -374,  -374,   402,  -316,   204,   387,  -153,  -198,    37,   905,
     367,   364,   380,   363,   386,   245,   -34,   248,   243,   -35,
    -374,  -374,    29
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    11,    28,    29,   142,    12,   272,   273,
      13,   121,    14,    15,    73,   105,   237,    18,   113,   289,
     290,   291,   292,   293,   294,   295,   106,   107,   195,   296,
      76,    77,   299,   300,    20,    21,   123,   301,   302,   436,
     402,   124,   480,   125,   126,   211,   403,   128,   404,   390,
     391,    78,   371,   303,   372,   470,   304,   220,   130,   131,
     132,   333,   133,   334,   335,   213,   214,   225,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,   329,   135,   129,     3,    25,    26,    31,    32,   355,
      17,   357,   319,    33,   468,   361,   325,   218,   108,   394,
     342,   298,     3,   346,   127,   108,   115,   116,   351,    37,
     437,   150,   151,   152,   352,   117,   155,    74,    74,    51,
     362,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,   219,   365,    57,   315,   190,   122,   318,    31,    32,
      52,   363,    74,   465,    58,   370,   191,   469,   204,   153,
     154,   394,   361,   120,    59,    94,     3,    34,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   271,   127,
     192,   361,   207,   177,   479,    35,   115,   116,   127,   148,
     298,   370,   370,   350,   118,   117,   209,   298,   384,   298,
     194,     3,   386,   298,    74,    38,   178,   179,   180,   -77,
     374,   122,    -2,     1,   380,     2,    55,   122,     3,   298,
     122,     4,   431,   122,   109,   434,     5,   181,   182,   118,
     -77,    56,   136,   120,   119,   257,   258,   259,   260,   234,
     110,   201,   265,   266,   267,     3,    74,   108,   143,   269,
       3,   366,   149,   206,   370,   127,   377,     6,   471,   472,
     298,    74,   383,     3,   278,   462,   463,   310,   209,   392,
     209,   227,   172,   118,    63,    64,   173,    65,   119,   298,
     115,   116,   191,   332,     7,   270,   137,   288,   481,   117,
     388,   138,   139,   140,   141,   311,   122,   122,   249,   206,
     174,   122,   488,     8,   122,   490,   183,   184,    74,    31,
      32,   418,   420,   192,   388,   122,   175,   425,   427,   311,
     311,   311,   311,   176,   312,   193,   432,   120,    72,     3,
     185,   186,    16,   194,   127,   368,    24,    16,    27,    30,
      63,   127,    16,   127,    60,   328,    37,   127,   336,   337,
     338,   339,    19,   450,    53,    54,   298,   298,   343,   446,
     456,   206,    19,   127,    22,    61,   288,    23,   196,   344,
     191,   183,   184,   288,   205,   288,   209,    74,   206,   288,
     235,   221,   222,   115,   116,   223,   224,   112,    16,   332,
      30,   197,   117,   332,   216,   288,   412,   395,   399,   400,
      74,    16,    16,   298,   127,   122,     3,   401,   209,   122,
     202,   111,   215,   198,   359,   122,    31,    32,   199,   108,
      31,    32,   122,   127,   228,   122,   340,     1,   297,     2,
     120,   171,     3,   399,   400,     4,   288,   148,   440,   156,
       5,    37,   401,   415,    74,   332,    74,   441,    25,   410,
     229,   170,   415,    16,   171,   288,   230,   464,    74,    16,
     344,     3,    16,   231,   122,    16,   385,   122,    37,   232,
     122,     6,   233,   122,   305,    74,   115,   116,   158,   159,
     307,   407,   122,   408,   308,   117,   209,   221,   222,   118,
     309,   223,   224,   326,   119,   414,   405,   406,     7,   316,
     127,   127,   187,   188,   189,   212,   330,   297,   122,   206,
     349,    63,   255,   256,   297,   122,   297,     8,   263,   264,
     297,   261,   262,   120,   347,     3,   345,    16,   274,   114,
     353,   306,   288,   288,    74,    74,   297,   354,    16,    16,
     115,   116,   356,    16,   358,    58,    16,   127,   396,   117,
     327,    30,   156,   118,   409,   411,   415,    16,   119,   442,
     122,   206,   443,   439,   444,   445,   115,   116,   447,   461,
     467,   473,   474,   486,   122,   117,   209,   297,   235,   288,
     482,   483,   484,   485,   489,   212,   275,   120,   317,   321,
      36,     3,   323,   134,   430,   114,   297,   276,   277,     5,
     397,   435,    75,   487,   200,   278,   115,   116,   268,   341,
     313,   348,   448,   120,   279,   117,   208,   206,   280,   118,
     281,   217,   115,   116,   119,   387,     3,   251,   253,   250,
     114,   117,   388,   203,   210,   282,   283,   284,   285,   286,
     226,   115,   116,     0,   252,     0,     0,    16,   369,     0,
     117,    16,   254,   120,   118,     0,     0,    16,    30,   119,
       0,   287,    30,     0,    16,     0,     0,    16,     0,   120,
       0,     3,     0,   297,   297,     0,   274,     0,     0,   348,
       0,     0,     0,     0,   369,   369,   115,   116,   120,     0,
      16,   324,   317,   323,     0,   117,   373,   376,   378,   118,
     379,     0,     0,   382,   119,     0,    16,     0,     0,    16,
       0,     0,    16,     0,   314,    16,     0,    38,   320,     0,
     297,   322,     0,     0,    16,     0,     3,     0,   274,     0,
      62,   236,   331,   120,     0,     0,   205,    63,    64,     0,
      65,    66,    67,     0,   373,   379,     0,   369,     0,     0,
      16,     0,   417,   419,     0,   422,     0,    16,   424,   426,
       0,   429,     0,     0,     0,    68,     0,     0,    39,    40,
      41,    42,    43,    44,    45,    69,    70,     0,     0,     0,
       0,   438,    46,    47,    71,     0,    48,    49,    50,     0,
       0,    72,   324,     0,   449,   324,   452,     0,   453,   454,
       0,   455,    16,   458,     0,   459,   460,     0,     0,     0,
       0,     0,     0,     0,   466,    16,    16,     0,     0,     0,
       0,     0,   367,     0,     0,     0,   375,     0,   475,   476,
       0,     0,   381,     3,   477,   478,     0,    62,   236,   389,
       0,     0,   393,   324,    63,    64,     3,    65,    66,    67,
       0,     0,     0,     0,   324,     0,     0,     0,     0,     0,
     324,   115,   116,     0,     0,     0,     0,     0,     0,   324,
     117,   388,    68,     0,   118,     0,   136,     0,     0,   119,
       0,   416,    69,    70,   421,     0,     0,   423,     0,     0,
     428,    71,     0,     0,     0,   324,     0,   324,    72,   433,
       0,     3,   324,     0,   324,    62,     0,     0,   120,   324,
       0,     0,    63,    64,     0,    65,    66,    67,     0,     0,
       0,     0,     0,     0,     0,   451,     0,   324,     0,     0,
     137,     0,   457,   324,     0,   138,   139,   140,   141,     0,
      68,     0,     0,   275,     0,     0,     0,     0,     3,     0,
      69,    70,   114,     0,   276,   360,     5,     0,     0,    71,
       0,     0,   278,   115,   116,     0,    72,     0,     0,   115,
     116,   279,   117,     0,     0,   280,   118,   281,   117,   209,
       0,   119,     0,     0,   221,   222,     0,     0,   223,   224,
       0,    38,   282,   283,   284,   285,   286,     0,     0,     0,
       0,     0,   275,   144,   145,   146,   147,     3,     0,     0,
     120,   114,     0,   276,   364,     5,   120,     0,   287,     0,
       0,   278,   115,   116,     0,     0,     0,     0,     0,     0,
     279,   117,     0,     0,   280,   118,   281,     0,     0,     0,
     119,     0,    39,    40,    41,    42,    43,    44,    45,   157,
       0,   282,   283,   284,   285,   286,    46,    47,     0,   275,
      48,    49,    50,     0,     3,     0,     0,     0,   114,   120,
     276,   398,     5,     0,     0,     0,     0,   287,   278,   115,
     116,     0,     0,     0,     0,     0,     0,   279,   117,     0,
       0,   280,   118,   281,     0,     0,     0,   119,     0,     0,
     158,   159,   160,   161,   162,   163,   164,     0,   282,   283,
     284,   285,   286,     0,   165,   166,   275,     0,   167,   168,
     169,     3,     0,     0,     0,   114,   120,   276,   413,     5,
       0,     0,     0,     0,   287,   278,   115,   116,     0,     0,
       0,     0,     0,     0,   279,   117,     0,     0,   280,   118,
     281,     0,   238,     0,   119,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   282,   283,   284,   285,   286,
       0,     0,     0,   275,     0,   206,     0,     0,     3,     0,
     115,   116,   114,   120,   276,     0,     5,     0,     0,   117,
     209,   287,   278,   115,   116,   221,   222,     0,     0,   223,
     224,   279,   117,     0,     3,   280,   118,   281,    62,     0,
       0,   119,     0,     0,     0,    63,    64,     0,    65,    66,
      67,     0,   282,   283,   284,   285,   286,   120,     0,     0,
       0,     0,     0,     0,     0,     3,     0,     0,     0,    62,
     120,     0,     0,    68,     0,     0,    63,    64,   287,    65,
      66,    67,     0,    69,    70,     0,     0,     0,     0,     0,
       0,     0,    71,     0,     3,     0,   120,     0,     0,    72,
       0,     0,     0,     0,    68,     0,     0,     0,     0,   115,
     116,     0,     0,     0,    69,    70,     0,     0,   117,   209,
       0,     0,   118,    71,   221,   222,     0,   119,   223,   224,
      72,    39,    40,    41,    42,    43,    44,    45,     0,     0,
       0,     0,     0,     0,     0,    46,    47,     0,     0,    48,
      49,    50,     0,     0,     0,     0,   120
};

static const yytype_int16 yycheck[] =
{
       0,   219,    59,    56,     6,     5,     5,     7,     7,   283,
      10,   285,   210,     7,     4,   289,   214,    38,    52,   335,
     271,   197,     6,   276,    56,    59,    21,    22,     4,    12,
     403,    66,    67,    68,    10,    30,    71,    37,    38,     5,
       5,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    72,   305,     5,   207,     5,    56,   210,    58,    58,
      26,    26,    62,   436,    16,   316,    16,    57,   121,    69,
      70,   387,   346,    68,    26,    38,     6,    71,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    72,   121,
       7,   365,   124,    19,   467,     0,    21,    22,   130,    62,
     276,   352,   353,   279,    34,    30,    31,   283,   326,   285,
      27,     6,   330,   289,   114,     4,    42,     7,     8,     5,
     318,   121,     0,     1,   322,     3,    10,   127,     6,   305,
     130,     9,   389,   133,     8,   392,    14,    27,    28,    34,
      26,    12,    49,    68,    39,   179,   180,   181,   182,   149,
      11,   114,   187,   188,   189,     6,   156,   191,     8,   193,
       6,   314,    38,    16,   415,   197,   319,    45,   442,   443,
     346,   171,   325,     6,    20,   432,   433,    10,    31,   332,
      31,     5,    44,    34,    17,    18,    43,    20,    39,   365,
      21,    22,    16,   225,    72,   195,   103,   197,   470,    30,
      31,   108,   109,   110,   111,   205,   206,   207,   171,    16,
      62,   211,   484,    91,   214,   489,    65,    66,   218,   219,
     219,   374,   375,     7,    31,   225,    67,   380,   381,   229,
     230,   231,   232,    63,   205,    19,   389,    68,    71,     6,
      21,    22,     0,    27,   276,    12,     4,     5,     6,     7,
      17,   283,    10,   285,    10,   218,    12,   289,   229,   230,
     231,   232,     0,   416,    22,    23,   442,   443,     5,     5,
     423,    16,    10,   305,     7,    33,   276,    10,     4,    16,
      16,    65,    66,   283,    23,   285,    31,   287,    16,   289,
     149,    36,    37,    21,    22,    40,    41,    55,    56,   331,
      58,    12,    30,   335,     5,   305,   363,   341,    21,    22,
     310,    69,    70,   489,   346,   315,     6,    30,    31,   319,
      17,    11,    30,    11,   287,   325,   326,   326,    16,   363,
     330,   330,   332,   365,    11,   335,    11,     1,   197,     3,
      68,    16,     6,    21,    22,     9,   346,   310,    11,    10,
      14,    12,    30,    16,   354,   387,   356,    11,   358,   358,
      11,    13,    16,   121,    16,   365,    11,    13,   368,   127,
      16,     6,   130,    11,   374,   133,    10,   377,    12,    11,
     380,    45,    11,   383,    12,   385,    21,    22,    55,    56,
      11,   354,   392,   356,    11,    30,    31,    36,    37,    34,
       5,    40,    41,    72,    39,   368,   352,   353,    72,    32,
     442,   443,    23,    24,    25,   127,    72,   276,   418,    16,
     279,    17,   177,   178,   283,   425,   285,    91,   185,   186,
     289,   183,   184,    68,    38,     6,     5,   195,   196,    10,
      10,   199,   442,   443,   444,   445,   305,    10,   206,   207,
      21,    22,    10,   211,    10,    16,   214,   489,    12,    30,
     218,   219,    10,    34,    52,     5,    16,   225,    39,    11,
     470,    16,    11,    30,    10,     5,    21,    22,    13,    11,
      57,   444,   445,   483,   484,    30,    31,   346,   347,   489,
      11,     5,    16,     5,    11,   207,     1,    68,   210,   211,
      10,     6,   214,    58,   385,    10,   365,    12,    13,    14,
     344,   396,    37,   483,   114,    20,    21,    22,   191,   270,
     206,   279,   415,    68,    29,    30,   124,    16,    33,    34,
      35,   130,    21,    22,    39,   331,     6,   173,   175,   172,
      10,    30,    31,    13,   127,    50,    51,    52,    53,    54,
     133,    21,    22,    -1,   174,    -1,    -1,   315,   316,    -1,
      30,   319,   176,    68,    34,    -1,    -1,   325,   326,    39,
      -1,    76,   330,    -1,   332,    -1,    -1,   335,    -1,    68,
      -1,     6,    -1,   442,   443,    -1,   344,    -1,    -1,   347,
      -1,    -1,    -1,    -1,   352,   353,    21,    22,    68,    -1,
     358,   214,   314,   315,    -1,    30,   318,   319,   320,    34,
     322,    -1,    -1,   325,    39,    -1,   374,    -1,    -1,   377,
      -1,    -1,   380,    -1,   207,   383,    -1,     4,   211,    -1,
     489,   214,    -1,    -1,   392,    -1,     6,    -1,   396,    -1,
      10,    11,   225,    68,    -1,    -1,    23,    17,    18,    -1,
      20,    21,    22,    -1,   366,   367,    -1,   415,    -1,    -1,
     418,    -1,   374,   375,    -1,   377,    -1,   425,   380,   381,
      -1,   383,    -1,    -1,    -1,    45,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    55,    56,    -1,    -1,    -1,
      -1,   403,    69,    70,    64,    -1,    73,    74,    75,    -1,
      -1,    71,   315,    -1,   416,   318,   418,    -1,   420,   421,
      -1,   423,   470,   425,    -1,   427,   428,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   436,   483,   484,    -1,    -1,    -1,
      -1,    -1,   315,    -1,    -1,    -1,   319,    -1,   450,   451,
      -1,    -1,   325,     6,   456,   457,    -1,    10,    11,   332,
      -1,    -1,   335,   366,    17,    18,     6,    20,    21,    22,
      -1,    -1,    -1,    -1,   377,    -1,    -1,    -1,    -1,    -1,
     383,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,   392,
      30,    31,    45,    -1,    34,    -1,    49,    -1,    -1,    39,
      -1,   374,    55,    56,   377,    -1,    -1,   380,    -1,    -1,
     383,    64,    -1,    -1,    -1,   418,    -1,   420,    71,   392,
      -1,     6,   425,    -1,   427,    10,    -1,    -1,    68,   432,
      -1,    -1,    17,    18,    -1,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   418,    -1,   450,    -1,    -1,
     103,    -1,   425,   456,    -1,   108,   109,   110,   111,    -1,
      45,    -1,    -1,     1,    -1,    -1,    -1,    -1,     6,    -1,
      55,    56,    10,    -1,    12,    13,    14,    -1,    -1,    64,
      -1,    -1,    20,    21,    22,    -1,    71,    -1,    -1,    21,
      22,    29,    30,    -1,    -1,    33,    34,    35,    30,    31,
      -1,    39,    -1,    -1,    36,    37,    -1,    -1,    40,    41,
      -1,     4,    50,    51,    52,    53,    54,    -1,    -1,    -1,
      -1,    -1,     1,   108,   109,   110,   111,     6,    -1,    -1,
      68,    10,    -1,    12,    13,    14,    68,    -1,    76,    -1,
      -1,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    -1,    -1,    33,    34,    35,    -1,    -1,    -1,
      39,    -1,    55,    56,    57,    58,    59,    60,    61,     4,
      -1,    50,    51,    52,    53,    54,    69,    70,    -1,     1,
      73,    74,    75,    -1,     6,    -1,    -1,    -1,    10,    68,
      12,    13,    14,    -1,    -1,    -1,    -1,    76,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    -1,
      -1,    33,    34,    35,    -1,    -1,    -1,    39,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    -1,    50,    51,
      52,    53,    54,    -1,    69,    70,     1,    -1,    73,    74,
      75,     6,    -1,    -1,    -1,    10,    68,    12,    13,    14,
      -1,    -1,    -1,    -1,    76,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    33,    34,
      35,    -1,   157,    -1,    39,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,    50,    51,    52,    53,    54,
      -1,    -1,    -1,     1,    -1,    16,    -1,    -1,     6,    -1,
      21,    22,    10,    68,    12,    -1,    14,    -1,    -1,    30,
      31,    76,    20,    21,    22,    36,    37,    -1,    -1,    40,
      41,    29,    30,    -1,     6,    33,    34,    35,    10,    -1,
      -1,    39,    -1,    -1,    -1,    17,    18,    -1,    20,    21,
      22,    -1,    50,    51,    52,    53,    54,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    10,
      68,    -1,    -1,    45,    -1,    -1,    17,    18,    76,    20,
      21,    22,    -1,    55,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    -1,     6,    -1,    68,    -1,    -1,    71,
      -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    21,
      22,    -1,    -1,    -1,    55,    56,    -1,    -1,    30,    31,
      -1,    -1,    34,    64,    36,    37,    -1,    39,    40,    41,
      71,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    70,    -1,    -1,    73,
      74,    75,    -1,    -1,    -1,    -1,    68
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     6,     9,    14,    45,    72,    91,   124,
     125,   126,   130,   133,   135,   136,   137,   138,   140,   156,
     157,   158,     7,    10,   137,   138,   157,   137,   127,   128,
     137,   138,   157,     7,    71,     0,   126,    12,     4,    55,
      56,    57,    58,    59,    60,    61,    69,    70,    73,    74,
      75,     5,    26,   137,   137,    10,    12,     5,    16,    26,
      10,   137,    10,    17,    18,    20,    21,    22,    45,    55,
      56,    64,    71,   137,   138,   139,   153,   154,   174,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   138,   149,   150,   199,     8,
      11,    11,   137,   141,    10,    21,    22,    30,    34,    39,
      68,   134,   138,   159,   164,   166,   167,   168,   170,   179,
     181,   182,   183,   185,   128,   149,    49,   103,   108,   109,
     110,   111,   129,     8,   108,   109,   110,   111,   191,    38,
     202,   202,   202,   138,   138,   202,    10,     4,    55,    56,
      57,    58,    59,    60,    61,    69,    70,    73,    74,    75,
      13,    16,    44,    43,    62,    67,    63,    19,    42,     7,
       8,    27,    28,    65,    66,    21,    22,    23,    24,    25,
       5,    16,     7,    19,    27,   151,     4,    12,    11,    16,
     159,   191,    17,    13,   179,    23,    16,   168,   185,    31,
     164,   168,   173,   188,   189,    30,     5,   182,    38,    72,
     180,    36,    37,    40,    41,   190,   164,     5,    11,    11,
      11,    11,    11,    11,   138,   153,    11,   139,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   191,
     193,   194,   195,   196,   197,   198,   198,   199,   199,   199,
     199,   200,   200,   201,   201,   202,   202,   202,   150,   199,
     138,    72,   131,   132,   137,     1,    12,    13,    20,    29,
      33,    35,    50,    51,    52,    53,    54,    76,   138,   142,
     143,   144,   145,   146,   147,   148,   152,   153,   154,   155,
     156,   160,   161,   176,   179,    12,   137,    11,    11,     5,
      10,   138,   205,   166,   164,   189,    32,   173,   189,   190,
     164,   173,   164,   173,   188,   190,    72,   137,   191,   127,
      72,   164,   168,   184,   186,   187,   205,   205,   205,   205,
      11,   151,   174,     5,    16,     5,   142,    38,   137,   153,
     154,     4,    10,    10,    10,   143,    10,   143,    10,   191,
      13,   143,     5,    26,    13,   142,   189,   164,    12,   137,
     174,   175,   177,   173,   190,   164,   173,   189,   173,   173,
     190,   164,   173,   189,   127,    10,   127,   187,    31,   164,
     172,   173,   189,   164,   186,   199,    12,   132,    13,    21,
      22,    30,   163,   169,   171,   177,   177,   191,   191,    52,
     157,     5,   149,    13,   191,    16,   164,   173,   189,   173,
     189,   164,   173,   164,   173,   189,   173,   189,   164,   173,
     129,   172,   189,   164,   172,   131,   162,   163,   173,    30,
      11,    11,    11,    11,    10,     5,     5,    13,   175,   173,
     189,   164,   173,   173,   173,   173,   189,   164,   173,   173,
     173,    11,   172,   172,    13,   163,   173,    57,     4,    57,
     178,   143,   143,   191,   191,   173,   173,   173,   173,   163,
     165,   167,    11,     5,    16,     5,   138,   158,   167,    11,
     143
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   123,   124,   125,   125,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   127,   127,   128,   128,   128,
     129,   129,   129,   129,   129,   129,   130,   131,   131,   132,
     132,   133,   134,   134,   135,   136,   136,   137,   138,   138,
     139,   139,   140,   140,   140,   140,   141,   141,   142,   142,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     144,   145,   146,   147,   148,   149,   149,   150,   150,   151,
     151,   152,   152,   152,   152,   152,   152,   152,   153,   153,
     154,   155,   155,   155,   155,   156,   156,   156,   157,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   159,   159,   160,   161,   162,   162,   163,   163,   164,
     164,   165,   165,   166,   166,   167,   167,   167,   168,   168,
     169,   169,   170,   170,   170,   171,   171,   172,   172,   173,
     174,   175,   175,   175,   176,   176,   177,   177,   178,   178,
     179,   179,   179,   179,   179,   179,   180,   180,   181,   181,
     182,   182,   182,   182,   182,   182,   182,   182,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   182,   182,   182,
     182,   182,   183,   183,   183,   184,   184,   184,   184,   185,
     185,   185,   185,   185,   186,   186,   186,   186,   186,   187,
     187,   188,   188,   189,   189,   190,   190,   190,   190,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   192,   192,   193,   193,   194,   194,   195,   195,   196,
     196,   197,   197,   197,   198,   198,   198,   198,   198,   199,
     199,   199,   200,   200,   200,   201,   201,   201,   201,   202,
     202,   202,   202,   202,   202,   202,   203,   203,   203,   204,
     204,   204,   204,   204,   205,   205,   205,   205,   205,   205,
     205,   205
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       3,     5,     2,     4,     1,     3,     1,     1,     1,     4,
       1,     1,     1,     1,     1,     1,     7,     3,     1,     5,
       1,     5,     3,     2,     4,     2,     4,     1,     1,     4,
       3,     1,     6,     7,     7,     8,     3,     1,     2,     1,
       2,     4,     3,     3,     1,     1,     1,     1,     1,     2,
       5,     2,     5,     7,     9,     3,     1,     3,     5,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     4,
       3,     1,     1,     2,     2,     1,     2,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     1,     2,     3,     6,     2,     1,     2,     3,     3,
       1,     3,     1,     1,     1,     1,     3,     1,     2,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     3,     6,     5,     3,     1,     1,     1,
       1,     2,     2,     3,     4,     4,     2,     5,     3,     3,
       2,     3,     4,     5,     5,     6,     6,     4,     5,     5,
       6,     6,     5,     6,     6,     7,     7,     5,     6,     6,
       7,     7,     2,     1,     2,     1,     1,     2,     2,     2,
       3,     3,     4,     4,     2,     3,     3,     4,     4,     2,
       1,     2,     3,     2,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     2,
       2,     2,     2,     2,     2,     1,     2,     2,     1,     4,
       4,     4,     4,     1,     1,     1,     1,     1,     1,     1,
       3,     3
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 101 "src/parser/plingua.y" /* yacc.c:1646  */
    {plingua::parser::PARSER.addNode((yyvsp[0].node));}
#line 2112 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 103 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node)->addChild((yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-1].node),(yyvsp[0].node));}
#line 2118 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 104 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(DEFINITIONS,(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[0].node));}
#line 2124 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 107 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2130 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 108 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2136 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 109 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2142 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 110 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2148 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 111 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2154 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 112 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2160 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 113 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-3].node)->addChild((yyvsp[-1].node));}
#line 2166 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 114 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2172 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 115 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-3].node)->addChild((yyvsp[-1].node));}
#line 2178 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 116 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(ERROR); (yyval.node)->setLoc((yylsp[0]));}
#line 2184 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 120 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-2].node)->addChild((yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 2190 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 121 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(FEATURE,(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[0].node));}
#line 2196 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 124 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2202 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 125 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2208 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 126 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-3].node)->addChild((yyvsp[-1].node));(yyval.node)->setLoc((yyvsp[-3].node),(yylsp[0]));}
#line 2214 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 129 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(INT_TYPE); }
#line 2220 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 130 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(LONG_TYPE); }
#line 2226 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 131 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(DOUBLE_TYPE); }
#line 2232 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 132 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(STRING_TYPE); }
#line 2238 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 133 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(PROB_TYPE); }
#line 2244 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 134 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(REXP_TYPE); }
#line 2250 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 138 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(MODEL_DEFINITION, (yyvsp[-4].node), (yyvsp[-1].node)); (yyval.node)->setLoc((yylsp[-6]),(yyvsp[-1].node));}
#line 2256 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 141 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-2].node)->addChild((yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 2262 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 142 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(MODEL_BODY,(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[0].node));}
#line 2268 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 145 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(MODEL_ELEMENT,(yyvsp[-3].node),(yyvsp[-1].node));(yyval.node)->setLoc((yylsp[-4]),(yylsp[0]));}
#line 2274 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 146 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2280 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 149 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(PATTERN,(yyvsp[-3].node),(yyvsp[-1].node)); (yyval.node)->setLoc((yylsp[-4]),(yylsp[0]));}
#line 2286 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 152 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-2].node)->addChild((yyvsp[-1].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[-1].node));}
#line 2292 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 153 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(RULES,(yyvsp[-1].node)); (yyval.node)->setLoc((yyvsp[-1].node));}
#line 2298 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 158 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(MODEL,(yyvsp[-1].node)); (yyval.node)->setLoc((yylsp[-3]),(yylsp[0]));}
#line 2304 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 161 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(INCLUDE,(yyvsp[0].stringValue)); (yyval.node)->setLoc((yylsp[-1]),(yylsp[0]));}
#line 2310 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 162 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(INCLUDE,(yyvsp[-1].node)); (yyval.node)->setLoc((yylsp[-3]),(yylsp[0]));}
#line 2316 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 165 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(ID,(yyvsp[0].stringValue)); (yyval.node)->setLoc((yylsp[0]));}
#line 2322 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 168 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(VARIABLE,(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[0].node));}
#line 2328 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 169 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(VARIABLE, (yyvsp[-3].node), (yyvsp[-1].node)->setType(INDEXES)); (yyval.node)->setLoc((yyvsp[-3].node),(yylsp[0]));}
#line 2334 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 172 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-2].node)->addChild((yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 2340 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 173 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(ARGUMENTS,(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[0].node));}
#line 2346 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 176 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(MODULE,(yyvsp[-4].node)); (yyval.node)->setLoc((yylsp[-5]),(yylsp[0]));}
#line 2352 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 177 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(MODULE,(yyvsp[-5].node),(yyvsp[-1].node)); (yyval.node)->setLoc((yylsp[-6]),(yylsp[0]));}
#line 2358 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 178 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(MODULE,(yyvsp[-5].node),(yyvsp[-3].node)); (yyval.node)->setLoc((yylsp[-6]),(yylsp[0]));}
#line 2364 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 179 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(MODULE,(yyvsp[-6].node),(yyvsp[-4].node),(yyvsp[-1].node)); (yyval.node)->setLoc((yylsp[-7]),(yylsp[0]));}
#line 2370 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 182 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-2].node)->addChild(new Node(VARIABLE,(yyvsp[0].node))); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 2376 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 183 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(PARAMETERS,new Node(VARIABLE,(yyvsp[0].node))); (yyval.node)->setLoc((yyvsp[0].node));}
#line 2382 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 186 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node)->addChild((yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-1].node),(yyvsp[0].node));}
#line 2388 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 187 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(SENTENCES,(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[0].node));}
#line 2394 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 190 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2400 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 191 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-3].node)->addChild((yyvsp[-1].node));}
#line 2406 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 192 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2412 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 193 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(RETURN,(yyvsp[-1].node)); (yyval.node)->setLoc((yylsp[-2]),(yyvsp[-1].node));}
#line 2418 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 194 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2424 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 195 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2430 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 196 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2436 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 197 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2442 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 198 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2448 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 199 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(ERROR); (yyval.node)->setLoc((yylsp[-1]),(yylsp[0]));}
#line 2454 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 202 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(IF,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yylsp[-4]),(yyvsp[0].node));}
#line 2460 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 205 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(ELSE,(yyvsp[0].node)); (yyval.node)->setLoc((yylsp[-1]),(yyvsp[0].node));}
#line 2466 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 208 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(WHILE,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yylsp[-4]),(yyvsp[0].node));}
#line 2472 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 211 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(DO,(yyvsp[-5].node),(yyvsp[-2].node)); (yyval.node)->setLoc((yylsp[-6]),(yylsp[-1]));}
#line 2478 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 215 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(FOR,(yyvsp[-6].node),(yyvsp[-4].node),(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yylsp[-8]),(yyvsp[0].node));}
#line 2484 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 218 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-2].node)->addChild((yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 2490 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 219 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(RANGES,(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[0].node));}
#line 2496 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 222 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(DIFF,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 2502 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 223 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(RANGE,(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-4].node),(yyvsp[0].node));}
#line 2508 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 226 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(LESS_THAN); (yyval.node)->setLoc((yylsp[0]));}
#line 2514 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 227 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(LESS_OR_EQUAL_THAN); (yyval.node)->setLoc((yylsp[0]));}
#line 2520 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 230 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2526 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 231 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2532 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 232 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2538 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 233 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2544 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 234 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2550 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 235 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2556 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 236 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2562 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 240 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(CALL,(yyvsp[-2].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yylsp[0]));}
#line 2568 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 241 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(CALL,(yyvsp[-3].node),(yyvsp[-1].node)); (yyval.node)->setLoc((yyvsp[-3].node),(yylsp[0]));}
#line 2574 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 244 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(SYSTEM_CALL,(yyvsp[0].node)); (yyval.node)->setLoc((yylsp[-2]),(yyvsp[0].node));}
#line 2580 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 247 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2586 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 248 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2592 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 249 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2598 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 250 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2604 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 253 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2610 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 254 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); (yyval.node)->setLoc((yylsp[-1]),(yyvsp[0].node));}
#line 2616 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 255 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2622 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 258 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(ASIG,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 2628 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 261 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(INC_BY,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 2634 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 262 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(DEC_BY,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 2640 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 263 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(MUL_BY,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 2646 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 264 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(DIV_BY,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 2652 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 265 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(MOD_BY,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 2658 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 266 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(BITWISE_LEFT_BY,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 2664 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 267 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(BITWISE_RIGHT_BY,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 2670 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 268 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(BITWISE_AND_BY,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 2676 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 269 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(BITWISE_OR_BY,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 2682 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 270 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(BITWISE_XOR_BY,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 2688 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 271 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(POST_INC,(yyvsp[-1].node)); (yyval.node)->setLoc((yyvsp[-1].node),(yylsp[0]));}
#line 2694 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 272 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(POST_DEC,(yyvsp[-1].node)); (yyval.node)->setLoc((yyvsp[-1].node),(yylsp[0]));}
#line 2700 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 276 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(ANONYMOUS_VARIABLE,0L); (yyval.node)->setLoc((yylsp[0]));}
#line 2706 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 277 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(ANONYMOUS_VARIABLE,(yyvsp[0].longValue)+1); (yyval.node)->setLoc((yylsp[-1]),(yylsp[0]));}
#line 2712 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 280 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(MU,(yyvsp[0].node)); (yyval.node)->setLoc((yylsp[-2]),(yyvsp[0].node));}
#line 2718 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 283 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(EMU,(yyvsp[-3].node),(yyvsp[0].node)); (yyval.node)->setLoc((yylsp[-5]),(yyvsp[0].node));}
#line 2724 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 286 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node)->addChild((yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-1].node),(yyvsp[0].node));}
#line 2730 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 287 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(MEMBRANES,(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[0].node));}
#line 2736 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 291 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(MEMBRANE,(yyvsp[-1].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-1].node),(yyvsp[0].node));}
#line 2742 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 292 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(MEMBRANE,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 2748 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 295 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-2].node)->addChild((yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 2754 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 296 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(MULTISET,(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[0].node));}
#line 2760 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 299 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-2].node)->addChild((yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 2766 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 300 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(MULTISET,(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[0].node));}
#line 2772 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 304 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2778 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 305 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(DISSOLUTION_SYMBOL); (yyval.node)->setLoc((yylsp[0]));}
#line 2784 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 308 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2790 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 309 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(MUL,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 2796 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 310 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(EMPTY); (yyval.node)->setLoc((yylsp[0]));}
#line 2802 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 313 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2808 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 314 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(CHARGE,0L); (yyval.node)->setLoc((yylsp[0]));}
#line 2814 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 318 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2820 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 319 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(CHARGE,0L); (yyval.node)->setLoc((yylsp[0]));}
#line 2826 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 324 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(CHARGE,1L); (yyval.node)->setLoc((yylsp[0]));}
#line 2832 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 325 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(CHARGE,-1L); (yyval.node)->setLoc((yylsp[0]));}
#line 2838 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 326 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(CHARGE,(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[0].node));}
#line 2844 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 330 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(CHARGE,1L); (yyval.node)->setLoc((yylsp[0]));}
#line 2850 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 331 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(CHARGE,-1L); (yyval.node)->setLoc((yylsp[0]));}
#line 2856 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 334 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(LABELS); (yyval.node)->setLoc((yylsp[0]));}
#line 2862 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 335 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2868 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 338 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2874 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 341 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(NON_NEGATIVE_LONG,(yyvsp[0].longValue)); (yyval.node)->setLoc((yylsp[0]));}
#line 2880 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 344 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(LABEL,(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[0].node));}
#line 2886 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 345 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(LABEL,(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[0].node));}
#line 2892 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 346 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(LABEL,(yyvsp[-1].node)); (yyval.node)->setLoc((yylsp[-2]),(yylsp[0]));}
#line 2898 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 349 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(MS,(yyvsp[-3].node),(yyvsp[-1].node),(yyvsp[0].node)); (yyval.node)->setLoc((yylsp[-5]),(yyvsp[0].node));}
#line 2904 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 350 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(MS,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yylsp[-4]),(yyvsp[0].node));}
#line 2910 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 353 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-2].node)->addChild((yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 2916 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 354 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(LABELS,(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[0].node));}
#line 2922 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 358 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(ASIG); (yyval.node)->setLoc((yylsp[0]));}
#line 2928 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 359 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(INC_BY); (yyval.node)->setLoc((yylsp[0]));}
#line 2934 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 363 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2940 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 364 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node)->addChild((yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-1].node),(yyvsp[0].node));}
#line 2946 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 365 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node)->addChild((yyvsp[-1].node)); (yyval.node)->setLoc((yyvsp[-1].node),(yyvsp[0].node));}
#line 2952 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 366 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-2].node)->addChild((yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 2958 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 367 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-3].node)->addChild((yyvsp[-2].node))->addChild((yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-3].node),(yyvsp[0].node));}
#line 2964 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 368 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-2].node)->addChild((yyvsp[-3].node))->addChild((yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-3].node),(yyvsp[0].node));}
#line 2970 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 371 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(PROBABILITY,(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[0].node));}
#line 2976 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 372 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-3].node)->addChild((yyvsp[-1].node));(yyval.node)->setLoc((yyvsp[-3].node),(yylsp[0]));}
#line 2982 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 376 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(PRIORITY,(yyvsp[-1].node)); (yyval.node)->setLoc((yyvsp[-1].node));}
#line 2988 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 377 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(PRIORITY,(yyvsp[-1].node)); (yyval.node)->setLoc((yyvsp[-1].node));}
#line 2994 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 380 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(RULE,(yyvsp[-1].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-1].node),(yyvsp[0].node));}
#line 3000 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 381 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(RULE,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 3006 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 382 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(RULE,(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));(yyval.node)->setLoc((yyvsp[-3].node),(yyvsp[0].node));}
#line 3012 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 383 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(RULE,(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));(yyval.node)->setLoc((yyvsp[-4].node),(yyvsp[0].node));}
#line 3018 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 384 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(RULE,(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));(yyval.node)->setLoc((yyvsp[-4].node),(yyvsp[0].node));}
#line 3024 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 385 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(RULE,(yyvsp[-5].node),(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));(yyval.node)->setLoc((yyvsp[-5].node),(yyvsp[0].node));}
#line 3030 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 386 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(RULE,(yyvsp[-5].node),(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));(yyval.node)->setLoc((yyvsp[-5].node),(yyvsp[0].node));}
#line 3036 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 387 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(RULE,(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));(yyval.node)->setLoc((yyvsp[-3].node),(yyvsp[0].node));}
#line 3042 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 388 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(RULE,(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));(yyval.node)->setLoc((yyvsp[-4].node),(yyvsp[0].node));}
#line 3048 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 389 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(RULE,(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));(yyval.node)->setLoc((yyvsp[-4].node),(yyvsp[0].node));}
#line 3054 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 390 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(RULE,(yyvsp[-5].node),(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));(yyval.node)->setLoc((yyvsp[-5].node),(yyvsp[0].node));}
#line 3060 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 391 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(RULE,(yyvsp[-5].node),(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));(yyval.node)->setLoc((yyvsp[-5].node),(yyvsp[0].node));}
#line 3066 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 392 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(RULE,(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));(yyval.node)->setLoc((yyvsp[-4].node),(yyvsp[0].node));}
#line 3072 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 393 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(RULE,(yyvsp[-5].node),(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));(yyval.node)->setLoc((yyvsp[-5].node),(yyvsp[0].node));}
#line 3078 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 394 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(RULE,(yyvsp[-5].node),(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));(yyval.node)->setLoc((yyvsp[-5].node),(yyvsp[0].node));}
#line 3084 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 395 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(RULE,(yyvsp[-6].node),(yyvsp[-5].node),(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));(yyval.node)->setLoc((yyvsp[-6].node),(yyvsp[0].node));}
#line 3090 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 396 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(RULE,(yyvsp[-6].node),(yyvsp[-5].node),(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));(yyval.node)->setLoc((yyvsp[-6].node),(yyvsp[0].node));}
#line 3096 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 397 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(RULE,(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));(yyval.node)->setLoc((yyvsp[-4].node),(yyvsp[0].node));}
#line 3102 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 398 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(RULE,(yyvsp[-5].node),(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));(yyval.node)->setLoc((yyvsp[-5].node),(yyvsp[0].node));}
#line 3108 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 399 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(RULE,(yyvsp[-5].node),(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));(yyval.node)->setLoc((yyvsp[-5].node),(yyvsp[0].node));}
#line 3114 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 400 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(RULE,(yyvsp[-6].node),(yyvsp[-5].node),(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));(yyval.node)->setLoc((yyvsp[-6].node),(yyvsp[0].node));}
#line 3120 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 401 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(RULE,(yyvsp[-6].node),(yyvsp[-5].node),(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));(yyval.node)->setLoc((yyvsp[-6].node),(yyvsp[0].node));}
#line 3126 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 405 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(LEFT_HAND_RULE,(yyvsp[-1].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-1].node),(yyvsp[0].node));}
#line 3132 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 406 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(LEFT_HAND_RULE,(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[0].node));}
#line 3138 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 407 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(LEFT_HAND_RULE,(yyvsp[0].node),(yyvsp[-1].node)); (yyval.node)->setLoc((yyvsp[-1].node),(yyvsp[0].node));}
#line 3144 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 410 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(RIGHT_HAND_RULE,(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[0].node));}
#line 3150 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 411 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(RIGHT_HAND_RULE,(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[0].node));}
#line 3156 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 412 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(RIGHT_HAND_RULE,(yyvsp[-1].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-1].node),(yyvsp[0].node));}
#line 3162 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 413 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(RIGHT_HAND_RULE,(yyvsp[0].node),(yyvsp[-1].node)); (yyval.node)->setLoc((yyvsp[-1].node),(yyvsp[0].node));}
#line 3168 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 416 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(OUTER_MEMBRANE,(yyvsp[-1].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-1].node),(yyvsp[0].node));}
#line 3174 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 417 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(OUTER_MEMBRANE,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 3180 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 418 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(OUTER_MEMBRANE,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 3186 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 419 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(OUTER_MEMBRANE,(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-3].node),(yyvsp[0].node));}
#line 3192 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 420 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(OUTER_MEMBRANE,(yyvsp[-3].node),(yyvsp[-1].node),(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-3].node),(yyvsp[0].node));}
#line 3198 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 423 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(OUTER_MEMBRANE,(yyvsp[-1].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-1].node),(yyvsp[0].node));}
#line 3204 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 424 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(OUTER_MEMBRANE,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 3210 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 425 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(OUTER_MEMBRANE,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 3216 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 426 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(OUTER_MEMBRANE,(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-3].node),(yyvsp[0].node));}
#line 3222 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 427 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(OUTER_MEMBRANE,(yyvsp[-3].node),(yyvsp[-1].node),(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-3].node),(yyvsp[0].node));}
#line 3228 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 432 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node)->addChild((yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-1].node),(yyvsp[0].node));}
#line 3234 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 433 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(OUTER_MEMBRANES,(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[0].node));}
#line 3240 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 437 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(INNER_MEMBRANE,(yyvsp[-1].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-1].node),(yyvsp[0].node));}
#line 3246 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 438 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(INNER_MEMBRANE,(yyvsp[-2].node),(yyvsp[0].node),(yyvsp[-1].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 3252 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 441 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node)->addChild((yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-1].node),(yyvsp[0].node));}
#line 3258 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 442 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(INNER_MEMBRANES,(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[0].node));}
#line 3264 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 446 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(LONG_RIGHT_ARROW); (yyval.node)->setLoc((yylsp[0]));}
#line 3270 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 447 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(SHORT_RIGHT_ARROW); (yyval.node)->setLoc((yylsp[0]));}
#line 3276 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 448 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(LONG_DOUBLE_ARROW); (yyval.node)->setLoc((yylsp[0]));}
#line 3282 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 449 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(SHORT_DOUBLE_ARROW); (yyval.node)->setLoc((yylsp[0]));}
#line 3288 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 453 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(ASIG,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 3294 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 454 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(INC_BY,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 3300 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 455 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(DEC_BY,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 3306 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 456 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(MUL_BY,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 3312 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 457 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(DIV_BY,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 3318 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 458 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(MOD_BY,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 3324 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 459 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(BITWISE_LEFT_BY,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 3330 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 460 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(BITWISE_RIGHT_BY,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 3336 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 461 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(BITWISE_AND_BY,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 3342 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 462 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(BITWISE_OR_BY,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 3348 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 463 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(BITWISE_XOR_BY,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 3354 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 464 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 3360 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 467 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(OR,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 3366 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 468 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 3372 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 472 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(AND,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 3378 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 473 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 3384 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 477 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(BITWISE_OR,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 3390 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 478 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 3396 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 481 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(BITWISE_XOR,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 3402 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 482 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 3408 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 486 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(BITWISE_AND,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 3414 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 487 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 3420 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 490 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(EQUAL,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 3426 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 491 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(DIFF,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 3432 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 492 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 3438 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 496 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(LESS_THAN,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 3444 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 497 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(LESS_OR_EQUAL_THAN,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 3450 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 498 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(GREATER_THAN,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 3456 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 499 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(GREATER_OR_EQUAL_THAN,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 3462 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 500 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 3468 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 503 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(BITWISE_LEFT,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 3474 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 504 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(BITWISE_RIGHT,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 3480 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 505 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 3486 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 509 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(ADD,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 3492 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 510 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(SUB,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 3498 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 511 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 3504 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 514 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(MUL,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 3510 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 515 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(DIV,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 3516 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 516 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(MOD,(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->setLoc((yyvsp[-2].node),(yyvsp[0].node));}
#line 3522 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 517 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 3528 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 521 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(PLUS,(yyvsp[0].node)); (yyval.node)->setLoc((yylsp[-1]),(yyvsp[0].node));}
#line 3534 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 522 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(MINUS,(yyvsp[0].node)); (yyval.node)->setLoc((yylsp[-1]),(yyvsp[0].node));}
#line 3540 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 523 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(NOT,(yyvsp[0].node)); (yyval.node)->setLoc((yylsp[-1]),(yyvsp[0].node));}
#line 3546 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 524 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(BITWISE_NOT,(yyvsp[0].node)); (yyval.node)->setLoc((yylsp[-1]),(yyvsp[0].node));}
#line 3552 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 525 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(INC,(yyvsp[0].node)); (yyval.node)->setLoc((yylsp[-1]),(yyvsp[0].node));}
#line 3558 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 526 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(DEC,(yyvsp[0].node)); (yyval.node)->setLoc((yylsp[-1]),(yyvsp[0].node));}
#line 3564 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 527 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 3570 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 530 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(POST_INC,(yyvsp[-1].node)); (yyval.node)->setLoc((yyvsp[-1].node),(yylsp[0]));}
#line 3576 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 247:
#line 531 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(POST_DEC,(yyvsp[-1].node)); (yyval.node)->setLoc((yyvsp[-1].node),(yylsp[0]));}
#line 3582 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 248:
#line 532 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 3588 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 249:
#line 536 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(INT_TYPE,(yyvsp[0].node)); (yyval.node)->setLoc((yylsp[-3]),(yyvsp[0].node));}
#line 3594 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 250:
#line 537 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(LONG_TYPE,(yyvsp[0].node)); (yyval.node)->setLoc((yylsp[-3]),(yyvsp[0].node));}
#line 3600 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 251:
#line 538 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(DOUBLE_TYPE,(yyvsp[0].node)); (yyval.node)->setLoc((yylsp[-3]),(yyvsp[0].node));}
#line 3606 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 252:
#line 539 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(STRING_TYPE,(yyvsp[0].node)); (yyval.node)->setLoc((yylsp[-3]),(yyvsp[0].node));}
#line 3612 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 253:
#line 540 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 3618 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 254:
#line 543 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 3624 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 255:
#line 544 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(NON_NEGATIVE_DOUBLE,(yyvsp[0].doubleValue)); (yyval.node)->setLoc((yylsp[0]));}
#line 3630 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 256:
#line 545 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 3636 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 257:
#line 546 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(STRING,(yyvsp[0].stringValue)); (yyval.node)->setLoc((yylsp[0]));}
#line 3642 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 258:
#line 547 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 3648 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 259:
#line 548 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 3654 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 260:
#line 549 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(SYSTEM_CONSTANT,(yyvsp[0].node)); (yyval.node)->setLoc((yylsp[-2]),(yyvsp[0].node));}
#line 3660 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;

  case 261:
#line 550 "src/parser/plingua.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node); (yyval.node)->setLoc((yylsp[-2]),(yylsp[0]));}
#line 3666 "src/parser/y.tab.c" /* yacc.c:1646  */
    break;


#line 3670 "src/parser/y.tab.c" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 555 "src/parser/plingua.y" /* yacc.c:1906  */



int main(int argc, char* argv[]) {
	return PARSER.parse(argc,argv);
}



