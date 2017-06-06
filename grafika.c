//Wczytanie grafik do pamięci

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "grafika.h"    //plik ze strukturą zwierzaka

#define CLEAR(x) memset(x,'\0',sizeof(char) * 100)           //czyści ścieżkę ze starej i robią ją pustą

char wczytajPlik(char * sciezka, char * nazwa, char tab[]){

      char c; //zmienna
      FILE * fp;

      char * folder = "ASCII_ART/psy/";
      strcat(sciezka,folder);
      strcat(sciezka, nazwa);
      strcat(sciezka,".txt");
      fp = fopen(sciezka,"r");

      int k = 0;

      if (fp != NULL){
        while ((c = getc(fp)) != EOF){
          tab[k] = c;
          k++;
        }
      }
      fclose(fp);

    return *tab;
}

void wczytajDoTablic(){

  char * sciezka = NULL;
  sciezka = malloc(sizeof(char) * 100);

  dol1 = malloc(sizeof(char) * 53);
  dol2 = malloc(sizeof(char) * 53);
  dol3 = malloc(sizeof(char) * 53);

  glowa1 = malloc(sizeof(char) * 71);
  glowa2 = malloc(sizeof(char) * 71);
  glowa3 = malloc(sizeof(char) * 71);

  miska  = malloc(sizeof(char) * 170);
  woda   = malloc(sizeof(char) * 170);
  spacer = malloc(sizeof(char) * 240);
  lekarz = malloc(sizeof(char) * 170);
  noc    = malloc(sizeof(char) * 220);

  char *plik = malloc(sizeof(char) * 10);

  plik = "dol1";
  *dol1 = wczytajPlik(sciezka, plik, dol1);
  CLEAR(sciezka);

  plik = "dol2";
  *dol2 = wczytajPlik(sciezka, plik, dol2);
  CLEAR(sciezka);

  plik = "dol3";
  *dol3 = wczytajPlik(sciezka, plik, dol3);
  CLEAR(sciezka);

  plik = "glowa1";
  *glowa1 = wczytajPlik(sciezka, plik, glowa1);
  CLEAR(sciezka);

  plik = "glowa2";
  *glowa2 = wczytajPlik(sciezka, plik, glowa2);
  CLEAR(sciezka);

  plik = "glowa3";
  *glowa3 = wczytajPlik(sciezka, plik, glowa3);
  CLEAR(sciezka);

  plik = "ekrany/miska";
  *miska = wczytajPlik(sciezka, plik, miska);
  CLEAR(sciezka);

  plik = "ekrany/woda";
  *woda = wczytajPlik(sciezka, plik, woda);
  CLEAR(sciezka);

  plik = "ekrany/spacer";
  *spacer = wczytajPlik(sciezka, plik, spacer);
  CLEAR(sciezka);

  plik = "ekrany/lekarz";
  *lekarz = wczytajPlik(sciezka, plik, lekarz);
  CLEAR(sciezka);

  plik = "ekrany/noc";
  *noc = wczytajPlik(sciezka, plik, noc);
  CLEAR(sciezka);

  plik = NULL;

  free(plik);
  free(sciezka);

  return;
}

void drukujCzesc(char tab[]){
                                          //czy można ulepszyć. printf("%s", tab) musi mieć 0 na końcu
    printf("%s", tab);

  return;
}

void drukujEkran(int ekran){

  system("clear");

  if(ekran==1) drukujCzesc(miska);
  if(ekran==2) drukujCzesc(woda);
  if(ekran==3) drukujCzesc(spacer);
  if(ekran==4) drukujCzesc(lekarz);
  if(ekran==5) drukujCzesc(noc);

  sleep(2);

  return;
}

void drukuj(int warunek){

  if(warunek>=2 && warunek<=4){
    drukujCzesc(glowa2);
    if(warunek == 2){
      drukujCzesc(dol2);
      return;
      }
    if(warunek == 3){
      drukujCzesc(dol3);
      return;
    }
    if(warunek == 4){
      drukujCzesc(dol1);
      return;
    }
  }

  if(warunek>=6 && warunek<=9){
    drukujCzesc(glowa3);
    if(warunek == 6){
      drukujCzesc(dol2);
      return;
    }
    if(warunek == 7){
      drukujCzesc(dol3);
      return;
    }
    if(warunek == 8){
      drukujCzesc(dol1);
      return;
    }
  }

  if(warunek>=10 && warunek<=12){
    drukujCzesc(glowa1);
    if(warunek == 10){
      drukujCzesc(dol2);
      return;
    }
    if(warunek == 11){
      drukujCzesc(dol3);
      return;
    }
    if(warunek == 12){
      drukujCzesc(dol1);
      return;
    }
  }

return;
}
