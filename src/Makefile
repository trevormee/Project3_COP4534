CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJS = main.o AdjacencyMatrix.o

proj3 : ${OBJS}
		${CXX} $(CXXFLAGS) -o $@ ${OBJS}

main.o : Headers/AdjacencyMatrix.hpp
AdjacencyMatrix.o : Headers/AdjacencyMatrix.hpp

clean :
		rm ${OBJS}