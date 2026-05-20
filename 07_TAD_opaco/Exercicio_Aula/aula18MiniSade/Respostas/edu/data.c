#include <stdio.h>
#include <stdlib.h>
#include "data.h"

struct Data
{
    int day;
    int month;
    int year;

};

tData* leData()
{
    tData* date = (tData*) malloc(sizeof(tData));

    int day,month,year;
    scanf("%d/%d/%d\n",&day,&month,&year);

    date->day = day;
    date->month = month;
    date->year = year;

    return date;
}


void printData(tData* d)
{
    printf("%02d/%02d/%d",d->day,d->month,d->year);
}

int retornaAno(tData* inicio)
{
    tData today = {3,4,2024};

    int age = today.year - inicio->year;

    if(today.month<inicio->month)
         age--;

    else if(today.month==inicio->month)
    {
        if(today.day<inicio->day)
           age--;
    }
     
    


        return age;

}

void liberaData(tData *d)
{
    
    if(d!=NULL)
        free(d);
}