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
   char linha[1000];

   while(1)
   {
        scanf(" %[^\n]",linha);
        int contador = 0;

        for(int i=0;linha[i]!='\0';i++)
        {
            if(linha[i]==';')
                contador++;
        }

        if(contador<6)
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
    strcpy(cnpj,str);

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

tVeiculo* BuscaNomeVeiculoemMotorista(tMotorista* m, char* name,int i)
{
    char* nome = getNomeVeiculo(m->veiculos[i]);

    if(strstr(nome,name)!=NULL)
        return m->veiculos[i];

    return NULL;
}

char* getCnpjMotorista(tMotorista* m)
{
    return m->cnpj;
}

int getQtdVeiculosMotorista(tMotorista* m)
{
    return m->qntVeiculos;
}
tVeiculo* getVeiculoMotorista(tMotorista* m, int i)
{
    return m->veiculos[i];
}

int ImprimeVeiculosMotorista(tMotorista* m, int indice,TipoAssinatura a, TipoUsuario id)
{
    for(int i=0;i<m->qntVeiculos;i++)
    {

        TipoAssinatura av = getRestricaoAssinaturaVeiculo(m->veiculos[i]);
        TipoUsuario iv = getRestricaoIdadeVeiculo(m->veiculos[i]);

        if(((id==INFANTIL&&iv==INFANTIL)||(id==ADULTO))&&((a==PREMIUM)||(a==PADRAO&&av==PADRAO)))
        {
            printf("%d - ",indice);
            
            char tip = getTipoVeiculoLetra(m->veiculos[i]);
                        if(tip=='C')
                            printf("CARRO #%s; %s; ",getCodVeiculo(m->veiculos[i]),getNomeVeiculo(m->veiculos[i]));
                        else if(tip=='M')
                            printf("MOTO #%s; %s; ",getCodVeiculo(m->veiculos[i]),getNomeVeiculo(m->veiculos[i]));
                        else if(tip=='V')
                            printf("VAN #%s; %s; ",getCodVeiculo(m->veiculos[i]),getNomeVeiculo(m->veiculos[i]));

            printf("%d; ",getAssentosVeiculo(m->veiculos[i]));
            imprimeFloatBr2(getKmVeiculo(m->veiculos[i]));
            printf("; %d; %s; %s (%s); %.2f\n",getAnoVeiculo(m->veiculos[i]),
            getMarcaVeiculo(m->veiculos[i]),m->cnpj,m->nome,getNotaMediaVeiculo(m->veiculos[i]));

            indice++;
        }
    }

    return indice;
}

void OrdenarVeiculosPeloIdMotorista(tMotorista* m)
{
    for(int i=0;i<m->qntVeiculos;i++)
    {
        for(int j=i+1;j<m->qntVeiculos;j++)
        {
            char* id1 = getCodVeiculo(m->veiculos[i]);
            char* id2 = getCodVeiculo(m->veiculos[j]);

            if(strcmp(id1,id2)>0)
            {
                tVeiculo* temp = m->veiculos[i];
                m->veiculos[i] = m->veiculos[j];
                m->veiculos[j] = temp;
            }
        }

        
    }
}


