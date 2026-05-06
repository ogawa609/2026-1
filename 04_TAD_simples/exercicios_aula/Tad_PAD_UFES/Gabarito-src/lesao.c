#include <stdio.h>
#include <string.h>
#include "lesao.h"

/*
typedef struct
{
    char cartaoSus[MAX_TAM_SUS];
    char idLesao[MAX_TAM_ID];
    char diagnostico[MAX_TAM_DIAG];
    char regiaoCorpo[MAX_TAM_REGIAO];
    int malignidade;
}tLesao;
*/

tLesao leLesao()
{
    tLesao l;
    scanf("%s\n", l.cartaoSus);
    scanf("%s\n", l.idLesao);
    scanf("%[^\n]\n", l.diagnostico);
    scanf("%[^\n]\n", l.regiaoCorpo);
    scanf("%d\n", &l.malignidade);
    return l;
}

void printLesao(tLesao *les, int qtdLesoes)
{
    for(int i=0; i<qtdLesoes; i++)
        printf("%s ", les[i].idLesao);
}

void obtemCartaoSusLesao(tLesao les, char cartaoSus[])
{
    strcpy(cartaoSus, les.cartaoSus);
}

int chanceCirirgiaLesao(tLesao les)
{
    return (les.malignidade > 50);
}