#Macros
CC = gcc
FLAGS = -Wall -g
all:functions
clean:
	rm -f functions *.o

functions: main.o functions.o functions.h
	$(CC) $(CFLAGS) main.o functions.o -o functions

main.o: main.c functions.h
	$(CC) $(CFLAGS) -c main.c

functions.o: functions.c functions.h
	$(CC) $(CFLAGS) -c functions.c