#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lesao.h"
#include "data.h"
#include "paciente.h"
/*
TOTAL PACIENTES: 4
MEDIA IDADE (ANOS): 29
TOTAL LESOES: 3
TOTAL CIRURGIAS: 2
LISTA DE PACIENTES:
- TRISTANA - L8 
- LUCIAN - L2 
- LUX - L100 */
int main()
{
    Paciente** pacientes = malloc(sizeof(Paciente*));
    int qnt = 0;
    int mediaIdade = 0;
    int lesoes =0;
    int cirurgias =0;
    Data* data = criaData(12,9,2023);

    char op;

    while(1)
    {
        scanf("%c\n",&op);

        if(op=='P')
        {
            Paciente* pac = lerPaciente();
            pacientes[qnt] = pac;
            qnt++;
            pacientes = realloc(pacientes, (qnt+1)* sizeof(Paciente*));
        }

        else if(op=='L')
        {
            int check = 1;
            Lesao* les = lerLesao();
           
            for(int i=0;i<qnt;i++)
            {
                if(strcmp(getCartaoSusPaciente(pacientes[i]),getCartaoSusLesao(les))==0)
                {
                    vinculaLesaoPaciente(pacientes[i],les);
                    check=0;
                }
                       
            }

            if(check)
                liberaLesao(les);
        }
        else
            break;
    }

    for(int i=0;i<qnt;i++)
    {
        lesoes += getNumLesoesPaciente(pacientes[i]);
        cirurgias += qtdLesoesCirurgicasPaciente(pacientes[i]);
        mediaIdade += calculaIdadePaciente(pacientes[i],data);
    }

    printf("TOTAL PACIENTES: %d\n",qnt);
    if(qnt>0)
        printf("MEDIA IDADE (ANOS): %d\n",mediaIdade/qnt);
    else
        printf("MEDIA IDADE (ANOS): -\n");
        
    printf("TOTAL LESOES: %d\n",lesoes);
    printf("TOTAL CIRURGIAS: %d\n",cirurgias);
    printf("LISTA DE PACIENTES:\n");
     for(int i=0;i<qnt;i++)
     {
        imprimePaciente(pacientes[i]);
        liberaPaciente(pacientes[i]);
     }

     free(pacientes);
     liberaData(data);
     return 0;

}