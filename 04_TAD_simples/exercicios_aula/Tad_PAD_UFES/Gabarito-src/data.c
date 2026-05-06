#include <stdio.h>
#include "data.h"

tData leData()
{
    tData d;
    scanf("%d/%d/%d\n", &d.dia, &d.mes, &d.ano);
    return d;
}

void printData(tData d)
{
    printf("%d/%d/%d\n", d.dia, d.mes, d.ano);
}

int retornaAno(tData inicio)
{
    tData final = {8, 04, 2026};

    int idade = final.ano - inicio.ano;

    if(final.mes == inicio.mes)
    {
        if(final.dia < inicio.dia)
            idade--;
    }
    else
        if(final.mes < inicio.mes)
            idade--;
    return idade;
}
