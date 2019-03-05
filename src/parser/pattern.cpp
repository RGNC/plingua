#include <parser/parser.hpp>

using namespace plingua::parser;





bool Parser::checkRule(Rule& rule,  const YYLTYPE& location) {
	bool success = false;
	if (rule.features.count("pattern")>0) {
		return true;
	}
	for (auto it = patterns.begin(); it != patterns.end() && !success; ++it) {
		const std::string& id = it->first;
		const std::set<Rule>& rules = it->second;
		for (auto it1 = rules.begin(); it1!= rules.end() && !success; ++it1) {
			const Rule& pattern = *it1;
			if(matchRule(rule, pattern)) {
				rule.features["pattern"] = id;
				success = true;
			}
		}
	}
	if (!success) {
		error("invalid rule",location);
	}
	return success;
}

bool Parser::matchRule(const Rule& rule, const Rule& pattern) {
	Match match;
	return rule.arrow == pattern.arrow && matchLHR(rule.lhr,pattern.lhr,match) && matchRHR(rule.rhr,pattern.rhr,match) && matchFeatures(rule.features,pattern.features);
}

bool Parser::matchFeatures(const Features& rF, const Features& pF) {
	// TODO
	return true;
}

bool Parser::matchLHR(const LHR& rLHR, const LHR& pLHR, Match& match) {
	return matchMultiset(rLHR.multiset, pLHR.multiset,match) && matchOMembrane(rLHR.membrane,pLHR.membrane,match);
	
}

bool Parser::matchRHR(const RHR& rRHR, const RHR& pRHR, Match& match) {
	if (!matchMultiset(rRHR.multiset,pRHR.multiset,match)) {
		return false;
	}
	if (rRHR.data.size() != pRHR.data.size()) {
		return false;
	}
	if (pRHR.data.empty()) {
		return true;
	}
	std::vector<unsigned> permutation(pRHR.data.size());
	for (unsigned i=0;i<pRHR.data.size();i++) {
		permutation[i] = i;
	}
	return matchOMembranes(rRHR,pRHR,match,0,permutation);
}


bool Parser::matchIMembrane(const IMembrane& rM, const IMembrane& pM, Match& match) {
	return matchCharge(rM.charge,pM.charge,match) && matchLabel(rM.label,pM.label,match) && matchMultiset(rM.multiset,pM.multiset,match);
}

bool Parser::matchOMembrane(const OMembrane& rM, const OMembrane& pM, Match& match) {
	if (!matchIMembrane(rM,pM,match)) {
		return false;
	}
	if (rM.data.size() != pM.data.size()) {
		return false;
	}
	if (pM.data.empty()) {
		return true;
	}
	
	std::vector<unsigned> permutation(pM.data.size());
	for (unsigned i=0;i<pM.data.size();i++) {
		permutation[i] = i;
	}
	
	return matchIMembranes(rM,pM,match,0,permutation);
}


bool Parser::matchOMembranes(const RHR& rRHR, const RHR& pRHR, Match& match, unsigned index, std::vector<unsigned>& permutation) {
		if (index==permutation.size()) {
		Match aux(match);
		for (unsigned i=0;i<pRHR.data.size();i++) {
			if (!matchOMembrane(rRHR.data[permutation[i]],pRHR.data[i],aux)) {
				return false;
			}
		}
		match = aux;
		return true;
	}
	unsigned aux = permutation[index];
	for (unsigned i = index; i< permutation.size(); i++) {
		permutation[index] = permutation[i];
		permutation[i] = aux;
		if (matchOMembranes(rRHR,pRHR,match,index+1,permutation)) {
			return true;
		}
		permutation[i] = permutation[index];
		permutation[index] = aux;
	} 
	return false;
	
}


bool Parser::matchIMembranes(const OMembrane& rM, const OMembrane& pM, Match& match, unsigned index, std::vector<unsigned>& permutation) {
	if (index==permutation.size()) {
		Match aux(match);
		for (unsigned i=0;i<pM.data.size();i++) {
			if (!matchIMembrane(rM.data[permutation[i]],pM.data[i],aux)) {
				return false;
			}
		}
		match = aux;
		return true;
	}
	unsigned aux = permutation[index];
	for (unsigned i = index; i< permutation.size(); i++) {
		permutation[index] = permutation[i];
		permutation[i] = aux;
		if (matchIMembranes(rM,pM,match,index+1,permutation)) {
			return true;
		}
		permutation[i] = permutation[index];
		permutation[index] = aux;
	} 
	return false;
} 


bool Parser::matchCharge(char rC, char pC, Match& match) {
	if (pC < 2) {
		return rC == pC;
	}
	if (pC == 2) {
		return true;
	}
	auto pair = match.charges.emplace(pC,rC);
	if (pair.second) {
		return true;
	}
	return pair.first->second == rC;
}

bool Parser::matchLabel(const Label& rL, const Label& pL, Match& match) {
	if (rL.size() != pL.size()) {
		return false;
	}
	for (unsigned i = 0; i< pL.size(); i++) {
		auto pair = match.labels.emplace(pL[i].str(),rL[i].str());
		if (pair.first->second != rL[i].str()) {
			return false;
		}
	}
	return true;
}


bool Parser::matchMultiset(const Multiset& rMS, const Multiset& pMS, Match& match) {

	if (!isSingleObjectPattern(pMS) && !isMultisetPattern(pMS)) {
		return rMS == pMS;
	}
	if (isSingleObjectPattern(pMS) && !isSingleObject(rMS)) {
		return false;
	}
	const std::string& object = pMS.begin()->first.str();
	if (object.size()==1) {
		return true;
	}
	auto pair = match.multisets.emplace(pMS.begin()->first.str(),rMS);
	if (pair.second) {
		return true;
	}
	return pair.first->second == rMS;
}

bool Parser::isSingleObject(const Multiset& multiset) {
	if (multiset.size()!=1) {
		return false;
	}
	auto it = multiset.begin();
	std::size_t multiplicity = it->second.raw();
	return multiplicity == 1;
}


bool Parser::isSingleObjectPattern(const Multiset& multiset) {
	if (!isSingleObject(multiset)) {
		return false;
	}
	const std::string& object = multiset.begin()->first.str();
	return object[0]=='a' || object[0]=='b' || object[0]=='c' || object[0]=='d';
}



bool Parser::isMultisetPattern(const Multiset& multiset) {
	if (!isSingleObject(multiset)) {
		return false;
	}
	const std::string& object = multiset.begin()->first.str();
	return object[0]=='u' || object[0]=='v' || object[0]=='w';
}






