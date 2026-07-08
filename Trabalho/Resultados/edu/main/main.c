#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TaxUfes.h"


int main()
{
    tGerenciador* tax = CriaTaxUfes();
    char comando[50];

    while(scanf("%s",comando)!=EOF)
    {
        
        if(strcmp(comando,"OUT")==0)
        {
            break;
        }
        else if(strcmp(comando,"CAT")==0)
        {
            LeCadastroAtor(tax);
        }
        else if(strcmp(comando,"CAV")==0)
        {
            CadastrarVeiculo(tax);
        }
        else if(strcmp(comando,"COC")==0 || strcmp(comando,"COM")==0 || strcmp(comando,"COV")==0 || strcmp(comando,"COCD")==0 ||
           strcmp(comando,"COCP")==0 || strcmp(comando,"COMP")==0 || strcmp(comando,"COVP")==0 || strcmp(comando,"COCDP")==0 )
        {
            BuscaVeiculosGerenciador(tax,comando);
        }
        else if(strcmp(comando,"MLC")==0)
        {
            RelatorioListaCorridasUsuario(tax);
        }
        else if(strcmp(comando,"ATL")==0)
        {
            RealizacaoSelecaoCorridaUsuario(tax);
        }
        else if(strcmp(comando,"RCL")==0)
        {
            RemoveCorridasLista(tax);
        }
        else if(strcmp(comando,"CPCLT")==0)
        {
            RealizarCorridaeAvaliar(tax);
        }
        else if(strcmp(comando,"GRU")==0)
        {
            GerarRelatorioUsuario(tax);
        }
        else if(strcmp(comando,"RGV")==0)
        {
            GerarRelatorioVeiculos(tax);
        }
        else if(strcmp(comando,"GRAV")==0)
        {
            GerarRelatorioAvaliacao(tax);
        }
        else
            printf("INVALIDO\n");
    }

    LiberaGerenciador(tax);
    return 0;
}

