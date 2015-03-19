CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -Werror

all: dynamic

dynamic: dynamic.o
	$(CC) -o dynamic dynamic.o

dynamic.o: dynamic.c
	$(CC) $(CFLAGS) -c -o dynamic.o dynamic.c

clean:
	rm -f *.o dynamic

.PHONY: all clean
