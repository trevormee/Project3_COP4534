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

    std::srand(std::time(0));
    InitializePopulation();
}

/*
    @brief Generates permutations 
    @param s: vector to permute through
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
}

/*
    @brief Generates permutations
    @param s: vector to permutate through

    @return Permutated vector
*/
std::vector<int> GeneticAlgorithm::Permutate(std::vector<int>& s)
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

    return s;
}


/*
    @brief Initializes first population (generation) to be used
           in various genetic operatoins
*/
void GeneticAlgorithm::InitializePopulation()
{
    std::vector<int> tour;

    // Start at city 0
    tour.push_back(0);

    for(int i = 1; i < numCities; ++i)
    {
        tour.push_back(i);
    }

    // End at city 0
    tour.push_back(0);

    population.push_back(tour);

    for(int i = 1; i < numToursToRun; ++i)
    {
        perm1(tour);
        population.push_back(tour);
    }
}

/*
    @brief Evaluates the distance (cost) of a tour
    @param(s) tour: current permutation to evaulate cost of              

    @return total distance (cost) of a tour
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
    @brief Parses through a population/generation and returns 
           the tour with the lowest total distance (cost)

    @return Tour with cheapest overall distance (cost) in a 
            population/generation
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
    @brief Performs a mutation on a given tour
    @param(s) tour: current tour to perform a a mutation on

    @return New, mutated tour
*/
std::vector<int> GeneticAlgorithm::Mutate(const std::vector<int>& tour)
{
    std::vector<int> mutatedTour = tour;

    for(size_t i = 1; i < mutatedTour.size() - 1; ++i)
    {
        int x = 1 + std::rand() % (mutatedTour.size() - 2);
        int y = 1 + std::rand() % (mutatedTour.size() - 2);
        std::swap(mutatedTour[x], mutatedTour[y]);
    }

    return mutatedTour;
}

/*
    @brief Runs genetic algorithm operations on the dataset
*/
void GeneticAlgorithm::RunGeneticAlgorithm()
{
    std::vector<int> optimalTour;
    double cheapestTourDistance = std::numeric_limits<double>::max();

    for(int generation = 0; generation < numGenerationsToRun; ++generation)
    {
        std::vector<int> eliteTour = optimalTour;
        eliteTour = GetEliteTour();
        int numToursToMutate = numToursToRun * mutationRate;
        std::vector<std::vector<int>> newGenerationPopulation;

        // Add Elite Tour from previous generation to new population
        newGenerationPopulation.push_back(eliteTour);

        // Mutate numToursToMutate times
        for(int i = 0; i < numToursToMutate; ++i)
        {
            std::vector<int> mutatedTour = Mutate(eliteTour);
            newGenerationPopulation.push_back(mutatedTour);
        }

        // Find remaining tours to permutate of current generation 
        int remainingToursToPermutate = (numToursToRun - numToursToMutate) - 1;

        for(int j = 0; j < remainingToursToPermutate; ++j)
        {
            std::vector<int> permutatedTour = Permutate(eliteTour);
            newGenerationPopulation.push_back(permutatedTour);
        }

        population = newGenerationPopulation;

        for (const auto& tour : newGenerationPopulation)
        {
            eliteTour = GetEliteTour();
            optimalTour = eliteTour;
            // Evaluate Fitness for each tour in a generation
            double fitness = EvaluateFitness(tour);
            if(fitness < cheapestTourDistance)
            {
                cheapestTourDistance = fitness;
            }
        }
    }

    // Print Genetic Algorithm Results
    std::cout << "Genetic Algorithm Most Optimal Tour: ";
    for (int city : optimalTour)
    {
        std::cout << city << " ";
    }
    std::cout << "| Distance (cost): " << cheapestTourDistance; // << std::endl;
}
