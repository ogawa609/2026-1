#ifndef _CORRIDA_H
#define _CORRIDA_H

#include "data.h"
#include "veiculo.h"
#include "motorista.h"

typedef struct Corrida tCorrida;
tCorrida* CriaCorrida(tVeiculo* veiculo, tMotorista* d, int duracao, char* origem, char* destino, tData* dataMarcacao, int qntAssentos);
void LiberaCorrida(tCorrida *dado);
void ImprimeCorrida(tCorrida* c,int indice);
int getTempoCorrida(tCorrida* c);
tVeiculo* getVeiculoCorrida(tCorrida* c);
tMotorista* getMotoristaCorrida(tCorrida* c);
char* getOrigemCorrida(tCorrida* c);
char* getDestinoCorrida(tCorrida* c);
#endif