#include <stdio.h>
#include "vetor.h"

/**
 * Lê um vetor da entrada padrão.
 * 
 * @param vetor Ponteiro para o vetor que será lido.
 */
void LeVetor(Vetor *vetor)
{
    int tam;
    scanf("%d",&tam);
    vetor->tamanhoUtilizado = tam;

    for(int i=0;i<tam;i++)
    {
        scanf("%d",&vetor->elementos[i]);
    }
}

/**
 * Aplica uma operação em um vetor.
 * 
 * @param vetor Ponteiro para o vetor que será utilizado.
 * @param op Ponteiro para a função que será aplicada.
 * @return O resultado da operação.
*/
int AplicarOperacaoVetor(Vetor *vetor, Operation op)
{
    int somatorio = vetor->elementos[0];

    for(int i=1;i<vetor->tamanhoUtilizado;i++)
    {

        somatorio = op(somatorio,vetor->elementos[i]);
    }

    return somatorio;
}