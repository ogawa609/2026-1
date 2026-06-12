#include <stdio.h>
#include <stdlib.h>
#include "tadgen.h"

struct generic{

    Type tipo;
    int numElem;
    void* dados;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar tanto inteiros quanto floats
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tGeneric* CriaGenerico(Type type, int numElem)
{
    tGeneric* g = malloc(sizeof(tGeneric));
    g->numElem = numElem;
    g->tipo = type;

    if(type==INT)
        g->dados = malloc(numElem*sizeof(int));
    else
        g->dados = malloc(numElem*sizeof(float));
    
    return g;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param gen - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiGenerico(tGeneric* gen)
{
    free(gen->dados);
    free(gen);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param gen - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LeGenerico(tGeneric* gen)
{
    printf("\n");
    printf("Digite o vetor:\n");

    for(int i=0;i<gen->numElem;i++)
    {
        if(gen->tipo==INT)
            scanf("%d",&((int*)gen->dados)[i]);
        
        else
            scanf("%f",&((float*)gen->dados)[i]);
    }
}


/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param gen - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimeGenerico(tGeneric* gen)
{
    for(int i=0;i<gen->numElem;i++)
    {
        if(gen->tipo==INT)
            printf("%d ",((int*)gen->dados)[i]);
        
        else
            printf("%.2f ",((float*)gen->dados)[i]);
    }
}
