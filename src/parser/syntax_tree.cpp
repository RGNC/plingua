#include <string>
#include <cstdio>
#include <parser/parser.hpp>
#include <parser/syntax_tree.hpp>
#include "y.tab.h"

using namespace plingua::parser;


int YYLTYPE::print(FILE *fp) const
{
		
	char buffer[256];
	std::string loc;
		
	if (file >=0 && (unsigned)file<PARSER.getFiles().size()) {
		sprintf(buffer, "%s:",PARSER.getFiles()[file].filename().c_str());
		loc += buffer;
	}
	sprintf(buffer, "%d",first_line+1);
	loc += buffer;
	if (first_line < last_line) {
		sprintf(buffer,"-%d",last_line+1);
		loc += buffer;
	}
	if (first_line==last_line) {
		sprintf(buffer,":%d",first_column+1);
		loc += buffer;
		if (first_column < last_column) {
			sprintf(buffer,"-%d",last_column+1);
			loc+=buffer;
		}
	}
	loc+=": ";
	if (fp==stdout || fp==stderr) {
		fprintf(fp, "%s", PARSER.getColorCode(BOLDWHITE));
	}
	fprintf(fp, "%s",loc.c_str());
	if (fp==stdout || fp==stderr) {
		fprintf(fp,"%s", PARSER.getColorCode(RESET));
	}
	return loc.size();
}


Node::~Node() 
{
	clear();
}

void Node::clear()
{
	for (unsigned i=0;i<childs.size();i++) {
		delete childs[i];
	}
	childs.clear();
	value.clear(); 
	loc.clear();
	type = 0;
	
}


void Node::print(FILE* fp, const Node* node, int tabs) 
{
	int size = node->getLocation().print(fp);

	for (int i= size;i<30;i++) {
		fprintf(fp," ");
	}
	for (int i=0;i<tabs;i++) {
		fprintf(fp," ");
	}
	
	fprintf(fp,"%s",node->getTypeAsString());
	if (node->getValue().isValid()) {
		fprintf(fp,"(");
		node->getValue().print(fp);
		fprintf(fp,")");
	}
	
	
	fprintf(fp,"\n");
	
	for (int i=0;i<node->size();i++) {
		print(fp,node->getChild(i),tabs+1);
	}
}

void Node::print(FILE *fp) const
{
	print(fp,this,0);
}

bool Node::isExpression() const
{
	return type==VARIABLE || type==CALL || type==SYSTEM_CALL || type == SYSTEM_CONSTANT || 
	       type==INT_TYPE || type==LONG_TYPE || type==DOUBLE_TYPE || type==STRING_TYPE || 
	       type==POST_INC || type==POST_DEC || type==PLUS || type==MINUS || type==NOT || 
	       type==BITWISE_NOT || type==INC || type == DEC || type==MUL || type==DIV || type==MOD || 
	       type==ADD || type == SUB || type==BITWISE_LEFT || type==BITWISE_RIGHT || 
	       type==LESS_THAN || type==LESS_OR_EQUAL_THAN || type==GREATER_THAN ||
	       type==GREATER_OR_EQUAL_THAN || type==EQUAL || type==DIFF || type==BITWISE_AND ||
	       type==BITWISE_OR || type==BITWISE_XOR || type==AND || type==OR || type==ASIG ||
	       type==INC_BY || type==DEC_BY || type==MUL_BY || type==DIV_BY || type==MOD_BY ||
	       type==BITWISE_LEFT_BY || type==BITWISE_RIGHT_BY || type==BITWISE_AND_BY ||
	       type==BITWISE_OR_BY || type==BITWISE_XOR_BY || type==NON_NEGATIVE_LONG ||
	       type==NON_NEGATIVE_DOUBLE || type==STRING;
	
}


void Node::removeChild(int index)
{
	for (unsigned i=index+1; i< childs.size(); i++) {
		childs[i-1] = childs[i];
	}
	childs.pop_back();
}

const char* Node::getTypeAsString() const
{
	switch(type)
	{
		case MODEL : return "MODEL";
		case ID : return "ID";
		case PARAMETERS : return "PARAMETERS";
		case ASIG :  return "ASIG";
		case LESS_THAN : return "LESS_THAN";
		case GREATER_THAN : return "GREATER_THAN";
		case NON_NEGATIVE_LONG : return "NON_NEGATIVE_LONG";
		case NON_NEGATIVE_DOUBLE : return "NON_NEGATIVE_DOUBLE";
		case DIFF : return "DIFF";
		case PLUS : return "PLUS";
		case MINUS : return "MINUS";
		case DIV : return "DIV";
		case MOD : return "MOD";
		case LESS_OR_EQUAL_THAN : return "LESS_OR_EQUAL_THAN";
		case GREATER_OR_EQUAL_THAN : return "GREATER_OR_EQUAL_THAN";
		case CALL : return "CALL";
		case MU : return "MU";
		case MS : return "MS";
		case DEFINITIONS : return "DEFINITIONS";
		case ERROR : return "ERROR";
		case VARIABLE :  return "VARIABLE";
		case STRING : return "STRING";
		case ARGUMENTS : return "ARGUMENTS";
		case INDEXES : return "INDEXES";
		case MODULE : return "MODULE";
		case SENTENCES : return "SENTENCES";
		case RETURN : return "RETURN";
		case IF : return "IF";
		case ELSE : return "ELSE";
		case WHILE : return "WHILE";
		case DO : return "DO";
		case FOR : return "FOR";
		case RANGES : return "RANGES";
		case RANGE : return "RANGE";
		case INC_BY : return "INC_BY";
		case DEC_BY : return "DEC_BY";
		case MUL_BY : return "MUL_BY";
		case DIV_BY : return "DIV_BY";
		case MOD_BY : return "MOD_BY";
		case BITWISE_LEFT_BY : return "BITWISE_LEFT_BY";
		case BITWISE_RIGHT_BY : return "BITWISE_RIGHT_BY";
		case BITWISE_AND_BY : return "BITWISE_AND_BY";
		case BITWISE_OR_BY : return "BITWISE_OR_BY";
		case BITWISE_XOR_BY : return "BITWISE_XOR_BY";
		case OR : return "OR";
		case AND : return "AND";
		case BITWISE_AND : return "BITWISE_AND";
		case BITWISE_OR : return "BITWISE_OR";
		case BITWISE_XOR : return "BITWISE_XOR";
		case ADD : return "ADD";
		case SUB : return "SUB";
		case EQUAL : return "EQUAL"; 
		case BITWISE_LEFT : return "BITWISE_LEFT";
		case BITWISE_RIGHT : return "BITWISE_RIGHT";
		case MUL : return "MUL";
		case NOT : return "NOT";
		case BITWISE_NOT : return "BITWISE_NOT";
		case INC : return "PRE_INC";
		case DEC : return "PRE_DEC";
		case POST_INC : return "POST_INC";
		case POST_DEC : return "POST_DEC";
		case MEMBRANES : return "MEMBRANES";
		case MEMBRANE : return "MEMBRANE";
		case CHARGE : return "CHARGE";
		case LABEL : return "LABEL";
		case DISSOLUTION_SYMBOL : return "DISSOLUTION_SYMBOL";
		case MULTISET : return "MULTISET";
		case PRIORITY : return "PRIORITY";
		case PROBABILITY : return "PROBABILITY";
		case LONG_RIGHT_ARROW : return "LONG_RIGHT_ARROW";
	    case SHORT_RIGHT_ARROW : return "SHORT_RIGHT_ARROW";
	    case LONG_DOUBLE_ARROW : return "LONG_DOUBLE_ARROW";
	    case SHORT_DOUBLE_ARROW : return "SHORT_DOUBLE_ARROW";
	    case RULE : return "RULE";
	    case EMPTY : return "EMPTY";
	    case PLINGUA : return "PLINGUA";
	    case INT_TYPE : return "int_t";
	    case LONG_TYPE : return "long_t";
	    case DOUBLE_TYPE : return "double_t";
	    case STRING_TYPE : return "string_t";
	    case INCLUDE : return "INCLUDE";
	    case ANONYMOUS_VARIABLE : return "ANONYMOUS_VARIABLE";
	    case PATTERN : return "PATTERN";
	    case RULES : return "RULES";
	    case MODEL_DEFINITION : return "MODEL_DEFINITION";
	    case MODEL_BODY : return "MODEL_BODY";
	    case MODEL_ELEMENT : return "MODEL_ELEMENT";
	    case SYSTEM_CALL : return "SYSTEM_CALL";
	    case SYSTEM_CONSTANT : return "SYSTEM_CONSTANT";
	    case INNER_MEMBRANE : return "INNER_MEMBRANE";
	    case INNER_MEMBRANES : return "INNER_MEMBRANES";
	    case OUTER_MEMBRANE : return "OUTER_MEMBRANE";
	    case OUTER_MEMBRANES : return "OUTER_MEMBRANES";
	    case LEFT_HAND_RULE : return "LEFT_HAND_RULE";
	    case RIGHT_HAND_RULE : return "RIGHT_HAND_RULE";
	    case FEATURE : return "FEATURE";
	    case EMU : return "EXTEND_MU";
	    case PROB_TYPE: return "prob_t";
	    case REXP_TYPE: return "rexp_t";
		default : return "UNKNOWN";
		
	}
	
	
}




