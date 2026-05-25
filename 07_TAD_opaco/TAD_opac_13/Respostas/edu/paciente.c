#include <stdio.h>
#include <stdlib.h>
#include "paciente.h"
#include "data.h"
#include "lesao.h"
#include <string.h>

struct Paciente{

    char* nome;
    char* sus;
    char genero;
    Data* nascimento;
    Lesao* lesoes[MAX_LESOES];
    int qntLesoes;
};
/*
Função que cria um paciente a partir dos parâmetros fornecidos.
@param nome: Nome do paciente.
@param cartaoSus: Cartão SUS do paciente.
@param genero: Gênero do paciente.
@param dataNasc: Data de nascimento do paciente.
@return Ponteiro para o paciente criado.
*/
Paciente *criaPaciente(char *nome, char *cartaoSus, char genero, Data *dataNasc)
{
    Paciente* p = malloc(sizeof(Paciente));
    p->qntLesoes = 0;
    int tam = strlen(nome) +1;
    p->nome = malloc(tam*sizeof(char));

    tam = strlen(cartaoSus) + 1;
    p->sus = malloc(tam* sizeof(char));

    strcpy(p->nome,nome);
    strcpy(p->sus,cartaoSus);
    p->genero = genero;
    p->nascimento = dataNasc;

    return p;
    
}

/*
Função que lê os dados de um paciente a partir da entrada padrão. Consulte o enunciado e/ou os casos de teste para o formato esperado.
@return Ponteiro para o paciente lido.
*/
Paciente *lerPaciente()
{
    char nome[MAX_NOME_PAC];

    char sus[MAX_CARTAO_SUS];
    char genero;

    scanf("%[^\n]\n",nome);
    Data* d = lerData();
    scanf("%[^\n]\n",sus);
    scanf("%c\n",&genero);

    Paciente* p = criaPaciente(nome,sus,genero,d);

    return p;
}

/*
Função que adiciona uma lesão ao paciente.
Basicamente, a lesão é adicionada à lista de lesões do paciente realizando toda a alocação dinâmica necessária.
@param p: Ponteiro para o paciente ao qual a lesão será vinculada.
@param l: Ponteiro para a lesão a ser vinculada ao paciente.
*/
void adicionaLesaoPaciente(Paciente *p, Lesao *l)
{
    if(p->qntLesoes<MAX_LESOES)
    {
        if(strcmp(p->sus,getCartaoSusLesao(l))==0)
        {
            p->lesoes[p->qntLesoes] = l;
            p->qntLesoes++;
        }
    }
}

/*
Função que calcula a idade do paciente em anos completos com base em uma data de referência.
@param p: O paciente cuja idade será calculada.
@param dataBase: A data de referência para o cálculo da idade.
@return A idade do paciente em anos completos.
*/
int calculaIdadePaciente(Paciente *p, Data *dataBase)
{
    return diferencaAnoData(p->nascimento,dataBase);
}

/*
Função que obtém o cartão SUS de um paciente.
@param p: Ponteiro para o paciente do qual se deseja obter o cartão SUS.
@return Ponteiro para cartão SUS do paciente.
*/
char *getCartaoSusPaciente(Paciente *p)
{
    return p->sus;
}

/*
Função que obtém o número de lesões associadas a um paciente.
@param p: Ponteiro para o paciente cuja quantidade de lesões será obtida.
@return O número de lesões do paciente.
*/
int getNumLesoesPaciente(Paciente *p)
{
    return p->qntLesoes;
}

/*
Função que calcula a quantidade de lesões cirúrgicas (malignas) associadas a um paciente.
@param p: Ponteiro para o paciente cuja quantidade de lesões cirúrgicas será calculada.
@return A quantidade de lesões cirúrgicas do paciente.
*/
int qtdLesoesCirurgicasPaciente(Paciente *p)
{
    int total=0;
    for(int i=0;i<p->qntLesoes;i++)
        total += verificaCirurgicaLesao(p->lesoes[i]);

    return total;
}

/*
Função que imprime o nome do paciente e o ID das lesões associadas a ele (exatamente como solicitado no enunciado e nos casos de teste).
@param p: Ponteiro para o paciente cujas informações serão impressas.
*/
void imprimePaciente(Paciente *p)
{
    if(p->qntLesoes>0)
    {
        printf("- %s - ",p->nome);

        for(int i=0;i<p->qntLesoes;i++)
            imprimeIdLesao(p->lesoes[i]);

        printf("\n");
    }
}

/*
Função que libera a memória alocada para um paciente.
@param p: Ponteiro para o paciente a ser liberado.
*/
void liberaPaciente(Paciente *p)
{
    free(p->nome);
    free(p->sus);

    liberaData(p->nascimento);

    for(int i=0;i<p->qntLesoes;i++)
        liberaLesao(p->lesoes[i]);

    free(p);
}