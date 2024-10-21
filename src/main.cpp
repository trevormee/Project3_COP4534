#include "Headers/AdjacencyMatrix.hpp"
#include "Headers/BruteForce.hpp"
#include "Headers/GeneticAlgorithm.hpp"

#include <iostream>

int main()
{
    AdjacencyMatrix am;
    am.ReadFileAndPopulate();
    am.PrintMatrix();

    int numCities = 7;
    int numToursToRun  = 10;
    double mutationRate = 0.25;

   GeneticAlgorithm ga(am, numCities, numToursToRun, mutationRate);
    
    //!!! Brute Force Testing
    //BruteForce bf(am, numCities);
    //bf.RunBruteForce(); 

    return 0;
}