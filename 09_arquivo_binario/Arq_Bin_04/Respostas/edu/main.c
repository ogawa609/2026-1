#include <stdio.h>
#include <stdlib.h>
#include "histograma.h"
#include "imagem.h"

int main()
{
    char caminho[100];
    scanf("%s",caminho);

    int intervalos;
    scanf("%d",&intervalos);

    Imagem* img = LerImagem(caminho);
    Histograma* histograma = CalcularHistograma(img,intervalos);

    MostrarHistograma(histograma);

    DestruirHistograma(histograma);
    DestruirImagem(img);

    return 0;

}