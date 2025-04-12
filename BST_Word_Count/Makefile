CC = g++
TARGET = WordSort
CFLAGS = -Wall -Wextra -C


all: $(TARGET)

$(TARGET): driver.o BST.o Node.o
	$(CC) driver.o BST.o Node.o -o $(TARGET)

driver.o: driver.cpp
	$(CC) $(CFLAGS) driver.cpp -o driver.o

BST.o: BST.h BST.cpp
	$(CC) $(CFLAGS) BST.cpp -o BST.o

Node.o: Node.h Node.cpp
	$(CC) $(CFLAGS) Node.cpp -o Node.o

clean:
	rm -f *.o $(TARGET)
