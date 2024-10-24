#include "Headers/AdjacencyMatrix.hpp"
#include "Headers/BruteForce.hpp"
#include "Headers/GeneticAlgorithm.hpp"

#include <iostream>
#include <vector>

int main()
{
    AdjacencyMatrix am;
    am.ReadFileAndPopulate();
   // am.PrintMatrix();

    int numCities = 7;
    int numToursToRun  = 10;
    int numGenerationsToRun = 1;
    double mutationRate = 0.25;

    GeneticAlgorithm ga(am, numCities, numToursToRun, numGenerationsToRun, mutationRate);
    
    ga.RunGeneticAlgorithm();

    //!!! Brute Force Testing
    //BruteForce bf(am, numCities);
    //bf.RunBruteForce(); 

    return 0;
}