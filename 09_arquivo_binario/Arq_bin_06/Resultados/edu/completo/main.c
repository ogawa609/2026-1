#include "estabelecimento.h"


int main()
{
    tEstabelecimento* e = CriaEstabelecimento();

    LeEstabelecimento(e);
    ImprimeRelatorioEstabelecimento(e);
    DestroiEstabelecimento(e);

    return 0;
}