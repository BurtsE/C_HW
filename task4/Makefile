]CC=gcc

CFLAGS= -lm
build:
	$(CC) -o task armstrong.c refactor.c linkedlist.c main.c $(CFLAGS)
build32:
	$(CC) -o task armstrong.c refactor.c linkedlist.c main.c $(CFLAGS) -m32
check: task
	valgrind --leak-check=full ./task
run: task
	./task
