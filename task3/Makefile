CC=gcc

CFLAGS= -lm -lreadline
build:
	$(CC) -o task armstrong.c refactor.c task.c main.c $(CFLAGS)
check: task
	valgrind --leak-check=full ./task
run:  task
	./task
