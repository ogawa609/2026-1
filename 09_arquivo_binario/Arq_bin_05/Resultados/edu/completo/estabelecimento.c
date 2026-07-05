#include <stdio.h>
#include  <stdlib.h>
#include "estabelecimento.h"
#include "vector.h"
#include "produto.h"

struct Estabelecimento{

    Vector* dados;
    int qnt;
};

/**
 * @brief Função para criar um novo estabelecimento.
 * @return Um ponteiro para o estabelecimento recém-criado. Se houver erro na alocação, o programa é encerrado.
 */
tEstabelecimento *CriaEstabelecimento()
{
    tEstabelecimento* e = malloc(sizeof(tEstabelecimento));
    e->dados = VectorConstruct();
    e->qnt = 0;

    return e;
}

/**
 * @brief Função para destruir um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser destruído.
 */
void DestroiEstabelecimento(tEstabelecimento *estabelecimento)
{
    VectorDestroy(estabelecimento->dados,DestroiProduto);
    free(estabelecimento);
}

/**
 * @brief Função para adicionar um produto a um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento.
 * @param produto Um ponteiro para o produto a ser adicionado.
 */
void AdicionaProdutoEstabelecimento(tEstabelecimento *estabelecimento, tProduto *produto)
{
    VectorPushBack(estabelecimento->dados,produto);

}

/**
 * @brief Função para ler um estabelecimento de um arquivo binário.
 * Inicialmente, deverá ser lido o nome do arquivo binário pela entrada padrão.
 * O arquivo binário deverá ser composto por um inteiro que representa a quantidade de produtos no estabelecimento, seguido pelos produtos.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser lido.
 */
void LeEstabelecimento(tEstabelecimento *estabelecimento)
{
    char caminho[100];
    scanf("%s",caminho);
    FILE* f = fopen(caminho,"rb");

    int qnt;
    fread(&qnt,sizeof(int),1,f);
    estabelecimento->qnt = qnt;

    for(int i=0;i<qnt;i++)
    {
        tProduto* p = LeProduto(f);
        AdicionaProdutoEstabelecimento(estabelecimento,p);
    }

    fclose(f);
}

/**
 * @brief Função para imprimir produtos que estão faltando em um estabelecimento no seguinte formato: Codigo;Nome;Preco
 * @param estabelecimento Um ponteiro para o estabelecimento.
 */
void ImprimeProdutosEmFaltaEstabelecimento(tEstabelecimento *estabelecimento)
{
    printf("Produtos em falta:\n");
    printf("Codigo;Nome;Preco\n");

    int flag = 1;
    for(int i=0;i<estabelecimento->qnt;i++)
    {
            void* produto = VectorGet(estabelecimento->dados,i);
            if(!TemEstoqueProduto((tProduto*)produto))
            {
                flag = 0;
                ImprimeProduto((tProduto*)produto);
            }
    }

    if(flag)
        printf("Nao ha produtos em falta!\n");
}