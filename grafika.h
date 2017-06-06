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

static char *miska;
static char *woda;
static char *spacer;
static char *lekarz;
static char *noc;

void wczytajDoTablic();

int drukujEkran(int ekran);     //zwraca przyspieszone tępo na jedno odświeżenie

void drukuj(int warunek);

void uwolnijGrafiki();

#endif /* GRAFIKA_H*/
