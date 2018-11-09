#include <string>
#include <vector>
#include <cmath>
#include <cstring>
#include <regex>
#include <parser/parser.hpp>
#include <parser/node_value.hpp>


const std::regex LOGN_REGEX("log[[:digit:]]+");

using namespace plingua::parser;


const NodeValue& Parser::getSystemConstant(Node& node)
{
	std::string aux;
	getVariableAsString(node,aux);
	return memory.getSystemConstant(aux,node.getLocation());
}


const NodeValue& Memory::getSystemConstant(const std::string& variable, const YYLTYPE& loc) const {
	if (variable.compare("e")==0) {
		return E_VALUE;
	}
	if (variable.compare("pi")==0 || variable.compare("PI")==0 || variable.compare("Pi")==0) {
		return PI_VALUE;
	}
	return UNKNOWN_VARIABLE_ERROR;
}


const NodeValue& Parser::doSystemCall(Node& sentence) {
	bool cte = true;
	std::string name = sentence[0].getValue().getString();
	unsigned n = sentence.size()>1 ? sentence[1].size() : 0;
	sentence.setValue(UNKNOWN_VALUE);
	std::vector<NodeValue> arguments;
	for (unsigned i=0;i<n;i++) {
		const NodeValue& value = computeValue(sentence[1][i]);
		if (value.isValid()) {
			arguments.push_back(value);
			cte = cte && value.isConstant();
		} else {
			error("invalid argument",sentence[1][i].getLocation());
		}
	}
	if (arguments.size()!=n) {
		sentence.setValue(GENERIC_ERROR);
		return sentence.getValue();
	}
	if (name.compare("print")==0 || name.compare("printn")==0 || name.compare("scan")==0) {
		for (unsigned i=0;i<n;i++) {
			fprintf(stdout,"%s",arguments[i].castString().getString());
		}
		if (name.compare("printn")==0) {
			fprintf(stdout,"\n");
		} else if (name.compare("scan")==0) {
			sentence.setValue(NodeValue(true));
		}
		
	} else if (name.compare("cos")==0 && n==1) {
		double aux = std::cos(arguments[0].castDouble().getDouble());
		sentence.setValue(NodeValue(aux,cte));
	} else if (name.compare("sin")==0 && n==1) {
		double aux = std::sin(arguments[0].castDouble().getDouble());
		sentence.setValue(NodeValue(aux,cte));
	} else if (name.compare("tan")==0 && n==1) {
		double aux = std::tan(arguments[0].castDouble().getDouble());
		sentence.setValue(NodeValue(aux,cte));
	} else if (name.compare("acos")==0 && n==1) {
		double aux = std::acos(arguments[0].castDouble().getDouble());
		sentence.setValue(NodeValue(aux,cte));
	} else if (name.compare("asin")==0 && n==1) {
		double aux = std::asin(arguments[0].castDouble().getDouble());
		sentence.setValue(NodeValue(aux,cte));
	} else if (name.compare("atan")==0 && n==1) {
		double aux = std::atan(arguments[0].castDouble().getDouble());
		sentence.setValue(NodeValue(aux,cte));
	} else if (name.compare("atan2")==0 && n==2) {
		double aux = std::atan2(arguments[0].castDouble().getDouble(),
		                        arguments[1].castDouble().getDouble());
		sentence.setValue(NodeValue(aux,cte));
	} else if (name.compare("cosh")==0 && n==1) {
		double aux = std::cosh(arguments[0].castDouble().getDouble());
		sentence.setValue(NodeValue(aux,cte));
	} else if (name.compare("sinh")==0 && n==1) {
		double aux = std::sinh(arguments[0].castDouble().getDouble());
		sentence.setValue(NodeValue(aux,cte));
	} else if (name.compare("tanh")==0 && n==1) {
		double aux = std::tanh(arguments[0].castDouble().getDouble());
		sentence.setValue(NodeValue(aux,cte));
	} else if (name.compare("acosh")==0 && n==1) {
		double aux = std::acosh(arguments[0].castDouble().getDouble());
		sentence.setValue(NodeValue(aux,cte));
	} else if (name.compare("asinh")==0 && n==1) {
		double aux = std::asinh(arguments[0].castDouble().getDouble());
		sentence.setValue(NodeValue(aux,cte));
	} else if (name.compare("atanh")==0 && n==1) {
		double aux = std::atanh(arguments[0].castDouble().getDouble());
		sentence.setValue(NodeValue(aux,cte));
	} else if (name.compare("exp")==0 && n==1) {
		double aux = std::exp(arguments[0].castDouble().getDouble());
		sentence.setValue(NodeValue(aux,cte));
	} else if (name.compare("exp2")==0 && n==1) {
		double aux = std::exp2(arguments[0].castDouble().getDouble());
		sentence.setValue(NodeValue(aux,cte));
	} else if (name.compare("log")==0 && n==1) {
		double aux = std::log(arguments[0].castDouble().getDouble());
		sentence.setValue(NodeValue(aux,cte));
	} else if (name.compare("log")==0 && n==2) {
		double aux = std::log(arguments[0].castDouble().getDouble()) /
		             std::log(arguments[1].castDouble().getDouble());
		sentence.setValue(NodeValue(aux,cte));
	} else if (std::regex_match(name,LOGN_REGEX) && n==1) {
		long base = atol(name.substr(3).c_str());
		double aux = arguments[0].castDouble().getDouble();
		aux = base==2 ? std::log2(aux) : base == 10 ? std::log10(aux) : std::log(aux) / std::log((double)base);
		sentence.setValue(NodeValue(aux,cte));
	} else if (name.compare("pow")==0 && n==2) {
		double aux = std::pow(arguments[0].castDouble().getDouble(),
		                      arguments[1].castDouble().getDouble());
		sentence.setValue(NodeValue(aux,cte));
	} else if (name.compare("sqrt")==0 && n==1) {
		double aux = std::sqrt(arguments[0].castDouble().getDouble());
		sentence.setValue(NodeValue(aux,cte));
	} else if (name.compare("ceil")==0 && n==1) {
		long aux = (long)std::ceil(arguments[0].castDouble().getDouble());
		sentence.setValue(NodeValue(aux,cte));
	} else if (name.compare("floor")==0 && n==1) {
		long aux = (long)std::floor(arguments[0].castDouble().getDouble());
		sentence.setValue(NodeValue(aux,cte));
	} else if (name.compare("round")==0 && n==1) {
		long aux = (long)std::round(arguments[0].castDouble().getDouble());
		sentence.setValue(NodeValue(aux,cte));
	} else if (name.compare("abs")==0 && n==1 && arguments[0].isLong()) {
		long aux = (long)std::abs(arguments[0].getLong());
		sentence.setValue(NodeValue(aux,cte));
	} else if (name.compare("abs")==0 && n==1) {
		double aux = std::fabs(arguments[0].castDouble().getDouble());
		sentence.setValue(NodeValue(aux,cte));
	} else if (name.compare("len")==0  && n==1) {
		long aux = strlen(arguments[0].castString().getString());
		sentence.setValue(NodeValue(aux,cte));
	} else if (name.compare("pos")==0 && n==2) {
		std::string aux(arguments[0].castString().getString());
		long pos = arguments[1].castLong().getLong();
		if (pos>=0 && pos < (long)aux.size()) {
			sentence.setValue(NodeValue(strdup(aux.substr(pos,1).c_str()),cte));
		} else {
			error("index out of range",sentence.getLocation());
			sentence.setValue(GENERIC_ERROR);
		}
	} else {
		std::string aux = "module ";
		aux+=getColorCode(BOLDWHITE);
		aux+="'";
		aux+=name;
		aux+="<";
		aux+=std::to_string(n);
		aux+=">'";
		aux+=getColorCode(RESET); 
		aux+=" not found";
		error(aux.c_str(),sentence.getLocation());
		sentence.setValue(GENERIC_ERROR);
	}
	return sentence.getValue();
}
