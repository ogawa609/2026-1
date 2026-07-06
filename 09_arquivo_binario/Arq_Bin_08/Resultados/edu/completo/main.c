#include <stdio.h>
#include <stdlib.h>
#include "lista_contato.h"

int main()
{
    tListaContato* l = CriarListaContato();
    char caminho[100];
    scanf("%s",caminho);

    CarregarListaContato(l,caminho);
    while(1)
    {
        printf("1 - Cadastrar contato\n2 - Remover contato\n3 - Realizar busca\n4 - Exibir todos os contatos\n0 - Sair da lista de contatos\nOpcao escolhida: \n");
        int op;
        scanf("%d",&op);

        if(op==0)
            break;
        else if(op==1)
        {
            tContato* c = LeContato();
            AdicionarContatoListaContato(l,c);
        }
        else if(op==2)
        {
            RemoverContatoListaContato(l);
        }
        else if(op==3)
        {
            printf("1 - Buscar pelo nome\n2 - Buscar pelo numero de telefone\nOpcao escolhida: \n");
            int op2;
            scanf("%d",&op2);

            if(op2==1)
            {
                BuscarPorNomeListaContato(l);
            }
            else if(op2==2)
            {
                BuscarPorNumeroTelefoneListaContato(l);
            }
        }
        else if(op==4)
        {
            ImprimirListaContato(l);
        }
    }

    SalvarListaContato(l,caminho);
    DestruirListaContato(l);
    return 0;
    
}