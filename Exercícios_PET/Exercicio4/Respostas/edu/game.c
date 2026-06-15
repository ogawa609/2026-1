#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"

struct Game{
    char* titulo;
    char* desenvolvedora;
    char* genero;
    int ano;
    int qntPlat;
    char** plataformas;
};
/**
 * @brief Lê os dados de um jogo da entrada padrão e constrói a estrutura correspondente.
 * A ordem de leitura esperada é: Título, Desenvolvedora, Gênero, Ano de lançamento, Quantidade de plataformas e a lista com o nome de cada plataforma.
 * @return Ponteiro para a estrutura Game recém-criada.
 */
Game *game_read_and_construct()
{
    Game* g = malloc(sizeof(Game));

    g->plataformas = NULL;
    char titulo[MAX_TAM_STRING];
    char desenvolvedora[MAX_TAM_STRING];
    char genero[MAX_TAM_STRING];
    char str[MAX_TAM_STRING];
    int ano;
    int qnt;
    //JOGO Portal Valve Puzzle 2007 3 PC PS3 Xbox_360
    scanf("%s %s %s %d %d ",titulo,desenvolvedora,genero,&ano,&qnt);

    if(qnt>0)
    {
        g->plataformas = malloc(qnt*sizeof(char*));

        for(int i=0;i<qnt;i++)
        {
            scanf("%s",str);
            int t = strlen(str) +1;
            g->plataformas[i] = malloc(t*sizeof(char));
            strcpy(g->plataformas[i],str);
        }
    }
    scanf("%*c");
    

    int tam = strlen(titulo) +1;
    g->titulo = malloc(tam*sizeof(char));
    strcpy(g->titulo,titulo);

    tam = strlen(desenvolvedora) + 1;
    g->desenvolvedora = malloc(tam*sizeof(char));
    strcpy(g->desenvolvedora,desenvolvedora);

    tam = strlen(genero) + 1;
    g->genero = malloc(tam*sizeof(char));
    strcpy(g->genero,genero);

    g->ano = ano;
    g->qntPlat =qnt;

     return g;   
}

/**
 * @brief Imprime os dados formatados de um jogo.
 * A formatação exibirá, linha por linha: o Nome, a Desenvolvedora, o Ano, o Gênero e a lista de Plataformas disponíveis.
 * @param g Ponteiro genérico que aponta para a estrutura Game.
 */

 /*
 MIDIA 10: JOGO
Titulo: Bully
Desenvolvedora: Rockstar
Genero: Acao_Aventura
Ano de lancamento: 2006
Plataforma(s): PS2, Xbox, PC*/
void game_print(void *g)
{
    Game* j = (Game*) g;
    printf("JOGO\n");
    printf("Titulo: %s\n",j->titulo);
    printf("Desenvolvedora: %s\n",j->desenvolvedora);
    printf("Genero: %s\n",j->genero);
    printf("Ano de lancamento: %d\n",j->ano);
    if(j->qntPlat>0)
    {
        printf("Plataforma(s): ");
        for(int i=0;i<j->qntPlat;i++)
        {
            if(i==j->qntPlat-1)
                printf("%s\n\n",j->plataformas[i]);
            else
               printf("%s, ",j->plataformas[i]); 
        }
    }
        
}

/**
 * @brief Libera a memória alocada para a estrutura de um jogo.
 * @param g Ponteiro genérico que aponta para a estrutura Game.
 */
void game_free(void *g)
{
    Game* j = (Game*) g;

    free(j->desenvolvedora);
    free(j->genero);
    free(j->titulo);

    if(j->qntPlat>0)
    {
        for(int i=0;i<j->qntPlat;i++)
            free(j->plataformas[i]);

        free(j->plataformas);
    }

    free(j);
}