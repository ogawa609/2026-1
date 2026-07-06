#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

struct Vector {
    DataType* dados;
    int tam;
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
    v->tam = 0;

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
    v->dados[v->tam] = val;
    v->tam++;
    v->dados = realloc(v->dados,(v->tam+1)*sizeof(DataType));

}

/**
 * @brief Remove o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
*/
void VectorRemove(Vector *v, int i)
{
    v->dados[i] = NULL;
    for(int j=i;j<v->tam-1;j++)
    {
        v->dados[j] = v->dados[j+1];
    }
    v->tam--;
    v->dados[v->tam] = NULL;
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
    return v->tam;
}


/**
 * @brief Troca os elementos i e j do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do primeiro elemento
 * @param j Índice do segundo elemento
*/
void VectorSwap(Vector *v, int i, int j)
{
    DataType temp = v->dados[i];
    v->dados[i] = v->dados[j];
    v->dados[j] = temp;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(DataType))
{
    for(int i=0;i<v->tam;i++)
        destroy(v->dados[i]);

    free(v->dados);
    free(v);
}