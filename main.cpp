#include <iostream>

#include "GeneticAlgorithm.h"
#include "BinOnePointCross.h"
#include "BinTwoPointCross.h"
#include "BinUniformCross.h"
#include "OneBitMutation.h"


int main() {
    OptimizingFunction function = [](const std::vector<double> &x) {
        double squaresSum = x[0] * x[0] + x[1] * x[1];
        return 0.5 - (std::pow(std::sin(std::sqrt(squaresSum)), 2) - 0.5) /
                             std::pow(1. + .001 * squaresSum, 2);
    };

    std::size_t experiments, population, generations, crossOp;
    bool elitism;
    double crossProb, mutProb, vMin, vMax;
    std::cin >> experiments >> population >> generations >> crossOp >> crossProb >> mutProb >> elitism >> vMin >> vMax;

    Cross<BinGenotype> *cross;
    if (crossOp == 0)
        cross = new BinUniformCross;
    else if (crossOp == 1)
        cross = new BinOnePointCross;
    else
        cross = new BinTwoPointCross;

    std::vector<double> bestCurve(generations), offlineCurve(generations), onlineCurve(generations);

    double bestFitness = 0;
    std::vector<double> bestSolution;
    GeneticAlgorithm<BinGenotype> ga(population, generations, cross, new OneBitMutation, crossProb, mutProb, elitism,
                                     vMin, vMax);
    for (std::size_t i = 0; i < experiments; ++i) {
        auto solution = ga.run(function, {{-100, 100, 1e-7},
                                          {-100, 100, 1e-7}});
        double fitness = function(solution);
        if (bestFitness < fitness) {
            bestSolution = solution;
            bestFitness = fitness;
        }

        auto bests = ga.getBests(), means = ga.getMeans();
        double bestsSum = 0, meansSum = 0;
        for (std::size_t g = 0; g <= generations; ++g) {
            bestCurve[g] += bests[g] / experiments;
            bestsSum += bests[g];
            offlineCurve[g] += bestsSum / (g + 1) / experiments;
            meansSum += means[g];
            onlineCurve[g] += meansSum / (g + 1) / experiments;
        }
    }

    for (std::size_t g = 0; g <= generations; ++g)
        std::cout << bestCurve[g] << '\t' << offlineCurve[g] << '\t' << onlineCurve[g] << std::endl;

    std::cerr << "x_0 = " << bestSolution[0] << ' ' << "\tx_1 = " << bestSolution[1] << '\t' << bestFitness << std::endl;
    return 0;
}