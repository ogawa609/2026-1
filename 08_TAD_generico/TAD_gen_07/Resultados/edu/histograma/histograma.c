#include <stdio.h>
#include <stdlib.h>
#include "histograma.h"

struct tHistograma {

    int intervalo;
    int tamaInter;
    int* npixels;
    Imagem* img;
};

/**
 * @brief Função para calcular o histograma de uma imagem.
 * @param img Ponteiro para a imagem.
 * @param nIntervalos Número de intervalos no histograma.
 * @return Ponteiro para o histograma calculado.
 */
Histograma *CalcularHistograma(Imagem *img, int nIntervalos)
{
    Histograma* h = malloc(sizeof(Histograma));
    h->img = img;
    h->intervalo = nIntervalos;
    h->npixels = calloc(nIntervalos,sizeof(int));

    h->tamaInter = 256/nIntervalos;

    if(256%nIntervalos!=0)
    {
        h->tamaInter++;
    }

        int inicio = 0;
        int fim = h->tamaInter;

        int largura = ObterLargura(img);
        int altura = ObterAltura(img);
        Tipo tipo = ObterTipoImagem(img);
        void* dado = ObterDadosImagem(img);

    for(int i=0;i<nIntervalos;i++)
    {
        for(int j=0;j<largura*altura;j++)
        {
            if(tipo==INT)
            {
                int elem = ((int*)dado)[j];

                if(elem>=inicio && elem<fim)
                    h->npixels[i]++;
            }
            else
            {
                float elem = ((float*)dado)[j];
                 elem *= 255;
                 int e = elem;

                 if(e>=inicio && e<fim)
                    h->npixels[i]++;
            }
        }

        inicio += h->tamaInter;
        fim += h->tamaInter;
    }

    return h;
}

/**
 * @brief Função para imprimir um histograma na tela.
 * @param histograma Ponteiro para o histograma a ser exibido.
 */
void MostrarHistograma(Histograma *histograma)
{
    int ini=0;
    int fim = histograma->tamaInter;

    for(int i=0;i<histograma->intervalo;i++)
    {
        printf("[%d, %d): %d\n",ini,fim,histograma->npixels[i]);

        ini += histograma->tamaInter;
        fim += histograma->tamaInter;
    }
}

/**
 * @brief Função para destruir um histograma.
 * @param histograma Ponteiro para o histograma a ser destruído.
 */
void DestruirHistograma(Histograma *histograma)
{
    free(histograma->npixels);
    
    free(histograma);
}