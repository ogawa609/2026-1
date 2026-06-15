#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "motorista.h"
#include "veiculo.h"


struct Motorista{
    char* nome;
    char* cnpj;
    char* telefone;
    char* endereco;
    char* nomeUsuario;
    char* senha;

    int qntVeiculos;
    tVeiculo** veiculos;
};

tMotorista* CriaMotorista(char* linha)
{
    tMotorista* m = malloc(sizeof(tMotorista));

     char *str;
    int tam;

    str = strtok(linha, ";");
    while (*str == ' ') 
        str++;

    tam = strlen(str) + 1;
    m->nome = malloc(tam);
    strcpy(m->nome, str);


    str = strtok(NULL, ";");
    while (*str == ' ') 
        str++;

    tam = strlen(str) + 1;
    m->cnpj = malloc(tam);
    strcpy(m->cnpj, str);


    str = strtok(NULL, ";");
    while (*str == ' ') 
        str++;

    tam = strlen(str) + 1;
    m->telefone = malloc(tam);
    strcpy(m->telefone, str);

    
   str = strtok(NULL, ";");
    while (*str == ' ') 
        str++;

    tam = strlen(str) + 1;
    m->endereco = malloc(tam);
    strcpy(m->endereco, str);

    str = strtok(NULL, ";");
    while (*str == ' ') 
        str++;

    tam = strlen(str) + 1;
    m->nomeUsuario = malloc(tam);
    strcpy(m->nomeUsuario, str);

    str = strtok(NULL, ";");
    while (*str == ' ') 
        str++;

    tam = strlen(str) + 1;
    m->senha = malloc(tam);
    strcpy(m->senha, str);

    m->qntVeiculos = 0;
    m->veiculos = malloc(sizeof(tVeiculo*));

    return m;

}

void liberaMotorista(void* dado)
{
    tMotorista* m = (tMotorista*) dado;

    for(int i=0;i<m->qntVeiculos;i++)
        liberaVeiculo(m->veiculos[i]);
    free(m->veiculos);
    free(m->cnpj);
    free(m->endereco);
    free(m->nome);
    free(m->nomeUsuario);
    free(m->senha);
    free(m->telefone);
    free(m);
}

char *getNomeMotorista(void*dado)
{
    tMotorista* m = (tMotorista*) dado;
    return m->nome;
}
char *getTelefoneMotorista(void*dado)
{
    tMotorista* m = (tMotorista*) dado;
    return m->telefone;
}
char *getEnderecoMotorista(void*dado)
{
    tMotorista* m = (tMotorista*) dado;
    return m->endereco;
}
char *getNomeUsuarioMotorista(void*dado)
{
    tMotorista* m = (tMotorista*) dado;
    return m->nomeUsuario;
}
char *getSenhaMotorista(void*dado)
{
    tMotorista* m = (tMotorista*) dado;
    return m->senha;
}

void AdicionaVeiculoEmMotorista(tMotorista* m, tVeiculo*v)
{
    m->veiculos[m->qntVeiculos] = v;
    m->qntVeiculos++;
    m->veiculos = realloc(m->veiculos,(m->qntVeiculos+1)*sizeof(tVeiculo*));
}


