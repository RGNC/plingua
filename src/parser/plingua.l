/* 
 * plingua.l:
 *
 * This file contains the FLEX lexical parser for P-Lingua
 *
 * Copyright (C) 2018  Ignacio Perez-Hurtado (perezh@us.es)
 *                     Research Group On Natural Computing
 *                     http://www.gcn.us.es 
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 *
 * You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>. 
 */

%option noyywrap
%{
	#define YY_DECL int yylex()
	#include <parser/syntax_tree.hpp>
	#include <parser/parser.hpp>
	#include "y.tab.h"
	#define YY_USER_ACTION plingua::parser::PARSER.update();
	using namespace plingua::parser;	
%}
%x IN_COMMENT1 IN_COMMENT2 

blank			     [ \t\r\n]+
letter			     [a-zA-Z]
digit			     [0-9]
hexa_digit           [0-9A-Fa-f]
id      		     ({letter}|"_"|".")({letter}|"_"|"."|{digit})*
non_negative_hex     ("0x"|"0X"){hexa_digit}+
non_negative_integer {digit}+ 
non_negative_real    ({non_negative_integer}("."{non_negative_integer})?|"."{non_negative_integer})([eE][+-]?{non_negative_integer})?
string               \"(\\.|[^"\\])*\"

%%
<INITIAL>{
"/*"           			BEGIN(IN_COMMENT1);
"//"					BEGIN(IN_COMMENT2);
{blank}  				{/* omit */}
"true"					{yylval.longValue = 1L; return (NON_NEGATIVE_LONG);}
"false"					{yylval.longValue = 0L; return (NON_NEGATIVE_LONG);}
"int_t"					{return (INT_TYPE);}
"long_t"				{return (LONG_TYPE);}
"double_t"				{return (DOUBLE_TYPE);}
"string_t"				{return (STRING_TYPE);}
"prob_t"				{return (PROB_TYPE);}
"rexp_t"				{return (REXP_TYPE);}
"def"					{return (DEF);}
"let"					{return (LET);}
"call"					{return (CALL);}
"system"				{return (SYSTEM);}
"@include"				{return (INCLUDE);}
"@model"				{return (MODEL);}
"@mu"					{return (MU);}
"@ms"					{return (MS);}
"@d"					{return (DISSOLUTION_SYMBOL);}
"@"	  			        {return (AT_SYMBOL);}
"return"				{return (RETURN);}
"?"						{return (QUESTION_MARK);}
"="						{return (ASIG);}
"#"						{return (EMPTY);}
";"						{return (SEPARATOR);}
"<"						{return (LESS_THAN);}
("<="|"=<")				{return (LESS_OR_EQUAL_THAN);}
">"						{return (GREATER_THAN);}
(">="|"=>")				{return (GREATER_OR_EQUAL_THAN);}
"-->"					{return (LONG_RIGHT_ARROW);}
"->"					{return (SHORT_RIGHT_ARROW);}
"<-->"					{return (LONG_DOUBLE_ARROW);}
"<->"					{return (SHORT_DOUBLE_ARROW);}
"=="					{return (EQUAL);}
"++"					{return (INC);}
"--"					{return (DEC);}
"&&"					{return (AND);}
"||"					{return (OR);}
"&"					    {return (BITWISE_AND);}
"|"					    {return (BITWISE_OR);}
"("						{return (LPAR);}
")"						{return (RPAR);}
"{"						{return (LBRACE);}
"}"						{return (RBRACE);}
","						{return (COMMA);}
"+"						{return (PLUS);}
"-"						{return (MINUS);}
"*"						{return (MUL);}
"'"						{return (QUOTE);}
"/"						{return (DIV);}
"%"						{return (MOD);}
"^"						{return (BITWISE_XOR);}
"::"					{return (DOUBLE_COLON);}
":"						{return (COLON);}
"["						{return (LSQUARE);}
"]"						{return (RSQUARE);}
"<>"					{return (DIFF);}
"!="					{return (DIFF);}
"+="					{return (INC_BY);}
"-="					{return (DEC_BY);}
"*="					{return (MUL_BY);}
"/="					{return (DIV_BY);}
"%="					{return (MOD_BY);}
"!"						{return (NOT);}
"~"						{return (BITWISE_NOT);}
"<<"					{return (BITWISE_LEFT);}
">>"					{return (BITWISE_RIGHT);}
"<<="					{return (BITWISE_LEFT_BY);}
">>="					{return (BITWISE_RIGHT_BY);}
"&="					{return (BITWISE_AND_BY);}
"|="					{return (BITWISE_OR_BY);}
"^="					{return (BITWISE_XOR_BY);}
"if"					{return (IF);}
"else"					{return (ELSE);}
"while"					{return (WHILE);}
"do"					{return (DO);}
"for"					{return (FOR);}
{non_negative_integer}  {yylval.longValue = atol(yytext); return (NON_NEGATIVE_LONG);}
{non_negative_hex}      {yylval.longValue = strtol(yytext,NULL,16); return (NON_NEGATIVE_LONG);}
{non_negative_real} 	{yylval.doubleValue = atof(yytext); return (NON_NEGATIVE_DOUBLE);}
{string}				{yylval.stringValue = strdup(std::string(yytext).substr(1,strlen(yytext)-2).c_str());return (STRING);}
{id}					{yylval.stringValue = strdup(yytext); return (ID);}
.						{return (SYMBOL);}
}

<IN_COMMENT1>{
"*/" BEGIN(INITIAL);
[^*]+   
"*"       
}

<IN_COMMENT2>{
"\n" BEGIN(INITIAL);
[^*\n]+
"*"
}

%% 


