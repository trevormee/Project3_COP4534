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
GeneticAlgorithm::GeneticAlgorithm(const AdjacencyMatrix& matrix, int _numCities, int _numToursToRun, int _numGenerationsToRun, double _mutationRate)
      : am(matrix)
{
    numCities = _numCities;
    numToursToRun = _numToursToRun;
    numGenerationsToRun = _numGenerationsToRun;
    mutationRate = _mutationRate;

    //std::srand(std::time(0));
    InitializePopulation();
}

/*
    @brief
    @param 
*/
void GeneticAlgorithm::perm1(std::vector<int>& s)
{
    int m, k, p, q;

    m = numCities - 2;

    while(s[m] > s[m + 1])
    {
        m = m - 1;
    }

    k = numCities - 1;
    while(s[m] > s[k])
    {
        k = k - 1;
    }

    std::swap(s[m],s[k]);

    p = m + 1;
    q = numCities - 1;
    while (p < q)
    {
        std::swap(s[p], s[q]);
        p++;
        q--;
    }

    // Remove output for final submission (using for testing)
    for(int i : s)
    {   
        std::cout << i << " ";
    }
    std::cout << "0" << std::endl;
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

        // CHANGE TO USE PERM1
        std::random_shuffle(tours.begin() + 1, tours.end() - 1);

        population.push_back(tours);
    }

    std::cout << "Population and Fitness: \n";
    for (const auto& tour : population)
    {
        // Print the tour
        for (int city : tour)
        {
            std::cout << city << " ";
        }

        // Evaluate the fitness of the current tour
        double fitness = EvaluateFitness(tour);

        // Print the fitness value
        std::cout << " | Fitness: " << fitness << std::endl;
    }

}

/*
    @brief
    @param(s)

    @return
*/
double GeneticAlgorithm::EvaluateFitness(const std::vector<int>& tour)
{
    double totalTourDistance = 0.0;

    for(size_t i = 0; i < tour.size() - 1; ++i)
    {
        int x = tour[i];
        int y = tour[i + 1];
        totalTourDistance += am.matrix[x][y];
    }

    // Add distance back to city 0
    totalTourDistance += am.matrix[tour.back()][0];

    return totalTourDistance;
}

/*
    @brief
    @param(s)

    @return
*/
std::vector<int> GeneticAlgorithm::GetEliteTour()
{
    std::vector<int> eliteTour = population[0];
    double cheapestTourDistance = EvaluateFitness(eliteTour);

    for(const auto& tour : population)
    {
        double currTourDistance = EvaluateFitness(tour);
        if(currTourDistance < cheapestTourDistance)
        {
            cheapestTourDistance = currTourDistance;
            eliteTour = tour;
        }
    }

    return eliteTour;
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
void GeneticAlgorithm::RunGeneticAlgorithm()
{
    //return {};
}