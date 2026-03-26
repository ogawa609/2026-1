#include <stdio.h>
#include <math.h>

int main(){
    float xAlvo,yAlvo,xTiro,yTiro,raioAlvo,raioTiro;
    scanf("%f %f %f %f %f %f",&xAlvo,&yAlvo,&raioAlvo,&xTiro,&yTiro,&raioTiro);
    float somaRaio=raioAlvo+raioTiro;

    float distancia= sqrt(((xAlvo-xTiro)*(xAlvo-xTiro))+((yAlvo-yTiro)*(yAlvo-yTiro)));

    if(somaRaio>=distancia){
        printf("ACERTOU\n");
    }
    else{
        printf("ERROU\n");
    }

    return 0;
}