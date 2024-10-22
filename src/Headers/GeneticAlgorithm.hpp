/***************************************************************
  Student Name: Trevor Mee
  File Name: GeneticAlgorithm.hpp
  Project 3

  @brief Contains function declarations for solving the Traveling
         Salesman Problem using genetic operations
***************************************************************/

#ifndef GENETICALGORITHM_HPP
#define GENETICALGORITHM_HPP

#include "AdjacencyMatrix.hpp"
#include <vector>
#include <random>
#include <algorithm>

class GeneticAlgorithm
{
    private:
      // Private instance variables
      AdjacencyMatrix am;
      int numCities;
      int numToursToRun;
      int numGenerationsToRun;
      double mutationRate;
      std::vector<std::vector<int>> population;

    public:
      // Parametrized Constructor
      GeneticAlgorithm(const AdjacencyMatrix& matrix, int _numCities, 
                       int _numToursToRun, double _mutationRate);
      
      // Initialize Population (First generation)
      void InitializePopulation();

      // Helper function to evaluate fitness of tour
      double EvaluateFitness(const std::vector<int>& tour);

      // Gets elite tour from a generation
      std::vector<int> GetEliteTour();

      // Generates mutations
      std::vector<int> Mutate(const std::vector<int>& tour);

      // Runs the genetic algorithm
      void RunGeneticAlgorithm();
};
#endif
