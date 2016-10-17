cmake_minimum_required(VERSION 3.6)
project(genetic_algorithm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(COMMON_FILES
        GeneticAlgorithm.h Cross.h
        RandomMachine.cpp RandomMachine.h
        Mutation.h)

set(CANON_FILES canonical.cpp
        VariableDescription.cpp VariableDescription.h
        Binary/BinGenotype.cpp Binary/BinGenotype.h
        Binary/BinChromosome.cpp Binary/BinChromosome.h
        Binary/BinOnePointCross.cpp Binary/BinOnePointCross.h
        Binary/OneBitMutation.cpp Binary/OneBitMutation.h
        Binary/BinTwoPointCross.cpp Binary/BinTwoPointCross.h
        Binary/BinUniformCross.cpp Binary/BinUniformCross.h)

add_executable(canonical_ga ${CANON_FILES} ${COMMON_FILES})
