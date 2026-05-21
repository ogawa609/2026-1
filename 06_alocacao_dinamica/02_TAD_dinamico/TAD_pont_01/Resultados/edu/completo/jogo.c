#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"



/**
 * Aloca e retorna uma estrutura do tipo tJogo.
 * Se a alocação falhar, o programa é encerrado.
 * 
 * @return a estrutura do tipo tJogo alocada.
 */
tJogo* CriaJogo()
{
    tJogo* jogo = (tJogo*) malloc(sizeof(tJogo));
    jogo->jogador1 = CriaJogador(1);
    jogo->jogador2 = CriaJogador(2);
    jogo->tabuleiro = CriaTabuleiro();

    return jogo;
}


/**
 * Inicia o jogo, definindo o tabuleiro e os jogadores.
 * 
 * @param jogo o jogo a ser iniciado.
 */
void ComecaJogo(tJogo* jogo)
{


    while(1)
    {
        
        JogaJogador(jogo->jogador1,jogo->tabuleiro);
        ImprimeTabuleiro(jogo->tabuleiro);

        if(VenceuJogador(jogo->jogador1,jogo->tabuleiro))
        {
            printf("JOGADOR 1 Venceu!\n");

            break;

        }

        if(AcabouJogo(jogo))
        {
            printf("Sem vencedor!\n");
            break;
        }

        JogaJogador(jogo->jogador2,jogo->tabuleiro);
        ImprimeTabuleiro(jogo->tabuleiro);

        if(VenceuJogador(jogo->jogador2,jogo->tabuleiro))
        {
            printf("JOGADOR 2 Venceu!\n");

            break;

        }

        if(AcabouJogo(jogo))
        {
            printf("Sem vencedor!\n");
            break;
        }
    }
}


/**
 * Verifica se o jogo acabou (se não há mais posições livres no tabuleiro).
 * 
 * @param jogo o jogo atual.
 * 
 * @return 1 se o jogo acabou, 0 caso contrário.
 */
int AcabouJogo(tJogo* jogo)
{
    if(TemPosicaoLivreTabuleiro(jogo->tabuleiro))
        return 0;
    
    return 1;
}


/**
 * Verifica se o usuário deseja jogar novamente.
 * 
 * @return 1 se o usuário deseja jogar novamente, 0 caso contrário.
 */
int ContinuaJogo()
{
    printf("Jogar novamente? (s,n)\n");
    
    while(1){
    char resposta;
    scanf(" %c",&resposta);

    if(resposta=='s')
        return 1;
    else if(resposta=='n')
        return 0;
    else
        continue;
    }
}


/**
 * Libera a memória de uma estrutura do tipo tJogo.
 * 
 * @param jogo a estrutura do tipo tJogo a ser liberada.
 */
void DestroiJogo(tJogo* jogo)
{
    if(jogo->jogador1!= NULL)
        DestroiJogador(jogo->jogador1);
    if(jogo->jogador2!=NULL)
        DestroiJogador(jogo->jogador2);
        if(jogo->tabuleiro!=NULL)
            DestroiTabuleiro(jogo->tabuleiro);

    free(jogo);
}