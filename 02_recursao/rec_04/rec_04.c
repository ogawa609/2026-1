#include <stdio.h>
#include <string.h>


int palindromo(char *string, int tamanho,int flag){

    if(tamanho<flag){
        return 1;
    }
    int inicio=string[flag];
    int final=string[tamanho];

    if(inicio-final==0){
        return 1*palindromo(string,tamanho-1,flag+1);
    }

    return 0*palindromo(string,tamanho-1,flag+1);

}

int main(){

    char palavra[1001];
    while( scanf("%1000s",palavra)!=EOF){

        int tam=strlen(palavra)-1;
        int ehPalin=palindromo(palavra,tam,0);

        if(ehPalin){
            printf("SIM\n");
        }
        else{
            printf("NAO\n");
        }
    }
   
    return 0;

}