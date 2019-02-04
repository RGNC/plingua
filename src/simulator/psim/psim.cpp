#include <iostream>

//#include <simulators/psim/psim_core.hpp>

#include <simulator/simulator.hpp>


using namespace plingua::simulator;




int main(int argc, char *argv[])
{
	Simulator simulator;
	try{
		simulator.parse(argc,argv);
		while(simulator.ok()) {
			simulator.step();
		}
	} catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
		std::cout << "type '" << argv[0] << " --help' for help" << std::endl;
	} 
	return 0;
}
