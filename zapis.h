#ifndef ZAPIS_H
#define ZAPIS_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include "symulator.h"
#include "zapis.h"

void zapiszGre(struct Pupil* pies,int dzien,int godzina);

struct Pupil* wczytajGre(struct Pupil* pies, int dzien, int godzina);

#endif /*ZAPIS_H*/
