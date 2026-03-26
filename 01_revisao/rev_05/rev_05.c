#include <stdio.h>

int main(){
    int linha, coluna;

    scanf("%d %d",&linha,&coluna);

    //armazena posicoes ja andadas
    int caminhoX[linha];
    int caminhoY[coluna];

    //controla quantas casas andou;
    int contadorCaminho=0;

    int matriz[linha][coluna];

    for(int i=0;i<linha;i++){

        for(int j=0;j<coluna;j++){

            scanf("%d",&matriz[i][j]);
        }
    }

    int xi,yi,xf,yf;
    scanf("%d %d %d %d",&xi,&yi,&xf,&yf);

    char comandos[4];
    for(int i=0;i<4;i++){
        scanf(" %c",&comandos[i]);

    }

    while(1){

       if(xi=xf&&yi==yf){
            break;
       }

       else{
            
       }

    }

    return 0;


}