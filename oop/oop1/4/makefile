main: main.o Parser.o
	g++ main.o Parser.o -o main
main.o: main.cpp Parser.h
	g++ -c main.cpp -o main.o
Parser.o: Parser.cpp Parser.h
	g++ -c Parser.cpp -o Parser.o
clean:
	-rm *.o main
