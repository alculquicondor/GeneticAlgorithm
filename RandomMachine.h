//
// Created by alculquicondor on 9/27/16.
//

#ifndef GENETIC_ALGORITHM_RANDOMMACHINE_H
#define GENETIC_ALGORITHM_RANDOMMACHINE_H

#include <random>

class RandomMachine {
private:
    static std::default_random_engine randomEngine;
    static std::uniform_real_distribution<double> rouletteDistribution;
public:
    static double roulette();
    static std::size_t number(std::size_t from, std::size_t to);
};


#endif //GENETIC_ALGORITHM_RANDOMMACHINE_H
