#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "van.h"

struct Van
{
     char* placa;
    char* nome;
    char* marca;
    TipoAssinatura restricaoAssinatura;
    TipoUsuario restricaoUsuario;
    int anoFabricacao;
    float quilometragem;
    int qntAssentos;

    int realizaViagensFretadas;

    float notaMedia;
};


tVan *criaVan(char *linha)
{
    tVan* v = malloc(sizeof(tVan));

     char *str;
    int tam;

   

    str = strtok(linha, ";");
    while (*str == ' '||*str=='#') 
        str++;

    tam = strlen(str) + 1;
    v->placa = malloc(tam);
    strcpy(v->placa, str);


    str = strtok(NULL, ";");
    while (*str == ' ') 
        str++;

    tam = strlen(str) + 1;
    v->nome = malloc(tam);
    strcpy(v->nome, str);


    str = strtok(NULL, ";");
    while (*str == ' ') 
        str++;

    tam = strlen(str) + 1;
    v->marca = malloc(tam);
    strcpy(v->marca, str);


    str = strtok(NULL, ";");
    while (*str == ' ') 
        str++;

    if (atoi(str))
        v->restricaoAssinatura = PREMIUM;
    else
        v->restricaoAssinatura = PADRAO;


    str = strtok(NULL, ";");
    while (*str == ' ') 
        str++;

    if (atoi(str))
        v->restricaoUsuario = ADULTO;
    else
        v->restricaoUsuario = INFANTIL;


    str = strtok(NULL, ";");
    while (*str == ' ') 
        str++;

    v->anoFabricacao = atoi(str);


    str = strtok(NULL, ";");
    while (*str == ' ')
        str++;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ',')
            str[i] = '.';
    }

    v->quilometragem = atof(str);


    str = strtok(NULL, ";");
    while (*str == ' ') 
        str++;

    v->qntAssentos = atoi(str);

    str = strtok(NULL, ";");
    while (*str == ' ') 
        str++;

    v->realizaViagensFretadas = atoi(str);

    v->notaMedia = 0;

    return v;

}


void liberaVan(void *dado)
{
    tVan* v = (tVan*) dado;
    free(v->marca);
    free(v->nome);
    free(v->placa);
    free(v);
}


int getAnoVan(void *dado)
{
    tVan* v = (tVan*) dado;
    return v->anoFabricacao;
}


char *getCodVan(void *dado)
{
    tVan* v = (tVan*) dado;
    return v->placa;
}


char *getNomeVan(void *dado)
{
    tVan* v = (tVan*) dado;
    return v->nome;
}


int getAssentosVan(void *dado)
{
    tVan* v = (tVan*) dado;
    return v->qntAssentos;
}


float getKmVan(void *dado)
{
    tVan* v = (tVan*) dado;
    return v->quilometragem;
}


char *getMarcaVan(void *dado)
{
    tVan* v = (tVan*) dado;
    return v->marca;
}

float getNotaMediaVan(void *dado)
{
    tVan* v = (tVan*) dado;
    return v->notaMedia;
}


TipoAssinatura getRestricaoAssinaturaVan(void *dado)
{
    tVan* v = (tVan*) dado;
    return v->restricaoAssinatura;
}


TipoUsuario getRestricaoIdadeVan(void *dado)
{
    tVan* v = (tVan*) dado;
    return v->restricaoUsuario;
}


char getLetraTipoVan(void)
{
    return 'V';
}


void printaVan(void *dado)
{
    tVan* v = (tVan*) dado;
    printf("VAN %s; %s; ",v->placa,v->nome);
}

void atualizaNumeroAssentosVan(void* v,int novoNumero)
{
    tVan* van = (tVan*) v;

    van->qntAssentos = novoNumero;
}