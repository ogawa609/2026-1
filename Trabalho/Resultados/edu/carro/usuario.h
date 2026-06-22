#ifndef _USUARIO_H
#define _USUARIO_H

typedef struct Usuario tUsuario;

tUsuario* CriaUsuario(char*nome,char*cpf,char*tel,char*ender,char*user,
char*senha,int dia,int mes, int ano,char* email,char* cartao, char* assinatura);
tUsuario* LeUsuario(char* assinatura);
void LiberaUsuario(tUsuario* user);
char *getCpfUsuario(tUsuario* user);
int ComparaCpfUsuario(char* cpf, tUsuario* user);

#endif