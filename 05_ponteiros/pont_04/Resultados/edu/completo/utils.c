#include <stdio.h>
#include "utils.h"

/**
 * @brief Lê uma sequência de inteiros da entrada padrão e os armazena em um array.
 * @param array Ponteiro para o array onde os inteiros serão armazenados.
 * @param tamanho O tamanho do array.
 */
void LeNumeros(int *array, int tamanho)
{
    for(int i = 0;i<tamanho;i++)
        scanf("%d",&array[i]);
    
}

/**
 * @brief Encontra o maior, o menor e a média dos valores em um array de inteiros.
 * @param array Ponteiro para o array de inteiros.
 * @param tamanho O tamanho do array.
 * @param maior Ponteiro para a variável que armazenará o maior valor.
 * @param menor Ponteiro para a variável que armazenará o menor valor.
 * @param media Ponteiro para a variável que armazenará a média dos valores.
 */
void EncontraMaiorMenorMedia(int *array, int tamanho, int *maior, int *menor, float *media)
{
    int biggest = array[0];
    int smallest = array[0];
    float med = 0;

    for(int i=0;i<tamanho;i++)
    {
        med += array[i];

        if(biggest<array[i])
            biggest = array[i];

        if(smallest>array[i])
            smallest = array[i];
    }

    if(tamanho>0)
        med = med/tamanho;

    *maior = biggest;
    *menor = smallest;
    *media = med;

}