#include <stdio.h>
#include "vetor.h"

/*
Soma: 55
Produto: 3628800
*/
int Adicao(int a,int b)
{
    return a+b;
}

int Mult(int a, int b)
{
    return a*b;
}

int main()
{
    Vetor vetor;
    LeVetor(&vetor);

    printf("Soma: %d\n",AplicarOperacaoVetor(&vetor,Adicao));
    printf("Produto: %d\n",AplicarOperacaoVetor(&vetor,Mult));

    return 0;
}