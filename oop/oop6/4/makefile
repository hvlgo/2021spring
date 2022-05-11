all: main
main: main.o Calculator.o
	g++ -o main main.o Calculator.o -std=c++11
main.o: main.cpp
	g++ -o main.o -c main.cpp -std=c++11
Calculator.o: Calculator.cpp
	g++ -o Calculator.o -c Calculator.cpp -std=c++11
clean:
	del *.o main.exe