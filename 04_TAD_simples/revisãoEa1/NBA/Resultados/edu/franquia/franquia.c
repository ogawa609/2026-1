#include <stdio.h>
#include <string.h>
#include "franquia.h"


/*
Função que cria os dados de uma franquia e retorna o tFranquia. 
@param char *nomeFranquia: String com o nome da franquia criada
@param char *nomeConferencia: String com o nome da conferência criada

@return tFranquia: Retorna uma variável do tipo tFranquia criada
*/
tFranquia lerFranquia(char *nomeFranquia, char *nomeConferencia)
{
    tFranquia f;
    strcpy(f.conferencia,nomeConferencia);
    strcpy(f.nome,nomeFranquia);
    f.derrotaCasa = f.derrotaFora = f.nPartidasJogadas = f.vitoriaCasa = f.vitoriaFora =0;

    return f;
}                                                                               

/*
Função que imprime todos os dados de uma franquia (diferente dos casos de teste).

@param tFranquia f: Tipo tFranquia a ser impresso
*/
void imprimeFranquia(tFranquia f)
{
    printf("%s\n",f.nome);
    printf("%s\n",f.conferencia);
    printf("%d\n",f.nPartidasJogadas);

}

/*
Função que atualiza os dados de franquia a partir de dados de uma partida jogada. 
Deve-se obter os dados da partida, percorrer todos os times das franquias passadas e verificar 
quais jogadores ganharam, perderam, quais foram suas pontuações e se a vitória foi em casa ou 
fora dela. Por fim, os times relacionados na partida devem ter seus dados atualizados

@param tFranquia *franquias: Vetor de tFranquias
@param int qtdFranquias: Inteiro com o tamanho de franquias cadastradas
@param tPartida p: Nova partida a ser utilizada para atualizar dados de times das franquias
*/
void insereDadosPartida(tFranquia *franquias, int qtdFranquias, tPartida p)
{
    char nomeFora[MAX_TIME_NOME], nomeCasa[MAX_TIME_NOME];
    int pontosFora, pontosCasa;
    obtemDadosPartida(p,nomeFora,nomeCasa,&pontosFora,&pontosCasa);

    for(int i=0;i<qtdFranquias;i++)
    {
        if(strcmp(franquias[i].nome,nomeCasa)==0)
        {
            if(pontosCasa>pontosFora)
                franquias[i].vitoriaCasa++;
            else
                franquias[i].derrotaCasa++;
        }
        else if(strcmp(franquias[i].nome,nomeFora)==0)
        {
            if(pontosCasa<pontosFora)
                franquias[i].vitoriaFora++;
            else
                franquias[i].derrotaFora++;
        }
    }
}

/*
Função que imprime os dados de das franquias de acordo com os casos de teste de saída.

@param tFranquia *franquias: Vetor do tipo tFranquia a ser impresso
@param int qtdFranquias: Inteiro com o tamanho do vetor de franquias

BUCKS [CL] 2 1 66.67 1 1
*/
void ImprimeDadosFranquia(tFranquia *franquias, int qtdFranquias)
{
    for(int i=0;i<qtdFranquias;i++)
    {
        printf("%s ",franquias[i].nome);

        if(strcmp(franquias[i].conferencia,"OESTE")==0)
            printf("[CO] ");
        else if(strcmp(franquias[i].conferencia,"LESTE")==0) 
            printf("[CL] ");
        
        int vitorias = franquias[i].vitoriaCasa+franquias[i].vitoriaFora;
        
        float aprov;
        if((franquias[i].vitoriaFora+franquias[i].vitoriaCasa+franquias[i].derrotaFora+franquias[i].derrotaCasa)>0)
             aprov = (vitorias*100.0)/(franquias[i].vitoriaFora+franquias[i].vitoriaCasa+franquias[i].derrotaFora+franquias[i].derrotaCasa);
        else
            aprov=0;
        
        printf("%d %d %.2f %d %d\n",franquias[i].vitoriaCasa+franquias[i].vitoriaFora,franquias[i].derrotaCasa+franquias[i].derrotaFora,aprov,franquias[i].vitoriaFora,franquias[i].vitoriaCasa);
    }
}

/*
Função que imprime os dados de uma conferência de acordo com os casos de teste de saída.
Deve-se calcular os valores de vitórias e derrotas dentro e fora de casa para cada franquia 
de cada conferência (LESTE e OESTE), imprimindo as estatísticas ao final da chamada da função.

@param tFranquia *franquias: Vetor do tipo tFranquia a ser impresso
@param int qtdFranquias: Inteiro com o tamanho do vetor de franquias
*/
void ImprimeDadosConferencia(tFranquia *franquias, int qtdFranquias)
{
     int vitoriasL,derrotasL,vitoriasO,derrotasO;
     vitoriasL = vitoriasO = derrotasL = derrotasO = 0;

     for(int i=0;i<qtdFranquias;i++)
     {
        if(strcmp(franquias[i].conferencia,"LESTE")==0)
        {
            vitoriasL += franquias[i].vitoriaCasa + franquias[i].vitoriaFora;
            derrotasL += franquias[i].derrotaCasa + franquias[i].derrotaFora;
        }
        else if(strcmp(franquias[i].conferencia,"OESTE")==0)
        {
             vitoriasO += franquias[i].vitoriaCasa + franquias[i].vitoriaFora;
             derrotasO += franquias[i].derrotaCasa + franquias[i].derrotaFora;
        }
     }

     float franqL;
     if(vitoriasL+derrotasL==0)
        franqL=0;
     else
        franqL = (vitoriasL*100.0)/(vitoriasL+derrotasL);

    float franqO;
     if(vitoriasO+derrotasO==0)
        franqO=0;
     else
        franqO = (vitoriasO*100.0)/(vitoriasO+derrotasO);


    printf("LESTE %d %d %.2f\n",vitoriasL,derrotasL,franqL);
    printf("OESTE %d %d %.2f",vitoriasO,derrotasO,franqO);
}