#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct aluno {
    char* nome;
    char* nascimento;
    char* curso;
    char* periodo;
    int conclusao;
    float cr;
};

Aluno** CriaVetorAlunos(int numeroAlunos)
{
    Aluno** a = malloc(numeroAlunos*sizeof(Aluno*));

    return a;
}

Aluno* CriaAluno(char *nome, char *dtNasc, char *cursoUfes, char* periodoIngresso, int percConclusao, float CRA)
{
    Aluno* a = malloc(sizeof(Aluno));

    int tam = strlen(nome) + 1;
    a->nome = malloc(tam*sizeof(char));
    strcpy(a->nome,nome);

    tam = strlen(dtNasc) + 1;
    a->nascimento = malloc(tam*sizeof(char));
    strcpy(a->nascimento,dtNasc);

    tam = strlen(cursoUfes) + 1;
    a->curso = malloc(tam*sizeof(char));
    strcpy(a->curso,cursoUfes);

    tam = strlen(periodoIngresso) + 1;
    a->periodo = malloc(tam*sizeof(char));
    strcpy(a->periodo,periodoIngresso);

    a->conclusao = percConclusao;
    a->cr = CRA;

    return a;

}

void LeAlunos(Aluno** vetorAlunos, int numeroAlunos)
{
    char nome[100];
    char nasc[100];
    char curso[100];
    char periodo[100];
    int per;
    float cr;

    for(int i=0;i<numeroAlunos;i++)
    {
        scanf(" %[^\n]",nome);
        scanf(" %[^\n]",nasc);
        scanf(" %[^\n]",curso);
        scanf(" %[^\n]",periodo);
        scanf("%d",&per);
        scanf("%f",&cr);

        Aluno* a = CriaAluno(nome,nasc,curso,periodo,per,cr);
        vetorAlunos[i] = a;

    }
}

void LiberaAlunos(Aluno** alunos, int numeroAlunos)
{
    
    for(int i=0;i<numeroAlunos;i++)
    {
        free(alunos[i]->curso);
        free(alunos[i]->nascimento);
        free(alunos[i]->nome);
        free(alunos[i]->periodo);
        free(alunos[i]);
    }

    free(alunos);
}

void SalvaAlunosBinario(Aluno **alunos, char *fileName, int numeroAlunos)
{
    FILE* f = fopen(fileName,"wb");
    int num = 0;
    num += (fwrite(&numeroAlunos,sizeof(int),1,f))*sizeof(int);
    

    for(int i=0;i<numeroAlunos;i++)
    {
        int tam = strlen(alunos[i]->nome)+1;
        num += (fwrite(&tam,sizeof(int),1,f))*sizeof(int);
        num += fwrite(alunos[i]->nome,sizeof(char),tam,f);

         tam = strlen(alunos[i]->nascimento)+1;
        num += (fwrite(&tam,sizeof(int),1,f))*sizeof(int);
        num += fwrite(alunos[i]->nascimento,sizeof(char),tam,f);

         tam = strlen(alunos[i]->curso)+1;
        num += (fwrite(&tam,sizeof(int),1,f))*sizeof(int);
        num += fwrite(alunos[i]->curso,sizeof(char),tam,f);

         tam = strlen(alunos[i]->periodo)+1;
        num += (fwrite(&tam,sizeof(int),1,f))*sizeof(int);
        num += fwrite(alunos[i]->periodo,sizeof(char),tam,f);

        num += (fwrite(&alunos[i]->conclusao,sizeof(int),1,f))*sizeof(int);
        num += (fwrite(&alunos[i]->cr,sizeof(float),1,f))*sizeof(float);
        

        

    }

    num -= 4*numeroAlunos;
    
    fwrite(&num,sizeof(int),1,f);

    fclose(f);
   
}

void CarregaAlunosBinario(Aluno **alunos, char *fileName)
{
    int numeroAlunos;
    FILE* f = fopen(fileName,"rb");
    fread(&numeroAlunos,sizeof(int),1,f);

    for(int i=0;i<numeroAlunos;i++)
    {

        char nome[100];
        char data[100];
        char curso[100];
        char periodo[100];
        int per;
        float cr;
        int tam= 0;
        fread(&tam,sizeof(int),1,f);
        fread(nome,sizeof(char),tam,f);

        fread(&tam,sizeof(int),1,f);
        fread(data,sizeof(char),tam,f);

        fread(&tam,sizeof(int),1,f);
        fread(curso,sizeof(char),tam,f);

        fread(&tam,sizeof(int),1,f);
        fread(periodo,sizeof(char),tam,f);

        fread(&per,1,sizeof(int),f);
        fread(&cr,1,sizeof(float),f);

        Aluno* a = CriaAluno(nome,data,curso,periodo,per,cr);

        alunos[i] = a;

    }

    int num;
    fread(&num,sizeof(int),1,f);
    printf("Numero de bytes salvos: %d",num);

    fclose(f);
}

void ImprimeAlunos(Aluno** alunos, int numeroAlunos)
{
    printf("\n");
    for(int i=0;i<numeroAlunos;i++)
    {
        printf("Aluno %d:\n",i);
        printf("Nome: %s\n",alunos[i]->nome);
        printf("Data Nascimento: %s\n",alunos[i]->nascimento);
        printf("Curso: %s\n",alunos[i]->curso);
        printf("Periodo Ingresso: %s\n",alunos[i]->periodo);
        printf("%% Conclusao do Curso: %d\n",alunos[i]->conclusao);
        printf("CRA: %.2f\n",alunos[i]->cr);
    }
}