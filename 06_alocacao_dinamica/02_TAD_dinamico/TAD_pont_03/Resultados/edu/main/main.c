#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locadora.h"


int main()
{
    tLocadora *loc=CriarLocadora();

    char comando[100];

    while(scanf(" %[^\n]\n",comando)==1)
    {
        if(strcmp(comando,"Cadastrar")==0)
        {
           LerCadastroLocadora(loc);
           printf("\n");
           
        }
        else if(strcmp(comando,"Alugar")==0)
        {
            LerAluguelLocadora(loc);
            printf("\n");
            
        }
        else if(strcmp(comando,"Devolver")==0)
        {
                LerDevolucaoLocadora(loc);
                printf("\n");
            
        }
        else if(strcmp(comando,"Estoque")==0)
        {
            OrdenarFilmesLocadora(loc);
            ConsultarEstoqueLocadora(loc);
            printf("\n");
             
            
        }

        
        scanf("#\n");

    }

    ConsultarLucroLocadora(loc);
    DestruirLocadora(loc);
    return 0;
}