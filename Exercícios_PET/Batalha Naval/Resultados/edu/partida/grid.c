#include <stdio.h>
#include <string.h>
#include "grid.h"
#include "navio.h"


/* ------------------------------------------------------------------ */
/* Operacoes                                                           */
/* ------------------------------------------------------------------ */

/*
 * grid_criar
 * Inicializa o grid com todas as celulas vazias e sem navios.
 * Pre-condicao : 2 <= tamanho <= GRID_MAX_TAMANHO
 */
Grid grid_criar(int tamanho)
{
    Grid g;
    g.tamanho = tamanho;
    for(int i=0;i<tamanho;i++)
    {
        for(int j=0;j<tamanho;j++)
        {
            g.celulas[i][j] = CELULA_VAZIA;
            g.navio_idx[i][j] = -1;
            g.parte_idx [i][j] = -1;
        }
    }
    g.total_navios =0;
    
    return g;
}

/*
 * grid_posicionar
 * Posiciona o navio apontado por n a partir de `inicio`.
 * Se horizontal == 1, ocupa colunas consecutivas; caso contrario, linhas.
 * Retorna 1 se posicionado com sucesso, 0 se posicao invalida ou sobreposicao.
 * Pre-condicao : g != NULL, n != NULL
 *                total_navios < GRID_MAX_NAVIOS antes da chamada
 * Pos-condicao : celulas ocupadas ficam com estado CELULA_NAVIO
 */
int grid_posicionar(Grid *g, const Navio *n, Posicao inicio, int horizontal)
{

    if(!posicao_valida(inicio,g->tamanho))
        return 0;

    int linha = posicao_linha(inicio);
    int coluna = posicao_coluna(inicio);

   
        for(int i=0;i<n->tamanho;i++)
        {
            if(horizontal==1)
            {
                if(g->celulas[linha][coluna+i] != CELULA_VAZIA)
                    return 0;

                g->celulas[linha][coluna+i] = CELULA_NAVIO;
                g->navio_idx[linha][coluna+i] = g->total_navios;
                g->parte_idx[linha][coluna+i] = i;
                
            }
            else{

                if(g->celulas[linha+i][coluna] != CELULA_VAZIA)
                    return 0;

                g->celulas[linha+i][coluna] = CELULA_NAVIO;
                g->navio_idx[linha+i][coluna] = g->total_navios;
                g->parte_idx[linha+i][coluna] = i;
                
            }
        }
                g->navios[g->total_navios] = *n;
                g->total_navios++;


    return 1;
}

/*
 * grid_atirar
 * Atira na posicao p.
 * Retorna 1 se acertou um navio, 0 se agua.
 * Pre-condicao : g != NULL
 *                posicao_valida(p, g->tamanho) == 1
 *                celula em p nao esta em CELULA_ATINGIDA nem CELULA_AGUA
 * Pos-condicao : celula em p muda para CELULA_ATINGIDA ou CELULA_AGUA
 *                se acertou, a parte correspondente do navio e marcada
 */
int grid_atirar(Grid *g, Posicao p)
{
    int linha = posicao_linha(p);
    int coluna = posicao_coluna(p);

    if(g->celulas[linha][coluna]==CELULA_NAVIO)
    {
        g->celulas[linha][coluna] = CELULA_ATINGIDA;
        int indiceNavio = g->navio_idx[linha][coluna];
        int indiceParte = g->parte_idx[linha][coluna];
        
        navio_atingir(&g->navios[indiceNavio],indiceParte);
        return 1;
    }
    else 
    {
        g->celulas[linha][coluna] = CELULA_AGUA;
        return 0;
    }
}

/*
 * grid_celula
 * Retorna o estado da celula na posicao p.
 * Pre-condicao : g != NULL, posicao_valida(p, g->tamanho) == 1
 */
CelulaEstado grid_celula(const Grid g, Posicao p)
{
    int linha = posicao_linha(p);
    int coluna = posicao_coluna(p);

    return g.celulas[linha][coluna];
}

/*
 * grid_todos_afundados
 * Retorna 1 se nao ha mais nenhuma celula com estado CELULA_NAVIO.
 * Pre-condicao : g != NULL
 */
int grid_todos_afundados(const Grid g)
{
    for(int i=0;i<g.tamanho;i++)
    {
        for(int j=0;j<g.tamanho;j++)
        {
            if(g.celulas[i][j]==CELULA_NAVIO)
                return 0;
        }
    }

    return 1;
}

int grid_get_tamanho (const Grid g)
{
    return g.tamanho;
}

Navio grid_navio (const Grid g, Posicao x)
{
    int linha = posicao_linha(x);
    int coluna = posicao_coluna(x);
    int indice = g.navio_idx[linha][coluna];

    return g.navios[indice];
}