#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tEventoMovimento.h"


struct eventomovimento{

    char* caracteres;
};

/// @brief Função que cria um evento do tipo movimento
/// @param caracteresAceitos - Vetor de QUATRO caracteres que irá representar movimento
///                             na ordem: CIMA, ESQUERDA, BAIXO, DIREITA
/// @return O ponteiro para a variável do tipo evento movimento
tEventoMovimento* criaEventoMovimento(char *caracteresAceitos)
{
    tEventoMovimento* e = malloc(sizeof(tEventoMovimento));
    
    e->caracteres = malloc(sizeof(char)*4);

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
    tEventoMovimento* v = (tEventoMovimento*) eve;
    free(v->caracteres);
    free(v);
}

/// @brief Função que executará o comportamento de um evento movimento
///         No caso, deve alterar o ambiente de acordo com a tecla apertada, se for possível
/// @param amb - Ponteiro para o ambiente a ser manipulado
/// @param eve - Ponteiro para o evento de movimento 
/// @param c - Caractere que foi digitado no teclado
void processaEventoMovimento(tAmbiente *amb, void *eve, char c)
{
    tEventoMovimento* m = (tEventoMovimento*) eve;
    int Latual, Catual;
    retornaPosicaoAtual(amb,&Latual,&Catual);

    if(c==m->caracteres[0])
    {
        if(Latual>0)
        {
            char casa = retornaSituacaoPosicao(amb,Latual-1,Catual);
            if(casa=='0'||casa=='\0')
            {
                Latual--;
                alteraPosicaoJogador(amb,Latual,Catual);
                printf("MOVIMENTO PARA POSICAO (%d,%d)\n",Latual,Catual);
                return;
            }
            else
            {
                 printf("MOVIMENTO INVALIDO POIS EXISTE OBSTACULO!\n");
                 return;
            }
        }
        printf("MOVIMENTO INVALIDO POIS SAI DO MAPA!\n");
    }
    else if(c==m->caracteres[1])
    {
        if(Catual>0)
        {
            char casa = retornaSituacaoPosicao(amb,Latual,Catual-1);
            if(casa=='0'||casa=='\0')
            {
                Catual--;
                alteraPosicaoJogador(amb,Latual,Catual);
                printf("MOVIMENTO PARA POSICAO (%d,%d)\n",Latual,Catual);
                return;
            }
            else
            {
                printf("MOVIMENTO INVALIDO POIS EXISTE OBSTACULO!\n");
                 return;
            }
        }
        printf("MOVIMENTO INVALIDO POIS SAI DO MAPA!\n");
    }
    else if(c==m->caracteres[2])
    {
        if(Latual<9)
        {
            char casa = retornaSituacaoPosicao(amb,Latual+1,Catual);
            if(casa=='0'||casa=='\0')
            {
                Latual++;
                alteraPosicaoJogador(amb,Latual,Catual);
                printf("MOVIMENTO PARA POSICAO (%d,%d)\n",Latual,Catual);
                return;
            }
            else
            {
                printf("MOVIMENTO INVALIDO POIS EXISTE OBSTACULO!\n");
                 return;
            }
        }
        printf("MOVIMENTO INVALIDO POIS SAI DO MAPA!\n");
    }
    else if(c==m->caracteres[3])
    {
        if(Catual<9)
        {
            char casa = retornaSituacaoPosicao(amb,Latual,Catual+1);
            if(casa=='0'||casa=='\0')
            {
                Catual++;
                alteraPosicaoJogador(amb,Latual,Catual);
                printf("MOVIMENTO PARA POSICAO (%d,%d)\n",Latual,Catual);
                return;
            }
            else
            {
                printf("MOVIMENTO INVALIDO POIS EXISTE OBSTACULO!\n");
                 return;
            }
        }
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

    return c==e->caracteres[0]||c==e->caracteres[1]||c==e->caracteres[2]||c==e->caracteres[3];
}