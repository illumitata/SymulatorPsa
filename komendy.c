#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "symulator.h"    //plik ze strukturą zwierzaka
#include "komendy.h"
#include "losowanie.h"    //ułatwienie dla ziaren i losowania

struct Pupil* dajJesc(struct Pupil* pies){

  int losowa = losowanie();      //inicjalizacja randa (sprawdzić) seed?

  if((pies->glod + (losowa%30 + 1))<100) pies->glod = pies->glod + (losowa%30 + 1);
  else pies->glod = 100;

  return pies;
}

struct Pupil* dajWode(struct Pupil* pies){

  int losowa = losowanie();

  if((pies->prag + (losowa%30 + 1))<100) pies->prag = pies->prag + (losowa%30 + 1);
  else pies->prag = 100;

  return pies;
}

struct Pupil* dajSpacer(struct Pupil* pies){

  int losowa = losowanie();

  if((pies->zado + (losowa%50 + 20))<100) pies->zado = pies->zado + (losowa%50 + 20);
  else pies->zado = 100;

  return pies;
}

struct Pupil* dajWet(struct Pupil* pies){

  if((pies->zdro + 30)<100) pies->zdro = pies->zdro + 30;
  else pies->zdro = 100;

  return pies;
}
