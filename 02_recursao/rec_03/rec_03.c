#include <stdio.h>

int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado){

    if(numElementos<0){
        return 0;
    }
    else if(numeroProcurado!=vet[numElementos]){

        return 0+ContaOcorrencias(vet,numElementos-1,numeroProcurado);
    }

    return 1+ContaOcorrencias(vet,numElementos-1,numeroProcurado);
}

int main(){

    int casos;
    scanf("%d",&casos);

    for(int i=0;i<casos;i++){

        int procurado;
        scanf("%d",&procurado);

        int qtd;
        scanf("%d",&qtd);

        int vet[qtd];

        for(int j=0;j<qtd;j++){

            scanf("%d",&vet[j]);
        }

        int conta=ContaOcorrencias(vet,qtd,procurado);
        printf("%d\n",conta);
    }
    
    return 0;
}