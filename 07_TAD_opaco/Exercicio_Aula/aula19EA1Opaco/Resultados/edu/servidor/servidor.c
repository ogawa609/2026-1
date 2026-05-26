#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servidor.h"


struct Servidor{

    tBracket** brackets;
    int qntBra;
};

/*
Função que lê todos os registros de brackets de um servidor a partir da entrada padrão e retorna um servidor
com todos os registros de brackets lidos. Conforme a especificação da atividade, a leitura é encerrada quando
um ID de bracket igual a -1 é lido.

@return *tServidor: Ponteiro de servidor com todos os registros de brackets lidos
*/
tServidor *leBracketsServidor()
{
    tServidor* s = malloc(sizeof(tServidor));
    s->qntBra = 0;
    s->brackets = malloc(sizeof(tBracket*));

    int id;

    while(1)
    {
        scanf("%d\n",&id);

        if(id==-1)
            break;
        
        tBracket*b = leBracket(id);
        s->brackets[s->qntBra] = b;
        s->qntBra++;
        s->brackets = realloc(s->brackets,(s->qntBra+1)*sizeof(tBracket*));
    }

    return s;
}

/*
Função que recebe um servidor já preenchido com os dados de todas as brackets e um ID de jogador.
A partir dessas informações, ela busca as estatísticas do jogador em todas as brackets que ele participou.
Se o jogar não for encontrado, um jogador com ID -1 é criado e retornado.
Se o jogador for encontrado em uma ou mais brackets, suas estatísticas são agregadas e o jogador é retornado.

@param *s: tServidor
@param idJog: ID do jogador
*/
tJogador *buscaDadosJogadorServidor(tServidor *s, int idJog)
{
    tJogador* buscado;
    tJogador* retornado = inicializaJogador(-1);

    for(int i = 0;i<s->qntBra;i++)
    {
        buscado = buscaJogadorBracket(s->brackets[i],idJog);

        if(getIdJogador(buscado) != -1)
            retornado = atualizaJogador(retornado,getIdJogador(buscado),getWinsJogador(buscado),getDefeatsJogador(buscado),getDrawsJogador(buscado));
        else
            liberaJogador(buscado);
    }

    return retornado;
}

/*
Função que recebe um servidor já criado e preenchido e imprime um relatório com as estatísticas de um conjunto de jogadores
solicitados a partir da entrada padrão. O relatório é impresso conforme o formato especificado na descrição da atividade.

@param *s: tServidor
*/
void criaRelatorioServidor(tServidor *s)
{
    int qnt,id;
    scanf("%d\n",&qnt);

    for(int i=0;i<qnt;i++)
    {

        scanf("%d",&id);

        tJogador* j = buscaDadosJogadorServidor(s,id);

        if(getIdJogador(j)==-1)
            printf("Jogador %d: -\n",id);
        
        else
            printaJogador(j);
        
        liberaJogador(j);
    }
}

/*
Funçao que libera um ponteiro de servidor caso este seja diferente de NULL.

@param *s: tServidor
*/
void liberaServidor(tServidor *s)
{
        for(int i=0;i<s->qntBra;i++)
        {
            liberaBracket(s->brackets[i]);
        }

        free(s->brackets);
        free(s);
}