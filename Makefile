CC=gcc
CLFAGS=-Wall -Wextra -fsanitize=address -fsanitize=undefined -lncurses -lm

: cube.o frameRenderer.o 3DObject2.o vector.o surface.o
	$(CC) $(CFLAGS) cube.o frameRenderer.o 3DObject2.o vector.o surface.o -o main

cube.o:
	$(CC) $(CFLAGS) -c cube.c
	echo "what"
