#include <stdio.h>
#include <string.h>
#include "bracket.h"


/*
Função que lê apenas uma bracket a partir da entrada padrão. O registro de uma bracket
é composto das informações de 5 jogadores. Verifique a especificação da atividade para mais detalhes.

@param idbracket: ID da bracket
@return tBracket: Uma bracket lida
*/
tBracket leBracket(int idBracket)
{
    tBracket bra;
    bra.idBracket = idBracket;

    for(int i=0;i<5;i++)
    {
        int id;
        scanf("%d: ",&id);

        bra.jogadores[i] = leJogador(id);
    }
    
    return bra;
}

/*
Função que busca um jogador em um registro de bracket a partir do ID do jogador.
Se o jogador for encontrado, ele é retornado. Caso contrário, um jogador é criado com ID -1 e retornado.

@param b: Uma bracket cadastrada
@param idJog: ID do jogador a ser buscado

@return tJogador: Jogador encontrado (ou não)
*/
tJogador buscaJogadorBracket(tBracket b, int idJog)
{
    for(int i=0;i<5;i++)
    {
        if(idJog == getIdJogador(b.jogadores[i]))
            return b.jogadores[i];
    }

    tJogador j = inicializaJogador(-1);
    return j;

    
}


