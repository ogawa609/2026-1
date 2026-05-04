#include <stdio.h>
#include <string.h>
#include "jogador.h"

/*
Função que inicializa um jogador com ID passado por parâmetro
Todas as estatísticas do jogador são inicializadas com 0
e o valor da league é inicializado com ROOKIE

@param id: ID do jogador
@return Jogador: Jogador inicializado
*/
tJogador inicializaJogador(int id)
{
    tJogador jogador;
    jogador.id = id;
    jogador.draws = 0;
    jogador.defeats = 0;
    jogador.wins = 0;
    strcpy(jogador.league,"ROOKIE");

    return jogador;
}

/*
Função que lê as estatísticas de um jogador a partir da entrada padrão e retorna um jogador inicializado
com essas estatísticas. O ID do jogador é passado por parâmetro. Uma vez lidas as estatísticas, a liga
é calculada e armazenada no jogador.

@param id: ID do jogador
@return Jogador: Jogador inicializado com as estatísticas lidas e o valor da liga calculada
*/
tJogador leJogador(int id)
{
    int wins, defeats, draws;
    scanf("%d %d %d\n",&wins,&defeats,&draws);

    tJogador j = inicializaJogador(id);
    j.defeats = defeats;
    j.draws = draws;
    j.wins = wins;

    return j;
}

/*
Função que calcula a liga (league) de um jogador e a retorna para ser armazenada no campo
league do próprio jogador
Lembre-se do escopo de variáveis! Aqui, não adianta declarar uma variável char* dentro da
função e retorná-la, pois seu escopo é local e sua existência é efêmera e dependente da duração
da chamada da função. Você deve retornar diretamente os literais correspondentes as ligas.

@param j: Jogador
@return char*: String referente a liga calculada do jogador
*/
char *calculaLeague(tJogador j)
{
    float lp;

    if(j.draws+j.wins>0)
        lp = ((j.wins*140.0)+(j.draws*70.0)-(j.defeats*10.0));
    else
        lp = 0;

    if(lp>=0&&lp<=200)
        return "ROOKIE";
    else if(lp>=201&&lp<=400)
        return "IRON";
    else if(lp>=401&&lp<=600)
        return "BRONZE";
    else if(lp>=601&&lp<=800)
        return "SILVER";
    else if(lp>=801&&lp<=1000)
        return "GOLD";
    else if(lp>=1001&&lp<=1500)
        return "PLATINUM";
    else if(lp>=1501&&lp<=2000)
        return "DIAMOND";
    else 
        return "MASTER";
    
}

/*
Função que recebe um jogador cadastrado e atualiza suas estatísticas de acordo com os valores passados por parâmetro.
O ID do jogador é sempre igualado ao ID passado por parâmetro e as estatísticas de wins, deafeats e draws são incrementadas
pelos valores passados por parâmetro. A liga do jogador é recalculada e armazenada no campo league do jogador.

@param j: Jogador
@param id: ID do jogador
@param k: Wins a serem incrementadas
@param d: Defeats a serem incrementadas
@param a: Draws a serem incrementadas

@return Jogador: Jogador atualizado
*/
tJogador atualizaJogador(tJogador j, int id, int k, int d, int a)
{
    j.defeats += d;
    j.draws += a;
    j.wins += k;
    j.id = id;

    strcpy(j.league,calculaLeague(j));

    return j;
}

/*
Funçao que recebe um jogador e retorna o numero de wins do jogador

@param j: Jogador
@return int: Wins do jogador
*/
int getWinsJogador(tJogador j)
{
    return j.wins;
}

/*
Funçao que recebe um jogador e retorna o valor de deaths do jogador

@param j: Jogador
@return int: deaths do jogador
*/
int getDefeatsJogador(tJogador j)
{
    return j.defeats;
}

/*
Funçao que recebe um jogador e retorna o valor de assists do jogador

@param j: Jogador
@return int: Assists do jogador
*/
int getDrawsJogador(tJogador j)
{
    return j.draws;
}

/*
Funçao que recebe um jogador e retorna o valor de ID do jogador

@param j: Jogador
@return int: ID do jogador
*/
int getIdJogador(tJogador j)
{
    return j.id;
}

/*
Funçao que recebe um jogador e imprime suas informações conforme o formato especificado 

@param j: Jogador
*/
void printaJogador(tJogador j)
{
    printf("Jogador %d: %d/%d/%d (%s)\n",j.id,j.wins,j.defeats,j.draws,calculaLeague(j));
}