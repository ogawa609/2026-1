#include <stdio.h>
#include "vetgenerico.h"

/*
    Função que cria e retorna uma variável do tipo tDado
    @param void *dado: endereço de memória de uma variável lida do lado de fora
    @param fptr_func impressao: endereço de uma função que opera sobre o dado

    @return tDado: variável do tipo tDado
*/
tDado leDadoGenerico(void *dado, fptr_func impressao)
{
    tDado d;
    d.dado=dado;
    d.impressao=impressao;
    return d;
    
}

/*
    Função que executa a callback de impressão de dados genéricos
    @param tDado d: variável tDado no qual o dado deve ser impresso utilizando
    a chamada da função com ponteiro armazenado no atributo impressão
    */
void imprimeDadoGenerico(tDado d)
{
    d.impressao(d.dado);
}