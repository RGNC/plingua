#include <limits>
#include <fstream>
#include "cereal/archives/xml.hpp"
#include "cereal/archives/json.hpp"
#include "cereal/archives/binary.hpp"
#include "cereal/archives/portable_binary.hpp"


namespace plingua {

inline
Value& Value::operator =(char value) {
	clear(); 
	type_ = CHAR;   
	value_.charValue = value; 
	return *this;
}

inline
Value& Value::operator =(unsigned char value) {
	if (value >= std::numeric_limits<char>::min() &&
	     value <= std::numeric_limits<char>::max()) {
		return operator =((char)value);
	}
	clear(); 
	type_ = UCHAR;   
	value_.ucharValue = value; 
	return *this;
}

inline
Value& Value::operator =(short value) {
	if (value >= std::numeric_limits<unsigned char>::min() &&
	     value <= std::numeric_limits<unsigned char>::max()) {
		return operator =((unsigned char)value);
	}
	clear(); 
	type_ = SHORT;    
	value_.shortValue = value; 
	return *this;
}

inline
Value& Value::operator =(unsigned short value) {
	if (value >= std::numeric_limits<short>::min() &&
	     value <= std::numeric_limits<short>::max()) {
		return operator =((short)value);
	}
	clear(); 
	type_ = USHORT;    
	value_.ushortValue = value; 
	return *this;
}


inline
Value& Value::operator =(int value) {
	if (value >= std::numeric_limits<unsigned short>::min() &&
	     value <= std::numeric_limits<unsigned short>::max()) {
		return operator =((unsigned short)value);
	}
	clear(); 
	type_ = INT;    
	value_.intValue = value; 
	return *this;
}

inline
Value& Value::operator =(unsigned int value) {
	if (value <= std::numeric_limits<int>::max()) {
		return operator =((int)value);
	}
	clear(); 
	type_ = UINT;    
	value_.uintValue = value; 
	return *this;
}

inline
Value& Value::operator =(long value) {
	if (value >= std::numeric_limits<unsigned int>::min() &&
	     value <= std::numeric_limits<unsigned int>::max()) {
		return operator =((unsigned int)value);
	}
	clear(); 
	type_ = LONG;   
	value_.longValue = value; 
	return *this;
}

inline
Value& Value::operator =(double value) {
	clear(); 
	type_ = DOUBLE; 
	value_.doubleValue = value; 
	return *this;
}

inline
Value& Value::operator =(const char* value) {
	clear(); 
	type_ = STRING; 
	value_.stringValue = strdup(value); 
	return *this;
}

inline
Value& Value::operator =(const std::string& value) {
	return this->operator =(value.c_str());
}

inline
Value& Value::operator =(const Value& other){
		clear(); 
		type_ = other.type_;
		switch(type_) {
			case CHAR   : value_.charValue   = other.value_.charValue;   break;
			case UCHAR   : value_.ucharValue   = other.value_.ucharValue;   break;
			case SHORT   : value_.shortValue   = other.value_.shortValue;   break;
			case USHORT   : value_.ushortValue   = other.value_.ushortValue;   break;
			case INT    : value_.intValue    = other.value_.intValue;    break; 
			case UINT    : value_.uintValue    = other.value_.uintValue;    break; 
			case LONG   : value_.longValue   = other.value_.longValue;   break;
			case DOUBLE : value_.doubleValue = other.value_.doubleValue; break;
			case STRING : value_.stringValue = strdup(other.value_.stringValue); break;
		}
		return *this;
	} 

inline
void Value::clear() {
	if (type_==STRING) {
		free(value_.stringValue);
	}
}

template<class A> 
void Value::save(A& archive) const {
	
	archive(cereal::make_nvp("type", type_));
	switch(type_) {
		case CHAR:
			archive(cereal::make_nvp("value", value_.charValue));
			break;
		case UCHAR:
			archive(cereal::make_nvp("value", value_.ucharValue));
			break;
		case SHORT:
			archive(cereal::make_nvp("value", value_.shortValue));
			break;
		case USHORT:
			archive(cereal::make_nvp("value", value_.ushortValue));
			break;
		case INT:
			archive(cereal::make_nvp("value", value_.intValue));
			break;
		case UINT:
			archive(cereal::make_nvp("value", value_.uintValue));
			break;
		case LONG:
			archive(cereal::make_nvp("value", value_.longValue));
			break;
		case DOUBLE:
			archive(cereal::make_nvp("value", value_.doubleValue));
			break;
		case STRING:
			ALPHABET.getStringId(value_.stringValue).save(archive);
			
			break;
	};
	
}

template<class A> 
void Value::load(A& archive) {
	
	archive(cereal::make_nvp("type", type_));
	switch(type_) {
		case CHAR:
			archive(cereal::make_nvp("value", value_.charValue));
			break;
		case UCHAR:
			archive(cereal::make_nvp("value", value_.ucharValue));
			break;
		case SHORT:
			archive(cereal::make_nvp("value", value_.shortValue));
			break;
		case USHORT:
			archive(cereal::make_nvp("value", value_.ushortValue));
			break;
		case INT:
			archive(cereal::make_nvp("value", value_.intValue));
			break;
		case UINT:
			archive(cereal::make_nvp("value", value_.uintValue));
			break;
		case LONG:
			archive(cereal::make_nvp("value", value_.longValue));
			break;
		case DOUBLE:
			archive(cereal::make_nvp("value", value_.doubleValue));
			break;
		case STRING:
		{
			UId aux(archive, ALPHABET.getStringsAlphabetSize());
			value_.stringValue = strdup(ALPHABET.getString(aux.getId()).c_str()); 
		}
		break;
	};
}

inline
Multiplicity::Multiplicity()
: multiplicity(0) 
{}

inline
Multiplicity::Multiplicity(std::size_t multiplicity)
: multiplicity(multiplicity)
{}

inline
Multiplicity& Multiplicity::operator =(std::size_t multiplicity) {
	Multiplicity::multiplicity = multiplicity;
	return *this;
}

inline
Multiplicity Multiplicity::operator  ++(int) {
	std::size_t aux = multiplicity;
	++multiplicity;
	return Multiplicity(aux);
}

inline
Multiplicity& Multiplicity::operator ++() {
	++multiplicity;
	return *this;
}

inline
Multiplicity& Multiplicity::operator +=(const Multiplicity& other) {
	multiplicity += other.multiplicity;
	return *this;
}

inline
bool Multiplicity::operator ==(const Multiplicity& other) const {
	return multiplicity == other.multiplicity;
}

inline
bool Multiplicity::operator  <(const Multiplicity& other) const {
	return multiplicity < other.multiplicity;
}

inline
std::size_t Multiplicity::raw() const {
	return multiplicity;
}

template<class A> void Multiplicity::save(A& archive) const {
	if (ALPHABET.getMaxMultiplicity() <= std::numeric_limits<unsigned char>::max()) {
		unsigned char aux = (unsigned char)multiplicity;
		archive(cereal::make_nvp("multiplicity",aux));
	} else if (ALPHABET.getMaxMultiplicity() <= std::numeric_limits<unsigned short>::max()) {
		unsigned short aux = (unsigned short)multiplicity;
		archive(cereal::make_nvp("multiplicity",aux));
	} else if (ALPHABET.getMaxMultiplicity() <= std::numeric_limits<unsigned int>::max()) {
		unsigned int aux = (unsigned int)multiplicity;
		archive(cereal::make_nvp("multiplicity",aux));
	} else {
		unsigned long aux = (unsigned long)multiplicity;
		archive(cereal::make_nvp("multiplicity",aux));
	}
}

template<class A> void Multiplicity::load(A& archive) {
	if (ALPHABET.getMaxMultiplicity() <= std::numeric_limits<unsigned char>::max()) {
		unsigned char aux;
		archive(cereal::make_nvp("multiplicity",aux));
		multiplicity = aux;
	} else if (ALPHABET.getMaxMultiplicity() <= std::numeric_limits<unsigned short>::max()) {
		unsigned short aux;
		archive(cereal::make_nvp("multiplicity",aux));
		multiplicity = aux;
	} else if (ALPHABET.getMaxMultiplicity() <= std::numeric_limits<unsigned int>::max()) {
		unsigned int aux;
		archive(cereal::make_nvp("multiplicity",aux));
		multiplicity = aux;
	} else {
		unsigned long aux;
		archive(cereal::make_nvp("multiplicity",aux));
		multiplicity = aux;
	}
}


template<class A> 
void LabelString::save(A& archive) const {
	ALPHABET.getLabelId(str()).save(archive);
}

template<class A> 
void LabelString::load(A& archive) {
	UId aux(archive, ALPHABET.getLabelAlphabetSize());
	String::operator =(ALPHABET.getLabel(aux.getId()));
}


template<class A> 
void ObjectString::save(A& archive) const {
	ALPHABET.getObjectId(str()).save(archive);
}

template<class A> 
void ObjectString::load(A& archive) {
	UId aux(archive, ALPHABET.getObjectAlphabetSize());
	String::operator =(ALPHABET.getObject(aux.getId()));
}


template<class A> 
void FeatureString::save(A& archive) const {
	ALPHABET.getFeatureId(str()).save(archive);
}

template<class A> 
void FeatureString::load(A& archive) {
	UId aux(archive, ALPHABET.getFeatureAlphabetSize());
	String::operator =(ALPHABET.getFeature(aux.getId()));
}

inline
UId::UId() 
: max(std::numeric_limits<unsigned char>::max()), id(0) {}


inline
UId::UId(std::size_t id, std::size_t max) {
	set(id,max);
}

inline
void UId::set(std::size_t id, std::size_t max) {
	UId::id = id;
	if (max <= std::numeric_limits<unsigned char>::max()) {
		UId::max = std::numeric_limits<unsigned char>::max();
	} else if (max <= std::numeric_limits<unsigned short>::max()) {
		UId::max = std::numeric_limits<unsigned short>::max();
	} else if (max <= std::numeric_limits<unsigned int>::max()) {
		UId::max = std::numeric_limits<unsigned int>::max();
	} else {
		UId::max = std::numeric_limits<unsigned long>::max();
	}
}


inline
UId& UId::operator =(std::size_t id) {
	max = std::numeric_limits<unsigned long>::max();
	UId::id = id;
	return *this;
}

template<class A> 
void UId::save(A& archive) const {
	if (max <= std::numeric_limits<unsigned char>::max()) {
		unsigned char aux = (unsigned char)id;
		archive(cereal::make_nvp("id",aux));
	} else if (max <= std::numeric_limits<unsigned short>::max()) {
		unsigned short aux = (unsigned short)id;
		archive(cereal::make_nvp("id",aux));
	} else if (max <= std::numeric_limits<unsigned int>::max()) {
		unsigned int aux = (unsigned int)id;
		archive(cereal::make_nvp("id",aux));
	} else {
		unsigned long aux = (unsigned long)id;
		archive(cereal::make_nvp("id",aux));
	}
}


template<class A>
UId::UId(A& archive, std::size_t max) {
	if (max <= std::numeric_limits<unsigned char>::max()) {
		UId::max = std::numeric_limits<unsigned char>::max();
		unsigned char aux;
		archive(cereal::make_nvp("id",aux));
		id = aux;
	} else if (max <= std::numeric_limits<unsigned short>::max()) {
		UId::max = std::numeric_limits<unsigned short>::max();
		unsigned short aux;
		archive(cereal::make_nvp("id",aux));
		id = aux;
	} else if (max <= std::numeric_limits<unsigned int>::max()) {
		UId::max = std::numeric_limits<unsigned int>::max();
		unsigned int aux;
		archive(cereal::make_nvp("id",aux));
		id = aux;
	} else {
		UId::max = std::numeric_limits<unsigned long>::max();
		unsigned long aux;
		archive(cereal::make_nvp("id",aux));
		id = aux;
	}
}

inline
bool UId::operator ==(const UId& other) const {
	return id == other.id;
}

inline
bool UId::operator  <(const UId& other) const {
	return id < other.id;
}





template<class T>
bool ExtendedVector<T>::operator==(const ExtendedVector<T>& other) const {
	if (data.size() != other.data.size()) {
		return false;
	}
	std::vector<T> aux0(data);
	std::vector<T> aux1(other.data);
	std::sort(aux0.begin(),aux0.end());
	std::sort(aux1.begin(),aux1.end());
	return aux0 == aux1; 
}

template<class T>	
bool ExtendedVector<T>::operator<(const ExtendedVector<T>& other) const {
	if (data.size() < other.data.size()) {
		return true;
	}
	if (!data.empty() && data.size() == other.data.size()) {
		std::vector<T> aux0(data);
		std::vector<T> aux1(other.data);
		std::sort(aux0.begin(),aux0.end());
		std::sort(aux1.begin(),aux1.end());
		unsigned c=0;
		for (unsigned i=0; i<data.size(); ++i) {
			if (aux0[i]==aux1[i]) {
				++c;
			} else if (!(aux0[i]<aux1[i])) {
				return false;
			}
		}
		return c<data.size();
	}
	return false;
}

inline
LeafMembrane::LeafMembrane() : charge(0) {}

inline
const char* LeafMembrane::getChargeSymbol() const 
{
	switch(charge) {
		case -1:  return "-"; 
		case  1:  return "+";
		case  2:  return "?";
		case  3:  return "?0";
		case  4:  return "?1";
		case  5:  return "?2";
		case  6:  return "?3";
		case  7:  return "?4";
		case  8:  return "?5";
		case  9:  return "?6";
		case  10: return "?7";
		case  11: return "?8";
		case  12: return "?9";
		default: return "";
 	}
	return "";
}

inline
bool LeafMembrane::operator==(const LeafMembrane& other) const {
	return charge==other.charge && label==other.label;
}

inline
bool LeafMembrane::operator<(const LeafMembrane& other) const {
	return label<other.label || (label==other.label && charge<other.charge);
}


template<class A> 
void LeafMembrane::serialize(A& archive) {
	archive(cereal::make_nvp("charge", charge),
	        cereal::make_nvp("label", label));
}


inline
bool Membrane::operator==(const Membrane& other) const {
	return LeafMembrane::operator ==(other) && ExtendedVector<Membrane>::operator ==(other);
}

inline
bool Membrane::operator<(const Membrane& other) const {
	return LeafMembrane::operator <(other) || (LeafMembrane::operator ==(other) && ExtendedVector<Membrane>::operator <(other));
}


template<class A> 
void Membrane::serialize(A& archive) {
	LeafMembrane::serialize(archive);
	archive(cereal::make_nvp("childs",ExtendedVector<Membrane>::data));
}


inline
bool IMembrane::operator ==(const IMembrane& other) const {
	return LeafMembrane::operator ==(other) && multiset == other.multiset;
}

inline
bool IMembrane::operator <(const IMembrane& other) const {
	return LeafMembrane::operator <(other) || (LeafMembrane::operator ==(other) && multiset < other.multiset);
}


template<class A> 
void IMembrane::serialize(A& archive) {
	LeafMembrane::serialize(archive);
	archive(cereal::make_nvp("multiset",multiset));
}


inline
bool OMembrane::operator==(const OMembrane& other) const {
	return IMembrane::operator ==(other) && ExtendedVector<IMembrane>::operator ==(other);
}

inline
bool OMembrane::operator<(const OMembrane& other) const {
	return IMembrane::operator <(other) || (IMembrane::operator ==(other) && ExtendedVector<IMembrane>::operator <(other));
}


template<class A> 
void OMembrane::serialize(A& archive) {
	IMembrane::serialize(archive);
	archive(cereal::make_nvp("childs",ExtendedVector<IMembrane>::data));
}


inline
bool HR::operator ==(const HR& other) const {
	return multiset == other.multiset;
}

inline
bool HR::operator <(const HR& other) const {
	return multiset < other.multiset;
}


template<class A> 
void HR::serialize(A& archive) {
	archive(cereal::make_nvp("multiset",multiset));
}


inline
bool LHR::operator==(const LHR& other) const {
	return HR::operator ==(other) && membrane == other.membrane;
}

inline
bool LHR::operator<(const LHR& other) const {
	return membrane < other.membrane || (membrane == other.membrane && HR::operator < (other));
}


template<class A> 
void LHR::serialize(A& archive) {
	HR::serialize(archive);
	archive(cereal::make_nvp("membrane",membrane));
}

inline
bool RHR::operator==(const RHR& other) const {
	return HR::operator ==(other) && ExtendedVector<OMembrane>::operator ==(other);
}

inline
bool RHR::operator<(const RHR& other) const {
	return ExtendedVector<OMembrane>::operator <(other) || (ExtendedVector<OMembrane>::operator ==(other) && HR::operator <(other));
}


template<class A> 
void RHR::serialize(A& archive) {
	HR::serialize(archive);
	archive(cereal::make_nvp("membranes",ExtendedVector<OMembrane>::data));
}

inline
Rule::Rule () : arrow(0) {}


inline
bool Rule::operator==(const Rule& other) const {
	return arrow == other.arrow && lhr == other.lhr && rhr == other.rhr;
}

inline
bool Rule::operator<(const Rule& other) const {
	return arrow < other.arrow || (arrow == other.arrow && lhr < other.lhr) || (arrow == other.arrow && lhr == other.lhr && rhr < other.rhr);
}


template<class A>
void Rule::serialize(A& archive) {
	archive(cereal::make_nvp("left_hand_rule",lhr));
	archive(cereal::make_nvp("arrow",arrow));
	archive(cereal::make_nvp("right_hand_rule",rhr));
	archive(cereal::make_nvp("features",features));
}


inline
void Alphabet::load(const Psystem& psystem)  {
	maxMultiplicity = 0;
	addMembrane(psystem.structure);
	for (auto it = psystem.multisets.begin(); it != psystem.multisets.end(); ++it) {
		addLabel(it->first);
		addMultiset(it->second);
	}	
	for (auto it = psystem.rules.begin(); it != psystem.rules.end(); ++it) {
		addRule(*it);
	}
	for (auto it = psystem.features.begin(); it != psystem.features.end(); ++it) {
		features[it->first.str()] = 0;
		if (it->second.type()==Value::Type::STRING) {
			strings[it->second.as_string()] = 0;
		}
	}
	sort();
}

inline
void Alphabet::addMultiset(const Multiset& multiset) {
	for (auto it = multiset.begin(); it!= multiset.end(); ++it) {
		objects[it->first.str()] = 0;
		if (it->second.raw() > maxMultiplicity) {
			maxMultiplicity = it->second.raw();
		}
	}
}

inline
void Alphabet::addLabel(const Label& label) {
	for (auto it = label.begin(); it != label.end(); ++it) {
		labels[(*it).str()] = 0;
	}
}

inline
void Alphabet::addMembrane(const Membrane& membrane) {
	addLabel(membrane.label);
	for (auto it = membrane.data.begin(); it != membrane.data.end(); ++it) {
		addMembrane(*it);
	}
}

inline
void Alphabet::addRule(const Rule& rule) {
	addMultiset(rule.lhr.multiset);
	addMultiset(rule.lhr.membrane.multiset);
	for (auto it = rule.lhr.membrane.data.begin(); it != rule.lhr.membrane.data.end(); ++it) {
		const IMembrane& m = *it;
		addMultiset(m.multiset);
	}
	addMultiset(rule.rhr.multiset);
	for (auto it1 = rule.rhr.data.begin(); it1 != rule.rhr.data.end(); ++it1) {
		const OMembrane& m = *it1;
		addLabel(m.label);
		addMultiset(m.multiset);
		for (auto it2 = m.data.begin(); it2 != m.data.end(); ++it2) {
			const IMembrane& m1 = *it2;
			addMultiset(m1.multiset);
		}
	}
	addLabel(rule.lhr.membrane.label);
	for (auto it = rule.features.begin(); it != rule.features.end(); ++it) {
		features[it->first.str()] = 0;
		if (it->second.type()==Value::Type::STRING) {
			strings[it->second.as_string()] = 0;
		}
	}
}

inline
void Alphabet::sort() {
	objects_array.clear();
	std::size_t counter = 0;
	for (auto it = objects.begin(); it!= objects.end(); ++it) {
		objects_array.push_back(it->first);
		it->second.set(counter++,objects.size());
	}
	labels_array.clear();
	counter = 0;
	for (auto it = labels.begin(); it!= labels.end(); ++it) {
		labels_array.push_back(it->first);
		it->second.set(counter++,labels.size());
	}
	features_array.clear();
	counter = 0;
	for (auto it = features.begin(); it!= features.end(); ++it) {
		features_array.push_back(it->first);
		it->second.set(counter++,features.size());
	}
	strings_array.clear();
	counter = 0;
	for (auto it = strings.begin(); it!= strings.end(); ++it) {
		strings_array.push_back(it->first);
		it->second.set(counter++,strings.size());
	}
}

inline
const UId& Alphabet::getObjectId(const std::string& object) const {
	return objects.at(object);
}

inline
const UId& Alphabet::getLabelId(const std::string& label) const {
	return labels.at(label);
}

inline
const UId& Alphabet::getFeatureId(const std::string& feature) const {
	return features.at(feature);
}

inline
const UId& Alphabet::getStringId(const std::string& str) const {
	return strings.at(str);
}

inline
const std::string& Alphabet::getObject(std::size_t id) const {
	return objects_array[id];
}

inline
const std::string& Alphabet::getLabel(std::size_t id) const {
	return labels_array[id];
}

inline
const std::string& Alphabet::getFeature(std::size_t id) const {
	return features_array[id];
}

inline
const std::string& Alphabet::getString(std::size_t id) const {
	return strings_array[id];
}

inline
std::size_t Alphabet::getObjectAlphabetSize() const {
	return objects.size();
}

inline
std::size_t Alphabet::getLabelAlphabetSize() const {
	return labels.size();
}

inline
std::size_t Alphabet::getFeatureAlphabetSize() const {
	return features.size();
}


inline
std::size_t Alphabet::getStringsAlphabetSize() const {
	return strings.size();
}


inline
std::size_t Alphabet::getMaxMultiplicity() const {
	return maxMultiplicity;
}

template<class A> 
void Alphabet::save(A& archive) const {
	archive(cereal::make_nvp("objects", objects_array),
	         cereal::make_nvp("labels", labels_array),
	         cereal::make_nvp("features", features_array),
	         cereal::make_nvp("strings", strings_array),
	         cereal::make_nvp("max_multiplicity", maxMultiplicity));
}

template<class A> 
void Alphabet::load(A& archive) {
	archive(cereal::make_nvp("objects", objects_array),
	         cereal::make_nvp("labels", labels_array),
	         cereal::make_nvp("features", features_array),
	         cereal::make_nvp("strings", strings_array),
	         cereal::make_nvp("max_multiplicity", maxMultiplicity));
	
	objects.clear();
	labels.clear();
	features.clear();
	strings.clear();
	for (unsigned i = 0; i< objects_array.size(); i++) {
		objects[objects_array[i]].set(i,objects_array.size());
	}         
	for (unsigned i = 0; i< labels_array.size(); i++) {
		labels[labels_array[i]].set(i,labels_array.size());
	}  
	for (unsigned i = 0; i< features_array.size(); i++) {
		features[features_array[i]].set(i,features_array.size());
	}    
	for (unsigned i = 0; i< strings_array.size(); i++) {
		strings[strings_array[i]].set(i,strings_array.size());
	}    
}


template<class A>
void Psystem::save(A& archive) const {
	ALPHABET.load(*this);
	ALPHABET.save(archive);
	archive(cereal::make_nvp("structure", structure));
	archive(cereal::make_nvp("multisets", multisets));
	archive(cereal::make_nvp("rules",rules));
	archive(cereal::make_nvp("features",features));
}


template<class A>
void Psystem::load(A& archive) {
	ALPHABET.load(archive);
	archive(cereal::make_nvp("structure", structure));
	archive(cereal::make_nvp("multisets", multisets));
	archive(cereal::make_nvp("rules",rules));
	archive(cereal::make_nvp("features",features));
}

template<class A> 
void File::serialize(A& archive) {
	archive(cereal::make_nvp("header", header),
		    cereal::make_nvp("version", version),
			cereal::make_nvp("psystem", psystem));
}

inline
void File::loadFromJsonFile(const std::string& path) {
	std::ifstream is(path);
    cereal::JSONInputArchive archive(is);
    archive(cereal::make_nvp("file",*this));
}

inline
void File::loadFromXmlFile(const std::string& path) {
	std::ifstream is(path);
    cereal::XMLInputArchive archive(is);
    archive(cereal::make_nvp("file",*this));
}

inline
void File::loadFromBinaryFile(const std::string& path) {
	std::ifstream is(path, std::ios::binary);
	cereal::BinaryInputArchive archive(is);
	archive(cereal::make_nvp("file",*this));
}

inline
void File::loadFromPortableBinaryFile(const std::string& path) {
	std::ifstream is(path, std::ios::binary);
	cereal::PortableBinaryInputArchive archive(is);
	archive(cereal::make_nvp("file",*this));
}

inline	
void File::saveToJsonFile(const std::string& path) const{
	std::ofstream os(path);
    cereal::JSONOutputArchive archive(os);
    archive(cereal::make_nvp("file",*this));
}

inline
void File::saveToXmlFile(const std::string& path) const{
	std::ofstream os(path);
    cereal::XMLOutputArchive archive(os);
	archive(cereal::make_nvp("file",*this));
}

inline
void File::saveToBinaryFile(const std::string& path) const {
	std::ofstream os(path, std::ios::binary);
	cereal::BinaryOutputArchive archive( os );
	archive(cereal::make_nvp("file",*this));
}

inline
void File::saveToPortableBinaryFile(const std::string& path) const {
	std::ofstream os(path, std::ios::binary);
	cereal::PortableBinaryOutputArchive archive(os);
	archive(cereal::make_nvp("file",*this));
}

}


inline
std::ostream& operator <<(std::ostream& os, const plingua::Multiplicity& arg) {
	return os << arg.raw();
}


inline
std::ostream& operator <<(std::ostream& os, const plingua::String& arg) {
	return os << arg.str();
}

inline
std::ostream& operator <<(std::ostream& os, const plingua::Value& arg) {
	
	switch(arg.type()) {
		case plingua::Value::Type::CHAR : return os << (int)(arg.as_char());
		case plingua::Value::Type::UCHAR : return os << (int)(arg.as_uchar());
		case plingua::Value::Type::SHORT  : return os << arg.as_short();
		case plingua::Value::Type::USHORT  : return os << arg.as_ushort();
		case plingua::Value::Type::INT  : return os << arg.as_int();
		case plingua::Value::Type::UINT  : return os << arg.as_uint();
		case plingua::Value::Type::LONG : return os << arg.as_long();
		case plingua::Value::Type::DOUBLE : return os << arg.as_double();
		case plingua::Value::Type::STRING : return os << "\"" << arg.as_string() << "\"";
		default : return os;
	}
}

inline
std::ostream& operator <<(std::ostream& os, const plingua::Multiset& arg) {
	auto it = arg.begin();
	if (it!=arg.end()) {
		os << it->first;
		if (it->second.raw() > 1) {
			os << "*"<<it->second;
		}
		while (++it != arg.end()) {
			os << "," << it->first;
			if (it->second.raw() > 1) {
				os << "*"<<it->second;
			}	
		}
	}
	return os;
}

inline
std::ostream& operator <<(std::ostream& os, const plingua::Label& arg) {
	if (!arg.empty()) {
		os << arg[0];
		for (unsigned i = 1; i< arg.size(); i++) {
			os << "," << arg[i];
		}
	}
	return os;
}

inline
std::ostream& operator <<(std::ostream& os, const plingua::LeafMembrane& arg) {
	return os << arg.getChargeSymbol() << "[ ]'" << arg.label;
}

inline
std::ostream& operator <<(std::ostream& os, const plingua::Membrane& arg) {
	os << arg.getChargeSymbol() << "[";
	for (auto it = arg.data.begin(); it != arg.data.end(); ++it) {
		os << " " << *it;
	}
	return os << " ]'" << arg.label;
}

inline
std::ostream& operator <<(std::ostream& os, const plingua::IMembrane& arg) {
	return os << arg.getChargeSymbol() << "[" << (arg.multiset.empty() ? "" : " ") << arg.multiset << " ]'" << arg.label;
}

inline
std::ostream& operator <<(std::ostream& os, const plingua::OMembrane& arg) {
	os << arg.getChargeSymbol() << "[" << (arg.multiset.empty() ? "" : " ") << arg.multiset;
	for (auto it = arg.data.begin(); it != arg.data.end(); ++it) {
		os << " " << *it;
	}
	return os << " ]'" << arg.label;
}

inline
std::ostream& operator <<(std::ostream& os, const plingua::HR& arg) {
	return os << arg.multiset;
}

inline
std::ostream& operator <<(std::ostream& os, const plingua::LHR& arg) {
	return os << arg.multiset << (arg.multiset.empty()? "" : " ") << arg.membrane;
}

inline
std::ostream& operator <<(std::ostream& os, const plingua::RHR& arg) {
	if (arg.multiset.empty() && arg.data.empty()) {
		return os << "#";
	}
	os << arg.multiset;
	auto it = arg.data.begin();
	if (it != arg.data.end()) {
		os << (arg.multiset.empty()? "" : " ") << *it;
		while (++it != arg.data.end()) {
			os << " " << *it;
		}
	}
	return os;
}

inline
std::ostream& operator <<(std::ostream& os, const plingua::Rule& arg) {
	os << arg.lhr << " ";
	switch(arg.arrow) {
		case 0 :  os << "-->"; break;
		case 1 :  os << "<-->"; break;
		default: ;
	}
	os << " " << arg.rhr;
	auto it = arg.features.begin();
	if (it!=arg.features.end()) {
		if ( (it->second.type()==plingua::Value::Type::CHAR && it->second.as_char() == 1) ||
		     (it->second.type()==plingua::Value::Type::UCHAR && it->second.as_uchar() == 1)) {
			os << " @ " << it->first;	 
		} else {
			os << " @ " << it->first << " = " << it->second;
		}
		while (++it != arg.features.end()) {
			if ( (it->second.type()==plingua::Value::Type::CHAR && it->second.as_char() == 1) ||
		     (it->second.type()==plingua::Value::Type::UCHAR && it->second.as_uchar() == 1)) {
				os << ", " << it->first;	 
			} else {
				os << ", " << it->first << " = " << it->second;
			}
		}
	}
	return os;
}

inline
std::ostream& operator <<(std::ostream& os, const plingua::Psystem& arg) {
	
	for (auto it = arg.features.begin(); it!=arg.features.end(); ++it) {
		if ( (it->second.type()==plingua::Value::Type::CHAR && it->second.as_char() == 1) ||
		     (it->second.type()==plingua::Value::Type::UCHAR && it->second.as_uchar() == 1)) {
			os << "\n@" << it->first << ";";	 
		} else {
			os << "\n@" << it->first << " = " << it->second << ";";
		}
	}
	os << (arg.features.empty() ? "" : "\n");	
	os << "\ndef main()\n{\n  @mu = " << arg.structure << ";\n";
	os << "\n  // "<< std::to_string(arg.multisets.size()) << " INITIAL MULTISETS\n";
	for (auto it = arg.multisets.begin(); it!=arg.multisets.end(); ++it) {
		os << "\n  @ms(" << it->first << ") = " << it->second<<";";
	}
	os << (arg.multisets.empty() ? "" : "\n");
	os << "\n  // "<< std::to_string(arg.rules.size()) << " RULES\n";
	for (auto it = arg.rules.begin(); it != arg.rules.end(); ++it) {
		os << "\n  " << *it <<";";
	}
	return os << (arg.rules.empty() ? "" : "\n") <<"}";
}

inline
std::ostream& operator <<(std::ostream& os, const plingua::File& arg) {
	return os << "// "<< arg.header <<" "<<arg.version << "\n" << arg.psystem;
}

