#include <stdio.h>
#include <stdlib.h>
#include "funcionario.h"
#include "empresa.h"

int main()
{
    int qntEmpresas;
    scanf("%d",&qntEmpresas);

    tEmpresa* empresas[qntEmpresas];

    for(int i=0;i<qntEmpresas;i++)
    {
        empresas[i] = CriaEmpresa();
        LeEmpresa(empresas[i]);
    }

    for(int i=0;i<qntEmpresas;i++)
    {
        ImprimeEmpresa(empresas[i]);
        ApagaEmpresa(empresas[i]);
        printf("\n");
    }

    return 0;
}