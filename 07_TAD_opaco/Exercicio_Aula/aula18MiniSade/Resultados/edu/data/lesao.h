
#ifndef _LESAO_H
#define _LESAO_H

#include "constantes.h"

//definicao struct tLesao
typedef struct Lesao tLesao;

tLesao *leLesao();
void printLesao(tLesao **les, int qtdLesoes);
void obtemCartaoSusLesao(tLesao *les, char cartaoSus[]);
int chanceCirirgiaLesao(tLesao *les);
void liberaLesao(tLesao *les);


#endif
