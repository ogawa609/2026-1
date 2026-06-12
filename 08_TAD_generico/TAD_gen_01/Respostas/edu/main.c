#include <stdio.h>
#include <stdlib.h>
#include "tadgen.h"

int main()
{
    printf("tad_gen_01\n");
    printf("Digite o tipo e numero de elementos:\n");
    int tipo,num;
    scanf("%d %d",&tipo,&num);

    tGeneric* g = CriaGenerico(tipo,num);
    LeGenerico(g);
    ImprimeGenerico(g);
    DestroiGenerico(g);

    return 0;
}