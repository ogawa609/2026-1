#include <stdio.h>>
#include <stdlib.h>
#include "imagem.h"


int main()
{
    char caminho[100];
    scanf("%s",caminho);

    Imagem* img = LerImagem(caminho);

    printf("Numero de bytes lidos: %d\n",ObterNumeroBytesLidos(img));

    ImprimirImagem(img);
    DestruirImagem(img);

    return 0;
}