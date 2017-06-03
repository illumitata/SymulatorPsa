//Drukowanie menu startowego gry

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "symulator.h"
#include "menu.h"

struct Pupil* stworzPsa(struct Pupil* pies){

    system("clear");

    printf("\n\t\tWitaj w kreatorze swojego wirtualnego zwierzaka!\n\n");

    printf("\n\t\tPodaj imię dla swojego pupila: ");
    scanf("%s", pies->imie);

    system("clear");

            pies->glod = 100;
            pies->prag = 100;
            pies->zdro = 100;
            pies->zado = 100;

    system("clear");

    printf("\n\t\tWygląda na to, że %s pojawił się już w domu. Opiekuj się nim!\n", pies->imie);

    sleep(4);

    return pies;
}

int menu(struct Pupil* pies){
  short int decyzja;
  system("clear");

  printf("\n\t\t\t\t\t 1 . [[ Nowa  gra ]]\n");
  printf("\n\t\t\t\t\t 2 . [[ Kontynuuj ]]\n");
  printf("\n\t\t\t\t\t 3 . [[   Wyjdź   ]]\n");

  printf("\n\n\n\n\n");
  printf("\n\t\t\t\t\t   Wybierz opcje: ");
  scanf("%hd",&decyzja);

  //    sleep(1);

  switch(decyzja){
      case 1:
          stworzPsa(pies);
          break;
      case 2:
          //wczytanie psa
      case 3:
          exit(1);                      //zabija program
          break;
      default:
          menu(pies);
  }

  system("clear");
  
  return 0;
}
