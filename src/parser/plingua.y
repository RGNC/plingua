/* 
 * plingua.y:
 *
 * This file contains the BISON grammar for P-Lingua
 * 
 * More information can be found in:
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
 * You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>. 
 */
 
 %{
#include <stdio.h> 
#include <parser/syntax_tree.hpp>
#include <parser/parser.hpp>

#define YYERROR_VERBOSE

#define yyerror(s) plingua::parser::PARSER.error(s,yylloc)


extern int yylex();

using namespace plingua::parser;

%}
%locations

%token MODEL ASIG SEPARATOR ID LESS_THAN GREATER_THAN
       DEF LPAR RPAR LBRACE RBRACE LET SYMBOL COMMA
       NON_NEGATIVE_LONG NON_NEGATIVE_DOUBLE DIFF SYSTEM
       PLUS MINUS MUL DIV MOD COLON LESS_OR_EQUAL_THAN 
       GREATER_OR_EQUAL_THAN CALL LSQUARE RSQUARE QUOTE MU EMPTY MS 
       LONG_RIGHT_ARROW SHORT_RIGHT_ARROW DOUBLE_COLON 
       DISSOLUTION_SYMBOL LONG_DOUBLE_ARROW SHORT_DOUBLE_ARROW 
       EQUAL AND OR NOT LABELS FEATURE EMU PROB_TYPE
       IF ELSE WHILE DO FOR INC DEC INC_BY DEC_BY MUL_BY
       DIV_BY MOD_BY BITWISE_OR BITWISE_AND BITWISE_NOT
       BITWISE_LEFT BITWISE_RIGHT BITWISE_XOR QUESTION_MARK
       BITWISE_LEFT_BY BITWISE_RIGHT_BY STRING AT_SYMBOL
       BITWISE_AND_BY BITWISE_OR_BY BITWISE_XOR_BY RETURN
       INTEGER_LITERAL DOUBLE_LITERAL STRING_LITERAL
       POST_INC POST_DEC ADD SUB DEFINITIONS ERROR MODULE
       VARIABLE ARGUMENTS PARAMETERS SENTENCES INCLUDE
       RANGES RANGE RULE INDEXES MEMBRANES MEMBRANE
       CHARGE LABEL MULTISET PATTERN RULES REXP_TYPE
       PROBABILITY PRIORITY PLINGUA ANONYMOUS_VARIABLE
       INT_TYPE LONG_TYPE DOUBLE_TYPE STRING_TYPE SYSTEM_CONSTANT
       MODEL_DEFINITION MODEL_BODY MODEL_ELEMENT SYSTEM_CALL
       INNER_MEMBRANE INNER_MEMBRANES OUTER_MEMBRANE OUTER_MEMBRANES
       RIGHT_HAND_RULE LEFT_HAND_RULE 
       
       
      
%union{
	long   longValue;
	double doubleValue;
	char*  stringValue;
	plingua::parser::Node* node;
}


%type <longValue>   NON_NEGATIVE_LONG
%type <doubleValue> NON_NEGATIVE_DOUBLE
%type <stringValue> ID STRING
%type <node>        expr0 expr5 expr10 expr20 expr30 expr40 expr45 expr50
					expr60 expr62 expr64 expr66 expr70 expr80 expr
					model definitions definition variable regular_call
					arguments parameters  module sentences system_call
					sentence if else while dowhile for instruction
					call assignment initialMembraneStructure initialMultiset
					rule ranges range rangeCmp include labels multiobject0
					membranes membrane charge lsquare rsquare increment
					label asigOrIncBy  multiset pattern rules multiset0
					multiobject ruleBody priority probability non_negative_long
					arrow id anonymous simple_assignment feature features
					model_definition model_body model_element rsquare0 
					inner_membrane inner_membranes left_outer_membrane type
					right_outer_membranes right_outer_membrane lsquare0 charge0
					right_hand_rule left_hand_rule extendMembraneStructure

			
%start plingua

%%

plingua : definitions {plingua::parser::PARSER.addNode($1);}

definitions : definitions definition {$$ = $1->addChild($2); $$->setLoc($1,$2);}
		    | definition			 {$$ = new Node(DEFINITIONS,$1); $$->setLoc($1);}
		    ;

definition : include              			           {$$ = $1;}
		   | model	              			           {$$ = $1;}
		   | model_definition     			           {$$ = $1;}
		   | pattern              			           {$$ = $1;}
		   | module	             			           {$$ = $1;}
		   | AT_SYMBOL features SEPARATOR              {$$ = $2;}
		   | AT_SYMBOL features COLON ranges SEPARATOR {$$ = $2->addChild($4);}
		   | assignment SEPARATOR 			           {$$ = $1;}
		   | assignment COLON ranges SEPARATOR         {$$ = $1->addChild($3);}
		   | error							           {$$ = new Node(ERROR); $$->setLoc(@1);}
		   ;


features :  features COMMA feature  {$$ = $1->addChild($3); $$->setLoc($1,$3);}
         |  feature                 {$$ = new Node(FEATURE,$1); $$->setLoc($1);}      
         ;

feature : simple_assignment            {$$ = $1;}
        | variable                     {$$ = $1;}
        | id LPAR type RPAR            {$$ = $1->addChild($3);$$->setLoc($1,@4);}
        ;
 
type : INT_TYPE      {$$ = new Node(INT_TYPE); }
     | LONG_TYPE     {$$ = new Node(LONG_TYPE); }
     | DOUBLE_TYPE   {$$ = new Node(DOUBLE_TYPE); }
     | STRING_TYPE   {$$ = new Node(STRING_TYPE); }
     | PROB_TYPE     {$$ = new Node(PROB_TYPE); }
     | REXP_TYPE     {$$ = new Node(REXP_TYPE); }  
     ;
         
        
model_definition : MODEL LPAR id RPAR ASIG model_body SEPARATOR {$$ = new Node(MODEL_DEFINITION, $3, $6); $$->setLoc(@1,$6);}
                 ;
                 
model_body : model_body COMMA model_element		{$$ = $1->addChild($3); $$->setLoc($1,$3);}
           | model_element						{$$ = new Node(MODEL_BODY,$1); $$->setLoc($1);}
           ;
           
model_element : AT_SYMBOL non_negative_long LBRACE model_body RBRACE {$$ = new Node(MODEL_ELEMENT,$2,$4);$$->setLoc(@1,@5);}
              | AT_SYMBOL LBRACE model_body RBRACE {$$ = new Node(MODEL_ELEMENT,$3);$$->setLoc(@1,@4);}
              | id	{$$ = $1;}
              ;                            

pattern :  NOT id LBRACE rules RBRACE {$$ = new Node(PATTERN,$2,$4); $$->setLoc(@1,@5);}
        ;
        
rules : rules rule SEPARATOR    {$$ = $1->addChild($2); $$->setLoc($1,$2);}
	  | rule SEPARATOR          {$$ = new Node(RULES,$1); $$->setLoc($1);}
	  ;


	  
model : MODEL LESS_THAN id GREATER_THAN {$$ = new Node(MODEL,$3); $$->setLoc(@1,@4);}
      ;   

include : INCLUDE STRING {$$ = new Node(INCLUDE,$2); $$->setLoc(@1,@2);}
		| INCLUDE LESS_THAN id GREATER_THAN {$$ = new Node(INCLUDE,$3); $$->setLoc(@1,@4);}
		;

id : ID {$$ = new Node(ID,$1); $$->setLoc(@1);} 
   ;
      
variable : id {$$ = new Node(VARIABLE,$1); $$->setLoc($1);}
		 | id LBRACE arguments RBRACE {$$ = new Node(VARIABLE, $1, $3->setType(INDEXES)); $$->setLoc($1,@4);}
		 ;

arguments : arguments COMMA expr {$$ = $1->addChild($3); $$->setLoc($1,$3);}
	      | expr			 	 {$$ = new Node(ARGUMENTS,$1); $$->setLoc($1);}
	  ;
		
module : DEF id LPAR RPAR LBRACE RBRACE {$$ = new Node(MODULE,$2); $$->setLoc(@1,@6);} 
       | DEF id LPAR RPAR LBRACE sentences RBRACE {$$ = new Node(MODULE,$2,$6); $$->setLoc(@1,@7);} 
       | DEF id LPAR parameters RPAR LBRACE RBRACE {$$ = new Node(MODULE,$2,$4); $$->setLoc(@1,@7);} 
	   | DEF id LPAR parameters RPAR LBRACE sentences RBRACE {$$ = new Node(MODULE,$2,$4,$7); $$->setLoc(@1,@8);}
       ;              	   

parameters : parameters COMMA id 	{$$ = $1->addChild(new Node(VARIABLE,$3)); $$->setLoc($1,$3);}
           | id 			  		{$$ = new Node(PARAMETERS,new Node(VARIABLE,$1)); $$->setLoc($1);}    
	       ;

sentences : sentences sentence	{$$ = $1->addChild($2); $$->setLoc($1,$2);}
	      | sentence			{$$ = new Node(SENTENCES,$1); $$->setLoc($1);}
	      ;

sentence : instruction SEPARATOR 		      	{$$ = $1;}
         | instruction COLON ranges SEPARATOR 	{$$ = $1->addChild($3);}
         | LBRACE sentences RBRACE 				{$$ = $2;}
         | RETURN expr SEPARATOR				{$$ = new Node(RETURN,$2); $$->setLoc(@1,$2);}
         | if  									{$$ = $1;}
         | else									{$$ = $1;}
         | while								{$$ = $1;}
         | dowhile								{$$ = $1;}
         | for									{$$ = $1;}
         | error SEPARATOR            			{$$ = new Node(ERROR); $$->setLoc(@1,@2);}
		 ;

if : IF LPAR expr RPAR sentence {$$ = new Node(IF,$3,$5); $$->setLoc(@1,$5);}
   ;
		
else : ELSE sentence {$$ = new Node(ELSE,$2); $$->setLoc(@1,$2);}
     ;	

while : WHILE LPAR expr RPAR sentence {$$ = new Node(WHILE,$3,$5); $$->setLoc(@1,$5);}
	  ;

dowhile : DO sentence WHILE LPAR expr RPAR SEPARATOR {$$ = new Node(DO,$2,$5); $$->setLoc(@1,@6);}
		;
		
for	: FOR LPAR simple_assignment SEPARATOR expr SEPARATOR increment RPAR sentence
      {$$ = new Node(FOR,$3,$5,$7,$9); $$->setLoc(@1,$9);}
    ;	
	
ranges : ranges COMMA range	{$$ = $1->addChild($3); $$->setLoc($1,$3);}
	   | range				{$$ = new Node(RANGES,$1); $$->setLoc($1);}
	   ;
	   
range : expr45 DIFF expr45					        {$$ = new Node(DIFF,$1,$3); $$->setLoc($1,$3);}
	  | expr45 rangeCmp variable rangeCmp expr45	{$$ = new Node(RANGE,$1,$2,$3,$4,$5); $$->setLoc($1,$5);}
	  ;	

rangeCmp : LESS_THAN				{$$ = new Node(LESS_THAN); $$->setLoc(@1);}
         | LESS_OR_EQUAL_THAN		{$$ = new Node(LESS_OR_EQUAL_THAN); $$->setLoc(@1);}
         ;

instruction : call						{$$ = $1;}
            | assignment				{$$ = $1;}
			| initialMembraneStructure  {$$ = $1;}
			| extendMembraneStructure   {$$ = $1;}
			| initialMultiset			{$$ = $1;}
			| rule						{$$ = $1;}
			| LBRACE sentences RBRACE   {$$ = $2;}
			;


regular_call : id LPAR RPAR		            {$$ = new Node(CALL,$1); $$->setLoc($1,@3);}
		     | id LPAR arguments RPAR	    {$$ = new Node(CALL,$1,$3); $$->setLoc($1,@4);}
             ;
          
system_call : SYSTEM DOUBLE_COLON regular_call {$$ = new Node(SYSTEM_CALL,$3); $$->setLoc(@1,$3);}
            ;

call : regular_call {$$ = $1;}
     | system_call  {$$ = $1;}
     | CALL regular_call {$$ = $2;}
     | CALL system_call {$$ = $2;}
     ;

assignment : simple_assignment			    {$$ = $1;}
		   | LET simple_assignment			{$$ = $2; $$->setLoc(@1,$2);}
		   | increment                      {$$ = $1;}
		   ;

simple_assignment : variable ASIG expr     {$$ = new Node(ASIG,$1,$3); $$->setLoc($1,$3);}
                  ;

increment :  variable INC_BY expr			{$$ = new Node(INC_BY,$1,$3); $$->setLoc($1,$3);}
		   | variable DEC_BY expr			{$$ = new Node(DEC_BY,$1,$3); $$->setLoc($1,$3);}
		   | variable MUL_BY expr			{$$ = new Node(MUL_BY,$1,$3); $$->setLoc($1,$3);}
		   | variable DIV_BY expr			{$$ = new Node(DIV_BY,$1,$3); $$->setLoc($1,$3);}
           | variable MOD_BY expr			{$$ = new Node(MOD_BY,$1,$3); $$->setLoc($1,$3);}
           | variable BITWISE_LEFT_BY expr	{$$ = new Node(BITWISE_LEFT_BY,$1,$3); $$->setLoc($1,$3);}
           | variable BITWISE_RIGHT_BY expr	{$$ = new Node(BITWISE_RIGHT_BY,$1,$3); $$->setLoc($1,$3);}
           | variable BITWISE_AND_BY expr	{$$ = new Node(BITWISE_AND_BY,$1,$3); $$->setLoc($1,$3);}
           | variable BITWISE_OR_BY expr	{$$ = new Node(BITWISE_OR_BY,$1,$3); $$->setLoc($1,$3);}
           | variable BITWISE_XOR_BY expr	{$$ = new Node(BITWISE_XOR_BY,$1,$3); $$->setLoc($1,$3);}
		   | variable INC					{$$ = new Node(POST_INC,$1); $$->setLoc($1,@2);} 
		   | variable DEC					{$$ = new Node(POST_DEC,$1); $$->setLoc($1,@2);} 
		   ;


anonymous : QUESTION_MARK						{$$ = new Node(ANONYMOUS_VARIABLE,0L); $$->setLoc(@1);}
		  | QUESTION_MARK NON_NEGATIVE_LONG		{$$ = new Node(ANONYMOUS_VARIABLE,$2+1); $$->setLoc(@1,@2);}
		  ;

initialMembraneStructure : MU ASIG membrane	 {$$ = new Node(MU,$3); $$->setLoc(@1,$3);}
                         ;

extendMembraneStructure  : MU LPAR labels RPAR INC_BY membrane  {$$ = new Node(EMU,$3,$6); $$->setLoc(@1,$6);} 
                         ;
                         
membranes : membranes membrane	{$$ = $1->addChild($2); $$->setLoc($1,$2);}
		  | membrane			{$$ = new Node(MEMBRANES,$1); $$->setLoc($1);}
		  ;


membrane : lsquare0 rsquare0				  {$$ = new Node(MEMBRANE,$1,$2); $$->setLoc($1,$2);}
         | lsquare0 membranes rsquare0        {$$ = new Node(MEMBRANE,$1,$2,$3); $$->setLoc($1,$3);}
         ;
		 
multiset : multiset COMMA multiobject {$$ = $1->addChild($3); $$->setLoc($1,$3);}
	     | multiobject				  {$$ = new Node(MULTISET,$1); $$->setLoc($1);}
	   	 ;

multiset0 : multiset0 COMMA multiobject0  {$$ = $1->addChild($3); $$->setLoc($1,$3);}
	      | multiobject0				  {$$ = new Node(MULTISET,$1); $$->setLoc($1);}
	   	  ; 

			 
multiobject : multiobject0			{$$ = $1;}
			| DISSOLUTION_SYMBOL	{$$ = new Node(DISSOLUTION_SYMBOL); $$->setLoc(@1);}
			;

multiobject0 : variable				    {$$ = $1;}
			 | variable MUL expr0	    {$$ = new Node(MUL,$1,$3); $$->setLoc($1,$3);}
			 | EMPTY					{$$ = new Node(EMPTY); $$->setLoc(@1);}
			 ;

lsquare : charge LSQUARE {$$ = $1;}
      	| LSQUARE        {$$ = new Node(CHARGE,0L); $$->setLoc(@1);}
      	;


lsquare0 : charge0 LSQUARE {$$ = $1;}
         | LSQUARE         {$$ = new Node(CHARGE,0L); $$->setLoc(@1);}
         ;
         
          

charge : PLUS			{$$ = new Node(CHARGE,1L); $$->setLoc(@1);}
       | MINUS			{$$ = new Node(CHARGE,-1L); $$->setLoc(@1);}
       | anonymous 	    {$$ = new Node(CHARGE,$1); $$->setLoc($1);}
       ;


charge0 : PLUS			{$$ = new Node(CHARGE,1L); $$->setLoc(@1);}
        | MINUS			{$$ = new Node(CHARGE,-1L); $$->setLoc(@1);}
        ;
		
rsquare : RSQUARE			   {$$ = new Node(LABELS); $$->setLoc(@1);}
		| rsquare0             {$$ = $1;} 
       	;

rsquare0 : RSQUARE QUOTE labels {$$ = $3;}
         ;

non_negative_long : NON_NEGATIVE_LONG {$$ = new Node(NON_NEGATIVE_LONG,$1); $$->setLoc(@1);}
                  ;

label : id						{$$ = new Node(LABEL,$1); $$->setLoc($1);}
	  | non_negative_long		{$$ = new Node(LABEL,$1); $$->setLoc($1);}
	  | LBRACE expr RBRACE 		{$$ = new Node(LABEL,$2); $$->setLoc(@1,@3);}
	  ;

initialMultiset : MS LPAR labels RPAR asigOrIncBy multiset0 {$$ = new Node(MS,$3,$5,$6); $$->setLoc(@1,$6);}
				| MS LPAR labels RPAR asigOrIncBy           {$$ = new Node(MS,$3,$5); $$->setLoc(@1,$5);}
				; 

labels : labels COMMA label   {$$ = $1->addChild($3); $$->setLoc($1,$3);}
       | label                {$$ = new Node(LABELS,$1); $$->setLoc($1);}
       ;

 
asigOrIncBy  : ASIG		{$$ = new Node(ASIG); $$->setLoc(@1);}
			 | INC_BY	{$$ = new Node(INC_BY); $$->setLoc(@1);}
			 ;


rule : ruleBody                                 {$$ = $1;}
     | ruleBody probability                     {$$ = $1->addChild($2); $$->setLoc($1,$2);}
     | priority ruleBody                        {$$ = $2->addChild($1); $$->setLoc($1,$2);}
     | ruleBody AT_SYMBOL features              {$$ = $1->addChild($3); $$->setLoc($1,$3);}
     | ruleBody probability AT_SYMBOL features  {$$ = $1->addChild($2)->addChild($4); $$->setLoc($1,$4);}
     | priority ruleBody AT_SYMBOL features     {$$ = $2->addChild($1)->addChild($4); $$->setLoc($1,$4);}
     ; 

probability : DOUBLE_COLON expr {$$ = new Node(PROBABILITY,$2); $$->setLoc($2);}
			| DOUBLE_COLON id LPAR type RPAR  {$$ = $2->addChild($4);$$->setLoc($2,@5);}
			;


priority : LPAR expr RPAR {$$ = new Node(PRIORITY,$2); $$->setLoc($2);}
         | LPAR anonymous RPAR {$$ = new Node(PRIORITY,$2); $$->setLoc($2);}
         ;				  

ruleBody : left_hand_rule arrow								{$$ = new Node(RULE,$1,$2); $$->setLoc($1,$2);}
         | left_hand_rule arrow right_hand_rule             {$$ = new Node(RULE,$1,$2,$3); $$->setLoc($1,$3);}
		 | lsquare multiset arrow rsquare0                            {$$ = new Node(RULE,$1,$2,$3,$4);$$->setLoc($1,$4);}
		 | lsquare multiset arrow multiset rsquare0                   {$$ = new Node(RULE,$1,$2,$3,$4,$5);$$->setLoc($1,$5);}
		 | lsquare multiset arrow inner_membranes rsquare0            {$$ = new Node(RULE,$1,$2,$3,$4,$5);$$->setLoc($1,$5);}
		 | lsquare multiset arrow multiset inner_membranes rsquare0   {$$ = new Node(RULE,$1,$2,$3,$4,$5,$6);$$->setLoc($1,$6);}
		 | lsquare multiset arrow inner_membranes multiset rsquare0   {$$ = new Node(RULE,$1,$2,$3,$4,$5,$6);$$->setLoc($1,$6);}
		 | lsquare inner_membranes arrow rsquare0                           {$$ = new Node(RULE,$1,$2,$3,$4);$$->setLoc($1,$4);}
		 | lsquare inner_membranes arrow multiset rsquare0                  {$$ = new Node(RULE,$1,$2,$3,$4,$5);$$->setLoc($1,$5);}
		 | lsquare inner_membranes arrow inner_membranes rsquare0           {$$ = new Node(RULE,$1,$2,$3,$4,$5);$$->setLoc($1,$5);}
		 | lsquare inner_membranes arrow multiset inner_membranes rsquare0  {$$ = new Node(RULE,$1,$2,$3,$4,$5,$6);$$->setLoc($1,$6);}
		 | lsquare inner_membranes arrow inner_membranes multiset rsquare0  {$$ = new Node(RULE,$1,$2,$3,$4,$5,$6);$$->setLoc($1,$6);}
		 | lsquare multiset inner_membranes arrow rsquare0                           {$$ = new Node(RULE,$1,$2,$3,$4,$5);$$->setLoc($1,$5);}
		 | lsquare multiset inner_membranes arrow multiset rsquare0                  {$$ = new Node(RULE,$1,$2,$3,$4,$5,$6);$$->setLoc($1,$6);}
		 | lsquare multiset inner_membranes arrow inner_membranes rsquare0           {$$ = new Node(RULE,$1,$2,$3,$4,$5,$6);$$->setLoc($1,$6);}
		 | lsquare multiset inner_membranes arrow multiset inner_membranes rsquare0  {$$ = new Node(RULE,$1,$2,$3,$4,$5,$6,$7);$$->setLoc($1,$7);}
		 | lsquare multiset inner_membranes arrow inner_membranes multiset rsquare0  {$$ = new Node(RULE,$1,$2,$3,$4,$5,$6,$7);$$->setLoc($1,$7);}
		 | lsquare inner_membranes multiset arrow rsquare0                           {$$ = new Node(RULE,$1,$2,$3,$4,$5);$$->setLoc($1,$5);}
		 | lsquare inner_membranes multiset arrow multiset rsquare0                  {$$ = new Node(RULE,$1,$2,$3,$4,$5,$6);$$->setLoc($1,$6);}
		 | lsquare inner_membranes multiset arrow inner_membranes rsquare0           {$$ = new Node(RULE,$1,$2,$3,$4,$5,$6);$$->setLoc($1,$6);}
		 | lsquare inner_membranes multiset arrow multiset inner_membranes rsquare0  {$$ = new Node(RULE,$1,$2,$3,$4,$5,$6,$7);$$->setLoc($1,$7);}
		 | lsquare inner_membranes multiset arrow inner_membranes multiset rsquare0  {$$ = new Node(RULE,$1,$2,$3,$4,$5,$6,$7);$$->setLoc($1,$7);}
		 ;


left_hand_rule : multiset left_outer_membrane               {$$ = new Node(LEFT_HAND_RULE,$1,$2); $$->setLoc($1,$2);}
               | left_outer_membrane						{$$ = new Node(LEFT_HAND_RULE,$1); $$->setLoc($1);}
               | left_outer_membrane multiset               {$$ = new Node(LEFT_HAND_RULE,$2,$1); $$->setLoc($1,$2);}
               ;
               
right_hand_rule : multiset						 		   {$$ = new Node(RIGHT_HAND_RULE,$1); $$->setLoc($1);}
                | right_outer_membranes                    {$$ = new Node(RIGHT_HAND_RULE,$1); $$->setLoc($1);}
                | multiset right_outer_membranes           {$$ = new Node(RIGHT_HAND_RULE,$1,$2); $$->setLoc($1,$2);}
				| right_outer_membranes multiset           {$$ = new Node(RIGHT_HAND_RULE,$2,$1); $$->setLoc($1,$2);}
				;

left_outer_membrane : lsquare rsquare0 		                     {$$ = new Node(OUTER_MEMBRANE,$1,$2); $$->setLoc($1,$2);}
                    | lsquare multiset rsquare0                  {$$ = new Node(OUTER_MEMBRANE,$1,$2,$3); $$->setLoc($1,$3);} 
                    | lsquare inner_membranes rsquare0           {$$ = new Node(OUTER_MEMBRANE,$1,$2,$3); $$->setLoc($1,$3);}
                    | lsquare multiset inner_membranes rsquare0  {$$ = new Node(OUTER_MEMBRANE,$1,$2,$3,$4); $$->setLoc($1,$4);}
                    | lsquare inner_membranes multiset rsquare0  {$$ = new Node(OUTER_MEMBRANE,$1,$3,$2,$4); $$->setLoc($1,$4);}
                    ;

right_outer_membrane : lsquare rsquare 		                     {$$ = new Node(OUTER_MEMBRANE,$1,$2); $$->setLoc($1,$2);}
                     | lsquare multiset rsquare                  {$$ = new Node(OUTER_MEMBRANE,$1,$2,$3); $$->setLoc($1,$3);} 
                     | lsquare inner_membranes rsquare           {$$ = new Node(OUTER_MEMBRANE,$1,$2,$3); $$->setLoc($1,$3);}
                     | lsquare multiset inner_membranes rsquare  {$$ = new Node(OUTER_MEMBRANE,$1,$2,$3,$4); $$->setLoc($1,$4);}
                     | lsquare inner_membranes multiset rsquare  {$$ = new Node(OUTER_MEMBRANE,$1,$3,$2,$4); $$->setLoc($1,$4);}
                     ;



right_outer_membranes : right_outer_membranes right_outer_membrane {$$ = $1->addChild($2); $$->setLoc($1,$2);} 
                      | right_outer_membrane			           {$$ = new Node(OUTER_MEMBRANES,$1); $$->setLoc($1);}
                      ;


inner_membrane : lsquare rsquare0			{$$ = new Node(INNER_MEMBRANE,$1,$2); $$->setLoc($1,$2);}
               | lsquare multiset rsquare0   {$$ = new Node(INNER_MEMBRANE,$1,$3,$2); $$->setLoc($1,$3);}
               ;
               
inner_membranes : inner_membranes inner_membrane  {$$ = $1->addChild($2); $$->setLoc($1,$2);}
                | inner_membrane				  {$$ = new Node(INNER_MEMBRANES,$1); $$->setLoc($1);}					
                ;                         
                  
	
arrow : LONG_RIGHT_ARROW  	{$$ = new Node(LONG_RIGHT_ARROW); $$->setLoc(@1);}
	  | SHORT_RIGHT_ARROW  	{$$ = new Node(SHORT_RIGHT_ARROW); $$->setLoc(@1);}
	  | LONG_DOUBLE_ARROW  	{$$ = new Node(LONG_DOUBLE_ARROW); $$->setLoc(@1);}
	  | SHORT_DOUBLE_ARROW  {$$ = new Node(SHORT_DOUBLE_ARROW); $$->setLoc(@1);} 
	  ;


expr : variable ASIG expr80         	{$$ = new Node(ASIG,$1,$3); $$->setLoc($1,$3);}
     | variable INC_BY expr80			{$$ = new Node(INC_BY,$1,$3); $$->setLoc($1,$3);}
     | variable DEC_BY expr80			{$$ = new Node(DEC_BY,$1,$3); $$->setLoc($1,$3);}
     | variable MUL_BY expr80			{$$ = new Node(MUL_BY,$1,$3); $$->setLoc($1,$3);}
     | variable DIV_BY expr80			{$$ = new Node(DIV_BY,$1,$3); $$->setLoc($1,$3);}
     | variable MOD_BY expr80			{$$ = new Node(MOD_BY,$1,$3); $$->setLoc($1,$3);}
     | variable BITWISE_LEFT_BY expr80	{$$ = new Node(BITWISE_LEFT_BY,$1,$3); $$->setLoc($1,$3);}
     | variable BITWISE_RIGHT_BY expr80	{$$ = new Node(BITWISE_RIGHT_BY,$1,$3); $$->setLoc($1,$3);}
     | variable BITWISE_AND_BY expr80	{$$ = new Node(BITWISE_AND_BY,$1,$3); $$->setLoc($1,$3);}
     | variable BITWISE_OR_BY expr80	{$$ = new Node(BITWISE_OR_BY,$1,$3); $$->setLoc($1,$3);}
     | variable BITWISE_XOR_BY expr80	{$$ = new Node(BITWISE_XOR_BY,$1,$3); $$->setLoc($1,$3);}
     | expr80							{$$ = $1;}
     ;

expr80 : expr80 OR expr70			{$$ = new Node(OR,$1,$3); $$->setLoc($1,$3);}
       | expr70						{$$ = $1;}
       ;


expr70 : expr70 AND expr66			{$$ = new Node(AND,$1,$3); $$->setLoc($1,$3);}
       | expr66						{$$ = $1;}
       ;


expr66 : expr66 BITWISE_OR expr64	{$$ = new Node(BITWISE_OR,$1,$3); $$->setLoc($1,$3);}
	   | expr64						{$$ = $1;}
	   ;

expr64 : expr64 BITWISE_XOR expr62	{$$ = new Node(BITWISE_XOR,$1,$3); $$->setLoc($1,$3);}
	   | expr62						{$$ = $1;}
	   ;


expr62 : expr62 BITWISE_AND expr60	{$$ = new Node(BITWISE_AND,$1,$3); $$->setLoc($1,$3);}
	   | expr60						{$$ = $1;}
	   ;

expr60 : expr60 EQUAL expr50  	{$$ = new Node(EQUAL,$1,$3); $$->setLoc($1,$3);}
	   | expr60 DIFF expr50		{$$ = new Node(DIFF,$1,$3); $$->setLoc($1,$3);}
	   | expr50					{$$ = $1;}
       ;


expr50 : expr50 LESS_THAN expr45				{$$ = new Node(LESS_THAN,$1,$3); $$->setLoc($1,$3);}
       | expr50 LESS_OR_EQUAL_THAN expr45		{$$ = new Node(LESS_OR_EQUAL_THAN,$1,$3); $$->setLoc($1,$3);}
       | expr50 GREATER_THAN expr45				{$$ = new Node(GREATER_THAN,$1,$3); $$->setLoc($1,$3);}
       | expr50 GREATER_OR_EQUAL_THAN expr45	{$$ = new Node(GREATER_OR_EQUAL_THAN,$1,$3); $$->setLoc($1,$3);}
       | expr45									{$$ = $1;}
       ;

expr45 : expr45 BITWISE_LEFT expr40		{$$ = new Node(BITWISE_LEFT,$1,$3); $$->setLoc($1,$3);}
	   | expr45 BITWISE_RIGHT expr40	{$$ = new Node(BITWISE_RIGHT,$1,$3); $$->setLoc($1,$3);}
	   | expr40							{$$ = $1;}
	   ;
						

expr40 : expr40 PLUS expr30  		{$$ = new Node(ADD,$1,$3); $$->setLoc($1,$3);}
	   | expr40 MINUS expr30		{$$ = new Node(SUB,$1,$3); $$->setLoc($1,$3);}
	   | expr30						{$$ = $1;}
       ;
       
expr30 : expr30 MUL expr20			{$$ = new Node(MUL,$1,$3); $$->setLoc($1,$3);}
       | expr30 DIV expr20 			{$$ = new Node(DIV,$1,$3); $$->setLoc($1,$3);}
       | expr30 MOD expr20			{$$ = new Node(MOD,$1,$3); $$->setLoc($1,$3);}
       | expr20						{$$ = $1;}
       ;
   

expr20 : PLUS expr20 				{$$ = new Node(PLUS,$2); $$->setLoc(@1,$2);}
	   | MINUS expr20				{$$ = new Node(MINUS,$2); $$->setLoc(@1,$2);}
	   | NOT expr20					{$$ = new Node(NOT,$2); $$->setLoc(@1,$2);}
	   | BITWISE_NOT expr20			{$$ = new Node(BITWISE_NOT,$2); $$->setLoc(@1,$2);}
	   | INC variable				{$$ = new Node(INC,$2); $$->setLoc(@1,$2);}
	   | DEC variable				{$$ = new Node(DEC,$2); $$->setLoc(@1,$2);}
	   | expr10						{$$ = $1;}				
	   ;
 
expr10 :  variable INC				{$$ = new Node(POST_INC,$1); $$->setLoc($1,@2);}
	   |  variable DEC 				{$$ = new Node(POST_DEC,$1); $$->setLoc($1,@2);}
	   |  expr5 					{$$ = $1;}	 
 	  ;


expr5 : LPAR INT_TYPE RPAR expr0      {$$ = new Node(INT_TYPE,$4); $$->setLoc(@1,$4);}
      | LPAR LONG_TYPE RPAR expr0     {$$ = new Node(LONG_TYPE,$4); $$->setLoc(@1,$4);}
      | LPAR DOUBLE_TYPE RPAR expr0   {$$ = new Node(DOUBLE_TYPE,$4); $$->setLoc(@1,$4);}
      | LPAR STRING_TYPE RPAR expr0	  {$$ = new Node(STRING_TYPE,$4); $$->setLoc(@1,$4);}
      | expr0						  {$$ = $1;}
      ;
       
expr0 : non_negative_long 		      {$$ = $1;}
      | NON_NEGATIVE_DOUBLE  		  {$$ = new Node(NON_NEGATIVE_DOUBLE,$1); $$->setLoc(@1);}
      | variable					  {$$ = $1;}
      | STRING						  {$$ = new Node(STRING,$1); $$->setLoc(@1);}			
      | regular_call                  {$$ = $1;}
      | system_call					  {$$ = $1;}
      | SYSTEM DOUBLE_COLON variable  {$$ = new Node(SYSTEM_CONSTANT,$3); $$->setLoc(@1,$3);}
      | LPAR expr RPAR                {$$ = $2; $$->setLoc(@1,@3);}			
      ;                


			 
%%


int main(int argc, char* argv[]) {
	return PARSER.parse(argc,argv);
}



