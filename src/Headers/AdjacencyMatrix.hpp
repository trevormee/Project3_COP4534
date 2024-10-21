/***************************************************************
  Student Name: Trevor Mee
  File Name: AdjacencyMatrix.hpp
  Project 3

  @brief Contains function declarations for reading in a text file
         and creating an adjaceny matrix
***************************************************************/

#ifndef ADJACENCYMATRIX_HPP
#define ADJACENCYMATRIX_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

class AdjacencyMatrix
{
    private:
        // Private Instance Variables
        const std::string DISTANCES = "../distances.txt";
        const static int ROW_COLUMN_SIZE = 20;

    public:
        // Public adjacency matrix 
        double matrix[ROW_COLUMN_SIZE][ROW_COLUMN_SIZE];
        
        // Constructor
        AdjacencyMatrix();

        // Reads in distances.txt & populates adjacency matrix
        void ReadFileAndPopulate();

        // Prints Matrix (used for testing)
        void PrintMatrix();    
};
#endif