#include <stdio.h>
#include <stdlib.h>
#include "elemento.h"




struct Elemento 
{
    void *widget;
    func_ptr_exibeNaTela exibeNaTela;
    func_ptr_executaClick executaClick;
    func_ptr_deslocaComponente desalocaElemento;
};

/**
 * Cria um novo elemento de interface associado a um widget.
 *
 * Entrada:
 *  - widget: ponteiro para o componente gráfico associado.
 *  - exibeNaTela: função responsável por exibir o widget na tela.
 *  - executaClick: função responsável por tratar eventos de clique no widget.
 *  - desalocaComponente: função responsável por liberar os recursos do widget.
 *
 * Saída:
 *  - Retorna um ponteiro para o Elemento criado.
 *  - Retorna NULL em caso de falha na alocação.
 */
Elemento *criaElemento(
    void *widget,
    func_ptr_exibeNaTela exibeNaTela,
    func_ptr_executaClick executaClick,
    func_ptr_deslocaComponente desalocaComponente
)
{
    Elemento* e = malloc(sizeof(struct Elemento));
    e->desalocaElemento = desalocaComponente;
    e->executaClick = executaClick;
    e->exibeNaTela = exibeNaTela;
    e->widget = widget;

    return e;
}

/**
 * Solicita a exibição do elemento na tela.
 *
 * Entrada:
 *  - e: ponteiro para o elemento a ser exibido.
 *
 * Saída:
 *  - Nenhuma.
 */
void exibeNaTelaElemento(Elemento *e)
{
    e->exibeNaTela(e->widget);
}

/**
 * Executa a ação associada ao clique do elemento.
 *
 * Entrada:
 *  - e: ponteiro para o elemento que recebeu o clique.
 *
 * Saída:
 *  - Nenhuma.
 */
void executaClickElemento(Elemento *e)
{
    e->executaClick(e->widget);
}

/**
 * Libera a memória ocupada pelo elemento e pelo widget associado.
 *
 * Entrada:
 *  - e: ponteiro para o elemento a ser desalocado.
 *
 * Saída:
 *  - Nenhuma.
 */
void desalocaElemento(Elemento *e)
{
    e->desalocaElemento(e->widget);
}