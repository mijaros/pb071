CC=gcc
CFLAGS=-std=c99 -Wall -Wextra

all: my_ls

my_ls: list_files.o
	$(CC) $(CFLAGS) list_files.o -o my_ls

list_files.o: list_files.c
	$(CC) $(CFLAGS) -c list_files.c -o list_files.o

clean:
	rm ./*.o my_ls

.PHONY: all clean
