#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"

struct Movie{
    char* nome;
    char* diretor;
    char* tipo;
    int ano;
    int duracao;
};

/**
 * @brief Lê os dados de um filme da entrada padrão e constrói a estrutura correspondente.
 * A ordem de leitura esperada é: Título, Diretor(a), Gênero, Ano de lançamento e Duração (em minutos).
 * @return Ponteiro para a estrutura Movie recém-criada.
 */
Movie *movie_read_and_construct()
{
    Movie* m = malloc(sizeof(Movie));
    
    char nome[MAX_TAM_STRING];
    char diretor[MAX_TAM_STRING];
    char genero[MAX_TAM_STRING];
    int ano, dur;

    scanf("%s %s %s %d %d\n",nome,diretor,genero,&ano,&dur);

    int tam = strlen(nome) + 1;
    m->nome = malloc(tam*sizeof(char));
    strcpy(m->nome,nome);

    tam = strlen(diretor) + 1;
    m->diretor = malloc(tam*sizeof(char));
    strcpy(m->diretor,diretor);

    tam = strlen(genero) + 1;
    m->tipo = malloc(tam*sizeof(char));
    strcpy(m->tipo,genero);

    m->ano = ano;
    m->duracao = dur;

    return m;
}

/**
 * @brief Imprime os dados formatados de um filme.
 * A formatação exibirá, linha por linha: o Nome, o Diretor, o Ano, o Gênero e a Duração.
 * @param m Ponteiro genérico que aponta para a estrutura Movie.
 */
/*
MIDIA 3: FILME
Titulo: Tubarao
Diretor(a): Steven_Spielberg
Genero: Suspense
Ano de lancamento: 1975
Duracao: 124 min*/
void movie_print(void *m)
{
    Movie* f = (Movie*) m;
    printf("FILME\n");
    printf("Titulo: %s\n",f->nome);
    printf("Diretor(a): %s\n",f->diretor);
    printf("Genero: %s\n",f->tipo);
    printf("Ano de lancamento: %d\n",f->ano);
    printf("Duracao: %d min\n\n",f->duracao);
}

/**
 * @brief Libera a memória alocada para a estrutura de um filme.
 * @param m Ponteiro genérico que aponta para a estrutura Movie.
 */
void movie_free(void *m)
{
    Movie* f = (Movie*) m;
    free(f->diretor);
    free(f->nome);
    free(f->tipo);
    free(f);
}