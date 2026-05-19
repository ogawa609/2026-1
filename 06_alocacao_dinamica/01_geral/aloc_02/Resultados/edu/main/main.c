#include <stdio.h>
#include "utils.h"
#include <stdlib.h>


int main()
{
    int linhas,colunas;
    scanf("%d %d",&linhas,&colunas);

    int **matriz = CriaMatriz(linhas,colunas);

    LeMatriz(matriz,linhas,colunas);
    ImprimeMatrizTransposta(matriz,linhas,colunas);
    LiberaMatriz(matriz,linhas);

    return 0;
}