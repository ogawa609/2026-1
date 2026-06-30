#ifndef _MOTORISTA_H
#define _MOTORISTA_H

#include "veiculo.h"
#include "carro.h"
#include "van.h"
#include "moto.h"


typedef struct Motorista tMotorista;

tMotorista* CriaMotorista(char* nome,char* cnpj,char* telefone, char* endereco, char* user, char* senha);
tMotorista* LeMotorista();
void liberaMotorista(void* dado);
char *getNomeMotorista(void*dado);
char *getTelefoneMotorista(void*dado);
char *getEnderecoMotorista(void*dado);
char *getNomeUsuarioMotorista(void*dado);
char *getSenhaMotorista(void*dado);

void AdicionaVeiculoEmMotorista(tMotorista* m, tVeiculo*v);
int ComparaCnpjMotorista(tMotorista* m, char* cnpj);
tVeiculo* BuscaVeiculoemMotorista(tMotorista* m, char* placa);
char* getCnpjMotorista(tMotorista* m);
tVeiculo* BuscaNomeVeiculoemMotorista(tMotorista* m, char* name, int i);
int getQtdVeiculosMotorista(tMotorista* m);
tVeiculo* getVeiculoMotorista(tMotorista* m, int i);
int ImprimeVeiculosMotorista(tMotorista* m, int indice,TipoAssinatura a, TipoUsuario i);
void OrdenarVeiculosPeloIdMotorista(tMotorista* m);


#endif

