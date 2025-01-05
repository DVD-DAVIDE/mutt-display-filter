CC=gcc
CFLAGS=-I.

main: main.o
	$(CC) -o display.out main.c

