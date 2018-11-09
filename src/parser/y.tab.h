/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 69 "src/parser/plingua.y" /* yacc.c:1909  */

	long   longValue;
	double doubleValue;
	char*  stringValue;
	plingua::parser::Node* node;

#line 305 "src/parser/y.tab.h" /* yacc.c:1909  */
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
