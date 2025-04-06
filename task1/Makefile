CC=gcc

CFLAGS=-lm
build:
	$(CC) -o task armstrong.c main.c $(CFLAGS)
build32:
	$(CC) -o task armstrong.c main.c -m32 $(CFLAGS)
run:  task
	./task
check:   task
	valgrind --leak-check=full ./task
