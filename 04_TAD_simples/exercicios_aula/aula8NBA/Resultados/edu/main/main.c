#include <stdio.h>
#include "franquia.h"

int main()
{
    tFranquia franquias[200];
    int qntFranquias=0;
    char op_code='\0';

    while(1)
    {
         scanf("%c ",&op_code);

         if(op_code=='F')
         {
            char nome[MAX_TIME_NOME];
            char conf[MAX_CONF_NOME];

            scanf("%s %s\n",nome,conf);
            franquias[qntFranquias]=lerFranquia(nome,conf);
            qntFranquias++;
         }

         else if(op_code=='P')
         {
            char timeF[MAX_TIME_NOME];
            char timeC[MAX_TIME_NOME];
            int pontosC,pontosF;

            scanf("%s @ %s %d %d\n",timeF,timeC,&pontosF,&pontosC);

            tPartida partida=lerPartida(timeF,timeC,pontosF,pontosC);
            insereDadosPartida(franquias,qntFranquias,partida);


         }
         else if(op_code=='E')
         {
            break;
         }
         else
            return 0;
    }

    ImprimeDadosFranquia(franquias,qntFranquias);
    ImprimeDadosConferencia(franquias,qntFranquias);

    return 0;
}