#include <stdio.h>
#include <string.h>
#include "paciente.h"
#include "lesao.h"
#include "data.h"

/*TOTAL PACIENTES: 4
MEDIA IDADE (ANOS): 29
TOTAL LESOES: 3
TOTAL CIRURGIAS: 2
LISTA DE PACIENTES:
- TRISTANA - L8 
- LUCIAN - L2 
- LUX - L100 
*/
int main()
{
    char comando;
    Paciente pacientes[100];
    int totalIdade,totalLesoes,totalCirurgias;
    totalCirurgias = totalIdade = totalLesoes = 0;
    Data hoje = criaData(12,9,2023);

    int numPac = 0;

    while(1)
    {
        scanf("%c\n",&comando);

        if(comando=='P')
        {
            pacientes[numPac] = lerPaciente();
            totalIdade += calculaIdadePaciente(pacientes[numPac],hoje);
            numPac++;
        }
        else if(comando=='L')
        {
            Lesao lesao = lerLesao();
            char cartaoLesao[19];
            getCartaoSusLesao(lesao,cartaoLesao);

            for(int i=0;i<numPac;i++)
            {
                char cartaoPac[19];
                getCartaoSusPaciente(pacientes[i],cartaoPac);

                if(strcmp(cartaoLesao,cartaoPac)==0)
                {
                   pacientes[i] = vinculaLesaoPaciente(pacientes[i],lesao);
            
                }
            }
        }

        else if(comando=='F')
            break;
    }

    for(int i=0;i<numPac;i++)
    {
        totalCirurgias += qtdLesoesCirurgicasPaciente(pacientes[i]);
        totalLesoes += getNumLesoesPaciente(pacientes[i]);
    }

    printf("TOTAL PACIENTES: %d\n",numPac);

    if(numPac>0)
    {
        totalIdade = totalIdade/numPac;
        printf("MEDIA IDADE (ANOS): %d\n",totalIdade);
    }
    else
        printf("MEDIA IDADE (ANOS): -\n");
        
    printf("TOTAL LESOES: %d\n",totalLesoes);
    printf("TOTAL CIRURGIAS: %d\n",totalCirurgias);

    printf("LISTA DE PACIENTES:\n");

     for(int i=0;i<numPac;i++)
        imprimePaciente(pacientes[i]);
    

    return 0;

}