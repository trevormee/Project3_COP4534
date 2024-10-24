//#include "Headers/AdjacencyMatrix.hpp"
//#include "Headers/BruteForce.hpp"
//#include "Headers/GeneticAlgorithm.hpp"
#include "Headers/TSP.hpp"

#include <iostream>
#include <vector>

int main()
{

    TSP tsp;
    tsp.RunComparison();

    /*
    AdjacencyMatrix am;
    am.ReadFileAndPopulate();
   // am.PrintMatrix();

    int numCities = 7;
    int numToursToRun  = 10;
    int numGenerationsToRun = 10;
    double mutationRate = 1.00;

    GeneticAlgorithm ga(am, numCities, numToursToRun, numGenerationsToRun, mutationRate);
    
    ga.RunGeneticAlgorithm();

    //!!! Brute Force Testing
    //BruteForce bf(am, numCities);
    //bf.RunBruteForce(); 
    */

    return 0;
}