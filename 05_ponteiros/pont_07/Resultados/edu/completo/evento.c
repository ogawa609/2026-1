#include <stdio.h>
#include <string.h>
#include "evento.h"

/**
 * Cadastra um novo evento no calendário e o insere na próxima posição do array.
 *
 * @param eventos Array de eventos onde o novo evento será cadastrado.
 * @param numEventos Ponteiro para o número atual de eventos cadastrados.
 */
void cadastrarEvento(Evento* eventos, int* numEventos)
{
    char nome[50];
    int dia,mes,ano;
    int num = *numEventos;

    

        scanf(" %[^\n]\n",nome);
        scanf("%d %d %d\n",&dia,&mes,&ano);

        strcpy(eventos[num].nome,nome);
        eventos[num].ano = ano;
        eventos[num].dia = dia;
        eventos[num].mes = mes;

        *numEventos++;
    
    
}

/**
 * Exibe todos os eventos cadastrados no calendário.
 *
 * @param eventos Array de eventos a serem exibidos.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void exibirEventos(Evento* eventos, int* numEventos)
{
    int num = *numEventos;

    for(int i = 0;i<num;i++)
    {
        printf("%d - %s - %02d/%02d/%d",eventos[i].nome,eventos[i].dia,eventos[i].mes,eventos[i].ano);
    }
}

/**
 * Troca a data de um evento específico no calendário.
 *
 * @param eventos Array de eventos onde o evento será modificado.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarDataEvento(Evento* eventos, int* numEventos)
{
    int dia,mes,ano;
    int indice;
    scanf("%d\n",&indice);

    if(indice<0||indice>=*numEventos)
    {
        printf("Indice invalido!\n");
        return;
    }
        

    scanf("%d %d %d\n",&dia,&mes,&ano);

    eventos[indice].ano = ano;
    eventos[indice].mes = mes;
    eventos[indice].dia = dia;
}

/**
 * Troca a posição de dois eventos, a partir do índice, dentro do array de eventos.
 *
 * @param eventos Array de eventos onde a troca será realizada.
 * @param indiceA Ponteiro para o primeiro índice.
 * @param indiceB Ponteiro para o segundo índice.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos)
{
    Evento temp = eventos[*indiceA];
    eventos[*indiceA] = eventos[*indiceB];
    eventos[*indiceB] = temp;

}
