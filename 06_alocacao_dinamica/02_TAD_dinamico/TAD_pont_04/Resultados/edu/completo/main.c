#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

int main()
{
    int qnt;
    scanf("%d",&qnt);

    tAluno* alunos[qnt];
    for(int i = 0;i<qnt;i++)
    {
        alunos[i] = CriaAluno();
        LeAluno(alunos[i]);

    }

    for(int i=0;i<qnt;i++)
    {
        for(int j=i+1;j<qnt;j++)
        {
            if(ComparaMatricula(alunos[i],alunos[j])==1)
            {
                tAluno* temp =alunos[i];
                alunos[i] = alunos[j];
                alunos[j]= temp;
            }
        }
    }

    for(int i = 0;i<qnt;i++)
    {
        if(VerificaAprovacao(alunos[i]))
            ImprimeAluno(alunos[i]);
        
        ApagaAluno(alunos[i]);

    }

    return 0;
}