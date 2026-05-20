#include <stdio.h>
#include <string.h>
#include "lesao.h"
#include <stdlib.h>

struct Lesao
{
    char cartaoSus[MAX_TAM_SUS];
    char id[11];
    char diagnostico[101];
    char regiao[101];
    int malignidade;
};

tLesao *leLesao()
{
    tLesao* les = (tLesao*) malloc(sizeof(tLesao));
    
    scanf("%s\n",les->cartaoSus);
    scanf("%s\n",les->id);
    scanf("%[^\n]\n",les->diagnostico);
    scanf("%[^\n]\n",les->regiao);
    scanf("%d",&les->malignidade);

    return les;
}


void printLesao(tLesao **les, int qtdLesoes)
{
    for(int i=0;i<qtdLesoes;i++)
    {
        printf("%s ",les[i]->id);

    }
    
}
void obtemCartaoSusLesao(tLesao *les, char cartaoSus[])
{
    strcpy(cartaoSus,les->cartaoSus);
}

int chanceCirirgiaLesao(tLesao *les)
{
    if(les->malignidade <= 50)
        return 0;
    return 1;
}
void liberaLesao(tLesao *les)
{
    free(les);
}