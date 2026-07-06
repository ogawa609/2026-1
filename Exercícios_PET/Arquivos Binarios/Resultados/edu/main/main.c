#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"
#include "cpu.h"
#include "instrucao.h"


int main()
{
    Cpu* cpu = criaCpu();

    int qtd;
    scanf("%d\n",&qtd);

    Usuario* user = criaUsuario(qtd);
    FILE* f = fopen("mem.bin","wb");
    adicionaInstrucao(user,f);
    fclose(f);

    FILE* f2 = fopen("mem.bin","rb");
    realizaInstrucao(cpu,f2,qtd);
    imprimeRegistradores(cpu);
    fclose(f2);

    liberaCpu(cpu);
    liberaUsuario(user);

    return 0;
}