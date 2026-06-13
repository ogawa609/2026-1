#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conta.h"


struct Conta{
    int numero;
    char* nome;
    float saldo;
};
/**
 * @brief Função para criar uma nova conta bancária.
 * @return Um ponteiro para a nova conta bancária criada. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tConta *CriaConta()
{
    tConta* c = malloc(sizeof(tConta));
    c->saldo = 0;
    return c;
}

/**
 * @brief Função para destruir uma conta bancária.
 * @param conta A conta bancária a ser destruída.
 */
void DestroiConta(DataType conta)
{
    tConta* c = (tConta*) conta;

    free(c->nome);
    free(c);
}

/**
 * @brief Função para ler uma conta bancária no formato "numero;nome do cliente;saldo inicial".
 * @param conta A conta bancária a ser lida.
 */
void LeConta(tConta *conta)
{
    char nome[100];
    scanf("%d;%[^;];%f\n",&conta->numero,nome,&conta->saldo);

    int tam = strlen(nome) + 1;
    conta->nome = malloc(tam*sizeof(char));
    strcpy(conta->nome,nome);

}

/**
 * @brief Função para obter o saldo de uma conta bancária.
 * @param conta A conta bancária.
 * @return O saldo da conta bancária.
 */
float GetSaldoConta(tConta *conta)
{
    return conta->saldo;
}
