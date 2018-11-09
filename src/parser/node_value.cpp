#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <parser/node_value.hpp>
#include <regex>

using namespace plingua::parser;


const std::regex HEX_INTEGER_REGEX("0[xX][0-9a-fA-F]+");
const std::regex DEC_INTEGER_REGEX("(\\+|-)?[[:digit:]]+");
const std::regex DOUBLE_REGEX("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?((e|E)((\\+|-)?)[[:digit:]]+)?");
	
NodeValue::NodeValue(bool scan)
: flags(NO_ERROR | UNKNOWN)
{
	std::string line;
	std::getline(std::cin,line);
	if (std::regex_match(line,DEC_INTEGER_REGEX)) {
		value.longValue = atol(line.c_str());
		flags = NO_ERROR | LONG;
	} else if (std::regex_match(line,HEX_INTEGER_REGEX)) {
		value.longValue = strtol(line.c_str(),NULL,16);
		flags = NO_ERROR | LONG;
	} else if (std::regex_match(line,DOUBLE_REGEX)) {
		value.doubleValue = atof(line.c_str());
		flags = NO_ERROR | DOUBLE;
	} else {
		value.stringValue = strdup(line.c_str());
		flags = NO_ERROR | STR;
	}	
	
}	
	
	
char* NodeValue::parseString(char* str)
{
	int readingIndex=0;
	int writingIndex=0;
	bool special = false;
	while (str[readingIndex]!='\0'){
		if (special) {
			str[writingIndex++] = str[readingIndex++] == 'n' ? '\n' : str[readingIndex-1] == 't' ? '\t' : str[readingIndex-1];
			special = false;
		} else if (str[readingIndex++]=='\\') {
			special = true;
		} else {
			str[writingIndex++] = str[readingIndex-1]; 
		}
	}
	str = (char*)realloc(str,writingIndex+1);
	str[writingIndex]='\0';
	return str;
}
	
	
char* NodeValue::reverse(char *str)
{
	std::string aux(str);
	std::reverse(aux.begin(),aux.end());
	return strdup(aux.c_str());
}

NodeValue::NodeValue(const NodeValue& other)
: flags(NO_ERROR | UNKNOWN)
{
	this->operator =(other);
}	

NodeValue& NodeValue::set(const NodeValue& other, bool cte)
{
	this->operator =(other);
	setCte(cte);
	return *this;
}

NodeValueType NodeValue::getType(const NodeValue& other, NodeValueType cte, NodeValueType ncte) const
{
	return isConstant() && other.isConstant() ? cte : ncte;
}

NodeValueError NodeValue::getError(double value)
{
	if (std::isinf(value)!=0) {
		return INFINITY_NUMBER;
	}
	if (std::isnan(value)!=0) {
		return NOT_A_NUMBER;
	}
	return NO_ERROR;
}

NodeValue& NodeValue::operator =(const NodeValue& other)
{
	clear();
	flags = other.flags;
	NodeValueType type = (NodeValueType)(flags & TYPE_MASK);
	switch(type) {
		case LONG:
		case CLONG:
			value.longValue = other.value.longValue;
		break;	
		
		case DOUBLE:
		case CDOUBLE:
			value.doubleValue = other.value.doubleValue;
		break;
	
		case STR:
		case CSTR:
			value.stringValue = strdup(other.value.stringValue);
		break;
		
		default:
		;
	}
	return *this;
	
}
	
NodeValue NodeValue::operator -() const
{
	if (isError()) {
		return UNKNOWN_VALUE;
	}
	NodeValueType type = (NodeValueType)(flags & TYPE_MASK);
	switch(type) {
		case LONG:
		case CLONG:
			return NodeValue(type,-value.longValue);
			
		case DOUBLE:
		case CDOUBLE:
			return NodeValue(type,-value.doubleValue);
	
		case STR:
		case CSTR:
			return NodeValue(type,reverse(value.stringValue));
					
		default:
			return UNKNOWN_VALUE;
	}

}



NodeValue NodeValue::operator *(const NodeValue& other) const
{
	if (!isValid() || !other.isValid()) {
		return UNKNOWN_VALUE;
	}
	
	if (isLong() && other.isLong()) {
		long aux = value.longValue * other.value.longValue;
		NodeValueError error = value.longValue!=0 && aux / value.longValue !=  other.value.longValue ? INFINITY_NUMBER : NO_ERROR; 
		return NodeValue(getType(other,CLONG,LONG),error, aux);	
	}
		
	if (isLong() && other.isDouble()) {
		return NodeValue(getType(other,CDOUBLE,DOUBLE), (double)value.longValue * other.value.doubleValue);
	}
		
	if (isDouble() && other.isLong()) {
		return NodeValue(getType(other,CDOUBLE,DOUBLE), value.doubleValue * (double)other.value.longValue);
	}	
	
	if (isDouble() && other.isDouble()) {
		return NodeValue(getType(other,CDOUBLE,DOUBLE), value.doubleValue * other.value.doubleValue);
	}
	
	return UNDEFINED_OPERATION_ERROR;
}

NodeValue NodeValue::operator /(const NodeValue& other) const
{
	if (!isValid() || !other.isValid()) {
		return UNKNOWN_VALUE;
	}
	if (other.isZero()) {
		return DIVISION_BY_ZERO_ERROR;
	}
	
	if (isLong() && other.isLong()) {
		return NodeValue(getType(other,CLONG,LONG), value.longValue / other.value.longValue);	
	}
		
	if (isLong() && other.isDouble()) {
		return NodeValue(getType(other,CDOUBLE,DOUBLE), (double)value.longValue / other.value.doubleValue);
	}
		
	if (isDouble() && other.isLong()) {
		return NodeValue(getType(other,CDOUBLE,DOUBLE), value.doubleValue / (double)other.value.longValue);
	}	
	
	if (isDouble() && other.isDouble()) {
		return NodeValue(getType(other,CDOUBLE,DOUBLE), value.doubleValue / other.value.doubleValue);
	}
	
	return UNDEFINED_OPERATION_ERROR;
	
}

NodeValue NodeValue::operator %(const NodeValue& other) const
{
	if (!isValid() || !other.isValid()) {
		return UNKNOWN_VALUE;
	}
		
	if (isLong() && other.isLong()) {
		if (other.isZero()) {
			return DIVISION_BY_ZERO_ERROR;
		}
		return NodeValue(getType(other,CLONG,LONG), value.longValue % other.value.longValue);	
	}
			
	return UNDEFINED_OPERATION_ERROR;
	
	
}

NodeValue NodeValue::operator +(const NodeValue& other) const
{
	if (!isValid() || !other.isValid()) {
		return UNKNOWN_VALUE;
	}
	
	if (isLong() && other.isLong()) {
		long aux = value.longValue + other.value.longValue;
		NodeValueError error =  aux - value.longValue !=  other.value.longValue ? INFINITY_NUMBER : NO_ERROR; 
		return NodeValue(getType(other,CLONG,LONG),error, aux);	
	}
		
	if (isLong() && other.isDouble()) {
		return NodeValue(getType(other,CDOUBLE,DOUBLE), (double)value.longValue + other.value.doubleValue);
	}
	
	if (isLong() && other.isString()) {
		std::string aux = std::to_string(value.longValue);
		aux+=other.value.stringValue;
		return NodeValue(getType(other,CSTR,STR),strdup(aux.c_str()));
	}
		
	if (isDouble() && other.isLong()) {
		return NodeValue(getType(other,CDOUBLE,DOUBLE), value.doubleValue + (double)other.value.longValue);
	}	
	
	if (isDouble() && other.isDouble()) {
		return NodeValue(getType(other,CDOUBLE,DOUBLE), value.doubleValue + other.value.doubleValue);
	}
	
	if (isDouble() && other.isString()) {
		std::string aux = std::to_string(value.doubleValue);
		aux+=other.value.stringValue;
		return NodeValue(getType(other,CSTR,STR),strdup(aux.c_str()));
	}
	
	if (isString() && other.isLong()) {
		std::string aux(value.stringValue);
		aux+=std::to_string(other.value.longValue);
		return NodeValue(getType(other,CSTR,STR),strdup(aux.c_str()));
	}
	
	if (isString() && other.isDouble()) {
		std::string aux(value.stringValue);
		aux+=std::to_string(other.value.doubleValue);
		return NodeValue(getType(other,CSTR,STR),strdup(aux.c_str()));
	}
	
	if (isString() && other.isString()) {
		std::string aux(value.stringValue);
		aux+=other.value.stringValue;
		return NodeValue(getType(other,CSTR,STR),strdup(aux.c_str()));
	}
		
	return UNDEFINED_OPERATION_ERROR;
	
	
}

NodeValue NodeValue::operator !() const
{
	if (!isValid()) {
		return UNKNOWN_VALUE;
	}
	if (isLong()) {
		NodeValueType type = (NodeValueType)(flags & TYPE_MASK);
		return NodeValue(type, !value.longValue?0L:1L);	
	}
	return UNDEFINED_OPERATION_ERROR;
}

NodeValue NodeValue::operator ~() const
{
	if (!isValid()) {
		return UNKNOWN_VALUE;
	}
	if (isLong()) {
		NodeValueType type = (NodeValueType)(flags & TYPE_MASK);
		return NodeValue(type, ~value.longValue);	
	}
	return UNDEFINED_OPERATION_ERROR;
}


NodeValue NodeValue::castLong() const
{
	if (!isValid()) {
		return UNKNOWN_VALUE;
	}
	if (isLong()) {
		return *this;
	}
	
	if (isDouble()) {
		return NodeValue(isConstant()?CLONG:LONG, (long)value.doubleValue);
	}
	
	if (isString()) {
		return NodeValue(isConstant()?CLONG:LONG, strtol(value.stringValue,NULL,0));
	}
	
	return UNDEFINED_OPERATION_ERROR;
	
}

NodeValue NodeValue::castDouble() const
{
	if (!isValid()) {
		return UNKNOWN_VALUE;
	}
	if (isLong()) {
		return NodeValue(isConstant()?CDOUBLE:DOUBLE, (double)value.longValue);
	}
	
	if (isDouble()) {
		return *this;
	}
	
	if (isString()) {
		return NodeValue(isConstant()?CDOUBLE:DOUBLE, atof(value.stringValue));
	}
	
	return UNDEFINED_OPERATION_ERROR;
	
}

NodeValue NodeValue::castString() const
{
	if (!isValid()) {
		return UNKNOWN_VALUE;
	}
	if (isLong()) {
		return NodeValue(isConstant()?CSTR:STR, strdup(std::to_string(value.longValue).c_str()));
	}
	
	if (isDouble()) {
		return NodeValue(isConstant()?CSTR:STR, strdup(std::to_string(value.doubleValue).c_str()));
	}
	
	if (isString()) {
		return *this;
	}
	
	return UNDEFINED_OPERATION_ERROR;
	
}


NodeValue NodeValue::operator <<(const NodeValue& other) const
{
	if (!isValid() || !other.isValid()) {
		return UNKNOWN_VALUE;
	}
	if (isLong() && other.isLong()) {
		return NodeValue(getType(other,CLONG,LONG), value.longValue << other.value.longValue);
	}
	return UNDEFINED_OPERATION_ERROR;
}



NodeValue NodeValue::operator >>(const NodeValue& other) const
{
	if (!isValid() || !other.isValid()) {
		return UNKNOWN_VALUE;
	}
	if (isLong() && other.isLong()) {
		return NodeValue(getType(other,CLONG,LONG), value.longValue >> other.value.longValue);
	}
	return UNDEFINED_OPERATION_ERROR;

}
	
NodeValue NodeValue::operator -(const NodeValue& other) const
{
	if (!isValid() || !other.isValid()) {
		return UNKNOWN_VALUE;
	}
	
	if (isLong() && other.isLong()) {
		long aux = value.longValue - other.value.longValue;
		NodeValueError error =  -aux + value.longValue !=  other.value.longValue ? INFINITY_NUMBER : NO_ERROR; 
		return NodeValue(getType(other,CLONG,LONG),error, aux);	
	}
		
	if (isLong() && other.isDouble()) {
		return NodeValue(getType(other,CDOUBLE,DOUBLE), (double)value.longValue - other.value.doubleValue);
	}
		
	if (isDouble() && other.isLong()) {
		return NodeValue(getType(other,CDOUBLE,DOUBLE), value.doubleValue - (double)other.value.longValue);
	}	
	
	if (isDouble() && other.isDouble()) {
		return NodeValue(getType(other,CDOUBLE,DOUBLE), value.doubleValue - other.value.doubleValue);
	}
	
	return UNDEFINED_OPERATION_ERROR;
	
}

NodeValue NodeValue::operator <(const NodeValue& other) const
{
	if (!isValid() || !other.isValid()) {
		return UNKNOWN_VALUE;
	}
	
	bool expr;
	
	if (isLong() && other.isLong()) {
		expr = value.longValue < other.value.longValue;
	} else if (isLong() && other.isDouble()) {
		expr = value.longValue < other.value.doubleValue;	
	} else if (isDouble() && other.isLong()) {
		expr = value.doubleValue < other.value.longValue;	
	} else if (isDouble() && other.isDouble()) {
		expr = value.doubleValue < other.value.doubleValue;	
	} else if (isString() && other.isString()) {
		expr = strcmp(value.stringValue,other.value.stringValue)<0;	
	} else {
		return UNDEFINED_OPERATION_ERROR;
	}
	if (expr) {
		return isConstant() && other.isConstant() ? CLONG_ONE_VALUE : LONG_ONE_VALUE;
	}
	return isConstant() && other.isConstant() ? CLONG_ZERO_VALUE : LONG_ZERO_VALUE;
}

NodeValue NodeValue::operator <=(const NodeValue& other) const
{
	if (!isValid() || !other.isValid()) {
		return UNKNOWN_VALUE;
	}
	
	bool expr;
	
	if (isLong() && other.isLong()) {
		expr = value.longValue <= other.value.longValue;
	} else if (isLong() && other.isDouble()) {
		expr = value.longValue <= other.value.doubleValue;	
	} else if (isDouble() && other.isLong()) {
		expr = value.doubleValue <= other.value.longValue;	
	} else if (isDouble() && other.isDouble()) {
		expr = value.doubleValue <= other.value.doubleValue;	
	} else if (isString() && other.isString()) {
		expr = strcmp(value.stringValue,other.value.stringValue)<=0;	
	} else {
		return UNDEFINED_OPERATION_ERROR;
	}
	if (expr) {
		return isConstant() && other.isConstant() ? CLONG_ONE_VALUE : LONG_ONE_VALUE;
	}
	return isConstant() && other.isConstant() ? CLONG_ZERO_VALUE : LONG_ZERO_VALUE;
	
}


NodeValue NodeValue::operator >(const NodeValue& other) const
{
	if (!isValid() || !other.isValid()) {
		return UNKNOWN_VALUE;
	}
	
	bool expr;
	
	if (isLong() && other.isLong()) {
		expr = value.longValue > other.value.longValue;
	} else if (isLong() && other.isDouble()) {
		expr = value.longValue > other.value.doubleValue;	
	} else if (isDouble() && other.isLong()) {
		expr = value.doubleValue > other.value.longValue;	
	} else if (isDouble() && other.isDouble()) {
		expr = value.doubleValue > other.value.doubleValue;	
	} else if (isString() && other.isString()) {
		expr = strcmp(value.stringValue,other.value.stringValue)>0;	
	} else {
		return UNDEFINED_OPERATION_ERROR;
	}
	if (expr) {
		return isConstant() && other.isConstant() ? CLONG_ONE_VALUE : LONG_ONE_VALUE;
	}
	return isConstant() && other.isConstant() ? CLONG_ZERO_VALUE : LONG_ZERO_VALUE;
	
	
}


NodeValue NodeValue::operator >=(const NodeValue& other) const
{
	if (!isValid() || !other.isValid()) {
		return UNKNOWN_VALUE;
	}
	
	bool expr;
	
	if (isLong() && other.isLong()) {
		expr = value.longValue >= other.value.longValue;
	} else if (isLong() && other.isDouble()) {
		expr = value.longValue >= other.value.doubleValue;	
	} else if (isDouble() && other.isLong()) {
		expr = value.doubleValue >= other.value.longValue;	
	} else if (isDouble() && other.isDouble()) {
		expr = value.doubleValue >= other.value.doubleValue;	
	} else if (isString() && other.isString()) {
		expr = strcmp(value.stringValue,other.value.stringValue)>=0;	
	} else {
		return UNDEFINED_OPERATION_ERROR;
	}
	if (expr) {
		return isConstant() && other.isConstant() ? CLONG_ONE_VALUE : LONG_ONE_VALUE;
	}
	return isConstant() && other.isConstant() ? CLONG_ZERO_VALUE : LONG_ZERO_VALUE;
	
}

NodeValue NodeValue::operator ==(const NodeValue& other) const
{
	if (!isValid() || !other.isValid()) {
		return UNKNOWN_VALUE;
	}
	
	bool expr;
	
	if (isLong() && other.isLong()) {
		expr = value.longValue == other.value.longValue;
	} else if (isLong() && other.isDouble()) {
		expr = value.longValue == other.value.doubleValue;	
	} else if (isDouble() && other.isLong()) {
		expr = value.doubleValue == other.value.longValue;	
	} else if (isDouble() && other.isDouble()) {
		expr = value.doubleValue == other.value.doubleValue;	
	} else if (isString() && other.isString()) {
		expr = strcmp(value.stringValue,other.value.stringValue)==0;	
	} else {
		return UNDEFINED_OPERATION_ERROR;
	}
	if (expr) {
		return isConstant() && other.isConstant() ? CLONG_ONE_VALUE : LONG_ONE_VALUE;
	}
	return isConstant() && other.isConstant() ? CLONG_ZERO_VALUE : LONG_ZERO_VALUE;
	
}

NodeValue NodeValue::operator !=(const NodeValue& other) const
{
	if (!isValid() || !other.isValid()) {
		return UNKNOWN_VALUE;
	}

	bool expr;
	
	if (isLong() && other.isLong()) {
		expr = value.longValue != other.value.longValue;
	} else if (isLong() && other.isDouble()) {
		expr = value.longValue != other.value.doubleValue;	
	} else if (isDouble() && other.isLong()) {
		expr = value.doubleValue != other.value.longValue;	
	} else if (isDouble() && other.isDouble()) {
		expr = value.doubleValue != other.value.doubleValue;	
	} else if (isString() && other.isString()) {
		expr = strcmp(value.stringValue,other.value.stringValue)!=0;	
	} else {
		return UNDEFINED_OPERATION_ERROR;
	}
	if (expr) {
		return isConstant() && other.isConstant() ? CLONG_ONE_VALUE : LONG_ONE_VALUE;
	}
	return isConstant() && other.isConstant() ? CLONG_ZERO_VALUE : LONG_ZERO_VALUE;
	
}

NodeValue NodeValue::operator &(const NodeValue& other) const
{
	if (!isValid() || !other.isValid()) {
		return UNKNOWN_VALUE;
	}
	if (isLong() && other.isLong()) {
		return NodeValue(getType(other,CLONG,LONG), value.longValue & other.value.longValue);
	}
	return UNDEFINED_OPERATION_ERROR;
	
}

NodeValue NodeValue::operator |(const NodeValue& other) const
{
	if (!isValid() || !other.isValid()) {
		return UNKNOWN_VALUE;
	}
	if (isLong() && other.isLong()) {
		return NodeValue(getType(other,CLONG,LONG), value.longValue | other.value.longValue);
	}
	return UNDEFINED_OPERATION_ERROR;
	
}



NodeValue NodeValue::operator ^(const NodeValue& other) const
{
	if (!isValid() || !other.isValid()) {
		return UNKNOWN_VALUE;
	}
	if (isLong() && other.isLong()) {
		return NodeValue(getType(other,CLONG,LONG), value.longValue ^ other.value.longValue);
	}
	return UNDEFINED_OPERATION_ERROR;
	
}


const char* NodeValue::getErrorAsString() const
{
	NodeValueError error = (NodeValueError)(flags & ERROR_MASK);
	switch(error) {
		case INFINITY_NUMBER:
			return "overflow";
		break;
		case NOT_A_NUMBER:
			return "not a number";
		break;
		case DIVISION_BY_ZERO:
			return "division by zero";
		break;
		case UNDEFINED_OPERATION:
			return "undefined operation";
		break;
		case INVALID_LVALUE:
			return "invalid left-value in assignment";
		case INVALID_RVALUE:
			return "invalid right-value in assignment";
		case NO_ERROR:
		default: 
			return "";
		
	}
}

	
void NodeValue::print(FILE *fp) const
{
	NodeValueType type = (NodeValueType)(flags & TYPE_MASK);
	switch(type) {
		case LONG:
		case CLONG:
			fprintf(fp,"%ld%s",value.longValue,type==CLONG?"=":"");
			if (isError()) fprintf(fp," ");
		break;
		
		case DOUBLE:
		case CDOUBLE:
			fprintf(fp,"%f%s",value.doubleValue,type==CDOUBLE?"=":"");
			if (isError()) fprintf(fp," ");
		break;
		
		case STR:
		case CSTR:
			fprintf(fp,"%s%s",value.stringValue,type==CSTR?"=":"");
			if (isError()) fprintf(fp," ");
		break;
		
		case UNKNOWN:
		default: ;
	}
	fprintf(fp,"%s",getErrorAsString());
	
	
}
const char* NodeValue::getTypeAsString() const
{
	NodeValueType type = (NodeValueType)(flags & TYPE_MASK);
	switch(type) {
		case LONG:
			return "long";
		case CLONG:
			return "constant long";
		case DOUBLE:
			return "double";
		case CDOUBLE:
			return "constant double";
		case STR:
			return "string";
		case CSTR:
			return "constant string";
		default:
			return "unknown";
	}
}


NodeValue::~NodeValue()
{
	clear();
}

NodeValue& NodeValue::clear()
{
	NodeValueType type = (NodeValueType)(flags & TYPE_MASK);
	if (type==STR || type==CSTR) {
		free(value.stringValue);
	}	
	flags = NO_ERROR | UNKNOWN;
	value.longValue = 0;
	return *this;
}

