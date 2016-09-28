//
// Created by alculquicondor on 9/27/16.
//

#ifndef GENETIC_ALGORITHM_BINTWOPOINTCROSS_H
#define GENETIC_ALGORITHM_BINTWOPOINTCROSS_H

#include "Cross.h"
#include "BinGenotype.h"
#include "RandomMachine.h"


class BinTwoPointCross : public Cross<BinGenotype> {
public:
    virtual Chromosome operator()(const Chromosome &c1, const Chromosome &c2) override;
};


#endif //GENETIC_ALGORITHM_BINTWOPOINTCROSS_H
