CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJS = main.o AdjacencyMatrix.o GeneticAlgorithm.o BruteForce.o

proj3 : ${OBJS}
		${CXX} $(CXXFLAGS) -o $@ ${OBJS}

main.o : Headers/AdjacencyMatrix.hpp
AdjacencyMatrix.o : Headers/AdjacencyMatrix.hpp
GeneticAlgorithm.o : Headers/GeneticAlgorithm.hpp
BruteForce.o : Headers/BruteForce.hpp

clean :
		rm ${OBJS}