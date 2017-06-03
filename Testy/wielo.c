#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include "bbb/getch.c"
#define LINE_MAX 6

static char gowno = 0;
char buf[LINE_MAX];

void *threadFunc(void *arg){
    char *str;
    int i = 0;
    //int gowno;
    str=(char*)arg;

    while(i < 110000 )
    {
        sleep(1);

        system("clear");
        printf("main is running... %c\n",gowno);
        //fflush(stdin);
        ++i;
    }

    return NULL;
}

int main(void){
    pthread_t pth;
    int i = 0;
    fflush(stdin);

    pthread_create(&pth,NULL,threadFunc,"foo");
    while(i < 100)
    {

    sleep(1);

    gowno = getche();
    if(gowno == '\n') gowno = '\0';
    ++i;

    }

    printf("main waiting for thread to terminate...\n");
    pthread_join(pth,NULL);

    return 0;
}
