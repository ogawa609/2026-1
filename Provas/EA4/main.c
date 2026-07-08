#include <stdio.h>
#include <stdlib.h>
#include "imagem.h"
#include "histograma.h"


int main()
{
    char caminho[100];
    scanf("%s",caminho);

    int intervalos;
    scanf("%d",&intervalos);

    tImagem* img =  LerImagem(caminho);
    tHistograma* h = CalcularHistograma(img,intervalos);

    
    EqualizaIntervalosHistograma(h,img);
    MostrarHistograma(h);
    DestruirHistograma(h);
    DestruirImagem(img);
    return 0;
}