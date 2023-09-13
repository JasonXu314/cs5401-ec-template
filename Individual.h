#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include "params-default.h"

struct Individual {
	GENOME_REP genome;
	FITNESS_REP fitness;
};

bool operator>(const Individual& a, const Individual& b) { return a.fitness > b.fitness; }

#endif