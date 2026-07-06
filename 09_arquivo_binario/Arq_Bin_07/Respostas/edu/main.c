#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "professor.h"
#include "vector.h"

int main()
{
    Vector* professores;
    Vector* alunos;

    int qntAlunos;
    scanf("%d",&qntAlunos);

    for(int i =0;i<qntAlunos;i++)
    {
        tAluno* a = LeAluno();
        VectorPushBack(alunos,a);

    }

    int qntProf;
    scanf("%d",&qntProf);

    for(int i=0;i<qntProf;i++)
    {
        tProfessor* p = LeProfessor();
        VectorPushBack(professores,p);
    }

    char caminho[100];
    scanf("%s",caminho);

    FILE* f = fopen(caminho,"wb");
    int salvos = 0;
    int carregados = 0;

    for(int i=0;i<qntAlunos;i++)
    {
        void* d =  VectorGet(alunos,i);
       salvos += SalvaAluno((tAluno*)d,f);
    }

    for(int i=0;i<qntProf;i++)
    {
        void* pr = VectorGet(professores,i);
       salvos += SalvaProfessor((tProfessor*)pr,f);
    }
    fclose(f);

    VectorDestroy(alunos,DestroiAluno);
    VectorDestroy(professores,DestroiProfessor);

    FILE* arq = fopen(caminho,"rb");

    Vector* alunos2 = VectorConstruct();
    Vector* professores2 = VectorConstruct();

    for(int i=0;i<qntAlunos;i++)
    {
        tAluno* al;
        carregados += CarregaAluno(al,arq);
        VectorPushBack(alunos2,al);
    }

    for(int i=0;i<qntProf;i++)
    {
        tProfessor* pro;
        carregados += CarregaProfessor(pro,arq);
        VectorPushBack(professores2,pro);
    }

    printf("Numero de bytes salvos: %d\n",salvos);
    printf("Numero de bytes lidos: %d\n\n",carregados);

    printf("Alunos:\n");
    for(int i=0;i<qntAlunos;i++)
    {
        void* d1 = VectorGet()
        ImprimeNomeAluno()
    }
}