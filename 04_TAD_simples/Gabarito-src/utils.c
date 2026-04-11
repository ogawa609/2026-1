#include "utils.h"

void associaLesaoPaciente(tPaciente *pacs, int qtdPacientes, tLesao les)
{
    char cartaoSusLesao[MAX_TAM_SUS];
    obtemCartaoSusLesao(les, cartaoSusLesao);

    for(int i=0; i<qtdPacientes; i++)
    {
        char cartaoSusPaciente[MAX_TAM_SUS];
        obtemCartaoSusPaciente(pacs[i], cartaoSusPaciente);

        if(strcmp(cartaoSusLesao, cartaoSusPaciente) == 0)
            pacs[i] = insereLesaoPaciente(pacs[i], les);
    }
}