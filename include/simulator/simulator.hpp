#ifndef _SIMULATOR_HPP_
#define _SIMULATOR_HPP_

#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <limits>
#include <simulator/command_line.hpp>
#include <simulator/shuffler.hpp>
#include <serialization.hpp>


namespace plingua { namespace simulator {

class SelectedRule
{
public:
	SelectedRule(unsigned membraneId, const Rule& rule, std::size_t applications)
	: membraneId(membraneId), rule(rule), applications(applications) {}
	unsigned membraneId;
	const Rule& rule;
	std::size_t applications;
};



class Simulator : public CommandLine
{
public: 	
	Simulator() : finished(false), initialTime(0) {}
	virtual ~Simulator() {}
	void step();
	virtual bool parse(int argc, char *argv[]);	
	const Configuration& getCurrentConfiguration() const {return configuration;}
	const File& getFile() const {return file;}
	bool ok() const {return !finished;}
	
protected:
	
	virtual void selectRules();
	virtual void executeRules();	
	

private:
	std::size_t getMaxApplications(const CMembrane& membrane, const Rule& rule) const;	
	void consume(CMembrane& membrane, const Rule& rule, std::size_t applications);	
	
	bool updateSemantics(Semantics& semantics, const std::string& pattern, std::size_t applications);
	void produce(unsigned membraneId, const Rule& rule, std::size_t applications, std::set<unsigned>& dissolving);
	void produce(unsigned membraneId, const OMembrane& lhrMembrane, const OMembrane& om, std::size_t applications, std::set<unsigned>& dissolving);
	
	std::size_t getMaxApplications(const Semantics& semantics, const std::string& pattern) const;
	
	// count the times that ms0 is contained in ms1
	static std::size_t count(const Multiset& ms0, const Multiset& ms1); 
	
	// ms0 = ms0 - ms1 * times
	static void sub(Multiset& ms0, const Multiset& ms1, std::size_t times);
	
	// ms0 = ms0 + ms1 * times
	static void add(Multiset& ms0, const Multiset& ms1, std::size_t times);
	
	static bool ruleSupported(const Rule& rule);
	
	static bool ruleSupportedArrow0(const Rule& rule);
		
	static bool ruleSupportedArrow1(const Rule& rule);
	
	void initConfigurationRec(const Membrane& membrane, int parent);
	
	unsigned copyMembrane(unsigned membraneId);
		
	std::map<Label, std::map<char, std::vector<Rule>>> ruleSets;
	
		
	std::map<unsigned, std::map<unsigned,std::size_t>> selectedRules;
	std::map<unsigned, std::set<std::string>> selectedPatterns; // selected rule patterns	
	std::queue<unsigned> freeIndexes;	
	Configuration configuration;
	File file;
	bool finished;
	unsigned long initialTime;
	std::map<std::string, std::set<std::string>> blacklist;

	
};	

///////////////////////////////////////////////////////////


inline
void Simulator::step()
{
	
	selectRules();
	executeRules();
	finished = selectedRules.empty() || 
				(getMaxStepsToSimulate()>0 && (configuration.time - initialTime) >= getMaxStepsToSimulate());
}

inline
void Simulator::selectRules()
{
	std::size_t remainingApplications;
	
	selectedRules.clear();
	selectedPatterns.clear();
	
	for (unsigned i = 0; i< configuration.membranes.size(); i++) {
		configuration.membranes[i].semantics = file.psystem.semantics;
	}
	
	do{
		remainingApplications = 0;
		Shuffler<CMembrane> membranes(configuration.membranes, randomized);
		for (unsigned i = 0; i < membranes.size(); i++) {
			
			if (membranes[i].parent==-2) { 
				continue;
			}
			membranes[i].priorityLevel = std::numeric_limits<long>::max();
			Shuffler<Rule> rules(ruleSets[membranes[i].label][membranes[i].charge],randomized);
			for (unsigned j = 0; j< rules.size(); j++) {
				bool aux=false;
				if (selectedPatterns.count(membranes(i))>0 && 
						rules[j].features.count("pattern")>0) {
					std::string str(rules[j].features.at("pattern").as_string());		
					if (blacklist.count(str)>0) {
						for (auto it = blacklist.at(str).begin(); it != blacklist.at(str).end(); ++it) {
							if (selectedPatterns.at(membranes(i)).count(*it)) {
								aux=true;
							}
						}
					}		
				}
				if (aux) {
					continue;
				}
				std::size_t max = getMaxApplications(membranes[i],rules[j]);
				std::size_t applications = randomized ? RANDOM(max+1) : max;
				if (rules[j].features.count("priority")>0) {
					if (rules[j].features.at("priority").cast_long() > membranes[i].priorityLevel) {
						applications = 0;
					} else if (max > applications) {
						membranes[i].priorityLevel = rules[j].features.at("priority").cast_long();
					}
				}
				if (applications>0) {
					selectedRules[membranes(i)][rules(j)] += applications;
					if (rules[j].features.count("pattern")>0) {
						std::string str(rules[j].features.at("pattern").as_string());
						selectedPatterns[membranes(i)].insert(str);
					}
					consume(membranes[i],rules[j],applications);
				}
				remainingApplications += (max - applications);
			}
		}
	} while (remainingApplications > 0);
	
	if (getVerbosityLevel()>1 && !selectedRules.empty()) {
		std::cout<<"-----------------------------------------------\n\n";
		std::cout<<"STEP "<<configuration.time+1<<":\n"; 
		for (auto it1 = selectedRules.begin(); it1 != selectedRules.end(); ++it1) {
			CMembrane& m = configuration.membranes[it1->first];
			std::cout << "\nMembrane ID: "<< it1->first << std::endl;
			const std::vector<Rule>& rules = ruleSets[m.label][m.charge];
			for (auto it2 = it1->second.begin(); it2 != it1->second.end(); ++it2) {
				std::cout<< it2->second <<" * "<< rules[it2->first] << std::endl;
			}
		}
	}
}


inline
void Simulator::consume(CMembrane& m, const Rule& rule, std::size_t applications) 
{
	if (rule.features.count("pattern")>0) {
		updateSemantics(m.semantics,rule.features.at("pattern").as_string(),applications);
	}
	
	
	Multiset& pMs = m.parent == -1 ? configuration.environment : configuration.membranes[m.parent].multiset;
	sub(pMs, rule.lhr.multiset, applications);
	sub(m.multiset,rule.lhr.membrane.multiset,applications);
	bool found;
	unsigned i;
	for (const IMembrane& im : rule.lhr.membrane.data) {
		found = false;
		i=0;
		while(i<m.children.size() && !found) {
			if (configuration.membranes[m.children[i]].label == im.label && 
				configuration.membranes[m.children[i]].charge == im.charge) {
				found = true;		
			} else {
				i++;
			}
		}
		if (found) {
			sub(configuration.membranes[m.children[i]].multiset,im.multiset,applications);
		}
	}
	
	if (rule.arrow == 1 && rule.rhr.data[0].label[0] != "0") {
		for (CMembrane& m : configuration.membranes) {
			if (m.label == rule.rhr.data[0].label) {
				sub(m.multiset, rule.rhr.data[0].multiset,applications);
				break;
			}
		}
		
	}
	
}



inline
void Simulator::add(Multiset& ms0, const Multiset& ms1, std::size_t times)
{
	if (times==0 || ms1.empty()) {
		return;
	}
	for (auto it = ms1.begin(); it!= ms1.end(); ++it) {
		ms0[it->first] += it->second.raw() * times;
	}
	
}


inline
void Simulator::sub(Multiset& ms0, const Multiset& ms1, std::size_t times)
{
	if (times==0 || ms1.empty()) {
		return;
	}
	for (auto it = ms1.begin(); it!= ms1.end(); ++it) {
		auto it1 = ms0.find(it->first);
		if (it1 == ms0.end()) {
			continue;
		}
		it1->second = it1->second.raw() - it->second.raw() * times;
		if (it1->second.raw() <= 0) {
			ms0.erase(it1);
		}
	}
	
}

inline
void Simulator::produce(unsigned membraneId, const OMembrane& lhrMembrane, const OMembrane& om, std::size_t applications, std::set<unsigned>& dissolving)
{
	CMembrane& m = configuration.membranes[membraneId];
	add(m.multiset,om.multiset,applications);
	if (om.charge != lhrMembrane.charge) {
		m.charge = om.charge;
	}
	if (m.multiset.count("@d")) {
		m.multiset.erase("@d");
		dissolving.insert(membraneId);
	}
	for (const IMembrane& im : om.data) {
		bool found = false;
		unsigned i=0;
		while(i<m.children.size() && !found) {
			if (configuration.membranes[m.children[i]].label == im.label) {
				found = true;		
			} else {
				i++;
			}
		}
		if (!found) {
			throw new std::runtime_error("Unable to produce");
		}
		configuration.membranes[m.children[i]].charge = im.charge;
		add(configuration.membranes[m.children[i]].multiset,im.multiset,applications);
		if (configuration.membranes[m.children[i]].multiset.count("@d")>0) {
			configuration.membranes[m.children[i]].multiset.erase("@d");
			dissolving.insert(m.children[i]);
		}
	}
}

inline
unsigned Simulator::copyMembrane(unsigned membraneId)
{
	unsigned index;
	if (freeIndexes.empty()) {
		index = configuration.membranes.size();
		configuration.membranes.resize(configuration.membranes.size()+1);
	} else {
		index = freeIndexes.front();
		freeIndexes.pop();
	}
	configuration.membranes[index].charge = configuration.membranes[membraneId].charge;
	configuration.membranes[index].label = configuration.membranes[membraneId].label;
	configuration.membranes[index].multiset = configuration.membranes[membraneId].multiset;
	configuration.membranes[index].parent = configuration.membranes[membraneId].parent;
	if (configuration.membranes[index].parent != -1) {
		configuration.membranes[configuration.membranes[index].parent].children.push_back(index);
	}
	
	for (unsigned i=0;i<configuration.membranes[membraneId].children.size(); i++) {
		configuration.membranes[index].children.push_back(copyMembrane(configuration.membranes[membraneId].children[i]));
	}
	
	return index;
}


inline
void Simulator::produce(unsigned membraneId, const Rule& rule, std::size_t applications, std::set<unsigned>& dissolving)
{
	CMembrane& m = configuration.membranes[membraneId];
	
	
	if (rule.arrow == 1) {
		add(m.multiset,rule.rhr.data[0].multiset,applications);
		for (CMembrane& m1 : configuration.membranes) {
			if (m1.label == rule.rhr.data[0].label) {
				if (m1.label[0]=="0") {
					add(m1.multiset,rule.lhr.membrane.multiset,1);
				} else {
					add(m1.multiset,rule.lhr.membrane.multiset,applications);
				}
				break;
			}
		}
		return;
		
	}
	
	
	Multiset& pMs = m.parent == -1 ? configuration.environment : configuration.membranes[m.parent].multiset;
	add(pMs,rule.rhr.multiset,applications);
	if (rule.rhr.data.size()==0) {
		dissolving.insert(membraneId);
		return;
	} 
	for (unsigned i = 1; i< rule.rhr.data.size(); i++) {
		unsigned index = copyMembrane(membraneId);
		produce(index,rule.lhr.membrane,rule.rhr.data[i],applications,dissolving);
	}
	produce(membraneId,rule.lhr.membrane,rule.rhr.data[0],applications,dissolving);
}


inline
void Simulator::executeRules()
{
	if (selectedRules.empty()) {
		return;
	}
		
	std::set<unsigned> dissolving;
	
	// First pass: no division
	for (auto it1 = selectedRules.begin(); it1 != selectedRules.end(); ++it1) {
		CMembrane& m = configuration.membranes[it1->first];
		const std::vector<Rule>& rules = ruleSets[m.label][m.charge];
		auto it2 = it1->second.begin();
		while (it2 != it1->second.end()) {
			const Rule& r = rules[it2->first];
			if (r.rhr.data.size()>1) {
				++it2;
			} else {
				produce(it1->first,r,it2->second,dissolving);
				it2 = it1->second.erase(it2);
			}
		}
	}
	
	// Second pass: division
	for (auto it1 = selectedRules.begin(); it1 != selectedRules.end(); ++it1) {
		CMembrane& m = configuration.membranes[it1->first];
		const std::vector<Rule>& rules = ruleSets[m.label][m.charge];
		for (auto it2 = it1->second.begin(); it2 != it1->second.end(); ++it2) {
			const Rule& r = rules[it2->first];
			produce(it1->first,r,it2->second,dissolving);
		}
	}
	
	// dissolution
	for (unsigned index : dissolving) {
		CMembrane& m = configuration.membranes[index];
		Multiset& pMs = m.parent == -1 ? configuration.environment : configuration.membranes[m.parent].multiset;
		add(pMs,m.multiset,1);
		if (m.parent != -1) {
			for (unsigned i=0;i<configuration.membranes[m.parent].children.size();i++) {
				if (configuration.membranes[m.parent].children[i]==(int)index) {
					configuration.membranes[m.parent].children[i] = configuration.membranes[m.parent].children[configuration.membranes[m.parent].children.size()-1];
					configuration.membranes[m.parent].children.resize(configuration.membranes[m.parent].children.size()-1);
					break;
				}
			}
		}
		for (unsigned i=0;i<m.children.size();i++) {
			if (m.parent!=-1) {
				configuration.membranes[m.parent].children.push_back(m.children[i]);
			}
			configuration.membranes[m.children[i]].parent = m.parent;
		}
		freeIndexes.push(index);
		m.parent = -2;
		m.multiset.clear();
		m.children.clear();	
	}
	
	
	configuration.time++;
	
	if (getVerbosityLevel()>0) {
		std::cout<<"\n***********************************************\n\n";
		std::cout<<getCurrentConfiguration()<<std::endl;
	}
	
}



bool Simulator::updateSemantics(Semantics& semantics, const std::string& pattern, std::size_t applications)
{
	if (!semantics.inf && semantics.value < applications) {
		return false;
	}
		
	if (!semantics.inf)  {
		semantics.value-=applications;
	}
	if (semantics.patterns.count(pattern)>0) {
		return true;
	}
	for (Semantics& child : semantics.children) {
		if (updateSemantics(child,pattern,applications)) {
			return true;
		}
	}
	if (!semantics.inf) {
		semantics.value+=applications;
	}
	return false;
	
}

std::size_t Simulator::getMaxApplications(const Semantics& semantics, const std::string& pattern) const
{
	if (semantics.patterns.count(pattern)>0) {
		return semantics.inf ? std::numeric_limits<std::size_t>::max() : semantics.value;
	}
	for (const Semantics& child : semantics.children) {
		std::size_t aux = getMaxApplications(child,pattern);
		if (aux > 0) {
			return aux;
		}
	}
	return 0;
}



std::size_t Simulator::getMaxApplications(const CMembrane& m, const Rule& rule) const
{
	
	const LHR& lhr = rule.lhr;
	
	if (m.children.size() < lhr.membrane.data.size()) {
		return 0;
	}
	
	std::size_t min = std::numeric_limits<std::size_t>::max();
	
	if (rule.features.count("pattern")>0) {
		min = std::min(min,getMaxApplications(m.semantics,rule.features.at("pattern").as_string()));
		if (min==0) {
			return 0;
		}
	}
		
	const Multiset& pMs = m.parent == -1 ? configuration.environment : configuration.membranes[m.parent].multiset;
	
	min = std::min(min, count(lhr.multiset,pMs));
	
	if (min==0) {
		return 0;
	}
	
	min = std::min(min, count(lhr.membrane.multiset,m.multiset));
	
	if (min==0) {
		return 0;
	}

	bool found;
	unsigned i;
	for (const IMembrane& im : lhr.membrane.data) {
		found = false;
		i=0;
		while(i<m.children.size() && !found) {
			if (configuration.membranes[m.children[i]].label == im.label && 
				configuration.membranes[m.children[i]].charge == im.charge) {
				found = true;		
			} else {
				i++;
			}
		}
		if (!found) {
			return 0;
		}
		min = std::min(min,count(im.multiset,configuration.membranes[m.children[i]].multiset));
		if (min==0) {
			return 0;
		}	
	}
	
	
	if (rule.arrow==1) {
		found = false;
		for (const CMembrane& m : configuration.membranes) {
			if (m.label == rule.rhr.data[0].label) {
				found=true;
				if (m.label[0]=="0") {
					if (count(rule.rhr.data[0].multiset,m.multiset)==0) {
						min=0;
					}
				} else {
					min = std::min(min,count(rule.rhr.data[0].multiset,m.multiset));
				}
				break;
			}
		}
		if (!found) {
			min = 0;
		}
		
	}
	
	
	return min;
}


std::size_t Simulator::count(const Multiset& ms0, const Multiset& ms1)
{
	if (ms0.empty()) {
		return std::numeric_limits<std::size_t>::max();
	}
		
	if (ms1.size() < ms0.size()) {
		return 0;
	}
	std::size_t min = std::numeric_limits<std::size_t>::max();
	for (auto it0 = ms0.begin(); it0 != ms0.end() && min>0; ++it0) {
		auto it1 = ms1.find(it0->first);
		if (it1 == ms1.end()) {
			min = 0;
		} else {
			std::size_t aux = it1->second.raw() / it0->second.raw();
			if (aux < min) {
				min = aux;
			}
		}
	}
	return min;
}


inline
bool Simulator::ruleSupportedArrow0(const Rule& rule)
{
	if (rule.lhr.multiset.count("@d")>0 || rule.lhr.membrane.multiset.count("@d") || rule.rhr.multiset.count("@d")>0) {
		return false;
	}
	
	for (unsigned i=0;i< rule.rhr.data.size(); i++) {
		
		if (rule.rhr.data[i].multiset.count("@d")>0 && rule.rhr.data.size()>1) {
			return false;
		}
		
		if (rule.lhr.membrane.label != rule.rhr.data[i].label) {
			return false;
		}
		if (rule.lhr.membrane.data.size() != rule.rhr.data[i].data.size()) {
			return false;
		}
		
		for (unsigned j=0;j< rule.lhr.membrane.data.size(); j++) {
			if (rule.lhr.membrane.data[j].label != rule.rhr.data[i].data[j].label) {
				return false;
			}
			if (rule.lhr.membrane.data[j].multiset.count("@d")>0) {
				return false;
			}
			if (rule.rhr.data[i].data[j].multiset.count("@d")>0 && rule.rhr.data.size()>1) {
				return false;
			}	
		}
	}
	return true;
}

inline 
bool Simulator::ruleSupportedArrow1(const Rule& rule)
{
	// <-->
	if (!rule.lhr.multiset.empty() || !rule.rhr.multiset.empty()) {
		return false;
	}
	
		
	if (rule.rhr.data.size()!=1) {
		return false;
	}
	
	if (rule.lhr.membrane.data.size()>0 || rule.rhr.data[0].data.size()>0) {
		return false;
	}
	
	if (rule.lhr.membrane.charge!=0 || rule.rhr.data[0].charge!=0) {
		return false;
	}
	
	if (rule.lhr.membrane.label == rule.rhr.data[0].label) {
		return false;
	}
	
		
	if (rule.lhr.membrane.multiset.count("@d")>0 || rule.rhr.data[0].multiset.count("@d")>0) {
		return false;
	}
	
	return true;
}


inline
bool Simulator::ruleSupported(const Rule& rule)
{
	if  (rule.features.count("probability")> 0) {
		return false;
	}
	
	if (rule.arrow == 0) {
		return ruleSupportedArrow0(rule);
	} 
	
	if (rule.arrow == 1) {
		return ruleSupportedArrow1(rule);
	}	
	
	return false;
}


template <class Container>
void split3(const std::string& str, Container& cont,
              char delim = ' ')
{
    std::size_t current, previous = 0;
    current = str.find(delim);
    while (current != std::string::npos) {
        cont.push_back(str.substr(previous, current - previous));
        previous = current + 1;
        current = str.find(delim, previous);
    }
    cont.push_back(str.substr(previous, current - previous));
}

	
inline
bool Simulator::parse(int argc, char *argv[])
{
	
	ruleSets.clear();
	selectedRules.clear();
	while(!freeIndexes.empty()) {
		freeIndexes.pop();
	}
	configuration.clear();
		
	
	if (!CommandLine::parse(argc,argv)) {
		finished = true;
		return false;
	}

	loadFromFile(getInputFile(),file);
	
	if (getConfigurationFile().empty()) {
		initConfigurationRec(file.psystem.structure, -1);
	} else {
		loadFromFile(getConfigurationFile(),configuration);
	}
	
	for (const Rule& rule : file.psystem.rules) {
		
		if (!ruleSupported(rule)) {
			 std::ostringstream ss;
			 ss << "Rule not supported: "<< rule ;
			 std::cout << ss.str() <<std::endl;
			 throw new std::runtime_error(ss.str());
		}
		ruleSets[rule.lhr.membrane.label][rule.lhr.membrane.charge].push_back(rule);
	}	
	
	if (file.psystem.features.count("blacklist")>0) {
		blacklist.clear();
		std::string str(file.psystem.features.at("blacklist").as_string()); 
		std::vector<std::string> cont;
		split3(str,cont,';');
		for (std::string& x : cont) {
			std::vector<std::string> cont1;
			split3(x,cont1,',');
			for (unsigned i= 1;i<cont1.size();i++) {
				blacklist[cont1[0]].insert(cont1[i]);	
			}
		}
		
	}
	
	struct {
		inline bool operator()(const Rule& a, const Rule& b)  {
						
			if (a.features.count("priority") > 0 && b.features.count("priority") > 0) {
				long x = a.features.at("priority").cast_long();
				long y = b.features.at("priority").cast_long();
				return x < y;
			}
			return a < b;
		}
	} customLess;
	
	for (auto it1 = ruleSets.begin(); it1 != ruleSets.end(); ++it1) {
		for (auto it2 = it1->second.begin(); it2 != it1->second.end(); ++it2) {
			std::vector<Rule>& rules = it2->second;
			std::sort(rules.begin(),rules.end(),customLess);
		}
	}
	
	if (!randomized) {
		randomized = file.psystem.features.count("randomized");
	}
	if (getVerbosityLevel()>1) {
		std::cout<<"// P SYSTEM TO SIMULATE:\n";
		std::cout<<getFile()<<"\n\n";
		std::cout<<"***********************************************\n\n";
	}
	if (getVerbosityLevel()>0) {
		std::cout<<getCurrentConfiguration()<<std::endl;
	}
	initialTime = configuration.time;
	finished = false;
	return true;
}

inline
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
		configuration.membranes[parent].children.push_back(index);
	}
	for (const Membrane& m : membrane.data) {
		initConfigurationRec(m,index);
	}
}



	
}}



#endif

