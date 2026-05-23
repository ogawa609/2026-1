#include <stdio.h>
#include <stdlib.h>
#include "data.h"

/*
Primeira data: 29 de Agosto de 2023
Segunda data: 25 de Dezembro de 2023
int compara A primeira data eh mais antiga
A diferenca em dias entre as datas eh: 118 dias*/

int main()
{
    tData *data1 = CriaData();
    LeData(data1);

    tData* data2 = CriaData();
    LeData(data2);

    if(!VerificaDataValida(data1)||!VerificaDataValida(data2))
    {
        printf("A primeira e/ou segunda data(s) invalida(s)");
        LiberaData(data1);
        LiberaData(data2);
        return 0;
    }

    printf("Primeira data: ");
    ImprimeDataExtenso(data1);

    printf("Segunda data: ");
    ImprimeDataExtenso(data2);

    int compara = ComparaData(data1,data2);

    if(compara==-1)
        printf("A primeira data eh mais antiga\n");

    else if(compara==1)
        printf("A segunda data eh mais antiga\n");
    else
        printf("As datas sao iguais\n");

    printf("A diferenca em dias entre as datas eh: %02d dias\n",CalculaDiferencaDias(data1,data2));

        LiberaData(data1);
        LiberaData(data2);
        return 0;
}