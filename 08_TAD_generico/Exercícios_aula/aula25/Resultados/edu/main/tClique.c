#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tClique.h"


struct clique{

    char* teclas;
    
};

/// @brief Função que cria um evento do tipo movimento
/// @param caracteresAceitos - Vetor de QUATRO caracteres que irá representar movimento
///                             na ordem: CIMA, ESQUERDA, BAIXO, DIREITA
/// @return O ponteiro para a variável do tipo evento movimento
tClique* criaEventoClique(char *caracteresAceitos)
{
    tClique* c = malloc(sizeof(tClique));

    c->teclas = malloc(sizeof(char)*3);

    for(int i=0;i<3;i++)
        c->teclas[i] = caracteresAceitos[i];

   

    return c;
}

/// @brief Função que libera o evento...
/// @param eve - Ponteiro para o evento
void liberaEventoClique(void* eve)
{
    tClique* c = (tClique*) eve;

   

    free(c->teclas);
    free(c);
}

/// @brief Função que executará o comportamento de um evento movimento
///         No caso, deve alterar o ambiente de acordo com a tecla apertada, se for possível
/// @param amb - Ponteiro para o ambiente a ser manipulado
/// @param eve - Ponteiro para o evento de movimento 
/// @param c - Caractere que foi digitado no teclado
void processaEventoClique(tAmbiente *amb, void *eve, char c)
{
    tClique* e = (tClique*) eve;
    
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
    int Alinha,Acoluna;
    retornaPosicaoAtual(amb,&Alinha,&Acoluna);

    if(c==e->teclas[0])
    {
        int x,y;
        scanf("%d %d\n",&x,&y);
        

        if(x<0||x>9||y<0||y>9)
        {
             printf("MOVIMENTO INVALIDO POIS SAI DO MAPA!\n");
             return;
        }

        if((((Alinha-x)*(Alinha-x))+((Acoluna-y)*(Acoluna-y)))==1)
        {
            char casa = retornaSituacaoPosicao(amb,x,y);

            if((casa>='a'&&casa<='z')||(casa>='A'&&casa<='Z'))
            {
                printf("INIMIGO %c SELECIONADO EM (%d,%d)\n",casa,x,y);
                alteraConteudo(amb,x,y,'+');
            }
            else if(casa=='-'||casa=='|')
                 printf("CLIQUE ESQUERDO NAO SELECIONOU INIMIGO\n");
        }
        else
            printf("CLIQUE LONGE DA POSICAO ATUAL\n");
    }
    else if(c == e->teclas[1])
    {
        char cima,baixo,esquerda,direita;
        cima = baixo = esquerda = direita = '#';

       
        
            cima = retornaSituacaoPosicao(amb,Alinha-1,Acoluna);
            baixo = retornaSituacaoPosicao(amb,Alinha+1,Acoluna);
            esquerda = retornaSituacaoPosicao(amb,Alinha,Acoluna-1);
            direita = retornaSituacaoPosicao(amb,Alinha,Acoluna+1);
            int flag = 1;

            

            if(cima=='+')
            {
                char inimigo = mapa[Alinha-1][Acoluna];
                printf("INIMIGO %c DA POSICAO (%d,%d) ELIMINADO COM CLIQUE DO MEIO\n",inimigo,Alinha-1,Acoluna);
                alteraConteudo(amb,Alinha-1,Acoluna,'\0');
                flag =0;
            }

            if(baixo=='+')
            {
                char inimigo = mapa[Alinha+1][Acoluna];
                printf("INIMIGO %c DA POSICAO (%d,%d) ELIMINADO COM CLIQUE DO MEIO\n",inimigo,Alinha+1,Acoluna);
                alteraConteudo(amb,Alinha+1,Acoluna,'\0');
                
                flag =0;
            }

            if(esquerda=='+')
            {
                char inimigo = mapa[Alinha][Acoluna-1];
                printf("INIMIGO %c DA POSICAO (%d,%d) ELIMINADO COM CLIQUE DO MEIO\n",inimigo,Alinha,Acoluna-1);
                alteraConteudo(amb,Alinha,Acoluna-1,'\0');
                flag =0;
            }

            if(direita=='+')
            {
                char inimigo = mapa[Alinha][Acoluna+1];
                printf("INIMIGO %c DA POSICAO (%d,%d) ELIMINADO COM CLIQUE DO MEIO\n",inimigo,Alinha,Acoluna+1);
                alteraConteudo(amb,Alinha,Acoluna+1,'\0');
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
    else if(c==e->teclas[2])
    {
         char cima,baixo,esquerda,direita;
        cima = baixo = esquerda = direita = '#';

       
            cima = retornaSituacaoPosicao(amb,Alinha-1,Acoluna);
            baixo = retornaSituacaoPosicao(amb,Alinha+1,Acoluna);
            esquerda = retornaSituacaoPosicao(amb,Alinha,Acoluna-1);
            direita = retornaSituacaoPosicao(amb,Alinha,Acoluna+1);
            int flag = 1;

           
               

            if(cima=='+')
            {
                char inimigo = mapa[Alinha-1][Acoluna];
                printf("INIMIGO %c DA POSICAO (%d,%d) ELIMINADO COM CLIQUE DIREITO\n",inimigo,Alinha-1,Acoluna);
                alteraConteudo(amb,Alinha-1,Acoluna,'\0');
                flag =0;
            }

            if(baixo=='+')
            {
                char inimigo = mapa[Alinha+1][Acoluna];
                printf("INIMIGO %c DA POSICAO (%d,%d) ELIMINADO COM CLIQUE DIREITO\n",inimigo,Alinha+1,Acoluna);
                alteraConteudo(amb,Alinha+1,Acoluna,'\0');
                flag =0;
            }

            if(esquerda=='+')
            {
                char inimigo = mapa[Alinha][Acoluna-1];
                printf("INIMIGO %c DA POSICAO (%d,%d) ELIMINADO COM CLIQUE DIREITO\n",inimigo,Alinha,Acoluna-1);
                alteraConteudo(amb,Alinha,Acoluna-1,'\0');
                flag =0;
            }

            if(direita=='+')
            {
                char inimigo = mapa[Alinha][Acoluna+1];
                printf("INIMIGO %c DA POSICAO (%d,%d) ELIMINADO COM CLIQUE DIREITO\n",inimigo,Alinha,Acoluna+1);
                alteraConteudo(amb,Alinha,Acoluna+1,'\0');
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
    tClique* e = (tClique*) eve;
    return  c == e->teclas[0] || c == e->teclas[1] || c == e->teclas[2];
}