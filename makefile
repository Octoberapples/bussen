CC=gcc
FLAGS= -Wall -ggdb -std=c99 
bus: bus.c bus.h main.o
	$(CC) $(FLAGS) -c  bus.c bus.h 

main.o: main.c main.h

//om vi inkluderar bus.h i bus.c så behöver vi inte ha med bus.h då det blir kompilerat i samband med bus.c
