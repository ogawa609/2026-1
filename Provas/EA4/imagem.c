#include <stdio.h>
#include <stdlib.h>
#include "imagem.h"

struct Imagem 
{
    int altura;
    int largura;
    Tipo tipo;
    void *dados;
};

/**
 * @brief Função para obter a altura de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Altura da imagem.
 */
int ObterAlturaImagem(tImagem *img)
{
    return img->altura;
}

/**
 * @brief Função para obter a largura de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Largura da imagem.
 */
int ObterLarguraImagem(tImagem *img)
{
    return img->largura;
}

/**
 * @brief Função para obter o tipo de dados de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Tipo de dados da imagem.
 */
Tipo ObterTipoImagem(tImagem *img)
{
    return img->tipo;
}

/**
 * @brief Função para obter os dados de uma imagem.
 * Note que a imagem é uma matriz, mas os dados podem ser armazenados de forma linear (vetor).
 * @param img Ponteiro para a imagem.
 * @return Ponteiro para os dados da imagem.
 */
void *ObterDadosImagem(tImagem *img)
{
    return img->dados;
}

/**
 * @brief Função para ler uma imagem, primeiro lendo a altura, depois largura e tipo de dados (tudo na mesma linha seperado por espaço). Em seguida, lê os dados da imagem.
 * @return Ponteiro para a imagem lida. (O ponteiro para imagem deve ser criado aqui).
 */
tImagem *LerImagem(const char *caminho)
{

    tImagem* img = (tImagem*) calloc(1,sizeof(tImagem));
    FILE* f = fopen(caminho,"rb");
    int altura,largura;
    int tipo;

    

    fread(&altura,sizeof(int),1,f);
    
    fread(&largura,sizeof(int),1,f);
    
    fread(&tipo,sizeof(int),1,f);

    if(tipo==1)
        img->dados = calloc(altura*largura,sizeof(int));
    else    
        img->dados = calloc(altura*largura,sizeof(float));
    

    for(int i=0;i<largura*altura;i++)
    {
        if(tipo==1)
        {
            fread(&(((int*)img->dados)[i]),sizeof(int),1,f);
            
        }
        else
        {
            fread(&(((float*)img->dados)[i]),sizeof(float),1,f);
            
        }
    }

    img->altura = altura;
    img->largura = largura;
    img->tipo = tipo;

    fclose(f);

    return img;
}

/**
 * @brief Função para destruir uma imagem.
 * @param img Ponteiro para a imagem.
 */
void DestruirImagem(tImagem *img)
{
    free(img->dados);
    free(img);
}