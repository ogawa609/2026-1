#include <stdio.h>
#include <stdlib.h>
#include "imagem.h"


struct Imagem{

    void* dado;
    int linha, coluna, numBytes;
    Tipo tipo;
};
/**
 * @brief Função para ler uma imagem de um arquivo binário e aloca-la na memória.
 * A função também armazena o número de bytes lidos na estrutura Imagem.
 * @param path O caminho para o arquivo de imagem.
 * @return Um ponteiro para a imagem lida. Se houver erro (de leitura ou alocação de memória), a função imprime uma mensagem de erro e termina o programa.
 */
tImagem *LerImagem(const char *caminho)
{
    FILE* arq = fopen(caminho,"rb");

    if(arq==NULL)
    {
        printf("PROBLEMAS");
        exit(1);
    }

    tImagem* img = malloc(sizeof(tImagem));
    img->numBytes = 0;
    img->numBytes += fread(&img->linha,sizeof(int),1,arq);
    img->numBytes += fread(&img->coluna,sizeof(int),1,arq);
    img->numBytes += fread(&img->tipo,sizeof(int),1,arq);

    if(img->tipo==INT)
    {
        img->dado = malloc(sizeof(int)*(img->coluna*img->linha));
        img->numBytes += fread(img->dado,sizeof(int),(img->coluna*img->linha),arq);
    }
    else
    {
         
        img->dado = malloc(sizeof(float)*(img->coluna*img->linha));
        img->numBytes += fread(img->dado,sizeof(float),(img->coluna*img->linha),arq);
    
    }

    printf("Linhas/Colunas %d/%d\n",img->linha,img->coluna);

    fclose(arq);
    return img;
        
}

/**
 * @brief Função para destruir uma imagem.
 * @param img A imagem a ser destruída.
 */
void DestruirImagem(tImagem *img)
{
    if(img!=NULL)
    {
        free(img->dado);
        free(img);
    }
}

/**
 * @brief Função para obter o número de bytes lidos de uma imagem.
 * @param img A imagem.
 * @return O número de bytes lidos.
 */
int ObterNumeroBytesLidos(tImagem *img)
{
    return img->numBytes;
}

/**
 * @brief Função para imprimir uma imagem.
 * @param img A imagem.
 */
void ImprimirImagem(tImagem *img)
{
    for(int i=0;i<(img->linha*img->coluna);i++)
    {
        if(img->tipo==INT)
        {
            printf("%d ",((int*)img->dado)[i]);
        }
        else
        {
             printf("%.1f ",((float*)img->dado)[i]);
        }

        if(i>0&&(i%img->coluna-1)==0)
            printf("\n");
    }
}

/**
 * @brief Função para retornar o menor pixel da imagem.
 * @param img A imagem.
 */
void* menorPixelImagem(tImagem *img)
{
    void* menor;

    if(img->tipo==INT)
    {
        menor = malloc(sizeof(int));
        *((int*)menor) = 10000000;

        for(int i=0;i<(img->linha*img->coluna);i++)
            if(((int*)img->dado)[i] < *((int*)menor))
                *((int*)menor) = ((int*)img->dado)[i];
    }
    else
    {
         menor = malloc(sizeof(float));
        *((float*)menor) = 10000000;

        for(int i=0;i<(img->linha*img->coluna);i++)
            if(((float*)img->dado)[i] < *((float*)menor))
                *((float*)menor) = ((float*)img->dado)[i];
    }

    return menor;
}

/**
 * @brief Função para retornar o maior pixel da imagem.
 * @param img A imagem.
 */
void* maiorPixelImagem(tImagem *img)
{
     void* maior;

    if(img->tipo==INT)
    {
        maior = malloc(sizeof(int));
        *((int*)maior) = 0;

        for(int i=0;i<(img->linha*img->coluna);i++)
            if(((int*)img->dado)[i] > *((int*)maior))
                *((int*)maior) = ((int*)img->dado)[i];
    }
    else
    {
         maior = malloc(sizeof(float));
        *((float*)maior) = 0;

        for(int i=0;i<(img->linha*img->coluna);i++)
            if(((float*)img->dado)[i] < *((float*)maior))
                *((float*)maior) = ((float*)img->dado)[i];
    }

    return maior;
}

/**
 * @brief Função para retornar a média dos pixels da imagem.
 * @param img A imagem.
 */
float mediaPixelImagem(tImagem *img)
{
    float media = 0;

    if(img->tipo==INT)
    {
        for(int i=0;i<img->linha*img->coluna;i++)
            media += (float) ((int*)img->dado)[i];
    }
    else
    {
        for(int i=0;i<img->linha*img->coluna;i++)
            media += ((float*)img->dado)[i];
    }

    media/= (img->coluna*img->linha);

    return media;
}

/**
 * @brief Função para retornar o tipo dos pixels da imagem.
 * @param img A imagem.
 */
Tipo obtemTipoImagem(tImagem *img)
{
    return img->tipo;
}