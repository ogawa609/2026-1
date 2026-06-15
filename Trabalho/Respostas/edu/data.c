#include <stdio.h>
#include <stdlib.h>
#include "data.h"


struct Data{

    int dia,mes,ano;
};

tData* CriaData(int dia,int mes,int ano)
{
    tData* data = malloc(sizeof(tData));

    data->ano = ano;
    data->dia = dia;
    data->mes = mes;

    return data;
}

void LiberaData(tData* data)
{
    free(data);
}

