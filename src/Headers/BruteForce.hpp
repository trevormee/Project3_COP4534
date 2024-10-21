/***************************************************************
  Student Name: Trevor Mee
  File Name: BruteForce.hpp
  Project 3

  @brief Contains function declarations for solving the Traveling
         Salesman Problem using a brute force algorithm
***************************************************************/

#ifndef BRUTEFORCE_HPP
#define BRUTEFORCE_HPP

#include "AdjacencyMatrix.hpp"
#include <limits>
#include <vector>
#include <algorithm>

class BruteForce
{
    private:
        // Private Instance Variables
        AdjacencyMatrix am;
        int numCities;

        // Helper method to compute (n-1)! value for RunBruteForce() iterations
        int Factorial(int n);

        // Helper function to evaluate the cost of a tour
        double EvaluateTour(const std::vector<int>& tour);
        
    public:
        // Parameterized Constructor
        BruteForce(const AdjacencyMatrix& matrix, int _numCities);

        // Generates Permutations
        void perm1(std::vector<int>& s);


        // Runs the Brute Force Algorithm
        void RunBruteForce();
};
#endif