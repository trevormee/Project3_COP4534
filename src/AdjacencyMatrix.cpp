/***************************************************************
  Student Name: Trevor Mee
  File Name: AdjacencyMatrix.cpp
  Project 3

  @brief Contains function definitions for reading in a text file
         and creating an adjaceny matrix
***************************************************************/

#include "Headers/AdjacencyMatrix.hpp"

/*
    @brief Default constructor to populate adjacency
           matrix with default value of 0.0
*/
AdjacencyMatrix::AdjacencyMatrix()
{
    for(int i = 0; i < ROW_COLUMN_SIZE; i++)
    {
        for(int j = 0; j < ROW_COLUMN_SIZE; j++)
        {
            matrix[i][j] = 0.0;
        }
    }
}


/*
    @brief Reads in distances.txt & populates adjacency matrix
*/
void AdjacencyMatrix::ReadFileAndPopulate()
{
    std::ifstream fileRead(DISTANCES);
    std::string line;

    double distance;
    int row = 0;
    int col = 0;

    while(std::getline(fileRead, line))
    {
        std::istringstream iss(line);
        iss >> distance;
        
        // Insert 0.0 when row value == col value
        if(row == col)
        {
            matrix[row][col] = 0.0;
            col++;
        }

        // if column is not full and insert distance value
        if(col < ROW_COLUMN_SIZE)
        {
            matrix[row][col] = distance;
            col++;
        }

        // If column is full, move to next row
        if(col == ROW_COLUMN_SIZE)
        {
            col = 0;
            row++;
        }

        // If matrix is full, break
        if(row == ROW_COLUMN_SIZE)
        {
            break;
        }
    }

    fileRead.close();
}


/*
    @brief prints adjacency matrix (used for testing)
*/
void AdjacencyMatrix::PrintMatrix() {
    
    const int spacing = 8; 

    // Print column indices
    std::cout << std::setw(spacing) << " "; 
    for (int col = 0; col < ROW_COLUMN_SIZE; col++) {
        std::cout << std::setw(spacing) << col;
    }
    std::cout << std::endl;

    // Print matrix
    for (int i = 0; i < ROW_COLUMN_SIZE; i++) {
        // Print row index
        std::cout << std::setw(spacing) << i;

        // Print the row of the matrix
        for (int j = 0; j < ROW_COLUMN_SIZE; j++) {
            std::cout << std::setw(spacing) << matrix[i][j];
        }
        std::cout << std::endl;
    }

    std::cout << " -- " << matrix[0][1] << std::endl;
}