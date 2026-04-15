#include <stdio.h>
#include "jogo.h"


int main()
{
   

    while(1)
    {
         tJogo jogo=CriaJogo();
         ComecaJogo(jogo);

         if(ContinuaJogo()==0)
            break;
    }

    return 0;
}