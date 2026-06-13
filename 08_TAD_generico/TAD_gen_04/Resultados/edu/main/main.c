#include <stdio.h>
#include <stdlib.h>
#include "banco.h"


int main()
{
    tBanco* banco = CriaBanco();
    LeBanco(banco);

    char op;

    while(1)
    {
        scanf("%c\n",&op);

        if(op=='F')
            break;

        else if(op=='A')
        {
            tAgencia* a = CriaAgencia();
            LeAgencia(a);

            AdicionaAgencia(banco,a);
        }
        else if(op=='C')
        {
            tConta* c = CriaConta();
            LeConta(c);
            int num;
            scanf("%d\n",&num);
            InsereContaBanco(banco,num,c);
        }
        
    }


    ImprimeRelatorioBanco(banco);
    DestroiBanco(banco);
    return 0;
}