#include <stdio.h>
#include "eleicao.h"

int main()
{

    tEleicao e=InicializaEleicao();

   e= RealizaEleicao(e);
   ImprimeResultadoEleicao(e);

   return 0;
}