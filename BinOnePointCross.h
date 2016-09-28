//
// Created by alculquicondor on 9/27/16.
//

#ifndef GENETIC_ALGORITHM_BINONEPOINTCROSS_H
#define GENETIC_ALGORITHM_BINONEPOINTCROSS_H

#include "BinGenotype.h"
#include "Cross.h"
#include "RandomMachine.h"


class BinOnePointCross : public Cross<BinGenotype> {
public:
    virtual Chromosome operator()(const Chromosome &c1,
                                               const Chromosome &c2) override;
};


#endif //GENETIC_ALGORITHM_BINONEPOINTCROSS_H
