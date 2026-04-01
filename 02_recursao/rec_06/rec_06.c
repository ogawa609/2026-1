#include <stdio.h>

int fibonacci(int n,int atual,int antigo){

    
    if(n<=0){
        return antigo;
    }
   

return fibonacci(n-1,antigo,antigo+atual);


    
}

int main(){

    int n;
    scanf("%d",&n);

  int fib=  fibonacci(n,1,0);
  printf("%d",fib);
  return 0;

}