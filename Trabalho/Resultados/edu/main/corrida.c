#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    tMotorista* motorista;
};

tCorrida* CriaCorrida(tVeiculo* veiculo,tMotorista* d, int duracao, char* origem, char* destino, tData* dataMarcacao, int qntAssentos)
{ 
    tCorrida* c = malloc(sizeof(tCorrida));

    c->duracao = duracao;
    c->veiculo = veiculo;
    c->qntAssentos = qntAssentos;
    c->dataMarcacao = dataMarcacao;

    int tam = strlen(origem) + 1;
    c->origem = malloc(tam * sizeof(char));
    strcpy(c->origem,origem);

    tam = strlen(destino) + 1;
    c->destino = malloc(tam * sizeof(char));
    strcpy(c->destino,destino);
    c->motorista = d;

    return c;
}
void LiberaCorrida(void*dado)
{
    tCorrida* c = (tCorrida*) dado;

    free(c->destino);
    free(c->origem);
    LiberaData(c->dataMarcacao);
    
    free(c);
}

int getTempoCorrida(tCorrida* c)
{
    return c->duracao;
}
//NUMERO - VEICULO #ID; NOME; DURACAO; ORIGEM; DESTINO; DATA DE MARCACAO (DD/MM/AAA); QUANTIDADE DE ASSENTOS REQUISITADOS
//1 - CARRO #ABCDEF123; GOL G5; 00:27; AVENIDA FERNANDO FERRARRI 001; AVENIDA DANTE MICHELIN 002; 10/04/2025; 2
void ImprimeCorrida(tCorrida* c,int indice)
{
    printf("%d - ",indice);
    printaVeiculo(c->veiculo);
    imprimeDuracaoCorrida(c->duracao);
    printf("; %s; %s; ",c->origem,c->destino);
    ImprimeData(c->dataMarcacao);
    printf("; %d\n",c->qntAssentos);

}

tVeiculo* getVeiculoCorrida(tCorrida* c)
{
    return c->veiculo;
}

tMotorista* getMotoristaCorrida(tCorrida* c)
{
    return c->motorista;
}

char* getOrigemCorrida(tCorrida* c)
{
    return c->origem;
}
char* getDestinoCorrida(tCorrida* c)
{
    return c->destino;
}

