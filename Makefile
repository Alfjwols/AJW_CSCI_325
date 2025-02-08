vectorTest: main.o vector.o
	g++ main.o vector.o -Wall -Wextra -o vectorTest

main.o: main.cpp
	g++ -c main.cpp -o main.o

vector.o: vector.cpp vector.h
	g++ -c vector.cpp -o vector.o

clean:
	rm -f*.o vectorTest
