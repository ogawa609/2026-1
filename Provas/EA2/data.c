#include <stdio.h>
#include <stdlib.h>
#include "data.h"

struct Data
{
    int dia;
    int mes;
    int ano;
};



/*
Função que cria a estrutura Data (alocando memória), lê os valores da entrada padrão
de acordo com a descrição, e retorna o ponteiro para a estrutura criada.
*/
tData *leData()
{
    tData* data = (tData*) malloc(sizeof(tData));
    int dia, mes, ano;

    scanf("%d/%d/%d\n",&dia,&mes,&ano);
    data->dia =dia;
    data->ano = ano;
    data->mes = mes;

    return data;
}

/*
Função que cria uma estrutura Data (alocando memória), inicializa os campos da estrutura
com os valores passados como parâmetro, e retorna o ponteiro para a estrutura criada.
*/
tData *criaData(int dia, int mes, int ano)
{
    tData* data = (tData*) malloc(sizeof(tData));

    data->dia = dia;
    data->ano = ano;
    data->mes = mes;

    return data;
}

/*
Função que libera a memória alocada para a estrutura Data.
Ela verifica se o ponteiro passado é nulo antes de tentar liberar a memória.
*/
void liberaData(tData *d)
{
    free(d);
}

/*
Função que compara duas datas e retorna um valor inteiro que indica a diferença em anos.
Essa diferença deve ser calculada como nós calculamos a idade de uma pessoa. Ou seja, uma pessoa
que nasceu em 10/10/2000 no dia 15/09/2020 tem 19 anos.
*/
int calculaDiffAnosData(tData *d, tData *atual)
{
    int idade = atual->ano - d->ano;

    if(atual->mes < d->mes)
        idade--;
    else if(atual->mes == d->mes)
    {
        if(atual->dia < d->dia)
            idade--;
    }

    return idade;
}

/*
Função que imprime a data no formato dd/mm/aaaa.
Não é necessário incluir zeros à esquerda.
*/
void imprimeData(tData *d)
{
    printf("%02d/%02d/%d\n", d->dia,d->mes,d->ano);
}