#include <stdio.h>


int somaDigitos(int n){

    if(n<=0){

        return 0;
    }


    int digito = n % 10;
    int resto = n / 10;

    return digito + somaDigitos(resto);
}

int main(){
    int n;
    scanf("%d",&n);

    int valor=somaDigitos(n);
    printf("%d",valor);

    return 0;
}