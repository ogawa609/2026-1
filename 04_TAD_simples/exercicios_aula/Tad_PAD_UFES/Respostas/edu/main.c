#include <stdio.h>
#include "utils.h"
#include "paciente.h"


int main()
{
    tPaciente pacs[MAX_TAM_PACIENTES];
    int totalPaciente=0;
    int totalLesoes=0;
    int mediaIdade=0;
    int totalCirurgias=0;
    char comando;

    while(1)
    {

        scanf("%c\n",&comando);
        if(comando=='P')
        {
            if(totalPaciente<MAX_TAM_PACIENTES)
            {
                pacs[totalPaciente]=lePaciente();
                mediaIdade+=obtemIdadePaciente(pacs[totalPaciente]);
                totalPaciente++;
            }
        }
        else if(comando=='L')
        {
            tLesao les=leLesao();
            associaLesaoPaciente(pacs,totalPaciente,les);
        }
        else if(comando=='F')
            break;
    }

    for(int i=0;i<totalPaciente;i++)
    {
        totalLesoes+=obtemQuatidadeLesoesPaciente(pacs[i]);
        tLesao lesoes[MAX_TAM_LES];
        obtemLesoesPaciente(pacs[i],lesoes,obtemQuatidadeLesoesPaciente(pacs[i]));

        for(int j=0;j<obtemQuatidadeLesoesPaciente(pacs[i]);j++)
        {
            
            totalCirurgias+=chanceCirirgiaLesao(lesoes[j]);
        }
    }
    if(totalPaciente>0)
    {
        printf("TOTAL PACIENTES: %d\n",totalPaciente);
        printf("MEDIA IDADE (ANOS): %d\n",mediaIdade/totalPaciente);
        printf("TOTAL LESOES: %d\n",totalLesoes);
        printf("TOTAL CIRURGIAS: %d\n",totalCirurgias);
        printf("LISTA DE PACIENTES:\n");
        for(int i=0;i<totalPaciente;i++)
        {
            printPaciente(pacs[i]);
        }
    }   

    return 0;
}