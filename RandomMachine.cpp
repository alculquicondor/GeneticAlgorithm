//
// Created by alculquicondor on 9/27/16.
//

#include "RandomMachine.h"

std::default_random_engine RandomMachine::randomEngine{std::random_device{}()};
std::uniform_real_distribution<double> RandomMachine::rouletteDistribution{0, 1};


double RandomMachine::roulette() {
    return rouletteDistribution(randomEngine);
}


std::size_t RandomMachine::number(std::size_t from, std::size_t to) {
    return std::uniform_int_distribution<std::size_t>(from, to)(randomEngine);
}
