//
// Created by alculquicondor on 9/6/16.
//

#include "BinChromosome.h"


void BinChromosome::replaceGenes(const BinChromosome &other, std::size_t from, std::size_t to) {
    for (std::size_t i = from; i < to; ++i) {
        operator[](i) = other[i];
    }
}
