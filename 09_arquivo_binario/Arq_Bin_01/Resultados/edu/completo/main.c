#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"


int main()
{
    printf("Digite o numero de alunos: ");
    int num;
    scanf("%d",&num);

    Aluno** alunos = CriaVetorAlunos(num);
    LeAlunos(alunos,num);

    char file[] = "Arq";

    SalvaAlunosBinario(alunos,file,num);
    LiberaAlunos(alunos,num);

    Aluno** alunosNovo = CriaVetorAlunos(num);
    CarregaAlunosBinario(alunosNovo,file);
    ImprimeAlunos(alunosNovo,num);

    LiberaAlunos(alunosNovo,num);
    return 0;


}