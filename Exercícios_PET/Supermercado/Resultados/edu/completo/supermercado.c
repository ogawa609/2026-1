#include <stdio.h>
#include <stdlib.h>
#include "supermercado.h"



struct Supermercado{

    Produto** lista;
    int qntProdutos;
    int qntAlocada;
    float lucro;
};
/**
 * @brief Cria uma nova instância de Supermercado e inicializa produto como NULL, numProdutos como 0 e lucro como 0.
 * 
 * @return Supermercado* Ponteiro para a nova instância de Supermercado criada ou encerra o programa caso não haja memória suficiente.
 */
Supermercado* CriarSupermercado ()
{
    Supermercado* s = malloc(sizeof(Supermercado));
    s->lucro = 0;
    s->qntAlocada = 0;
    s->qntProdutos = 0;

    s->lista = malloc(sizeof(Produto*));

    return s;
}

/**
 * @brief Destrói uma instância de Supermercado.
 * 
 * @param s Ponteiro para a instância de Supermercado a ser destruída.
 */
void LiberaSupermercado (Supermercado* s)
{
    if(s!=NULL)
    {
        for(int i=0;i<s->qntProdutos;i++)
        {
            LiberaProduto(s->lista[i]);
        }

        free(s->lista);
        free(s);
    }
}

/**
 * @brief Verifica se um produto está cadastrado no supermercado.
 * 
 * @param s Ponteiro para a instância de Supermercado a ser verificada.
 * @param codigo Código do produto a ser verificado.
 * @return int 1 se o produto está cadastrado, 0 caso contrário.
 */
int VerificarProdutoCadastrado (Supermercado* s, int codigo)
{
    for(int i=0;i<s->qntProdutos;i++)
    {
        if(ObterCodigoProduto(s->lista[i])==codigo)
            return 1;
    }

    return 0;
}

/**
 * @brief Lê os dados de cadastro de um produto e o cadastra no supermercado.
 * 
 * @param s Ponteiro para a instância de Supermercado a ser atualizada.
 */
void LerCadastroSupermercado(Supermercado* s)
{
    Produto* p = CriarProduto();
    int cod;
    scanf("%d\n",&cod);
    LeProduto(p,cod);

   CadastrarProdutoSupermercado(s,p);
}

/**
 * @brief Cadastra um novo produto no supermercado caso ele não esteja cadastrado.
 * 
 * @param s Ponteiro para a instância de Supermercado a ser atualizada.
 * @param p Ponteiro para o produto a ser cadastrado.
 */
void CadastrarProdutoSupermercado(Supermercado *s, Produto *p)
{
   if(VerificarProdutoCadastrado(s,ObterCodigoProduto(p)))
   {
        LiberaProduto(p);
        return;
   }

    ImprimirNomeProduto(p);
    printf(" foi cadastrado(a)\n");

    s->lista[s->qntProdutos] = p;
    s->qntAlocada++;
    s->qntProdutos++;
    s->lista = realloc(s->lista,(s->qntProdutos+1)*sizeof(Produto*));
}

/**
 * @brief Compra um produto do supermercado.
 * 
 * @param s Ponteiro para a instância de Supermercado a ser atualizada.
 * @param codigo código do produto a ser alugado.
 */
void ComprarProdutoSupermercado(Supermercado* s, int codigo)
{
    for(int i=0;i<s->qntProdutos;i++)
    {
        if(EhMesmoCodigoProduto(s->lista[i],codigo))
        {
            if(ObterQtdEstoqueProduto(s->lista[i])>0)
            {
                ComprarProduto(s->lista[i]);
                s->lucro += ObterValorProduto(s->lista[i]);
                ImprimirNomeProduto(s->lista[i]);
                printf(" foi comprado(a)\n");
                return;
            }
            else
            {
                ImprimirNomeProduto(s->lista[i]);
                printf(" sem estoque\n");
                return;
            }
        }
    }

    printf("Codigo nao cadastrado no supermercado\n");
}

/**
 * @brief Lê a compra de um conjunto de produtos a partir da entrada padrão e os compra no supermercado.
 * 
 * @param s Ponteiro para a instância de Supermercado a ser atualizada.
 */
void LerCompraSupermercado(Supermercado* s)
{
    int qnt;
    scanf("%d\n",&qnt);

    for(int i=0;i<qnt;i++)
    {
        int codigo;
        scanf("%d\n",&codigo);
        ComprarProdutoSupermercado(s,codigo);
        
    }

}

/**
 * @brief Adiciona a qtdFornecida do produto ao estoque do supermercado
 * 
 * @param s Ponteiro para a instancia de Supermercado a ser atualizada
 * @param codigo codigo do produto ja cadastrado no supermercado
 * @param qtdFornecida quantidade do produto fornecida ao supermercado
 */
void FornecerProdutoSupermercado(Supermercado* s, int codigo, int qtdFornecida)
{
    for(int i=0;i<s->qntProdutos;i++)
    {
        if(EhMesmoCodigoProduto(s->lista[i],codigo))
        {
            AumentaEstoque(s->lista[i],qtdFornecida);
            ImprimirNomeProduto(s->lista[i]);
            printf(" teve estoque aumentado\n");
            return;
        }
    }

    printf("Codigo nao cadastrado no supermercado\n");
}

/**
 * @brief Le o fornecimento de um quantidade de um produto ja cadastrado e o fornece pro supermercado 
 * 
 * @param s Ponteiro para a instancia de Supermercado a ser atualizada
 */
void LerFornecimento(Supermercado* s)
{
    int cod, qnt;
    scanf("%d %d\n",&cod,&qnt);

    FornecerProdutoSupermercado(s,cod,qnt);

}

/**
 * @brief Ordena os produtos cadastrados no supermercado por ordem alfabética.
 * 
 * @param s Ponteiro para a instância de Supermercado a ser atualizada.
 */
void OrdenarProdutosSupermercado(Supermercado* s)
{
    for(int i=0;i<s->qntProdutos;i++)
    {
        for(int j=i+1;j<s->qntProdutos;j++)
        {
            if(CompararNomesProdutos(s->lista[i],s->lista[j])==1)
            {
                Produto* temp = s->lista[i];
                s->lista[i] = s->lista[j];
                s->lista[j] = temp;
            }
        }
    }
}

/**
 * @brief Consulta o estoque de produtos do supermercado.
 * 
 * @param s Ponteiro para a instância de Supermercado a ser consultada.
 */
void ConsultarEstoqueSupermercado (Supermercado* s)
{
    OrdenarProdutosSupermercado(s);
    for(int i=0;i<s->qntProdutos;i++)
    {
        printf("%d - ",ObterCodigoProduto(s->lista[i]));
        ImprimirNomeProduto(s->lista[i]);
        printf(" - %d\n",ObterQtdEstoqueProduto(s->lista[i]));
    }
}

/**
 * @brief Consulta o lucro do supermercado.
 * 
 * @param s Ponteiro para a instância de Supermercado a ser consultada.
 */
void ConsultarLucroSupermercado (Supermercado* s)
{
    printf("Lucro do supermercado: %.2f\n",s->lucro);
}