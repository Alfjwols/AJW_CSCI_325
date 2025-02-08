
output: main.o vector.o
	g++ main.o -Wall -Wextra -o vectorTest

main.o: main.cpp
	g++ -c main.cpp

vector.o: vector.cpp vector.h
	g++ -c vector.cpp

clean:
	rm *.o output
