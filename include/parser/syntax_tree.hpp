#ifndef _SYNTAX_TREE_HPP_
#define _SYNTAX_TREE_HPP_

#include <vector>
#include <parser/node_value.hpp>

#define YYLTYPE_IS_DECLARED
typedef struct YYLTYPE  
{
  YYLTYPE() : file(0), first_line(0), first_column(0), last_line(0), last_column(0), valid(true) {}	
  int file;	  
  int first_line;  
  int first_column;  
  int last_line;  
  int last_column; 
  bool valid;
  int getFile() const {return file;}
  int getFirstLine() const {return first_line;}
  int getFirstColumn() const {return first_column;}
  int getLastLine() const {return last_line;}
  int getLastColumn() const {return last_column;}
  void clear() 
  {
	  file=0; 
	  first_line=0; 
	  first_column=0; 
	  last_line=0; 
	  last_column=0;
  }
  void set(const YYLTYPE& from, const YYLTYPE& to) 
  {
	  file=to.file; 
	  first_line=from.first_line; 
	  first_column=from.first_column; 
	  last_line=to.last_line; 
	  last_column=to.last_column;
  }
  int print(FILE* fp) const;
} YYLTYPE;


namespace plingua{namespace parser{


class Node
{
public:	
	Node() : type(0) {}
	Node(int type) : type(type) {}	
	Node(int type, long value) :type(type), value(value) {}
	Node(int type, double value) :type(type), value(value) {}
	Node(int type, char* value) : type(type), value(value) {}
	Node(int type, Node* child) : type(type) {addChild(child);}
	Node(int type, Node* child0, Node* child1) 
	: type(type) {addChild(child0);addChild(child1);}
	Node(int type, Node* child0, Node* child1, Node* child2) 
	: type(type) {addChild(child0);addChild(child1);addChild(child2);}
	Node(int type, Node* child0, Node* child1, Node* child2, Node* child3) 
	: type(type) {addChild(child0);addChild(child1);addChild(child2);addChild(child3);}
	Node(int type, Node* child0, Node* child1, Node* child2, Node* child3, Node* child4) 
	: type(type)  {addChild(child0);addChild(child1);addChild(child2);addChild(child3);addChild(child4);}
	Node(int type, Node* child0, Node* child1, Node* child2, Node* child3, Node* child4, Node* child5) 
	: type(type)  {addChild(child0);addChild(child1);addChild(child2);addChild(child3);addChild(child4);addChild(child5);}
	Node(int type, Node* child0, Node* child1, Node* child2, Node* child3, Node* child4, Node* child5, Node* child6) 
	: type(type)  {addChild(child0);addChild(child1);addChild(child2);addChild(child3);addChild(child4);addChild(child5);addChild(child6);}
	
	virtual ~Node();
	Node* setType(int type) {Node::type = type; return this;}
	int getType() const {return type;}
	const char* getTypeAsString() const;
	void setValue(const NodeValue& value) {Node::value = value;}
	const NodeValue& getValue() const {return value;}
	int size() const {return childs.size();}
	const Node* getChild(int index) const {return childs[index];}
	Node* getChild(int index) {return childs[index];}
	const Node& operator[](int index) const {return *(childs[index]);}
	Node& operator[](int index) {return *(childs[index]);}
	Node* addChild(Node* child) {if (child!=NULL) childs.push_back(child); return this;}
	void removeChild(int index);
	const YYLTYPE& getLocation() const {return loc;}
	void clear();
	void print(FILE* fp) const;
	
	Node* setInvalidLoc() {loc.valid = false; return this;}
	Node* setLoc(const YYLTYPE& loc) {Node::loc = loc;return this;}
	Node* setLoc(const YYLTYPE& from, const YYLTYPE& to) {loc.set(from,to);return this;}
	Node* setLoc(const Node* from, const Node* to) {loc.set(from->loc,to->loc);return this;}
	Node* setLoc(const Node* from, const YYLTYPE& to) {loc.set(from->loc,to);return this;}
	Node* setLoc(const YYLTYPE& from, const Node* to) {loc.set(from,to->loc);return this;}
	Node* setLoc(const Node* other) {loc.set(other->loc,other->loc);return this;}
	
	bool isExpression() const;
private:
	static void print(FILE* fp, const Node* node, int tabs) ;
	
	int type;
	NodeValue value;
	YYLTYPE loc;
	std::vector<Node*> childs;
};

}}
#endif
