#include <stdio.h>
#include "matrix_utils.h"


int main()
{
    int x1,y1,x2,y2;
    scanf("%d %d",&x1,&y1);

    tMatrix m1=MatrixCreate(x1,y1);
    m1=MatrixRead(m1);

    scanf("%d %d",&x2,&y2);
    tMatrix m2=MatrixCreate(x2,y2);
    m2=MatrixRead(m2);

    while(1)
    {
         printf("1 - Somar matrizes\n");
        printf("2 - Subtrair matrizes\n");
        printf("3 - Multiplicar matrizes\n");
        printf("4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida:\n");

        int op;
        scanf("%d",&op);

        if(op==1)
        {
            if(PossibleMatrixSum(m1,m2))
            {
                tMatrix m3=MatrixAdd(m1,m2);
                MatrixPrint(m3);
            }
            else
            {
                printf("Erro: as dimensoes da matriz nao correspondem\n");
            }
        }
        else if(op==2)
        {
            if(PossibleMatrixSub(m1,m2))
            {
            
                tMatrix m3=MatrixSub(m1,m2);
                MatrixPrint(m3);
            }
            else
            {
                printf("Erro: as dimensoes da matriz nao correspondem\n");
            }
        }
        else if(op==3)
        {
            if(PossibleMatrixMultiply(m1,m2))
            {
                tMatrix m3=MatrixMultiply(m1,m2);
                MatrixPrint(m3);
            }
            else
            {
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");
            }
        }
        else if(op==4)
        {
            int scalar,matriz;
            scanf("%d %d",&scalar,&matriz);

            if(matriz==1)
            {
                m1=MatrixMultiplyByScalar(m1,scalar);
                MatrixPrint(m1);
            }
            else if(matriz==2)
            {
                m2=MatrixMultiplyByScalar(m2,scalar);
                MatrixPrint(m2);
            }
        }
        else if(op==5)
        {
            tMatrix t1 = TransposeMatrix(m1);
            MatrixPrint(t1);
            tMatrix t2 = TransposeMatrix(m2);
            MatrixPrint(t2);
        }
        else if(op==6)
        {
            break;
        }
    }

    return 0;
}