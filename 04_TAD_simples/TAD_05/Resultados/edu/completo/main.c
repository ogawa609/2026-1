#include <stdio.h>
#include "usuario.h"
#include "conta.h"

int main()
{
    int comando;
    
    int qntContas=0;
    int total;
    scanf("%d",&total);
    tConta contas[total];

    while(1)
    {
        scanf("%d",&comando);

        if(comando==0)
        {
            break;
        }
        else if(comando==1)
        {

            int numero;
            float valor;
            scanf("%d %f",&numero,&valor);

            if(qntContas>0)
            {

                for(int i=0;i<qntContas;i++)
                {
                    if(VerificaConta(contas[i],numero))
                    {
                        contas[i]=SaqueConta(contas[i],valor);
                        break;
                    }
                }
            }
        }
        else if(comando==2)
        {
            
            int numero;
            float valor;
            scanf("%d %f",&numero,&valor);

            if(qntContas>0)
            {

                for(int i=0;i<qntContas;i++)
                {
                    if(VerificaConta(contas[i],numero))
                    {
                        contas[i]=DepositoConta(contas[i],valor);
                        break;
                    }
                }
            }
        }
        else if(comando==3)
        {
            char nome[20];
            int num;
            char cpf[15];

            scanf(" %s %s %d",nome,cpf,&num);

            tUsuario cliente=CriaUsuario(nome,cpf);
            tConta nov=CriaConta(num,cliente);

            contas[qntContas]=nov;
            qntContas++;

        }
        else if(comando==4)
        {
            printf("===| Imprimindo Relatorio |===\n");

            for(int i=0;i<qntContas;i++)
            {
                ImprimeConta(contas[i]);
                printf("\n");
            }
        }
    }

    return 0;
}