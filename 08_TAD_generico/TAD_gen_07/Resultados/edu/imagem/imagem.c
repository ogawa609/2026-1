#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "imagem.h"


struct tImagem {

    int altura,largura;
    Tipo tipo;
    void* dados;
};

/**
 * @brief Função para obter a altura de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Altura da imagem.
 */
int ObterAltura(Imagem *img)
{
    return img->altura;
}

/**
 * @brief Função para obter a largura de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Largura da imagem.
 */
int ObterLargura(Imagem *img)
{
    return img->largura;
}

/**
 * @brief Função para obter o tipo de dados de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Tipo de dados da imagem.
 */
Tipo ObterTipoImagem(Imagem *img)
{
    return img->tipo;
}

/**
 * @brief Função para obter os dados de uma imagem.
 * Note que a imagem é uma matriz, mas os dados podem ser armazenados de forma linear (vetor).
 * @param img Ponteiro para a imagem.
 * @return Ponteiro para os dados da imagem.
 */
void *ObterDadosImagem(Imagem *img)
{
    return img->dados;
}

/**
 * @brief Função para criar uma imagem.
 * @param altura Altura da imagem.
 * @param largura Largura da imagem.
 * @param tipo Tipo de dados da imagem.
 * @return Ponteiro para a imagem criada. Caso não seja possível criar a imagem, o programa é encerrado.
 */
Imagem *CriarImagem(int altura, int largura, Tipo tipo)
{
    Imagem* i = malloc(sizeof(Imagem));
    i->altura = altura;
    i->largura = largura;
    i->tipo = tipo;

    if(tipo==INT)
        i->dados = malloc((largura*altura) * sizeof(int));
    else
        i->dados = malloc((largura*altura) * sizeof(float));

    return i;
}

/**
 * @brief Função para ler uma imagem, primeiro lendo a altura, largura e tipo de dados (tudo na mesma linha seperado por espaço). Em seguida, lê os dados da imagem.
 * @return Ponteiro para a imagem lida. (Crie a imagem com a função CriarImagem).
 */
Imagem *LerImagem()
{
    int altura,largura,tipo;
    scanf("%d %d %d",&altura,&largura,&tipo);

    Imagem* img = CriarImagem(altura,largura,tipo);

    for(int i=0;i<(largura*altura);i++)
    {
        if(tipo==INT)
            scanf("%d",&((int*)img->dados)[i]);
        
        else
            scanf("%f",&((float*)img->dados)[i]);
        
    }

    return img;
}

/**
 * @brief Função para imprimir uma imagem.
 * @param img Ponteiro para a imagem.
 */
void ImprimirImagem(Imagem *img)
{
    for(int i=0;i<img->altura;i++)
    {
        for(int j=0;j<img->largura;j++)
        {
            if(img->tipo==INT)
                printf("%d ",((int*)img->dados)[i * img->largura + j]);
            else
                printf("%.2f ",((float*)img->dados)[i*img->largura+j]);

        }

        printf("\n");
    }

}

/**
 * @brief Função para destruir uma imagem.
 * @param img Ponteiro para a imagem.
 */
void DestruirImagem(Imagem *img)
{
    free(img->dados);
    free(img);
}