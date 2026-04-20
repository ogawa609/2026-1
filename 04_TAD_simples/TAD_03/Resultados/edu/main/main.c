#include <stdio.h>
#include <string.h>
#include "locadora.h"

int main()
{
    tLocadora loc=criarLocadora();

    char comando[100];

    while(scanf(" %[^\n]\n",comando)==1)
    {
        if(strcmp(comando,"Cadastrar")==0)
        {
           loc= lerCadastroLocadora(loc);
           printf("\n");
           
        }
        else if(strcmp(comando,"Alugar")==0)
        {
            loc=lerAluguelLocadora(loc);
            printf("\n");
            
        }
        else if(strcmp(comando,"Devolver")==0)
        {
            loc=lerDevolucaoLocadora(loc);
            printf("\n");
            
        }
        else if(strcmp(comando,"Estoque")==0)
        {
            loc= ordenarFilmesLocadora(loc);
            consultarEstoqueLocadora(loc);
            printf("\n");
             
            
        }

        scanf("%*[^\n]");
        scanf("%*c");

    }

    consultarLucroLocadora(loc);
    return 0;
}