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

    tCorrida** corridasRealizadas;
    int numCorridasRealizadas;

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
    m->corridasRealizadas = malloc(sizeof(tCorrida*));

    m->minutosGastos = 0;
    m->numCorridas = 0;
    m->servicosConsumidos = 0;
    m->totalAvaliacoes = 0;
    m->numCorridasRealizadas = 0;

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
    char responsavel[MAX_CPF+1];
    
    int dia,mes,ano;             
    char linha[1000];

   while(1)
   {
        scanf(" %[^\n]",linha);
        
        if(strcmp(linha,"OUT")==0)
            return NULL;

        int contador = 0;

        for(int i=0;linha[i]!='\0';i++)
        {
            if(linha[i]==';')
                contador++;
        }

        if(contador<9)
        {
            printf("ATRIBUTO(S) FALTANTE(S)! FAVOR INICIAR O CADASTRO NOVAMENTE.\n");
            continue;
        }

        break;
   }

   char* str;

   str = strtok(linha, ";");
    while (*str == ' '||*str=='#') 
        str++;
    
    strcpy(nome,str);

    str = strtok(NULL, ";");
    while (*str == ' '||*str=='#') 
        str++;
    
    strcpy(cpf,str);

    str = strtok(NULL, ";");
    while (*str == ' '||*str=='#') 
        str++;
    
    strcpy(telefone,str);

    str = strtok(NULL, ";");
    while (*str == ' '||*str=='#') 
        str++;
    
    strcpy(endereco,str);

    str = strtok(NULL, ";");
    while (*str == ' '||*str=='#') 
        str++;
    
    strcpy(user,str);

    str = strtok(NULL, ";");
    while (*str == ' '||*str=='#') 
        str++;
    
    strcpy(senha,str);

    str = strtok(NULL, "/");
    while (*str == ' '||*str=='#') 
        str++;
    dia = atoi(str);

    str = strtok(NULL, "/");
    while (*str == ' ') 
        str++;
    mes = atoi(str);

    str = strtok(NULL, ";");
    while (*str == ' '||*str=='#') 
        str++;
    ano = atoi(str);

    str = strtok(NULL, ";");
    while (*str == ' '||*str=='#') 
        str++;
    
    strcpy(email,str);

    if(strcmp(assinatura,"USUARIO INFANTIL")==0)
    {
        str = strtok(NULL, ";");
        while (*str == ' '||*str=='#') 
            str++;
        
        strcpy(responsavel,str);
    }
    else
    {
        str = strtok(NULL, ";");
        while (*str == ' '||*str=='#') 
            str++;
        
        strcpy(cartao,str);
    }



      

    tUsuario* u = NULL;

    if(strcmp(assinatura,"USUARIO INFANTIL")==0)
        u = CriaUsuario(nome,cpf,telefone,endereco,user,senha,dia,mes,ano,email,responsavel,assinatura);
    else
        u = CriaUsuario(nome,cpf,telefone,endereco,user,senha,dia,mes,ano,email,cartao,assinatura);

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

    for(int i=0;i<user->numCorridasRealizadas;i++)
        LiberaCorrida(user->corridasRealizadas[i]);
    free(user->corridasRealizadas);
    
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

TipoUsuario getRestricaoIdadeUsuario(tUsuario* user)
{
    return user->restricao;
}

char* getCartaoUsuario(tUsuario* user)
{
    return user->cartao;
}

TipoAssinatura getRestricaoAssinaturaUsuario(tUsuario* user)
{
    return user->assinatura;
}

int UsuarioPodeUsarVeiculo(TipoUsuario usuario,
                           TipoUsuario restricaoVeiculo)
{
    if(restricaoVeiculo == INFANTIL)
        return 1;

    if(restricaoVeiculo == ADULTO &&
       usuario == ADULTO)
        return 1;

    return 0;
}

int getQtdCorridasUsuario(tUsuario* user)
{
    return user->numCorridas;
}

tCorrida* getCorridaUsuario(tUsuario* user, int i)
{
    return user->corridas[i];
}

void AdicionaCorridaUsuario(tUsuario* user,tCorrida* run)
{
    user->corridas[user->numCorridas] = run;

    user->numCorridas++;
    user->corridas = realloc(user->corridas,(user->numCorridas+1) * sizeof(tCorrida*));
}

int VerificaVeiculoExisteCorridaUsuario(tUsuario* user, char* placa)
{
    for(int i=0;i<user->numCorridas;i++)
    {
         tVeiculo* temp = getVeiculoCorrida(user->corridas[i]);
         char* cod = getCodVeiculo(temp);
         
         if(strcmp(cod,placa) == 0)
            return 1;
    }

    return 0;
}

void RemoveCorridaUsuario(tUsuario* user, char* placa, int modo)
{
    int indice = -1;
    

    for(int i=0;i<user->numCorridas;i++)
    {
        tVeiculo* temp = getVeiculoCorrida(user->corridas[i]);
        char* cod = getCodVeiculo(temp);

        if(strcmp(cod,placa)==0)
        {
            indice = i;
            break;
        }
    }

    if(indice == -1)
        return;

    tCorrida* removido = user->corridas[indice];

    for(int i = indice; i < user->numCorridas - 1; i++)
    {
        user->corridas[i] = user->corridas[i + 1];
    }

    user->numCorridas--;

    user->corridas[user->numCorridas] = NULL;

    if(modo==1)
    {
        AdicionaCorridaHistoricoUsuario(user,removido);
    }
    else
    {
        LiberaCorrida(removido);
    }

}

void IncrementarServicosUsuario(tUsuario* user)
{
    user->servicosConsumidos++;
}
void IncrementarMinutosGastosUsuario(tUsuario* user, int minutos)
{
    user->minutosGastos += minutos;
}
void IncrementarNumeroAvaliacoesUsuario(tUsuario* user)
{
    user->totalAvaliacoes++;
}

char* getSenhaUsuario(tUsuario* user)
{
    return user->senha;
}
char* getNomeUsuario(tUsuario* user)
{
    return user->nome;
}
char* getTelefoneUsuario(tUsuario* user)
{
    return user->telefone;
}

char* getEnderecoUsuario(tUsuario* user)
{
    return user->endereco;
}

char* getUserUsuario(tUsuario* user)
{
    return user->nomeUsuario;
}
char* getEmailUsuario(tUsuario* user)
{
    return user->email;
}
tData* getNascimentoUsuario(tUsuario* user)
{
    return user->nascimento;
}
int getCorridasRealizadasUsuario(tUsuario* user)
{
    return user->servicosConsumidos;
}
int getMinutosTotaisUsuario(tUsuario* user)
{
    return user->minutosGastos;
}
int getNumAvaliacoesFeitasUsuario(tUsuario* user)
{
    return user->totalAvaliacoes;
}

void AdicionaCorridaHistoricoUsuario(tUsuario* user, tCorrida* realizada)
{
    user->corridasRealizadas[user->numCorridasRealizadas] = realizada;

    user->numCorridasRealizadas++;

    user->corridasRealizadas = realloc(user->corridasRealizadas,(user->numCorridasRealizadas+1)*sizeof(tCorrida*));
}

void ImprimeCorridasRealizadasUsuario(tUsuario* user)
{
    if(user->numCorridasRealizadas==0)
    {
        printf("LISTA DE CORRIDAS VAZIA!\n");
        return;
    }

    printf("LISTA DE CORRIDA:\n");

    int tempo = 0;
    for(int i = 0;i<user->numCorridasRealizadas;i++)
    {
        ImprimeCorrida(user->corridasRealizadas[i],i+1);
        tempo += getTempoCorrida(user->corridasRealizadas[i]);
        
    }

    printf("(TOTAL ");
    imprimeDuracaoCorrida(tempo);
    printf(" horas)\n");
}