#include <stdio.h>

int SomaElementosPares(int* vet, int numElementos){

        if(numElementos<0){
            return 0;
        }

        else if(vet[numElementos]%2!=0){

            return 0+SomaElementosPares(vet,numElementos-1);
        }

        return vet[numElementos]+SomaElementosPares(vet,numElementos-1);
}

int main(){
    int numeroVetores;
    scanf("%d",&numeroVetores);

    for(int i=0;i<numeroVetores;i++){

        int qtd;
        scanf("%d",&qtd);

        int vetor[qtd];

        for(int j=0;j<qtd;j++){

            scanf("%d",&vetor[j]);
        }

        int soma=SomaElementosPares(vetor,qtd-1);

        printf("%d\n",soma);

    }

    return 0;
}