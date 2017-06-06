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
#include "losowanie.h"    //ułatwienie dla ziaren i losowania

//////////
static int  wyjscie = 0;
static int wybor    = 0;
static char komenda = 0;  //A góra, B dół
static int  sygnal  = 0;
static int  pozycja = 1;  //pozycja strzałki w menu od 1 do 5

//Wątek odpowiadający za czytanie z klawiatury
void *threadFunc(void *arg){

    do{
        usleep(100000);
        //sleep(2); na potrzeby testu

        if(wybor != '\0') komenda = wybor;      //WAŻNA KOLEJNOŚĆ TYCH KOMEND

        wybor = getche();

        if(wybor==10){                          //jeśli ENTER zatwierdza wybór i czyści
          sygnal = 1;
          wybor  = '\0';
        }

        if(wybor == 27){                        //Ubuntu pod którym pracuje najpierw ściąga 27
          komenda = getche();
          if(komenda==91){                      //Potem ściąga 91 i dopiero dla 65 i 66 określa strzałkę
            komenda = getche();
            if(komenda == 65 && pozycja>1) pozycja-=1;
            if(komenda == 66 && pozycja<5) pozycja+=1;
          }
        }
        else wybor = '\0';
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
      //sleep(2); na potrzeby testu

      system("clear");
      printf("%s... Dzień: %d Godzina: %d:00\n", pies->imie, dzien, godzina);
      printf("%d\n", pies->glod);
      printf("%d\n", pies->prag);
      printf("%d\n", pies->zado);
      printf("%d\n", pies->zdro);

      if(sygnal==1){
        if(pozycja==1) dajJesc(pies);    //nakarm - 1
        if(pozycja==2) dajWode(pies);    //daj wodę - 2
        if(pozycja==3) dajSpacer(pies);  //wyjdź na spacer - 3
        if(pozycja==4) dajWet(pies);     //odwiedź weterynarza - 4
        if(pozycja==5){
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

    menuGry(pozycja);

    int czynnik = losowanie();
    if((czynnik%10000)<500) choroba = 1;
    else choroba = 0;

//    printf("Twoja czynność: %c\n", wybor);

    czas++;

      if(czas%40 == 0){           //czas do zmiennej stałej
        godzina++;
        pies->glod = pies->glod - 2;
        pies->prag = pies->prag - 2;
        if(choroba==1){
          int problem = losowanie();
          pies->zdro = pies->zdro - (problem%30);
        }
        pies->zado = pies->zado - 5;
          if(godzina%24==0){
            czas = 0;
            godzina = 0;
            dzien++;
          }
      }
    }

    system("clear");
    printf("\n\t\t Wytrzymałeś %d dni i %d godzin.\n", dzien, godzina);
    printf("\n\t (Naciśnij dowolny przycisk, żeby wyjść z gry)\n");

    free(pies);

    pthread_join(pth,NULL);

    return 0;
}
