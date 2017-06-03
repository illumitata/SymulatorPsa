#ifndef GRAFIKA_H
#define GRAFIKA_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "grafika.h"

static char dol1[44];
static char dol2[44];
static char dol3[44];

static char glowa1[44];
static char glowa2[44];
static char glowa3[44];


void wczytajDoTablicy();

void drukuj(char stan[]);

#endif /* GRAFIKA_H*/
