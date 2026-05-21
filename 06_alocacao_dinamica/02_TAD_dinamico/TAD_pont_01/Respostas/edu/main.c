#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"



int main()
{
    while(1)
    {

    
        tJogo* jogo = CriaJogo();

        ComecaJogo(jogo);

        if(ContinuaJogo())
        {
            DestroiJogo(jogo);
            continue;
        }
        else
        {
            DestroiJogo(jogo);
            break;

        }
            
    }

    return 0;

}