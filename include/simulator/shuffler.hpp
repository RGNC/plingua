#ifndef _SHUFFLER_HPP_
#define _SHUFFLER_HPP_


#include <vector>
#include <serialization.hpp>
#include <random.hpp>

namespace plingua { namespace simulator {

template<class T>
class Shuffler
{
public:	
	Shuffler(std::vector<T>& data, bool randomized);
	
	const T& operator[](unsigned index) const;
	T& operator[](unsigned index);
	unsigned size() const {return randomized ? indexes.size() : data.size();}
	
	unsigned operator()(unsigned index) const;
	
private:	
	bool randomized;
	std::vector<T>& data;
	std::vector<unsigned> indexes;
};

template<class T>
Shuffler<T>::Shuffler(std::vector<T>& data, bool randomized)
: randomized(randomized),
  data(data)
{
	if (!randomized) {
		return;
	}

	for (unsigned i =0; i< data.size(); i++) {
		indexes.push_back(i);
	}
	
	unsigned index, aux;
	for (unsigned i=0;i<indexes.size()-1; i++) {
		index = RANDOM(indexes.size() - i);
		aux = indexes[index];
		indexes[index] = indexes[indexes.size() - i - 1];
		indexes[indexes.size() - i - 1] = aux;
	}
}


template<>
Shuffler<Rule>::Shuffler(std::vector<Rule>& data, bool randomized)
: randomized(randomized),
  data(data)
{
	if (!randomized) {
		return;
	}

	for (unsigned i =0; i< data.size(); i++) {
		indexes.push_back(i);
	}
	
	unsigned index, aux;
	std::vector<unsigned> priority_indexes;
	
	for (unsigned i=0;i<indexes.size(); i++) {
		index = RANDOM(indexes.size() - i);
		aux = indexes[index];
		indexes[index] = indexes[indexes.size() - i - 1];
		indexes[indexes.size() - i - 1] = aux;
		if (data[aux].features.count("priority")>0) {
			priority_indexes.push_back(indexes.size() - i - 1);
		}
	}
	
	for (unsigned i = 1 ; i< priority_indexes.size(); i++) {
		for (unsigned j=0; j< priority_indexes.size()-i; j++) {
			if (data[indexes[priority_indexes[j]]].features.at("priority").cast_long() <
			     data[indexes[priority_indexes[j+1]]].features.at("priority").cast_long()) {
				unsigned aux = indexes[priority_indexes[j+1]];
				indexes[priority_indexes[j+1]] = indexes[priority_indexes[j]];
				indexes[priority_indexes[j]] = aux;
			}
		}
	}
}

template<class T>
unsigned Shuffler<T>::operator()(unsigned index) const
{
	return randomized ? indexes[index] : index;
}

template<class T>
const T& Shuffler<T>::operator[](unsigned index) const
{
	return randomized ? data[indexes[index]] : data[index];
}


template<class T>
T& Shuffler<T>::operator[](unsigned index)
{
	return randomized ? data[indexes[index]] : data[index];
}


}}


#endif
