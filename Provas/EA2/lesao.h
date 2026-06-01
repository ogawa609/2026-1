
#ifndef _LESAO_H
#define _LESAO_H

#define TAM_ID 10
#define TAM_DIAG 100
#define TAM_REG 100

typedef struct Lesao tLesao;

/*
struct Lesao
{
    char *id;        // salva o id da lesão
    char *diag;      // salva o diagnóstico da lesão
    char *regiao;    // salva a região da lesão
    int malignidade; // salva o grau de malignidade da lesão
};
*/

/*
Função que cria uma estrutura Lesao (alocando memória para o que for necessário), lê os valores da entrada padrão
de acordo com a descrição, e retorna o ponteiro para a estrutura criada.
*/
tLesao *leLesao();

/*
Função que libera a memória alocada para a estrutura Lesao.
Ela verifica se o ponteiro passado é nulo antes de tentar liberar a memória.
*/
void liberaLesao(tLesao *l);

/*
Função que retorna o Id da lesão passada como parâmetro.
*/
char *getIdLesao(tLesao *l);

/*
Função que calcula se a lesão passada como parâmetro precisa de cirurgia de acordo com a regra
informada na descrição.
*/
int precisaCirurgiaLesao(tLesao *l);

#endif