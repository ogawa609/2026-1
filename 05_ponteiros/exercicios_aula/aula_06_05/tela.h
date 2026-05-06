#ifndef _TELA_H
#define _TELA_H

#include "botao.h"

#define MAX_BOTOES 10
typedef struct {
    int altura;
    int largura;
    Botao botoes[MAX_BOTOES];
    int qntBotoes;
}Tela;

/*
Funcao que cria uma tela de acordo com a altura e largura passadas por parametro

@param altura: Inteiro que define a altura da tela
@param largura: Inteiro que define a largura da tela

@return Tela: Tela criada
*/
Tela criarTela (int altura, int largura);

/*
Funcao que adiciona um novo botao a tela

@param t: Tela a ser atualizada com o novo botao
@param b: Botao a ser adicionado a tela

@return Tela: Tela criada
*/
void registraBotaoTela(Tela *t, Botao b);

/*
Funcao que desenha a tela (desenha todos os botões que foram registrados).

@param t: Tela a ser desenhada (e seus respectivos botoes)
*/
void desenhaTela (Tela *t);

/*
Funcao que aguarda um evento de clique (simulado pela leitura do teclado). 
O clique é simulado pela seleção de uma das opções dos botões.
Exemplo - clicar no primeiro botão significa escolher a opção "1" pelo terminal. 

@param t: Tela criada que aguarda um evento para executar uma funcao de Callback
*/
void ouvidorEventosTela(Tela t);

#endif