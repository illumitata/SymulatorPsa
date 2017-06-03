//Wczytanie grafik do pamięci

#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "grafika.h"    //plik ze strukturą zwierzaka

int * wczytajPlik(char * nazwa){

      int *tab = malloc(44);

      char c = 0;
      FILE * fp;
      char * sciezka = NULL;
      char * folder = "ASCII_ART/psy/";
      sciezka = malloc(sizeof(sciezka) * 100);
      strcat(sciezka,folder);
      strcat(sciezka, nazwa);
      strcat(sciezka,".txt");
      fp = fopen(sciezka,"r");

      int k = 0;

      if (fp != NULL) {
        while ((c = getc(fp)) != EOF)
        tab[k] = c;
        k++;
      }
      fclose(fp);

    free(nazwa);
    free(sciezka);


    return tab;
}

void wczytajDoTablicy(){

  char *s1 = "dol1";
  char *wynik;
  wynik = (char *)wczytajPlik(s1);
  for(int k=0; k<44; k++) printf("%c", wynik[k]);
/*  dol2[44] = wczytajPlik("dol2");
  dol3[44] = wczytajPlik("dol3");

  glowa1[44] = wczytajPlik(glowa1);
  glowa2[44] = wczytajPlik(glowa2);
  glowa3[44] = wczytajPlik(glowa3);
*/
 free(wynik);
  return;
}

void drukuj(char stan[]){

  for(int k=0; k<44; k++) printf("%c", stan[k]);

  free(stan);
  return;
}
