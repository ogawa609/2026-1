#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eleicao.h"


/**
 * @brief Inicializa uma eleição com valores padrão (zerando as variáveis que armazenam votos).
 * Ainda nessa função, é lido a quantidade de candidatos e os candidatos são lidos e armazenados
 * A memória necessária para os vetores "presidentes", "governadores" deve ser alocada aqui.
 * Demais ponteiros devem ser inicializado com NULL.
 * @return Eleição inicializada.
 */
tEleicao* InicializaEleicao()
{
    tEleicao* e = (tEleicao*) malloc(sizeof(tEleicao));

    e->eleitores = NULL;
    e->governadores = (tCandidato**) malloc(sizeof(tCandidato*));
    e->presidentes = (tCandidato**) malloc(sizeof(tCandidato*));;
    e->totalEleitores = 0;
    e->totalGovernadores = 0;
    e->totalPresidentes = 0;
    e->votosBrancosGovernador = 0;
    e->votosBrancosPresidente = 0;
    e->votosNulosGovernador = 0;
    e->votosNulosPresidente = 0;

    int qntCandidatos;
    scanf("%d",&qntCandidatos);

    for(int i = 0;i<qntCandidatos;i++)
    {
        tCandidato* temp = CriaCandidato();
        LeCandidato(temp);

        if(ObtemCargo(temp)=='P')
        {
            e->presidentes[e->totalPresidentes] = temp;
            e->totalPresidentes++;
            e->presidentes = realloc(e->presidentes,(e->totalPresidentes+1)*sizeof(tCandidato*));
        }
        else if(ObtemCargo(temp)=='G')
        {
            e->governadores[e->totalGovernadores] = temp;
            e->totalGovernadores++;
            e->governadores = realloc(e->governadores,(e->totalGovernadores+1)*sizeof(tCandidato*));
        }
        else
            ApagaCandidato(temp);

        
    }

    return e;

}


void ApagaEleicao(tEleicao* eleicao)
{
    for(int i=0;i<eleicao->totalGovernadores;i++)
        ApagaCandidato(eleicao->governadores[i]);

    for(int i=0;i<eleicao->totalPresidentes;i++)
        ApagaCandidato(eleicao->presidentes[i]);

    for(int i=0;i<eleicao->totalEleitores;i++)
        ApagaEleitor(eleicao->eleitores[i]);
    
    free(eleicao->eleitores);
    free(eleicao->governadores);
    free(eleicao->presidentes);

    free(eleicao);
    
}

/**
 * @brief Realiza uma eleição.
 * Nessa função, é lido a quantidade de eleitores e os eleitores são lidos e armazenados.
 * @param eleicao Eleição a ser realizada. 
 */
void RealizaEleicao(tEleicao* eleicao)
{
    int qntEeitores;
    scanf("%d",&qntEeitores);
    eleicao->totalEleitores = qntEeitores;

    eleicao->eleitores = (tEleitor**) malloc(qntEeitores*sizeof(tEleitor*));

    for(int i = 0;i<qntEeitores;i++)
    {
        eleicao->eleitores[i] = CriaEleitor();
        LeEleitor(eleicao->eleitores[i]);
    }

}

/**
 * @brief Imprime o resultado da eleição na tela a partir da aparucao dos votos.
 * @param eleicao Eleição a ser impressa.
 */
void ImprimeResultadoEleicao(tEleicao* eleicao)
{
    for(int i= 0;i<eleicao->totalEleitores;i++)
    {
        for(int j=i+1;j<eleicao->totalEleitores;j++)
        {
            if(EhMesmoEleitor(eleicao->eleitores[i],eleicao->eleitores[j]))
            {
                printf("ELEICAO ANULADA\n");
                return;
            }
        }
    }

    for(int i= 0;i<eleicao->totalEleitores;i++)
    {
        int vp = ObtemVotoPresidente(eleicao->eleitores[i]);
        int vg = ObtemVotoGovernador(eleicao->eleitores[i]);

        if(vg==0)
            eleicao->votosBrancosGovernador++;
        else
        {
            int check = 1;
            for(int j=0;j<eleicao->totalGovernadores;j++)
            {
                if(VerificaIdCandidato(eleicao->governadores[j],vg))
                {
                    IncrementaVotoCandidato(eleicao->governadores[j]);
                    check = 0;
                    break;
                }
                
            }

            if(check)
                eleicao->votosNulosGovernador++;
        }


        if(vp==0)
            eleicao->votosBrancosPresidente++;
        else
        {
            int check = 1;
            for(int j=0;j<eleicao->totalPresidentes;j++)
            {
                if(VerificaIdCandidato(eleicao->presidentes[j],vp))
                {
                    IncrementaVotoCandidato(eleicao->presidentes[j]);
                    check = 0;
                    break;
                }
                
            }

            if(check)
                eleicao->votosNulosPresidente++;
        }
    }

//Apuraçao
    int empateP = 0;
    int empateG = 0;

    for(int i=0;i<eleicao->totalPresidentes;i++)
{
    for(int j=i+1;j<eleicao->totalPresidentes;j++)
    {
        int votosI = ObtemVotos(eleicao->presidentes[i]);
        int votosJ = ObtemVotos(eleicao->presidentes[j]);

        if(votosJ>votosI)
        {
            tCandidato* temp = eleicao->presidentes[i];
            eleicao->presidentes[i] = eleicao->presidentes[j];
            eleicao->presidentes[j] = temp;
        }
    }
}

if(eleicao->totalPresidentes>1)
{
    if(ObtemVotos(eleicao->presidentes[0])==ObtemVotos(eleicao->presidentes[1]))
        empateP = 1;
}

if(empateP)
    printf("- PRESIDENTE ELEITO: EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
else if(ObtemVotos(eleicao->presidentes[0])<= (eleicao->votosBrancosPresidente+eleicao->votosNulosPresidente))
    printf("- PRESIDENTE ELEITO: SEM DECISAO\n");

else
{
    printf("- PRESIDENTE ELEITO: ");
    ImprimeCandidato(eleicao->presidentes[0],CalculaPercentualVotos(eleicao->presidentes[0],eleicao->totalEleitores));
}


    for(int i=0;i<eleicao->totalGovernadores;i++)
    {
        for(int j=i+1;j<eleicao->totalGovernadores;j++)
        {
            int votosI = ObtemVotos(eleicao->governadores[i]);
            int votosJ = ObtemVotos(eleicao->governadores[j]);

            if(votosJ>votosI)
            {
                tCandidato* temp = eleicao->governadores[i];
                eleicao->governadores[i] = eleicao->governadores[j];
                eleicao->governadores[j] = temp;
            }
        }
    }

    if(eleicao->totalGovernadores>1)
    {
        if(ObtemVotos(eleicao->governadores[0])==ObtemVotos(eleicao->governadores[1]))
            empateG = 1;
    }

    if(empateG)
        printf("- GOVERNADOR ELEITO: EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    else if(ObtemVotos(eleicao->governadores[0])<= (eleicao->votosBrancosGovernador+eleicao->votosNulosGovernador))
        printf("- GOVERNADOR ELEITO: SEM DECISAO\n");
    
    else
    {
        printf("- GOVERNADOR ELEITO: ");
        ImprimeCandidato(eleicao->governadores[0],CalculaPercentualVotos(eleicao->governadores[0],eleicao->totalEleitores));
        
    }


    printf("- NULOS E BRANCOS: %d, %d\n",eleicao->votosNulosGovernador+eleicao->votosNulosPresidente,eleicao->votosBrancosGovernador+eleicao->votosBrancosPresidente);
    

}

