#ifndef _FORMATS_HPP_
#define _FORMATS_HPP_

#include <vector>
#include <string>
#include <serialization.hpp>
#include <parser/parser.hpp>

// INSTRUCTIONS TO ADD A NEW FORMAT
// A) IN FORMATS.HPP
// 		1) ADD AN ENUM VALUE FOR YOUR NEW FORMAT
// 		2) UPDATE MAX FORMATS 
// 		3) ADD AN UNIQUE ID FOR YOUR NEW FORMAT
//		4) ADD A SHORT DESCRIPTION FOR YOUR NEW FORMAT
//		5) ADD A HEADER FOR YOUR CODIFYING FUNCTION
// B) IN FORMATS.CPP
//		6) ADD A FUNCTION CALL TO YOUR CODIFYING FUNCTION
// 		note: ALL OF YOUR IMPLEMENTATION SHOULD BE IN YOUR FILES. 
//      	  KEEP CLEAN FORMATS.HPP AND FORMATS.CPP
// C) IN YOUR FILES 
// 		7) IMPLEMENT YOUR CODIFYING FUNCTION
// D) IN MAKEFILE
//		8) INCLUDE YOUR FILES


namespace plingua
{
	

// ADD AN ENUM VALUE FOR YOUR NEW FORMAT
enum Format  
{
	JSON,
	XML,
	PLI,
	BINARY,
	PORTABLE,
	CPLUSPLUS
	// HERE
};

const Format defaultFormat = JSON;

// UPDATE MAX FORMATS
const unsigned maxFormats = 6; // HERE


// ADD AN UNIQUE ID FOR YOUR NEW FORMAT
const std::vector<std::string> formatId = 
{
	"json",
	"xml",
	"pli",
	"bin",
	"bin2",
	"c++"
	// HERE
};

// ADD A SHORT DESCRIPTION FOR YOUR NEW FORMAT
const std::vector<std::string> formatDescription = 
{
	"JSON format",
	"XML format",
	"unrolled P-Lingua format",	
	"compact bit level representation",
	"compact bit level representation which tracks the endianness of the data",
	"optimized ad-hoc C++ simulator"
	// HERE
};


// ADD A HEADER FOR YOUR CODIFYING FUNCTION
bool codifyJson(const File& file, const std::string& path);
bool codifyXml(const File& file, const std::string& path);
bool codifyPli(const File& file, const std::string& path);
bool codifyBinary(const File& file, const std::string& path);
bool codifyPortable(const File& file, const std::string& path);
bool codifyCplusplus(const File& file, const std::string& path);
// HERE	
	

////////////////////////////////////////
// DO NOT MODIFY THE REST OF THIS FILE
////////////////////////////////////////
bool codify(Format format, const File& file, const std::string& path);
/////////////////////////////////////////////////////////
// Utility functions, you can use them for printing messages
void printFatalMessage(const std::string& message) ;
void printErrorMessage(const std::string& message) ;
void printWarningMessage(const std::string& message) ;
void printInfoMessage(const std::string& message) ;
void printDebugMessage(const std::string& message) ;	


}
#endif
