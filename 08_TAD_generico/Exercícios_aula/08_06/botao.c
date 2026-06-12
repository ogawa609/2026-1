#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "botao.h"

struct Botao 
{
    char *texto;
    int tamFonte;
    char *corHex;    
};


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
Botao *criarBotao(char *texto, int tamFonte, char *cor)
{
    Botao* b = malloc(sizeof(struct Botao));

    int tam = strlen(texto) + 1;
    b->texto = malloc(tam*sizeof(char));
    strcpy(b->texto,texto);

    tam = strlen(cor) + 1;
    b->corHex = malloc(tam*sizeof(char));
    strcpy(b->corHex,cor);

    b->tamFonte = tamFonte;

    return b;
}

/**
 * @brief Exibe um botão na tela.
 *
 * Recebe um ponteiro genérico para um botão e apresenta suas
 * informações visuais na saída.
 *
 * @param widget Ponteiro para o botão a ser exibido.
 */
void exibeBotao(void *widget)
{
    Botao* b = (Botao*) widget;

    printf("#########\n");
    printf("%s|%d|%s\n",b->texto,b->tamFonte,b->corHex);
    printf("#########\n\n");
}

/**
 * @brief Executa a ação associada ao clique de um botão.
 *
 * Simula ou processa o evento de clique sobre o botão informado.
 *
 * @param widget Ponteiro para o botão que recebeu o clique.
 */
void executaClickBotao(void *widget)
{
    Botao* b = (Botao*) widget;
    printf("- Botao de %s dados ativado\n",b->texto);
}

/**
 * @brief Libera os recursos associados a um botão.
 *
 * Desaloca toda a memória utilizada pelo botão.
 *
 * @param widget Ponteiro para o botão a ser destruído.
 */
void desalocaBotao(void *widget)
{
    Botao* b = (Botao*) widget;

    free(b->corHex);
    free(b->texto);
    free(b);
}