/***************************************************************
  Student Name: Trevor Mee
  File Name: GeneticAlgorithm.hpp
  Project 3

  @brief Contains function definitions for solving the Traveling
         Salesman Problem using genetic operations
***************************************************************/

#include "Headers/GeneticAlgorithm.hpp"

/*
    @brief Parametrized constructor to set private instance 
           variables and initialze the initial population
    @param(s) matrix: adjacency matrix from AdjacencyMatrix class
              _numCities: number of cities in a given tour
              _numToursToRun: number of tours to run
              _mutationRate: % of generations that should be comprised of mutations
*/
GeneticAlgorithm::GeneticAlgorithm(const AdjacencyMatrix& matrix, int _numCities, int _numToursToRun, double _mutationRate)
      : am(matrix)
{
    numCities = _numCities;
    numToursToRun = _numToursToRun;
    mutationRate = _mutationRate;

    std::srand(std::time(0));
    InitializePopulation();
}

/*
    @brief
    @param(s)

    @return
*/
void GeneticAlgorithm::InitializePopulation()
{
    for(int i = 0; i < numToursToRun; ++i)
    {
        std::vector<int> tours;

        // Start at city 0
        tours.push_back(0);

        for(int j = 1; j < numCities; ++j)
        {
            tours.push_back(j);
        }

        // End at city 0 
        tours.push_back(0);

        std::random_shuffle(tours.begin() + 1, tours.end() - 1);

        population.push_back(tours);
    }

    std::cout << "Population: \n";
    for (const auto& tour : population)
    {
        for (int city : tour)
        {
            std::cout << city << " ";
        }
        std::cout << std::endl;
    }
}

/*
    @brief
    @param(s)

    @return
*/
double GeneticAlgorithm::EvaluateFitness(const std::vector<int>& tour)
{
    return 0.0;
}

/*
    @brief
    @param(s)

    @return
*/
std::vector<int> GeneticAlgorithm::GetEliteTour()
{
    return {};
}

/*
    @brief
    @param(s)

    @return
*/
std::vector<int> GeneticAlgorithm::Mutate(const std::vector<int>& tour)
{
    return {};
}

/*
    @brief
    @param(s)

    @return
*/
std::vector<int> GeneticAlgorithm::RunGeneticAlgorithm()
{
    return {};
}