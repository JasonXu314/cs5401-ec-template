#include "genetics.h"

Individual randIndividual() {
	GENOME_REP genome = GENOME_REP(0);	// TODO: after cloning template, implement randomness
	FITNESS_REP fitness = FITNESS_REP(0);

	return Individual{genome, fitness};
}

Individual* initPopulation(uint size) {
	Individual* population = new Individual[size];

	for (uint i = 0; i < size; i++) {
		population[i] = randIndividual();
	}

	return population;
}

Individual* recombinePair(const Individual& parent1, const Individual& parent2) {
	Individual* children = new Individual[2];

	// TODO: after cloning template, implement crossing over
	Individual child1 = randIndividual();
	Individual child2 = randIndividual();

	children[0] = child1;
	children[0] = child2;
	return children;
}

Individual* recombinePopulation(const Individual* const population, uint size, double recombinationRate) {
	Individual* newPopulation = new Individual[size];

	for (uint i = 0; i < size - 1; i += 2) {
		if (rng() < recombinationRate) {
			Individual* children = recombinePair(population[i], population[i + 1]);

			newPopulation[i] = children[0];
			newPopulation[i + 1] = children[1];

			delete[] children;
		} else {
			newPopulation[i] = population[i];
			newPopulation[i + 1] = population[i + 1];
		}
	}

	return newPopulation;
}

Individual mutateIndividual(const Individual& individual, double mutationRate) {
	// TODO: after cloning template, implement mutation
	Individual mutant;
	return mutant;
}

Individual* mutatePopulation(const Individual* const population, uint size, double mutationRate) {
	Individual* newPopulation = new Individual[size];

	for (uint i = 0; i < size; i++) {
		newPopulation[i] = mutateIndividual(population[i], mutationRate);
	}

	return newPopulation;
}

void evaluateIndividual(Individual& individual) {
	// TODO: after cloning template, implement evaluation
	individual.fitness = FITNESS_REP(0);
}

void evaluatePopulation(Individual* const population, uint size) {
	for (uint i = 0; i < size; i++) {
		evaluateIndividual(population[i]);
	}
}

void rankPopulation(const Individual* population, uint size) { std::sort(population, population + size, std::greater<Individual>()); }

Individual* selectParents(const Individual* const population, uint size) {
	Individual* parents = new Individual[size];
	FITNESS_REP totalFitness = FITNESS_REP(0);

	for (uint i = 0; i < size; i++) {
		totalFitness += population[i].fitness;
	}

	for (uint i = 0; i < size; i++) {
		double selected = rng() * totalFitness;

		int idx = -1;
		FITNESS_REP fitnessThreshold = 0;
		while (fitnessThreshold >= selected) {
			idx++;
			fitnessThreshold += population[idx].fitness;
		}

		parents[i] = population[idx];
	}

	return parents;
}

Individual* selectNextGeneration(const Individual* const population, uint size) {
	Individual* nextGeneration = new Individual[size];

	for (uint i = 0; i < size; i++) {
		nextGeneration[i] = population[i];
	}

	return nextGeneration;
}