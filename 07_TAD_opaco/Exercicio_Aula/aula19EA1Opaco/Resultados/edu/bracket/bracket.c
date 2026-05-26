#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bracket.h"


struct Bracket
{
    int idBracket;
    tJogador **jogadores;
};


/*
Função que lê apenas uma bracket a partir da entrada padrão. O registro de uma bracket
é composto das informações de 5 jogadores. Verifique a especificação da atividade para mais detalhes.

@param idbracket: ID da bracket
@return *tBracket: Uma bracket lida
*/
tBracket *leBracket(int idBracket)
{
    tBracket* b = malloc(MAX_JOGADOR_BRACKET*sizeof(tBracket));
    b->jogadores = malloc(sizeof(tJogador*)*MAX_JOGADOR_BRACKET);
    b->idBracket = idBracket;

    for(int i=0;i<MAX_JOGADOR_BRACKET;i++)
    {
        int id;
        scanf("%d: ",&id);
        b->jogadores[i] = leJogador(id);
    }

    return b;
}

/*
Função que busca um jogador em um registro de bracket a partir do ID do jogador.
Se o jogador for encontrado, ele é retornado. Caso contrário, um jogador é criado com ID -1 e retornado.

@param *b: Uma bracket cadastrada
@param idJog: ID do jogador a ser buscado

@return *tJogador: Jogador encontrado (ou não)
*/
tJogador *buscaJogadorBracket(tBracket *b, int idJog)
{
    tJogador* buscado = inicializaJogador(-1);

    for(int i=0;i<MAX_JOGADOR_BRACKET;i++)
    {
        if(idJog == getIdJogador(b->jogadores[i]))
        {
            liberaJogador(buscado);
           return b->jogadores[i];
        }
    }

    return buscado;
}

/*
Funçao que libera um ponteiro de uma bracket caso este seja diferente de NULL.

@param *b: Bracket
*/
void liberaBracket(tBracket *b)
{
    for(int i=0;i<5;i++)
        liberaJogador(b->jogadores[i]);
    
    free(b->jogadores);
    free(b);
}