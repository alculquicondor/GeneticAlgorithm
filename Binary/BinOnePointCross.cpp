//
// Created by alculquicondor on 9/27/16.
//

#include "BinOnePointCross.h"


BinOnePointCross::Chromosome BinOnePointCross::operator()(const Chromosome &c1, const Chromosome &c2) {
    std::size_t p = RandomMachine::number(1, c1.size() - 1);
    Chromosome desc = c1;
    desc.replaceGenes(c2, 0, p);
    return desc;
}
