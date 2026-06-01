#ifndef _paciente
#define _paciente

#include "data.h"
#include "lesao.h"

#define TAM_NOME 100
#define TAM_SUS 19

typedef struct Paciente tPaciente;
/*
struct Paciente
{
    char *nome;            // salva o nome do paciente
    tData *dataNasc;        // salva a data de nascimento do paciente
    char *cartaoSus;       // salva o cartão do SUS do paciente
    char genero;           // salva o gênero do paciente
    tLesao **lesoes;        // salva as lesões do paciente
    int qtdLesoes;         // salva a quantidade de lesões do paciente
    int qtdLesoesAlocadas; // controla a quantidade de lesões alocadas
};
*/

/*
Função que cria uma estrutura Paciente (alocando memória para o que for necessário), lê os valores da entrada padrão
de acordo com a descrição, e retorna o ponteiro para a estrutura criada.
*/
tPaciente *lePaciente();

/*
Função que libera toda a memória alocada para a estrutura Paciente.
Ela verifica se o ponteiro passado é nulo antes de tentar liberar a memória.
*/
void liberaPaciente(tPaciente *p);

/*
Função que recebe um paciente e uma lesão e adiciona a lesão ao paciente no grupo de lesões que ele possui.
Se for necessário mais memória para alocar uma nova lesão, essa função deve realocar a memória necessária.
*/
void adicionaLesaoPaciente(tPaciente *p, tLesao *l);

/*
Função que calcula a idade do paciente em relação a uma data de referência informada.
*/
int calculaIdadePaciente(tPaciente *p, tData *ref);

/*
Função que retorna a quantidade de cirurgias associadas a este paciente de acordo com as regras
descritas na descrição.
*/
int getQtdCirurgiasPaciente(tPaciente *p);

/*
Função que retorna o cartão do sus do paciente.
*/
char *getCartaoSusPaciente(tPaciente *p);

/*
Função que retorna a data de nascimento do paciente.
*/
tData *getDataNascPaciente(tPaciente *p);

/*
Função que retorna a quantidade de lesões do paciente
*/
int getQtdLesoesPaciente(tPaciente *p);

/*
Função que imprime o nome do paciente, seguido do IDs das lesões associadas a ele.
Ela verifica se existe lesão. Se não existir, nada é impresso.
Essa impressão segue o padrão da descrição.
*/
void imprimeIdLesoesPaciente(tPaciente *p);

#endif
