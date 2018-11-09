#ifndef _NODE_VALUE_HPP_
#define _NODE_VALUE_HPP_


namespace plingua{namespace parser{

	
enum NodeValueType : unsigned int 
{
	UNKNOWN  = 0x00,	
	LONG     = 0x01, 
	DOUBLE   = 0x02,
	STR      = 0x03,
	CUNKNOWN = 0x08, 
	CLONG    = 0x09, 
	CDOUBLE  = 0x0A, 
	CSTR     = 0x0B 
}; 	


enum NodeValueError : unsigned int
{
	NO_ERROR				= 0x00, 
	UNDEFINED_OPERATION     = 0x10, 
	DIVISION_BY_ZERO        = 0x20, 
	INFINITY_NUMBER         = 0x30, 
	NOT_A_NUMBER            = 0x40, 
	INVALID_RVALUE          = 0x50, 
	INVALID_LVALUE          = 0x60, 
	GENERIC                 = 0x70, 
	UNKNOWN_VARIABLE        = 0x80
};

	
class NodeValue 
{
public:
	NodeValue(bool scan);
	NodeValue() : flags(NO_ERROR | UNKNOWN) {}
	NodeValue(NodeValueError error) : flags (error | UNKNOWN) {}
	NodeValue(NodeValueType type) : flags (NO_ERROR | type) {}
	NodeValue(const NodeValue& other);
	
	NodeValue(long value) : value(value), flags(NO_ERROR | CLONG) {}
	NodeValue(NodeValueType type, NodeValueError error, long value) : value(value), flags (error | type) {}
	NodeValue(NodeValueType type, long value) : value(value), flags(NO_ERROR | type) {}
	NodeValue(long value, bool cte) : value(value), flags(NO_ERROR | CLONG) {setCte(cte);}
	
	NodeValue(double value) :value(value), flags(NO_ERROR | CDOUBLE) {}
	NodeValue(NodeValueType type, double value) : value(value), flags (getError(value) | type) {}
	NodeValue(double value, bool cte) : value(value), flags(NO_ERROR | CDOUBLE)  {setCte(cte);}
		
	NodeValue(char* value) : value(parseString(value)), flags(NO_ERROR | CSTR) {}
	NodeValue(NodeValueType type, char* value) : value(parseString(value)), flags(NO_ERROR | type) {}
	NodeValue(char* value, bool cte) : value(parseString(value)), flags(NO_ERROR | CSTR) {setCte(cte);}
	
	~NodeValue();
	
	long getLong() const {return value.longValue;}
	double getDouble() const {return value.doubleValue;}
	const char* getString() const {return value.stringValue;}
	
	const char* getTypeAsString() const;
	NodeValueType getType() const {return (NodeValueType)(flags & TYPE_MASK);}
	
	bool isConstant() const {return (flags & CTE_MASK) != 0x00;}
	bool isLong() const {return  getType() == LONG || getType() == CLONG;}
	bool isDouble() const {return getType() == DOUBLE || getType() == CDOUBLE;}
	bool isString() const {return getType() == STR  || getType() == CSTR;}
	bool isValid() const {return !isUnknown() && !isError();}
	bool isUnknown() const {return (flags & TYPE_MASK) == UNKNOWN;}
	bool isGenericError() const {return getError()==GENERIC;}
	bool isError() const {return getError()!=NO_ERROR;}
	bool isZero() const {return (isLong() && getLong()==0L) || (isDouble() && getDouble()==0.0L);}
	bool isTrue() const {return isValid() && !isZero();}
	bool isFalse() const {return isValid() && isZero();}
	
	NodeValue& clear();
	NodeValue& set(const NodeValue& other, bool cte);
	
	NodeValueError getError() const {return (NodeValueError)(flags & ERROR_MASK);}
	const char* getErrorAsString() const;
	
	NodeValue castLong() const;
	NodeValue castDouble() const;
	NodeValue castString() const;
	
	NodeValue& operator =(const NodeValue& other);
	NodeValue operator -() const;
	NodeValue operator *(const NodeValue& other) const;
	NodeValue operator /(const NodeValue& other) const;
	NodeValue operator %(const NodeValue& other) const;
	NodeValue operator +(const NodeValue& other) const;
	NodeValue operator -(const NodeValue& other) const;
	NodeValue operator <<(const NodeValue& other) const;
	NodeValue operator >>(const NodeValue& other) const;
	NodeValue operator <(const NodeValue& other) const;
	NodeValue operator <=(const NodeValue& other) const;
	NodeValue operator >(const NodeValue& other) const;
	NodeValue operator >=(const NodeValue& other) const;
	NodeValue operator ==(const NodeValue& other) const;
	NodeValue operator !=(const NodeValue& other) const;
	NodeValue operator &(const NodeValue& other) const;
	NodeValue operator |(const NodeValue& other) const;
	NodeValue operator ^(const NodeValue& other) const;
	NodeValue operator !() const;
	NodeValue operator ~() const;
	void print(FILE *fp) const;
	
private:

	
	static const unsigned int CTE_MASK   =  0x08;
	static const unsigned int TYPE_MASK  =  0x0F;
	static const unsigned int ERROR_MASK =  0xF0;

	static char* parseString(char* str);
	static char* reverse(char* str);
	static NodeValueError getError(double value);	
	NodeValueType getType(const NodeValue& other, NodeValueType cte, NodeValueType ncte) const;
	void setCte(bool cte) {flags = cte ? flags | CTE_MASK : flags & ~CTE_MASK;}
	union ValueUnion {
		ValueUnion() : longValue(0) {}
		ValueUnion(long longValue) : longValue(longValue) {}
		ValueUnion(double doubleValue) : doubleValue(doubleValue) {}
		ValueUnion(char* stringValue) : stringValue(stringValue) {}
		long  longValue;
		double doubleValue;
		char* stringValue;
	} value;
	unsigned int flags;
};	

const NodeValue CLONG_ONE_VALUE(CLONG,1L);
const NodeValue CLONG_ZERO_VALUE(CLONG,0L);
const NodeValue LONG_ONE_VALUE(LONG,1L);
const NodeValue LONG_ZERO_VALUE(LONG,0L);

const NodeValue E_VALUE(2.71828182845904523536);
const NodeValue PI_VALUE(3.141592653589793238463);

const NodeValue UNKNOWN_VALUE;
const NodeValue UNDEFINED_OPERATION_ERROR(UNDEFINED_OPERATION);
const NodeValue DIVISION_BY_ZERO_ERROR(DIVISION_BY_ZERO);
const NodeValue INFINITY_NUMBER_ERROR(INFINITY_NUMBER);
const NodeValue NOT_A_NUMBER_ERROR(NOT_A_NUMBER);
const NodeValue INVALID_RVALUE_ERROR(INVALID_RVALUE);
const NodeValue INVALID_LVALUE_ERROR(INVALID_LVALUE);
const NodeValue UNKNOWN_VARIABLE_ERROR(UNKNOWN_VARIABLE);
const NodeValue GENERIC_ERROR(GENERIC);

}}

#endif
