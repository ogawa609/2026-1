#include <stdio.h>
#include "data.h"


tData leData()
{
    tData d;
    int dia,mes,ano;
    scanf("%d/%d/%d\n",&dia,&mes,&ano);
    d.dia=dia;
    d.mes=mes;
    d.ano=ano;
    return d;
}

void printData(tData d)
{
    printf("%d/%d/%d",d.dia,d.mes,d.ano);
}

int retornaAno(tData inicio)
{
    tData hj={11,4,2026};

    int idade= hj.ano-inicio.ano;

        if(hj.mes==inicio.mes)
        {
            if(hj.dia<inicio.dia)
                idade--;
        }
        else if(hj.mes<inicio.mes)
            idade--;
            
    return idade;
}