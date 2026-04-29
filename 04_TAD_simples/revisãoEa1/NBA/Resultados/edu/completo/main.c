#include <stdio.h>
#include <string.h>
#include "franquia.h"
#include "partida.h"

int main()
{
    tFranquia franquias[MAX_FRANQUIAS];
    int qnt = 0;

    char op;

    while(1)
    {
        scanf("%c ",&op);

        if(op=='P')
        {
            tPartida partida;
            char nomeF[MAX_TIME_NOME], nomeC[MAX_TIME_NOME];
            int pF, pC;
            scanf("%s @ %s %d %d\n",nomeF,nomeC,&pF,&pC);

            partida = lerPartida(nomeF,nomeC,pF,pC);

            insereDadosPartida(franquias,qnt,partida);
        }
        else if(op=='F')
        {
            char nome[MAX_TIME_NOME];
            char conf[MAX_CONF_NOME];
            scanf("%s %s\n",nome,conf);

            franquias[qnt] = lerFranquia(nome,conf);
            qnt++;
        }
        else if(op=='E')
        {
            break;
        }
    }

    ImprimeDadosFranquia(franquias,qnt);
    ImprimeDadosConferencia(franquias,qnt);

    return 0;
}