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
void CadastrarVeiculo(tGerenciador* g);
void BuscaVeiculosGerenciador(tGerenciador* g, char* comando);
void RelatorioListaCorridasUsuario(tGerenciador* g);
void RealizacaoSelecaoCorridaUsuario(tGerenciador* g);
void ImprimirListaCorridasUsuario(tGerenciador* g,tUsuario* user); //
void RemoveCorridasLista(tGerenciador* g);
void RealizarCorridaeAvaliar(tGerenciador* g);
void GerarRelatorioUsuario(tGerenciador* g);
void GerarRelatorioVeiculos(tGerenciador* g);
void GerarRelatorioAvaliacao(tGerenciador* g);



#endif