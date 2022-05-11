main: main.o graph.o node.o operation.o mymap.o addandminus.o
	g++ -std=c++11 -o main main.o graph.o node.o operation.o mymap.o addandminus.o
main.o: main.cpp
	g++ -c -std=c++11 -o main.o main.cpp 
graph.o: graph.cpp graph.h mymap.h node.h operation.h
	g++ -c -std=c++11 -o graph.o graph.cpp 
node.o: node.cpp node.h
	g++ -c -std=c++11 -o node.o node.cpp 
operation.o: operation.cpp operation.h node.h
	g++ -c -std=c++11 -o operation.o operation.cpp 
mymap.o: mymap.cpp mymap.h 
	g++ -c -std=c++11 -o mymap.o mymap.cpp 
addandminus.o:
	g++ -c -std=c++11 -o addandminus.o addandminus.cpp
clean:
	del main *.o
