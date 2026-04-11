
#ifndef _PACIENTE_H
#define _PACIENTE_H

#include "lesao.h"
#include "data.h"
#include "constantes.h"

//definicao struct tPaciente
typedef struct
{
    char nomePaciente[MAX_TAM_NOME];
    tData nascimentoPaciente;
    char susPaciente[MAX_TAM_SUS];
    char generoPaciente;
    tLesao lesoesPaciente[MAX_TAM_LES];
    int qtdLesoesPaciente;
}tPaciente;

tPaciente lePaciente();
void printPaciente(tPaciente p);
void obtemCartaoSusPaciente(tPaciente p, char cartaoSus[]);
tPaciente insereLesaoPaciente(tPaciente p, tLesao les);
void obtemLesoesPaciente(tPaciente p, tLesao *saida, int qtdLesoes);
int obtemIdadePaciente(tPaciente p);
int obtemQuatidadeLesoesPaciente(tPaciente p);

#endif
