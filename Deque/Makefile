CC = g++
CFLAGS = -Wall -Wextra

TARGET = deque

all: $(TARGET)

$(TARGET): main.o deque.o
	$(CC) $(CFLAGS) main.o deque.o -o $(TARGET)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o

deque.o: deque.cpp deque.h
	$(CC) $(CFLAGS) -c deque.cpp -o deque.o

clean:
	rm *.o $(TARGET)
