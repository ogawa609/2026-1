#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agendatarefas.h"

struct tTarefa{
    void* tarefa;
    void(*executa)(void*);
    void (*libera)(void*);
    int prioridade;

};

 struct agendatarefas{
    struct tTarefa** tarefas;
    int numTarefas;
    int max;

 };
/**
 * @brief Cria uma variável para um tipo genérico que representa uma Agenda de Tarefas
 *
 * @param numElem A quantidade de tarefas que serão armazenadas no agendador
 *
 * @return Um ponteiro para a agenda de tarefas
 */
tAgendaTarefas* CriaAgendaDeTarefas(int numElem)
{
    tAgendaTarefas* a = malloc(sizeof(tAgendaTarefas));

    a->numTarefas = 0;
    a->max= numElem;
    a->tarefas = malloc( numElem * sizeof(struct tTarefa*));
    

    return a;
}

/**
 * @brief Destroi a agenda de tarefas (libera a memória)
 *
 * @param tar - A agenda que terá seu conteúdo liberado/destruído
 */
void DestroiAgendaDeTarefas(tAgendaTarefas* tar)
{
    for(int i=0;i<tar->numTarefas;i++)
    {
        tar->tarefas[i]->libera(tar->tarefas[i]->tarefa);
        free(tar->tarefas[i]);
    }

    free(tar->tarefas);
    free(tar);
}

/**
 * @brief Cadastra uma tarefa em um agendador de tarefas
 *
 * @param tar - Pointeiro para a agenda de tarefas
 * @param prioridade - Prioridade de execução da nova tarefa
 * @param tarefa - Ponteiro para nova tarefa a ser executada
 * @param executa - Ponteiro para função (callback) que será chamada quando for a hora de executar a tarefa
 * @param destroi - Ponteiro para função (callback) que será chamada quando for a hora de destruir a tarefa (liberar a memória)
 *
 */
void CadastraTarefaNaAgenda(tAgendaTarefas* tar, int prioridade, void *tarefa, void (*executa)(void*), void (*destroi)(void*) )
{
    if(tar->numTarefas<=tar->max)
    {
        tar->tarefas[tar->numTarefas] = malloc(sizeof(struct tTarefa));
        tar->tarefas[tar->numTarefas]->tarefa = tarefa;
        tar->tarefas[tar->numTarefas]->executa = executa;
        tar->tarefas[tar->numTarefas]->libera = destroi;
        tar->tarefas[tar->numTarefas]->prioridade = prioridade;

        tar->numTarefas++;

        tar->tarefas = realloc(tar->tarefas,(tar->numTarefas+1)*sizeof(struct tTarefa*));
    }
}   

/**
 * @brief Executa as tarefas que estão salvas na agenda de tarefas passada como parâmetro.
 *
 * @param tar Agenda de tarefas
 *
 */
void ExecutarTarefasDaAgenda(tAgendaTarefas* tar)
{
   for(int i = 0; i < tar->numTarefas - 1; i++)
{
    for(int j = 0; j < tar->numTarefas - 1 - i; j++)
    {
        if(tar->tarefas[j]->prioridade < tar->tarefas[j + 1]->prioridade)
        {
            struct tTarefa* temp = tar->tarefas[j];
            tar->tarefas[j] = tar->tarefas[j + 1];
            tar->tarefas[j + 1] = temp;
        }
    }
}
    for(int i=0;i<tar->numTarefas;i++)
        tar->tarefas[i]->executa(tar->tarefas[i]->tarefa);
}
