CC = clang++
#CC = g++

all: dsPath

dsPath: main.o graph.o priorityQueue.o shortestPath.o
	${CC} main.o graph.o priorityQueue.o shortestPath.o -o dsPath

main.o: graph.h priorityQueue.h shortestPath.h main.cpp
	${CC} -c main.cpp

graph.o: graph.h graph.cpp
	${CC} -c graph.cpp

priorityQueue.o: priorityQueue.h priorityQueue.cpp
		${CC} -c priorityQueue.cpp

shortestPath.o: graph.h priorityQueue.h shortestPath.h shortestPath.cpp
		${CC} -c shortestPath.cpp

clean:
	rm dsPath *.o
