#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogador.h"


struct Jogador
{
    int id;
    int wins;
    int defeats;
    int draws;
    char *league;
};


/*
Função que inicializa um jogador com ID passado por parâmetro
Todas as estatísticas do jogador são inicializadas com 0
e o valor da league é inicializado com ROOKIE

@param id: ID do jogador
@return *tJogador: Ponteiro de tJogador inicializado
*/
tJogador *inicializaJogador(int id)
{
    tJogador* jogador = malloc(sizeof(tJogador));
    jogador->defeats = jogador->draws = jogador->wins = 0;
    jogador->league = malloc(MAX_LEAGUE*sizeof(char));
    strcpy(jogador->league,"ROOKIE");
    jogador->id = id;

    return jogador;
}


/*
Função que lê as estatísticas de um jogador a partir da entrada padrão e retorna um jogador inicializado
com essas estatísticas. O ID do jogador é passado por parâmetro. Uma vez lidas as estatísticas, a liga
é calculada e armazenada no jogador.

@param id: ID do jogador
@return *tJogador: Jogador inicializado com as estatísticas lidas e o valor da liga calculada
*/
tJogador *leJogador(int id)
{
    tJogador* jog = inicializaJogador(id);

    int wins, draws, defeats;
    scanf("%d %d %d\n",&wins,&defeats,&draws);

    jog->defeats = defeats;
    jog->draws = draws;
    jog->wins = wins;
    calculaLeague(jog);

    return jog;
}

/*
Função que calcula a liga (league) de um jogador e a retorna para ser armazenada no campo
league do próprio jogador

@param *j: Ponteiro de jogador
*/
void calculaLeague(tJogador *j)
{
    int lp = j->wins*140 + j->draws*70 - j->defeats*10;

    if(lp <= 200)
        strcpy(j->league,"ROOKIE");
    else if(201<=lp&&lp<=400)
        strcpy(j->league,"IRON");
    else if(401<=lp&&lp<=600)
        strcpy(j->league,"BRONZE");
    else if(601<=lp&&lp<=800)
        strcpy(j->league,"SILVER");
    else if(801<=lp&&lp<=1000)
        strcpy(j->league,"GOLD");
    else if(1001<=lp&&lp<=1500)
        strcpy(j->league,"PLATINUM");
    else if(1501<=lp&&lp<=2000)
        strcpy(j->league,"DIAMOND");
    else
        strcpy(j->league,"MASTER");
}

/*
Função que recebe um jogador cadastrado e atualiza suas estatísticas de acordo com os valores passados por parâmetro.
O ID do jogador é sempre igualado ao ID passado por parâmetro e as estatísticas de wins, deafeats e draws são incrementadas
pelos valores passados por parâmetro. A liga do jogador é recalculada e armazenada no campo league do jogador.

@param *j: Jogador
@param id: ID do jogador
@param k: Wins a serem incrementadas
@param d: Defeats a serem incrementadas
@param a: Draws a serem incrementadas

@return *tJogador: Ponteiro do jogador atualizado
*/
tJogador *atualizaJogador(tJogador *j, int id, int k, int d, int a)
{
    j->defeats += d;
    j->draws += a;
    j->wins += k;
    j->id = id;
    calculaLeague(j);

    return j;
}

/*
Funçao que recebe um jogador e retorna o numero de wins do jogador

@param *j: Ponteiro de tJogador
@return int: Wins do jogador
*/
int getWinsJogador(tJogador *j)
{
    return j->wins;
}

/*
Funçao que recebe um jogador e retorna o valor de deaths do jogador

@param *j: Ponteiro de tJogador
@return int: Defeats do jogador
*/
int getDefeatsJogador(tJogador *j)
{
    return j->defeats;
}

/*
Funçao que recebe um jogador e retorna o valor de assists do jogador

@param *j: Ponteiro de tJogador
@return int: Draws do jogador
*/
int getDrawsJogador(tJogador *j)
{
    return j->draws;
}

/*
Funçao que recebe um jogador e retorna o valor de ID do jogador

@param *j: Ponteiro de tJogador
@return int: ID do jogador
*/
int getIdJogador(tJogador *j)
{
    return j->id;
}

/*
Funçao que recebe um ponteiro de jogador e imprime suas informações conforme o formato especificado

@param *j: Jogador
*/
void printaJogador(tJogador *j)
{
    printf("Jogador %d: %d/%d/%d (%s)\n",j->id,j->wins,j->defeats,j->draws,j->league);
}

/*
Funçao que libera um ponteiro de jogador caso este seja diferente de NULL.

@param *j: Jogador
*/
void liberaJogador(tJogador *j)
{
    free(j->league);
    free(j);
}
