CC=gcc
CFLAGS=-Wall

all: symulator.o menu.o getch.o grafika.o logika.o komendy.o
	$(CC) symulator.o menu.o grafika.o getch.o logika.o komendy.o -o symulator -lpthread

symulator.o: symulator.c symulator.h getch.h grafika.h menu.h logika.h
	$(CC)  symulator.c -c -o symulator.o -lpthread

menu.o: menu.c symulator.h menu.h
	$(CC) menu.c -c -o menu.o	-lpthread

komendy.o: komendy.c symulator.h komendy.h
	$(CC) komendy.c -c -o komendy.o	-lpthread

logika.o: logika.c logika.h symulator.h
	$(CC) logika.c -c -o logika.o -lpthread

getch.o: getch.c getch.h
	$(CC) getch.c -c -o getch.o	-lpthread

grafika.o: grafika.c grafika.h
	$(CC) grafika.c -c -o grafika.o -lpthread

clean:		#make clean w terminalu usuwa wszystkie zbędne pliki *.o
	@rm -f *.o
