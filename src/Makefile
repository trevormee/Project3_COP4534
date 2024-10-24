CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJS = main.o AdjacencyMatrix.o GeneticAlgorithm.o BruteForce.o TSP.o

proj3 : ${OBJS}
		${CXX} $(CXXFLAGS) -o $@ ${OBJS}

#main.o : Headers/AdjacencyMatrix.hpp 
main.o : Headers/TSP.hpp
AdjacencyMatrix.o : Headers/AdjacencyMatrix.hpp
GeneticAlgorithm.o : Headers/GeneticAlgorithm.hpp
BruteForce.o : Headers/BruteForce.hpp
TSP.o : Headers/TSP.hpp

clean :
		rm ${OBJS}