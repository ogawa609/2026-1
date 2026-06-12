#include <stdio.h>
#include <stdlib.h>
#include "tela.h"
#include "botao.h"


int main()
{
    Tela* tela = criarTela(600,800);

    Botao* salvar = criarBotao("SALVAR",18,"00FF00");
    Botao* excluir = criarBotao("EXCLUIR",14,"FF0000");
    Botao* enviar = criarBotao("ENVIAR",18,"0000FF");

    registraElementoTela(tela,salvar,exibeBotao,executaClickBotao,desalocaBotao);
    registraElementoTela(tela,excluir,exibeBotao,executaClickBotao,desalocaBotao);
    registraElementoTela(tela,enviar,exibeBotao,executaClickBotao,desalocaBotao);

    desenhaTela(tela);
    ouvidorClickTela(tela);
    desalocaTela(tela);

    return 0;

}