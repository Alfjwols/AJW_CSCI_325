CC = g++
TARGET = GameLibrary
CFLAGS = -Wall -Wextra -c

all: $(TARGET)

$(TARGET): Game.o Library.o main.o
	$(CC) Game.o Library.o main.o -o $(TARGET)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -o main.o

Library.o: Library.cpp Library.h
	$(CC) $(CFLAGS) Library.cpp -o Library.o

Game.o: Game.cpp Game.h
	$(CC) $(CFLAGS) Game.cpp -o Game.o

clean:
	rm -f *.o $(TARGET)
