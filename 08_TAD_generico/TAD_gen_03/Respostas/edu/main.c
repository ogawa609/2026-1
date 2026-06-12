#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "aluno.h"
#include "relatorio.h"

int main()
{
    int qnt;
    scanf("%d\n",&qnt);

    Vector* v = VectorConstruct();

    for(int i=0;i<qnt;i++)
    {
        tAluno* a = CriaAluno();
        LeAluno(a);

        VectorPushBack(v,a);
    }

    ImprimeRelatorio(v);
    VectorDestroy(v,DestroiAluno);

    return 0;
}
