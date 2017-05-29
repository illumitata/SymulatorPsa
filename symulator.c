//Symulator Psa - Jan Iwaszkiewicz, Krzysztof Józefczyk

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

//#include "pies.h"

static int dzien = 0;

typedef struct Pupil{
  char       imie[30];      //imię psa
  char       glod;          //glod
  char       prag;          //pragnienie
  char       zdro;          //zdrowie
  char       zado;          //zadowolenie
} Pupil;

struct Pupil* stworzPsa(struct Pupil* pies){

    system("clear");

    printf("\n\t\tWitaj w kreatorze swojego wirtualnego zwierzaka!\n\n");

    printf("\n\t\tPodaj imię dla swojego pupila: ");
    scanf("%s", pies->imie);
//    sleep(1);                   //wartość w sekundach
    system("clear");

            pies->glod = 100;
            pies->prag = 100;
            pies->zdro = 100;
            pies->zado = 100;

    return pies;
}

void drukujPsa(char* nazwa){

  char znak = 0;

  FILE *fp = fopen(nazwa, "r");

  do{
    znak = fgetc(fp);
    if(znak != EOF) printf("%c", znak);             //Dlaczego lol?
  }while(znak!=EOF);

  printf("\n\n");

  fclose(fp);

  return;
}

void nowyDzien(struct Pupil* pies){

  system("clear");
  int skun;

  if(dzien==0) printf("\n\t\t\tTwój pies %s właśnie pojawił się w domu.\n\n\n", pies->imie);


  drukujPsa("ASCII_ART/stan1.txt");

  printf(" Sztuczny %s\n", pies->imie);
//
  printf(" Głód %hd\n", pies->glod);
  printf(" Prag %hd\n", pies->prag);
  printf(" zdro %hd\n", pies->zdro);
  printf(" nast %hd\n", pies->zado);
  scanf("%d", &skun);
  sleep(2);

  pies->glod = pies->glod - 10;


  if(skun==1) pies->zdro = pies->zdro + 10;
  nowyDzien(pies);

  return;
}

int main(){
    short int decyzja;
    system("clear");
    struct Pupil *pies = malloc(sizeof(Pupil));

    printf("\n\t\t\t\t\t 1 . [[ Nowa  gra ]]\n");
    printf("\n\t\t\t\t\t 2 . [[  Zamknji  ]]\n");

    printf("\n\n\n\n\n");
    printf("\n\t\t\t\t\t   Wybierz opcje: ");
    scanf("%hd",&decyzja);

//    sleep(1);

    switch(decyzja){
        case 1:
            pies = stworzPsa(pies);
            nowyDzien(pies);
/*
            drukujPsa("ASCII_ART/stan1.txt");
            printf(" Sztuczny %s\n", pies->imie);
//
            printf(" Głód %hd\n", pies->glod);
            printf(" Prag %hd\n", pies->prag);
            printf(" zdro %hd\n", pies->zdro);
            printf(" nast %hd\n", pies->zado);
//
*/
        case 2:
            return 0;
            break;
        default:
            main();
    }

    system("clear");

    return 0;
}
