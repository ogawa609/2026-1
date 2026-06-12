#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "relatorio.h"



/**
 * @brief Imprime o relatorio de uma coleção de alunos.
 * O relatorio deve possuir a media das notas, porcentagem de alunos aprovados e porcentagem de cada gênero.
 * 
 * @param alunos Ponteiro para o vetor de alunos.
*/
void ImprimeRelatorio(Vector *alunos)
{
    float mediaNotas = 0;
    int totalAlunos = VectorSize(alunos);
    int aprovados = 0;
    int masc = 0;
    int fem = 0;
    int outros = 0;
    
    for(int i = 0;i<VectorSize(alunos);i++)
    {
        tAluno* a = (tAluno*) VectorGet(alunos,i);
        float nota = GetNotaAluno(a);
        char gen = GetGeneroAluno(a);

        if(totalAlunos>0)
            mediaNotas += nota;

        if(nota>=6)
            aprovados++;
        
        if(gen=='M')
            masc++;
        else if(gen=='F')
            fem++;
        else
            outros++;
    }

    printf("Media das notas: %.2f\n",mediaNotas/totalAlunos);
    printf("Porcentagem de alunos aprovados: %.2f%%\n", (aprovados*100.0)/totalAlunos);
    printf("Porcentagem de cada genero:\n");
    printf("Masculino: %.2f%%\n",(masc*100.0)/totalAlunos);
    printf("Feminino: %.2f%%\n",(fem*100.0)/totalAlunos);
    printf("Outro: %.2f%%\n",(outros*100.0)/totalAlunos);
}