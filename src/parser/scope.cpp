#include <algorithm>
#include <parser/scope.hpp>
#include <parser/parser.hpp>
#include "y.tab.h"
using namespace plingua::parser;


const NodeValue& Scope::setVariable(const std::string& variable, const NodeValue& value)
{
	if (variable.empty()) {
		return INVALID_LVALUE_ERROR;
	}
	if (!value.isValid()) {
		return INVALID_RVALUE_ERROR;
	}
	NodeValue& m = scope[variable];		
	m.set(value,false);
	return m;
}

const NodeValue& Scope::getVariable(const std::string& variable) const
{
	auto it = scope.find(variable);
	if (it==scope.end()) {
		return UNKNOWN_VARIABLE_ERROR;
	}
	return it->second;
}




bool Scope::containsVariable(const std::string& variable) const
{
	return scope.find(variable) != scope.end();
}

void Scope::print(FILE* fp, const std::string& prefix) const
{
	for (auto it=scope.begin();it!=scope.end();++it) {
		fprintf(fp,"%s%s = ", prefix.c_str(),it->first.c_str());
		it->second.print(fp);
		fprintf(fp,"\n");
	}
}

const NodeValue& Memory::setVariable(const std::string& variable, const NodeValue& value, const YYLTYPE& loc) 
{
	if (counter>0) {
		const NodeValue& v1 = localScope.getVariable(variable);
		if (v1.isValid()) {
			if (PARSER.getVerbosityLevel()>=LEVEL_DEBUG_1) {
				std::string buffer = "set variable '";
				buffer += variable;
				buffer +="' = ";
				buffer += value.castString().getString();
				buffer += " in local scope ";
				buffer += std::to_string(counter);
				PARSER.error(buffer.c_str(),loc,LEVEL_DEBUG_1);
			}
			const NodeValue& v = localScope.setVariable(variable,value);
			if (PARSER.getVerbosityLevel()>=LEVEL_DEBUG_2) {
				printMemory(stdout);
			}
			return v;
		}
	}
	const NodeValue& v2 = globalScope.getVariable(variable);
	if (v2.isValid()) {
		if (PARSER.getVerbosityLevel()>=LEVEL_DEBUG_1) {
			std::string buffer = "set variable '";
			buffer += variable;
			buffer +="' = ";
			buffer += value.castString().getString();
			buffer += " in global scope";
			PARSER.error(buffer.c_str(),loc,LEVEL_DEBUG_1);
		}
		const NodeValue& v = globalScope.setVariable(variable,value);
		if (PARSER.getVerbosityLevel()>=LEVEL_DEBUG_2) {
			printMemory(stdout);
		}
		return v;
	}
	Scope& scope = counter==0 ? globalScope : localScope;
	if (PARSER.getVerbosityLevel()>=LEVEL_DEBUG_1) {
		std::string buffer = "set variable '";
		buffer += variable;
		buffer +="' = ";
		buffer += value.castString().getString();
		buffer += counter==0 ? " in global scope " : " in local scope ";
		buffer += std::to_string(counter);
		PARSER.error(buffer.c_str(),loc,LEVEL_DEBUG_1);
	}
	const NodeValue& v = scope.setVariable(variable,value);
	if (PARSER.getVerbosityLevel()>=LEVEL_DEBUG_2) {
		printMemory(stdout);
	}
	return v;
}



const NodeValue& Memory::getVariable(const std::string& variable, const YYLTYPE& loc) const
{
	if (counter>0) {
		const NodeValue& v1 = localScope.getVariable(variable);
		if (v1.isValid()) {
			if (PARSER.getVerbosityLevel()>=LEVEL_DEBUG_1) {
				std::string buffer = "get variable '";
				buffer += variable;
				buffer +="' = ";
				buffer += v1.castString().getString();
				buffer += " from local scope ";
				buffer += std::to_string(counter);
				PARSER.error(buffer.c_str(),loc,LEVEL_DEBUG_1);
			}
			return v1;
		}	
	}
	const NodeValue& v2 = globalScope.getVariable(variable);
	if (v2.isValid()) {
		if (PARSER.getVerbosityLevel()>=LEVEL_DEBUG_1) {
			std::string buffer = "get variable '";
			buffer += variable;
			buffer +="' = ";
			buffer += v2.castString().getString();
			buffer += " from global scope";
			PARSER.error(buffer.c_str(),loc,LEVEL_DEBUG_1);
		}
		return v2;
	}	
	return getSystemConstant(variable,loc);
}

void Memory::printMemory(FILE* fp) const
{
	fprintf(fp,"STACK SIZE: %lu\n",stack.size());
	globalScope.print(fp, "global ");
	if (counter>0) {
		localScope.print(fp, "local ");
	}
}

void Scope::clear() {
	scope.clear();
}


void Scope::saveToStack(Stack& stack)
{
	for (auto it = scope.begin(); it!= scope.end(); ++it) {
		stack.push(it->first,it->second);
	}
	stack.push("size",NodeValue((long)scope.size()));
}

void Memory::clear()
{
	localScope.clear();
	globalScope.clear();
	while(!stack.empty()) {
		stack.pop();
	}
	counter = 0;
}

void Scope::loadFromStack(Stack& stack) {
	long size = stack.topB().getLong();
	stack.pop();
	while(size > 0) {
		scope.emplace(std::piecewise_construct,
						std::forward_as_tuple(stack.topA()),
						std::forward_as_tuple(stack.topB()));
		stack.pop();
		--size;
	}
}


void Memory::pushScope()
{
	if (++counter == 1) {
		return;
	}
	localScope.saveToStack(stack);
	localScope.clear();
}


void Memory::popScope()
{
	if (counter==0) {
		return;
	}
	--counter;
	localScope.clear();
	if (counter>0) {
		localScope.loadFromStack(stack);
	}
}
