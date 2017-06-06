//Wczytanie grafik do pamięci

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "grafika.h"    //plik ze strukturą zwierzaka

#define CLEAR(x) memset(x,'\0',sizeof(char) * 50)           //czyści ścieżkę ze starej i robią ją pustą

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
  sciezka = malloc(sizeof(char) * 50);

  dol1 = malloc(sizeof(char) * 53);
  dol2 = malloc(sizeof(char) * 53);
  dol3 = malloc(sizeof(char) * 53);

  glowa1 = malloc(sizeof(char) * 71);
  glowa2 = malloc(sizeof(char) * 71);
  glowa3 = malloc(sizeof(char) * 71);

  char *plik = malloc(sizeof(char) * 6);

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
