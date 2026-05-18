#include <stdio.h>
#include <string.h>
#include "rolagem.h"



/**
 * @brief Dispara a função de rolagem de mensagens.
 * 
 * @param FuncMsg Ponteiro para a função que recebe um array de mensagens e o número de mensagens.
 * @param tamanhoDisplay Tamanho do display.
 * @param tempoFim Tempo de duração da rolagem, que diz respeito a quantidade de deslocamento no painel.
 */
void RolaMsg(FptrMsg FuncMsg, int tamanhoDisplay, int tempoFim)
{ 
    int controlaMsgs=0;
    char msg[NUM_MAX_MSGS][TAM_MAX_MSG];
    int numMsg;

    FuncMsg(msg, &numMsg);

    char conc[NUM_MAX_MSGS*TAM_MAX_MSG]="";

    for(int i=0;i<numMsg;i++)
    {
        strcat(conc,msg[i]);
    }

    int tam = strlen(conc);

    for(int i=0;i<tempoFim;i++)
    {
        for(int j=0;j<tamanhoDisplay;j++)
        {
            printf("%c",conc[(controlaMsgs+j)%tam]);
            
        }
        controlaMsgs++;
        printf("\n");
        printf("\033[H\033[J");
    }
}