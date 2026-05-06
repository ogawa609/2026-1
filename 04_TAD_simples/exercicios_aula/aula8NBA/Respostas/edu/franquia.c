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
    strcpy(f.nome,nomeFranquia);
    strcpy(f.conferencia,nomeConferencia);
    f.derrotaCasa=f.derrotaFora=f.nPartidasJogadas=f.vitoriaCasa=f.vitoriaFora=0;

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
    printf("%d\n",f.vitoriaCasa);
    printf("%d\n",f.vitoriaFora);
    printf("%d\n",f.derrotaCasa);
    printf("%d\n",f.derrotaFora);
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
    char nomeTimeFora[MAX_TIME_NOME];
    char nomeTimeCasa[MAX_TIME_NOME];
    int pontosFora,pontoCasa;

    obtemDadosPartida(p,nomeTimeFora,nomeTimeCasa,&pontosFora,&pontoCasa);

    for(int i=0;i<qtdFranquias;i++)
    {

        if(strcmp(p.nomeTimeCasa,franquias[i].nome)==0)
        {
            if(pontoCasa<pontosFora)
            {
                franquias[i].derrotaCasa++;
                franquias[i].nPartidasJogadas++;
            }
            else{

                franquias[i].vitoriaCasa++;
                franquias[i].nPartidasJogadas++;
            }
        }
        else if(strcmp(p.nomeTimeFora,franquias[i].nome)==0)
        {
            if(pontosFora<pontoCasa)
            {
                franquias[i].derrotaFora++;
                franquias[i].nPartidasJogadas++;

            }
            

            else 
            {
                franquias[i].vitoriaFora++;
                franquias[i].nPartidasJogadas++;
            }
        }

        
    }

}

/*
Função que imprime os dados de das franquias de acordo com os casos de teste de saída.

@param tFranquia *franquias: Vetor do tipo tFranquia a ser impresso
@param int qtdFranquias: Inteiro com o tamanho do vetor de franquias
*/
void ImprimeDadosFranquia(tFranquia *franquias, int qtdFranquias)
{
    for(int i=0;i<qtdFranquias;i++)
    {
        char conf[3];

        if(strcmp(franquias[i].conferencia,"OESTE")==0)
            strcpy(conf,"CO");
        else
            strcpy(conf,"CL");

        if(franquias[i].derrotaCasa+franquias[i].derrotaFora+franquias[i].vitoriaCasa+franquias[i].vitoriaFora>0)
        {
            int vit=franquias[i].vitoriaCasa+franquias[i].vitoriaFora;
            int der=franquias[i].derrotaCasa+franquias[i].derrotaFora;
            printf("%s [%s] %d %d %.2f %d %d\n",franquias[i].nome,conf,franquias[i].vitoriaCasa+franquias[i].vitoriaFora,franquias[i].derrotaCasa+franquias[i].derrotaFora,(100.0*vit)/(der+vit),franquias[i].vitoriaFora,franquias[i].vitoriaCasa );
        }
        else
            printf("%s [%s] %d %d %.2f %d %d\n",franquias[i].nome,conf,franquias[i].vitoriaCasa+franquias[i].vitoriaFora,franquias[i].derrotaCasa+franquias[i].derrotaFora,0.00,franquias[i].vitoriaFora,franquias[i].vitoriaCasa );

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

    int vitO,vitL,derO,derL;
    vitL=vitO=derL=derO=0;

    float apro=0,aprL=0;

    for(int i=0;i<qtdFranquias;i++)
    {
        if(strcmp(franquias[i].conferencia,"OESTE")==0)
        {
            vitO+= (franquias[i].vitoriaCasa+franquias[i].vitoriaFora);
            derO+= (franquias[i].derrotaCasa+franquias[i].derrotaFora);
        }
        else
        {
             vitL+= (franquias[i].vitoriaCasa+franquias[i].vitoriaFora);
            derL+= (franquias[i].derrotaCasa+franquias[i].derrotaFora);
        }
    }

    
    if(vitL+derL>0)
        printf("LESTE %d %d %.2f\n",vitL,derL,((100.0*vitL)/(vitL+derL)));
    else
        printf("LESTE %d %d %.2f\n",vitL,derL,0.00);

     if(vitO+derO>0)
        printf("OESTE %d %d %.2f",vitO,derO,((100.0*vitO)/(vitO+derO)));
    else
        printf("OESTE %d %d %.2f",vitO,derO,0.00);
}