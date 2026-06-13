#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "agencia.h"

struct Agencia{

    int num;
    char *nome;
    Vector* contas;
};
/**
 * @brief Função para criar uma nova agência bancária.
 * @return Um ponteiro para a nova agência bancária criada. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tAgencia *CriaAgencia()
{
    tAgencia* a = malloc(sizeof(tAgencia));
    a->contas = VectorConstruct();

    return a;
}

/**
 * @brief Função para destruir uma agência bancária.
 * @param agencia A agência bancária a ser destruída.
 */
void DestroiAgencia(DataType agencia)
{
    tAgencia* a = (tAgencia*) agencia;
    VectorDestroy(a->contas,DestroiConta);
    free(a->nome);
    free(a);

}

/**
 * @brief Função para ler uma agência bancária no formato "numero;nome".
 * @param agencia A agência bancária a ser lida.
 */
void LeAgencia(tAgencia *agencia)
{
    char nome[100];
    scanf("%d;%[^\n]\n",&agencia->num,nome);

    int tam = strlen(nome) + 1;
    agencia->nome = malloc(tam*sizeof(char));
    strcpy(agencia->nome,nome);


}

/**
 * @brief Função para adicionar uma conta bancária a uma agência bancária.
 * @param agencia A agência bancária.
 * @param conta A conta bancária a ser adicionada.
 */
void AdicionaConta(tAgencia *agencia, tConta *conta)
{
    VectorPushBack(agencia->contas,conta);
}

/**
 * @brief Função para comparar um número de agência bancária com uma agência bancária.
 * @param numAgencia O número da agência bancária.
 * @param agencia2 A agência bancária a ser comparada.
 * @return 1 se os números forem iguais, 0 caso contrário.
 */
int ComparaAgencia(int numAgencia, tAgencia *agencia2)
{
    return numAgencia == agencia2->num;
}

/**
 * @brief Função para obter o saldo médio das contas de uma agência bancária.
 * @param agencia A agência bancária.
 * @return O saldo médio das contas da agência.
 */
float GetSaldoMedioAgencia (tAgencia *agencia)
{
    float saldo =0;
    for(int i=0;i<VectorSize(agencia->contas);i++)
    {
        tConta* c = (tConta*) VectorGet(agencia->contas,i);
        saldo += GetSaldoConta(c);
    }

    return saldo/VectorSize(agencia->contas);
}

/**
 * @brief Função para imprimir os dados de uma agência bancária (nome, número, número de contas cadastradas e saldo médio).
 * @param agencia A agência bancária.
 */
void ImprimeDadosAgencia(tAgencia *agencia)
{
    printf("Nome: %s\n",agencia->nome);
    printf("Numero: %d\n",agencia->num);
    printf("Numero de contas cadastradas: %d\n",VectorSize(agencia->contas));
    printf("Saldo médio: R$%.2f\n",GetSaldoMedioAgencia(agencia));
}