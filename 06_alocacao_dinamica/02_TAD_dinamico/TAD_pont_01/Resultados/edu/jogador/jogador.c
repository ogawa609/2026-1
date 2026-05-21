#include <stdio.h>
#include <stdlib.h>
#include "jogador.h"
#include "jogada.h"


/**
 * Aloca e retorna uma estrutura do tipo tJogador.
 * Se a alocação falhar, o programa é encerrado.
 *
 *  @param idJogador o ID do jogador (1 ou 2).
 * 
 * @return a estrutura do tipo tJogador alocada.
 */
tJogador* CriaJogador(int idJogador)
{
    tJogador* jog = (tJogador*) malloc(sizeof(tJogador));

    jog->id = idJogador;

    return jog;
}


/**
 * Libera a memória de uma estrutura do tipo tJogador.
 * 
 * @param jogador a estrutura do tipo tJogador a ser liberada.
 */
void DestroiJogador(tJogador* jogador)
{
    free(jogador);
}


/**
 * Lê uma jogada e armazena em uma estrutura do tipo tJogada.
 * 
 * @param jogador o jogador atual.
 * @param tabuleiro o tabuleiro atual.
 */
void JogaJogador(tJogador* jogador, tTabuleiro* tabuleiro)
{
    while(1){
        printf("Jogador %d\n",jogador->id);

        tJogada*jogada = CriaJogada();
        LeJogada(jogada);
        int x = ObtemJogadaX(jogada);
        int y = ObtemJogadaY(jogada);

        if(FoiJogadaBemSucedida(jogada))
        {
            if(EhPosicaoValidaTabuleiro(x,y))
            {
                if(EstaLivrePosicaoTabuleiro(tabuleiro,x,y))
                {
                    MarcaPosicaoTabuleiro(tabuleiro,jogador->id,x,y);
                    if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,x,y,jogador->id))
                    {
                        DestroiJogada(jogada);
                        printf("Jogada [%d,%d]!\n",x,y);
                        break;
                    }
                }
                else
                {
                    printf("Posicao invalida (OCUPADA - [%d,%d] )!\n",x,y);
                    DestroiJogada(jogada);
                    continue;
                }

            }
            else
            {
                printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n",x,y);
                DestroiJogada(jogada);
                continue;
            }
        }
    }
}


/**
 * Verifica se o jogador venceu o jogo.
 * 
 * @param jogador o jogador atual.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador* jogador, tTabuleiro* tabuleiro)
{
    for(int i =0;i<3;i++)
    {
        if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,0,i,jogador->id)==1&&
            EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,1,i,jogador->id)==1&&
                EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,2,i,jogador->id)==1)
                return 1;
    }

    for(int i =0;i<3;i++)
    {
        if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,i,0,jogador->id)==1&&
            EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,i,1,jogador->id)==1&&
                EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,i,2,jogador->id)==1)
                return 1;
    }

    if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,0,0,jogador->id)==1&&
            EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,1,1,jogador->id)==1&&
                EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,2,2,jogador->id)==1)
                return 1;

    if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,0,2,jogador->id)==1&&
            EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,1,1,jogador->id)==1&&
                EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,2,0,jogador->id)==1)
                return 1;
    
    return 0;
}