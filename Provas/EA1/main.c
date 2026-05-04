#include <stdio.h>
#include <string.h>
#include "servidor.h"


int main()
{
    tServidor serv = leBracketsServidor();
    criaRelatorioServidor(serv);

    return 0;
}