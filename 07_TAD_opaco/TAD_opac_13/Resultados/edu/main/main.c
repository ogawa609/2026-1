#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"
#include "lesao.h"
#include "data.h"



int main()
{
    Paciente** pacientes = malloc(sizeof(Paciente*));
    int qntPac=0;
    char op;
    int idade = 0;
    int lesoes = 0;
    int cirurgiasc =0;
    Data* data = criaData(12,9,2023);


    while(1)
    {
        scanf("%c\n",&op);

        if(op=='P')
        {
            Paciente* pac = lerPaciente();
            pacientes[qntPac] = pac;
            qntPac++;
            pacientes = realloc(pacientes, (qntPac+1)* sizeof(Paciente*));
        }

        else if(op=='L')
        {
            int check = 1;
            Lesao* les = lerLesao();
           
            for(int i=0;i<qntPac;i++)
            {
                if(strcmp(getCartaoSusPaciente(pacientes[i]),getCartaoSusLesao(les))==0)
                {
                    adicionaLesaoPaciente(pacientes[i],les);
                    check=0;
                }
                       
            }

            if(check)
                liberaLesao(les);
        }
        else
            break;
    }


    for(int i=0;i<qntPac;i++)
    {
        lesoes += getNumLesoesPaciente(pacientes[i]);
        cirurgiasc += qtdLesoesCirurgicasPaciente(pacientes[i]);
        idade += calculaIdadePaciente(pacientes[i],data);
    }

    printf("TOTAL PACIENTES: %d\n",qntPac);

    if(qntPac>0)
        printf("MEDIA IDADE (ANOS): %d\n",idade/qntPac);
    else
        printf("MEDIA IDADE (ANOS): -\n");
        
    printf("TOTAL LESOES: %d\n",lesoes);
    printf("TOTAL CIRURGIAS: %d\n",cirurgiasc);
    printf("LISTA DE PACIENTES:\n");

     for(int i=0;i<qntPac;i++)
     {
        imprimePaciente(pacientes[i]);
        liberaPaciente(pacientes[i]);
     }

     free(pacientes);
     liberaData(data);
     return 0;


}