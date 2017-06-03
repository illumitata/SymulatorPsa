CC=gcc
CFLAGS=-Wall

all: symulator.o menu.o getch.o
	$(CC) symulator.o menu.o getch.o -o symulator -lpthread

symulator.o: symulator.c symulator.h getch.h menu.h
	$(CC)  symulator.c -c -o symulator.o -lpthread

menu.o: menu.c symulator.h menu.h
	$(CC) menu.c -c -o menu.o	-lpthread

getch.o: getch.c getch.h
	$(CC) getch.c -c -o getch.o	-lpthread

clean:		#make clean w terminalu usuwa wszystkie zbędne pliki *.o
	@rm -f *.o
