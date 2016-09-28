//
// Created by alculquicondor on 9/6/16.
//

#ifndef GENETIC_ALGORITHM_GENETICALGORITHM_H
#define GENETIC_ALGORITHM_GENETICALGORITHM_H

#include <algorithm>
#include <functional>
#include <memory>

#include "VariableDescription.h"
#include "RandomMachine.h"
#include "Cross.h"
#include "Mutation.h"

using OptimizingFunction = std::function<double(const std::vector<double> &)>;

template <typename G>
class GeneticAlgorithm {
private:
    using Genotype = G;
    using Chromosome = typename G::Chromosome;

    double crossProbability, mutationProbability;
    double vMin, vMax;
    bool elitism;
    std::size_t populationSize, iterations;
    std::unique_ptr<Genotype> genotype;
    OptimizingFunction optimizingFunction;
    std::vector<Chromosome> population;
    std::vector<double> fitness;
    std::unique_ptr<Cross<G>> cross;
    std::unique_ptr<Mutation<G>> mutation;
    std::vector<double> means, bests;

    double getFitness();
    Chromosome getBestIndividual() const;
    std::vector<Chromosome> getSelection() const;

public:
    GeneticAlgorithm(size_t populationSize, size_t iterations, Cross<G> *cross, Mutation<G> *mutation,
                     double crossProbability, double mutationProbability, bool elitism = true,
                     double vMin = 0, double vMax = 0) :
            populationSize(populationSize), iterations(iterations), cross(cross), mutation(mutation),
            crossProbability(crossProbability), mutationProbability(mutationProbability), elitism(elitism),
            vMin(vMin), vMax(vMax) { }

    std::vector<double> run(OptimizingFunction optimizingFunction, std::vector<VariableDescription> variables);

    std::vector<double> getMeans() {
        return means;
    }

    std::vector<double> getBests() {
        return bests;
    }

};


template <typename G>
std::vector<double> GeneticAlgorithm<G>::run(OptimizingFunction optimizingFunction,
                                          std::vector<VariableDescription> variables) {
    means.clear();
    bests.clear();
    GeneticAlgorithm::optimizingFunction = optimizingFunction;
    genotype = std::unique_ptr<G>{new Genotype(variables)};

    population = std::vector<Chromosome>(populationSize);
    for (Chromosome &chromosome : population)
        chromosome = genotype->generateChromosome();

    for (std::size_t i = 0; i < iterations; ++i) {
        means.push_back(getFitness());
        Chromosome best = getBestIndividual();
        bests.push_back(optimizingFunction(genotype->getFenotype(best)));

        auto selection = getSelection();
        if (elitism)
            population = {best};
        else
            population = {};
        for (const auto &chromosome : selection) {
            double probability = RandomMachine::roulette();
            if (probability <= crossProbability) {
                std::size_t other = RandomMachine::number(0, selection.size() - 1);
                population.push_back((*cross)(chromosome, selection[other]));
            } else if (probability <= crossProbability + mutationProbability) {
                population.push_back((*mutation)(chromosome));
            } else {
                population.push_back(chromosome);
            }
        }
    }
    means.push_back(getFitness());
    Chromosome best = getBestIndividual();
    auto bestFenotype = genotype->getFenotype(best);
    bests.push_back(optimizingFunction(bestFenotype));

    return bestFenotype;
}


template <typename G>
double GeneticAlgorithm<G>::getFitness() {
    double mean = 0;
    fitness = std::vector<double>(populationSize);
    for (std::size_t i = 0; i < populationSize; ++i) {
        fitness[i] = optimizingFunction(genotype->getFenotype(population[i]));
        mean += fitness[i];
    }
    if (vMax != 0) {
        std::vector<std::size_t> order(populationSize);
        for (std::size_t i = 0; i < populationSize; ++i)
            order[i] = i;
        std::sort(order.begin(), order.end(), [this](std::size_t i, std::size_t j) {
            return fitness[i] < fitness[j];
        });
        for (std::size_t i = 0; i < populationSize; ++i) {
            fitness[order[i]] = vMin + (vMax - vMin) * i / (populationSize - 1);
        }
    }
    return mean / populationSize;
}


template <typename G>
typename G::Chromosome GeneticAlgorithm<G>::getBestIndividual() const {
    std::size_t maxId = 1;
    for (std::size_t i = 1; i < populationSize; ++i)
        if (fitness[i] > fitness[maxId])
            maxId = i;
    return population[maxId];
}


template <typename G>
std::vector<typename G::Chromosome> GeneticAlgorithm<G>::getSelection() const {
    std::vector<double> share = fitness;
    for (std::size_t i = 1; i < population.size(); ++i)
        share[i] += share[i - 1];
    for (double &s : share)
        s /= share.back();

    std::vector<Chromosome> selection(populationSize - elitism);
    for (auto &s : selection) {
        auto id = std::lower_bound(share.begin(), share.end(), RandomMachine::roulette()) - share.begin();
        s = population[id];
    }

    return selection;
}

#endif //GENETIC_ALGORITHM_GENETICALGORITHM_H
