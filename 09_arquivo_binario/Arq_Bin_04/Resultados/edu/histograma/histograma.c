#include <stdio.h>
#include <stdlib.h>
#include "histograma.h"

struct tHistograma {

    int numIntervalos;
    int tamIntervalo;
    int* taxaPixelsIntervalo;
};

/**
 * @brief Função para calcular um histograma a partir de uma imagem.
 * @param image A imagem para calcular o histograma.
 * @param n_buckets O número de intervalos no histograma.
 * @return Um ponteiro para o histograma calculado.
 */
Histograma *CalcularHistograma(Imagem *img, int nIntervalos)
{
    Histograma* h = malloc(sizeof(Histograma));
    h->numIntervalos = nIntervalos;

    int n = 256/nIntervalos;
    if(256%nIntervalos!=0)
        n++;
    h->tamIntervalo = n;
    

    int linha = ObterAlturaImagem(img);
    int coluna = ObterLarguraImagem(img);
    void* dado = ObterDadosImagem(img);
    int tipo = ObterTipoImagem(img);

    if(tipo==1)
         h->taxaPixelsIntervalo = malloc(nIntervalos*sizeof(int));
    else if(tipo==0)
         h->taxaPixelsIntervalo = malloc(nIntervalos*sizeof(float));

    int inicio = 0;
    int final = h->tamIntervalo;

    for(int j =0;j<nIntervalos;j++)
    {
        int acumulador = 0;
        for(int i=0;i<linha*coluna;i++)
        {
            if(tipo==1)
            {
                if(((int*)dado)[i]>=inicio&&((int*)dado)[i]<final)
                    acumulador++;
            }
            else
            {
                int d = ((float*)dado)[i] * 255;
                if(d>=inicio&&d<final)
                    acumulador++;
            }
        }

        h->taxaPixelsIntervalo[j] = acumulador;
        inicio += h->tamIntervalo;
        final += h->tamIntervalo;
    }   
    return h;
}

/**
 * @brief Função para exibir um histograma na tela.
 * @param histogram O histograma a ser exibido.
 */
void MostrarHistograma(Histograma *h)
{
    int ini = 0;
    int fin = h->tamIntervalo;
    for(int i=0;i<h->numIntervalos;i++)
    {
        printf("[%d, %d): %d\n",ini,fin,h->taxaPixelsIntervalo[i]);

        ini += h->tamIntervalo;
        fin += h->tamIntervalo;
    }
}

/**
 * @brief Função para destruir um histograma.
 * @param histogram O histograma a ser destruído.
 */
void DestruirHistograma(Histograma *histograma)
{
    free(histograma->taxaPixelsIntervalo);
    free(histograma);
}