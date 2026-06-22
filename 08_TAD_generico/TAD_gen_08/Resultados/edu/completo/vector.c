#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

struct Vector {

    DataType* dados;
    int tamanho;

};

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct()
{
    Vector* v = malloc(sizeof(Vector));

    v->dados = malloc(sizeof(DataType));
    v->tamanho = 0;

    return v;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, DataType val)
{
    v->dados[v->tamanho] = val;

    v->tamanho++;
    v->dados = realloc(v->dados,(v->tamanho+1)*sizeof(DataType));
}

/**
 * @brief Remove o primeiro elemento do vetor e organiza os demais elementos, ou seja, 
 * o segundo elemento passa a ser o primeiro, o terceiro passa a ser o segundo, e assim por diante.
 * 
 * @param v Ponteiro para o vetor
 * @return DataType Elemento removido
*/
DataType VectorPopFront(Vector *v)
{
    DataType primeiro = v->dados[0];

    for(int i=0;i<v->tamanho-1;i++)
    {
        v->dados[i] = v->dados[i+1];
        
    }

    

    v->tamanho--;
    v->dados[v->tamanho] = NULL;
    
    return primeiro;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return DataType Elemento do vetor
*/
DataType VectorGet(Vector *v, int i)
{
    return v->dados[i];
}

/**
 * @brief Retorna o tamanho do vetor
 * 
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
*/
int VectorSize(Vector *v)
{
    return v->tamanho;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(DataType))
{
    for(int i=0;i<v->tamanho;i++)
        destroy(v->dados[i]);

    free(v->dados);
    free(v);
}