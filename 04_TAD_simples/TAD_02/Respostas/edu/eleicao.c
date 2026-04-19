#include <stdio.h>
#include "eleicao.h"

/**
 * @brief Inicializa uma eleição com valores padrão (zerando os votos invalidos).
 * Ainda nessa função, é lido a quantidade de candidatos e os candidatos são lidos e armazenados.
 * @return Eleição inicializada.
 */
tEleicao InicializaEleicao()
{
    tEleicao e;

    e.votosBrancosGovernador=0;
    e.votosBrancosPresidente=0;
    e.votosNulosGovernador=0;
    e.votosNulosPresidente=0;
    e.totalEleitores=0;
    e.totalPresidentes=0;
    e.totalGovernadores=0;

    int candidatos;
    scanf("%d\n",&candidatos);

    for(int i=0;i<candidatos;i++)
    {
        tCandidato c= LeCandidato();

        if(ObtemCargo(c)=='G')
        {
            if(e.totalGovernadores<3)
            {
                e.governadores[e.totalGovernadores]=c;
                e.totalGovernadores++;
            }
        }
        else if(ObtemCargo(c)=='P')
        {
            if(e.totalPresidentes<3)
            {
                e.presidentes[e.totalPresidentes]=c;
                e.totalPresidentes++;
            }
        }
    }

    return e;
}

/**
 * @brief Realiza uma eleição.
 * Nessa função, é lido a quantidade de eleitores e os eleitores são lidos e armazenados.
 * @param eleicao Eleição a ser realizada.
 * @return Eleição com os resultados da votação.
 */
tEleicao RealizaEleicao(tEleicao eleicao)
{
    int eleitores;
    scanf("%d",&eleitores);

    for(int i=0;i<eleitores;i++)
    {
        tEleitor ele=LeEleitor();

        int votoG=ObtemVotoGovernador(ele);
        int votoP=ObtemVotoPresidente(ele);
        
            eleicao.eleitores[eleicao.totalEleitores]=ele;
            eleicao.totalEleitores++;


            int verifica=1;
            for(int j=0;j<eleicao.totalGovernadores;j++)
            {
                if(votoG==0)
                {
                    eleicao.votosBrancosGovernador++;
                    verifica=0;
                    break;
                }

                else if(VerificaIdCandidato(eleicao.governadores[j],votoG))
                {
                    IncrementaVotoCandidato(eleicao.governadores[j]);
                    printf("AQUI");
                    verifica=0;
                    break;
                }
                
            }

            if(verifica)
                eleicao.votosNulosGovernador++;

            verifica=1;

            for(int j=0;j<eleicao.totalPresidentes;j++)
            {

                if(votoP==0)
                {
                    eleicao.votosBrancosPresidente++;
                    verifica=0;
                    break;
                }

                else if(VerificaIdCandidato(eleicao.presidentes[j],votoP))
                {
                    IncrementaVotoCandidato(eleicao.presidentes[j]);
                    verifica=0;
                    break;
                }
            }

            if(verifica)
                eleicao.votosNulosPresidente++;
                
        }
        
    return eleicao;
}

/**
 * @brief Imprime o resultado da eleição na tela a partir da aparucao dos votos.
 * @param eleicao Eleição a ser impressa.
 */
void ImprimeResultadoEleicao(tEleicao eleicao)
{
    if(eleicao.totalEleitores>10||eleicao.totalGovernadores==0||eleicao.totalPresidentes==0)
        printf("ELEICAO ANULADA");
    
    else{

        for(int i=0;i<eleicao.totalEleitores;i++)
        {
            for(int j=i+1;j<eleicao.totalEleitores;j++){

                if(EhMesmoEleitor(eleicao.eleitores[i],eleicao.eleitores[j]))
                {
                    printf("ELEICAO ANULADA");
                    return;
                }
            }
        }

        
        tCandidato eleitoG=eleicao.governadores[0];
        int indiceG=0;

        for(int i=0;i<eleicao.totalGovernadores;i++)
        {
            if(ObtemVotos(eleicao.governadores[i])>ObtemVotos(eleitoG))
            {
                eleitoG=eleicao.governadores[i];
                indiceG=i;
            }
        }

        tCandidato eleitoP=eleicao.presidentes[0];
        int indiceP=0;
        
        for(int i=0;i<eleicao.totalPresidentes;i++)
        {
            if(ObtemVotos(eleicao.presidentes[i])>ObtemVotos(eleitoP))
            {
                eleitoP=eleicao.presidentes[i];
                indiceP=i;
            }
        }

        int empate=1;

        if(eleicao.votosBrancosPresidente>ObtemVotos(eleitoP)||eleicao.votosNulosPresidente>ObtemVotos(eleitoP))
            printf("- PRESIDENTE ELEITO: SEM DECISAO\n");

        else
        {
            for(int i=0;i<eleicao.totalPresidentes;i++)
            {
                if(ObtemVotos(eleicao.presidentes[i])==ObtemVotos(eleitoP)&&i!=indiceP)
                {
                    empate=0;
                    printf("- PRESIDENTE ELEITO: EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
                    break;
                }
            }

            if(empate)
            {
                float resultado=CalculaPercentualVotos(eleitoP,eleicao.totalEleitores);
                printf("PRESIDENTE ELEITO: ");
                ImprimeCandidato(eleitoP,resultado);
            }
        }

        if(eleicao.votosBrancosGovernador>ObtemVotos(eleitoG)||eleicao.votosNulosGovernador>ObtemVotos(eleitoG))
            printf("- GOVERNADOR ELEITO: SEM DECISAO\n");
        
        else
        {
            empate=1;

             for(int i=0;i<eleicao.totalGovernadores;i++)
            {
                if(ObtemVotos(eleicao.governadores[i])==ObtemVotos(eleitoG)&&i!=indiceG)
                {
                    empate=0;
                    printf("- GOVERNADOR ELEITO: EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
                    break;
                }
            }
            if(empate)
            {
                float resultado=CalculaPercentualVotos(eleitoG,eleicao.totalEleitores);
                printf("GOVERNADOR ELEITO: ");
                ImprimeCandidato(eleitoG,resultado);
            }
        }

        printf("- NULOS E BRANCOS: %d, %d",eleicao.votosNulosGovernador+eleicao.votosNulosPresidente,eleicao.votosBrancosGovernador+eleicao.votosBrancosPresidente);
    }
}