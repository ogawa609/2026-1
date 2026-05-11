#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"

int main()
{
    int n;
    scanf("%d\n", &n);

    tPessoa **pessoas = (tPessoa**) malloc (sizeof(tPessoa*)*n);
    for(int i=0; i<n; i++)
        pessoas[i] = criaPessoa();
    
    for(int i=0; i<n; i++)
        printaPessoa(pessoas[i]);

    for(int i=0; i<n; i++)
        liberaPessoa(pessoas[i]);
   
    if(pessoas != NULL)
        free(pessoas);
        
    return 0;
}