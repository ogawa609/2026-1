#include <stdio.h>
#include "pessoa.h"

int main()
{
    int qnt;
    scanf("%d",&qnt);

    tPessoa pessoas[qnt];

    for(int i=0;i<qnt;i++)
    {
        pessoas[i] = CriaPessoa();
        LePessoa(pessoas+i);

    }

    AssociaFamiliasGruposPessoas(pessoas,qnt);

     for(int i=0;i<qnt;i++)
    {
        ImprimePessoa(pessoas+i);

    }

    return 0;
}