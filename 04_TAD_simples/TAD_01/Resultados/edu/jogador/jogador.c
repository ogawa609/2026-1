#include <stdio.h>
#include "jogador.h"
#include "jogada.h"

/**
 * Cria um jogador com o id passado como parâmetro e retorna o jogador criado.
 * 
 * @param idJogador o id do jogador (1 ou 2).
 * 
 * @return tJogador o jogador criado.
 */
tJogador CriaJogador(int idJogador)
{
    tJogador j;
    j.id=idJogador;

    return j;
}


/**
 * Recebe um jogador e um tabuleiro e retorna o tabuleiro com a jogada do jogador.
 * 
 * @param jogador o jogador que fará a jogada.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return o tabuleiro atualizado com a jogada do jogador.
 */
tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro)
{
    while(1)
    {
        printf("Jogador %d\n",jogador.id);

        tJogada jog = LeJogada();

        if(FoiJogadaBemSucedida(jog))
        {

        int x=ObtemJogadaX(jog);
        int y=ObtemJogadaY(jog);
       

        if(EhPosicaoValidaTabuleiro(x,y))
        {
            if(EstaLivrePosicaoTabuleiro(tabuleiro,x,y))
            {
                 printf("Jogada [%d,%d]!\n",x,y);
                tabuleiro=MarcaPosicaoTabuleiro(tabuleiro,jogador.id,x,y);
                break;
            }
            else
                printf("Posicao invalida (OCUPADA - [%d,%d] )!\n",x,y);
        }
        else
            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n",x,y);
    }
    else
        break; 
}

return tabuleiro;

}


/**
 * Recebe um jogador e um tabuleiro e retorna 1 se o jogador venceu e 0 caso contrário.
 * 
 * @param jogador o jogador a ser verificado.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro)
{
    int venceu=1;

    for(int i=0;i<3;i++) 
    {
        venceu=1;
        for(int j=0;j<3;j++)
        {
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,i,j,jogador.id)==0)
            {
                venceu=0;
                break;
            }
        }

        if(venceu)
            return 1;
    }

    for(int i=0;i<3;i++) 
    {
        venceu=1;
        for(int j=0;j<3;j++)
        {
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,j,i,jogador.id)==0)
            {
                venceu=0;
                break;
            }
        }

        if(venceu)
            return 1;
    }

    if( EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,0,0,jogador.id)&&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,1,1,jogador.id)&&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,2,2,jogador.id))
            return 1;

    if( EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,0,2,jogador.id)&&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,1,1,jogador.id)&&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,2,0,jogador.id))
            return 1;

    return 0;
        
}
