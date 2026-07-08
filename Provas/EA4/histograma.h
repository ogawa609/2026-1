#ifndef _HISTOGRAMA_H
#define _HISTOGRAMA_H

#include "imagem.h"

/*
struct Histograma
{
    int *contagens;
    int *intensidadeEqualizada;
    int tamanhoDoIntervalo;
    int nIntervalos;
};
*/

/**
 * @brief Estrutura para representar um Histograma.
 */
typedef struct Histograma tHistograma;

/**
 * @brief Função para calcular o histograma de uma imagem. Deve-se calcular o tamanho dos intervalos para definir onde cada pixel estará localizado
 	nas porções agregadas do histograma. LEMBRETE: é importante verificar o tipo do dado da imagem para fazer o typecast.
 * @param img Ponteiro para a imagem.
 * @param nIntervalos Número de intervalos no histograma.
 * @return Ponteiro para o histograma calculado.
 */
tHistograma *CalcularHistograma(tImagem *img, int nIntervalos);

/**
 * @brief Função para imprimir um histograma na tela. Imprime as porções agregadas de pixels no formato 
 * [limite_inferior, limite_superior): quantidade_de_pixes\n -> intensidade_equalizada_do_intervalo (valor central do intervalo projetado)
 * lembrando que os intervalos são fechado a esquerda e aberto a direita.
 * @param histograma Ponteiro para o histograma a ser exibido.
 */
void MostrarHistograma(tHistograma *histograma);

/**
 * @brief Função para destruir um histograma.
 * @param histograma Ponteiro para o histograma a ser destruído.
 */
void DestruirHistograma(tHistograma *histograma);

/**
 * @brief Função arredondar um valor real.
 * @param number: Valor real a ser arredondado.
 * @return Inteiro arredondado.
 */
int Arredondar(float number);

/**
 * @brief Função para equalizar o histograma. Deve-se calcular a intensidade equalizada para cada
 * intervalo de frequência calculado na função CalcularHistograma. A equalização respeita a formu-
 * lação apresentada na especificação do EA.
 * @param histograma: Ponteiro do tipo Histograma com um histograma já calculado.
 * @param imagem: Ponteiro do tipo Imagem com uma imagem válida já lida.
 */
void EqualizaIntervalosHistograma(tHistograma *histograma, tImagem *imagem);

#endif
