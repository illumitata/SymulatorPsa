#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "zapis.h"
#include "symulator.h"

void zapiszGre(struct Pupil* pies,int dzien,int godzina){

      FILE * fp;
      char * folder = "zapis/zapis.txt";
      fp = fopen(folder,"w");

      if(fp != NULL){
        fprintf(fp,"%d %d %s %d %d %d %d",dzien,godzina,pies->imie,pies->glod,pies->prag,pies->zado,pies->zdro);
      }

      fclose(fp);

      return;
}

struct Zapis* wczytajGre(struct Zapis* zapis){

    FILE * fp;
    char * folder = "zapis/zapis.txt";
    fp = fopen(folder,"r");

    int glod;
    int prag;
    int zado;
    int zdro;

    if(fp != NULL){
      fscanf(fp,"%d %d %s %d %d %d %d",&zapis->dzien,&zapis->godzina,zapis->imie,&glod,&prag,&zado,&zdro);
    }
    fclose(fp);

    zapis->glod = glod;
    zapis->prag = prag;
    zapis->zado = zado;
    zapis->zdro = zdro;

    //printf("%d %d %s %d %d %d %d",zapis->dzien,zapis->godzina,zapis->imie,zapis->glod,zapis->prag, zapis->zado,zapis->zdro);

    return zapis;

}
