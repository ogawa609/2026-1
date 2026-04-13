#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "lesao.h"
#include "paciente.h"

void associaLesaoPaciente(tPaciente *pacs, int qtdPacientes, tLesao les)
{
    char susLesao[MAX_TAM_SUS];
    obtemCartaoSusLesao(les,susLesao);
    char susPaciente[MAX_TAM_SUS];

    for(int i=0;i<qtdPacientes;i++)
    {
        obtemCartaoSusPaciente(pacs[i],susPaciente);

        if(strcmp(susLesao,susPaciente)==0)
                pacs[i]=insereLesaoPaciente(pacs[i],les);
        
    }

}