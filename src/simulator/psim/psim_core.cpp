#include <iostream>
#include <algorithm>
#include <limits>
#include <simulator/random.hpp>
#include <simulator/psim/psim_core.hpp>

using namespace plingua::psim;


bool RSetKey::operator ==(const RSetKey& other) const
{
	return charge == other.charge && label == other.label;
}

bool RSetKey::operator  <(const RSetKey& other) const
{
	return charge < other.charge || (charge == other.charge && label < other.label);
}


Simulator::Simulator(int argc, char *argv[])
: CommandLine(argc,argv)
{
	if (!isReady()) {
		return;
	}
	// Load p system file
	loadFromFile(getInputFile(),file);
	
	// initialize the configuration or load from file
	if (getConfigurationFile().empty()) {
		initConfigurationRec(file.psystem.structure, -1);
	} else {
		loadFromFile(getConfigurationFile(),configuration);
	}
	
	// Init rules
	for (const Rule& rule : file.psystem.rules) {
		rules[RSetKey(rule.lhr.membrane.charge, rule.lhr.membrane.label)].push_back(rule);
	}
	
	if (getVerbosityLevel()>1) {
		std::cout<<"// P SYSTEM TO SIMULATE:\n";
		std::cout<<file<<"\n\n";
		std::cout<<"***********************************************\n\n";
	}
	
	if (getVerbosityLevel()>0) {
		std::cout<<configuration<<std::endl;
		
	}
}


void Simulator::initConfigurationRec(const Membrane& membrane, int parent)
{
	int index = configuration.membranes.size();
	configuration.membranes.emplace_back();
	CMembrane& c = configuration.membranes.back();
	c.label = membrane.label;
	c.charge = membrane.charge;
	c.parent = parent;
	
	if (file.psystem.multisets.count(membrane.label)>0) {
		c.multiset = file.psystem.multisets.at(membrane.label);
	}
	
	if (parent!=-1) {
		configuration.membranes[parent].childs.push_back(index);
	}
	for (const Membrane& m : membrane.data) {
		initConfigurationRec(m,index);
	}
}


void Simulator::run()
{
	std::vector<unsigned> membraneIndexes;
	bool finished=false;
	
	while(!finished) {
		membraneIndexes.resize(configuration.membranes.size());
		for (unsigned i=0;i<membraneIndexes.size();i++) {
			membraneIndexes[i] = i;
		}
		std::random_shuffle(membraneIndexes.begin(),membraneIndexes.end());
		
		for (unsigned i = 0; i< membraneIndexes.size(); i++) {
			selectRules(membraneIndexes[i]);
		}
		finished=true;
	}
		
}

unsigned Simulator::selectRules(unsigned membraneIndex)
{
	CMembrane& m = configuration.membranes[membraneIndex];
	RSetKey key(m.charge,m.label);
	if (rules.count(key)==0) {
		return 0;
	}
	std::vector<Rule>& r = rules.at(key);
	std::size_t max;
	for (unsigned i=0; i<r.size(); i++) {
		max = getMaxApplications(r[i].lhr,m);
		
		std::cout<< r[i] <<": "<<getMaxApplications(r[i].lhr,m)<<std::endl;
		
	}
	return 0;
}

std::size_t Simulator::countMultisets(const Multiset& ms0, const Multiset& ms1)
{
	if (ms0.empty()) {
		return std::numeric_limits<std::size_t>::max();
	}
		
	if (ms1.size() < ms0.size()) {
		return 0;
	}
	std::size_t aux;
	std::size_t min = std::numeric_limits<std::size_t>::max();
	for (auto it1 = ms0.begin(); it1 != ms0.end() && min>0; ++it1) {
		auto it2 = ms1.find(it1->first);
		if (it2 == ms1.end()) {
			min = 0;
		} else {
			aux = it2->second.raw() / it1->second.raw();
			if (aux < min) {
				min = aux;
			}
		}
	}
	return min;
}


std::size_t Simulator::getMaxApplications(const LHR& lhr, const CMembrane& m) const
{
	if (m.childs.size() < lhr.membrane.data.size()) {
		return 0;
	}
	
	std::size_t min = std::numeric_limits<std::size_t>::max();
	
	const Multiset& pMs = m.parent == -1 ? configuration.environment : configuration.membranes[m.parent].multiset;
	
	min = std::min(min, countMultisets(lhr.multiset,pMs));
	
	if (min==0) {
		return 0;
	}
	
	min = std::min(min, countMultisets(lhr.membrane.multiset,m.multiset));
	
	if (min==0) {
		return 0;
	}

	bool found;
	unsigned i;
	for (const IMembrane& im : lhr.membrane.data) {
		found = false;
		i=0;
		while(i<m.childs.size() && !found) {
			if (configuration.membranes[m.childs[i]].label == im.label && 
				configuration.membranes[m.childs[i]].charge == im.charge) {
				found = true;		
			} else {
				i++;
			}
		}
		if (!found) {
			return 0;
		}
		min = std::min(min,countMultisets(im.multiset,configuration.membranes[m.childs[i]].multiset));
		if (min==0) {
			return 0;
		}	
	}
	
	return min;
}
