#include <stdio.h>
#include <stdlib.h>
#include "banco.h"


int main()
{
    tBanco* banco = CriaBanco();

    while(1)
    {
    char op;

    scanf("%c\n",&op);

    if(op=='F') 
        break;
    
    else if(op=='A')
        AbreContaBanco(banco);

    else if(op=='S')
        SaqueContaBanco(banco);

    else if(op=='D')
        DepositoContaBanco(banco);

    else if(op=='R')
        ImprimeRelatorioBanco(banco);

    else if(op=='T')
        TransferenciaContaBanco(banco);

    else
        printf("OPERACAO INVALIDA\n");

    }

    DestroiBanco(banco);
    return 0;
}