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

      int powrot = 0;
      int wyjdz  = 0;

      do{
        powrot = getche();
        if(powrot!=0){
          wyjdz = 1;
          fflush(stdin);
        }
      }while(wyjdz != 1);

      return;
}


void menuGry(int poz){

  puts("Strzałka wskazuje wybór(sterowanie klawiaturą):");
  if(poz==1) printf(" > ");
  puts("1 - nakarm zwierzaka.");

  if(poz==2) printf(" > ");
  puts("2 - daj wodę zwierzakowi.");

  if(poz==3) printf(" > ");
  puts("3 - wyjdź na spacer lub pobaw się.");

  if(poz==4) printf(" > ");
  puts("4 - wycieczka do weterynarza lub pielęgnacja.");

  if(poz==5) printf(" > ");
  puts("5 - wyjdź z symulatora.");

  return;
}

int menu(struct Pupil* pies, struct Zapis* zapis){
  int decyzja = 1;
  int wyborMenu;
  int komendaMenu;
  int sygnalMenu = 0;

  while(sygnalMenu!=1){

      system("clear");

      puts("\t\t|||||||||||||||||||");
      printf("\n\t\t");
      if(decyzja==1) printf("  > ");
      puts("[[ Nowa  gra ]]");
      printf("\n\t\t");
      if(decyzja==2) printf("  > ");
      puts("[[ Kontynuuj ]]");
      printf("\n\t\t");
      if(decyzja==3) printf("  > ");
      puts("[[   Pomoc   ]]");
      printf("\n\t\t");
      if(decyzja==4) printf("  > ");
      puts("[[   Wyjdź   ]]");
      puts("\n\t\t|||||||||||||||||||");
      printf("\n\n");

      puts("\t\tWybierz strzałkami");

      if(wyborMenu != '\0') komendaMenu = wyborMenu;      //WAŻNA KOLEJNOŚĆ TYCH KOMEND

      wyborMenu = getche();

      if(wyborMenu==10){                          //jeśli ENTER zatwierdza wybór i czyści
        sygnalMenu = 1;
        wyborMenu  = '\0';
      }

      if(wyborMenu == 27){
        komendaMenu = getche();
        if(komendaMenu==91){
          komendaMenu = getche();
          if(komendaMenu == 65 && decyzja>1) decyzja-=1;
          if(komendaMenu == 66 && decyzja<4) decyzja+=1;
        }
      }
      else wyborMenu = '\0';
  }

  switch(decyzja){
      case 1:
          fflush(stdin);
          stworzPsa(pies);
          return 1;
          break;
      case 2:
          fflush(stdin);
          wczytajGre(zapis);
          return 2;
          break;
      case 3:
          menuInstrukcje();
          menu(pies, zapis);
          break;
          /*tutaj nie było breaka i double menu, KOMPLETNIE NIEPOTRZEBNIE
          więc struktura po wyświetleniu pomocy się psuła*/
      case 4:
          free(pies);
          free(zapis);
          exit(1);                  //zabija program
          break;
      default:                      //nie powinno się zdarzyć ale na wszelki wypadek
          menu(pies, zapis);
          break;
  }

  system("clear");

  return 0;
}
