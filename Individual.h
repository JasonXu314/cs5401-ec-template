#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include "representation.h"

struct Individual {
	GENOME genome;
	FITNESS fitness;
};

bool operator>(const Individual& a, const Individual& b);

#endif