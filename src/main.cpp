#include "Headers/AdjacencyMatrix.hpp"

#include <iostream>

int main()
{
    AdjacencyMatrix am;
    am.ReadFileAndPopulate();
    am.PrintMatrix();

    std::cout << "end" << std::endl;

    return 0;
}