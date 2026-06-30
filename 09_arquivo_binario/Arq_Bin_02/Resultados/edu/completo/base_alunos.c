#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "base_alunos.h"
#include "aluno.h"

struct BaseAlunos {

    tAluno** alunos;
    int qnt;
};

/**
 * @brief Função para criar uma nova base de alunos.
 * 
 * @return Um ponteiro para a base de alunos recém-criada. Se houver erro na alocação de memória, o programa é encerrado.
 */
tBaseAlunos* CriarBaseAlunos()
{
    tBaseAlunos* b = malloc(sizeof(tBaseAlunos));
    b->qnt = 0;

    return b;
}

/**
 * @brief Função para destruir uma base de alunos.
 * 
 * @param baseAlunos A base de alunos a ser destruída.
 */
void DestruirBaseAlunos(tBaseAlunos* baseAlunos)
{
    for(int i = 0; i<baseAlunos->qnt; i++)
    {
        DestruirAluno(baseAlunos->alunos[i]);
    }

    free(baseAlunos->alunos);
    free(baseAlunos);
}

/**
 * @brief Função para ler uma base de alunos de um arquivo binário.
 * 
 * @param baseAlunos A base de alunos para ler o arquivo.
 * @param nomeArquivo O nome do arquivo a ser lido.
 */
void LerBaseAlunos(tBaseAlunos* baseAlunos, char* nomeArquivo)
{
    FILE* f = fopen(nomeArquivo,"rb");

    int num;
    fread(&num,sizeof(int),1,f);

    baseAlunos->qnt = num;

    baseAlunos->alunos = malloc(num*sizeof(tAluno*));

    for(int i=0;i<num;i++)
    {
        tAluno* a = LeAluno(f);

        baseAlunos->alunos[i] = a;
    }

    fclose(f);


}

/**
 * @brief Função para obter o coeficiente de rendimento médio de uma base de alunos.
 * 
 * @param baseAlunos A base de alunos para obter o coeficiente de rendimento médio.
 * @return O coeficiente de rendimento médio da base de alunos.
 */
float GetCoeficienteRendimentoMedioBaseAlunos(tBaseAlunos* baseAlunos)
{
    float soma = 0;

    for(int i = 0;i<baseAlunos->qnt;i++)
    {
        soma += GetCoeficienteRendimentoAluno(baseAlunos->alunos[i]);
    }

    if(baseAlunos->qnt>0)
        return soma/baseAlunos->qnt;

    return 0;

}