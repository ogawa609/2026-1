#include <stdio.h>
#include <stdlib.h>
#include "tabuleiro.h"

/**
 * Aloca e retorna uma estrutura do tipo tTabuleiro.
 * Se a alocação falhar, o programa é encerrado.
 * 
 * @return a estrutura do tipo tTabuleiro alocada.
 */
tTabuleiro* CriaTabuleiro()
{
    tTabuleiro* tab = (tTabuleiro*) malloc(sizeof(tTabuleiro));
    tab->peca1='X';
    tab->peca2='0';
    tab->pecaVazio='-';
    tab->posicoes = (char**) malloc(3*sizeof(char*));

    for(int i=0;i<3;i++)
    {
            tab->posicoes[i] = (char*) malloc(3*sizeof(char));
    }

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            tab->posicoes[i][j] = tab->pecaVazio;
        }
    }

    return tab;
}


/**
 * Libera a memória de uma estrutura do tipo tTabuleiro.
 * 
 * @param tabuleiro a estrutura do tipo tTabuleiro a ser liberada.
 */
void DestroiTabuleiro(tTabuleiro* tabuleiro)
{
    for(int i=0;i<3;i++)
    {
        free(tabuleiro->posicoes[i]);
    }
    free(tabuleiro->posicoes);
    free(tabuleiro);
}


/**
 * Marca uma posição do tabuleiro com a peça do jogador.
 * 
 * @param tabuleiro o tabuleiro atual.
 * @param peca a peça do jogador (1 ou 2).
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 */
void MarcaPosicaoTabuleiro(tTabuleiro* tabuleiro, int peca, int x, int y)
{
    if(peca==1)
        tabuleiro->posicoes[y][x] = tabuleiro->peca1;
    else
        tabuleiro->posicoes[y][x] = tabuleiro->peca2;
}


/**
 * Verifica se há alguma posição livre no tabuleiro.
 * 
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se há alguma posição livre, 0 caso contrário.
 */
int TemPosicaoLivreTabuleiro(tTabuleiro* tabuleiro)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(tabuleiro->posicoes[i][j]=='-')
                return 1;
        }
    }

    return 0;
}


/**
 * Verifica se a posição do tabuleiro está marcada com a peça do jogador.
 * 
 * @param tabuleiro - o tabuleiro atual.
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 * @param peca a peça do jogador (1 ou 2).
 * 
 * @return 1 se a posição está marcada com a peça do jogador, 0 caso contrário.
 */
int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro* tabuleiro, int x, int y, int peca)
{
    if(peca == 1)
    {
        if(tabuleiro->posicoes[y][x]==tabuleiro->peca1)
            return 1;
        else
            return 0;
    }
    else
    {
        if(tabuleiro->posicoes[y][x]==tabuleiro->peca2)
            return 1;
        else
            return 0;
    }
}


/**
 * Verifica se a posição do tabuleiro está livre.
 * 
 * @param tabuleiro o tabuleiro atual.
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 * 
 * @return 1 se a posição está livre, 0 caso contrário.
 */
int EstaLivrePosicaoTabuleiro(tTabuleiro* tabuleiro, int x, int y)
{
    return tabuleiro->posicoes[y][x] == '-';
}


/**
 * Verifica se a posição do tabuleiro é válida.
 * 
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 * 
 * @return 1 se a posição é válida, 0 caso contrário.
 */
int EhPosicaoValidaTabuleiro(int x, int y)
{
    return x>=0&&x<3 && y>=0 &&y<3;
}


/**
 * Imprime o tabuleiro.
 * 
 * @param tabuleiro o tabuleiro atual.
 */
void ImprimeTabuleiro(tTabuleiro* tabuleiro)
{
    for(int i=0;i<3;i++)
    {
        printf("        ");
        for(int j=0;j<3;j++)
        {
            printf("%c",tabuleiro->posicoes[i][j]);
        }
        printf("\n");
    }
}
