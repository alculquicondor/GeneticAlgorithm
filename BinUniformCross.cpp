//
// Created by alculquicondor on 9/27/16.
//

#include "BinUniformCross.h"

BinUniformCross::Chromosome BinUniformCross::operator()(const Chromosome &c1, const Chromosome &c2) {
    Chromosome desc(c1.size());
    for (std::size_t i = 0; i < c1.size(); ++i)
        desc.setGene(i, RandomMachine::roulette() < 0.5 ? c1.getGene(i) : c2.getGene(i));
    return desc;
}
