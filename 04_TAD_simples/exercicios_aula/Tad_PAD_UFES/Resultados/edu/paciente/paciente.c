#include <stdio.h>
#include <string.h>
#include "paciente.h"
#include "data.h"

tPaciente lePaciente()
{
    tPaciente p;

    scanf("%[^\n]\n",p.nomePaciente);
    p.nascimentoPaciente=leData();
    scanf("%s\n",p.susPaciente);
    scanf("%c\n",&p.generoPaciente);
    p.qtdLesoesPaciente=0;

    return p;
}


void printPaciente(tPaciente p)
{
    if(p.qtdLesoesPaciente>0)
    {
        printf("- %s - ",p.nomePaciente);
        printLesao(p.lesoesPaciente,p.qtdLesoesPaciente);
        printf("\n");
    }
}


void obtemCartaoSusPaciente(tPaciente p, char cartaoSus[])
{
    strcpy(cartaoSus,p.susPaciente);
}

tPaciente insereLesaoPaciente(tPaciente p, tLesao les)
{
    if(p.qtdLesoesPaciente<MAX_TAM_LES)
    {
        p.lesoesPaciente[p.qtdLesoesPaciente]=les;
        p.qtdLesoesPaciente++;
    }
    return p;
}


void obtemLesoesPaciente(tPaciente p, tLesao *saida, int qtdLesoes)
{
    for(int i=0;i<qtdLesoes;i++)
    {
        saida[i]=p.lesoesPaciente[i];
    }
}

int obtemIdadePaciente(tPaciente p)
{
    return retornaAno(p.nascimentoPaciente);
}


int obtemQuatidadeLesoesPaciente(tPaciente p)
{
    return p.qtdLesoesPaciente;
}