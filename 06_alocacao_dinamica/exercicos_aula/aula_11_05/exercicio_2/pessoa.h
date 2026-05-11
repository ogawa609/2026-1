#ifndef _PESSOA_H
#define _PESSOA_H

typedef struct
{
    char nome[150], CPF[11];
    int nascimentoDia, nascimentoMes, nascimentoAno;
}tPessoa;


tPessoa* criaPessoa();
void liberaPessoa(tPessoa *p);
void setNomePessoa(tPessoa *p);
void setDataNascimento(tPessoa *p);
void setCPF(tPessoa *p);
void printaPessoa(tPessoa *p);

char* getNome(tPessoa *p);
int getDiaNascimento(tPessoa *p);
int getMesNascimento(tPessoa *p);
int getAnoNascimento(tPessoa *p);
char* getCPF(tPessoa *p);

#endif