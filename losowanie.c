#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "losowanie.h"

int losowanie(){

  time_t t;
  int    liczba;

  srand((unsigned) time(&t));
  liczba = rand();

  return liczba;
}
