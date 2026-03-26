#include <stdio.h>

int main(){
    int decimal;
    scanf("%d",&decimal);

    int numero[200];
    int i=0;
    int octal=0;
    int resultado=decimal;

    while(resultado>0){
        octal=resultado%8;
        numero[i]=octal;
        i++;
        resultado= resultado/8;
    }

    for(int j=i-1;j>=0;j--){
        printf("%d",numero[j]);
    }

    return 0;
}