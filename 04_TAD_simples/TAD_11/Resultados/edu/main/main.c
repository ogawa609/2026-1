#include <stdio.h>
#include "loja.h"

int main()
{

    int qnt;
    int controller = 0;
    scanf("%d",&qnt);

    tLoja lojas[qnt];

    int op;

    while(1)
    {
        scanf("%d",&op);

        if(op==0)
        {
            break;
        }
        else if(op==1)
        {
            int id;
            float aluguel;
            scanf("%d %f",&id,&aluguel);

            if(controller<qnt)
            {
                lojas[controller] = AbreLoja(id,aluguel);
                controller++;
            }

        }
        else if(op==2)
        {
            char nome[50];
            float per,salario;
            scanf("%s %f %f",nome,&salario,&per);
            tVendedor vend = RegistraVendedor(nome,salario,per);

            int idLoja;
            int indice;
            int existe = 1;
            scanf("%d",&idLoja);

            for(int i=0;i<controller;i++)
            {
                if(VerificaIdLoja(lojas[i],idLoja))
                {
                    indice = i;
                    existe = 0;
                    break;
                }
            }

            if(!existe)
                lojas[indice] = ContrataVendedor(lojas[indice],vend);
        }
        else if(op==3)
        {

            char nome[50];
            float valor;
            int idLoja;
            int indice;
            int existe = 1;

            scanf("%d %s",&idLoja,nome);
            scanf("%f",&valor);

             for(int i=0;i<controller;i++)
            {
                if(VerificaIdLoja(lojas[i],idLoja))
                {
                    indice = i;
                    existe = 0;
                    break;
                }
            }

            if(!existe)
            lojas[indice] = RegistraVenda(lojas[indice],nome,valor);

        }
        else if(op==4)
        {
            for(int i=0;i<controller;i++)
            {
                lojas[i] = CalculaLucro(lojas[i]);
                ImprimeRelatorioLoja(lojas[i]);
            }
        }
    }

    return 0;

}