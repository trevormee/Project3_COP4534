/***************************************************************
  Student Name: Trevor Mee
  File Name: GeneticAlgorithm.hpp
  Project 3

  @brief Contains function definition for solving the Traveling Sales 
         Person by comparing the brute force & genetic algorithm 
         solutions
***************************************************************/

#include "Headers/TSP.hpp"

void TSP::RunComparison()
{
    /*
    int numCities, numToursToRun, numGenerationsToRun;
    double mutationRate;

    std::cout << "How many cities to run?" << std::endl;
    std::cin >> numCities;
    std::cout << "How many indicidual tours are there in a given generation?" << std::endl;
    std::cin >> numToursToRun;
    std::cout << "How many generations to run?" << std::endl;
    std::cin >> numGenerationsToRun;
    std::cout << "What percentage of a generation should be comprised of mutations? Write in Decimal Format (i.e. If you want a mutation rate of 25%, input 0.25)" << std::endl;
    std::cin >> mutationRate;
    */

    int numCities = 12;
    int numToursToRun  = 50;
    int numGenerationsToRun = 50;
    double mutationRate = 0.50;

    AdjacencyMatrix am;
    am.ReadFileAndPopulate();

    BruteForce bf(am, numCities);

    timespec BFstart, BFstop, GAstart, GAStop;

    // Track Run-time of Brute Force Algorithm
    clock_gettime(CLOCK_REALTIME, &BFstart);

    bf.RunBruteForce();

    clock_gettime(CLOCK_REALTIME, &BFstop);

    // Get run time seconds and nano seconds
    double BFseconds = BFstop.tv_sec - BFstart.tv_sec;
    double BFnanoSeconds = BFstop.tv_nsec - BFstart.tv_nsec;
    double BFtotalTime = BFseconds + BFnanoSeconds / 1e9;

    std::cout << " | Run-time for Brute Force: " << BFtotalTime << std::endl; 

    GeneticAlgorithm ga(am, numCities, numToursToRun, numGenerationsToRun, mutationRate);

    // Track Run-time of Genetic Algorithm
    clock_gettime(CLOCK_REALTIME, &GAstart);

    ga.RunGeneticAlgorithm();

    clock_gettime(CLOCK_REALTIME, &GAStop);

    double GAseconds = GAStop.tv_sec - GAstart.tv_sec;
    double GAnanoSeconds = GAStop.tv_nsec - GAstart.tv_nsec;
    double GAtotalTime = GAseconds + GAnanoSeconds / 1e9;

    std::cout << " | Run-time for Genetic Algorithm: " << GAtotalTime << std::endl;

}