#ifndef _SCOPE_HPP_
#define _SCOPE_HPP_

#include <unordered_map>
#include <string>
#include <stack>
#include <cstdio>
#include <parser/syntax_tree.hpp>
#include <parser/node_value.hpp>

namespace plingua{ namespace parser
{

template<size_t SIZE, class A, class B>
class TStack	
{
public:
	struct T {
		A a;
		B b;
		void clear() {
			a.clear();
			b.clear();
		}
	};
	bool empty() const {return sp==0;}
	size_t size() const {return sp;}
	const A& topA() const {return s[sp-1].a;}
	const B& topB() const {return s[sp-1].b;}
	void push(const A& a, const B& b) {s[sp].a = a; s[sp++].b = b;}
	void pop() {s[--sp].clear();}
private:
	T s[SIZE];
	size_t sp;
};

typedef TStack<1024*1024, std::string, NodeValue> Stack;

class Scope
{
public:
	Scope() {}
	const NodeValue& setVariable(const std::string& variable, const NodeValue& value);
	const NodeValue& getVariable(const std::string& variable) const;
	bool containsVariable(const std::string& variable) const;
	void print(FILE* fp, const std::string& prefix = "") const;
	void saveToStack(Stack& stack);
	void loadFromStack(Stack& stack);
	void clear();
private:
	std::unordered_map<std::string, NodeValue> scope;
};

class Memory
{
public:
	Memory() : counter(0) {}
	const NodeValue& getVariable(const std::string& variable, const YYLTYPE& loc = YYLTYPE()) const;
	const NodeValue& setVariable(const std::string& variable, const NodeValue& value, const YYLTYPE& loc);
	bool containsLocalVariable(const std::string& variable) const {return counter>0 && localScope.containsVariable(variable);}
	bool containsGlobalVariable(const std::string& variable) const {return globalScope.containsVariable(variable);}
	void clear();
	unsigned getCounter() const {return counter;}
	void pushScope();
	void popScope();
	void printMemory(FILE* fp) const;
	const NodeValue& getSystemConstant(const std::string& variable, const YYLTYPE& loc) const;
private:
	
	unsigned counter;
	Scope globalScope;
	Scope localScope;
	Stack stack;
};


}}
#endif
