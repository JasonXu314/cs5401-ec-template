#include <iostream>
#include <string>

#include "Individual.h"
#include "genetics.h"

using namespace std;

#define POP_SIZE 50
#define TARGET_FITNESS FITNESS_REP(0)
#define RECOMBINATION_RATE 0.8

int main(int argc, char** argv) {
	if (argc == 3) {
		// TODO: implement CLI
	} else {
		Individual* population = initPopulation(POP_SIZE);
		evaluatePopulation(population, POP_SIZE);
		rankPopulation(population, POP_SIZE);

		FITNESS_REP bestFitness = population[0].fitness;

		uint generation = 0;
		while (bestFitness < TARGET_FITNESS) {
			cout << "Generation " << generation << ":\nIndividual\t\tGenome\t\tFitness" << endl;
			for (uint i = 0; i < POP_SIZE; i++) {
				cout << i << "\t\t\t" << population[i].genome << "\t\t" << population[i].fitness << endl;
			}
			generation++;

			Individual* parents = selectParents(population, POP_SIZE);
			Individual* children = recombinePopulation(parents, POP_SIZE, RECOMBINATION_RATE);

			double mutationRate = (1 - ((double)bestFitness / TARGET_FITNESS)) / 5;
			Individual* mutants = mutatePopulation(children, POP_SIZE, mutationRate);
			evaluatePopulation(mutants, POP_SIZE);

			Individual* everyone = new Individual[POP_SIZE * 2];
			for (uint i = 0; i < POP_SIZE; i++) {
				everyone[i] = parents[i];
				everyone[i + POP_SIZE] = mutants[i];
			}

			rankPopulation(everyone, POP_SIZE * 2);

			Individual* newGeneration = selectNextGeneration(everyone, POP_SIZE);

			delete[] population;
			delete[] parents;
			delete[] children;
			delete[] mutants;
			delete[] everyone;
			population = newGeneration;

			if (bestFitness != population[0].fitness) {
				bestFitness = population[0].fitness;
				cout << "Generation " << generation << ", best individal fitness: " << bestFitness << endl;
			}
		}
	}
}