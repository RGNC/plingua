#ifndef _COMMAND_LINE_HPP_
#define _COMMAND_LINE_HPP_

#include <string>

namespace plingua { namespace simulator {


// Class to parse and store parameters from the command-line
class CommandLine
{
public:
	CommandLine();

	virtual bool parse(int argc, char *argv[]);
	
	int getVerbosityLevel() const {return verbosityLevel;}
	unsigned getMaxStepsToSimulate() const {return steps;}
			
	const std::string& getInputFile() const {return inputFile;}
	const std::string& getOutputFile() const {return outputFile;}
	const std::string& getConfigurationFile() const {return configurationFile;}
	bool isRandomized() const {return randomized;}

protected:
	bool randomized;

private:
	
	void printAbout() const;
	
	int verbosityLevel;
	unsigned steps;
				
	std::string inputFile;
	std::string outputFile;
	std::string configurationFile;
	
};



}}






#endif
