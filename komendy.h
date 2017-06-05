#ifndef GRAFIKA_H
#define GRAFIKA_H

#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "symulator.h"    //plik ze strukturą zwierzaka
#include "komendy.h"

struct Pupil* dajJesc(struct Pupil* pies);

struct Pupil* dajWode(struct Pupil* pies);

struct Pupil* dajSpacer(struct Pupil* pies);

struct Pupil* dajWet(struct Pupil* pies);

#endif /* GRAFIKA_H*/
