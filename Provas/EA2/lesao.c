#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lesao.h"



struct Lesao
{
    char *id;        // salva o id da lesão
    char *diag;      // salva o diagnóstico da lesão
    char *regiao;    // salva a região da lesão
    int malignidade; // salva o grau de malignidade da lesão
    
};


/*
Função que cria uma estrutura Lesao (alocando memória para o que for necessário), lê os valores da entrada padrão
de acordo com a descrição, e retorna o ponteiro para a estrutura criada.
*/
tLesao *leLesao()
{
    char id[TAM_ID];
    char diag[TAM_DIAG];
    char regiao[TAM_REG];
    int malignidade;
    

   
    scanf("%[^\n]\n",id);
    scanf("%[^\n]\n",diag);
    scanf("%[^\n]\n",regiao);
    scanf("%d\n",&malignidade);

    tLesao* l = (tLesao*) malloc(sizeof(tLesao));

    int tam = strlen(id) + 1 ;
    l->id = (char*) malloc(sizeof(char)*tam);

    tam = strlen(diag) + 1 ;
    l->diag = (char*) malloc(sizeof(char)*tam);

    tam = strlen(regiao) + 1;
    l->regiao = (char*) malloc(sizeof(char)*tam);

    


    strcpy(l->diag,diag);
    strcpy(l->id,id);
    strcpy(l->regiao,regiao);
    l->malignidade = malignidade;

    return l;

}

/*
Função que libera a memória alocada para a estrutura Lesao.
Ela verifica se o ponteiro passado é nulo antes de tentar liberar a memória.
*/
void liberaLesao(tLesao *l)
{
    free(l->diag);
    free(l->id);
    free(l->regiao);
    free(l);
}

/*
Função que retorna o Id da lesão passada como parâmetro.
*/
char *getIdLesao(tLesao *l)
{
    return l->id;
}

/*
Função que calcula se a lesão passada como parâmetro precisa de cirurgia de acordo com a regra
informada na descrição.
*/
int precisaCirurgiaLesao(tLesao *l)
{
    return l->malignidade > 50;
}