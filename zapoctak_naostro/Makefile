CC=gcc
CFLAGS=-std=c99

all: comp

comp: main.o
  $(CC) -o comp main.o
  
main.o: main.c
  $(CC) $(CFLAGS) -o main.o -c main.c
  
clean:
  rm *.o comp
  
.PHONY: all clean
