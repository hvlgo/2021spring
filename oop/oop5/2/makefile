main: main.o myfriend.o newslist.o
	g++ -o main  main.o myfriend.o newslist.o
main.o: main.cpp 
	g++ -c main.cpp
myfriend.o: myfriend.cpp
	g++ -c myfriend.cpp
newslist.o: newslist.cpp
	g++ -c newslist.cpp
clean:
	del *.o main