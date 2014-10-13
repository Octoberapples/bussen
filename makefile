CC=gcc
FLAGS= -Wall -ggdb -std=c99
bus: bus.c bus.h
	$(CC) $(FLAGS) -c bus.c bus.h 