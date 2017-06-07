#ifndef ZAPIS_H
#define ZAPIS_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include "symulator.h"
#include "zapis.h"

void zapiszGre(struct Pupil* pies,int dzien,int godzina);

struct Zapis* wczytajGre(struct Zapis* zapis);

#endif /*ZAPIS_H*/
