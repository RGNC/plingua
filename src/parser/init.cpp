#include <iostream>
#include <sstream>
#include <exception>
#include <boost/program_options.hpp>
#include <formats.hpp>
#include <parser/parser.hpp>
#include <parser/constants.hpp>
#include <gpl.hpp>
#include "y.tab.h"

using namespace plingua::parser;

void Parser::addIncludePath(const std::string& includePath)
{
	using namespace boost::filesystem;
	path p = absolute(path(includePath));
	if (is_directory(p)) {
		for (unsigned i = 0; i< includePaths.size(); i++) {
			if (p == includePaths[i]) {
				std::string buffer;
				buffer = "ignoring duplicated include path ";
				buffer += getColorCode(BOLDWHITE);
				buffer += "'";
				buffer += p.c_str();
				buffer += "'";
				buffer += getColorCode(RESET);
				error(buffer.c_str(),LEVEL_WARNING);
				return;
			}
		}
		includePaths.push_back(p);
	} else {
		std::string buffer;
		buffer += getColorCode(BOLDWHITE);
		buffer += "'";
		buffer += p.c_str();
		buffer += "'";
		buffer += getColorCode(RESET);
		buffer += " is not a directory";
		error(buffer.c_str(),LEVEL_FATAL);
	}
}

void Parser::addFile(const char* file, bool ignoreWarning)
{
	using namespace boost::filesystem;
	addFile(absolute(path(file)),ignoreWarning);
}

void Parser::addFile(const char* file, const boost::filesystem::path& base, bool ignoreWarning)
{
	using namespace boost::filesystem;
	addFile(absolute(path(file),base.parent_path()),ignoreWarning);
}

void Parser::addFile(const boost::filesystem::path& p, bool ignoreWarning)
{
	std::string buffer;
	boost::filesystem::path filename = p.filename();
	for (unsigned i=0;i<files.size();i++) {
		if (filename == files[i].filename()) {
			if (!ignoreWarning) {
				buffer = "ignoring duplicated file ";
				buffer += getColorCode(BOLDWHITE);
				buffer += "'";
				buffer += filename.c_str();
				buffer += "'";
				buffer += getColorCode(RESET);
				error(buffer.c_str(),LEVEL_WARNING);
			}
			return;
		} 
	}
	files.push_back(p);
}

void Parser::printAbout() const
{
	using namespace std;
	
	cout<< "------------------------------------"<<endl;
	cout<< "RRRRR     GGGGGG   NN    N    CCCCCC"<<endl;
	cout<< "RR  RR   GG        NNNN  N   CC     "<<endl;
	cout<< "RRRRR   GG         NN NN N  CC      "<<endl;
	cout<< "RRRR    GG  GGGGG  NN  NNN  CC      "<<endl;
	cout<< "RR RR    GG   GGG  NN   NN   CC     "<<endl;
	cout<< "RR  RR    GGGGGG   NN   NN    CCCCCC"<<endl;
	cout<< "------------------------------------"<<endl;
	cout<< "        =======    *******"<<endl;
	cout<< "       ==     ==  **     **"<<endl;
	cout<< "      ==       ==**       **"<<endl;
	cout<< "      ==       ==**       **"<<endl;
	cout<< "       ==     ==  **     **"<<endl;
	cout<< "        =======    *******"<<endl;
	cout<< "       hhtp://www.gcn.us.es"<<endl;
	cout<< "  https://github.com/RGNC/plingua"<<endl;
	cout<< "------------------------------------"<<endl;
	cout<< endl;
	cout<< "P-LINGUA:"<<endl;
	cout<<" A SOFTWARE TOOL FOR MEMBRANE COMPUTING"<<endl;
	cout<< endl;
	cout<< PROGRAM_NICE_NAME <<" "<< PROGRAM_VERSION <<" Copyright (C) 2018 " << getColorCode(BOLDWHITE)<< "Ignacio Perez-Hurtado"<< getColorCode(RESET) <<" (perezh@us.es)" << endl;
	cout<< "Research Group on Natural Computing" <<endl;
	cout<< "Department of Computer Science and Artificial Intelligence"<<endl;
	cout<< "University of Seville, Seville, Spain"<<endl;
	cout<< endl;
	cout<< "This program comes with ABSOLUTELY NO WARRANTY; type `--license' for details."<<endl;
    cout<< "This is free software, and you are welcome to redistribute it"<<endl;
    cout<< "under certain conditions; type `--license' for details."<<endl;
    cout<< "See the GNU GPLv3 TERMS AND CONDITIONS for more details."<<endl;
    cout<< "https://www.gnu.org/licenses/gpl.txt"<<endl;
	cout<< endl;
	
}


void Parser::init(int argc, char* argv[])
{
	using namespace std;
	namespace po = boost::program_options;
	
	
	memory.clear();
	root.clear();
	root.setType(PLINGUA);
	lines.clear();
	currentFile=0;
	currentLine=0;
	currentColumn=0;
	errorCounter=0;
	warningCounter=0;
	modules.clear();
	files.clear();
	includePaths.clear();
	verbosityLevel=2;
	hasStructure = false;
	file.header = FILE_HEADER;
	file.version = FILE_VERSION;
	file.psystem.model.str().clear();
	blacklist.clear();
	file.psystem.structure.data.clear();
	file.psystem.rules.clear();
	file.psystem.multisets.clear();	
	file.psystem.features.clear();
	patterns.clear();
	models.clear();
	po::options_description desc("Allowed options");
	desc.add_options()
	("help,h", "show this help message")
	("info,i", po::value< vector<string> >(), "show information about a command")
	("about,a", "show the about message")
	("license,L", "show the license to use, share and modify P-Lingua")
	("verbosity,v", po::value<int>(), "set the verbosity level")
	("include,I", po::value< vector<string> >(),"set a path for including files")
	("output,o", po::value< string>(),"set the output file")
	("format,f", po::value< string>(),"set the output format")
	("list,l", "show a list of allowed output formats")
	("global,g", po::value< vector<string> >(), "set a global variable")
	("no-color,n", "set the standard output without ASCII color codes")
	("input", po::value< vector<string> >(), "set the input file and its arguments")
	;
	
	po::positional_options_description p;
	p.add("input", -1);
	
	po::variables_map vm;
	
	try{
		po::store(po::command_line_parser(argc, argv).
			options(desc).positional(p).run(), vm);
		po::notify(vm);    
	}
	catch(exception& ex) {
		error(ex.what(),LEVEL_FATAL);
		return;
	}
	
	if (vm.count("no-color")) {
		usingColors = false;
	}
	
	if (vm.count("help")) {
		cout<< "P-LINGUA:"<<endl;
		cout<<" A SOFTWARE TOOL FOR MEMBRANE COMPUTING"<<endl;
		cout<< endl;
		cout << desc << endl;
		cout <<"Examples:"<<endl;
		cout <<"\t"<<PROGRAM_NAME<<" foo.pli 32 43 -v 5 -o bar.json -f json"<<endl;
		cout <<"\tread foo.pli with arguments 32 and 43; use verbosity level 5; generate bar.json in JSON format"<<endl;
		cout << endl;
		cout <<"\t"<<PROGRAM_NAME<<" foo.pli 32 43 -g p{0}=10 -g p{1}=20.24 -g p{2}='diblau' -o bar.cpp -f c++"<<endl;
		cout <<"\tread foo.pli with arguments 32 and 43; use global variables p{0}=10, p{1}=20.24 and p{2}='diblau'; generate bar.cpp in C++ format"<<endl;
		cout << endl;
		cout <<"\t"<<PROGRAM_NAME<<" foo.pli 32 43 -g \"p{0}=10 p{1}=20.24 p{2}='diblau'\" -o bar.cpp -f c++"<<endl;
		cout <<"\tsame than above but more compact"<<endl;
		cout << endl;
		cout <<"\t"<<PROGRAM_NAME<<" foo.pli -I \"include ../models\" -o bar.bin -f bin1"<<endl;
		cout <<"\tread foo.pli without arguments; use folders 'include' and '../models' for including files; generate bar.bin in binary format"<<endl;
		cout << endl;
		cout <<"\t"<<PROGRAM_NAME<<" -l"<<endl;
		cout <<"\tget a list of output formats for using with -t option"<<endl;
		cout << endl;
		cout <<"\t"<<PROGRAM_NAME<<" -i global"<<endl;
		cout <<"\tget information about the '--global' command option, a.k.a. '-g' command option"<<endl;	
		cout << endl;
		cout <<"\t"<<PROGRAM_NAME<<" -i \"global verbosity type\""<<endl;
		cout <<"\tget information about '--global', '--verbosity' and '--type' command options, a.k.a. '-g', '-v' and '-t' command options"<<endl;
		cout << endl;
		cout <<"\t"<<PROGRAM_NAME<<" --license | more"<<endl;
		cout <<"\tread the license to use, share and modify this software"<<endl;
		cout << endl;
		cout <<"See https://github.com/RGNC/plingua for more information and examples"<<endl;
		cout<< endl;
		cout<< PROGRAM_NICE_NAME <<" "<< PROGRAM_VERSION <<" Copyright (C) 2018 " <<getColorCode(BOLDWHITE)<< "Ignacio Perez-Hurtado"<< getColorCode(RESET) <<" (perezh@us.es)" << endl;
		cout<< "Research Group on Natural Computing" <<endl;
		cout<< "Department of Computer Science and Artificial Intelligence"<<endl;
		cout<< "University of Seville, Seville, Spain"<<endl;
		cout<< endl;
		cout<< "This program comes with ABSOLUTELY NO WARRANTY; type `--license' for details."<<endl;
		cout<< "This is free software, and you are welcome to redistribute it"<<endl;
		cout<< "under certain conditions; type `--license' for details."<<endl;
		cout<< "See the GNU GPLv3 TERMS AND CONDITIONS for more details."<<endl;
		cout<< "https://www.gnu.org/licenses/gpl.txt"<<endl;
		cout<< endl;
		return;
	}
	
	if (vm.count("info")) {
		const vector<string>& query = vm["info"].as< vector<string> >();
		for (unsigned i=0;i<query.size();i++) {
			cout<<query[i]<<endl;
		}
		return;
	}
		
	if (vm.count("about")) {
		printAbout();
		return;
	}
	
	if (vm.count("license")) {
		print_gpl_license();
		return;
	}
	
	if (vm.count("list")) {
		cout<<"Allowed output formats:"<<endl;
		for (unsigned i=0;i<maxFormats;i++) {
			cout<<"  -f [ --format ] "<< formatId[i] <<"\t"<<formatDescription[i]<<(i==defaultFormat?" (default)":"")<<endl;
		}
		cout<<endl;
		return;
	}
	
	if (vm.count("format")) {
		outputFormat = vm["format"].as<string>();
		bool success = false;
		for (unsigned i=0;i<maxFormats && !success;i++) {
			success = outputFormat.compare(formatId[i])==0;
		}
		if (!success) {
			std::ostringstream os;
			os << "unrecognised format '" << outputFormat << "'";
			error(os.str().c_str(),LEVEL_FATAL);
			return;
		}
	} else {
		outputFormat = formatId[defaultFormat];
	}
	
	
	if (vm.count("output")) {
		outputFile = vm["output"].as<string>();
	}
		
	

		
	if (vm.count("verbosity")) {
		verbosityLevel = vm["verbosity"].as<int>();
		if (verbosityLevel<0) {
			verbosityLevel=0;
			error("The verbosity level should be >= 0",LEVEL_FATAL);
		}
	}
	
	if (vm.count("include")) {
		const vector<string>& paths = vm["include"].as< vector<string> >();
		for (unsigned i=0;i<paths.size();i++) {
			addIncludePath(paths[i]);
		}
	}
	
	
	if (vm.count("input")) {
		const vector<string>& inputFiles = vm["input"].as< vector<string> >();
		for (unsigned i=0;i<inputFiles.size();i++) {
			addFile(inputFiles[i].c_str(),false);
		}
	}
	
	if (files.empty()) {
		error("no input files", LEVEL_FATAL);
	}
	
}
