#include <stdio.h>

int VerificarTabuleiro(int linha, int coluna, int m[linha][coluna],int x1,int y1,char c){
    if(c=='B'){
        if(x1+1<linha){
            if(m[x1+1][y1]==0){
                x1++;
                return x1;
            }
            else{
                return -1;
            }
        }
        else{
            return -1;
        }
    }
    else if(c=='C'){
        if(x1-1>=0){
            if(m[x1-1][y1]==0){
                x1--;
                return x1;
            }
            else{
                return -1;
            }
        }
        else{
            return -1;
        }
    }
     else if(c=='E'){
        if(y1-1>=0){
            if(m[x1][y1-1]==0){
                y1--;
                return y1;
            }
            else{
                return -1;
            }
        }
        else{
            return -1;
        }
    }
     else if(c=='D'){
        if(y1+1<coluna){
            if(m[x1][y1+1]==0){
                y1++;
                return y1;
            }
            else{
                return -1;
            }
        }
        else{
            return -1;
        }
    }
}

int main(){

    int linha, coluna;
    int semSaida=1;

    scanf("%d %d",&linha,&coluna);

    //armazena posicoes ja andadas
    int caminhoX[linha*coluna];
    int caminhoY[coluna*coluna];

    //controla quantas casas andou;
    int contadorCaminho=0;

    int matriz[linha][coluna];

    for(int i=0;i<linha;i++){

        for(int j=0;j<coluna;j++){

            scanf("%d",&matriz[i][j]);
        }
    }
    //adiciona primeira casa ao trajeto
    int xi,yi,xf,yf;
    scanf("%d %d %d %d",&xi,&yi,&xf,&yf);
    xi--;
    yi--;
    xf--;
    yf--;
    caminhoX[0]=xi;
    caminhoY[0]=yi;
    contadorCaminho++;
    
   

    char comandos[4];
    for(int i=0;i<4;i++){
        scanf(" %c",&comandos[i]);

    }
    

    while(1){
        semSaida=1;

       if(xi==xf&&yi==yf){
            break;
       }

       for(int i=0;i<4;i++){

        int verifica=VerificarTabuleiro(linha,coluna,matriz,xi,yi,comandos[i]);

        if(verifica==-1)
        continue;

        else if(comandos[i]=='B'||comandos[i]=='C'){
            matriz[xi][yi]=2;
            xi=verifica;
            caminhoX[contadorCaminho]=xi;
            caminhoY[contadorCaminho]=yi;
            contadorCaminho++;
            semSaida=0;
            break;
        }
       
        else if(comandos[i]=='E'||comandos[i]=='D'){
            matriz[xi][yi]=2;
            yi=verifica;
            caminhoX[contadorCaminho]=xi;
            caminhoY[contadorCaminho]=yi;
            contadorCaminho++;
            semSaida=0;
            break;
        }
        
       }

       if(semSaida){
        break;
       }

       
    }

    for(int i=0;i<contadorCaminho;i++){
        printf("(%d,%d) ",caminhoX[i]+1,caminhoY[i]+1);
    }

    return 0;


}