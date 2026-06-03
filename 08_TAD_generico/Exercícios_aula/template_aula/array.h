#ifndef _ARRAY_H
#define _ARRAY_H

#define INT 1
#define FLOAT 2
#define CHAR 3
#define STR 4

#define MAX_STR 20

typedef struct Array tArray;
/*
struct Array 
{
    void *dado;
    func_ptr_imprimeDado imprimeDado;
    func_ptr_liberaDado liberaDado;
};
*/

//funções de callBack
typedef void (*func_ptr_imprimeDado)(void *dado);
typedef void (*func_ptr_liberaDado)(void *dado);


/**
 * Cria um array genérico vazio.
 *
 * O array é capaz de armazenar elementos de diferentes tipos,
 * juntamente com as funções responsáveis por imprimi-los e liberá-los.
 *
 * @return Ponteiro para o vetor de elementos do tipo tArray.
 */
tArray **criaArray();

/**
 * Adiciona um novo elemento ao final do array.
 *
 * A função redimensiona o vetor dinamicamente, cria uma nova posição
 * e armazena o dado juntamente com suas funções de callback.
 *
 * @param a Vetor de elementos do array.
 * @param tam Ponteiro para a quantidade atual de elementos do array.
 *            O valor é incrementado após a inserção.
 * @param dado Ponteiro para o dado que será armazenado.
 * @param imprimeDado Função responsável por imprimir o dado.
 * @param liberaDado Função responsável por liberar a memória do dado.
 *
 * @return Ponteiro para o vetor atualizado após a possível realocação.
 */
tArray **adicionaDadoArray(
    tArray **a,
    int *tam,
    void *dado,
    func_ptr_imprimeDado imprimeDado,
    func_ptr_liberaDado liberaDado
);

/**
 * Imprime todos os elementos armazenados no array.
 *
 * Para cada posição do vetor, a função callback de impressão
 * associada ao elemento é executada.
 *
 * @param a Vetor de elementos do array.
 * @param tam Quantidade de elementos armazenados.
 */
void imprimeArray(tArray **a, int tam);

/**
 * Libera toda a memória utilizada pelo array.
 *
 * Para cada elemento armazenado:
 * - libera o dado utilizando a callback associada;
 * - libera a estrutura tArray correspondente.
 *
 * Ao final, libera o próprio vetor de ponteiros.
 *
 * @param a Vetor de elementos do array.
 * @param tam Quantidade de elementos armazenados.
 */
void desalocaArray(tArray **a, int tam);

#endif
