CC=gcc
CFLAGS=-Wall

all: symulator.o menu.o getch.o grafika.o logika.o komendy.o losowanie.o
	$(CC) symulator.o menu.o grafika.o getch.o logika.o komendy.o losowanie.o -o symulator -lpthread

symulator.o: symulator.c symulator.h getch.h grafika.h menu.h logika.h losowanie.h
	$(CC)  symulator.c -c -o symulator.o -lpthread

menu.o: menu.c symulator.h menu.h
	$(CC) menu.c -c -o menu.o	-lpthread

komendy.o: komendy.c symulator.h komendy.h losowanie.h
	$(CC) komendy.c -c -o komendy.o	-lpthread

logika.o: logika.c logika.h symulator.h
	$(CC) logika.c -c -o logika.o -lpthread

getch.o: getch.c getch.h
	$(CC) getch.c -c -o getch.o	-lpthread

grafika.o: grafika.c grafika.h
	$(CC) grafika.c -c -o grafika.o -lpthread

losowanie.o: losowanie.c losowanie.h
	$(CC) losowanie.c -c -o losowanie.o -lpthread

clean:		#make clean w terminalu usuwa wszystkie zbędne pliki *.o
	@rm -f *.o
