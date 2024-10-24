/***************************************************************
  Student Name: Trevor Mee
  File Name: BruteForce.cpp
  Project 3

  @brief Contains function defintions for solving the Traveling
         Salesman Problem using a brute force algorithm
***************************************************************/

#include "Headers/BruteForce.hpp"

/*
    @brief Parameterized contructor to load adjacency matrix and set
           number of cities
    @param(s) matrix: Reference to the adjacency matrix from AdjacencyMatrix class
              _numCities: number of cities to run brute force algorithm for
*/
BruteForce::BruteForce(const AdjacencyMatrix& matrix, int _numCities) : am(matrix), numCities(_numCities){}


/*
    @brief Generates permutations
    @param s: current permutation
*/
void BruteForce::perm1(std::vector<int>& s)
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

    /*
    // Remove output for final submission (using for testing)
    for(int i : s)
    {   
        std::cout << i << " ";
    }

    std::cout << "0" << std::endl;
    */
}


/*
    @brief Evaluates and computes the total distance of a tour
    @param tour: current permutation to evaluate total distance for

    @return total tour distance for current tour
*/
double BruteForce::EvaluateTour(const std::vector<int>& tour)
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
    @brief Helper function to determine how many permuttaions we need
           to generate in brute force algorithm
    @param n: number of cities to find (n-1)! value

    @return number of permutations needed for brute force algorithm (n-1)!
*/
int BruteForce::Factorial(int n)
{
    int numPermutations = 1;
    for(int i = 1; i <= n; ++i)
    {
        numPermutations *= i;
    }

    return numPermutations;
}


/*
    @brief Runs the brute force algorithm and outputs the most optimal 
           tour and the total distance of the most optimal tour
*/
void BruteForce::RunBruteForce()
{
    // Init. vector of cities to permutate thru
    std::vector<int> cities(numCities);
    for(int i = 0; i < numCities; ++i)
    {
        cities[i] = i;
    }

    // Init. various components to running brute force algorithm
    cities[0] = 0;
    double cheapestTourDistance = std::numeric_limits<double>::max();
    std::vector<int> optimalTour;
    int numPermutations = Factorial(numCities - 1);
    //std::cout << "num permutations " << numPermutations<< std::endl;

    // Permutate thru (n-1)! cities and find cheapest tour 
    for(int i = 0; i < numPermutations; ++i)
    {
        double currTourDistance = EvaluateTour(cities);

        if(currTourDistance < cheapestTourDistance)
        {
            cheapestTourDistance = currTourDistance;
            optimalTour = cities;
        }

        perm1(cities);
    }

    // Ouput most optimal tour and its total distance value
    std::cout << "Most Optimal Tour: ";
    for(int i : optimalTour) {
        std::cout << i << " ";  
    }
    std::cout << "0 | Distance (cost): " << cheapestTourDistance;// << std::endl; 

}
