all: main

main: main.o School.o Student.o
	g++ $(dbg) main.o School.o Student.o -o main
main.o: main.cpp
	g++ $(dbg) -c main.cpp -o main.o --std=c++11
School.o : School.h School.cpp
	g++ $(dbg) -c School.cpp -o School.o
Student.o: Student.h Student.cpp
	g++ $(dbg) -c Student.cpp -o Student.o

clean:
	del *.o main