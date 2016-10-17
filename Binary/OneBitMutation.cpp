//
// Created by alculquicondor on 9/27/16.
//

#include "OneBitMutation.h"

BinChromosome OneBitMutation::operator()(const Chromosome &chromosome) {
    std::size_t pos = RandomMachine::number(0, chromosome.size() - 1);
    Chromosome desc = chromosome;
    desc.swapGene(pos);
    return desc;
}
