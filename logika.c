//Funckje odpowiedzialne za sprawdzanie stanu psa i "wynioskowaniu" warunków zwycięstwa bądź druku

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include "logika.h"

/*
pies->glod = 100;
pies->prag = 100;
pies->zdro = 100;
pies->zado = 100;
*/

int sprawdzStan(struct Pupil* pies){

  if(pies->glod<=0 || pies->prag<=0 || pies->glod<=0 || pies->zado<=0){
    stan = 0; //przegrana
    return stan;
  }

  if(pies->glod>=70 && pies->zdro>=70){ //&&  //glowa wysoko
      stan = 1;
      if(pies->prag>=70 && pies->zado>=70){
        stan+=1;                              //ogon wysoko
      }
      else{
        if(pies->prag>=40 && pies->zado>=40 ){  //ogon srednio
          stan+=2;
        }
        else{
          stan+=3; //ogon nisko
        }
      }
  }else{
    if(pies->glod>=40 && pies->zdro>=40){ //glowa srednio
        stan = 5;
        if(pies->prag>=70 && pies->zado>=70){ //ogon wysoko
          stan+=1;
        }
        else{
            if(pies->prag>=40 && pies->zado>=40 ){ //ogon srednio
              stan+=2;
            }
            else{
              stan+=3; //ogon nisko
            }
        }
    }
    else{                                        //glowa nisko
        stan = 9;
        if(pies->prag>=70 && pies->zado>=70){ //ogon wysoko
          stan+=1;
        }
        else{
          if(pies->prag>=40 && pies->zado>=40 ){ //ogon srednio
            stan+=2;
          }
          else{
            stan+=3; //ogon nisko
          }
        }
    }
  }
  return stan;
}
