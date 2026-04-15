#include <stdio.h>
#include "jogo.h"

/**
 * Cria um jogo e retorna o jogo criado.
 * 
 * @return o jogo criado.
 */
tJogo CriaJogo()
{
    tJogo jogo;
    
    jogo.tabuleiro=CriaTabuleiro();
    jogo.jogador1=CriaJogador(1);
    jogo.jogador2=CriaJogador(2);

    return jogo;
}


/**
 * Inicia o jogo, definindo o tabuleiro e os jogadores.
 * 
 * @param jogo o jogo a ser iniciado.
 */
void ComecaJogo(tJogo jogo)
{

    while(1)
    {
       jogo.tabuleiro= JogaJogador(jogo.jogador1,jogo.tabuleiro);
       ImprimeTabuleiro(jogo.tabuleiro);

       if(VenceuJogador(jogo.jogador1,jogo.tabuleiro))
       {
            printf("JOGADOR 1 Venceu!\n");
            break;
       }

       if(TemPosicaoLivreTabuleiro(jogo.tabuleiro)==0)
       {
            printf("Sem vencedor!\n");
            break;
       }

       jogo.tabuleiro= JogaJogador(jogo.jogador2,jogo.tabuleiro);
       ImprimeTabuleiro(jogo.tabuleiro);

       if(VenceuJogador(jogo.jogador2,jogo.tabuleiro))
       {
            printf("JOGADOR 2 Venceu!\n");
            break;
       }
        if(TemPosicaoLivreTabuleiro(jogo.tabuleiro)==0)
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
int AcabouJogo(tJogo jogo){
    if(TemPosicaoLivreTabuleiro(jogo.tabuleiro))
    {
        return 0;
    }

    return 1;
}


/**
 * Verifica se o usuário deseja jogar novamente.
 * 
 * @return 1 se o usuário deseja jogar novamente, 0 caso contrário.
 */
int ContinuaJogo()
{
    char c;
   
    printf("Jogar novamente? (s,n)\n");
    while(1)

    {
     scanf(" %c",&c);
     if(c=='s')
        return 1;
        
    else if(c=='n')
        return 0;
    }
}