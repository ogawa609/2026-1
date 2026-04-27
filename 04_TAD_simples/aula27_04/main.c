#include "vetgenerico.h"
#include <stdio.h>


void imprimeInt(void* dado)
{
    printf("%d ",*(int*)dado);
}

void imprimeFLoat(void* dado)
{
    printf("%.2f ",*(float*)dado);
}

void imprimeString(void* dado)
{
    printf("%s ",(char*)dado);
}


int main()
{
    int tipo,dadoI;
    float dadoF;
    char dadoS[MAX_STR];
    tDado dadosGen[MAX_DADOS_G];
    int qnt=0;

    scanf("%d\n",&tipo);

    while(tipo!=OUT)
    {

        if(tipo == INT)
        {
            scanf("%d\n",&dadoI);
            dadosGen[qnt] = leDadoGenerico(&dadoI, imprimeInt);
            qnt++;
        }
        else if(tipo == FLOAT)
        {
            scanf("%f\n",&dadoF);
            dadosGen[qnt] = leDadoGenerico(&dadoF,imprimeFLoat);
            qnt ++;
        }
        else
        {
            scanf("%s\n",dadoS);
            dadosGen[qnt] = leDadoGenerico(dadoS,imprimeString);
            qnt ++;
        }
    }

}
