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

  int stan = 0;

  if(pies->glod>=70 || pies->zdro>=70) stan = 1;

  return stan;
}
