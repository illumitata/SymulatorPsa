CC=gcc
CFLAGS=-Wall

all: symulator.o menu.o getch.o grafika.o
	$(CC) symulator.o menu.o grafika.o getch.o -o symulator -lpthread

symulator.o: symulator.c symulator.h getch.h grafika.h menu.h
	$(CC)  symulator.c -c -o symulator.o -lpthread

menu.o: menu.c symulator.h menu.h
	$(CC) menu.c -c -o menu.o	-lpthread

getch.o: getch.c getch.h
	$(CC) getch.c -c -o getch.o	-lpthread

grafika.o: grafika.c grafika.h
	$(CC) grafika.c -c -o grafika.o -lpthread

clean:		#make clean w terminalu usuwa wszystkie zbędne pliki *.o
	@rm -f *.o
