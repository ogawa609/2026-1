#include <stdio.h>
#include "tela.h"
#include "botao.h"

/*
Possiveis funcoes de Callback a serem armazenadas pelos ponteiros de funcao e executadas de acordo com eventos
realizados na tela
*/
void salvarDados(){
    printf("- Botao de SALVAR dados ativado!\n");
}

void excluirDados(){
    printf("- Botao de EXCLUIR dados ativado!\n");
}

void abrirMenuOpcoes(){
    printf("- Botao de OPCOES ativado!\n");
}

int main(){
    //criando tela full HD;
    Tela tela = criarTela(1920, 2080);

    //criando três tipos de botão: salvar, excluir e opções
    Botao salvar = criarBotao("SALVAR",1,"23F5",1,salvarDados);
    Botao excluir = criarBotao("EXCLUIR",2,"13E0",2,excluirDados);
    Botao menu = criarBotao("MENU OPCOES",3,"34C7",3,abrirMenuOpcoes);

    //registrando os três botões
    
    registraBotaoTela(&tela,salvar);
    registraBotaoTela(&tela,excluir);
    registraBotaoTela(&tela,menu);


    //desenhando a tela

    desenhaTela(&tela);

    //pega a opção escolhida pelo usuário
    ouvidorEventosTela(tela);

    

    return 0;
}
