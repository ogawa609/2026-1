#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct Aluno {
    char* nome;
    char* data;
    char* curso;
    int periodo;
    float cr;
};

/**
 * @brief Função para criar um novo aluno.
 * 
 * @param nome Nome do aluno.
 * @param dataNascimento Data de nascimento do aluno.
 * @param curso Curso em que o aluno está matriculado.
 * @param periodo Período do curso em que o aluno está.
 * @param coeficienteRendimento Coeficiente de rendimento do aluno.
 * @return Um ponteiro para o aluno recém-criado. Se houver erro na alocação de memória, o programa é encerrado.
 */
tAluno* CriarAluno(char* nome, char* dataNascimento, char* curso, int periodo, float coeficienteRendimento)
{
    tAluno* a = malloc(sizeof(tAluno));

    int tam = strlen(nome) + 1;
    a->nome = malloc(tam*sizeof(char));
    strcpy(a->nome,nome);

    tam = strlen(dataNascimento) + 1;
    a->data = malloc(tam*sizeof(char));
    strcpy(a->data,dataNascimento);

    tam = strlen(curso) + 1;
    a->curso = malloc(tam*sizeof(char));
    strcpy(a->curso,curso);

    a->periodo = periodo;
    a->cr = coeficienteRendimento;

    return a;
}

/**
 * @brief Função para destruir um aluno.
 * 
 * @param aluno O aluno a ser destruído.
 */
void DestruirAluno(tAluno* aluno)
{
    free(aluno->curso);
    free(aluno->data);
    free(aluno->nome);
    free(aluno);
}

/**
 * @brief Função para ler um aluno de um arquivo binário.
 * 
 * @param arquivo_binario O arquivo binário para ler o aluno.
 * @return Um ponteiro para o aluno lido.
 */
tAluno *LeAluno(FILE *arquivo_binario)
{
    char nome[100];
    fread(nome,sizeof(char),100,arquivo_binario);

    char data[11];
    fread(data,sizeof(char),11,arquivo_binario);

    char curso[50];
    fread(curso,sizeof(char),50,arquivo_binario);

    float periodo;
    fread(&periodo,sizeof(float),1,arquivo_binario);

    float cr;
    fread(&cr,sizeof(float),1,arquivo_binario);

    

    tAluno* aluno = CriarAluno(nome,data,curso,periodo,cr);
    return aluno;
}

/**
 * @brief Função para obter o coeficiente de rendimento de um aluno.
 * 
 * @param aluno O aluno para obter o coeficiente de rendimento.
 * @return O coeficiente de rendimento do aluno.
 */
float GetCoeficienteRendimentoAluno(tAluno* aluno)
{
    return aluno->cr;
}