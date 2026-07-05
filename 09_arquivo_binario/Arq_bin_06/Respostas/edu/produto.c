#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

struct Produto {
    int codigo;
    char* nome;
    float preco;
    int qnt;
};

/**
 * @brief Função para criar um novo produto.
 * @param codigo O código do produto.
 * @param nome O nome do produto.
 * @param preco O preço do produto.
 * @param quantidade A quantidade do produto em estoque.
 * @return Um ponteiro para o produto recém-criado. Se houver erro na alocação de memória, a função aborta o programa.
 */
tProduto *CriaProduto(int codigo, char *nome, float preco, int quantidadeVendida)
{
    tProduto* p = malloc(sizeof(tProduto));
    p->codigo = codigo;
    p->preco = preco;
    p->qnt = quantidadeVendida;

    int tam = strlen(nome) + 1;
    p->nome = malloc(tam*sizeof(char));
    strcpy(p->nome,nome);

    return p;
}

/**
 * @brief Função para destruir um produto.
 * @param produto Um ponteiro para o produto a ser destruído.
 */
void DestroiProduto(tProduto *produto)
{
    free(produto->nome);
    free(produto);
}

/**
 * @brief Função para ler um produto de um arquivo binário.
 * @param arquivo O arquivo de onde o produto será lido.
 * Formato do arquivo: 
 * Código (int) 
 * Nome (string) 
 * Preço (float) 
 * Quantidade (int).
 * @return Um ponteiro para o produto lido.
 */
tProduto *LeProduto(FILE *arquivo)
{
    int cod;
    char nome[51];
    float preco;
    int qnt;

    fread(&cod,sizeof(int),1,arquivo);
    fread(nome,sizeof(char),50,arquivo);
    nome[50] = '\0';
    fread(&preco,sizeof(float),1,arquivo);
    fread(&qnt,sizeof(int),1,arquivo);

    tProduto* p = CriaProduto(cod,nome,preco,qnt);
    return p;
}

/**
 * @brief Função para imprimir um produto no formato "Codigo;Nome;Preco;Quantidade vendida".
 * @param produto Um ponteiro para o produto a ser impresso.
 */
void ImprimeProduto(tProduto *produto)
{
    printf("%d;%s;R$ %.2f;%d",produto->codigo,produto->nome,produto->preco,produto->qnt);
}

/**
 * @brief Função para obter a quantidade vendida de um produto.
 * @param produto Um ponteiro para o produto.
 * @return A quantidade vendida do produto.
 */
int GetQuantidadeVendidaProduto(tProduto *produto)
{
    return produto->qnt;
}

/**
 * @brief Função para obter o preço de um produto.
 * @param produto Um ponteiro para o produto.
 * @return O preço do produto.
*/
float GetPrecoProduto(tProduto *produto)
{
    return produto->preco;
}