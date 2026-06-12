#include <stdio.h>
#include <stdlib.h>
#include "gerenciadorpacotes.h"

int main()
{
    tGerenciador* g = CriaGerenciador();
    printf("\n");

    while(1)
    {
        printf("Escolha uma opcao:\n");
        printf("(1) Cadastrar um novo pacote\n");
        printf("(2) Imprimir um pacote especifico\n");
        printf("(3) Imprimir todos os pacotes e sair\n");

        int op;
        scanf("%d\n",&op);

        if(op==1)
        {
            printf("Digite o tipo (0-char, 1-int) e o numero de elementos do pacote/mensagem:\n");
            int tipo,num;
            scanf("%d %d\n",&tipo,&num);

            if(tipo>1||tipo<0)
            {
                printf("Digite um tipo valido!\n");
                continue;
            }

            tPacote* p = CriaPacote(tipo,num);

            AdicionaPacoteNoGerenciador(g,p);
        }
        else if(op==2)
        {
            int idx;
            scanf("%d\n",&idx);
            ImprimirPacoteNoIndice(g,idx);
        }
        else if(op==3)
        {
            ImprimirTodosPacotes(g);
            break;
        }
        else
        {
            printf("Escolha uma opcao valida para o menu!\n");
        }
    }

    DestroiGerenciador(g);
    return 0;
}