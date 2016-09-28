cmake_minimum_required(VERSION 3.6)
project(genetic_algorithm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp
        VariableDescription.cpp VariableDescription.h
        BinGenotype.cpp BinGenotype.h
        BinChromosome.cpp BinChromosome.h
        GeneticAlgorithm.h Cross.h
        BinOnePointCross.cpp BinOnePointCross.h
        RandomMachine.cpp RandomMachine.h Mutation.h OneBitMutation.cpp OneBitMutation.h BinTwoPointCross.cpp BinTwoPointCross.h BinUniformCross.cpp BinUniformCross.h)
add_executable(genetic_algorithm ${SOURCE_FILES})