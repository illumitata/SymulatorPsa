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
        fprintf(fp,"%d\n",dzien);
        fprintf(fp,"%d\n",godzina);
        fprintf(fp,"%s\n",pies->imie);
        fprintf(fp,"%d\n",pies->glod);
        fprintf(fp,"%d\n",pies-> prag);
        fprintf(fp,"%d\n",pies->zado);
        fprintf(fp,"%d\n",pies->zdro);
      }

      fclose(fp);

      return;
}

struct Pupil* wczytajGre(struct Pupil* pies){

    FILE * fp;
    char * folder = "zapis/zapis.txt";

    if(fp != NULL){
      fscanf(fp,"%d\n",&dzien);
      fscanf(fp,"%d\n",&godzina);
      fscanf(fp,"%s\n",pies->imie);
      fscanf(fp,"%d\n",pies->glod);
      fscanf(fp,"%d\n",pies->prag);
      fscanf(fp,"%d\n",pies->zado);
      fscanf(fp,"%d\n",pies->zdro);

    }
    fclose(fp);

    return pies;

}
