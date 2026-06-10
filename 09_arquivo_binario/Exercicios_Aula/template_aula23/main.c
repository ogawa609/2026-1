#include <stdio.h>
#include <stdlib.h>
#include "imagem.h"

int main() 
{
    char caminho[100];
    scanf("%s", caminho);
    tImagem *img = LerImagem(caminho);

    printf("Numero de bytes lidos: %d\n", ObterNumeroBytesLidos(img));
    if(obtemTipoImagem(img) == INT)
    {
        int* menor = (int*) menorPixelImagem(img);
        int* maior = (int*) maiorPixelImagem(img);
        
        printf("Menor Pixel: %d\n",*menor);
        printf("Maior Pixel: %d\n",*maior);
        printf("Pixel médio: %.2f\n",mediaPixelImagem(img));
        free(menor);
        free(maior);
    }
    else
    {
        float* maior = (float*) maiorPixelImagem(img);
        float* menor = (float*) menorPixelImagem(img);
         printf("Menor Pixel: %.2f\n",*menor);
        printf("Maior Pixel: %.2f\n",*maior);
        printf("Pixel médio: %.2f\n",mediaPixelImagem(img));
        free(menor);
        free(maior);
    }

    ImprimirImagem(img);
    DestruirImagem(img);

    return 0;
}
