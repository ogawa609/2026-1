#include <stdio.h>
#include <stdlib.h>
#include "gerenciador.h"


int main()
{
    tGerenciador* gerenciador = criaGerenciador();

    preencheBancoPacientesGerenciador(gerenciador);
    imprimeRelatorioGerenciador(gerenciador);
    liberaGerenciador(gerenciador);
}