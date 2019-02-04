
#ifndef _RANDOM_HPP_
#define _RANDOM_HPP_
#include <random>
#include <chrono>

/**
 * class RandomNumberGenerator
 *
 * A Random Number Generator based on std::mt19937 
 * impemented by using the singleton pattern 
 *
 * @author Ignacio Perez
 */

class RandomNumberGenerator
{
public:
	RandomNumberGenerator(RandomNumberGenerator const&) = delete;
        void operator=(RandomNumberGenerator const&)  = delete;
	~RandomNumberGenerator() {}
        /**
   	 * Get the singleton instance of RandomNumberGenerator
	 * Note: You can use the macro RANDOM instead of RandomNumberGenerator::getInstance()
   	 * @return the singleton instance
   	 */
	static RandomNumberGenerator& getInstance()
   	{
      		static RandomNumberGenerator singleton;
      		return singleton;
	}
	#define RANDOM RandomNumberGenerator::getInstance()
	/**
   	 * Get the seed of the random number generator
	 * Note: An initial seed based on std::chrono will be used
	 * @return the seed
   	 */
	unsigned getSeed() const {return seed;}
	/**
   	 * Set the seed of the random number generator
	 * @param seed: the new seed
   	 */
	void setSeed(unsigned seed) {this->seed = seed; gen.seed(seed);}
	/**
   	 * Get a random discrete number 0 <= x < size following an uniform distribution
	 * @param size: the upper bound for the number (excluded)
	 * @return: A random discrete number
   	 */
	unsigned operator()(unsigned size);
	/**
   	 * Get a random real number 0 <= x < 1.0 following an uniform distribution
	 * @return: A random real number
   	 */
	double operator()() {return uniformDist(gen);}
	/**
   	 * Get a random real number following a normal distribution
	 * @param mean: mean of the normal distribution
	 * @param stddev: standard deviation of the normal distribution
	 * @return: A random real number
   	 */
	double operator()(double mean, double stddev);
private:
	RandomNumberGenerator(): seed(std::chrono::system_clock::now().time_since_epoch().count()), gen(seed), uniformDist(0.0,1.0) {} 
	unsigned seed;
	std::mt19937 gen;
	std::uniform_real_distribution<double> uniformDist;
};

inline
unsigned RandomNumberGenerator::operator()(unsigned size)
{
	std::uniform_int_distribution<unsigned> distribution(0,size-1);
	return distribution(gen);
}

inline
double RandomNumberGenerator::operator()(double mean, double stddev)
{
	std::normal_distribution<double> distribution(mean,stddev);
	return distribution(gen);
}


#endif
