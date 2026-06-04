#include <stdio.h>
#include <stdlib.h>
#include "matrix_utils.h"


/**
 * @brief Cria uma matriz com o número de linhas e colunas especificado. Alocar dinamicamente o espaço na memória para a matriz bidimensional
 * @param rows O número de linhas na matriz.
 * @param cols O número de colunas na matriz.
 * @return A matriz criada.
 */
tMatrix* MatrixCreate(int rows, int cols)
{
    tMatrix* m = malloc(sizeof(tMatrix));
    m->cols = cols;
    m->rows = rows;
    m->data = malloc(sizeof(int*)*rows);
    for(int i=0;i<rows;i++)
        m->data[i] = malloc(sizeof(int)*cols);

    return m;
}

/**
 * @brief Libera toda a memória alocada por uma matriz
 * @param matrix O ponteiro para a estrutura que armazena uma matriz.
 */
void MatrixFree(tMatrix* matrix)
{
    for(int i=0;i<matrix->rows;i++)
        free(matrix->data[i]);
    
    free(matrix->data);
    free(matrix);
}

/**
 * @brief Lê uma matriz da entrada padrão.
 * @param matrix A matriz a ser lida.
 */
void MatrixRead(tMatrix* matrix)
{

    for(int i =0; i<matrix->rows;i++)
    {
        for(int j = 0; j<matrix->cols;j++)
            scanf("%d",&matrix->data[i][j]);
    }
}

/**
 * @brief Imprime uma matriz na saída padrão.
 * @param matrix A matriz a ser impressa.
 */
void MatrixPrint(tMatrix* matrix)
{
    for(int i =0; i<matrix->rows;i++)
    {
        printf("|");

        for(int j = 0; j<matrix->cols;j++)
        {
            if(j!=matrix->cols-1)
                printf("%d ",matrix->data[i][j]);
            else
                printf("%d|\n",matrix->data[i][j]);
        }
    }
    printf("\n");
}

/**
 * @brief Verifica se é possível somar duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível somar as matrizes, 0 caso contrário.
 */
int PossibleMatrixSum(tMatrix* matrix1, tMatrix* matrix2)
{
    return matrix1->rows==matrix2->rows && matrix1->cols==matrix2->cols;
}

/**
 * @brief Verifica se é possível subtrair duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível subtrair as matrizes, 0 caso contrário.
 */
int PossibleMatrixSub(tMatrix* matrix1, tMatrix* matrix2)
{
    return matrix1->rows==matrix2->rows && matrix1->cols==matrix2->cols;
}

/**
 * @brief Verifica se é possível multiplicar duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível multiplicar as matrizes, 0 caso contrário.
 */
int PossibleMatrixMultiply(tMatrix* matrix1, tMatrix* matrix2)
{
    return matrix1->cols==matrix2->rows; 
}

/**
 * @brief Soma duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da soma.
 */
tMatrix* MatrixAdd(tMatrix* matrix1, tMatrix* matrix2)
{
    tMatrix* c = MatrixCreate(matrix1->rows,matrix2->cols);

    for(int i =0; i<matrix1->rows;i++)
    {
        for(int j = 0; j<matrix1->cols;j++)
        {
            c->data[i][j] = matrix1->data[i][j] + matrix2->data[i][j];
        }
    }

    return c;
}

/**
 * @brief Subtrai duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da subtração.
 */
tMatrix* MatrixSub(tMatrix* matrix1, tMatrix* matrix2)
{
    tMatrix* c = MatrixCreate(matrix1->rows,matrix2->cols);

    for(int i =0; i<matrix1->rows;i++)
    {
        for(int j = 0; j<matrix1->cols;j++)
        {
            c->data[i][j] = matrix1->data[i][j] - matrix2->data[i][j];
        }
    }

    return c;
}

/**
 * @brief Multiplica duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da multiplicação.
 */
tMatrix* MatrixMultiply(tMatrix* matrix1, tMatrix* matrix2)
{
    tMatrix* c = MatrixCreate(matrix1->rows,matrix2->cols);

    for(int i =0; i<matrix1->rows;i++)
    {
        for(int j = 0; j<matrix2->cols;j++)
        {
            c->data[i][j] = 0;
        }
    }


    for(int i =0; i<matrix1->rows;i++)
    {
        for(int j = 0; j<matrix2->cols;j++)
        {
            for(int k = 0; k<matrix2->rows;k++)
            {
                c->data[i][j] += matrix1->data[i][k] * matrix2->data[k][j];
            }
        }
    }

    return c;
}

/**
 * @brief Transpõe uma matriz.
 * @param matrix A matriz a ser transposta.
 * @return A matriz transposta.
 */
tMatrix* TransposeMatrix(tMatrix* matrix)
{

    tMatrix* m = MatrixCreate(matrix->cols,matrix->rows);

    for(int i=0;i<matrix->cols;i++)
    {
        for(int j=0; j<matrix->rows;j++)
            m->data[i][j] = matrix->data[j][i];
    }

    return m;
}

/**
 * @brief Multiplica uma matriz por um escalar.
 * @param matrix A matriz a ser multiplicada.
 * @param scalar O escalar pelo qual a matriz será multiplicada.
 * @return O resultado da multiplicação.
 */
tMatrix* MatrixMultiplyByScalar(tMatrix* matrix, int scalar)
{

    tMatrix* m = MatrixCreate(matrix->rows,matrix->cols);

    for(int i =0; i<matrix->rows;i++)
    {
        for(int j = 0; j<matrix->cols;j++)
        {
            m->data[i][j] = matrix->data[i][j]*scalar;
        }
    }


    return m;
}