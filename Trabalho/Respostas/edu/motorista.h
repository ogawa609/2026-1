#ifndef _MOTORISTA_H
#define _MOTORISTA_H

typedef struct Motorista tMotorista;

tMotorista* CriaMotorista(char* linha);
void liberaMotorista(void* dado);
char *getNomeMotorista(void*dado);
char *getTelefoneMotorista(void*dado);
char *getEnderecoMotorista(void*dado);
char *getNomeUsuarioMotorista(void*dado);
char *getSenhaMotorista(void*dado);

void AdicionaVeiculoEmMotorista(tMotorista* m, tVeiculo*v);
#endif

/*
 char* nome;
    char* cnpj;
    char* telefone;
    char* endereco;
    char* nomeUsuario;
    char* senha;

    int qntVeiculos;
    tVeiculo** veiculos;*/