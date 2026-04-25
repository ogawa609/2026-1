#include <stdio.h>
#include "empresa.h"

int main()
{
    int qntEmpresas;
    scanf("%d",&qntEmpresas);

    tEmpresa empresas[qntEmpresas];

    for(int i=0;i<qntEmpresas;i++)
        empresas[i] = leEmpresa();

    for(int i=0;i<qntEmpresas;i++)
        imprimeEmpresa(empresas[i]);

    return 0;

}