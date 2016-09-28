//
// Created by alculquicondor on 9/6/16.
//

#ifndef GENETIC_ALGORITHM_BINCHROMOSOME_H
#define GENETIC_ALGORITHM_BINCHROMOSOME_H

#include <vector>


class BinChromosome : protected std::vector<bool> {
public:
    explicit BinChromosome() : std::vector<bool>() {}
    explicit BinChromosome(std::size_t size) : std::vector<bool>(size) {}

    void swapGene(std::size_t pos) {
        operator[](pos) = not operator[](pos);
    }

    void replaceGenes(const BinChromosome &other, std::size_t from, std::size_t to);

    void setGene(std::size_t pos, bool value) {
        operator[](pos) = value;
    }

    bool getGene(std::size_t pos) const {
        return operator[](pos);
    }

    using std::vector<bool>::size;

    friend class BinGenotype;
};


#endif //GENETIC_ALGORITHM_BINCHROMOSOME_H
