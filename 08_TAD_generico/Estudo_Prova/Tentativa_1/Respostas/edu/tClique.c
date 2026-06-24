#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tClique.h"


struct Clique {

    char* caracteres;
};
/// @brief Função que cria um evento do tipo movimento
/// @param caracteresAceitos - Vetor de QUATRO caracteres que irá representar movimento
///                             na ordem: CIMA, ESQUERDA, BAIXO, DIREITA
/// @return O ponteiro para a variável do tipo evento movimento
tClique* criaEventoClique(char *caracteresAceitos)
{
    tClique* c = malloc(sizeof(tClique));
    c->caracteres = malloc(3*sizeof(char));

    for(int i=0;i<3;i++)
        c->caracteres[i] = caracteresAceitos[i];

    return c;
}

/// @brief Função que libera o evento...
/// @param eve - Ponteiro para o evento
void liberaEventoClique(void* eve)
{
    tClique* c = (tClique*) eve;
    free(c->caracteres);
    free(c);
}

/// @brief Função que executará o comportamento de um evento movimento
///         No caso, deve alterar o ambiente de acordo com a tecla apertada, se for possível
/// @param amb - Ponteiro para o ambiente a ser manipulado
/// @param eve - Ponteiro para o evento de movimento 
/// @param c - Caractere que foi digitado no teclado
void processaEventoClique(tAmbiente *amb, void *eve, char c)
{

     static char mapa[10][10] =  {
                                {'\0', 'o', 't', '\0', '\0', 'g', '\0', '\0', '\0', 'o'},
                                {'o', '\0', 'o', 'g', '\0', '\0', '\0', 't', 't', '\0'},
                                {'-', '|', 'g', 'g', '\0', '\0', '\0', '\0', '\0', '\0'},
                                {'t', '\0', '\0', 'g', '\0', '\0', '\0', '\0', '\0', 'g'},
                                {'g', 'o', '\0', '-', 'o', '\0', '\0', '\0', '-', 't'},
                                {'o', '|', 'g', '\0', '\0', '\0', '\0', '\0', '|', 'o'},
                                {'|', 'g', 'g', '|', 't', 't', 'o', 'g', '\0', 'g'},
                                {'t', '\0', 'o', 'g', '\0', '\0', '\0', '\0', '\0', '\0'},
                                {'t', 'g', '\0', 'g', '\0', '\0', '\0', '|', '-', 'o'},
                                {'-', '\0', '\0', '\0', '\0', '-', '-', 't', '\0', '\0'},
                            };


    tClique* k = (tClique*) eve;

    int ax,ay;
    retornaPosicaoAtual(amb,&ax,&ay);

    if(c==k->caracteres[0])
    {
        int x,y;
        scanf("%d %d\n",&x,&y);

        if(ax>0||ax<9||ay>0||ay<9)
        {
            if((((ax-x)*(ax-x))+((ay-y)*(ay-y)))==1)
            {
                char icone = retornaSituacaoPosicao(amb,x,y);

                if(icone=='|' || icone =='-' || icone == '\0' || icone == '0')
                {
                    printf("CLIQUE ESQUERDO NAO SELECIONOU INIMIGO\n");
                    return;
                }
                else
                {
                     printf("INIMIGO %c SELECIONADO EM (%d,%d)\n",icone,x,y);
                     alteraConteudo(amb,x,y,'+');
                     return;
                }

            }

            else
            {
                printf("CLIQUE LONGE DA POSICAO ATUAL\n");
                return;
            }

        }

        else
        {
            printf("MOVIMENTO INVALIDO POIS SAI DO MAPA!\n");
        }
    }
    else if(c==k->caracteres[1])
    {
          char cima,baixo,esquerda,direita;
        cima = baixo = esquerda = direita = '#';

       
        
            cima = retornaSituacaoPosicao(amb,ax-1,ay);
            baixo = retornaSituacaoPosicao(amb,ax+1,ay);
            esquerda = retornaSituacaoPosicao(amb,ax,ay-1);
            direita = retornaSituacaoPosicao(amb,ax,ay+1);
            int flag = 1;

            

            if(cima=='+')
            {
                char inimigo = mapa[ax-1][ay];
                printf("INIMIGO %c DA POSICAO (%d,%d) ELIMINADO COM CLIQUE DO MEIO\n",inimigo,ax-1,ay);
                alteraConteudo(amb,ax-1,ay,'\0');
                flag =0;
            }

            if(baixo=='+')
            {
                char inimigo = mapa[ax+1][ay];
                printf("INIMIGO %c DA POSICAO (%d,%d) ELIMINADO COM CLIQUE DO MEIO\n",inimigo,ax+1,ay);
                alteraConteudo(amb,ax+1,ay,'\0');
                
                flag =0;
            }

            if(esquerda=='+')
            {
                char inimigo = mapa[ax][ay-1];
                printf("INIMIGO %c DA POSICAO (%d,%d) ELIMINADO COM CLIQUE DO MEIO\n",inimigo,ax,ay-1);
                alteraConteudo(amb,ax,ay-1,'\0');
                flag =0;
            }

            if(direita=='+')
            {
                char inimigo = mapa[ax][ay+1];
                printf("INIMIGO %c DA POSICAO (%d,%d) ELIMINADO COM CLIQUE DO MEIO\n",inimigo,ax,ay+1);
                alteraConteudo(amb,ax,ay+1,'\0');
                flag =0;
            }

            if(flag)
            {
                int flagSaida = 0;
                for(int i=0;i<10;i++)
                {
                    for(int j=0;j<10;j++)
                    {
                        if(retornaSituacaoPosicao(amb,i,j)=='+')
                        {
                             printf("ALVO LONGE DA POSICAO ATUAL\n");
                             flag = 0;
                             flagSaida =1;
                             break;

                        }
                    }

                    if(flagSaida)
                        break;
                }
            }

            if(flag)
                printf("CLIQUE DO MEIO SEM ALVO\n");
    }

    else if(c==k->caracteres[2])
    {
         char cima,baixo,esquerda,direita;
        cima = baixo = esquerda = direita = '#';

       
            cima = retornaSituacaoPosicao(amb,ax-1,ay);
            baixo = retornaSituacaoPosicao(amb,ax+1,ay);
            esquerda = retornaSituacaoPosicao(amb,ax,ay-1);
            direita = retornaSituacaoPosicao(amb,ax,ay+1);
            int flag = 1;

           
               

            if(cima=='+')
            {
                char inimigo = mapa[ax-1][ay];
                printf("INIMIGO %c DA POSICAO (%d,%d) ELIMINADO COM CLIQUE DIREITO\n",inimigo,ax-1,ay);
                alteraConteudo(amb,ax-1,ay,'\0');
                flag =0;
            }

            if(baixo=='+')
            {
                char inimigo = mapa[ax+1][ay];
                printf("INIMIGO %c DA POSICAO (%d,%d) ELIMINADO COM CLIQUE DIREITO\n",inimigo,ax+1,ay);
                alteraConteudo(amb,ax+1,ay,'\0');
                flag =0;
            }

            if(esquerda=='+')
            {
                char inimigo = mapa[ax][ay-1];
                printf("INIMIGO %c DA POSICAO (%d,%d) ELIMINADO COM CLIQUE DIREITO\n",inimigo,ax,ay-1);
                alteraConteudo(amb,ax,ay-1,'\0');
                flag =0;
            }

            if(direita=='+')
            {
                char inimigo = mapa[ax][ay+1];
                printf("INIMIGO %c DA POSICAO (%d,%d) ELIMINADO COM CLIQUE DIREITO\n",inimigo,ax,ay+1);
                alteraConteudo(amb,ax,ay+1,'\0');
                flag =0;
            }

            if(flag)
            {
                int flagSaida = 0;
                for(int i=0;i<10;i++)
                {
                    for(int j=0;j<10;j++)
                    {
                        if(retornaSituacaoPosicao(amb,i,j)=='+')
                        {
                             printf("ALVO LONGE DA POSICAO ATUAL\n");
                             flag = 0;
                             flagSaida =1;
                             break;

                        }
                    }

                    if(flagSaida)
                        break;
                }
            }

            if(flag)
                printf("CLIQUE DIREITO SEM ALVO\n");
    }
}

/// @brief Função que indica se um caractere apertado está registrado nos caracteres válidos de um movimento
/// @param eve - ponteiro para a variável evento
/// @param c - Caractere que foi digitado no teclado
/// @return 1 se o caractere digitado está registrado como um caractere do evento
int identificaEventoClique(void *eve, char c)
{
    tClique* ck = (tClique*) eve;

    return c == ck->caracteres[0] || c == ck->caracteres[1] || c == ck->caracteres[2];
}