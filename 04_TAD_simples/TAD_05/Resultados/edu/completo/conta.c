#include <stdio.h>
#include "conta.h"
#include "usuario.h"


/**
 * @brief Cria uma nova conta bancária.
 * @param numero Número da conta.
 * @param user Usuário da conta.
 * @return A nova conta criada.
 */
tConta CriaConta(int numero, tUsuario user)
{
    tConta c;
    c.numero=numero;
    c.saldo=0;
    c.user=user;

    return c;
}

/**
 * @brief Imprime os dados de uma conta bancária.
 * @param conta Conta bancária a ser impressa.
 */
void ImprimeConta(tConta conta)
{
    printf("Conta: %d\n",conta.numero);
    printf("Saldo: R$ %.2f\n",conta.saldo);
    ImprimeUsuario(conta.user);
}

/**
 * @brief Compara o número de uma conta bancária com um número dado.
 * @param conta Conta bancária a ser comparada.
 * @param numero Número a ser comparado.
 * @return 1 se os números forem iguais, 0 caso contrário.
 */
int VerificaConta(tConta conta, int numero)
{
    if(conta.numero==numero)
        return 1;

    return 0;
}

/**
 * @brief Realiza um saque em uma conta bancária.
 * @param conta Conta bancária a ser sacada.
 * @param valor Valor a ser sacado.
 * @return A conta com o novo saldo após o saque.
 */
tConta SaqueConta(tConta conta, float valor)
{
    if(conta.saldo>=valor)
        conta.saldo-=valor;
    
    return conta;
}

/**
 * @brief Realiza um depósito em uma conta bancária.
 * @param conta Conta bancária a ser depositada.
 * @param valor Valor a ser depositado.
 * @return A conta com o novo saldo após o depósito.
 */
tConta DepositoConta(tConta conta, float valor)
{
    conta.saldo+=valor;

    return conta;
}