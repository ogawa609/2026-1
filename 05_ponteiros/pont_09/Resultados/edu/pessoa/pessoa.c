#include <stdio.h>
#include <string.h>
#include "pessoa.h"

/**
 * @brief Cria uma nova pessoa com nome vazio (primeiro caractere igual a '\0') e inicializa os ponteiros para pai e mae com NULL.
 * 
 * @return Uma nova pessoa e sem pais.
 */
tPessoa CriaPessoa()
{
    tPessoa p;
    p.nome[0] = '\0';
    p.mae = NULL;
    p.pai = NULL;

    return p;
}

/**
 * @brief Lê os dados de uma pessoa.
 * 
 * @param pessoa Ponteiro para a pessoa a ser lida.
 */
void LePessoa(tPessoa *pessoa)
{
    char nome[100];
    scanf(" %[^\n]",nome);

    strcpy(pessoa->nome,nome);
}

/**
 * @brief Verifica se uma pessoa tem pai e/ou mae associado(s).
 * Ou seja, verifica pelo menos um dos ponteiros pai e mae é diferente de NULL.
 * 
 * @param pessoa Ponteiro para a pessoa a ser verificada.
 * 
 * @return 1 se a pessoa tiver pai e/ou mae associado(s) e 0 caso contrário.
*/
int VerificaSeTemPaisPessoa(tPessoa *pessoa)
{
    return (pessoa->mae!=NULL||pessoa->pai!=NULL);
}

/**
 * @brief Imprime os dados de uma pessoa caso tenha pai e/ou mae associado(s).
 * Dica: use a função VerificaSeTemPaisPessoa para verificar se a pessoa tem pai e/ou mae associado(s).
 * Alem disso, imprimir o nome do irmao caso exista.
 * 
 * @param pessoa Ponteiro para a pessoa a ser impressa.
 */
void ImprimePessoa(tPessoa *pessoa)
{
    
    if(VerificaSeTemPaisPessoa(pessoa))
    {
        printf("NOME COMPLETO: %s\n",pessoa->nome);
        
        if(pessoa->pai==NULL)
            printf("PAI: NAO INFORMADO\n");
        else
            printf("PAI: %s\n",pessoa->pai->nome);

        if(pessoa->mae==NULL)
            printf("MAE: NAO INFORMADO\n");
        else 
            printf("MAE: %s\n",pessoa->mae->nome);


    
    }

}

/**
 * @brief Le as associciacoes da entrada padrao e altera as pessoas de forma a representar as associacoes lidas
 * 
 * @param pessoas Ponteiro para a lista de pessoas a serem associadas.
 */
void AssociaFamiliasGruposPessoas(tPessoa *pessoas)
{
    int qnt;

    scanf("%d\n",&qnt);

    for(int i=0;i<qnt;i++)
    {
        int im,ip,ifi;
        scanf("mae: %d, pai: %d, filho: %d\n",&im,&ip,&ifi);

        if(im!=-1)
            pessoas[ifi].mae = &pessoas[im];
        
        if(ip!=-1)
            
            pessoas[ifi].pai = pessoas+ip;
    
    }
}