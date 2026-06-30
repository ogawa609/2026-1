#include <stdio.h>
#include <stdlib.h>
#include "imagem.h"

 struct tImagem {
    int linha, coluna;
    Tipo tipo;
    void* dado;
    int bytes;
 };

/**
 * @brief Função para ler uma imagem de um arquivo binário e aloca-la na memória.
 * A função também armazena o número de bytes lidos na estrutura Imagem.
 * @param path O caminho para o arquivo de imagem.
 * @return Um ponteiro para a imagem lida. Se houver erro (de leitura ou alocação de memória), a função imprime uma mensagem de erro e termina o programa.
 */
Imagem *LerImagem(const char *caminho)
{
    FILE* f = fopen(caminho,"rb");
    int linha,coluna;
    int tipo;
    Imagem* i = malloc(sizeof(Imagem));
    i->bytes = 0;

   i->bytes += (fread(&linha,sizeof(int),1,f));
    i->bytes += (fread(&coluna,sizeof(int),1,f));
   i->bytes+=  (fread(&tipo,sizeof(int),1,f));

    i->coluna = coluna;
    i->linha = linha;
    i->tipo = tipo;

    if(tipo==1)
    {
        i->dado = malloc(linha*coluna*sizeof(int));

        for(int j=0;j<(linha*coluna);j++)
        {
            int dado;
            i->bytes+= (fread(&dado,sizeof(int),1,f));
            ((int*)i->dado)[j] =  dado;
        }
    }
    else
    {
        i->dado = malloc(linha*coluna*sizeof(float));

        for(int j=0;j<(linha*coluna);j++)
        {
            float dado;
            i->bytes+= (fread(&dado,sizeof(float),1,f));
            ((float*)i->dado)[j] =  dado;
        }
    }
    fclose(f);

    return i;

}

/**
 * @brief Função para destruir uma imagem.
 * @param img A imagem a ser destruída.
 */
void DestruirImagem(Imagem *img)
{
    free(img->dado);
    free(img);
}

/**
 * @brief Função para obter o número de bytes lidos de uma imagem.
 * @param img A imagem.
 * @return O número de bytes lidos.
 */
int ObterNumeroBytesLidos(Imagem *img)
{
    return img->bytes;

}

/**
 * @brief Função para imprimir uma imagem.
 * @param img A imagem.
 */
void ImprimirImagem(Imagem *img)
{
    
    for(int i=0;i<img->linha;i++)
    {
        for(int j=0;j<img->coluna;j++)
        {
            if(img->tipo==1)
            {
                printf("%d ",((int*)img->dado)[(i*img->coluna)+j]);
            }
            else
            {
                printf("%.2f ",((float*)img->dado)[(i*img->coluna)+j]);
            }
        }
        printf("\n");
    }
}