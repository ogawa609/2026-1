#include <stdio.h>

int main(){
    int quantidade;
    int nenhum=1;
    scanf("%d",&quantidade);
    int biblioteca[quantidade];

    for(int i=0;i<quantidade;i++){
        scanf("%d",&biblioteca[i]);
    }

    for(int i=0;i<quantidade;i++){

        if(biblioteca[i]<0)
        continue;

        int copia=1;

        for(int j=i+1;j<quantidade;j++){

            if(biblioteca[i]==biblioteca[j]){

                copia=0;
                biblioteca[j]=-1;
            }
        }

        if(copia){
            
            printf("%d ",biblioteca[i]);
            nenhum=0;
        }
    }
    
    if(nenhum){
        printf("NENHUM");
    }

    return 0;
}