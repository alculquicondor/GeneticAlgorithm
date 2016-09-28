//
// Created by alculquicondor on 9/27/16.
//

#include "BinTwoPointCross.h"

BinTwoPointCross::Chromosome BinTwoPointCross::operator()(const Chromosome &c1, const Chromosome &c2) {
    std::size_t from = RandomMachine::number(1, c1.size() - 2), to = RandomMachine::number(from + 1, c1.size() - 1);
    Chromosome desc = c1;
    desc.replaceGenes(c2, from, to);
    return desc;
}
