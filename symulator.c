//Symulator Psa - Jan Iwaszkiewicz, Krzysztof Józefczyk

#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "symulator.h"    //plik ze strukturą zwierzaka
#include "getch.h"        //odpowiada za zczytywanie znaku i zapamiętywanie go na ekranie pomimo odświeżania ekranu
#include "grafika.h"      //wczytanie grafik do pamięci, ich alokacja, oraz drukowanie na podstawie logik
#include "menu.h"         //drukowanie menu startowego
#include "logika.h"       //logika całej gry, zestaw warunków

static int dzien = 0;
static short int wybor = 0;

//Wątek odpowiadający za czytanie z klawiatury
void *threadFunc(void *arg){
    char *str;
    int i = 0;
    //int gowno;
    str=(char*)arg;

    while(i < 110000 )
    {
        sleep(1);

        wybor = getche();
        if(wybor == '\n') wybor = '\0';
        ++i;
    }

    return NULL;
}

//Główny wątek gry
int main(void){

    wczytajDoTablic();

    struct Pupil *pies = malloc(sizeof(Pupil));

    menu(pies);

    pthread_t pth;
    int i = 0;
    fflush(stdin);

    pthread_create(&pth,NULL,threadFunc,"wejscie");

    while(i < 100000){

    sleep(1);

    system("clear");
    printf("%s... %c\n", pies->imie, wybor);

    //druk = "glowa2";
    drukuj(1);
    /*Dlaczego tak a nie przywołując tablice?
      po pierwsze wyżej będzie funckja sprawdzająca życie psa i ustalająca warunki
      więc wysłanie sygnału do "świata" druku wydaje się zdecydowanie lepszym rozwiązaniem.
      dzięki temu nie trzeba tak wiele linkować, omijamy tonę niepotrzebnej zabawy
    */
    i++;
    }

    printf("main waiting for thread to terminate...\n");
    pthread_join(pth,NULL);

    free(pies);

    exit(1);
    return 0;
}
