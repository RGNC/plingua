#ifndef _SERIALIZATION_HPP_
#define _SERIALIZATION_HPP_
#include <iostream>
#include <algorithm>
#include <cstring>
#include "cereal/types/vector.hpp"
#include "cereal/types/map.hpp"
#include "cereal/types/set.hpp"
#include "cereal/types/string.hpp"

namespace plingua {

//  VALUE CLASS
class Value {
public:
	enum Type {CHAR, UCHAR, SHORT, USHORT, INT, UINT, LONG, DOUBLE, STRING};

	Value()                         : type_(INT) {this->operator =(0);}	
	Value(long value)               : type_(INT) {this->operator =(value);}
	Value(double value)             : type_(INT) {this->operator =(value);}
	Value(const char* value)        : type_(INT) {this->operator =(value);}
	Value(const std::string& value) : type_(INT) {this->operator =(value);}
	Value(const Value& value): type_(INT) {this->operator =(value);}
	~Value() {clear();}

	Type type() const 					{return type_;}
	char as_char() const 				{return value_.charValue;}
	unsigned char as_uchar() const 		{return value_.ucharValue;}
	short as_short() const 				{return value_.shortValue;}
	unsigned short as_ushort() const 	{return value_.ushortValue;}
	int as_int() const 					{return value_.intValue;}
	unsigned int as_uint() const 		{return value_.uintValue;}
	long as_long() const				{return value_.longValue;}
	double as_double() const			{return value_.doubleValue;}
	const char* as_string() const 		{return value_.stringValue;} 
	
	long cast_long() const {
		switch(type_) {
			case CHAR:  return (long)(value_.charValue);
			case UCHAR:  return (long)(value_.ucharValue);
			case SHORT:  return (long)(value_.shortValue);
			case USHORT:  return (long)(value_.ushortValue);
			case INT:  return (long)(value_.intValue);
			case UINT:  return (long)(value_.uintValue);
			case LONG:  return value_.longValue;
			default: return 0;
		}
		
		
	}
		
	Value& operator =(char value);
	Value& operator =(unsigned char value);
	Value& operator =(short value);
	Value& operator =(unsigned short value);
	Value& operator =(int value);
	Value& operator =(unsigned int value);
	Value& operator =(long value);
	Value& operator =(double value);
	Value& operator =(const char* value);
	Value& operator =(const std::string& value);
	Value& operator =(const Value& other);
	
	template<class A> void save(A& archive) const;
	template<class A> void load(A& archive);
	
private:
	void clear();
	Type type_;
	union {
		char charValue;
		unsigned char ucharValue;
		short shortValue;
		unsigned short ushortValue;
		int intValue;
		unsigned int uintValue;
		long longValue;
		double doubleValue;
		char* stringValue;
	} value_;
};


class Multiplicity  {
public:
	Multiplicity();
	Multiplicity(std::size_t multiplicity);
	Multiplicity& operator =(std::size_t multiplicity);
	Multiplicity operator  ++(int);
	Multiplicity& operator ++();
	Multiplicity& operator +=(const Multiplicity& other);
	bool operator ==(const Multiplicity& other) const;
	bool operator  <(const Multiplicity& other) const;
	std::size_t raw() const;
	template<class A> void save(A& archive) const;
	template<class A> void load(A& archive);
private:
	std::size_t multiplicity;
};



class String 
{
public:
	String()                        {}
	String(const std::string& str)  : str_(str) {}
	String(const char* s)           : str_(s) {}
	virtual ~String() {}
	
	String& operator =(const String& other)        {str_ = other.str_; return *this;}
	String& operator =(const std::string& other)   {str_ = other; return *this;}
	String& operator =(const char* s)              {str_ = s; return *this;}
	
	const std::string& str() const {return str_;}
	std::string& str() {return str_;}
	
	bool operator ==(const String& other) const       {return str_ == other.str_;}
	bool operator !=(const String& other) const       {return str_ != other.str_;}
	bool operator  <(const String& other) const       {return str_ < other.str_;}	

	template<class A> void save(A& archive) const;
	template<class A> void load(A& archive);

private:
	std::string str_;
};

class LabelString : public String
{
public:	
	LabelString()                        {}
	LabelString(const std::string& str)  : String(str) {}
	LabelString(const char* s)           : String(s) {}
	virtual ~LabelString() {}
	
	template<class A> void save(A& archive) const;
	template<class A> void load(A& archive);
	
};

class ObjectString : public String
{
public:	
	ObjectString()                        {}
	ObjectString(const std::string& str)  : String(str) {}
	ObjectString(const char* s)           : String(s) {}
	virtual ~ObjectString() {}
	
	template<class A> void save(A& archive) const;
	template<class A> void load(A& archive);
};

class FeatureString : public String
{
public:	
	FeatureString()                        {}
	FeatureString(const std::string& str)  : String(str) {}
	FeatureString(const char* s)           : String(s) {}
	virtual ~FeatureString() {}
	
	template<class A> void save(A& archive) const;
	template<class A> void load(A& archive);
	
	
};


typedef std::vector<LabelString> Label;
typedef std::map<ObjectString,Multiplicity> Multiset;
typedef std::map<FeatureString,Value> Features;

// EXTENDED VECTOR CLASS
template<class T>
class ExtendedVector {
public:
	std::vector<T> data;
	bool operator==(const ExtendedVector<T>& other) const;
	bool operator<(const ExtendedVector<T>& other) const;
};

// LEAF MEMBRANE CLASS

class LeafMembrane {
public:
	char charge;   // charge < 0; charge == 0; charge > 0;
	Label label;
	LeafMembrane();
	const char* getChargeSymbol() const;
	bool operator==(const LeafMembrane& other) const;
	bool operator<(const LeafMembrane& other) const;
	template<class A> void serialize(A& archive);
};

// MEMBRANE CLASS

class Membrane : public LeafMembrane , public ExtendedVector<Membrane> {
public:
	bool operator==(const Membrane& other) const;
	bool operator<(const Membrane& other) const;
	template<class A> void serialize(A& archive);
};

// INNER MEMBRANE CLASS 
class IMembrane : public LeafMembrane {
public:
	Multiset multiset;
	bool operator ==(const IMembrane& other) const;
	bool operator <(const IMembrane& other) const;
	template<class A> void serialize(A& archive);
};

// OUTER MEMBRANE CLASS (ONLY FOR RULES)
class OMembrane : public IMembrane, public ExtendedVector<IMembrane> {
public:
	bool operator==(const OMembrane& other) const;
	bool operator<(const OMembrane& other) const;
	template<class A> void serialize(A& archive);
};

// HAND RULE CLASS
class HR {
public:
	Multiset multiset;
	bool operator ==(const HR& other) const;
	bool operator <(const HR& other) const;
	template<class A> void serialize(A& archive);
};

// LEFT-HAND RULE CLASS
class LHR : public HR  {
public:
	OMembrane membrane;
	bool operator==(const LHR& other) const;
	bool operator<(const LHR& other) const;
	template<class A> void serialize(A& archive);
};

// RIGHT-HAND RULE CLASS
class RHR : public HR, public ExtendedVector<OMembrane> {
public:
	bool operator==(const RHR& other) const;
	bool operator<(const RHR& other) const;
	template<class A> void serialize(A& archive);
};

// RULE CLASS
class Rule {
public:
	LHR lhr;
	char arrow;   // 0 is --> ; 1 is <--> ;
	RHR rhr;
	Features features; // extension features (probability, priority, regular expression, etc...)
	Rule () ;
	bool operator==(const Rule& other) const;
	bool operator<(const Rule& other) const;
	template<class A> void serialize(A& archive);
};


// SEMANTICS CLASS
class Semantics{
public:	
	std::size_t value;
	bool inf;
	std::set<String> patterns;
	std::vector<Semantics> childs;
	Semantics() : value(0),inf(true) {}
	void getAllPatterns(std::set<String>& allPatterns) const;
	bool operator==(const Semantics& other) const;
	bool operator<(const Semantics& other) const;
	template<class A> void serialize(A& archive);
};

// CONFIGURATION MEMBRANE
class CMembrane : public IMembrane
{
public:
	int parent;              // index of the parent membrane (-1 if root membrane)
	std::vector<int> childs; // indexes of the child membranes
	long priorityLevel;   
	Semantics semantics;
	CMembrane() : parent(-1), priorityLevel(0) {}
	template<class A> void serialize(A& archive);
};

// P SYSTEM CONFIGURATION 
class Configuration
{
public:
	unsigned long time;               // current time stamp, 0 for initial configuration.
	Multiset environment;             // environment multiset
	std::vector<CMembrane> membranes; // All the membranes in the configuration
	Configuration() : time(0) {}
	void clear();
	template<class A> void serialize(A& archive);
};

// P SYSTEM CLASS
class Psystem {
public:
	String model;						 // model
	Membrane structure;                  // initial membrane structure 
	std::map<Label, Multiset> multisets; // initial multisets 
	std::set<Rule> rules;		         // rules 
	Semantics semantics;			     // semantics	
	Features features;                   // extension features (multienvironment, confluent, etc...)
	template<class A> void save(A& archive) const;
	template<class A> void load(A& archive);
};


// P SYSTEM FILE CLASS
class File {
public:	
	std::string header;
	std::string version;
	Psystem psystem;
	template<class A> void serialize(A& archive);
};


// UID CLASS
class UId {
public:
	UId();
	template<class A> UId(A& archive, std::size_t max);
	UId(std::size_t id, std::size_t max);
	UId& operator =(std::size_t id);
	void set(std::size_t id, std::size_t max);
	std::size_t getMax() const {return max;}
	std::size_t getId() const {return id;}
	bool operator ==(const UId& other) const;
	bool operator  <(const UId& other) const;
	template<class A> void save(A& archive) const;
private:
	std::size_t max;
	std::size_t id;
};



// ALPHABET CLASS
class Alphabet {
public:	

	Alphabet(Alphabet const&) = delete;
    void operator=(Alphabet const&)  = delete;
	virtual ~Alphabet() {}
	static Alphabet& getInstance() {
      	static Alphabet singleton;
      	return singleton;
	}
	#define ALPHABET Alphabet::getInstance()	

	const UId& getObjectId(const std::string& object) const;
	const UId& getLabelId(const std::string& label) const;
	const UId& getFeatureId(const std::string& feature) const;
	const UId& getStringId(const std::string& str) const;
	const std::string& getObject(std::size_t id) const;
	const std::string& getLabel(std::size_t id) const;
	const std::string& getFeature(std::size_t id) const;
	const std::string& getString(std::size_t id) const;
	std::size_t getObjectAlphabetSize() const;
	std::size_t getLabelAlphabetSize() const;
	std::size_t getFeatureAlphabetSize() const;
	std::size_t getStringsAlphabetSize() const;
	std::size_t getMaxMultiplicity() const;
	template<class A> void save(A& archive) const;
	template<class A> void load(A& archive);
	void load(const Psystem& psystem);
private:
	Alphabet() {}
	void addMultiset(const Multiset& multiset);
	void addRule(const Rule& rule);
	void addLabel(const Label& label);
	void addMembrane(const Membrane& membrane);
	void sort();
	std::map<std::string,UId> objects;
	std::vector<std::string> objects_array;
	std::map<std::string,UId> labels;
	std::vector<std::string> labels_array;
	std::map<std::string,UId> features;
	std::vector<std::string> features_array;
	std::map<std::string,UId> strings;
	std::vector<std::string> strings_array;
	std::size_t maxMultiplicity;
};

template<class T>
void loadFromJsonFile(const std::string& path, T& data, const std::string& root = "file");

template<class T>
void loadFromXmlFile(const std::string& path, T& data, const std::string& root = "file");

template<class T>
void loadFromBinaryFile(const std::string& path, T& data, const std::string& root = "file");

template<class T>
void loadFromPortableBinaryFile(const std::string& path, T& data, const std::string& root = "file");

template<class T>
void loadFromFile(const std::string& path, T& data, const std::string& root = "file");

template<class T>	
void saveToJsonFile(const std::string& path, const T& data, const std::string& root = "file");

template<class T>
void saveToXmlFile(const std::string& path, const T& data, const std::string& root = "file");

template<class T>
void saveToBinaryFile(const std::string& path, const T& data, const std::string& root = "file");

template<class T>
void saveToPortableBinaryFile(const std::string& path, const T&data, const std::string& root = "file");

template<class T>
void saveToFile(const std::string& path, const T& data, const std::string& root = "file");

}

std::ostream& operator <<(std::ostream& os, const plingua::Multiplicity& arg);

std::ostream& operator <<(std::ostream& os, const plingua::String& arg);

std::ostream& operator <<(std::ostream& os, const plingua::Value& arg);

std::ostream& operator <<(std::ostream& os, const plingua::Label& arg);

std::ostream& operator <<(std::ostream& os, const plingua::Multiset& arg);

std::ostream& operator <<(std::ostream& os, const plingua::LeafMembrane& arg);

std::ostream& operator <<(std::ostream& os, const plingua::Membrane& arg);

std::ostream& operator <<(std::ostream& os, const plingua::IMembrane& arg);

std::ostream& operator <<(std::ostream& os, const plingua::OMembrane& arg);

std::ostream& operator <<(std::ostream& os, const plingua::HR& arg);

std::ostream& operator <<(std::ostream& os, const plingua::LHR& arg);

std::ostream& operator <<(std::ostream& os, const plingua::RHR& arg);

std::ostream& operator <<(std::ostream& os, const plingua::Rule& arg);

std::ostream& operator <<(std::ostream& os, const plingua::Semantics& arg);

std::ostream& operator <<(std::ostream& os, const plingua::Psystem& arg);

std::ostream& operator <<(std::ostream& os, const plingua::File& arg);

std::ostream& operator <<(std::ostream& os, const plingua::Configuration& arg);

#include "serialization.tcc"
#endif
