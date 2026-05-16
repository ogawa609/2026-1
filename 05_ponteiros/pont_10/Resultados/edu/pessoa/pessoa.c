#include <stdio.h>
#include <string.h>
#include "pessoa.h"


/**
 * @brief Cria uma nova pessoa com nome vazio (primeiro caractere igual a '\0') e inicializa os ponteiros para pai, mae e irmao com NULL.
 * 
 * @return Uma nova pessoa e sem pais e irmao.
 */
tPessoa CriaPessoa()
{
    tPessoa p;
    p.irmao = NULL;
    p.mae = NULL;
    p.pai = NULL;
    p.nome[0]='\0';

    return p;
}

/**
 * @brief Lê os dados de uma pessoa.
 * 
 * @param pessoa Ponteiro para a pessoa a ser lida.
 */
void LePessoa(tPessoa *pessoa)
{
    
    scanf(" %[^\n]\n",pessoa->nome);

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
    return !((pessoa->mae==NULL)&&(pessoa->pai==NULL));
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
        if(pessoa->pai!=NULL)
            printf("PAI: %s\n",pessoa->pai->nome);
        else
            printf("PAI: NAO INFORMADO\n");

        if(pessoa->mae != NULL)
            printf("MAE: %s\n",pessoa->mae->nome);
        else 

            printf("MAE: NAO INFORMADO\n");

        if(pessoa->irmao!=NULL)
            printf("IRMAO: %s\n",pessoa->irmao->nome);
        else
            printf("IRMAO: NAO INFORMADO\n");
    }
}

/**
 * @brief Verifica se duas pessoas são irmãos, ou seja, se os ponteiros pai e mae são iguais.
 * 
 * @param pessoa1 Ponteiro para a primeira pessoa.
 * @param pessoa2 Ponteiro para a segunda pessoa.
 * 
 * @return 1 se as pessoas forem irmãos e 0 caso contrário.
*/
int VerificaIrmaoPessoa(tPessoa *pessoa1, tPessoa *pessoa2)
{
    if(!VerificaSeTemPaisPessoa(pessoa1)&&!VerificaSeTemPaisPessoa(pessoa2))
        return 0;
    
    return (pessoa1->mae==pessoa2->mae||pessoa1->pai==pessoa2->pai);
}


/**
 * @brief Le as associciacoes da entrada padrao e altera as pessoas de forma a representar as associacoes lidas
 * 
 * Apos a associado dos pais, voce deve verificar se ha irmaos e associar os irmaos.
 * 
 * @param pessoas Ponteiro para a lista de pessoas a serem associadas.
 * @param numPessoas Numero de pessoas a serem associadas (tamanho do vetor).
 */
void AssociaFamiliasGruposPessoas(tPessoa *pessoas, int numPessoas)
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

    for(int i=0;i<numPessoas;i++)
    {
        for(int j=i+1;j<numPessoas-1;j++)
        {
            if(VerificaIrmaoPessoa((pessoas+i),(pessoas+j)))
            {
                 pessoas[j].irmao = &pessoas[i];
                 pessoas[i].irmao = &pessoas[j];
            }
                
        }
    }
}

