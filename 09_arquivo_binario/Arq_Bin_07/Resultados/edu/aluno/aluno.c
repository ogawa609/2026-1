#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct Aluno 
{
    char* nome;
    char* nascimento;
    char* curso;
    float perConcl;
    float cf;
};

/**
 * @brief Cria um novo aluno.
 * @param nome Nome do aluno.
 * @param dataNascimento Data de nascimento do aluno.
 * @param curso Curso do aluno.
 * @param prctConclusao Percentual de conclusão do curso.
 * @param cfRendimento Coeficiente de rendimento do aluno.
 * @return Um ponteiro para a estrutura do aluno criada. Caso a alocação falhe, a função termina o programa.
 */
tAluno *CriaAluno(char *nome, char *dataNascimento, char *curso, float prctConclusao, float cfRendimento)
{
    tAluno* a = malloc(sizeof(tAluno));
    a->cf = cfRendimento;
    a->perConcl = prctConclusao;

    int tam = strlen(nome) + 1;
    a->nome = malloc(tam*sizeof(char));
    strcpy(a->nome,nome);

    tam = strlen(dataNascimento) + 1;
    a->nascimento = malloc(tam*sizeof(char));
    strcpy(a->nascimento,dataNascimento);

    tam = strlen(curso) + 1;
    a->curso = malloc(tam*sizeof(char));
    strcpy(a->curso,curso);

    return a;
}

/**
 * @brief Destroi um aluno.
 * @param aluno Ponteiro para a estrutura do aluno a ser destruída.
 */
void DestroiAluno(tAluno *aluno)
{
    free(aluno->curso);
    free(aluno->nascimento);
    free(aluno->nome);
    free(aluno);
}

/**
 * @brief Lê um aluno da entrada padrão.
 * @return Um ponteiro para a estrutura do aluno lida.
 */
tAluno *LeAluno()
{
    char nome[100];
    char curso[100];
    char nascimento[50];
    float cr, per;
    scanf("%s",nome);
    scanf("%s",nascimento);
    scanf("%s",curso);
    scanf("%f",&per);
    scanf("%f",&cr);

    tAluno* aluno = CriaAluno(nome,nascimento,curso,per,cr);
    return aluno;
}

/**
 * @brief Compara o nome de dois alunos.
 * @param aluno1 Ponteiro para a estrutura do primeiro aluno.
 * @param aluno2 Ponteiro para a estrutura do segundo aluno.
 * @return Um inteiro indicando o resultado da comparação, conforme a função strcmp.
 */
int ComparaNomeAluno(tAluno *aluno1, tAluno *aluno2)
{
    return strcmp(aluno1->nome,aluno2->nome);
}

/**
 * @brief Salva um aluno em um arquivo binário.
 * @param aluno Ponteiro para a estrutura do aluno a ser salva.
 * @param file Ponteiro para o arquivo onde o aluno será salvo.
 * @return Um inteiro indicando o número de bytes salvos deste aluno.
 */
int SalvaAluno(tAluno *aluno, FILE *file)
{
    int total = 0;
    int tam = strlen(aluno->nome) + 1;
    total += fwrite(&tam,sizeof(int),1,file) * sizeof(int);
    total += fwrite(aluno->nome,sizeof(char),tam,file) -1 ;

    tam = strlen(aluno->nascimento) + 1;
    total += fwrite(&tam,sizeof(int),1,file) * sizeof(int);
    total += fwrite(aluno->nascimento,sizeof(char),tam,file) -1;

    tam = strlen(aluno->curso) + 1;
    total += fwrite(&tam,sizeof(int),1,file) * sizeof(int);
    total += fwrite(aluno->curso,sizeof(char),tam,file) -1;

    total += fwrite(&aluno->perConcl,sizeof(float),1,file) * sizeof(float);
    total += fwrite(&aluno->cf,sizeof(float),1,file) * sizeof(float);
    DestroiAluno(aluno);

    return total;
}

/**
 * @brief Carrega um aluno de um arquivo binário.
 * @param aluno Ponteiro para a estrutura do aluno a ser carregada.
 * @param file Ponteiro para o arquivo de onde o aluno será carregado.
 * @return Um inteiro indicando o número de bytes lidos deste aluno.
 */
int CarregaAluno(tAluno *aluno, FILE *file)
{
     int total = 0;
     char nome[100];
     char nascimento[100];
     char curso[100];
     float per;
     float cr;

     
    int tam;
    total += fread(&tam,sizeof(int),1,file) * sizeof(int);
    aluno->nome = malloc(tam*sizeof(char));
    total += fread(nome,sizeof(char),tam,file) -1 ;
    strcpy(aluno->nome,nome);

    tam = 0;
    total += fread(&tam,sizeof(int),1,file) * sizeof(int);
    aluno->nascimento = malloc(tam*sizeof(char));
    total += fread(nascimento,sizeof(char),tam,file) -1;
    strcpy(aluno->nascimento,nascimento);

    tam = 0;
    total += fread(&tam,sizeof(int),1,file) * sizeof(int);
    aluno->curso = malloc(tam*sizeof(char));
    total += fread(curso,sizeof(char),tam,file) -1;
    strcpy(aluno->curso,curso);

    total += fread(&per,sizeof(float),1,file) * sizeof(float);
    total += fread(&cr,sizeof(float),1,file) * sizeof(float);

    aluno->cf = cr;
    aluno->perConcl = per;
    

    return total;
}

/**
 * @brief Imprime o nome de um aluno na saída padrão.
 * @param aluno Ponteiro para a estrutura do aluno cujo nome será impresso.
 */
void ImprimeNomeAluno(tAluno *aluno)
{
    printf("%s",aluno->nome);
}
