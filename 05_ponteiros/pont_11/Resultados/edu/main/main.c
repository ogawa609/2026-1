#include <stdio.h>
#include "calculadora.h"

float Adicao(float n1,float n2)
{
    return n1+n2;
}

float Subtracao(float n1,float n2)
{
    return n1-n2;
}

float Multiplicacao(float n1,float n2)
{
    return n1*n2;
}

float Divisao(float n1,float n2)
{
    return n1/n2;
}


int main()
{
    char op;
    float n1,n2,r;

    while(1)
    {
        scanf(" %c",&op);

        if(op=='f')
            break;

        scanf("%f %f",&n1,&n2);

        if(op=='a')
        {
            r = Calcular(n1,n2,Adicao);
            printf("%.2f + %.2f = %.2f\n",n1,n2,r);
        }
            
        else if(op=='s')
        {
            r = Calcular(n1,n2,Subtracao);
            printf("%.2f - %.2f = %.2f\n",n1,n2,r);
        }
            
        else if(op=='m')
        {
            r = Calcular(n1,n2,Multiplicacao);
            printf("%.2f x %.2f = %.2f\n",n1,n2,r);
        }
            
        else if(op == 'd')
        {
            r = Calcular(n1,n2,Divisao);
            printf("%.2f / %.2f = %.2f\n",n1,n2,r);
        }
            
    }

    return 0;
}