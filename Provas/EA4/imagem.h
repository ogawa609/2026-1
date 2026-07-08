#ifndef _IMAGE_H
#define _IMAGE_H

/*
struct Imagem 
{
    int altura;
    int largura;
    Tipo tipo;
    void *dados;
};
*/

/**
 * @brief Enumeração para representar o tipo de dados da imagem.
 */
typedef enum {
    FLOAT = 0, 
    INT = 1    
} Tipo;

/**
 * @brief Estrutura para representar uma imagem.
 */
typedef struct Imagem tImagem;

/**
 * @brief Função para obter a altura de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Altura da imagem.
 */
int ObterAlturaImagem(tImagem *img);

/**
 * @brief Função para obter a largura de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Largura da imagem.
 */
int ObterLarguraImagem(tImagem *img);

/**
 * @brief Função para obter o tipo de dados de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Tipo de dados da imagem.
 */
Tipo ObterTipoImagem(tImagem *img);

/**
 * @brief Função para obter os dados de uma imagem.
 * Note que a imagem é uma matriz, mas os dados podem ser armazenados de forma linear (vetor).
 * @param img Ponteiro para a imagem.
 * @return Ponteiro para os dados da imagem.
 */
void *ObterDadosImagem(tImagem *img);

/**
 * @brief Função para ler uma imagem, primeiro lendo a altura, depois largura e tipo de dados (tudo na mesma linha seperado por espaço). Em seguida, lê os dados da imagem.
 * @return Ponteiro para a imagem lida. (O ponteiro para imagem deve ser criado aqui).
 */
tImagem *LerImagem(const char *caminho);

/**
 * @brief Função para destruir uma imagem.
 * @param img Ponteiro para a imagem.
 */
void DestruirImagem(tImagem *img);

#endif
