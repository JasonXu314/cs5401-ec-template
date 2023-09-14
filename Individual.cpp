#include "Individual.h"

bool operator>(const Individual& a, const Individual& b) { return a.fitness > b.fitness; }