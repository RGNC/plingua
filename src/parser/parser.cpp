#include <cstdio>
#include <cmath>
#include <iostream>
#include <sstream>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <unordered_set>
#include <formats.hpp>
#include <parser/gtest.hpp>
#include <parser/parser.hpp>
#include <parser/constants.hpp>
#include "y.tab.h"

using namespace plingua::parser;

extern FILE* yyin;
extern char* yytext;
extern YYLTYPE yylloc;
extern int yyparse();


const std::string RETURN_VARIABLE("@return");
const FloatingPoint<double> FLOATING_POINT_ZERO(FloatingPoint<double>::kZeroValueInBits);
const FloatingPoint<double> FLOATING_POINT_ONE(FloatingPoint<double>::kOneValueInBits);

Parser::Parser() 
: mainCall(CALL,new Node(ID,strdup("main"))),
  usingColors(true)
{
	mainCall.setInvalidLoc();
}
		
const char* Parser::getColorCode(Color color) const
{
	if (!usingColors) {
		return "";
	}
	switch(color) {
		case RESET      : return "\033[0m";
		case BLACK      : return "\033[30m";
		case RED        : return "\033[31m";
		case GREEN      : return "\033[32m";
		case YELLOW     : return "\033[33m";
		case BLUE       : return "\033[34m";
		case MAGENTA    : return "\033[35m";
		case CYAN       : return "\033[36m";
		case WHITE      : return "\033[37m";
		case BOLDBLACK  : return "\033[1m\033[30m";
		case BOLDRED    : return "\033[1m\033[31m";
		case BOLDGREEN  : return "\033[1m\033[32m";
		case BOLDYELLOW : return "\033[1m\033[33m";
		case BOLDBLUE   : return "\033[1m\033[34m";
		case BOLDMAGENTA: return "\033[1m\033[35m";
		case BOLDCYAN   : return "\033[1m\033[36m";
		case BOLDWHITE  : return "\033[1m\033[37m";
		default : return "";
	}
}
	
void Parser::addNode(Node* node)
{
	if (errorCounter==0) {
		readIncludes(*node);
	}
	
	if (errorCounter==0) {
		readModules(*node);
	}
	
	if (errorCounter==0) {
		readGlobalVariables(*node);
	}
	
	if (errorCounter==0) {
		readPatterns(*node);
	}
	
	if (errorCounter==0) {
		readSemantics(*node);
	}
		
	if (errorCounter==0) {
		readModel(*node);
	}
	
	if (errorCounter==0) {
		root.addChild(node);
	}
}

void Parser::update()
{
	int firstLine = currentLine;
	int firstColumn = currentColumn;
	for(char* s = yytext; *s != '\0'; s++)
	{
		if(*s == '\n'){
			currentLine++;
			currentColumn = 0;
		}else{
			currentColumn++;
		}
	}
	yylloc.file = currentFile;
	yylloc.first_line = firstLine;
	yylloc.first_column = firstColumn;
	yylloc.last_line = currentLine;
	yylloc.last_column = currentColumn - 1;
	
}	

void Parser::error(const char* s, ErrorLevel level, bool printProgramName)
{
	if (verbosityLevel>=level) {
		if (printProgramName) {
			fprintf(stdout,"%s%s: %s", getColorCode(BOLDWHITE),PROGRAM_NAME.c_str(),getColorCode(RESET));
		}
		switch(level) {
			case LEVEL_FATAL: fprintf(stdout,"%sfatal error: %s",getColorCode(BOLDRED),getColorCode(RESET)); break;
			case LEVEL_ERROR: fprintf(stdout,"%serror: %s",getColorCode(BOLDRED),getColorCode(RESET)); break;
			case LEVEL_WARNING: fprintf(stdout,"%swarning: %s",getColorCode(BOLDMAGENTA),getColorCode(RESET)); break;
			case LEVEL_INFO: fprintf(stdout,"%sinfo: %s",getColorCode(BOLDWHITE),getColorCode(RESET)); break;
			default : fprintf(stdout,"%sdebug: %s",getColorCode(BOLDBLUE),getColorCode(RESET)); break;
		}
		fprintf(stdout,"%s\n",s);
	}
	
	if (level==LEVEL_FATAL || level==LEVEL_ERROR) {
		errorCounter++;
	} else if (level==LEVEL_WARNING) {
		warningCounter++;
	}
}

void Parser::error(const char* s, const YYLTYPE& location, ErrorLevel level)
{
	if (verbosityLevel>=level && location.valid) {
		location.print(stdout);
	}
	error(s, level, !location.valid);
	if (verbosityLevel>=level && location.valid) {
		fprintf(stdout,"%s\n",lines[location.getFile()][location.getFirstLine()].c_str());
		int initColumn = location.getFirstColumn();
		for (int i=0;i<initColumn;i++) {
			fprintf(stdout," ");
		}
		if (location.getFirstLine()==location.getLastLine()) {
			fprintf(stdout,"%s",getColorCode(BOLDGREEN));
			for (int i=initColumn; i<= location.getLastColumn(); i++) {
				fprintf(stdout,"^");
			}
			fprintf(stdout,"%s\n", getColorCode(RESET));
		} else {
			fprintf(stdout,"%s^%s\n",getColorCode(BOLDGREEN),getColorCode(RESET));
		}
	}
}


void Parser::readLines(unsigned fileNumber)
{
	std::string line;
	std::ifstream file(files[fileNumber].c_str(),std::ifstream::in);
	if (fileNumber>=lines.size()) {
		lines.resize(fileNumber+1);
	}
	while (std::getline(file, line)) {
		std::replace(line.begin(), line.end(), '\t', ' ');
		lines[fileNumber].push_back(line);
	}
	file.close();
}


bool Parser::findMembrane(const Label& label, const Membrane& membrane)
{
	if (label == membrane.label) {
		return true;
	}
	for (auto it = membrane.data.begin(); it!= membrane.data.end(); ++it) {
		if (findMembrane(label,*it)) {
			return true;
		}
	}
	return false;
}

bool Parser::addSemantics()
{
	if (file.psystem.model.str().empty()) {
		error("no model defined",LEVEL_WARNING);
		patterns.clear();
		return true;
	}
	if (models.count(file.psystem.model.str())==0) {
		std::string buffer = "undefined model '"+file.psystem.model.str()+"'";
		error(buffer.c_str());
		return false;
	}
	file.psystem.semantics = models.at(file.psystem.model.str());
	std::set<String> aux;
	file.psystem.semantics.getAllPatterns(aux);
	auto it = patterns.begin();
	while (it != patterns.end()) {
		String s(it->first);
		if (aux.count(s)>0) {
			++it;
		} else {
			it = patterns.erase(it);
		}
	}
	return true;
}


bool Parser::checkData()
{
	bool success = true;
	if (!hasStructure && !outputFile.empty()) {
		error("missing initial membrane structure");
		return false;
	}
	return success;
}


bool Parser::generateOutput()
{
	if (verbosityLevel>=LEVEL_DEBUG_3) {
		std::cout << file << "\n";
	}
	if (outputFile.empty()) {
		return true;
	}
	Format format;
	bool success = false;
	for (unsigned i=0;i<maxFormats && !success;i++) {
		if (outputFormat.compare(formatId[i])==0) {
			format = (Format)i;
			success= true;
		}
	}
	if (!success) {
		std::ostringstream os;
		os << "unrecognised format '" << outputFormat << "'";
		error(os.str().c_str(),LEVEL_FATAL);
	    return false;
	}
	return codify(format,file,outputFile);
}


int Parser::parse(int argc, char* argv[])
{
	init(argc,argv);
	for(unsigned i=0; i< files.size(); i++) {
		readLines(i);
		currentFile = i;
		currentLine = 0;
		currentColumn = 0;
		yyin = fopen(files[i].c_str(),"r");
		if (yyin==NULL) {
			std::string buffer = "unable to open ";
			buffer += getColorCode(BOLDWHITE);
			buffer += "'";
			buffer += files[i].c_str();
			buffer += "'";
			buffer += getColorCode(RESET);
			error(buffer.c_str(),LEVEL_FATAL);
			continue;
		}
		do{
			yyparse();
		}while(!feof(yyin));
		fclose(yyin);
	}
	if (errorCounter==0 && root.size()>0 &&
		   addSemantics() &&
	       unrollSentence(mainCall) && 
	       errorCounter==0 && checkData() ) {
		generateOutput();
	}
	if (verbosityLevel>=LEVEL_DEBUG_2) {
		memory.printMemory(stdout);
	}
	if (verbosityLevel>=LEVEL_DEBUG_4) {
		root.print(stdout);
	}
	finishMessage();
	return errorCounter==0 ? EXIT_SUCCESS : EXIT_FAILURE;
}	

void Parser::finishMessage() const
{
	if (errorCounter==0 && warningCounter>0) {
		fprintf(stdout,"%sfinished with %d warning%s.\n%s",getColorCode(BOLDWHITE),warningCounter,warningCounter>1?"s":"",getColorCode(RESET));
		
	} else if (errorCounter>0 && warningCounter==0) {
		fprintf(stdout,"%sfinished with %d error%s.\n%s",getColorCode(BOLDWHITE),errorCounter,errorCounter>1?"s":"",getColorCode(RESET));
		
	} else if (errorCounter>0 && warningCounter>0){
		fprintf(stdout,"%sfinished with %d error%s and %d warning%s.\n%s",getColorCode(BOLDWHITE),errorCounter,errorCounter>1?"s":"",warningCounter,warningCounter>1?"s":"",getColorCode(RESET));
	}
}


bool Parser::getVariableAsString(Node& variable, std::string& str)
{
	bool success = true;
	
	for (int i=0;i<variable.size();i++) {
		if (variable[i].getType()==ID) {
			str = variable[i].getValue().getString();
		} else if (variable[i].getType()==INDEXES) {
			str+="{";
			for(int j=0;j<variable[i].size();j++) {
				const NodeValue& value = computeValue(variable[i][j]);
				if ((!value.isError() && value.isUnknown()) || value.isGenericError() || (value.isValid() && !value.isLong())) {
					error("invalid index",variable[i][j].getLocation());
					success=false;
				}
				str+=value.castString().getString();
				if (j+1<variable[i].size()) {
					str+=",";
				}
			}
			str+="}";
		} 
		
	}
	if (!success) {
		str="";
	}
	return success;
}


const NodeValue& Parser::setVariable(Node& node, const NodeValue& value) 
{
	std::string aux;
	getVariableAsString(node,aux);
	return memory.setVariable(aux,value,node.getLocation());
}



const NodeValue& Parser::getVariable(Node& node)
{
	std::string aux;
	getVariableAsString(node,aux);
	return memory.getVariable(aux,node.getLocation());
}


void Parser::addInclude(Node& id, bool ignoreWarning)
{
	using namespace boost::filesystem;
	const char* file = id.getValue().getString();
	for (unsigned i=0;i<includePaths.size();i++) {
		path p = absolute(path(file),includePaths[i]);
		if (is_regular_file(p)) {
			addFile(p,true);
			return;
		} 
	}
	path p = absolute(path(file),files[currentFile].parent_path());
	if (is_regular_file(p)) {
		addFile(p,true);
		return;
	}
	std::string buffer = "cannot find file ";
	buffer += getColorCode(BOLDWHITE);
	buffer += "'";
	buffer += file;
	buffer += "'";
	buffer += getColorCode(RESET);
	error(buffer.c_str(),id.getLocation(),LEVEL_FATAL);
	
}

void Parser::readIncludes(Node& node)
{
	for (int i=0; i<node.size(); i++) {
		if (node[i].getType()==INCLUDE && node[i].size()==0) {
			addFile(node[i].getValue().getString(),files[currentFile],true);
		} else if (node[i].getType()==INCLUDE) {
			addInclude(node[i][0],true);
		}
	}
}

void Parser::readSemantics(Node& node)
{
	for (int i=0;i<node.size(); i++) {
		if (node[i].getType()==MODEL_DEFINITION) {
			unrollSemantics(node[i]);
		}
	}
}



void Parser::readModules(Node& node)
{
	std::string buffer,aux;
	for (int i=0; i<node.size(); i++) {
		if (node[i].getType()==MODULE && setModule(&node[i]) == NULL) {
			buffer = "duplicated module ";
			buffer += getColorCode(BOLDWHITE);
			buffer += "'";
			buffer += getModuleAsString(node[i],aux);
			buffer += "'";
			buffer += getColorCode(RESET);
			error(buffer.c_str(),node[i].getLocation());
		}
	}
}

void Parser::readGlobalVariables(Node& node)
{
	for (int i=0; i<node.size(); i++) {
		if (node[i].isExpression() || node[i].getType() == FEATURE) {
			unrollSentence(node[i]);
		}
	}
}


void Parser::readModel(Node& node)
{
	for (int i=0;i<node.size();i++) {
		
		if (node[i].getType() != MODEL) {
			continue;
		}
		if (!file.psystem.model.str().empty()) {
			error("duplicated model declaration",node[i].getLocation());
		} else {
			file.psystem.model =  node[i][0].getValue().getString();
			std::string buffer = "Using model '"+file.psystem.model.str()+"'";
			error(buffer.c_str(),LEVEL_DEBUG_1);
		}
	}
	
}

void Parser::readPatterns(Node& node)
{
	for (int i=0; i< node.size(); i++) {
		if (node[i].getType() == PATTERN) {
			unrollPattern(node[i]);
		}
	}
}

bool Parser::unrollPattern(Node& node)
{
	bool success=true;
	std::string id = node[0].getValue().getString();
	Node& rules = node[1];
	for (int i=0; i< rules.size(); i++) {
		success = unrollRule(rules[i],id) ? success : false;
	}
	return success;
}

void Parser::unrollSemantics(Node& node)
{
	std::string id = node[0].getValue().getString();
	if (models.count(id)) {
		error("duplicated model definition",node[0].getLocation());
	}
	Semantics semantics;
	std::set<std::string> patterns;
	if (unrollSemanticsBody(node[1],semantics,std::numeric_limits<unsigned>::max(),patterns)) {
		models[id] = semantics;
	} 
}

bool Parser::unrollSemanticsBody(Node& node, Semantics& semantics, unsigned value, std::set<std::string>& patterns)
{
	bool success = true;
	for (int i=0;i< node.size(); i++) {
		if (node[i].getType()==ID) {
			std::string pattern = node[i].getValue().getString();
			if (patterns.count(pattern)>0) {
				error("duplicated pattern",node[i].getLocation());
				success = false;
			}
			semantics.patterns.emplace(pattern);
		} else if (node[i].getType()==MODEL_ELEMENT) {
			Semantics child;
			child.value = (unsigned)node[i][0].getValue().getLong();
			if (child.value==0 || child.value > value) {
				error("invalid bound",node[i][0].getLocation());
				success = false;
			}
			child.inf = false;
			success = unrollSemanticsBody(node[i][1],child,child.value,patterns) ? success : false;
			semantics.childs.push_back(child);
		}
	}
	return success;
}


bool Parser::unrollSentence(Node& sentence)
{
	if (sentence.size()==0 || sentence[sentence.size()-1].getType()!=RANGES) {
		return unrollSentenceB(sentence);
	}
	
	return unrollSentenceR(sentence,sentence[sentence.size()-1],0);
}

bool Parser::unrollSentenceR(Node& sentence, Node& ranges, int index)
{
	if (memory.containsLocalVariable(RETURN_VARIABLE)) {
		return true;
	}
	
	if (index==ranges.size()) {
		for (int i = 0; i< ranges.size();i++) {
			if (ranges[i].getType()==DIFF) {
				const NodeValue& a = computeValue(ranges[i][0]);
				const NodeValue& b = computeValue(ranges[i][1]);
				if ((!a.isError() && a.isUnknown()) || a.isGenericError()) {
					error("invalid expression",ranges[i][0].getLocation());
				}
				if ((!b.isError() && b.isUnknown()) || b.isGenericError()) {
					error("invalid expression",ranges[i][1].getLocation());
				}
				if (!a.isValid() || !b.isValid()) {
					return false;
				}
				NodeValue r = a!=b;
				if (r.isFalse()) {
					return true;
				} 
			}
		}
		return unrollSentenceB(sentence);
	}
	Node& range = ranges[ranges.size()-index-1];
	if (range.getType()==DIFF) {
		return unrollSentenceR(sentence,ranges,index+1);
	}
	const NodeValue& fromValue = computeValue(range[0]);
	const NodeValue& toValue = computeValue(range[4]);
	if ((!fromValue.isError() && fromValue.isUnknown()) || fromValue.isGenericError()) {
		error("invalid range",range[0].getLocation());
	}
	if ((!toValue.isError() && toValue.isUnknown()) || toValue.isGenericError()) {
		error("invalid range",range[4].getLocation());
	}
	if (!fromValue.isValid() || !toValue.isValid()) {
		return false;
	} 
	long from = fromValue.castLong().getLong();
	long to = toValue.castLong().getLong();
	if (range[1].getType()==LESS_THAN) {
		from++;
	}
	if (range[3].getType()==LESS_OR_EQUAL_THAN) {
		to++;
	}
	for (long i=from;i<to;i++) {
		const NodeValue& value = setVariable(range[2],NodeValue(i));
		if (value.isError()) {
			return false;
		}
		if (!unrollSentenceR(sentence,ranges,index+1)) {
			return false;
		}
	}
	return true;
}

bool Parser::unrollSentenceB(Node& sentence)
{
	switch (sentence.getType()) {
		case ASIG: case INC_BY: case DEC_BY: case MUL_BY: case DIV_BY: case MOD_BY:
		case BITWISE_LEFT_BY: case BITWISE_RIGHT_BY: case BITWISE_AND_BY: case BITWISE_OR_BY:
		case BITWISE_XOR_BY: case POST_INC: case POST_DEC: case CALL:
		return !computeValue(sentence).isError();
		
		case FEATURE:
		return unrollFeatures(sentence,file.psystem.features,false);
				
		case MU:
		if (hasStructure) {
			error("duplicated initial membrane structure",sentence.getLocation());
			return true;
		}
		if (unrollMembraneStructure(sentence[0],file.psystem.structure)) {
			hasStructure = true;
			return true;
		}
		return false;
		
		case EMU:
		if (!hasStructure) {
			error("you should define the initial membrane structure before extending it",sentence.getLocation());
			return true;
		}
		return unrollExtendMembraneStructure(sentence,file.psystem.structure);
		
		case MS:
		return unrollMultiset(sentence);
				
		case RULE:
		return unrollRule(sentence);
				
		case SENTENCES:
		return unrollSentences(sentence);
				
		case RETURN:
		return unrollReturn(sentence);
		
		case IF:
		return unrollIf(sentence);
		
		case ELSE:
		error("orphan else",sentence.getLocation());
		return false;
		
		case WHILE:
		return unrollWhile(sentence);
		
		case DO:
		return unrollDoWhile(sentence);
		
		case FOR:
		return unrollFor(sentence);
		
		default:
		return true;
	}
}

bool Parser::unrollLabels(Node& node, Label& label)
{
	bool success=true;
	label.clear();
	for (int i=0;i<node.size();i++) {
		const NodeValue& value = computeValue(node[i][0]);
		if ((!value.isError() && value.isUnknown()) || value.isGenericError() || value.isDouble()) {
			error("invalid label", node[i][0].getLocation());
		}
		if (!value.isValid() || value.isDouble()) {
			success=false;
		} else {
			label.push_back(value.castString().getString());
		}
	}
	if (success && verbosityLevel>=LEVEL_DEBUG_1) {
		std::ostringstream buffer;
		buffer << "label '"<<label<<"'";
		error (buffer.str().c_str(),node.getLocation(),LEVEL_DEBUG_1);
	}
	return success;
}

void Parser::extendMembrane(const Label& label, const Membrane& innerMembrane, Membrane& membrane) {
	
	for (auto it = membrane.data.begin(); it!= membrane.data.end(); ++it) {
		extendMembrane(label,innerMembrane,*it);
	}
	if (label == membrane.label) {
		membrane.data.push_back(innerMembrane);
	}
	
}


bool Parser::unrollExtendMembraneStructure(Node& sentence, Membrane& membrane)
{
	Label label;
	Membrane innerMembrane;
	bool success=true;
	for (int i=0;i<sentence.size();i++) {
		if (sentence[i].getType()==LABELS) {
			success = unrollLabels(sentence[i],label) ? success : false; 
		} else if (sentence[i].getType()==MEMBRANE) {
			success = unrollMembraneStructure(sentence[i],innerMembrane) ? success : false;
		}
	}
	if (success) {
		extendMembrane(label,innerMembrane,membrane);
	}
	return success;
}


bool Parser::unrollMembraneStructure(Node& sentence, Membrane& membrane)
{
	bool success=true;
	for (int i=0;i<sentence.size();i++) {
		if (sentence[i].getType()==CHARGE ) {
			membrane.charge = sentence[i].getValue().getLong()< 0 ? -1 : sentence[i].getValue().getLong() > 0 ? 1 : 0; 
		} else if (sentence[i].getType()==LABELS) {
			success = unrollLabels(sentence[i],membrane.label) ? success : false; 
		} else if (sentence[i].getType()==MEMBRANES) {
			for (int j=0; j< sentence[i].size(); j++) {
				membrane.data.emplace_back();
				success = unrollMembraneStructure(sentence[i][j],membrane.data.back()) ? success : false;
			}
		}
	}
	return success;
}


bool Parser::unrollMultiset(Node& sentence, Multiset& multiset)
{
	bool success=true;
	multiset.clear();
	std::string object;
	for (int i=0;i<sentence.size();i++) {
		if (sentence[i].getType()==DISSOLUTION_SYMBOL) {
			multiset["@d"] = 1;
		} else if (sentence[i].getType()==VARIABLE) {
			if (!getVariableAsString(sentence[i],object)) {
				success=false;
			} else {
				multiset[object]++;
			}
		} else if (sentence[i].getType()==MUL) {
			if (!getVariableAsString(sentence[i][0],object)) {
				success=false;
			}
			NodeValue multiplicity = computeValue(sentence[i][1]);
			if ((!multiplicity.isError() && multiplicity.isUnknown()) || multiplicity.isGenericError() || (multiplicity.isValid() && multiplicity.isString())) {
				error("invalid multiplicity",sentence[i][1].getLocation());
			}
			if (multiplicity.isValid() && multiplicity.isDouble()) {
				multiplicity = multiplicity.castLong();
			}
			if (multiplicity.isValid() && multiplicity.isLong() && multiplicity.getLong() < 0) {
				error("negative multiplicity",sentence[i][1].getLocation());
			}
			if (multiplicity.isValid() && multiplicity.isLong() && multiplicity.getLong() == 0) {
				error("zero multiplicity", sentence[i][1].getLocation(), LEVEL_INFO);
			}
			if (!multiplicity.isValid() || !multiplicity.isLong() || multiplicity.getLong() < 0)  {
				success=false;
			} 
			if (!object.empty() && multiplicity.isValid() && multiplicity.isLong() && multiplicity.getLong() > 0) {
				multiset[object]+=multiplicity.getLong();
			}
		}
	}
	if (success && verbosityLevel>=LEVEL_DEBUG_1) {
		std::ostringstream buffer;
		buffer << "multiset " << multiset;
		error(buffer.str().c_str(),sentence.getLocation(),LEVEL_DEBUG_1);
	}
	return success;
}


bool Parser::unrollMultiset(Node& sentence) {
	Label label;
	Multiset multiset;
	int type = ASIG;	
	bool success=true;
	for (int i=0;i<sentence.size();i++) {
		if (sentence[i].getType()==LABELS) {
			success = unrollLabels(sentence[i],label) ? success : false;
		} else if (sentence[i].getType()==INC_BY) {
			type = INC_BY;
		} else if (sentence[i].getType()==MULTISET) {
			success = unrollMultiset(sentence[i],multiset) ? success : false;
		}
	}
	if (success) {
		if (type == ASIG) {
			if (verbosityLevel>=LEVEL_DEBUG_1) {
				std::ostringstream buffer;
				buffer << "ms("<<label<<") = "<< multiset;
				error(buffer.str().c_str(),sentence.getLocation(),LEVEL_DEBUG_1);
			}
			file.psystem.multisets[label] = multiset;
		} else {
			if (verbosityLevel>=LEVEL_DEBUG_1) {
				std::ostringstream buffer;
				buffer << "ms("<<label<<") += "<< multiset;
				error(buffer.str().c_str(),sentence.getLocation(),LEVEL_DEBUG_1);
			}
			for (auto it = multiset.begin(); it!= multiset.end(); ++it) {
				file.psystem.multisets[label][it->first]+=it->second;
			}
		}
	}	
	return success;
}

bool Parser::unrollInnerMembrane(Node& sentence, IMembrane& membrane, const std::string& patternGroup, const Label& defaultLabel, bool flag) {
	bool success = true;
	for (int i=0;i<sentence.size();i++) {
		if (sentence[i].getType() == CHARGE) {
			success = unrollCharge(sentence[i],membrane.charge,patternGroup) ? success : false;
			if (verbosityLevel>=LEVEL_DEBUG_1) {
				std::ostringstream buffer;
				buffer << "charge '"<<membrane.getChargeSymbol()<<"'";
				error(buffer.str().c_str(),sentence[i].getLocation(),LEVEL_DEBUG_1);
			}
		} else if (sentence[i].getType() == LABELS) {
			success = unrollLabels(sentence[i],membrane.label) ? success : false;
			if (success && membrane.label.empty()) {
				membrane.label = defaultLabel;
			}
		} else if (sentence[i].getType() == MULTISET) {
			success = unrollMultiset(sentence[i],membrane.multiset) ? success : false;
		}
	}
	if (success && flag && verbosityLevel>=LEVEL_DEBUG_1) {
		std::ostringstream buffer;
		buffer << "inner membrane "<<membrane;
		error(buffer.str().c_str(),sentence.getLocation(),LEVEL_DEBUG_1);
	}
	return success;
}


bool Parser::unrollOuterMembrane(Node& sentence, OMembrane& membrane,  const std::string& patternGroup, const Label& defaultLabel) {
	bool success = unrollInnerMembrane(sentence,membrane,patternGroup, defaultLabel,false);
	for (int i=0;i<sentence.size();i++) {
		if (sentence[i].getType() == INNER_MEMBRANES) {
			for (int j=0; j< sentence[i].size(); j++) {
				membrane.data.emplace_back();
				success = unrollInnerMembrane(sentence[i][j],membrane.data.back(), patternGroup) ? success : false;
			}
		}
	}
	if (success && verbosityLevel>=LEVEL_DEBUG_1) {
		std::ostringstream buffer;
		buffer << "outer membrane "<<membrane;
		error(buffer.str().c_str(),sentence.getLocation(),LEVEL_DEBUG_1);
	}
	return success;
}


bool Parser::unrollLeftHandRule(Node& sentence, LHR& lhr, const std::string& patternGroup) {
	bool success = true;
	for(int i=0;i<sentence.size();i++) {
		if (sentence[i].getType() == MULTISET) {
			success = unrollMultiset(sentence[i],lhr.multiset) ? success : false;
		} else if (sentence[i].getType() == OUTER_MEMBRANE) {
			success = unrollOuterMembrane(sentence[i],lhr.membrane, patternGroup) ? success : false;
		}
	}
	if (success && verbosityLevel>=LEVEL_DEBUG_1) {
		std::ostringstream buffer;
		buffer << "left-hand rule "<<lhr;
		error(buffer.str().c_str(),sentence.getLocation(),LEVEL_DEBUG_1);
	}
	return success;
}

bool Parser::unrollRightHandRule(Node& sentence, RHR& rhr,  const std::string& patternGroup, const Label& defaultLabel) {
	bool success = true;
	for(int i=0;i<sentence.size();i++) {
		if (sentence[i].getType() == MULTISET) {
			success = unrollMultiset(sentence[i],rhr.multiset) ? success : false;
		} else if (sentence[i].getType() == OUTER_MEMBRANES) {
			for (int j=0;j<sentence[i].size(); j++) {
				rhr.data.emplace_back();
				success = unrollOuterMembrane(sentence[i][j],rhr.data.back(), patternGroup, defaultLabel) ? success : false;
			}
		}
	}
	if (success && verbosityLevel>=LEVEL_DEBUG_1) {
		std::ostringstream buffer;
		buffer << "right-hand rule "<<rhr;
		error(buffer.str().c_str(),sentence.getLocation(),LEVEL_DEBUG_1);
	}
	return success;
	
}

bool Parser::unrollFeatures(Node& node, Features& features, bool pattern) {
	bool success = true;
	std::string tag;
	for (int i=0; i< node.size(); i++) {
		
		if (node[i].getType()==ID) {
			tag = node[i].getValue().getString();
			tag+="(";
			tag+=node[i][0].getTypeAsString();
			tag+=")";
			if (!pattern) {
				success = false;
				error("invalid feature",node[i].getLocation());
			} else	if (features.count(tag)>0) {
				std::ostringstream os;
				os << "ignoring duplicated feature '" << tag << "'"; 
				error(os.str().c_str(),node[i].getLocation(),LEVEL_WARNING);
			} else {
				features[tag] = 1;
			}
		} else if (node[i].getType()==VARIABLE) {
			if (pattern) {
				success = false;
				error("invalid pattern feature",node[i].getLocation());
			
			} else if (!getVariableAsString(node[i],tag)) {
				success = false; 
			} else if (features.count(tag)>0) {
				std::ostringstream os;
				os << "ignoring duplicated feature '" << tag << "'"; 
				error(os.str().c_str(),node[i].getLocation(),LEVEL_WARNING);
			} else {
				features[tag] = 1;
			}
		} else if (node[i].getType()==ASIG) {
			if (pattern) {
				success = false;
				error("invalid pattern feature",node[i].getLocation());
			} else if (!getVariableAsString(node[i][0],tag)) {
				success = false; 
			} else if (features.count(tag)>0) {
				std::ostringstream os;
				os << "ignoring duplicated feature '" << tag << "'"; 
				error(os.str().c_str(),node[i].getLocation(),LEVEL_WARNING);
			} else {
				const NodeValue& value = computeValue(node[i][1]);
				if ((!value.isError() && value.isUnknown()) || value.isGenericError()) {
					error("invalid feature value", node[i][1].getLocation());
				} 
				if (!value.isValid()) {
					success = false;
				} else if (value.isLong()) {
					features[tag] = value.getLong();
				} else if (value.isDouble()) {
					features[tag] = value.getDouble();
				} else if (value.isString()) {
					features[tag] = value.getString();
				}
			}
		}
	}
	return success;
}


bool Parser::unrollCharge(Node& sentence, char& charge, const std::string& patternGroup) {
	if (sentence.size()>0 && patternGroup.empty()) {
		error("invalid anonymous charge",sentence.getLocation());
		return false;
	} 
	if (sentence.size() > 0) {
		long x = sentence[0].getValue().getLong();
		if (x >10) {
			error("anonymous variable out of range (0-9)", sentence[0].getLocation());
			return false;
		}
		charge = (char)(x + 2);
		return true; 
	}
	
	charge = sentence.getValue().getLong()< 0 ? -1 : sentence.getValue().getLong() > 0 ? 1 : 0;	
	return true;	
}


bool Parser::unrollRule(Node& sentence, const std::string& patternGroup) {
	Rule rule;
	bool success = true;
	bool hasProbability = false;
	bool leftSide = true;
	for (int i = 0; i< sentence.size(); i++) {
		if (sentence[i].getType() == FEATURE) {
			success = unrollFeatures(sentence[i],rule.features, !patternGroup.empty()) ? success : false;
		} else if (sentence[i].getType() == PRIORITY) {
			const NodeValue& value = computeValue(sentence[i][0]);
			if ((!value.isError() && value.isUnknown()) || value.isGenericError() || (value.isValid() && !value.isLong())) {
				error("invalid priority", sentence[i][0].getLocation());
			}
			if (value.isValid() && value.isLong() && value.getLong() < 0) {
				error("negative priority", sentence[i][0].getLocation());
			}
			if (value.isValid() && value.isLong() && value.getLong() >= 0) {
				if (rule.features.count("priority")>0) {
					error("ignoring duplicated feature 'priority'",sentence[i].getLocation(),LEVEL_WARNING);
				} else {
					if (verbosityLevel>=LEVEL_DEBUG_1) {
						std::ostringstream buffer;
						buffer << "priority "<<value.getLong();
						error(buffer.str().c_str(),sentence[i].getLocation(),LEVEL_DEBUG_1);
					}
					rule.features["priority"] = value.getLong();
				}
			} else {
				success = false;
			}
		} else if (sentence[i].getType() == PROBABILITY) {
			double p = -1.0;
			const NodeValue& value = computeValue(sentence[i][0]);
			if ((!value.isError() && value.isUnknown()) || value.isGenericError() || (value.isValid() && value.isString())) {
				error("invalid probability", sentence[i][0].getLocation());
			} else if (value.isValid()){
				p = value.isDouble() ? value.getDouble() : value.getLong()==0 ? 0.0 : value.getLong()==1 ? 1.0 : (double) value.getLong();
				FloatingPoint<double> aux(p);
				if (aux.AlmostEquals(FLOATING_POINT_ZERO)) {
					p = 0.0;
					error("probability is zero",sentence[i][0].getLocation(),LEVEL_INFO);
				} else if (aux.AlmostEquals(FLOATING_POINT_ONE)) {
					p = 1.0;
				}
				if (p<0.0) {
					error("negative probability",sentence[i][0].getLocation());
				} else if (p > 1.0) {
					error("probability greater than 1.0",sentence[i][0].getLocation());
				} 
			}
			if (p >= 0.0 && p <= 1.0) {
				if (rule.features.count("probability")>0) {
					error("ignoring duplicated feature 'probability'",sentence[i].getLocation(),LEVEL_WARNING);
				} else {
					if (verbosityLevel>=LEVEL_DEBUG_1) {
						std::ostringstream buffer;
						buffer << "probability "<<p;
						error(buffer.str().c_str(),sentence[i].getLocation(),LEVEL_DEBUG_1);
					}
					rule.features["probability"] = p;
					hasProbability = true;
				}
			} else {
				success = false;
			}
		} else if (sentence[i].getType() == CHARGE) {
			success = unrollCharge(sentence[i],rule.lhr.membrane.charge,patternGroup) ? success : false;
			rule.rhr.data.emplace_back();
			rule.rhr.data.back().charge = rule.lhr.membrane.charge;
			if (verbosityLevel>=LEVEL_DEBUG_1) {
				std::ostringstream buffer;
				buffer << "charge '"<<rule.lhr.membrane.getChargeSymbol()<<"'";
				error(buffer.str().c_str(),sentence[i].getLocation(),LEVEL_DEBUG_1);
			}
		} else if (sentence[i].getType() == LABELS) {
			success = unrollLabels(sentence[i],rule.lhr.membrane.label) ? success : false;
			rule.rhr.data.back().label = rule.lhr.membrane.label;
		} else if (sentence[i].getType() == LONG_RIGHT_ARROW || sentence[i].getType()==SHORT_RIGHT_ARROW) {
			rule.arrow = 0;
			leftSide = false;
		} else if (sentence[i].getType() == LONG_DOUBLE_ARROW || sentence[i].getType() == SHORT_DOUBLE_ARROW) { 
			rule.arrow = 1;
			leftSide = false;
		} else if (sentence[i].getType() == MULTISET) {
			Multiset& multiset = leftSide ? rule.lhr.membrane.multiset : rule.rhr.data.back().multiset;
			success = unrollMultiset(sentence[i],multiset) ? success : false;
		} else if (sentence[i].getType() == INNER_MEMBRANES) {
			OMembrane& membrane = leftSide ? rule.lhr.membrane : rule.rhr.data.back();
			for (int j=0; j< sentence[i].size(); j++) {
				membrane.data.emplace_back();
				success = unrollInnerMembrane(sentence[i][j],membrane.data.back()) ? success : false;
			}
		} else if (sentence[i].getType() == LEFT_HAND_RULE) {
			success = unrollLeftHandRule(sentence[i],rule.lhr, patternGroup) ? success : false;
		} else if (sentence[i].getType() == RIGHT_HAND_RULE) {
			success	= unrollRightHandRule(sentence[i],rule.rhr,patternGroup,rule.lhr.membrane.label) ? success : false;
		}
	}
		
	if (success) {
		if (hasProbability && rule.features["probability"].as_double() == 0.0) {
			return true;
		}
		if (file.psystem.rules.count(rule)>0) {
			error("ignoring duplicated rule",sentence.getLocation(),LEVEL_INFO);
			return true;
		}
		if (patternGroup.empty()) {
			if (verbosityLevel>=LEVEL_DEBUG_1) {
				std::ostringstream buffer;
				buffer << "rule "<<rule;
				error(buffer.str().c_str(),sentence.getLocation(),LEVEL_DEBUG_1);
			}
			success = checkRule(rule,sentence.getLocation());
			if (success) {
				file.psystem.rules.insert(rule);
			}
		} else {
			if (verbosityLevel>=LEVEL_DEBUG_1) {
				std::ostringstream buffer;
				buffer << "pattern("<<patternGroup<<") " << rule;
				error(buffer.str().c_str(),sentence.getLocation(),LEVEL_DEBUG_1);
			}
			patterns[patternGroup].insert(rule);
		}
		return success;
	}
	return false;
}

bool Parser::unrollSentences(Node& sentence) {
	bool success = true;
	for (int i=0;i<sentence.size() && !memory.containsLocalVariable(RETURN_VARIABLE);i++) {
		if (sentence[i].getType()==IF && (i+1) < sentence.size() && sentence[i+1].getType()==ELSE) {
			sentence[i].addChild(sentence.getChild(i+1));
			sentence.removeChild(i+1);
		}
		success = unrollSentence(sentence[i]) ? success: false;	
	}
	return success;
}


const NodeValue& Parser::doCall(Node& sentence) {
	
	std::string name = sentence[0].getValue().getString();
	unsigned n = sentence.size()>1 ? sentence[1].size() : 0;
	Node* module_ptr = getModule(name,n);
	if (module_ptr==NULL) {
		return doSystemCall(sentence);
	} 
	Node& module = *module_ptr;
	if (module.size()==1) {
		sentence.setValue(UNKNOWN_VALUE);
		return sentence.getValue();
	}
	NodeValue* arguments = new NodeValue[n+1];
	for (unsigned i=0;i<n;i++) {
		const NodeValue& value = computeValue(sentence[1][i]);
		if ((!value.isError() && value.isUnknown()) || value.isGenericError()) {
			error("invalid argument",sentence[1][i].getLocation());
		}
		if (value.isValid()) {
			arguments[i] = value;
		} else {
			sentence.setValue(GENERIC_ERROR);
		}
	}
	if (sentence.getValue().isError()) {
		delete[] arguments;
		return sentence.getValue();
	}
	if (module[1].getType()==PARAMETERS && module.size()==2) {
		sentence.setValue(UNKNOWN_VALUE);
		delete[] arguments;
		return sentence.getValue();
	}
    memory.pushScope();
	for (unsigned i=0;i<n;i++) {
		setVariable(module[1][i],arguments[i]);	
	}
	delete[] arguments;
	Node& body = module.size()==2 ? module[1] : module[2];
	
	if (!unrollSentences(body)) {
		sentence.setValue(GENERIC_ERROR);
	} else if (memory.containsLocalVariable(RETURN_VARIABLE)) {
		sentence.setValue(memory.getVariable(RETURN_VARIABLE));
	} else {
		sentence.setValue(UNKNOWN_VALUE);
	}
	memory.popScope();	
	return sentence.getValue();
}

bool Parser::unrollReturn(Node& sentence) {
	const NodeValue& value = computeValue(sentence[0]);
	if ((!value.isError() && value.isUnknown()) || value.isGenericError()) {
		error("invalid return expression",sentence[0].getLocation());
	}
	if (value.isValid()) {
		memory.setVariable(RETURN_VARIABLE,value,sentence.getLocation());
	}
	return value.isValid();
}

bool Parser::unrollIf(Node& sentence) {
	const NodeValue& condition = computeValue(sentence[0]);
	if ((!condition.isError() && condition.isUnknown()) || condition.isGenericError()) {
		error("invalid if-else condition",sentence.getLocation());
	}
	if (!condition.isValid()) {
		return false; 
	}
	if (condition.isTrue()) {
		return unrollSentence(sentence[1]);
	}
	if (sentence.size()>2) {
		return unrollSentence(sentence[2][0]);
	}
	return true;
}


bool Parser::unrollWhile(Node& sentence){
	const NodeValue& condition = computeValue(sentence[0]);
	while (condition.isTrue() && unrollSentence(sentence[1])) {
		computeValue(sentence[0]);
	}
	if ((!condition.isError() && condition.isUnknown()) || condition.isGenericError()) {
		error("invalid while condition",sentence[0].getLocation());
	}
	return condition.isFalse();
}

bool Parser::unrollDoWhile(Node& sentence){
	if (!unrollSentence(sentence[0])) {
		return false;
	}
	const NodeValue& condition = computeValue(sentence[1]);
	while (condition.isTrue() && unrollSentence(sentence[0])) {
		computeValue(sentence[1]);
	}
	if ((!condition.isError() && condition.isUnknown()) || condition.isGenericError()) {
		error("invalid do-while condition",sentence[1].getLocation());
	}
	return condition.isFalse();
}
bool Parser::unrollFor(Node& sentence) {
	if (!unrollSentence(sentence[0])) {
		return false;
	}
	const NodeValue& condition = computeValue(sentence[1]);
	while (condition.isTrue() && unrollSentence(sentence[3]) && unrollSentence(sentence[2])) {
		computeValue(sentence[1]);
	}
	if ((!condition.isError() && condition.isUnknown()) || condition.isGenericError()) {
		error("invalid for condition",sentence[1].getLocation());
	}
	return condition.isFalse();
}


const NodeValue& Parser::computeValue(Node& node)
{
	if (!node.isExpression() || node.getValue().isConstant()) {
		return node.getValue();
	}
	NodeValue v;
	switch(node.getType()) {
		case VARIABLE:
			node.setValue(getVariable(node));
		break;
		case CALL:
			doCall(node);
		break;
		case SYSTEM_CALL:
			node.setValue(doSystemCall(node[0]));
		break;
		case SYSTEM_CONSTANT:
			node.setValue(getSystemConstant(node[0]));
		break;
		case INT_TYPE:
		case LONG_TYPE:
			node.setValue(computeValue(node[0]).castLong());
		break;
		case DOUBLE_TYPE:
			node.setValue(computeValue(node[0]).castDouble());
		break;
		case STRING_TYPE:
			node.setValue(computeValue(node[0]).castString());
		break;
		case POST_INC:
			setVariable(node[0], computeValue(node[0]) + CLONG_ONE_VALUE);
			node.setValue(node[0].getValue().isValid() ? node[0].getValue() : UNDEFINED_OPERATION_ERROR);
		break;
		case POST_DEC:
			setVariable(node[0], computeValue(node[0]) - CLONG_ONE_VALUE);
			node.setValue(node[0].getValue().isValid() ? node[0].getValue() : UNDEFINED_OPERATION_ERROR);
		break;
		case PLUS:
			node.setValue(computeValue(node[0]));
		break;
		case MINUS:
			node.setValue(-computeValue(node[0]));
		break;
		case NOT:
			node.setValue(!computeValue(node[0]));
		break;
		case BITWISE_NOT:
			node.setValue(~computeValue(node[0]));
		break;
		case INC:
			node.setValue((v = setVariable(node[0], computeValue(node[0]) + CLONG_ONE_VALUE)).isValid() ? v : UNDEFINED_OPERATION_ERROR);
		break;
		case DEC:
			node.setValue((v = setVariable(node[0], computeValue(node[0]) - CLONG_ONE_VALUE)).isValid() ? v : UNDEFINED_OPERATION_ERROR);
		break;
		case MUL:
			node.setValue(computeValue(node[0]) * computeValue(node[1]));
		break;
		case DIV:
			node.setValue(computeValue(node[0]) / computeValue(node[1]));
		break;
		case MOD:
			node.setValue(computeValue(node[0]) % computeValue(node[1]));
		break;
		case ADD:
			node.setValue(computeValue(node[0]) + computeValue(node[1]));
		break;
		case SUB:
			node.setValue(computeValue(node[0]) - computeValue(node[1]));
		break;
		case BITWISE_LEFT:
			node.setValue(computeValue(node[0]) << computeValue(node[1]));
		break;
		case BITWISE_RIGHT:
			node.setValue(computeValue(node[0]) >> computeValue(node[1]));
		break;
		case LESS_THAN:
			node.setValue(computeValue(node[0]) < computeValue(node[1]));
		break;
		case LESS_OR_EQUAL_THAN:
			node.setValue(computeValue(node[0]) <= computeValue(node[1]));	
		break;
		case GREATER_THAN:
			node.setValue(computeValue(node[0]) > computeValue(node[1]));
		break;
		case GREATER_OR_EQUAL_THAN:
			node.setValue(computeValue(node[0]) >= computeValue(node[1]));
		break;
		case EQUAL:
			node.setValue(computeValue(node[0]) == computeValue(node[1]));
		break;
		case DIFF:
			node.setValue(computeValue(node[0]) != computeValue(node[1]));
		break;
		case BITWISE_AND:
			node.setValue(computeValue(node[0]) & computeValue(node[1]));
		break;
		case BITWISE_OR:
			node.setValue(computeValue(node[0]) | computeValue(node[1]));
		break;
		case BITWISE_XOR:
			node.setValue(computeValue(node[0]) ^ computeValue(node[1]));
		break;
		case AND:
			if (!computeValue(node[0]).isValid()) {
				node.setValue(UNKNOWN_VALUE);
			} else if (node[0].getValue().isFalse()) {
				node.setValue(node[0].getValue().isConstant() ? CLONG_ZERO_VALUE : LONG_ZERO_VALUE);
			} else if (!computeValue(node[1]).isValid()) {
				node.setValue(UNKNOWN_VALUE);
			} else if (node[1].getValue().isFalse()) {
				node.setValue(node[0].getValue().isConstant() && node[1].getValue().isConstant() ? CLONG_ZERO_VALUE : LONG_ZERO_VALUE);
			} else {
				node.setValue(node[0].getValue().isConstant() && node[1].getValue().isConstant() ? CLONG_ONE_VALUE : LONG_ONE_VALUE);
			}
		break;
		case OR:
			if (!computeValue(node[0]).isValid()) {
				node.setValue(UNKNOWN_VALUE);
			} else if (node[0].getValue().isTrue()) {
				node.setValue(node[0].getValue().isConstant() ? CLONG_ONE_VALUE : LONG_ONE_VALUE);
			} else if (!computeValue(node[1]).isValid()) {
				node.setValue(UNKNOWN_VALUE);
			} else if (node[1].getValue().isTrue()) {
				node.setValue(node[0].getValue().isConstant() && node[1].getValue().isConstant() ? CLONG_ONE_VALUE : LONG_ONE_VALUE);
			} else {
				node.setValue(node[0].getValue().isConstant() && node[1].getValue().isConstant() ? CLONG_ZERO_VALUE : LONG_ZERO_VALUE);
			}
		break;
		case ASIG:
			node.setValue(setVariable(node[0],computeValue(node[1])));
		break;
		case INC_BY:
		   	node.setValue((v = setVariable(node[0], computeValue(node[0]) + computeValue(node[1]))).isValid() ? v : UNDEFINED_OPERATION_ERROR);
		break;
		case DEC_BY:
			node.setValue((v = setVariable(node[0], computeValue(node[0]) - computeValue(node[1]))).isValid() ? v : UNDEFINED_OPERATION_ERROR);
		break;
		case MUL_BY:
			node.setValue((v = setVariable(node[0], computeValue(node[0]) * computeValue(node[1]))).isValid() ? v : UNDEFINED_OPERATION_ERROR);
		break;
		case DIV_BY:
			node.setValue((v = setVariable(node[0], computeValue(node[0]) / computeValue(node[1]))).isValid() ? v : UNDEFINED_OPERATION_ERROR);
		break;
		case MOD_BY:
			node.setValue((v = setVariable(node[0], computeValue(node[0]) % computeValue(node[1]))).isValid() ? v : UNDEFINED_OPERATION_ERROR);
		break;
		case BITWISE_LEFT_BY:
			node.setValue((v = setVariable(node[0], computeValue(node[0]) << computeValue(node[1]))).isValid() ? v : UNDEFINED_OPERATION_ERROR);
		break;
		case BITWISE_RIGHT_BY:
			node.setValue((v = setVariable(node[0], computeValue(node[0]) >> computeValue(node[1]))).isValid() ? v : UNDEFINED_OPERATION_ERROR);
		break;
		case BITWISE_AND_BY:
			node.setValue((v = setVariable(node[0], computeValue(node[0]) & computeValue(node[1]))).isValid() ? v : UNDEFINED_OPERATION_ERROR);
		break;
		case BITWISE_OR_BY:
			node.setValue((v = setVariable(node[0], computeValue(node[0]) | computeValue(node[1]))).isValid() ? v : UNDEFINED_OPERATION_ERROR);
		break;
		case BITWISE_XOR_BY:
			node.setValue(setVariable(node[0], computeValue(node[0]) ^ computeValue(node[1])));
		break;
		default:
		;
	}
	std::string aux,aux1;
	switch(node.getValue().getError()) {
		
		case UNKNOWN_VARIABLE:
			aux = "unknown variable";
			if (getVariableAsString(node,aux1)) {
				aux += getColorCode(BOLDWHITE);
				aux += " '";
				aux += aux1;
				aux+="'";
				aux+=getColorCode(RESET);
			}
			error (aux.c_str(),node.getLocation());
		
		break;
		case UNDEFINED_OPERATION:
			aux = "undefined operation ";
			aux += getColorCode(BOLDWHITE);
			aux += "'";
			aux += node.getTypeAsString();
			if (node.size()>0) {
				aux+="(";
				aux+= node[0].getValue().getTypeAsString();
				for (int i=1;i<node.size();i++) {
					aux+=", ";
					aux+= node[i].getValue().getTypeAsString();
				}
				aux+=")";
			}
			aux+="'";
			aux+=getColorCode(RESET);
			error (aux.c_str(),node.getLocation());
		break;
		case INVALID_LVALUE:
			error(node.getValue().getErrorAsString(),node[0].getLocation());
		break;
		case INVALID_RVALUE:
			error(node.getValue().getErrorAsString(),node[1].getLocation());
		break;
		case GENERIC:
		case NO_ERROR:
		/* nothing */
		break;
		
		default:
			node.getValue().print(stdout);
			printf("\n");
			error(node.getValue().getErrorAsString(),node.getLocation());
	}
	return node.getValue();
}
	

std::string& Parser::getModuleAsString(const Node& module, std::string& str)
{
	if (module.getType()!=MODULE) {
		str="";
		return str;
	}
	str = module[0].getValue().getString();
	str+="<";
	if (module.size()>1 && module[1].getType()==PARAMETERS) {
		str+=std::to_string	(module[1].size());
	} else {
		str+="0";
	}
	str+=">";
	return str;
}
	

Node* Parser::setModule(Node* module)
{
	std::string aux;
	getModuleAsString(*module,aux);			
	if (aux.empty()) {
		return NULL;
	}
	auto it = modules.find(aux);
	if (it != modules.end()) {
		return NULL;
	}
	modules[aux] = module;
	
	return module;
}

Node* Parser::getModule(const std::string& name, int parameters) const
{
	std::string aux = name + "<" + std::to_string(parameters) +">";
	auto it = modules.find(aux);
	if (it==modules.end()) {
		return NULL;
	}
	return it->second;
}

	
