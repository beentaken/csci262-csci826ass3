CC = g++
all: Traffic
Traffic: main.o
	$(CC) main.o -o Traffic

main.o: main.cpp
	$(CC) -c main.cpp

clean:
	rm *.o
	rm Traffic
