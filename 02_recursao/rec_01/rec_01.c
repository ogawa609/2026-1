#include <stdio.h>
#include <string.h>

int ImprimeString(char*string,int i){
   
    if(i<0){
        return 0;
    }

    printf("%c",string[i]);
    return ImprimeString(string,i-1);  
   
}




int main(){

    char palavra[1001];
    
    while(scanf("%1000s",palavra)!=EOF){
    
        int i=strlen(palavra)-1;

        ImprimeString(palavra,i);
        
        printf(" ");
    }
    return 0;

}