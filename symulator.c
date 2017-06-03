//Symulator Psa - Jan Iwaszkiewicz, Krzysztof Józefczyk

#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "symulator.h"    //plik ze strukturą zwierzaka
#include "getch.h"        //odpowiada za zczytywanie znaku i zapamiętywanie go na ekranie pomimo odświeżania ekranu
#include "grafika.h"
#include "menu.h"         //drukowanie menu startowego


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

    wczytajDoTablicy();

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
    drukuj(dol1);

    i++;
    }

    printf("main waiting for thread to terminate...\n");
    pthread_join(pth,NULL);

    free(pies);

    exit(1);
    return 0;
}
