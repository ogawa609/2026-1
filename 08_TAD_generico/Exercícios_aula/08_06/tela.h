#ifndef _TELA_H
#define _TELA_H

#include "elemento.h"

#define MAX_ELEMENTOS 10
typedef struct Tela Tela;

/*
struct Tela 
{
    int altura;
    int largura;
    Elemento **elemento;
    int nElementos;    
};
*/

/**
 * Cria uma nova tela vazia.
 *
 * A função aloca dinamicamente uma estrutura Tela, inicializa suas
 * dimensões (altura e largura), define a quantidade de elementos como
 * zero e cria um vetor dinâmico inicial capaz de armazenar ponteiros
 * para elementos da interface.
 *
 * Entrada:
 *  - altura: altura da tela.
 *  - largura: largura da tela.
 *
 * Saída:
 *  - Retorna um ponteiro para a Tela criada e inicializada.
 */
Tela *criarTela(int altura, int largura);

/**
 * Registra um novo elemento na tela.
 *
 * A função cria um Elemento a partir do widget e dos ponteiros para
 * funções recebidos, armazena esse elemento no vetor interno da tela
 * e redimensiona o vetor para permitir futuras inserções.
 *
 * Entrada:
 *  - t: ponteiro para a tela onde o elemento será registrado.
 *  - widget: ponteiro para o componente associado ao elemento.
 *  - exibeNaTela: função utilizada para exibir o componente.
 *  - executaClick: função utilizada para tratar eventos de clique.
 *  - desalocaComponente: função utilizada para liberar os recursos do componente.
 *
 * Saída:
 *  - Nenhuma.
 */
void registraElementoTela(
    Tela *t,
    void *widget,
    func_ptr_exibeNaTela exibeNaTela,
    func_ptr_executaClick executaClick,
    func_ptr_deslocaComponente desalocaComponente
);

/**
 * Exibe todos os elementos registrados na tela.
 *
 * Para cada elemento armazenado, imprime delimitadores visuais
 * ("##################") antes e depois da exibição do componente,
 * chamando a função de exibição associada ao elemento.
 *
 * Entrada:
 *  - t: ponteiro para a tela a ser desenhada.
 *
 * Saída:
 *  - Nenhuma.
 */
void desenhaTela(Tela *t);

/**
 * Aguarda a seleção de um elemento pelo usuário e executa sua ação.
 *
 * A função solicita ao usuário um índice correspondente a um dos
 * elementos registrados na tela. Caso o índice seja inválido,
 * exibe uma mensagem de aviso e encerra o programa. Caso contrário,
 * executa a função de clique associada ao elemento selecionado.
 *
 * Entrada:
 *  - t: ponteiro para a tela que contém os elementos interativos.
 *
 * Saída:
 *  - Nenhuma.
 */
void ouvidorClickTela(Tela *t);

/**
 * Libera todos os recursos associados à tela.
 *
 * A função percorre todos os elementos registrados, desalocando cada
 * um deles por meio de sua função apropriada. Em seguida, libera o
 * vetor de elementos e a própria estrutura Tela.
 *
 * Entrada:
 *  - t: ponteiro para a tela a ser destruída.
 *
 * Saída:
 *  - Nenhuma.
 */
void desalocaTela(Tela *t);

#endif
