#include <stdio.h>

int fatorial(int n){
    if(n<=1){
        return 1;
    }

    return n*fatorial(n-1);
}

int main(){

    int n;
    scanf("%d",&n);
    int fat=fatorial(n);
    printf("%d",fat);
    return 0;
}