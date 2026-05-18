#include "tela.h"
#include <stdio.h>


void salvarDados(){
    printf("- Botao de SALVAR dados ativado!\n");
}

void excluirDados(){
    printf("- Botao de EXCLUIR dados ativado!\n");
}

void abrirMenuOpcoes(){
    printf("- Botao de OPCOES ativado!\n");
}


int main()
{
    Tela tela = CriarTela(200,400);

    Botao salvar = CriarBotao("Salvar",12,"FFF",1,salvarDados);
    Botao excluir = CriarBotao("Excluir",18,"000",1,excluirDados);
    Botao opcoes = CriarBotao("Opcoes",10,"FF0000",2,abrirMenuOpcoes);

    RegistraBotaoTela(&tela,salvar);
    RegistraBotaoTela(&tela,excluir);
    RegistraBotaoTela(&tela,opcoes);

    DesenhaTela(tela);
    OuvidorEventosTela(tela);

    return 0;

}