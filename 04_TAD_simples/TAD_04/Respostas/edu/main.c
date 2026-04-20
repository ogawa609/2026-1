#include <stdio.h>
#include "aluno.h"

int main()
{
    int qnt;
    scanf("%d",&qnt);

    tAluno alunos[qnt];

    for(int i=0;i<qnt;i++)
        alunos[i]=LeAluno();
    
    for(int i=0;i<qnt;i++)
    {
        for(int j=i+1;j<qnt;j++)
        {
            if(ComparaMatricula(alunos[i],alunos[j])>0)
            {
                tAluno temp=alunos[i];
                alunos[i]=alunos[j];
                alunos[j]=temp;
            }

        }
    }

    for(int i=0;i<qnt;i++)
    {
        if(VerificaAprovacao(alunos[i]))
            ImprimeAluno(alunos[i]);
    }

    return 0;
}