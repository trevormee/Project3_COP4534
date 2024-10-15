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
*
void AdjacencyMatrix::ReadFileAndPopulate()
{
    std::ifstream fileRead(DISTANCES);
    std::string line;

    double distance;
    int row = 0;
    int col = 0;
    int count = 0;

    while(std::getline(fileRead, line))
    {
        
        std::istringstream iss(line);
        iss >> distance;

         if(row == col)
        {
            matrix[row][col] = 0;
            if(col + 1 < ROW_COLUMN_SIZE)
            {
                col++;
                matrix[row][col] = distance;
                std::cout << "inserted -> " << distance << " at " << row << " " << col << std::endl;
            }
            else if(row + 1 < ROW_COLUMN_SIZE)
            {
                row++;
                matrix[row][col] = distance;
                std::cout << "\tinserted -> " << distance << " at " << row << " " << col << std::endl;
            }
        }
        else
        {
            matrix[row][col] = distance;
            col++;
            if(col == ROW_COLUMN_SIZE)
            {
                col = 0;
                row++;
            }

            std::cout << "\t\tinserted -> " << distance << " at " << row << " " << col << std::endl;
        }

       // std::cout << "inserted -> " << distance << " at " << row << " " << col << std::endl;
       *

    }

    fileRead.close();
}
*/


void AdjacencyMatrix::ReadFileAndPopulate()
{
    std::ifstream fileRead(DISTANCES);
    std::string line;

    double distance;
    int row = 0;
    int col = 0;
    int count = 0;

    while (std::getline(fileRead, line))
    {
        std::istringstream iss(line);
        iss >> distance;

        // Always skip the diagonal (set to 0)
        if (row == col) {
            matrix[row][col] = 0.0;
            col++;  // Move to the next column
        }

        // Insert the distance into the matrix
        if (col < ROW_COLUMN_SIZE) {
            matrix[row][col] = distance;
            std::cout << "Inserted -> " << distance << " at " << row << " " << col << std::endl;
            col++;
        }

        // Move to the next row if we've filled all columns
        if (col == ROW_COLUMN_SIZE) {
            col = 0;
            row++;
        }

        // Stop when we finish filling the matrix
        if (row == ROW_COLUMN_SIZE) {
            break;
        }
    }

    fileRead.close();
}



/*
    @brief
    @param
*/
void AdjacencyMatrix::PrintMatrix() {
    const int spacing = 8; // Adjust the width for each element for even spacing

    // Print column indices
    std::cout << std::setw(spacing) << " ";  // Empty space for row labels
    for (int col = 0; col < ROW_COLUMN_SIZE; col++) {
        std::cout << std::setw(spacing) << col;
    }
    std::cout << std::endl;

    // Print the matrix with row indices
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