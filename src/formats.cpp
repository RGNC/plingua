
#include <parser/constants.hpp>
#include <formats.hpp>
#include <serialization.hpp>
#include <parser/parser.hpp>
#include <cereal/archives/xml.hpp>
#include <cereal/archives/json.hpp>
#include <cereal/archives/binary.hpp>
#include <cereal/archives/portable_binary.hpp>

namespace plingua
{
// ADD A FUNCTION CALL TO YOUR CODIFYING FUNCTION
bool codify(Format format, const File& file, const std::string& path)   {
	switch(format) { 
		case JSON      : return codifyJson(file, path); 
		case XML       : return codifyXml(file, path);
		case PLI       : return codifyPli(file, path);
		case BINARY    : return codifyBinary(file,path);
		case PORTABLE  : return codifyPortable(file,path);
		case CPLUSPLUS : return codifyCplusplus(file,path);
		// HERE
		default        : printFatalMessage("Invalid format"); return false;
	}
	return true;
}



bool codifyJson(const File& file, const std::string& path)  {
	saveToJsonFile(path,file);
	return true;
}


bool codifyXml(const File& file, const std::string& path)  {
	saveToXmlFile(path,file);
	return true;
}


bool codifyPli(const File& file, const std::string& path) {
	std::ofstream os(path);
	os << file;
	return true;
}


bool codifyBinary(const File& file, const std::string& path) {
	saveToBinaryFile(path,file);
	return true;
}


bool codifyPortable(const File& file, const std::string& path)  {
	saveToPortableBinaryFile(path,file);
	return true;
}


void printFatalMessage(const std::string& message)  {
	parser::PARSER.error(message.c_str(),parser::LEVEL_FATAL);
	
}

void printErrorMessage(const std::string& message) {
	parser::PARSER.error(message.c_str(),parser::LEVEL_ERROR);
}

void printWarningMessage(const std::string& message)  {
	parser::PARSER.error(message.c_str(),parser::LEVEL_WARNING);
}

void printInfoMessage(const std::string& message){
	parser::PARSER.error(message.c_str(),parser::LEVEL_INFO);
}


void printDebugMessage(const std::string& message)  {
	parser::PARSER.error(message.c_str(),parser::LEVEL_DEBUG_1);
}
}

