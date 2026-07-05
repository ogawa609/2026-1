#include <stdio.h>
#include <stdlib.h>
#include "estabelecimento.h"

int main()
{
    tEstabelecimento* e = CriaEstabelecimento();

    LeEstabelecimento(e);
    ImprimeProdutosEmFaltaEstabelecimento(e);
    DestroiEstabelecimento(e);

    return 0;
}