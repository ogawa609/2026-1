#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movel.h"
#include "fila.h"


int main()
{
    int comandos;
    scanf("%d",&comandos);
    
    Fila* fila = FilaConstruct();

    for(int i=0;i<comandos;i++)
    {
        char op[50];
        scanf("%s",op);

        if(strcmp(op,"ENTRADA")==0)
        {
            tMovel* m = LeMovel();
            FilaPush(fila,m);
        }
        else if(strcmp(op,"PRODUZIR")==0)
        {
            int i = FilaSize(fila);
            if(i>0)
            {
                tMovel* prod = (tMovel*) FilaPop(fila);
                ImprimeMovel(prod);
                DestroiMovel(prod);
            }
        }
    }

    FilaDestroy(fila,DestroiMovel);
    return 0;
}