#include <stdio.h>
#include  <stdlib.h>
#include "servidor.h"



int main()
{
    tServidor* serv = leBracketsServidor();
    criaRelatorioServidor(serv);
    liberaServidor(serv);

    return 0;
}