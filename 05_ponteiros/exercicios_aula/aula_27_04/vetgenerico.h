#ifndef _VET_G_H
#define _VET_G_H

#define INT 1
#define FLOAT 2
#define STRING 3
#define OUT 0

#define MAX_STR 50
#define MAX_DADOS_G 100

typedef void (*fptr_func)(void *dado);

typedef struct
{
    void *dado;
    fptr_func impressao;
}tDado;

/*
    Função que cria e retorna uma variável do tipo tDado
    @param void *dado: endereço de memória de uma variável lida do lado de fora
    @param fptr_func impressao: endereço de uma função que opera sobre o dado

    @return tDado: variável do tipo tDado
*/
tDado leDadoGenerico(void *dado, fptr_func impressao);

/*
    Função que executa a callback de impressão de dados genéricos
    @param tDado d: variável tDado no qual o dado deve ser impresso utilizando
    a chamada da função com ponteiro armazenado no atributo impressão
    */
void imprimeDadoGenerico(tDado d);

#endif