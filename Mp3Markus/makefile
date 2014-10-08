CC=gcc
FLAGS= -Wall -ggdb -std=c99
main: main.c tagManager.o
	$(CC) $(FLAGS) main.c tagManager.o -o main

tagManager.o: tagManager.c
	$(CC) $(FLAGS) -c tagManager.c
