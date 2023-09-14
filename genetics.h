#ifndef GENETICS_H
#define GENETICS_H

#include <algorithm>

#include "Individual.h"
#include "randutils.h"
#include "representation.h"
#include "typeutils.h"

// TODO: consider removing individual/pair/population and just making function overloads
Individual randIndividual();

// TODO: consider population class for more semantically nice mem management
Individual* initPopulation(uint size);

Individual* recombinePair(const Individual& parent1, const Individual& parent2);

Individual* recombinePopulation(const Individual* const population, uint size, double recombinationRate);

Individual mutateIndividual(const Individual& individual, double mutationRate);

Individual* mutatePopulation(const Individual* const population, uint size, double mutationRate);

void evaluateIndividual(Individual& individual);

void evaluatePopulation(Individual* const population, uint size);

void rankPopulation(const Individual* population, uint size);

Individual* selectParents(const Individual* const population, uint size);

// Assumes that the current population is larger than the given size (size of next generation)
Individual* selectNextGeneration(const Individual* const population, uint size);

#endif