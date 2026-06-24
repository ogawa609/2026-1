#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tMonitorador.h"
#include "tEventoMovimento.h"
#include "tClique.h"


int main()
{
    tMonitorador* monit = criaMonitorador();
    tAmbiente* amb = criaAmbiente();

    char comandosClique[3] = {'L','M','R'};
    char mov1[4] = {'W','A','S','D'};
    char mov2[4] = {'U','H','J','K'};
    
    tClique* clique = criaEventoClique(comandosClique);
    adicionaElementoMonitorador(monit,clique,processaEventoClique,identificaEventoClique,liberaEventoClique);

    int modo;
    scanf("%d\n",&modo);
    

    printf("Modo %d selecionado!\n",modo);

    if(modo==1)
    {
        tEventoMovimento*m1 = criaEventoMovimento(mov1);
        adicionaElementoMonitorador(monit,m1,processaEventoMovimento,identificaEventoMovimento,liberaEventoMovimento);
    }
    else if(modo==2)
    {
        tEventoMovimento*m2 = criaEventoMovimento(mov2);
        adicionaElementoMonitorador(monit,m2,processaEventoMovimento,identificaEventoMovimento,liberaEventoMovimento);
    }
    else if(modo==3)
    {
        tEventoMovimento*m1 = criaEventoMovimento(mov1);
        adicionaElementoMonitorador(monit,m1,processaEventoMovimento,identificaEventoMovimento,liberaEventoMovimento);
        tEventoMovimento*m2 = criaEventoMovimento(mov2);
        adicionaElementoMonitorador(monit,m2,processaEventoMovimento,identificaEventoMovimento,liberaEventoMovimento);
    }
    else 
        printf("Modo de jogo invalido\n");
    
    
    
    iniciaMonitoramentotMonitorador(amb,monit);

    liberaAmbiente(amb);
    liberaMonitorador(monit);
}