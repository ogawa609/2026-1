#include <stdio.h>
#include <string.h>
#include "partida.h"  
#include "grid.h"

/*
 * partida_criar
 * Inicializa a partida com dois jogadores e grids do tamanho indicado.
 * O turno inicial e do jogador 1 (indice 0).
 * Pre-condicao : p != NULL, nome_j1 != NULL, nome_j2 != NULL
 *                2 <= tamanho_grid <= GRID_MAX_TAMANHO
 */
Partida partida_criar(const char *nome_j1, const char *nome_j2,
                   int tamanho_grid)
{
    Partida p;
    p.vencedor = -1;
    strcpy(p.nomes[0],nome_j1);
    strcpy(p.nomes[1],nome_j2);
    p.turno = 0;
    p.encerrada = 0;
    p.grids[0] = grid_criar(tamanho_grid);
    p.grids[1] = grid_criar(tamanho_grid);

    return p;
}

/*
 * partida_jogar
 * O jogador do turno atual atira na posicao `alvo` no grid adversario.
 * Avanca o turno somente se a jogada for valida.
 * Pre-condicao : p != NULL, p->encerrada == 0
 * Pos-condicao : se resultado == JOGADA_VITORIA, p->encerrada = 1
 */
ResultadoJogada partida_jogar(Partida *p, Posicao alvo)
{
    
  
    int turno = p->turno;
    int adversario = (turno == 0) ? 1 : 0;

    Grid *g = &p->grids[adversario];

    int tam = g->tamanho;

    
    if (!posicao_valida(alvo, tam) ||
        grid_celula(*g, alvo) == CELULA_ATINGIDA ||
        grid_celula(*g, alvo) == CELULA_AGUA)
    {
        return JOGADA_INVALIDA;
    }

    int acertou = grid_atirar(g, alvo);

    // vitória
    if (grid_todos_afundados(*g))
    {
        p->encerrada = 1;
        p->vencedor = turno;
        return JOGADA_VITORIA;
    }

    // água
    if (!acertou)
    {
        p->turno = adversario;
        return JOGADA_AGUA;
    }

    // ACERTOU NAVIO 
    int linha = posicao_linha(alvo);
    int coluna = posicao_coluna(alvo);

    int indiceNavio = g->navio_idx[linha][coluna];
    Navio n = g->navios[indiceNavio];

    if (navio_afundado(n))
        return JOGADA_AFUNDOU;
    else
        return JOGADA_ACERTO;
}




/*
 * partida_encerrada
 * Retorna 1 se a partida terminou, 0 caso contrario.
 * Pre-condicao : p != NULL
 */
int partida_encerrada(const Partida p)
{
    return p.encerrada;
}

/*
 * partida_vencedor
 * Retorna o nome do vencedor, ou NULL se a partida ainda nao terminou.
 * Pre-condicao : p != NULL
 */
const char *partida_vencedor(const Partida *p)
{
    if(!partida_encerrada(*p))
        return NULL;
    
    return p->nomes[p->vencedor];
    
}

/*
 * partida_turno_atual
 * Retorna o nome do jogador que deve jogar agora.
 * Pre-condicao : p != NULL, p->encerrada == 0
 */
const char *partida_turno_atual(const Partida *p)
{
    return p->nomes[p->turno];
}