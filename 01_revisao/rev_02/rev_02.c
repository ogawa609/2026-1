#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);

    int coluna=1;
    int j=1;
    
    for(int i=0;i<n;i++){

        for(int k=0;k<j;k++){
            printf("%d ",coluna);
            coluna++;
        }
        
        j++;
        printf("\n");
    }
    return 0;
}