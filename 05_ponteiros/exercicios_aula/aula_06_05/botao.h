#ifndef _BOTAO_H
#define _BOTAO_H

#define MAX_TAM_TEXTO 30
#define CLICK 1
#define LONGO_CLICK 2
#define HOVER 3

typedef struct {
    char texto[MAX_TAM_TEXTO];
    int tamFonte;
    char corHex[7];
    int tipo;
    void (*executa)(void);
}Botao;

/*
Funcao que atualiza o texto de um botao criado.

@param b: Botao.
@param novoTexto: String com o texto a ser atualizado.
*/
void setarTexto(Botao *b, char *novoTexto);

/*
Funcao que o tamanho da fonte do texto de um botao criado.

@param b: Botao.
@param novoTamFonte: Inteiro com o novo valor da fonte do texto do botao.
*/
void setarTamFonte(Botao *b, int novoTamFonte);

/*
Funcao que atualiza a cor do texto de um botão criado.

@param b: Botao.
@param novoTexto: String com a cor do texto a ser atualizada.
*/
void setarCor(Botao *b, char *novaCor);

/*
Funcao que atualiza o tipo de um botão criado.

@param b: Botao.
@param novoTexto: Inteiro com o tipo do botao.
*/
void setarTipo(Botao *b, int novoTipo);

/*
Funcao que cria um botao para ser exibido na tela.

@param texto: String com o texto do botao.
@param tamFonte: Inteiro com o tamanho da fonte do botao.
@param cor: String com a cor da fonte do botao.
@param tipo: Inteiro com o tipo do botao.
@param executa: funcao a ser executada de acordo com o evento esperado (tipo do botao).

@return Botao: Botao criado
*/
Botao criarBotao(char *texto, int tamFonte, char *cor, int tipo, void (*executa)(void));

/*
Funcao que executa o botao quando este eh "clicado".

@param botao: botao cuja execucao serah realizada.
*/
void executaBotao(Botao b);

/*
Funcao que desenha o botao quando a tela eh exibida.

@param botao: botao a ser impresso.
@param idx: indice do botao a ser impresso.
*/
void desenhaBotao(Botao b, int idx);

#endif