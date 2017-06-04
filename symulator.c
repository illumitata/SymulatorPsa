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
#include "menu.h"         //drukowanie menu startowego i innych statycznych elementów
#include "logika.h"       //logika całej gry, zestaw warunków

static int dzien = 0;
static char wybor = 0;
static char starywybor = 0;
static int sygnal = 0;

//Wątek odpowiadający za czytanie z klawiatury
void *threadFunc(void *arg){
    char *str;
    int i = 0;
    //int gowno;
    str=(char*)arg;

    while(1)
    {
        usleep(100000);

        if(wybor != '\0') starywybor = wybor;       //WAŻNA KOLEJNOŚĆ TYCH KOMEND

        wybor = getche();
        //printf("%c\n", wybor);
        //sleep(1);

        if(wybor==10) sygnal = 1;          //teraz wysyła sygnał czyli i potem od razu zeruje, bo eneter nie leży od 48 do57
        //printf("%c\n", wybor);
        //sleep(1);
        if(!(wybor>48 && wybor<57)) wybor = '\0';     //wybór leży tylko miedzy danymi w menu inaczej "\0"
                                                      //(!!!)dopracować oraz po naciśnięciu entera dopiero wysyłał sygnał
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

    int warunek = 0;

    fflush(stdin);

    pthread_create(&pth,NULL,threadFunc,"wejscie");

    while(i < 100000){

    usleep(100000);

    system("clear");
    printf("%s... %c\n", pies->imie, wybor);
    printf("%d\n", pies->glod);

    if(sygnal==1){
      if(starywybor==49) pies->glod = pies->glod - 10;
      sygnal = 0;
      starywybor = '\0';                //rozwiązuje problem kiedy wciskamy enter kilka razy
    }

    warunek = sprawdzStan(pies);
    if(warunek == 0) break; //drukuj ekran przegranej i break z pętli
    else drukuj(warunek);
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
