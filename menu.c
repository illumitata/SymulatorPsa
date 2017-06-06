//Drukowanie menu startowego gry

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "symulator.h"
#include "menu.h"
#include "grafika.h"
#include "getch.h"

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

void menuInstrukcje(){

      system("clear");
      printf("Twoj pies może wyglądać w następujący sposób: \n\n");
      drukuj(2);
      printf("\n\t\tTwój pies najedzony, napity, wypoczęty.\n");
      drukuj(7);
      printf("\n\t\tTwój pies zgłodniał, potrzebuje wody lub musi wyjść na spacer.\n");
      drukuj(12);
      printf("\n\t\tJesteś blisko przegranej, lepiej zacznji zajmować się swoim pupilem.\n" );
      printf("\n\n(Wciśnij dowolny przycisk żeby wrócić do menu)\n");

      char powrot = '\0';
      char wyjdz  = '\0';

      do{
        if(powrot==10) wyjdz ='\n';
        powrot = getche();
      }while(wyjdz == '\0');

      return;
}


void menuGry(){

  puts("Wpisz i zatwierdź enterem:");
  puts("1 - nakarm zwierzaka.");
  puts("2 - daj wodę zwierzakowi.");
  puts("3 - wyjdź na spacer lub pobaw się.");
  puts("4 - wycieczka do weterynarza lub pielęgnacja.");
  puts("5 - wyjdź z symulatora.");

}

int menu(struct Pupil* pies){
  short int decyzja;
  system("clear");
  system("clear");

  printf("\n\t\t|||||||||||||||||||\n");
  printf("\n\t\t1 . [[ Nowa  gra ]]\n");
  printf("\n\t\t2 . [[ Kontynuuj ]]\n");
  printf("\n\t\t3 . [[   Pomoc   ]]\n");
  printf("\n\t\t4 . [[   Wyjdź   ]]\n");
  printf("\n\t\t|||||||||||||||||||\n");
  printf("\n\n");
  printf("\n\t\t Wybierz opcje: ");
  scanf("%hd",&decyzja);

  switch(decyzja){
      case 1:
          stworzPsa(pies);
          break;
      case 2:
          //wczytanie psa
      case 3:
          menuInstrukcje();
          menu(pies);
          break;
          /*tutaj nie było breaka i double menu, KOMPLETNIE NIEPOTRZEBNIE
          więc struktura po wyświetleniu pomocy się psuła*/
      case 4:
          free(pies);
          exit(1);                  //zabija program
          break;
      default:
          menu(pies);
          break;
  }

  system("clear");

  return 0;
}
