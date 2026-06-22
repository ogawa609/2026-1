#ifndef _TAXUFES_H
#define _TAXUFES_H

#include "motorista.h"
#include "usuario.h"

typedef struct Gerenciador tGerenciador;
tGerenciador* CriaTaxUfes();
void CadastrarUsuario(tGerenciador*g, tUsuario* user);
void CadastrarMotorista(tGerenciador* g,tMotorista* driver);
void LiberaGerenciador(tGerenciador* g);
void LeCadastroAtor(tGerenciador* g);
void BuscaVeiculosGerenciador(tGerenciador* g);

tMotorista* BuscaMotoristaGerenciador(tGerenciador* g, char* cnpj);

#endif