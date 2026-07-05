#include <stdio.h>
#include <stdlib.h>
#include "imagem.h"

struct tImagem {
    void* dados;
    int linha;
    int coluna;
    Tipo tipo;
};

/**
 * @brief Função para ler uma imagem de um arquivo binário e aloca-la na memória.
 * @param path O caminho para o arquivo de imagem.
 * @return Um ponteiro para a imagem lida. Se houver erro (de leitura ou alocação de memória), a função imprime uma mensagem de erro e termina o programa.
 */
Imagem *LerImagem(const char *caminho)
{
    Imagem* img = malloc(sizeof(Imagem));
    FILE* f = fopen(caminho,"rb");
    int linha, coluna,tipo;
    fread(&linha,sizeof(int),1,f);
    fread(&coluna,sizeof(int),1,f);
    fread(&tipo,sizeof(int),1,f);

    img->coluna = coluna;
    img->linha = linha;
    img->tipo = tipo;
    if(tipo==1)
        img->dados = malloc(linha*coluna*sizeof(int));
    else
        img->dados = malloc(linha*coluna*sizeof(float));


    for(int i =0;i<linha*coluna;i++)
    {
        if(tipo==1)
        {
            int dado;
            fread(&dado,sizeof(int),1,f);
            ((int*)img->dados)[i] = dado;

        }
        else if(tipo==0)
        {
            float dado;
            fread(&dado,sizeof(float),1,f);
            ((float*)img->dados)[i] = dado;
        }
    }
    fclose(f);

    return img;
}

/**
 * @brief Função para destruir uma imagem.
 * @param img A imagem a ser destruída.
 */
void DestruirImagem(Imagem *img)
{
    free(img->dados);
    free(img);
}

/**
 * @brief Função para obter a altura de uma imagem.
 * @param img A imagem.
 * @return A altura da imagem.
 */
int ObterAlturaImagem(Imagem *img)
{
    return img->linha;
}

/**
 * @brief Função para obter a largura de uma imagem.
 * @param img A imagem.
 * @return A largura da imagem.
 */
int ObterLarguraImagem(Imagem *img)
{
    return img->coluna;
}

/**
 * @brief Função para obter o tipo de uma imagem.
 * @param img A imagem.
 * @return O tipo da imagem.
 */
Tipo ObterTipoImagem(Imagem *img)
{
    return img->tipo;
}

/**
 * @brief Função para obter os dados de uma imagem.
 * @param img A imagem.
 * @return Um ponteiro para os dados da imagem.
 */
void *ObterDadosImagem(Imagem *img)
{
    return img->dados;
}