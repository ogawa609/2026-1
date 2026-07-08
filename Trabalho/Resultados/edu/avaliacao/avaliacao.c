#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avaliacao.h"

struct Avaliacao{

    char* cpf;
    int nota;
};



/// @brief Cria um objeto do tipo tAvaliacao.
/// @param cpf CPF da pessoa que fez a avaliação.
/// @param nota Nota atribuída pela pessoa.
/// @return A avaliação criada.

tAvaliacao* criaAvaliacao(char* cpf, int nota)
{
    tAvaliacao* a = malloc(sizeof(tAvaliacao));

    int tam = strlen(cpf) + 1;
    a->cpf = malloc(tam*sizeof(char));

    strcpy(a->cpf,cpf);

    a->nota = nota;

    return a;
}


/// @brief Retorna a nota de uma avaliação.
/// @param a Ponteiro para a avaliação.
/// @return A nota da avaliação.
int getNotaAvaliacao(tAvaliacao *a)
{
    return a->nota;
}


/// @brief Retorna o CPF de quem fez uma avaliação.
/// @param a Ponteiro para a avaliação.
/// @return O CPF do responsável pela avaliação.
char* getCpfAvaliacao(tAvaliacao *a)
{
    return a->cpf;
}

/// @brief Libera a memória alocada para uma avaliação.
/// @param avaliacao Ponteiro para a avaliação que será liberada.
void liberaAvaliacao(tAvaliacao *avaliacao)
{
    free(avaliacao->cpf);
    free(avaliacao);
}
