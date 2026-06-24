#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tEventoMovimento.h"


struct eventomovimento {
    char* caracteres;
};

/// @brief Função que cria um evento do tipo movimento
/// @param caracteresAceitos - Vetor de QUATRO caracteres que irá representar movimento
///                             na ordem: CIMA, ESQUERDA, BAIXO, DIREITA
/// @return O ponteiro para a variável do tipo evento movimento
tEventoMovimento* criaEventoMovimento(char *caracteresAceitos)
{
    tEventoMovimento* e = malloc(sizeof(tEventoMovimento));

    
    e->caracteres = malloc(4*sizeof(char));
   
    for(int i=0;i<4;i++)
    {
        e->caracteres[i] = caracteresAceitos[i];
    }

    return e;
}

/// @brief Função que libera o evento...
/// @param eve - Ponteiro para o evento
void liberaEventoMovimento(void* eve)
{
    tEventoMovimento* e = (tEventoMovimento*) eve;
    free(e->caracteres);
    free(e);

}

/// @brief Função que executará o comportamento de um evento movimento
///         No caso, deve alterar o ambiente de acordo com a tecla apertada, se for possível
/// @param amb - Ponteiro para o ambiente a ser manipulado
/// @param eve - Ponteiro para o evento de movimento 
/// @param c - Caractere que foi digitado no teclado
void processaEventoMovimento(tAmbiente *amb, void *eve, char c)
{
    tEventoMovimento* e = (tEventoMovimento*) eve;
    int x,y;
    retornaPosicaoAtual(amb,&x,&y);
    char posicao;

    if(c == e->caracteres[0])
    {
       
        if(x>0)
        {
             posicao = retornaSituacaoPosicao(amb,x-1,y);

            if(posicao == '\0' || posicao == '0')
            {
                x--;
                alteraPosicaoJogador(amb,x,y);
                printf("MOVIMENTO PARA POSICAO (%d,%d)\n",x,y);
                return;
            }
            else
            {
                printf("MOVIMENTO INVALIDO POIS EXISTE OBSTACULO!\n");
                return;
            }
        }
        else
            printf("MOVIMENTO INVALIDO POIS SAI DO MAPA!\n");

    }
    else if(c == e->caracteres[1])
    {
        if(y>0)
        {

            posicao = retornaSituacaoPosicao(amb,x,y-1);

            if(posicao == '\0' || posicao == '0')
            {
                y--;
                alteraPosicaoJogador(amb,x,y);
                printf("MOVIMENTO PARA POSICAO (%d,%d)\n",x,y);
                return;
            }
            else
            {
                printf("MOVIMENTO INVALIDO POIS EXISTE OBSTACULO!\n");
                return;
            }
        }
        else
            printf("MOVIMENTO INVALIDO POIS SAI DO MAPA!\n");
    }
    else if(c == e->caracteres[2])
    {

        if(x<9)
        {
             posicao = retornaSituacaoPosicao(amb,x+1,y);
             
            if(posicao == '\0' || posicao == '0')
            {
                x++;
                alteraPosicaoJogador(amb,x,y);
                printf("MOVIMENTO PARA POSICAO (%d,%d)\n",x,y);
                return;
            }
            else
            {
                printf("MOVIMENTO INVALIDO POIS EXISTE OBSTACULO!\n");
                return;
            }
        }
        else
            printf("MOVIMENTO INVALIDO POIS SAI DO MAPA!\n");

    }
    else if(c == e->caracteres[3])
    {
        if(y<9)
        {

            posicao = retornaSituacaoPosicao(amb,x,y+1);

            if(posicao == '\0' || posicao == '0')
            {
                y++;
                alteraPosicaoJogador(amb,x,y);
                printf("MOVIMENTO PARA POSICAO (%d,%d)\n",x,y);
                return;
            }
            else
            {
                printf("MOVIMENTO INVALIDO POIS EXISTE OBSTACULO!\n");
                return;
            }
        }
        else
            printf("MOVIMENTO INVALIDO POIS SAI DO MAPA!\n");
    }
}

/// @brief Função que indica se um caractere apertado está registrado nos caracteres válidos de um movimento
/// @param eve - ponteiro para a variável evento
/// @param c - Caractere que foi digitado no teclado
/// @return 1 se o caractere digitado está registrado como um caractere do evento
int identificaEventoMovimento(void *eve, char c)
{
    tEventoMovimento* e = (tEventoMovimento*) eve;
    return c== e->caracteres[0] || c==e->caracteres[1] || c==e->caracteres[2] || c==e->caracteres[3];
}