#include <stdio.h>
#include <stdlib.h>
#include "corrida.h"
#include "veiculo.h"
#include "data.h"


struct Corrida{
    tVeiculo* veiculo;
    int duracao;
    char* origem;
    char* destino;
    tData* dataMarcacao;
    int qntAssentos;
};

