#include <string.h>
#include <stdio.h>
#include "tela.h"


/*
Funcao que cria uma tela de acordo com a altura e largura passadas por parametro

@param altura: Inteiro que define a altura da tela
@param largura: Inteiro que define a largura da tela

@return Tela: Tela criada
*/
Tela criarTela (int altura, int largura)
{
    Tela tela;
    tela.altura = altura;
    tela.largura = largura;
    tela.qntBotoes = 0;

    return tela;
}

/*
Funcao que adiciona um novo botao a tela

@param t: Tela a ser atualizada com o novo botao
@param b: Botao a ser adicionado a tela

@return Tela: Tela criada
*/
void registraBotaoTela(Tela *t, Botao b)
{
    t->botoes[t->qntBotoes] = b;
    t->qntBotoes ++;
}

/*
Funcao que desenha a tela (desenha todos os botões que foram registrados).

@param t: Tela a ser desenhada (e seus respectivos botoes)
*/
void desenhaTela (Tela *t)
{
    printf("============================================================\n\n\n");

    for(int i= 0; i<t->qntBotoes;i++)
    {
        desenhaBotao(t->botoes[i],i);

    }



    printf("============================================================\n");

     
}

/*
Funcao que aguarda um evento de clique (simulado pela leitura do teclado). 
O clique é simulado pela seleção de uma das opções dos botões.
Exemplo - clicar no primeiro botão significa escolher a opção "1" pelo terminal. 

@param t: Tela criada que aguarda um evento para executar uma funcao de Callback
*/
void ouvidorEventosTela(Tela t)
{
    int idx;
    scanf("%d",&idx);

    executaBotao(t.botoes[idx]);
}