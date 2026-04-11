#include <stdio.h>
#include <string.h>
#include "paciente.h"
/*
typedef struct
{
    char nomePaciente[MAX_TAM_NOME];
    tData nascimentoPaciente;
    char susPaciente[MAX_TAM_SUS];
    char generoPaciente;
    tLesao lesoesPaciente[MAX_TAM_LES];
    int qtdLesoesPaciente;
}tPaciente;
*/

tPaciente lePaciente()
{
    tPaciente p;
    scanf("%[^\n]\n", p.nomePaciente);
    p.nascimentoPaciente = leData();
    scanf("%s\n", p.susPaciente);
    scanf("%c\n", &p.generoPaciente);
    p.qtdLesoesPaciente = 0;
    return p;
}

void printPaciente(tPaciente p)
{
    if(p.qtdLesoesPaciente > 0)
    {
        printf("- %s - ", p.nomePaciente);
        printLesao(p.lesoesPaciente, p.qtdLesoesPaciente);
        printf("\n");
    }
}

void obtemCartaoSusPaciente(tPaciente p, char cartaoSus[])
{
    strcpy(cartaoSus, p.susPaciente);
}

tPaciente insereLesaoPaciente(tPaciente p, tLesao les)
{
    if(p.qtdLesoesPaciente == MAX_TAM_LES-1)
        printf("Máximo de lesões cadastradas!\n");
    else
    {
        p.lesoesPaciente[p.qtdLesoesPaciente] = les;
        p.qtdLesoesPaciente++;
    }
    return p;
}

void obtemLesoesPaciente(tPaciente p, tLesao *saida, int qtdLesoes)
{
    for(int i=0; i<qtdLesoes; i++)
        saida[i] = p.lesoesPaciente[i];
}

int obtemIdadePaciente(tPaciente p)
{
    return retornaAno(p.nascimentoPaciente);
}

int obtemQuatidadeLesoesPaciente(tPaciente p)
{
    return p.qtdLesoesPaciente;
}