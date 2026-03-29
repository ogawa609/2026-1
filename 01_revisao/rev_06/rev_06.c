#include <stdio.h>


int main(){

    char rotulos[1000];
    int limite;
    int quantidade=0;
    char c;
    int nenhum=1;

    scanf("%d",&limite);

    while(scanf(" %c",&c)!=EOF){
        

        if(c=='\n'){
            rotulos[quantidade]='\0';
            break;
        }

        rotulos[quantidade]=c;
        quantidade++;
    }
    

    
    //Organiza em ordem crescente
    for(int i=0;i<quantidade;i++){

        for(int j=i+1;j<quantidade;j++){

            int rotuloI= rotulos[i];
            int rotulosJ= rotulos[j];

            if(rotuloI>rotulosJ){

                char temp=rotulos[i];
                rotulos[i]=rotulos[j];
                rotulos[j]=temp;
            }
        }
    }

    int contar=1;
    char caracter=rotulos[0];

    for(int i=1;i<quantidade;i++){

       if(rotulos[i]==caracter)
            contar++;
       
        else{

            if(contar>limite){
                printf("%c: %d\n",caracter,contar);
                nenhum=0;
            }
            
            contar=1;

        }

        caracter=rotulos[i];

        
    }

    if(nenhum)
        printf("NENHUM");
    
    return 0;

}