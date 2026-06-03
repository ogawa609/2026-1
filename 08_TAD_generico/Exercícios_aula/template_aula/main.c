#include "array.h"
#include <stdio.h>
#include <stdlib.h>

//impressões
void imprimeInt(void *dado)
{
    printf("%d ", *(int*)dado);
}

void imprimeFloat(void *dado)
{
    printf("%.2f ", *(float*)dado);
}

void imprimeChar(void *dado)
{
    printf("%c ", *(char*)dado);
}

void imprimeString(void *dado)
{
    printf("%s ", (char*)dado);
}

//liberações
void liberaInt(void *dado)
{
    free((int*)dado);
}

void liberaFloat(void *dado)
{
    free((float*)dado);
}

void liberaChar(void *dado)
{
    free((char*)dado);
}

void liberaString(void *dado)
{
    free((char*)dado);
}

int main()
{
    int tipo;
    int tam = 0;
    tArray **a = criaArray();

    while(1)
    {
       

    }

    imprimeArray(a, tam);
    desalocaArray(a, tam);
    return 0;
}
