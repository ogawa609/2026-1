#include <stdio.h>
#include "tDepartamento.h"


int main()
{
    int n;
    scanf("%d",&n);

    tDepartamento dep[n];

    for(int i = 0;i<n;i++)
    {
        char nome[STRING_MAX];
        char curso1[STRING_MAX];
        char curso2[STRING_MAX];
        char curso3[STRING_MAX];
        char diretor[STRING_MAX];
        int m1,m2,m3;

        scanf(" %[^\n]",nome);
        scanf(" %[^\n]",diretor);
        scanf(" %[^\n]",curso1);
        scanf(" %[^\n]",curso2);
        scanf(" %[^\n]",curso3);
        scanf("%d %d %d",&m1,&m2,&m3);

        dep[i] = CriaDepartamento(curso1,curso2,curso3,nome,m1,m2,m3,diretor);

    }

    OrdenaDepartamentosPorMedia(dep,n);

    for(int i = 0;i<n;i++)
    {
        ImprimeAtributosDepartamento(dep[i]);
    }


    return 0;
}