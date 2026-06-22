#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "motorista.h"
#include "veiculo.h"

#define MAX_BUFFER 318
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

tMotorista* CriaMotorista(char* nome,char* cnpj,char* telefone, char* endereco, char* user, char* senha)
{
    tMotorista* m = malloc(sizeof(tMotorista));

    int tam = strlen(nome) + 1;
    m->nome = malloc(tam*sizeof(char));
    strcpy(m->nome,nome);

    tam = strlen(cnpj) + 1;
    m->cnpj = malloc(tam*sizeof(char));
    strcpy(m->cnpj,cnpj);

    tam = strlen(telefone) + 1;
    m->telefone = malloc(tam*sizeof(char));
    strcpy(m->telefone,telefone);

    tam = strlen(endereco) + 1;
    m->endereco = malloc(tam*sizeof(char));
    strcpy(m->endereco,endereco);
    
    tam = strlen(user) + 1;
    m->nomeUsuario = malloc(tam*sizeof(char));
    strcpy(m->nomeUsuario,user);

    tam = strlen(senha) + 1;
    m->senha = malloc(tam*sizeof(char));
    strcpy(m->senha,senha);

    m->qntVeiculos = 0;

    m->veiculos = malloc(sizeof(tVeiculo*));

    return m;

}

tMotorista* LeMotorista()
{
    char nome[MAX_NOME];
    char cnpj[MAX_CNPJ];
    char telefone[MAX_TELEFONE];
    char endereco[MAX_ENDERECO];
    char user[MAX_NOME_USUARIO];
    char senha[MAX_SENHA];

    //**** */
    while(1) {

        char buffer[MAX_BUFFER + 1];
        scanf(" %[^\n]", buffer);
        getchar();

        if (strcmp(buffer, "OUT") == 0) {
            return NULL;
        }

        int qtdAtributos = sscanf(
            buffer,
            " %[^;]; %[^;]; %[^;]; %[^;]; %[^;]; %[^;];",
            nome,
            cnpj,
            telefone,
            endereco,
            user,
            senha
        );

        if (qtdAtributos < 6) {
            puts("ATRIBUTO(S) FALTANTE(S), FAVOR INICIAR O CADASTRO NOVAMENTE.");
            continue;
        }

        

        break;
    }

    //

    tMotorista* m = CriaMotorista(nome,cnpj,telefone,endereco,user,senha);
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

int ComparaCnpjMotorista(tMotorista* m, char* cnpj)
{
    return strcmp(m->cnpj,cnpj)==0;
}

tVeiculo* BuscaVeiculoemMotorista(tMotorista* m, char* placa)
{
    for(int i=0;i<m->qntVeiculos;i++)
    {
        char* cod = getCodVeiculo(m->veiculos[i]);

        if(strcmp(placa,cod)==0)
            return m->veiculos[i];
    }

    return NULL;
}

tVeiculo* BuscaNomeVeiculoemMotorista(tMotorista* m, char* marca)
{
    for(int i =0;i<m->qntVeiculos;i++)
    {
        char* nome = getNomeVeiculo(m->veiculos[i]);
       

        if(strstr(nome,marca)!=NULL)

            return m->veiculos[i];
    }
}

char* getCnpjMotorista(tMotorista* m)
{
    return m->cnpj;
}

void ImprimeListaVeiculosMotorista(tMotorista* m, int assentos,TipoAssinatura* p)
{
    for(int i=0;i<m->qntVeiculos;i++)
    {
        int b = getAssentosVeiculo(m->veiculos[i]);
        if(b>=assentos)
        {
                    printf("%d - ",i+1);
                    printaVeiculo(m->veiculos[i]);
                    float km = getKmVeiculo(m->veiculos[i]);
                    int ano = getAnoVeiculo(m->veiculos[i]);
                    char* fab = getMarcaVeiculo(m->veiculos[i]);
                    char* condutor = getNomeMotorista(m);
                     char* cnpj = getCnpjMotorista(m);
                    float nota = getNotaMediaVeiculo(m->veiculos[i]);
                    
                    

                    printf("%d; %.2f; %d; %s; %s (%s); %.2f\n",assentos,km,ano,fab,cnpj,condutor,nota);
        }
    }
}



