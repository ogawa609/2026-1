

#ifndef _GERENCIADOR_H
#define _GERENC

// Dados de referência para cálculo de idade
#define DIA_BASE 27
#define MES_BASE 5
#define ANO_BASE 2026

#include "paciente.h"

typedef struct Gerenciador tGerenciador;
/*
struct Gerenciador
{
    tPaciente **bancoPacientes;
    int tamBanco;
    int tamBancoAlocado;
};
*/

/*
Função que cria uma estrutura Gerenciador (alocando toda memória necessária), inicializa o que for necessário
e retorna o ponteiro para a estrutura criada.
*/
tGerenciador *criaGerenciador();

/*
Função que adiciona um paciente ao banco de pacientes do gerenciador.
Se for necessário mais memória para alocar um novo paciente, essa função deve realocar a memória necessária.
*/
void adicionaPacienteBancoGerenciador(tGerenciador *g, tPaciente *p);

/*
Função que busca e retorna um paciente (se existir) no banco de pacientes do gerenciador a partir do cartão do SUS.
Se não encontrar o paciente, retorna NULL.
*/
tPaciente *getPacientePeloSUSBancoGerenciador(tGerenciador *g, char *sus);

/*
Função que le os dados de pacientes e lesões a partir da entrada padrão e preenche o banco de
pacientes do gerenciador. Essa leitura seguem as regras descritas na descrição.
Perceba que o banco salva apenas os pacientes, as lesões são salvas nos pacientes.
*/
void preencheBancoPacientesGerenciador(tGerenciador *ger);

/*
Função que libera a memória alocada para a estrutura Gerenciador.
Ela verifica se o ponteiro passado é nulo antes de tentar liberar a memória.
*/
void liberaGerenciador(tGerenciador *g);

/*
Função que calcula a média de idade dos pacientes do banco de pacientes do gerenciador.
Para isso, é necessário calcular a idade de cada paciente em relação a data de referência.
*/
int calculaMediaIdadePacientesBancoGerenciador(tGerenciador *g);

/*
Função que imprime os pacientes do banco de pacientes do gerenciador de acordo com a descrição.
*/
void imprimePacientesBancoGerenciador(tGerenciador *g);

/*
Função que calcula a quantidade total de lesões dos pacientes do banco de pacientes do gerenciador.
Se não houver pacientes ou lesões associadas, retorna 0.
*/
int calculaQtdLesoesPacientesBancoGerenciador(tGerenciador *g);

/*
Função que calcula a quantidade total de cirurgias necessárias para os pacientes do banco de pacientes do gerenciador.
Se não houver pacientes ou lesões que necessitam de cirurgia, retorna 0.
*/
int calculaQtdCirurgiaPacientesBancoGerenciador(tGerenciador *g);

/*
Função que imprime o relatório do gerenciador de acordo com a descrição da atividade.
*/
void imprimeRelatorioGerenciador(tGerenciador *g);

#endif
