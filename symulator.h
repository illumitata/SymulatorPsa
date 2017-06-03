//struktura psa potrzebna w grze

#ifndef SYMULATOR_H
#define SYMULATOR_H

#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

typedef struct Pupil{
  char       imie[30];      //imię psa
  char       glod;          //glod
  char       prag;          //pragnienie
  char       zdro;          //zdrowie
  char       zado;          //zadowolenie
} Pupil;

#endif /* !SYMULATOR_H */
