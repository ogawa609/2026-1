#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "usuario.h"
#include "corrida.h"
#include "util.h"
#include "data.h"

#define MAX_BUFFER 375

struct Usuario{

    char* nome;
    char* cpf;
    char* telefone;
    char* endereco;
    char* nomeUsuario;
    char* senha;

    tData* nascimento;
    char* email;
    int servicosConsumidos;
    int totalAvaliacoes;
    int minutosGastos;

    tCorrida** corridas;
    int numCorridas;

    TipoUsuario restricao;
    TipoAssinatura assinatura;
    char* cartao;

};

// Aloca memoria para struct e para os campos; inicia os campos; insere dados em cada campo passada por parâmetros;
tUsuario* CriaUsuario(char*nome,char*cpf,char*tel,char*ender,char*user,
char*senha,int dia,int mes, int ano,char* email,char* cartao, char* assinatura)
{
    tUsuario* m = malloc(sizeof(tUsuario));

    int tam = strlen(nome) + 1;
    m->nome = malloc(tam*sizeof(char));
    strcpy(m->nome, nome);

    tam = strlen(cpf) + 1;
    m->cpf = malloc(tam*sizeof(char));
    strcpy(m->cpf, cpf);

    tam = strlen(tel) + 1;
    m->telefone = malloc(tam*sizeof(char));
    strcpy(m->telefone, tel);

    tam = strlen(ender) + 1;
    m->endereco = malloc(tam*sizeof(char));
    strcpy(m->endereco, ender);

    tam = strlen(user) + 1;
    m->nomeUsuario = malloc(tam*sizeof(char));
    strcpy(m->nomeUsuario, user);

    tam = strlen(senha) + 1;
    m->senha = malloc(tam*sizeof(char));
    strcpy(m->senha, senha);

    tam = strlen(email) + 1;
    m->email = malloc(tam*sizeof(char));
    strcpy(m->email, email);

    tam = strlen(cartao) + 1;
    m->cartao = malloc(tam*sizeof(char));
    strcpy(m->cartao, cartao);

    tData* data = CriaData(dia,mes,ano);
    m->nascimento = data;

    if(strcmp(assinatura,"USUARIO INFANTIL")==0)
    {
        m->restricao = INFANTIL;
        m->assinatura = PADRAO;
    }
    else if(strcmp(assinatura,"USUARIO PADRAO")==0)
    {
        m->restricao = ADULTO;
        m->assinatura = PADRAO;
    }
    else if(strcmp(assinatura,"USUARIO PREMIUM")==0)
    {
        m->restricao = ADULTO; 
        m->assinatura = PREMIUM;
    }

    m->corridas = malloc(sizeof(tCorrida*));

    m->minutosGastos = 0;
    m->numCorridas = 0;
    m->servicosConsumidos = 0;
    m->totalAvaliacoes = 0;

    return m;
}


tUsuario* LeUsuario(char* assinatura)
{
    char nome[MAX_NOME+1];
    char cpf[MAX_CPF+1];
    char telefone[MAX_TELEFONE+1];
    char endereco[MAX_ENDERECO+1];
    char user[MAX_NOME_USUARIO+1];
    char senha[MAX_SENHA+1];
    char email[MAX_EMAIL+1];
    char cartao[MAX_CARTAO+1];
    
    int dia,mes,ano;

   

      while(1) {

        char buffer[MAX_BUFFER + 1];
        scanf(" %[^\n]", buffer);
        getchar();

        if (strcmp(buffer, "OUT") == 0) {
            return NULL;
        }

        int qtdAtributos = sscanf(
            buffer,
            " %[^;]; %[^;]; %[^;]; %[^;]; %[^;]; %[^;]; %d/%d/%d; %[^;]; %[^;];",
            nome,
            cpf,
            telefone,
            endereco,
            user,
            senha,
            &dia,&mes,&ano,
            email,
            cartao
        );

        if (qtdAtributos < 11) {
            puts("ATRIBUTO(S) FALTANTE(S), FAVOR INICIAR O CADASTRO NOVAMENTE.");
            continue;
        }

        break;
    }

    tUsuario* u = CriaUsuario(nome,cpf,telefone,endereco,user,senha,dia,mes,ano,email,cartao,assinatura);

    return u;

}

void LiberaUsuario(tUsuario* user)
{
    free(user->cartao);
    free(user->cpf);
    free(user->email);
    free(user->endereco);
    free(user->nome);
    free(user->nomeUsuario);
    free(user->senha);
    free(user->telefone);
    
    LiberaData(user->nascimento);

    for(int i=0; i<user->numCorridas;i++)
        LiberaCorrida(user->corridas[i]);
    free(user->corridas);
    
    free(user);
}

char *getCpfUsuario(tUsuario* user)
{
    return user->cpf;
}

int ComparaCpfUsuario(char* cpf, tUsuario* user)
{
    if(strcmp(cpf,user->cpf)==0)
        return 1;

    return 0;
}