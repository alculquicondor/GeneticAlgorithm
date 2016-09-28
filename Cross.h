//
// Created by alculquicondor on 9/27/16.
//

#ifndef GENETIC_ALGORITHM_BINCROSS_H
#define GENETIC_ALGORITHM_BINCROSS_H

template <typename G>
class Cross {
public:
    using Chromosome = typename G::Chromosome;
    virtual Chromosome operator()(const Chromosome &c1, const Chromosome &c2) = 0;
};


#endif //GENETIC_ALGORITHM_BINCROSS_H
