#ifndef _BOTAO_H
#define _BOTAO_H

#define MAX_TAM_TEXTO 30
#define MAX_TAM_COR 7
typedef struct Botao Botao;

/*
struct Botao 
{
    char *texto;
    int tamFonte;
    char *corHex;    
};
*/

/**
 * @brief Cria um botão.
 *
 * Aloca memória para um novo botão e inicializa seus atributos.
 *
 * @param texto Texto exibido no botão.
 * @param tamFonte Tamanho da fonte utilizada para exibição do texto.
 * @param cor Cor do botão.
 *
 * @return Ponteiro para o botão criado. Retorna NULL em caso de falha
 *         na alocação de memória.
 */
Botao *criarBotao(char *texto, int tamFonte, char *cor);

/**
 * @brief Exibe um botão na tela.
 *
 * Recebe um ponteiro genérico para um botão e apresenta suas
 * informações visuais na saída.
 *
 * @param widget Ponteiro para o botão a ser exibido.
 */
void exibeBotao(void *widget);

/**
 * @brief Executa a ação associada ao clique de um botão.
 *
 * Simula ou processa o evento de clique sobre o botão informado.
 *
 * @param widget Ponteiro para o botão que recebeu o clique.
 */
void executaClickBotao(void *widget);

/**
 * @brief Libera os recursos associados a um botão.
 *
 * Desaloca toda a memória utilizada pelo botão.
 *
 * @param widget Ponteiro para o botão a ser destruído.
 */
void desalocaBotao(void *widget);

#endif
