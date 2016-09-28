//
// Created by alculquicondor on 9/27/16.
//

#ifndef GENETIC_ALGORITHM_MUTATION_H
#define GENETIC_ALGORITHM_MUTATION_H


template <typename G>
class Mutation {
public:
    using Chromosome = typename G::Chromosome;
    virtual Chromosome operator()(const Chromosome &chromosome) = 0;
};


#endif //GENETIC_ALGORITHM_MUTATION_H
