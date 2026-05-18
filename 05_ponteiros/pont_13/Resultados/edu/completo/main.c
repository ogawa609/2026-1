#include <stdio.h>
#include <string.h>
#include "rolagem.h"


void Mensagem(char msg[NUM_MAX_MSGS][TAM_MAX_MSG],int *n)
{
    scanf("%d",n);

    for(int i=0;i<*n;i++)
    {
        scanf(" %[^\n]",msg[i]);
    }
}

int main()
{
    int temp;
    scanf("%d",&temp);

    RolaMsg(Mensagem,30,temp);

    return 0;
}