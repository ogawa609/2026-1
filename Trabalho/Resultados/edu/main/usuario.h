#ifndef _USUARIO_H
#define _USUARIO_H

#include "corrida.h"
typedef struct Usuario tUsuario;


tUsuario* CriaUsuario(char*nome,char*cpf,char*tel,char*ender,char*user,
char*senha,int dia,int mes, int ano,char* email,char* cartao, char* assinatura);
tUsuario* LeUsuario(char* assinatura);
void LiberaUsuario(tUsuario* user);
char *getCpfUsuario(tUsuario* user);
int ComparaCpfUsuario(char* cpf, tUsuario* user);
TipoUsuario getRestricaoIdadeUsuario(tUsuario* user);
char* getCartaoUsuario(tUsuario* user);
TipoAssinatura getRestricaoAssinaturaUsuario(tUsuario* user);
int UsuarioPodeUsarVeiculo(TipoUsuario usuario, TipoUsuario restricaoVeiculo);
int getQtdCorridasUsuario(tUsuario* user);
tCorrida* getCorridaUsuario(tUsuario* user, int i);
void AdicionaCorridaUsuario(tUsuario* user,tCorrida* run);
int VerificaVeiculoExisteCorridaUsuario(tUsuario* user, char* placa);
void RemoveCorridaUsuario(tUsuario* user, char* placa, int modo);
void IncrementarServicosUsuario(tUsuario* user);
void IncrementarMinutosGastosUsuario(tUsuario* user, int minutos);
void IncrementarNumeroAvaliacoesUsuario(tUsuario* user);
char* getSenhaUsuario(tUsuario* user);
char* getNomeUsuario(tUsuario* user);
char* getTelefoneUsuario(tUsuario* user);
char* getEnderecoUsuario(tUsuario* user);
char* getUserUsuario(tUsuario* user);
char* getEmailUsuario(tUsuario* user);
tData* getNascimentoUsuario(tUsuario* user);
int getCorridasRealizadasUsuario(tUsuario* user);
int getMinutosTotaisUsuario(tUsuario* user);
int getNumAvaliacoesFeitasUsuario(tUsuario* user);
void ImprimeCorridasRealizadasUsuario(tUsuario* user);
void AdicionaCorridaHistoricoUsuario(tUsuario* user, tCorrida* realizada);
#endif