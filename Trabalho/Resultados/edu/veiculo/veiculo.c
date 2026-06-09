#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "veiculo.h"

struct Veiculo{
    void* dado;
    func_ptr_anoVeiculo anoVeiculo;
    func_ptr_codVeiculo codVeiculo;
    func_ptr_notaMediaVeiculo notaMedia;
    func_ptr_nomeVeiculo nome;
    func_ptr_assentosVeiculo assentos;
    func_ptr_kmVeiculo km;
    func_ptr_marcaVeiculo marca;
    func_ptr_printaVeiculo printaVeiculo;
    func_ptr_restricaoAssinaturaVeiculo restricaoAssinatura;
    func_ptr_tipoVeiculo tipoVeiculo;
    func_ptr_restricaoIdadeVeiculo restricaoIdade;
    func_ptr_liberaVeiculo liberaVeiculo;

    tAvaliacao** avaliacoes;
    int quantidade;

};

/// @brief Cria um veículo genérico a partir de um dado específico e suas funções de acesso.
/// @param dado Ponteiro genérico para o veículo específico.
/// @param anoVeiculo Função que retorna o ano do veículo.
/// @param codVeiculo Função que retorna o código do veículo.
/// @param notaMedia Função que retorna a nota média do veículo.
/// @param nome Função que retorna o nome do veículo.
/// @param assentos Função que retorna a quantidade de assentos do veículo.
/// @param km Função que retorna a quilometragem do veículo.
/// @param marca Função que retorna a marca do veículo.
/// @param printaVeiculo Função que imprime o veículo.
/// @param restricaoAssinatura Função que retorna a restrição de assinatura do veículo.
/// @param tipoVeiculo Função que retorna a letra do tipo do veículo.
/// @param restricaoIdade Função que retorna a restrição de idade do veículo.
/// @param liberaVeiculo Função que libera o veículo específico.
/// @return O veículo genérico criado.
tVeiculo *criaVeiculo(void *dado,
                      func_ptr_anoVeiculo anoVeiculo,
                      func_ptr_codVeiculo codVeiculo,
                      func_ptr_notaMediaVeiculo notaMedia,
                      func_ptr_nomeVeiculo nome,
                      func_ptr_assentosVeiculo assentos,
                      func_ptr_kmVeiculo km,
                      func_ptr_marcaVeiculo marca,
                      func_ptr_printaVeiculo printaVeiculo,
                      func_ptr_restricaoAssinaturaVeiculo restricaoAssinatura,
                      func_ptr_tipoVeiculo tipoVeiculo,
                      func_ptr_restricaoIdadeVeiculo restricaoIdade,
                      func_ptr_liberaVeiculo liberaVeiculo)
                      {

                        tVeiculo* v = malloc(sizeof(tVeiculo));
                        v->dado = dado;
                        v->anoVeiculo = anoVeiculo;
                        v->assentos = assentos;
                        v->codVeiculo = codVeiculo;
                        v->km = km;
                        v->liberaVeiculo = liberaVeiculo;
                        v->marca = marca;
                        v->nome = nome;
                        v->notaMedia = notaMedia;
                        v->printaVeiculo = printaVeiculo;
                        v->restricaoAssinatura = restricaoAssinatura;
                        v->restricaoIdade = restricaoIdade;
                        v->tipoVeiculo = tipoVeiculo;

                        v->quantidade = 0;
                        v->avaliacoes = malloc(sizeof(tAvaliacao*));

                        return v;
                      }

/// @brief Retorna a restrição de assinatura de um veículo.
/// @param v Ponteiro para o veículo.
/// @return O tipo de assinatura exigido pelo veículo.
TipoAssinatura getRestricaoAssinaturaVeiculo(tVeiculo *v)
{
   return  v->restricaoAssinatura(v->dado);
}

/// @brief Imprime as informações de um veículo.
/// @param v Ponteiro para o veículo.
void printaVeiculo(tVeiculo *v)
{
    v->printaVeiculo(v->dado);
}

/// @brief Retorna a letra que representa o tipo de um veículo.
/// @param v Ponteiro para o veículo.
/// @return A letra do tipo do veículo.
char getTipoVeiculoLetra(tVeiculo *v)
{
    return v->tipoVeiculo();
}

/// @brief Retorna o código de um veículo.
/// @param v Ponteiro para o veículo.
/// @return O código do veículo.
char *getCodVeiculo(tVeiculo *v)
{
    return v->codVeiculo(v->dado);
}

/// @brief Retorna a restrição de idade de um veículo.
/// @param v Ponteiro para o veículo.
/// @return O tipo de usuário permitido para o veículo.
TipoUsuario getRestricaoIdadeVeiculo(tVeiculo *v)
{
    return v->restricaoIdade(v->dado);
}

/// @brief Retorna o nome de um veículo.
/// @param v Ponteiro para o veículo.
/// @return O nome do veículo.
char *getNomeVeiculo(tVeiculo *v)
{
    return v->nome(v->dado);
}

/// @brief Calcula e retorna a nota média das avaliações de um veículo.
/// @param v Ponteiro para o veículo.
/// @return A nota média do veículo.
float getNotaMediaVeiculo(tVeiculo *v)
{
    float media = 0;
   if(v->quantidade>0)
    {
        for(int i=0;i<v->quantidade;i++)
        {
            media += getNotaAvaliacao(v->avaliacoes[i]);
        }

        media = media/v->quantidade;
    }

    v->notaMedia = (int) media;
    
    return media;
}

/// @brief Insere uma avaliação em um veículo.
/// @param v Ponteiro para o veículo.
/// @param a Ponteiro para a avaliação que será inserida.
void inserirAvaliacaoVeiculo(tVeiculo *v, tAvaliacao *a)
{
    v->avaliacoes[v->quantidade] = a;

    v->quantidade++;
    v->avaliacoes = realloc(v->avaliacoes,(v->quantidade+1)*sizeof(tAvaliacao*));
}

/// @brief Imprime o veículo com a nota dada por um usuário.
/// @param v Ponteiro para o veículo.
/// @param cpf CPF do usuário que realizou a avaliação.
void printaVeiculoComNota(tVeiculo *v, char *cpf)
{
   float media = 0;
   if(v->quantidade>0)
    {
        for(int i=0;i<v->quantidade;i++)
        {
            media += getNotaAvaliacao(v->avaliacoes[i]);
        }

        media = media/v->quantidade;
    }


            
    
    printf("CORRIDA %s AVALIADA COM NOTA %.1f\n",v->codVeiculo(v->dado),getNotaMediaVeiculo(v));
}

/// @brief Busca a avaliação feita por um CPF em um veículo.
/// @param v Ponteiro para o veículo.
/// @param cpf CPF do usuário avaliador.
/// @return A avaliação encontrada, ou NULL caso não exista.
tAvaliacao *buscaNotaAvaliacaoVeiculo(tVeiculo *v, char *cpf)
{
    for(int i=0;i<v->quantidade;i++)
    {
        if(strcmp(getCpfAvaliacao(v->avaliacoes[i]),cpf)==0)
        {
            return v->avaliacoes[i];
        }
    }

    return NULL;
}

/// @brief Retorna a quantidade de avaliações de um veículo.
/// @param v Ponteiro para o veículo.
/// @return A quantidade de avaliações cadastradas.
int getQtdAvaliacoesVeiculo(tVeiculo *v)
{
    return v->quantidade;
}

/// @brief Retorna a avaliação armazenada em uma posição.
/// @param v Ponteiro para o veículo.
/// @param pos Posição da avaliação no vetor.
/// @return A avaliação da posição informada.
tAvaliacao *getAvaliacaoPosicaoVeiculo(tVeiculo *v, int pos)
{
    return v->avaliacoes[pos];
}

/// @brief Libera a memória alocada para um veículo genérico.
/// @param v Ponteiro para o veículo que será liberado.
void liberaVeiculo(tVeiculo *v)
{
    for(int i=0;i<v->quantidade;i++)
        liberaAvaliacao(v->avaliacoes[i]);
    free(v->avaliacoes);

    v->liberaVeiculo(v->dado);
    free(v);
}

/// @brief Retorna o dado específico armazenado em um veículo genérico.
/// @param v Ponteiro para o veículo.
/// @return Ponteiro genérico para o veículo específico.
void *getDadoVeiculo(tVeiculo *v)
{
    return v->dado;
}

/// @brief Retorna a quantidade de assentos de um veículo.
/// @param v Ponteiro para o veículo.
/// @return A quantidade de assentos do veículo.
int getAssentosVeiculo(tVeiculo *v)
{
    return v->assentos(v->dado);
}

/// @brief Retorna o ano de um veículo.
/// @param v Ponteiro para o veículo.
/// @return O ano do veículo.
int getAnoVeiculo(tVeiculo *v)
{
    return v->anoVeiculo(v->dado);
}

/// @brief Retorna a quilometragem de um veículo.
/// @param v Ponteiro para o veículo.
/// @return A quilometragem do veículo.
float getKmVeiculo(tVeiculo *v)
{
    return v->km(v->dado);
}

/// @brief Retorna a marca de um veículo.
/// @param v Ponteiro para o veículo.
/// @return A marca do veículo.
char *getMarcaVeiculo(tVeiculo *v)
{
    return v->marca(v->dado);
}