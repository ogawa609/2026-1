#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "moto.h"

struct Moto{
    char* placa;
    char* nome;
    char* marca;
    TipoAssinatura restricaoAssinatura;
    TipoUsuario restricaoUsuario;
    int anoFabricacao;
    float quilometragem;
    int qntAssentos;

    char* condicoesPneus;
    int bagageiro;

    float notaMedia;
};

tMoto *criaMoto(char *linha)
{
    tMoto* m = malloc(sizeof(tMoto));

     char *str;
    int tam;

   

    str = strtok(linha, ";");
    while (*str == ' '||*str=='#') 
        str++;

    tam = strlen(str) + 1;
    m->placa = malloc(tam);
    strcpy(m->placa, str);


    str = strtok(NULL, ";");
    while (*str == ' ') 
        str++;

    tam = strlen(str) + 1;
    m->nome = malloc(tam);
    strcpy(m->nome, str);


    str = strtok(NULL, ";");
    while (*str == ' ') 
        str++;

    tam = strlen(str) + 1;
    m->marca = malloc(tam);
    strcpy(m->marca, str);


    str = strtok(NULL, ";");
    while (*str == ' ') 
        str++;

    if (atoi(str))
        m->restricaoAssinatura = PREMIUM;
    else
        m->restricaoAssinatura = PADRAO;


    str = strtok(NULL, ";");
    while (*str == ' ') 
        str++;

    if (atoi(str))
        m->restricaoUsuario = ADULTO;
    else
        m->restricaoUsuario = INFANTIL;


    str = strtok(NULL, ";");
    while (*str == ' ') 
        str++;

    m->anoFabricacao = atoi(str);


    str = strtok(NULL, ";");
    while (*str == ' ')
        str++;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ',')
            str[i] = '.';
    }

    m->quilometragem = atof(str);


    str = strtok(NULL, ";");
    while (*str == ' ') 
        str++;

    m->qntAssentos = atoi(str);

    tam = strlen(str) + 1;
    m->condicoesPneus = malloc(tam);
    strcpy(m->condicoesPneus, str);


    str = strtok(NULL, ";");
    while (*str == ' ')
         str++;

    m->bagageiro = atoi(str);

    m->notaMedia = 0;

    return m;
}


void liberaMoto(void *dado)
{
    tMoto* m = (tMoto*) dado;
    free(m->condicoesPneus);
    free(m->marca);
    free(m->nome);
    free(m->placa);
    free(m);
}


int getAnoMoto(void *dado)
{
    tMoto* m = (tMoto*) dado;
    return m->anoFabricacao;
}


char *getCodMoto(void *dado)
{
    tMoto* m = (tMoto*) dado;
    return m->placa;
}


char *getNomeMoto(void *dado)
{
    tMoto* m = (tMoto*) dado;
    return m->nome;
}


int getAssentosMoto(void *dado)
{
    tMoto* m = (tMoto*) dado;
    return m->qntAssentos;
}


float getKmMoto(void *dado)
{
    tMoto* m = (tMoto*) dado;
    return m->quilometragem;
}


char *getMarcaMoto(void *dado)
{
    tMoto* m = (tMoto*) dado;
    return m->marca;
}

float getNotaMediaMoto(void *dado)
{
    tMoto* m = (tMoto*) dado;
    return m->notaMedia;
}


TipoAssinatura getRestricaoAssinaturaMoto(void *dado)
{
    tMoto* m = (tMoto*) dado;
    return m->restricaoAssinatura;
}


TipoUsuario getRestricaoIdadeMoto(void *dado)
{
    tMoto* m = (tMoto*) dado;
    return m->restricaoUsuario;
}


char getLetraTipoMoto(void)
{
    return 'M';
}


void printaMoto(void *dado)
{
     tMoto* m = (tMoto*) dado;
    printf("MOTO %s; %s; ",m->placa,m->nome);
}