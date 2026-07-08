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

void LiberaCorrida(tCorrida *dado)
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

void ImprimeCorrida(tCorrida* c,int indice)
{
    printf("%d - ",indice);
    
    char tip = getTipoVeiculoLetra(c->veiculo);

    if(tip=='C')
             printf("CARRO #%s; %s; ",getCodVeiculo(c->veiculo),getNomeVeiculo(c->veiculo));
    else if(tip=='M')
            printf("MOTO #%s; %s; ",getCodVeiculo(c->veiculo),getNomeVeiculo(c->veiculo));
    else if(tip=='V')
            printf("VAN #%s; %s; ",getCodVeiculo(c->veiculo),getNomeVeiculo(c->veiculo));

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

