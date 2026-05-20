
#ifndef _PACIENTE_H
#define _PACIENTE_H

#include "lesao.h"
#include "data.h"
#include "constantes.h"

//definicao struct tPaciente
typedef struct Paciente tPaciente;


tPaciente *lePaciente();
void printPaciente(tPaciente *p);
void obtemCartaoSusPaciente(tPaciente *p, char cartaoSus[]);
tPaciente *insereLesaoPaciente(tPaciente *p, tLesao *les);
void obtemLesoesPaciente(tPaciente *p, tLesao **saida, int qtdLesoes);
int obtemIdadePaciente(tPaciente *p);
int obtemQuatidadeLesoesPaciente(tPaciente *p);
void liberaPaciente(tPaciente *p);

#endif
