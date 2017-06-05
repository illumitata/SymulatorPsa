//Wczytanie grafik do pamięci

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "grafika.h"    //plik ze strukturą zwierzaka

#define CLEAR(x) memset(x,'\0',sizeof(char) * 50)           //czyści ścieżkę ze starej i robią ją pustą

char wczytajPlik(char * sciezka, char * nazwa, char tab[]){

      char c;
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

  glowa1 = malloc(sizeof(char) * 70);
  glowa2 = malloc(sizeof(char) * 70);
  glowa3 = malloc(sizeof(char) * 70);

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

void drukujGlowe(char tab[]){

  for(int k=0; k<70; k++){          //czy można ulepszyć. printf("%s", tab) musi mieć 0 na końcu
    printf("%c", tab[k]);
  }

  return;
}

void drukujDol(char tab[]){

  for(int k=0; k<53; k++){
    printf("%c", tab[k]);
  }

  return;
}

void drukuj(int warunek){

if(warunek == 1){
  drukujGlowe(glowa2);
  drukujDol(dol2);
}
  return;
}
