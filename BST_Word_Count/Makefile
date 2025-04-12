CC = g++
TARGET = WordSort
CFLAGS = -Wall -Wextra -c


all: $(TARGET)

$(TARGET): driver.o BST.o Node.o HelperFunctions.o
	$(CC) driver.o BST.o Node.o HelperFunctions.o -o $(TARGET)

HelperFunctions.o: HelperFunctions.cpp HelperFunctions.h
	$(CC) $(CFLAGS) HelperFunctions.cpp -o HelperFunctions.o

driver.o: driver.cpp
	$(CC) $(CFLAGS) driver.cpp -o driver.o

BST.o: BST.h BST.cpp HelperFunctions.o
	$(CC) $(CFLAGS) BST.cpp -o BST.o

Node.o: Node.h Node.cpp HelperFunctions.o
	$(CC) $(CFLAGS) Node.cpp -o Node.o

clean:
	rm -f *.o $(TARGET)
