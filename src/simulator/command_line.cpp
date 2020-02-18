#include <iostream>
#include <exception>
#include <boost/program_options.hpp>
#include <simulator/command_line.hpp>
#include <gpl.hpp>


using namespace plingua::simulator;


CommandLine::CommandLine()
: randomized(false),
  verbosityLevel(0),
  steps(0),
  outputFile("a.json") {}

bool CommandLine::parse(int argc, char *argv[])
{
	
	randomized = false;
	verbosityLevel = 0;
	steps = 0;
	bool ready = false;
	inputFile = "";
	outputFile = "a.json";
	configurationFile = "";
	
	namespace po = boost::program_options;
	using namespace std;
	po::options_description desc("Allowed options");
	desc.add_options()
	("help,h", "show this help message")
	("about,a", "show the about message")
	("license,l", "show the GPLv3 license")
	("verbosity,v", po::value<int>(), "set the verbosity level")
	("randomized,r", "set randomized feature")
	("steps,s", po::value<int>(), "set the number of steps to simulate")
	("configuration,c", po::value<string>(),"set the initial configuration file")
	("output,o", po::value<string>(),"set the output file")
	("psystem", po::value< string>(), "set the psystem file")
	;
	
	po::positional_options_description p;
	p.add("psystem", -1);
	
	po::variables_map vm;
	
	po::store(po::command_line_parser(argc, argv).
	options(desc).positional(p).run(), vm);
	po::notify(vm);    
	
	if (vm.count("help")) {
		std::cout << desc << std::endl;
		std::cout << "Example:"<<std::endl;
		std::cout << "  "<<argv[0]<<" psystem.json -c init_configuration.json -s 100 -o output.json -v 5" << std::endl << std::endl;
		std::cout << "Note:"<<std::endl;
		std::cout << "  input/output files can be .json, .xml, .bin or .bin2; see P-Lingua help for more information"<<std::endl << std::endl;
	} else if (vm.count("about")) {
		printAbout();
	} else if (vm.count("license")) {
		print_gpl_license();
	} else {
		if (vm.count("randomized")) {
			randomized = true;
		}
		
		if (vm.count("verbosity")) {
			verbosityLevel = vm["verbosity"].as<int>();
		}
		if (vm.count("steps")) {
			steps = vm["steps"].as<int>();
		}
		if (vm.count("output")) {
			outputFile = vm["output"].as<string>();
		}
	
		if (vm.count("configuration")) {
			configurationFile = vm["configuration"].as<string>();
		} 
		if (vm.count("psystem")) {
			inputFile = vm["psystem"].as<string>();
		} else {
			throw std::runtime_error("required input file missing");
		}
		ready = true;
	}
	return ready;
}

void CommandLine::printAbout() const
{
	std::cout<< "------------------------------------"<<std::endl;
	std::cout<< "RRRRR     GGGGGG   NN    N    CCCCCC"<<std::endl;
	std::cout<< "RR  RR   GG        NNNN  N   CC     "<<std::endl;
	std::cout<< "RRRRR   GG         NN NN N  CC      "<<std::endl;
	std::cout<< "RRRR    GG  GGGGG  NN  NNN  CC      "<<std::endl;
	std::cout<< "RR RR    GG   GGG  NN   NN   CC     "<<std::endl;
	std::cout<< "RR  RR    GGGGGG   NN   NN    CCCCCC"<<std::endl;
	std::cout<< "------------------------------------"<<std::endl;
	std::cout<< "        =======    *******"<<std::endl;
	std::cout<< "       ==     ==  **     **"<<std::endl;
	std::cout<< "      ==       ==**       **"<<std::endl;
	std::cout<< "      ==       ==**       **"<<std::endl;
	std::cout<< "       ==     ==  **     **"<<std::endl;
	std::cout<< "        =======    *******"<<std::endl;
	std::cout<< "       hhtp://www.gcn.us.es"<<std::endl;
	std::cout<< "  https://github.com/RGNC/plingua"<<std::endl;
	std::cout<< "------------------------------------"<<std::endl;
	std::cout<< std::endl;
	std::cout<<"A SOFTWARE SIMULATOR FOR MEMBRANE COMPUTING"<<std::endl;
	std::cout<< std::endl;
	std::cout<< "Copyright (C) 2019 Ignacio Perez-Hurtado (perezh@us.es)" << std::endl;
	std::cout<< "Research Group on Natural Computing" <<std::endl;
	std::cout<< "Department of Computer Science and Artificial Intelligence"<<std::endl;
	std::cout<< "University of Seville, Seville, Spain"<<std::endl;
	std::cout<< std::endl;
	std::cout<< "This program comes with ABSOLUTELY NO WARRANTY; type `--license' for details."<<std::endl;
    std::cout<< "This is free software, and you are welcome to redistribute it"<<std::endl;
    std::cout<< "under certain conditions; type `--license' for details."<<std::endl;
    std::cout<< "See the GNU GPLv3 TERMS AND CONDITIONS for more details."<<std::endl;
    std::cout<< "https://www.gnu.org/licenses/gpl.txt"<<std::endl;
	std::cout<< std::endl;
}
