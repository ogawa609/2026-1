
#ifndef _LESAO_H
#define _LESAO_H

#include "constantes.h"

//definicao struct tLesao
typedef struct
{
    char cartaoSus[MAX_TAM_SUS];
    char idLesao[MAX_TAM_ID];
    char diagnostico[MAX_TAM_DIAG];
    char regiaoCorpo[MAX_TAM_REGIAO];
    int malignidade;
}tLesao;


tLesao leLesao();
void printLesao(tLesao *les, int qtdLesoes);
void obtemCartaoSusLesao(tLesao les, char cartaoSus[]);
int chanceCirirgiaLesao(tLesao les);


#endif
