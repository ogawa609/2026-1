#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tMonitorador.h"

typedef struct evento{
    void* evento;
    FptrIdentificaEvento identifica;
    FptrLiberaEvento libera;
    FptrProcessaEvento processa;

}tEvento;

 struct _tMonitorador {

    tEvento** eventos;
    int tam;
 };

/// @brief Função que cria uma variável do tipo monitorador de eventos
/// @return Um ponteiro para a variável do tipo monitorador de eventos
tMonitorador* criaMonitorador()
{
    tMonitorador* m = malloc(sizeof(tMonitorador));
    m->eventos = malloc(sizeof(tEvento*));
    m->tam = 0;

    return m;
}

/// @brief Função que libera o monitorador e seus eventos cadastrados.
/// @param m - O monitorador a ser liberado
void liberaMonitorador(tMonitorador* m)
{
    for(int i=0;i<m->tam;i++)
    {
        m->eventos[i]->libera(m->eventos[i]->evento);
        free(m->eventos[i]);
    }

    free(m->eventos);
    free(m);
}

/// @brief Função que adiciona um evento a um monitorador de eventos
/// @param m - Ponteiro para o monitorador de eventos
/// @param e - Ponteiro para o evento a ser cadastrado no monitorados
/// @param funcPE Callback para a função a ser executada quando o evento for identificado ("evento será processado")
/// @param funcId Callback para a função responsável por indicar se a tecla apertada se refere a um dos eventos
///                 cadastrados no monitorador
/// @param funcLE Callback para a função a ser executada quando o evento cadastrado tiver que ser liberado
void adicionaElementoMonitorador(tMonitorador* m, void* e, FptrProcessaEvento funcPE, FptrIdentificaEvento funcId, FptrLiberaEvento funcLE)
{
    tEvento* ev = malloc(sizeof(tEvento));
    ev->evento = e;
    ev->identifica = funcId;
    ev->libera = funcLE;
    ev->processa = funcPE;

    m->eventos[m->tam] = ev;
    m->tam++;
    m->eventos = realloc(m->eventos,(m->tam+1)*sizeof(tEvento*));
}

/// @brief Função que inicia o "loop de escuta" do monitorador. Ver especificação do EA para mais detalhes
/// @param amb - Ponteiro para o ambiente
/// @param m - Ponteiro para o monitorador de eventos
void iniciaMonitoramentotMonitorador(tAmbiente* amb, tMonitorador* m)
{
    char op;
    while(1)
    {
        scanf(" %c",&op);
        int flag = 1;

        for(int i=0;i<m->tam;i++)
        {
            if(m->eventos[i]->identifica(m->eventos[i]->evento,op))
            {
                m->eventos[i]->processa(amb,m->eventos[i]->evento,op);
                flag = 0;
            }
        }

        if(flag)
            break;
    }
}