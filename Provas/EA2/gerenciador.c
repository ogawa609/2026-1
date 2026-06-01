#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gerenciador.h"

struct Gerenciador
{
    tPaciente **bancoPacientes;
    int tamBanco;
    int tamBancoAlocado;
};


/*
Função que cria uma estrutura Gerenciador (alocando toda memória necessária), inicializa o que for necessário
e retorna o ponteiro para a estrutura criada.
*/
tGerenciador *criaGerenciador()
{
    tGerenciador* g = (tGerenciador*) malloc(sizeof(tGerenciador));

    g->tamBanco = 0;
    g->tamBancoAlocado = 0;

    g->bancoPacientes = (tPaciente**) malloc(sizeof(tPaciente*));

    return g;
}

/*
Função que adiciona um paciente ao banco de pacientes do gerenciador.
Se for necessário mais memória para alocar um novo paciente, essa função deve realocar a memória necessária.
*/
void adicionaPacienteBancoGerenciador(tGerenciador *g, tPaciente *p)
{
    g->bancoPacientes[g->tamBanco] = p;
    g->tamBanco++;
    g->tamBancoAlocado++;

    g->bancoPacientes = realloc(g->bancoPacientes,(g->tamBanco+1) * sizeof(tPaciente*));
}

/*
Função que busca e retorna um paciente (se existir) no banco de pacientes do gerenciador a partir do cartão do SUS.
Se não encontrar o paciente, retorna NULL.
*/
tPaciente *getPacientePeloSUSBancoGerenciador(tGerenciador *g, char *sus)
{
    for(int i =0;i<g->tamBanco;i++)
    {
        if(strcmp(getCartaoSusPaciente(g->bancoPacientes[i]),sus)==0)
            return g->bancoPacientes[i];
    }

    return NULL;
}

/*
Função que le os dados de pacientes e lesões a partir da entrada padrão e preenche o banco de
pacientes do gerenciador. Essa leitura seguem as regras descritas na descrição.
Perceba que o banco salva apenas os pacientes, as lesões são salvas nos pacientes.
*/
void preencheBancoPacientesGerenciador(tGerenciador *ger)
{
    char op;

    while(1)
    {
        scanf("%c\n",&op);

        if(op=='P')
        {
            tPaciente* p = lePaciente();
            adicionaPacienteBancoGerenciador(ger,p);
        }
        else if(op == 'L')
        {
            char sus[TAM_SUS];
            scanf("%[^\n]\n",sus);
            tLesao* lesao = leLesao();

            tPaciente* pobrezinho = getPacientePeloSUSBancoGerenciador(ger,sus);

            if(pobrezinho!=NULL)
                adicionaLesaoPaciente(pobrezinho,lesao);
            else
                liberaLesao(lesao);
            
        }
        else
            break;
    }
}

/*
Função que libera a memória alocada para a estrutura Gerenciador.
Ela verifica se o ponteiro passado é nulo antes de tentar liberar a memória.
*/
void liberaGerenciador(tGerenciador *g)
{
    for(int i=0;i<g->tamBanco;i++)
        liberaPaciente(g->bancoPacientes[i]);

    free(g->bancoPacientes);
    free(g);
}

/*
Função que calcula a média de idade dos pacientes do banco de pacientes do gerenciador.
Para isso, é necessário calcular a idade de cada paciente em relação a data de referência.
*/
int calculaMediaIdadePacientesBancoGerenciador(tGerenciador *g)
{
    int idade = 0;
    tData* data = criaData(27,5,2026);

    for(int i=0;i<g->tamBanco;i++)
        idade += calculaIdadePaciente(g->bancoPacientes[i],data);

    liberaData(data);

    return idade/g->tamBanco;
}

/*
Função que imprime os pacientes do banco de pacientes do gerenciador de acordo com a descrição.
*/
void imprimePacientesBancoGerenciador(tGerenciador *g)
{
    printf("LISTA DE PACIENTES:\n");

     for(int i=0;i<g->tamBanco;i++)
        imprimeIdLesoesPaciente(g->bancoPacientes[i]);
}

/*
Função que calcula a quantidade total de lesões dos pacientes do banco de pacientes do gerenciador.
Se não houver pacientes ou lesões associadas, retorna 0.
*/
int calculaQtdLesoesPacientesBancoGerenciador(tGerenciador *g)
{
    int total = 0;

     for(int i=0;i<g->tamBanco;i++)
        total+= getQtdLesoesPaciente(g->bancoPacientes[i]);

    return total;
}

/*
Função que calcula a quantidade total de cirurgias necessárias para os pacientes do banco de pacientes do gerenciador.
Se não houver pacientes ou lesões que necessitam de cirurgia, retorna 0.
*/
int calculaQtdCirurgiaPacientesBancoGerenciador(tGerenciador *g)
{
    int total = 0;

     for(int i=0;i<g->tamBanco;i++)
        total += getQtdCirurgiasPaciente(g->bancoPacientes[i]);

    return total;
}

/*
Função que imprime o relatório do gerenciador de acordo com a descrição da atividade.
*/
void imprimeRelatorioGerenciador(tGerenciador *g)
{
    if(g->tamBanco>0)
    {
        printf("TOTAL PACIENTES: %d\n",g->tamBanco);
        printf("MEDIA IDADE (ANOS): %d\n",calculaMediaIdadePacientesBancoGerenciador(g));
        printf("TOTAL LESOES: %d\n", calculaQtdLesoesPacientesBancoGerenciador(g));
        printf("TOTAL CIRURGIAS: %d\n",calculaQtdCirurgiaPacientesBancoGerenciador(g));
    }
    else
    {
            printf("TOTAL PACIENTES: %d\n",g->tamBanco);
        printf("MEDIA IDADE (ANOS): %d\n",0);
        printf("TOTAL LESOES: %d\n", 0);
        printf("TOTAL CIRURGIAS: %d\n",0);
    }

    imprimePacientesBancoGerenciador(g);
}

/*
TOTAL PACIENTES: 1
MEDIA IDADE (ANOS): 27
TOTAL LESOES: 1
TOTAL CIRURGIAS: 1
LISTA DE PACIENTES:
- SHOKO KOMI - L1 */
