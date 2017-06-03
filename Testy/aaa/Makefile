CC=gcc
CFLAGS=-Wall
LDLIBS=-lpthread

all: wielo

wielo: wielo.o getch.o
	$(CC) $(CFLAGS) -o wielo wielo.o getch.o $(LDLIBS)

wielo.o: wielo.c getch.h
	$(CC) $(CFLAGS) -c wielo.c

getch.o: getch.c
	$(CC) $(CFLAGS) -c getch.c
