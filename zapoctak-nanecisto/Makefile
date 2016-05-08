CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -pedantic -g

all: printer

clean:
	rm -f *.o printer

printer: main.o functions.o functions.h
	$(CC) -o printer main.o functions.o

main.o: main.c functions.h
	$(CC) $(CFLAGS) -c main.c

functions.o: functions.c functions.h
	$(CC) $(CFLAGS) -c functions.c
