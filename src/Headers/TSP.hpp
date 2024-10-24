/***************************************************************
  Student Name: Trevor Mee
  File Name: GeneticAlgorithm.hpp
  Project 3

  @brief Contains function declaration for solving the Traveling Sales 
         Person by comparing the brute force & genetic algorithm 
         solutions
***************************************************************/

#ifndef TSP_HPP
#define TSP_HPP

#include "AdjacencyMatrix.hpp"
#include "BruteForce.hpp"
#include "GeneticAlgorithm.hpp"
#include <time.h>
#include <iostream>

class TSP 
{
    private:

    public:
        // Runs Comparison Between Brute Force & Genetic Algorithm
        void RunComparison();
};
#endif