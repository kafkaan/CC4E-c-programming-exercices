CC = gcc
CFLAGS = -Wall

all: tree_program

tree_program: main.o tree.o stack.o
	$(CC) -o tree_program main.o tree.o stack.o

main.o: main.c tree.h
	$(CC) $(CFLAGS) -c main.c

tree.o: tree.c tree.h
	$(CC) $(CFLAGS) -c tree.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

clean:
	rm -f *.o tree_program
