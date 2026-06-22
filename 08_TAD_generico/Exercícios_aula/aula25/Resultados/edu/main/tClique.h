#ifndef _TCLIQUE_H
#define _TCLIQUE_H

#include "tAmbiente.h"

typedef struct clique tClique;

/// @brief Função que cria um evento do tipo movimento
/// @param caracteresAceitos - Vetor de QUATRO caracteres que irá representar movimento
///                             na ordem: CIMA, ESQUERDA, BAIXO, DIREITA
/// @return O ponteiro para a variável do tipo evento movimento
tClique* criaEventoClique(char *caracteresAceitos);

/// @brief Função que libera o evento...
/// @param eve - Ponteiro para o evento
void liberaEventoClique(void* eve);

/// @brief Função que executará o comportamento de um evento movimento
///         No caso, deve alterar o ambiente de acordo com a tecla apertada, se for possível
/// @param amb - Ponteiro para o ambiente a ser manipulado
/// @param eve - Ponteiro para o evento de movimento 
/// @param c - Caractere que foi digitado no teclado
void processaEventoClique(tAmbiente *amb, void *eve, char c);

/// @brief Função que indica se um caractere apertado está registrado nos caracteres válidos de um movimento
/// @param eve - ponteiro para a variável evento
/// @param c - Caractere que foi digitado no teclado
/// @return 1 se o caractere digitado está registrado como um caractere do evento
int identificaEventoClique(void *eve, char c);
#endif