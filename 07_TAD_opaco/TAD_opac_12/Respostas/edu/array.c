#include <stdio.h>
#include <stdlib.h>
#include "array.h"

struct  Array{

    int *array;
    int tamanho;
};


    /* data */


/**
 * @brief Inicializa um novo array, apontando data para NULL e tamanho para 0.
 * @return Ponteiro para a estrutura Array criada ou encerra caso não seja possível alocar memória.
 */
Array *CriarArray()
{
    Array* a = (Array*) malloc(sizeof(Array));
    a->tamanho = 0;
    a->array = (int*) malloc(sizeof(int));

    return a;
}


/**
 * @brief Libera a memória alocada para o array.
 * @param array Ponteiro para a estrutura Array a ser destruída.
 */
void DestruirArray(Array *array)
{
    free(array->array);
    free(array);
}

/**
 * @brief Lê os elementos do array a partir da entrada padrão e aloca memória para eles.
 * @details A leitura é feita até encontrar um ponto final (.) na entrada.
 * @param array Ponteiro para a estrutura Array a ser preenchida.
 */
void LerArray(Array *array)
{
    int d;

    while(scanf("%d",&d)!=1)
    {
        array->array[array->tamanho] = d;
        array->tamanho++;
        array->array = realloc(array->array,(array->tamanho+1)*sizeof(int));
    }

    scanf("%*[^\n]\n");
}

/**
 * @brief Ordena os elementos do array em ordem crescente.
 * @param array Ponteiro para a estrutura Array a ser ordenada.
 */
void OrdenarArray(Array *array)
{
    
}

/**
 * @brief Realiza uma busca binária no array pelo elemento especificado.
 * @param array Ponteiro para a estrutura Array a ser buscada.
 * @param elementoBuscado Elemento a ser buscado no array.
 * @return Índice do elemento buscado no array, ou -1 caso não seja encontrado.
 */
int BuscaBinariaArray(Array *array, int elementoBuscado);