#include <stdio.h>
#include <stdlib.h>
#include "imagem.h"
#include "histograma.h"

int main()
{
    int intervalo;
    scanf("%d",&intervalo);

    Imagem* img = LerImagem();

    Histograma* histograma = CalcularHistograma(img,intervalo);
    MostrarHistograma(histograma);
    DestruirHistograma(histograma);
    DestruirImagem(img);

    return 0;
}