#include "Headers/AdjacencyMatrix.hpp"
#include "Headers/BruteForce.hpp"

#include <iostream>

int main()
{
    AdjacencyMatrix am;
    am.ReadFileAndPopulate();
    //am.PrintMatrix();
    int numCities = 7;

    BruteForce bf(am, numCities);

    bf.RunBruteForce(); 

    return 0;
}