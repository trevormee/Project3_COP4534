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
    /*
    for(int i : s)
    {   
        std::cout << i << " ";
    }
    std::cout << "0" << std::endl;
    */
}

/*
    PERM1 but returns a vector
*/
std::vector<int> GeneticAlgorithm::Permutate(std::vector<int>& s)
{
    //std::vector<int> permutatedTour = s;

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

    // Remove output for final submission (using for testing)
    /*
    for(int i : s)
    {   
        std::cout << i << " ";
    }
    std::cout << "0" << std::endl;
    */
}


/*
    @brief
    @param(s)

    @return
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

    // Used for testing only!
    std::cout << "Initial Population..." << std::endl;
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
    @brief
    @param(s)

    @return
*/
void GeneticAlgorithm::RunGeneticAlgorithm()
{
    for(int generation = 0; generation < numGenerationsToRun; ++generation)
    {
        std::vector<int> eliteTour = GetEliteTour();
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
        // Math: (# tours in each gen - # tours already mutated) - eliteTour @ top [-1] 
        int remainingToursToPermutate = (numToursToRun - numToursToMutate) - 1;
        for(int j = 0; j < remainingToursToPermutate; ++j)
        {
            std::vector<int> permutatedTour = Permutate(eliteTour);
            //perm1(eliteTour);
            newGenerationPopulation.push_back(permutatedTour);
        }

        std::cout << "Generation " << generation << "\n";
        for (const auto& tour : newGenerationPopulation)
        {
            // Print the tour
            for (int city : tour)
            {
                std::cout << city << " ";
            }
            // Evaluate the fitness of the current mutated tour
            double fitness = EvaluateFitness(tour);

            // Print the fitness value
            std::cout << " | Fitness: " << fitness << std::endl;
        }
    }
    /*
    std::vector<int> eliteTour = GetEliteTour();
    double cheapestTourDistance = EvaluateFitness(eliteTour);

    for(int i = 0; i < numGenerationsToRun; ++i)
    {
        std::vector<std::vector<int>> newGenerationPopulation;
        newGenerationPopulation.push_back(eliteTour);

        int numToursToMutate = numToursToRun * mutationRate;
        for(int j = 0; j < numToursToMutate; ++j)
        {
            std::vector<int> mutatedTour = Mutate(eliteTour);
            newGenerationPopulation.push_back(mutatedTour);
        }
    }
        
        for(int k = numToursToMutate + 1; k < numToursToRun; ++k)
        {
            std::vector<int> tourToPermutateFrom = eliteTour;
            perm1(tourToPermutateFrom);
            newGenerationPopulation.push_back(tourToPermutateFrom);
        }

        population = newGenerationPopulation;

        eliteTour = GetEliteTour();
        double mostEliteTourOfGeneration = EvaluateFitness(eliteTour);

        if(mostEliteTourOfGeneration < cheapestTourDistance)
        {
            cheapestTourDistance = mostEliteTourOfGeneration;
        }       

        std::cout << "Generation " << i + 1 << " Best Tour: ";
        for (int city : eliteTour)
        {
            std::cout << city << " ";
        }
        std::cout << "| Fitness: " << mostEliteTourOfGeneration << std::endl;
    }

    std::cout << "Overall Best Tour: ";
    for (int city : eliteTour)
    {
        std::cout << city << " ";
    }
    std::cout << "| Fitness: " << cheapestTourDistance << std::endl;
    */
}
