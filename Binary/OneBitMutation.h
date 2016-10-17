//
// Created by alculquicondor on 9/27/16.
//

#ifndef GENETIC_ALGORITHM_ONEBITMUTATION_H
#define GENETIC_ALGORITHM_ONEBITMUTATION_H

#include "../Mutation.h"
#include "BinGenotype.h"
#include "../RandomMachine.h"


class OneBitMutation : public Mutation<BinGenotype> {
public:
    virtual Chromosome operator()(const Chromosome &chromosome) override;
};


#endif //GENETIC_ALGORITHM_ONEBITMUTATION_H
