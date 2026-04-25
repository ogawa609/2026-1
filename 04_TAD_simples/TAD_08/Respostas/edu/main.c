#include <stdio.h>
#include "departamento.h"

int main()
{
    int qnt;
    scanf("%d",&qnt);

    tDepartamento dep[qnt];

    for(int i=0;i<qnt;i++)
    {
        char nome[100];
        char c1[50];
        char c2[50];
        char c3[50];
        int m1,m2,m3;
        char diretor[100];

        scanf("%s\n",nome);
        scanf("%s\n",diretor);
        scanf("%s\n",c1);
        scanf("%s\n",c2);
        scanf("%s\n",c3);
        scanf("%d %d %d",&m1,&m2,&m3);

        tDepartamento d = criaDepartamento(c1,c2,c3,nome,m1,m2,m3,diretor);
        int media = calculaMediaGeralDepartamento(d);

        if(validaMediaDepartamento(media))
            dep[i] = d;

    }

    ordenaPorMediaDepartamentos(dep,qnt);

    for(int i=0;i<qnt;i++)
    {
        imprimeAtributosDepartamento(dep[i]);
    }

    return 0;
}