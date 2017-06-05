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
#include "komendy.h"      //działania na rzecz zwierzaka

//////////
static int  wyjscie = 0;
static char wybor   = 0;
static char komenda = 0;
static int  sygnal  = 0;


//Wątek odpowiadający za czytanie z klawiatury
void *threadFunc(void *arg){

    char *str;
    str=(char*)arg;

    do{
        usleep(100000);

        if(wybor != '\0') komenda = wybor;       //WAŻNA KOLEJNOŚĆ TYCH KOMEND

        wybor = getche();
        //printf("%c\n", wybor);
        //sleep(1);

        if(wybor==10) sygnal = 1;          //teraz wysyła sygnał czyli i potem od razu zeruje, bo eneter nie leży od 48 do57
        if(!(wybor>48 && wybor<54)) wybor = '\0';     //wybór leży tylko miedzy danymi w menu inaczej "\0"
                                                      //(!!!) oraz po naciśnięciu entera dopiero wysyła sygnał
    }while(wyjscie<1);

    return NULL;

}

//Główny wątek gry
int main(void){

    wczytajDoTablic();

    struct Pupil *pies = malloc(sizeof(Pupil));

    menu(pies);

    static int dzien = 0;
    static long long int czas = 0;
    static int godzina = 0;
    static int choroba = 0;

    pthread_t pth;

    int warunek = 0;

    fflush(stdin);  //na wszelki wypadek

    pthread_create(&pth,NULL,threadFunc,"wejscie");

    while(1){

      usleep(100000);

      system("clear");
      printf("%s... Dzień: %d Godzina: %d:00\n", pies->imie, dzien, godzina);
      printf("%d\n", pies->glod);
      printf("%d\n", pies->prag);
      printf("%d\n", pies->zado);
      printf("%d\n", pies->zdro);

      if(sygnal==1){
        if(komenda==49) dajJesc(pies);    //nakarm - 1
        if(komenda==50) dajWode(pies);    //daj wodę - 2
        if(komenda==51) dajSpacer(pies);  //wyjdź na spacer - 3
        if(komenda==52) dajWet(pies);     //odwiedź weterynarza - 4
        if(komenda==53){
                        system("clear");
                        wyjscie = 1;
                        break;
                       }
        sygnal = 0;
        komenda = '\0';                   //rozwiązuje problem kiedy wciskamy enter kilka razy
      }

    warunek = sprawdzStan(pies);

    if(warunek == 0){
      wyjscie = 1;
      break; //drukuj ekran przegranej i break z pętli
    }
    else drukuj(warunek);
    /*Dlaczego tak a nie przywołując tablice?
      po pierwsze wyżej będzie funckja sprawdzająca życie psa i ustalająca warunki
      więc wysłanie sygnału do "świata" druku wydaje się zdecydowanie lepszym rozwiązaniem.
      dzięki temu nie trzeba tak wiele linkować, omijamy tonę niepotrzebnej zabawy
    */

    menuGry();

    int czynnik = rand();
    if((czynnik%10000)<1000) choroba = 1;
    else choroba = 0;

    printf("Twoja czynność: %c\n", wybor);

    czas++;

      if(czas%40 == 0){           //czas do zmiennej stałej
        godzina++;
        pies->glod = pies->glod - 5;
        pies->prag = pies->prag - 5;
        if(choroba==1){
          int problem = rand();
          pies->zdro = pies->zdro - (problem%30);
        }
        pies->zado = pies->zado - 10;
          if(godzina%24==0){
            czas = 0;
            godzina = 0;
            dzien++;
          }
      }
    }

    printf("\n\t\t Wytrzymałeś %d dni i %d godzin.\n", dzien, godzina);
    printf("\n\t (Naciśnij dowolny przycisk, żeby wyjść z gry)\n");

    free(pies);

    pthread_join(pth,NULL);

    return 0;
}
