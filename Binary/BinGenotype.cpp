//
// Created by alculquicondor on 9/6/16.
//

#include "BinGenotype.h"

BinGenotype::BinGenotype(const std::vector<VariableDescription> &variables) :
        variables(variables), variableLength(variables.size()),
        randomEngine(std::random_device{}()), coin(0, 1) {
    totalLength = 0;
    for (std::size_t i = 0; i < variables.size(); ++i) {
        const VariableDescription &v = variables[i];
        variableLength[i] =
                std::size_t(std::ceil(std::log2(v.getMaxValue() - v.getMinValue()) - std::log2(v.getPrecision())));
        totalLength += variableLength[i];
    }
}

BinGenotype::Chromosome BinGenotype::generateChromosome() {
    Chromosome chromosome(totalLength);
    for (auto it = chromosome.begin(); it != chromosome.end(); ++it) {
        *it = coin(randomEngine);
    }
    return chromosome;
}

std::vector<double> BinGenotype::getFenotype(Chromosome chromosome) const {
    std::vector<double> fenotype(variables.size());
    std::size_t j = 0;
    for (std::size_t i = 0; i < variables.size(); ++i) {
        const auto &var = variables[i];
        double pow2 = 1, tmp = 0;
        bool acc = false;
        for (std::size_t k = 0; k < variableLength[i] - 1; ++k) {
            acc ^= chromosome[j + k];
            tmp += acc * pow2;
            pow2 *= 2;
        }
        acc ^= chromosome[j + variableLength[i] - 1];
        tmp += acc * pow2;
        pow2 *= 2;
        fenotype[i]  = var.getMinValue() + tmp * (var.getMaxValue() - var.getMinValue()) / (pow2 - 1);
        j += variableLength[i];
    }
    return fenotype;
}
