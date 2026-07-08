#include <stdio.h>
#include <stdlib.h>
#include "histograma.h"
#include "imagem.h"

struct Histograma
{
    int *contagens;
    int *intensidadeEqualizada;
    int tamanhoDoIntervalo;
    int nIntervalos;
};




/**
 * @brief Função para calcular o histograma de uma imagem. Deve-se calcular o tamanho dos intervalos para definir onde cada pixel estará localizado
 	nas porções agregadas do histograma. LEMBRETE: é importante verificar o tipo do dado da imagem para fazer o typecast.
 * @param img Ponteiro para a imagem.
 * @param nIntervalos Número de intervalos no histograma.
 * @return Ponteiro para o histograma calculado.
 */
tHistograma *CalcularHistograma(tImagem *img, int nIntervalos)
{
    tHistograma* h = (tHistograma*)calloc(1,sizeof(tHistograma));

    h->nIntervalos = nIntervalos;

    h->tamanhoDoIntervalo = 256/nIntervalos;
     if(256%nIntervalos!=0)
        h->tamanhoDoIntervalo++;

    int periodo = ObterAlturaImagem(img) * ObterLarguraImagem(img);
    void* dados = ObterDadosImagem(img);
    Tipo tipo = ObterTipoImagem(img);

   

    h->contagens = (int*)calloc(nIntervalos,sizeof(int));

    int inicio = 0;
    int final = h->tamanhoDoIntervalo;

    for(int i=0;i<nIntervalos;i++)
     h->contagens[i] = 0;

    for(int i=0;i<nIntervalos;i++)
    {
        for(int j=0;j<periodo;j++)
        {
            if(tipo==INT)
            {
                int valor = ((int*)dados)[j];

                if(valor>=inicio&&valor<final)
                {
                    h->contagens[i]++;
                }
            }
            else
            {
                float valor = ((float*)dados)[j] * 255;

                if(valor>=inicio&&valor<final)
                {
                    h->contagens[i]++;
                }
            }
        }

        inicio += h->tamanhoDoIntervalo;
        final += h->tamanhoDoIntervalo;
    }

    h->intensidadeEqualizada = NULL;

    return h;
}

/**
 * @brief Função para imprimir um histograma na tela. Imprime as porções agregadas de pixels no formato 
 * [limite_inferior, limite_superior): quantidade_de_pixes\n -> intensidade_equalizada_do_intervalo (valor central do intervalo projetado)
 * lembrando que os intervalos são fechado a esquerda e aberto a direita.
 * @param histograma Ponteiro para o histograma a ser exibido.
 */
void MostrarHistograma(tHistograma *histograma)
{
    int inicio = 0;
    int final = histograma->tamanhoDoIntervalo;
    for(int i=0;i<histograma->nIntervalos;i++)
    {
        printf("[%d, %d): %d -> %d\n",inicio,final,histograma->contagens[i],histograma->intensidadeEqualizada[i]);
        inicio += histograma->tamanhoDoIntervalo;
        final += histograma->tamanhoDoIntervalo;
    }

   
}

/**
 * @brief Função para destruir um histograma.
 * @param histograma Ponteiro para o histograma a ser destruído.
 */
void DestruirHistograma(tHistograma *histograma)
{
    free(histograma->contagens);
    free(histograma->intensidadeEqualizada);
    free(histograma);
}

/**
 * @brief Função arredondar um valor real.
 * @param number: Valor real a ser arredondado.
 * @return Inteiro arredondado.
 */
int Arredondar(float number)
{
    int numero = (int) number;
    return numero;
}

/**
 * @brief Função para equalizar o histograma. Deve-se calcular a intensidade equalizada para cada
 * intervalo de frequência calculado na função CalcularHistograma. A equalização respeita a formu-
 * lação apresentada na especificação do EA.
 * @param histograma: Ponteiro do tipo Histograma com um histograma já calculado.
 * @param imagem: Ponteiro do tipo Imagem com uma imagem válida já lida.
 */
void EqualizaIntervalosHistograma(tHistograma *histograma, tImagem *imagem)
{
    histograma->intensidadeEqualizada = malloc(histograma->nIntervalos*sizeof(int));

    int altura = ObterAlturaImagem(imagem);
    int largura = ObterLarguraImagem(imagem);
    int intervalo = histograma->nIntervalos;

    
    int probabilidade[intervalo];
    int media[intervalo];
    int somatoria = 0;
    float pr = ((histograma->nIntervalos - 1)/(largura*altura));

    for(int i=0;i<histograma->nIntervalos;i++)
    {
        

    }
}