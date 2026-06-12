#include <stdio.h>
#include <stdlib.h>
#include "pacote.h"

struct pacote{
    Type tipo;
    int numElem;
    void* dado;
    int soma;
};
/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar um pacote a ser transmitido
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tPacote* CriaPacote(Type type, int numElem)
{
    tPacote* p = malloc(sizeof(tPacote));
    p->numElem = numElem;
    p->tipo = type;
    p->soma = 0;

    if(type==CHAR)
        p->dado = malloc(numElem*sizeof(char));
    else
        p->dado = malloc(numElem*sizeof(int));

    return p;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param pac - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiPacote(tPacote* pac)
{
    free(pac->dado);
    free(pac);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param pac - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LePacote(tPacote* pac)
{
    for(int i=0;i<pac->numElem;i++)
    {
        if(pac->tipo==INT)
            scanf("%d",&((int*)pac->dado)[i]);
        else
            scanf("%c",&((char*)pac->dado)[i]);
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param pac - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimePacote(tPacote* pac)
{
    printf("%d ",pac->soma);
    for(int i=0;i<pac->numElem;i++)
    {
        if(pac->tipo==INT)
            printf("%d ",((int*)pac->dado)[i]);
        else
            printf("%%c",((char*)pac->dado)[i]);
    }
    printf("\n");
}

/**
 * @brief Calcula a soma de verificacao de um pacote e a armazena internamente
 *
 * @param pac - O vetor genérico que terá sua soma de verificacao calculada
 */
void CalculaSomaVerificacaoPacote(tPacote* pac)
{
    
int soma=0;
    for(int i=0;i<pac->numElem;i++)
    {
        if(pac->tipo==INT)
            soma+= ((int*)pac->dado)[i];
        else
            soma+= (int)((char*)pac->dado)[i];
    }
    pac->soma = soma;
}