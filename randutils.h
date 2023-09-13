#ifndef RANDUTILS_H
#define RANDUTILS_H

#include <random>

class RNG {
public:
	RNG() {}

	double operator()() { return _rand(_engine); }

private:
	std::uniform_real_distribution<double> _rand;
	std::mt19937_64 _engine;
};

extern RNG rng;

#endif