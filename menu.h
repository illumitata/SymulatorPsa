#ifndef MENU_H
#define MENU_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "symulator.h"
#include "menu.h"
#include "getch.h"

int menu(struct Pupil* pies, struct Zapis* zapis);

void menuGry(int poz);

#endif /* !MENU_H */
