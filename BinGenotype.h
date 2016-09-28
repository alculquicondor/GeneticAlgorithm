//
// Created by alculquicondor on 9/6/16.
//

#ifndef GENETIC_ALGORITHM_BINGENOTYPE_H
#define GENETIC_ALGORITHM_BINGENOTYPE_H

#include <cmath>
#include <random>

#include "BinChromosome.h"
#include "VariableDescription.h"


class BinGenotype {
private:
    std::vector<VariableDescription> variables;
    std::vector<std::size_t> variableLength;
    std::size_t totalLength;

    std::default_random_engine randomEngine;
    std::uniform_int_distribution<int> coin;

public:
    using Chromosome = BinChromosome;

    BinGenotype(const std::vector<VariableDescription> &variables);

    Chromosome generateChromosome();

    std::vector<double> getFenotype(Chromosome chromosome) const;
};


#endif //GENETIC_ALGORITHM_BINGENOTYPE_H
