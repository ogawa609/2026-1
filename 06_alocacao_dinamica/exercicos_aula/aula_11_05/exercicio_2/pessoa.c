#include <stdlib.h>
#include "pessoa.h"
#include <stdio.h>

tPessoa* criaPessoa()
{
    tPessoa *p = (tPessoa*) malloc (sizeof(tPessoa));
    setNomePessoa(p);
    setDataNascimento(p);
    setCPF(p);
    return p;
}

void liberaPessoa(tPessoa *p)
{
    if(p != NULL)
        free(p);
}

void setNomePessoa(tPessoa *p)
{
    scanf("%[^\n]\n", p->nome);
}

void setDataNascimento(tPessoa *p)
{
    scanf("%d/%d/%d\n", &p->nascimentoDia, &p->nascimentoMes, &p->nascimentoAno);
}

void setCPF(tPessoa *p)
{
    scanf("%s\n", p->CPF);
}

void printaPessoa(tPessoa *p)
{
    printf(" Nome: %s\n Nascimento: %d/%d/%d\n CPF: %s\n", p->nome, p->nascimentoDia, p->nascimentoMes, p->nascimentoAno, p->CPF);    
}

char* getNome(tPessoa *p)
{
    return(p->nome);
}

int getDiaNascimento(tPessoa *p)
{
    return(p->nascimentoDia);
}

int getMesNascimento(tPessoa *p)
{
    return(p->nascimentoMes);
}

int getAnoNascimento(tPessoa *p)
{
    return(p->nascimentoAno);
}

char* getCPF(tPessoa *p)
{
    return(p->CPF);
}