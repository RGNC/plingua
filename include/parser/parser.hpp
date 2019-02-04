#ifndef _PARSER_HPP_
#define _PARSER_HPP_

#include <vector>
#include <string>
#include <map>
#include <set>
#include <cstdio>
#include <boost/filesystem.hpp> 
#include <serialization.hpp>
#include <parser/node_value.hpp>
#include <parser/scope.hpp>
#include <parser/syntax_tree.hpp>



namespace plingua { namespace parser {


enum Color {
	RESET,
	BLACK,
	RED,
	GREEN,
	YELLOW,
	BLUE,
	MAGENTA,
	CYAN,
	WHITE,
	BOLDBLACK,
	BOLDRED,
	BOLDGREEN,
	BOLDYELLOW,
	BOLDBLUE,
	BOLDMAGENTA,
	BOLDCYAN,
	BOLDWHITE
};


enum ErrorLevel{LEVEL_FATAL = 0, LEVEL_ERROR = 1, LEVEL_WARNING = 2, LEVEL_INFO = 3, 
	            LEVEL_DEBUG_1 = 4, LEVEL_DEBUG_2 = 5, LEVEL_DEBUG_3 = 6, LEVEL_DEBUG_4 = 7};


struct Match {
	std::map<std::string,Multiset> multisets;
	std::map<std::string,std::string> labels;
	std::map<char,char> charges;
};

	
class Parser
{

public:	
	Parser(Parser const&) = delete;
    void operator=(Parser const&)  = delete;
	virtual ~Parser() {}
	static Parser& getInstance() {
      	static Parser singleton;
      	return singleton;
	}
	#define PARSER Parser::getInstance()	
	

	const std::vector<boost::filesystem::path>& getFiles() const {return files;}
	
	int parse(int argc, char* argv[]);
	int getVerbosityLevel() const {return verbosityLevel;}
	void update();
	void error(const char* s, const YYLTYPE& location, ErrorLevel level = LEVEL_ERROR);
	void error(const char* s, ErrorLevel level = LEVEL_ERROR, bool printProgramName = true);
	
	const char* getColorCode(Color color) const;
	void addNode(Node* node);
	
	const Node& getRoot() const {return root;}
	
private:	
	Parser();
	void init(int argc, char* argv[]);
	void printAbout() const;
	void addFile(const char* file, bool ignoreWarning);
	void addFile(const boost::filesystem::path& p, bool ignoreWarning);
	void addFile(const char* file, const boost::filesystem::path& base, bool ignoreWarning);
	void addInclude(Node& id, bool ignoreWarning);
	void addIncludePath(const std::string& includePath);
	void readLines(unsigned fileNumber);
	void readIncludes(Node& node);
	void readModules(Node& node);
	void readModel(Node& node);
	void readGlobalVariables(Node& node);
	void readPatterns(Node& node);
	void readSemantics(Node& node);
	bool unrollPattern(Node& sentence);
	bool unrollSentence(Node& sentence);
	bool unrollSentenceB(Node& sentence);
	bool unrollSentenceR(Node& sentence, Node& ranges, int index);
	bool unrollMembraneStructure(Node& sentence, Membrane& membrane);
	bool unrollExtendMembraneStructure(Node& sentence, Membrane& membrane);
	bool unrollMultiset(Node& sentence, Multiset& multiset);
	bool unrollMultiset(Node& sentence);
	bool unrollRule(Node& sentence, const std::string& patternGroup = "");
	bool unrollCharge(Node& sentence, char& charge, const std::string& patternGroup = ""); 
	bool unrollLeftHandRule(Node& sentence, LHR& lhr, const std::string& patternGroup = "");
	bool unrollRightHandRule(Node& sentence, RHR& rhr,  const std::string& patternGroup = "", const Label& defaultLabel = std::vector<LabelString>());
	bool unrollOuterMembrane(Node& sentence, OMembrane& membrane, const std::string& patternGroup = "", const Label& defaultLabel = std::vector<LabelString>());
	bool unrollInnerMembrane(Node& sentence, IMembrane& membrane, const std::string& patternGroup = "", const Label& defaultLabel = std::vector<LabelString>(), bool flag = true) ;
	bool unrollFeatures(Node& node, Features& features, bool pattern);
	void unrollSemantics(Node& node);
	bool unrollSemanticsBody(Node& node, Semantics& semantics,unsigned value, std::set<std::string>& patterns);
	bool unrollSentences(Node& sentence);
	bool unrollReturn(Node& sentence);
	bool unrollIf(Node& sentence);
	bool unrollWhile(Node& sentence);
	bool unrollDoWhile(Node& sentence);
	bool unrollFor(Node& sentence);
	void extendMembrane(const Label& label, const Membrane& innerMembrane, Membrane& membrane);
	
	const NodeValue& doCall(Node& sentence);
	const NodeValue& doSystemCall(Node& sentence);
	
	const NodeValue& computeValue(Node& node);
	const NodeValue& getVariable(Node& node);
	const NodeValue& getSystemConstant(Node& node);
	const NodeValue& setVariable(Node& node, const NodeValue& value);
	
	Node* setModule(Node* module);
	Node* getModule(const std::string& name, int parameters) const;
		
	bool getVariableAsString(Node& variable, std::string& str);
	static std::string& getModuleAsString(const Node& module, std::string& str);
	bool unrollLabels(Node& node, Label& label);
	static bool findMembrane(const Label& label, const Membrane& membrane);
	void finishMessage() const;	
	bool checkData();
	bool generateOutput();
	bool addSemantics();

	bool checkRule(Rule& rule,  const YYLTYPE& location);
	bool matchRule(const Rule& rule, const Rule& pattern);
	bool matchLHR(const LHR& ruleLHR, const LHR& patternLHR, Match& match);
	bool matchRHR(const RHR& ruleRHR, const RHR& patternRHR, Match& match);
	bool matchMultiset(const Multiset& ruleMultiset, const Multiset& patternMultiset, Match& match);
	bool matchIMembrane(const IMembrane& rM, const IMembrane& pM, Match& match);
	bool matchOMembrane(const OMembrane& rM, const OMembrane& pM, Match& match); 
	bool matchCharge(char rC, char pC, Match& match);
	bool matchLabel(const Label& rL, const Label& pL, Match& match);
	bool matchIMembranes(const OMembrane& rM, const OMembrane& pM, Match& match, unsigned index, std::vector<unsigned>& permutation);
	bool matchOMembranes(const RHR& rRHR, const RHR& pRHR, Match& match, unsigned index, std::vector<unsigned>& permutation);
	bool matchFeatures(const Features& rF, const Features& pF);

	static bool isSingleObject(const Multiset& multiset);
	static bool isSingleObjectPattern(const Multiset& multiset);
	static bool isMultisetPattern(const Multiset& multiset);


	std::vector<boost::filesystem::path> files;
	std::vector<boost::filesystem::path> includePaths;
	std::vector<std::vector<std::string>> lines;
	int currentFile;
	int currentLine;
	int currentColumn;
	int errorCounter;
	int warningCounter;
	int verbosityLevel;
	Node root;
	Node mainCall;
	Memory memory;
	std::map<std::string, Node*> modules;
	std::map<std::string, std::set<Rule>> patterns;
	std::map<std::string, Semantics> models;
	
	bool hasStructure;
	File file;
	
	std::string outputFormat;
	std::string outputFile;
	
	bool usingColors;
	
	
};

}}

#endif
