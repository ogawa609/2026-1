#include <stdio.h>
#include <stdlib.h>
#include "cpu.h"


struct cpu 
{
    int* registradores;
   
    

};

/**
 * @brief Cria e inicializa uma CPU.
 * 
 * A CPU criada deve possuir 8 registradores, que posteriormente
 * serão inicializados com valores lidos do arquivo binário.
 * 
 * @return Ponteiro para a CPU criada e alocada dinamicamente.
 */
Cpu *criaCpu()
{
    Cpu* c = calloc(1,sizeof(Cpu));
    c->registradores = malloc(8*sizeof(int));
    for(int i=0;i<8;i++)
    {
        int v;
        scanf("%d",&v);
        c->registradores[i] = v;
    }

    return c;
        
}

/**
 * @brief Lê e executa um conjunto de instruções a partir de um arquivo binário.
 * 
 * Essa função lê as instruções armazenadas no arquivo e as executa
 * sequencialmente na CPU.
 * 
 * @param c CPU que executará as instruções.
 * @param f Arquivo binário de onde as instruções serão lidas.
 * @param nInstrucoes Quantidade de instruções a serem executadas.
 */
void realizaInstrucao(Cpu *c, FILE *f, int nInstrucoes)
{
    for(int i=0;i<nInstrucoes;i++)
    {
       Instrucao* in = leInstrucaoArquivo(f);
       executaInstrucao(c,in);
       free(in);
      
    }
}

/**
 * @brief Executa uma única instrução na CPU.
 * 
 * A instrução é interpretada e aplicada sobre os registradores da CPU,
 * substituindo o valor do registrador de destino pelo resultado da operação.
 * 
 * @param c CPU que executará a instrução.
 * @param i Instrução a ser executada.
 */
void executaInstrucao(Cpu *c, Instrucao *i)
{
    char op = getOpcode(i);
    int rd = getIndiceRegDestino(i);
    int r1 = getIndiceReg1(i);
    int r2 = getIndiceReg2(i);

    if(op=='A')
    {
        c->registradores[rd] = c->registradores[r1] + c->registradores[r2];
    }
    else if(op=='S')
    {
        c->registradores[rd] = c->registradores[r1] - c->registradores[r2];
    }

    else if(op=='M')
    {
        c->registradores[rd] = c->registradores[r1] * c->registradores[r2];
    }

    else if(op=='D')
    {
        c->registradores[rd] = c->registradores[r1] / c->registradores[r2];
    }
}

/**
 * @brief Imprime o conteúdo dos 8 registradores da CPU.
 * 
 * Os registradores são impressos em ordem, do registrador 0 ao 7.
 * 
 * @param c CPU cujos registradores serão impressos.
 */
void imprimeRegistradores(Cpu *c)
{
    for(int i=0;i<8;i++)
    {
        printf("%d ",c->registradores[i]);
    }
}

/**
 * @brief Libera toda a memória associada à CPU.
 * 
 * @param c CPU a ser liberada.
 */
void liberaCpu(Cpu *c)
{
    free(c->registradores);
    free(c);
}
