#include <stdio.h>
#include "paciente.h"
#include "lesao.h"
#include "utils.h"

int main()
{
    tPaciente pacientes[MAX_TAM_PACIENTES];
    int qtdPacientes = 0;

    //Leituras
    while(1)
    {
        char tipo;
        scanf("%c\n", &tipo);

        if(tipo == 'F')
            break;
        else
            if(tipo == 'P')
            {
                pacientes[qtdPacientes] = lePaciente();
                qtdPacientes++;
            }
            else
            {
                tLesao l = leLesao();
                associaLesaoPaciente(pacientes, qtdPacientes, l);
            }
    }

    //Estatísticas e impressões
    if(qtdPacientes > 0)
    {
        printf("TOTAL PACIENTES: %d\n", qtdPacientes);
        int mediaIdade = 0;
        int totalCirurgias = 0;
        int totalLesoes = 0;
        for(int i=0; i<qtdPacientes; i++)
        {
            mediaIdade+= obtemIdadePaciente(pacientes[i]);
            totalLesoes+= obtemQuatidadeLesoesPaciente(pacientes[i]);

            int qtdLesoesPaciente = obtemQuatidadeLesoesPaciente(pacientes[i]);
            tLesao lesoesPaciente[MAX_TAM_LES];
            obtemLesoesPaciente(pacientes[i],lesoesPaciente, qtdLesoesPaciente);
            for(int j=0; j<qtdLesoesPaciente; j++)
                totalCirurgias+= chanceCirirgiaLesao(lesoesPaciente[j]);
            
        }
        printf("MEDIA IDADE (ANOS): %d\n", mediaIdade/qtdPacientes);
        printf("TOTAL LESOES: %d\n", totalLesoes);
        printf("TOTAL CIRURGIAS: %d\n", totalCirurgias);

        printf("LISTA DE PACIENTES: \n");
        for(int i=0; i<qtdPacientes; i++)
            printPaciente(pacientes[i]);
    }
    return 0;
}