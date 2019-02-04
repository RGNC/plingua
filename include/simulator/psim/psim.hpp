#ifndef _PSIM_CORE_HPP_
#define _PSIM_CORE_HPP_

#include <map>
#include <vector>
#include <serialization.hpp>
#include <simulator/psim/command_line.hpp>

namespace plingua { namespace psim {

class RSetKey
{
public:
	RSetKey(char charge, const Label& label) : charge(charge), label(label) {}
	char charge;
	Label label;
	bool operator ==(const RSetKey& other) const;
	bool operator  <(const RSetKey& other) const;
};



class Simulator : public CommandLine
{
public:
	Simulator(int argc, char *argv[]);
	void run();


private:	
	void initConfigurationRec(const Membrane& membrane, int parent);
	unsigned selectRules(unsigned membraneIndex);
	std::size_t getMaxApplications(const LHR& lhr, const CMembrane& membrane) const; 
	
	// count how may times ms0 is contained in ms1
	// Ej: ms0 = a*2,b 
	//     ms1 = a*7,b*4
	//     ms0 is contained 3 times in ms1
	static std::size_t countMultisets(const Multiset& ms0, const Multiset& ms1); 


	File file; // P system to simulate
	Configuration configuration; // current configuration
	std::map<RSetKey, std::vector<Rule> > rules;
	
	
};




}}


#endif
