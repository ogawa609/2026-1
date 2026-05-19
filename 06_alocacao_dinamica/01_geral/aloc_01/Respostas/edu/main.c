#include <stdio.h>
#include "utils.h"

int main()
{
    int tam;
    int *vetor;

    scanf("%d",&tam);

    vetor = CriaVetor(tam);
    LeVetor(vetor,tam);

    float media = CalculaMedia(vetor,tam);

    printf("%.2f\n",media);

    LiberaVetor(vetor);

    return 0;

}