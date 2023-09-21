functions: main.o functions.o functions.h
	gcc main.o functions.o -o functions

main.o: main.c functions.h
	gcc -c main.c

functions.o: functions.c functions.h
	gcc -c functions.c