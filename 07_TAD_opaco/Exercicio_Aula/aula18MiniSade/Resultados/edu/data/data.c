#include <stdio.h>
#include <stdlib.h>
#include "data.h"

struct Data
{
    int *day;
    int *month;
    int *year;

};

tData* leData()
{
    tData* date = (tData*) malloc(sizeof(tData));

    int day,month,year;
    scanf("%d/%d/%d\n",&day,&month,&year);

    date->day = (int*) malloc(sizeof(int));
    date->month = (int*) malloc(sizeof(int));
    date->year = (int*) malloc(sizeof(int));

    *date->day = day;
    *date->month = month;
    *date->year = year;

    return date;
}


void printData(tData* d)
{
    printf("%02d/%02d/%d",*d->day,*d->month,*d->year);
}

int retornaAno(tData* inicio)
{
    int idade = 2026 - *inicio->year;

    if(*inicio->month<4)
        idade--;

    else if(*inicio->month==4)
    {
        if(*inicio->day<=11)
            idade--;
    }

    return idade;

}

void liberaData(tData *d)
{
    free(d->day);
    free(d->month);
    free(d->year);

    free(d);
}