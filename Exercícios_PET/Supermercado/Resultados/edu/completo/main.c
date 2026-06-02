#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "supermercado.h"

int main()
{
    Supermercado* mercado = CriarSupermercado();
    
    char comando[MAX_CARACTERES];

    while(1)
    {
        if(scanf("%s",comando)!=1)
            break;

        else if(strcmp(comando,"ENCERRAR")==0)
            break;

        else if(strcmp(comando,"CADASTRAR")==0)
            LerCadastroSupermercado(mercado);

        else if(strcmp(comando,"COMPRAR")==0)
            LerCompraSupermercado(mercado);

        else if(strcmp(comando,"FORNECEDOR")==0)
            LerFornecimento(mercado);

        else if(strcmp(comando,"ESTOQUE")==0)
            ConsultarEstoqueSupermercado(mercado);
        
        else if(strcmp(comando,"LUCRO")==0)
            ConsultarLucroSupermercado(mercado);

            
    }

    LiberaSupermercado(mercado);
    return 0;

}