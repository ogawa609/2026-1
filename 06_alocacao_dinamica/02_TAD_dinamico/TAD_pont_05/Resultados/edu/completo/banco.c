#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "banco.h"



/**
 * @brief Cria um novo banco, com 5 contas alocadas e nenhuma conta aberta.
 * Se não for possível alocar memória, o programa é encerrado.
 * 
 * @return Um ponteiro para o novo banco criado.
 */
tBanco *CriaBanco()
{
    tBanco*b = malloc(sizeof(tBanco));
    b->contasAlocadas=0;
    b->qtdContas=0;
    b->contas= malloc(sizeof(tConta*));

    return b;
}

/**
 * @brief Desaloca a memória de um banco e de todas as suas contas.
 * 
 * @param banco Ponteiro para o banco a ser destruído.
 */
void DestroiBanco(tBanco *banco)
{
    for(int i=0;i<banco->qtdContas;i++)
    {
        DestroiConta(banco->contas[i]);
    }
    free(banco->contas);
    free(banco);
}

/**
 * @brief Abre uma nova conta no banco e a adiciona ao vetor de contas.
 * 
 * @param banco Ponteiro para o banco onde a conta será aberta.
 */
void AbreContaBanco(tBanco *banco)
{
    tConta* cc = CriaConta();
    LeConta(cc);

    banco->contas[banco->contasAlocadas] = cc;
    banco->contasAlocadas++;
    banco->qtdContas++;

    banco->contas = realloc(banco->contas,(banco->contasAlocadas+1)*sizeof(tConta*));
}

/**
 * @brief Realiza um saque em uma conta do banco se ela existir e tiver saldo suficiente.
 * 
 * @param banco Ponteiro para o banco onde a conta será sacada.
 */
void SaqueContaBanco(tBanco *banco)
{
    int cc;
    float valor;
    scanf("%d %f\n",&cc,&valor);

    for(int i=0;i<banco->qtdContas;i++)
    {
        if(VerificaConta(banco->contas[i],cc))
        {
            SaqueConta(banco->contas[i],valor);
            break;
        }
    }
}

/**
 * @brief Realiza um depósito em uma conta do banco se ela existir.
 * 
 * @param banco Ponteiro para o banco onde a conta será depositada.
 */
void DepositoContaBanco(tBanco *banco)
{
     int cc;
    float valor;
    scanf("%d %f\n",&cc,&valor);

    for(int i=0;i<banco->qtdContas;i++)
    {
        if(VerificaConta(banco->contas[i],cc))
        {
            DepositoConta(banco->contas[i],valor);
            break;
        }
    }
}

/**
 * @brief Realiza uma transferência entre duas contas do banco se elas existirem e a conta de origem tiver saldo suficiente.
 * 
 * @param banco Ponteiro para o banco onde as contas estão.
 */
void TransferenciaContaBanco(tBanco *banco)
{
     int c1,c2;
    float valor;
    int i1,i2;
    scanf("%d %d %f\n",&c1,&c2,&valor);

    for(int i=0;i<banco->qtdContas;i++)
    {
        if(VerificaConta(banco->contas[i],c1))
            i1=i;
        else if(VerificaConta(banco->contas[i],c2))
            i2=i;
        
    }

    TransferenciaConta(banco->contas[i1],banco->contas[i2],valor);
}

/**
 * @brief Imprime o relatório do banco, com todas as contas e seus respectivos dados.
 * 
 * @param banco Ponteiro para o banco a ser impresso.
 */
void ImprimeRelatorioBanco(tBanco *banco)
{
    printf("===| Imprimindo Relatorio |===\n");

    for(int i=0;i<banco->qtdContas;i++)
    {
        ImprimeConta(banco->contas[i]);
    }
}