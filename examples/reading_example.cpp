#include <iostream>
#include <plingua/serialization.hpp>

using namespace plingua;

int main()
{
	File file;
	
	//loadFromXmlFile("data.xml",file);
	//loadFromJsonFile("data.json",file);
	//loadFromPortableBinaryFile("data.bin",file);
	
	loadFromBinaryFile("data.bin",file);
	std::cout << file << std::endl;
	return 0;
	
}
