#include <stdio.h>
#include "loja.h"

/**
 * @brief Abre uma nova loja.
 * 
 * @param id ID da loja.
 * @param aluguel Valor do aluguel da loja.
 * @return tLoja Retorna a estrutura do tipo tLoja com os dados da loja aberta.
 */
tLoja AbreLoja(int id, float aluguel)
{
    tLoja l;
    l.aluguel = aluguel;
    l.id = id;
    l.lucro = 0;
    l.totalVendedores = 0;
    
    return l;
}

/**
 * @brief Verifica se o ID de uma loja é igual a outro.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja a ser verificada.
 * @param id ID da loja a ser comparado.
 * @return int Retorna 1 se o ID da loja é igual ao ID passado como parâmetro, ou 0 caso contrário.
 */
int VerificaIdLoja(tLoja loja, int id)
{
    return (loja.id==id);
}

/**
 * @brief Contrata um novo vendedor para a loja.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor a ser contratado.
 * @return tLoja Retorna a estrutura do tipo tLoja atualizada com o novo vendedor contratado.
 */
tLoja ContrataVendedor(tLoja loja, tVendedor vendedor)
{
    loja.vendedores[loja.totalVendedores] = vendedor;
    loja.totalVendedores++;

    return loja;
}

/**
 * @brief Registra uma nova venda para um vendedor da loja.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 * @param nome Nome do vendedor que realizou a venda.
 * @param valor Valor da venda a ser registrada.
 * @return tLoja Retorna a estrutura do tipo tLoja atualizada com a venda registrada.
 */
tLoja RegistraVenda(tLoja loja, char nome[50], float valor)
{
    for(int i=0;i<loja.totalVendedores;i++)
    {
        if(VerificaNomeVendedor(loja.vendedores[i],nome))
           loja.vendedores[i] = ContabilizaVenda(loja.vendedores[i],valor);

    }

    return loja;
}

/**
 * @brief Calcula o lucro da loja.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 * @return tLoja Retorna a estrutura do tipo tLoja atualizada com o lucro calculado.
 */
tLoja CalculaLucro(tLoja loja)
{
    float valorBruto = 0;
    float salario = 0;

    for(int i=0;i<loja.totalVendedores;i++)
    {
        valorBruto += GetTotalVendido(loja.vendedores[i]);
        salario += GetTotalRecebido(loja.vendedores[i]);
    }

   loja.lucro += valorBruto - (salario+loja.aluguel);
   return loja;
}

/**
 * @brief Imprime o relatório da loja.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 */
void ImprimeRelatorioLoja(tLoja loja)
{
    printf("Loja %d: Lucro total: R$ %.2f\n",loja.id,loja.lucro);

    for(int i=0;i<loja.totalVendedores;i++)
    {
        
        ImprimeRelatorioVendedor(loja.vendedores[i]);
    }
} 