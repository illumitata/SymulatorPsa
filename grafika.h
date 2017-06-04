#ifndef GRAFIKA_H
#define GRAFIKA_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "grafika.h"

static char *dol1;
static char *dol2;
static char *dol3;

static char *glowa1;
static char *glowa2;
static char *glowa3;

void wczytajDoTablic();

void drukuj(int warunek);

#endif /* GRAFIKA_H*/
