#include <stdio.h>
#include <stdlib.h>
#include "estabelecimento.h"
#include "vector.h"
#include "produto.h"

struct Estabelecimento {

    Vector* dados;
    int qnt;
    int total;
};

/**
 * @brief Função para criar um novo estabelecimento.
 * @return Um ponteiro para o estabelecimento recém-criado. Se houver erro na alocação, o programa é encerrado.
 */
tEstabelecimento *CriaEstabelecimento()
{
    tEstabelecimento* e = malloc(sizeof(tEstabelecimento));

    e->qnt = 0;
    e->total = 0;
    e->dados = VectorConstruct();

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

    for(int i =0;i<qnt;i++)
    {
        tProduto* p = LeProduto(f);
        estabelecimento->total += GetQuantidadeVendidaProduto(p);
        AdicionaProdutoEstabelecimento(estabelecimento,p);
    }
    fclose(f);
}

/**
 * @brief Função para obter o valor total de produtos vendidos em um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento.
 * @return O valor total de produtos vendidos.
*/
float GetValorTotalVendidoEstabelecimento(tEstabelecimento *estabelecimento)
{
    float total = 0;

    for(int i=0;i<estabelecimento->qnt;i++)
    {
        void* d = VectorGet(estabelecimento->dados,i);
        total += (GetPrecoProduto(((tProduto*)d))*GetQuantidadeVendidaProduto((tProduto*)d));
    }

    return total;
}

/**
 * @brief Função para imprimir na tela um relatório de um estabelecimento, cotendo o valor total vendido e a porcentagem de cada produto relativo ao total vendido.
 * Formato: Codigo;Nome;Preco;Quantidade vendida
 * @param estabelecimento Um ponteiro para o estabelecimento.
*/
void ImprimeRelatorioEstabelecimento(tEstabelecimento *estabelecimento)
{
    printf("Valor total vendido: R$ %.2f\n",GetValorTotalVendidoEstabelecimento(estabelecimento));
    printf("Produtos vendidos:\n");
    printf("Codigo;Nome;Preco;Quantidade vendida;Porcentagem\n");
    int flag = 1;
    for(int i=0;i<estabelecimento->qnt;i++)
    {
        void* p = VectorGet(estabelecimento->dados,i);
        double q = GetQuantidadeVendidaProduto((tProduto*)p)*GetPrecoProduto((tProduto*)p);
        double per = (q*100.0)/GetValorTotalVendidoEstabelecimento(estabelecimento);
        ImprimeProduto((tProduto*)p);
        printf(";%.2f%%\n",per);
        flag = 0;
    }

    if(flag)
        printf("Nao ha produtos\n");
}