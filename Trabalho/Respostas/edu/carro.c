#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carro.h"


struct Carro{
    char* placa;
    char* nome;
    char* marca;
    TipoAssinatura restricaoAssinatura;
    TipoUsuario restricaoUsuario;
    int anoFabricacao;
    float quilometragem;
    int qntAssentos;

    int petFriendly;
    int transportesIntermunicip;
    int arCondicionado;
    int disponibilidade4Passag;
    char* condicoesPneus;
    int step;

    float notaMedia;
};



/// @brief Cria uma variável do tipo tCarro a partir de uma linha de entrada.
/// @param linha String com as informações do carro.
/// @return O carro criado.
tCarro *criaCarro(char *linha)
{
    tCarro *c = malloc(sizeof(tCarro));

    char *str;
    int tam;

   

    str = strtok(linha, ";");
    while (*str == ' '||*str=='#') 
        str++;

    tam = strlen(str) + 1;
    c->placa = malloc(tam);
    strcpy(c->placa, str);


    str = strtok(NULL, ";");
    while (*str == ' ') 
        str++;

    tam = strlen(str) + 1;
    c->nome = malloc(tam);
    strcpy(c->nome, str);


    str = strtok(NULL, ";");
    while (*str == ' ') 
        str++;

    tam = strlen(str) + 1;
    c->marca = malloc(tam);
    strcpy(c->marca, str);


    str = strtok(NULL, ";");
    while (*str == ' ') 
        str++;

    if (atoi(str))
        c->restricaoAssinatura = PREMIUM;
    else
        c->restricaoAssinatura = PADRAO;


    str = strtok(NULL, ";");
    while (*str == ' ') 
        str++;

    if (atoi(str))
        c->restricaoUsuario = ADULTO;
    else
        c->restricaoUsuario = INFANTIL;


    str = strtok(NULL, ";");
    while (*str == ' ') 
        str++;

    c->anoFabricacao = atoi(str);


    str = strtok(NULL, ";");
    while (*str == ' ')
        str++;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ',')
            str[i] = '.';
    }

    c->quilometragem = atof(str);


    str = strtok(NULL, ";");
    while (*str == ' ') 
        str++;

    c->qntAssentos = atoi(str);


    str = strtok(NULL, ";");
    while (*str == ' ') 
        str++;

    c->petFriendly = atoi(str);


    str = strtok(NULL, ";");
    while (*str == ' ')
         str++;

    c->transportesIntermunicip = atoi(str);


    str = strtok(NULL, ";");
    while (*str == ' ') 
        str++;

    c->arCondicionado = atoi(str);


    str = strtok(NULL, ";");
    while (*str == ' ') 
        str++;

    c->disponibilidade4Passag= atoi(str);


    str = strtok(NULL, ";");
    while (*str == ' ') 
        str++;

    tam = strlen(str) + 1;
    c->condicoesPneus = malloc(tam);
    strcpy(c->condicoesPneus, str);


    str = strtok(NULL, ";");
    while (*str == ' ')
         str++;

    c->step = atoi(str);

    c->notaMedia = 0;

    return c;
}

/// @brief Libera a memória alocada para um carro.
/// @param dado Ponteiro genérico que deve ser convertido para tCarro*.
void liberaCarro(void *dado)
{
    tCarro* c = (tCarro*) dado;

    free(c->condicoesPneus);
    free(c->marca);
    free(c->nome);
    free(c->placa);
    free(c);
}

/// @brief Retorna o ano de fabricação de um carro.
/// @param dado Ponteiro genérico que deve ser convertido para tCarro*.
/// @return O ano de fabricação do carro.
int getAnoCarro(void *dado)
{
    tCarro* c = (tCarro*) dado;
    return c->anoFabricacao;
}

/// @brief Retorna o código de um carro.
/// @param dado Ponteiro genérico que deve ser convertido para tCarro*.
/// @return O código do carro.
char *getCodCarro(void *dado)
{
    tCarro* c = (tCarro*) dado;
    return c->placa;
}

/// @brief Retorna o nome de um carro.
/// @param dado Ponteiro genérico que deve ser convertido para tCarro*.
/// @return O nome do carro.
char *getNomeCarro(void *dado)
{
    tCarro* c = (tCarro*) dado;
    return c->nome;
}

/// @brief Retorna a quantidade de assentos de um carro.
/// @param dado Ponteiro genérico que deve ser convertido para tCarro*.
/// @return A quantidade de assentos do carro.
int getAssentosCarro(void *dado)
{
    tCarro* c = (tCarro*) dado;
    return c->qntAssentos;
}

/// @brief Retorna a quilometragem de um carro.
/// @param dado Ponteiro genérico que deve ser convertido para tCarro*.
/// @return A quilometragem do carro.
float getKmCarro(void *dado)
{
    tCarro* c = (tCarro*) dado;
    return c->quilometragem;
}

/// @brief Retorna a marca de um carro.
/// @param dado Ponteiro genérico que deve ser convertido para tCarro*.
/// @return A marca do carro.
char *getMarcaCarro(void *dado)
{
    tCarro* c = (tCarro*) dado;
    return c->marca;
}

/// @brief Retorna a nota média armazenada em um carro.
/// @param dado Ponteiro genérico que deve ser convertido para tCarro*.
/// @return A nota média do carro.
float getNotaMediaCarro(void *dado)
{
    tCarro* c = (tCarro*) dado;
    return c->notaMedia;
}

/// @brief Retorna a restrição de assinatura de um carro.
/// @param dado Ponteiro genérico que deve ser convertido para tCarro*.
/// @return O tipo de assinatura exigido pelo carro.
TipoAssinatura getRestricaoAssinaturaCarro(void *dado)
{
    tCarro* c = (tCarro*) dado;
    return c->restricaoAssinatura;
}

/// @brief Retorna a restrição de idade de um carro.
/// @param dado Ponteiro genérico que deve ser convertido para tCarro*.
/// @return O tipo de usuário permitido para o carro.
TipoUsuario getRestricaoIdadeCarro(void *dado)
{
    tCarro* c = (tCarro*) dado;
    return c->restricaoUsuario;
}

/// @brief Retorna a letra que representa um carro.
/// @return O caractere 'C'.
char getLetraTipoCarro(void)
{
    return 'C';
}

/// @brief Imprime as informações de um carro conforme especificação do trabalho.
/// @param dado Ponteiro genérico que deve ser convertido para tCarro*.
void printaCarro(void *dado)
{
    tCarro* c = (tCarro*) dado;
    printf("CARRO %s; %s; ",c->placa,c->nome);
} 