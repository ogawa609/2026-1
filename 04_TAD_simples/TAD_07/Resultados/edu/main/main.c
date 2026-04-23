#include <stdio.h>
#include "data.h"

int main()
{
    int d1,m1,a1,d2,m2,a2;

    scanf("%d/%d/%d",&d1,&m1,&a1);
    scanf("%d/%d/%d",&d2,&m2,&a2);

    tData data1 = CriaData(d1,m1,a1);
    tData data2 = CriaData(d2,m2,a2);


    int v1 = VerificaDataValida(data1);
    int v2 = VerificaDataValida(data2);

    if(!v1||!v2)
    {
        printf("A primeira e/ou segunda data(s) invalida(s)");
        return 0;
    }

    printf("Primeira data: ");
    ImprimeDataExtenso(data1);
    printf("Segunda data: ");
    ImprimeDataExtenso(data2);

    int compara = ComparaData(data1,data2);

    if(compara==0)
        printf("As datas sao iguais\n");
    else if(compara==1)
        printf("A segunda data eh mais antiga\n");
    else
        printf("A primeira data eh mais antiga\n");


    int diferencaDias = CalculaDiferencaDias(data1,data2);
    printf("A diferenca em dias entre as datas eh: %02d dias",diferencaDias);

    return 0;
}