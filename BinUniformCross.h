//
// Created by alculquicondor on 9/27/16.
//

#ifndef GENETIC_ALGORITHM_BINUNIFORMCROSS_H
#define GENETIC_ALGORITHM_BINUNIFORMCROSS_H

#include "Cross.h"
#include "BinGenotype.h"
#include "RandomMachine.h"


class BinUniformCross : public Cross<BinGenotype> {
public:
    virtual Chromosome operator()(const Chromosome &c1, const Chromosome &c2) override;
};


#endif //GENETIC_ALGORITHM_BINUNIFORMCROSS_H
