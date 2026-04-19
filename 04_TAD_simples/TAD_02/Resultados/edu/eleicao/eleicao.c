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
        tEleitor e= LeEleitor();

        eleicao.eleitores[eleicao.totalEleitores]=e;
        eleicao.totalEleitores++;
   }

   for(int i=0;i<eleitores;i++)
   {
            int votoG=ObtemVotoGovernador(eleicao.eleitores[i]);
            int votoP=ObtemVotoPresidente(eleicao.eleitores[i]);

            if(votoG==0){
                eleicao.votosBrancosGovernador++;
                votoG=-1;
                
            }
            else{

                for(int j=0;j<eleicao.totalGovernadores;j++){
                    
                    if(VerificaIdCandidato(eleicao.governadores[j],votoG)){

                       eleicao.governadores[j]= IncrementaVotoCandidato(eleicao.governadores[j]);
                        votoG=-1;
                        break;
                    }
                }
            }

            if(votoG!=-1){

                eleicao.votosNulosGovernador++;
            }


            if(votoP==0){
                eleicao.votosBrancosPresidente++;
                votoP=-1;
                
            }

            else{

                for(int j=0;j<eleicao.totalPresidentes;j++){
                    
                    if(VerificaIdCandidato(eleicao.presidentes[j],votoP)){

                       eleicao.presidentes[j]= IncrementaVotoCandidato(eleicao.presidentes[j]);
                        votoP=-1;
                        break;
                    }
                }

                if(votoP!=-1){

                    eleicao.votosNulosPresidente++;
                }
            }

            }

            return eleicao;
   }


/**
 * @brief Imprime o resultado da eleição na tela a partir da aparucao dos votos.
 * @param eleicao Eleição a ser impressa.
 */
void ImprimeResultadoEleicao(tEleicao eleicao)
{
    if(eleicao.totalEleitores>10){

        printf("ELEICAO ANULADA");
        return;
    }
    else{

        for(int i=0;i<eleicao.totalEleitores;i++){

            for(int j=i+1;j<eleicao.totalEleitores;j++){
                 
                if(EhMesmoEleitor(eleicao.eleitores[i],eleicao.eleitores[j])){

                    printf("ELEICAO ANULADA");
                    return;
                }
            }
        }

        for(int i=0;i<eleicao.totalPresidentes;i++){

            for(int j=i+1;j<eleicao.totalPresidentes;j++){

                tCandidato temp;

                if(ObtemVotos(eleicao.presidentes[i])<ObtemVotos(eleicao.presidentes[j])){
                    
                    temp=eleicao.presidentes[i];
                    eleicao.presidentes[i]=eleicao.presidentes[j];
                    eleicao.presidentes[j]=temp;
                }
            }

        }

        for(int i=0;i<eleicao.totalGovernadores;i++){

            for(int j=i+1;j<eleicao.totalGovernadores;j++){

                tCandidato temp;

                if(ObtemVotos(eleicao.governadores[i])<ObtemVotos(eleicao.governadores[j])){

                    temp=eleicao.governadores[i];
                    eleicao.governadores[i]=eleicao.governadores[j];
                    eleicao.governadores[j]=temp;
                }
            }

        }

        

         if(eleicao.totalPresidentes>1){

            if(ObtemVotos(eleicao.presidentes[0])==ObtemVotos(eleicao.presidentes[1])){

                printf("- PRESIDENTE ELEITO: EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
            }

            else if(ObtemVotos(eleicao.presidentes[0])<eleicao.votosBrancosPresidente+eleicao.votosNulosPresidente){

                printf("- PRESIDENTE ELEITO: SEM DECISAO\n");
            }

            else{

                float resultado=CalculaPercentualVotos(eleicao.presidentes[0],eleicao.totalEleitores);

                printf("- PRESIDENTE ELEITO: ");
                ImprimeCandidato(eleicao.presidentes[0],resultado);

                

            }
        }
        else{

            if(ObtemVotos(eleicao.presidentes[0])<eleicao.votosBrancosPresidente+eleicao.votosNulosPresidente){

                printf("- PRESIDENTE ELEITO: SEM DECISAO\n");
            }
            else{
                float resultado=CalculaPercentualVotos(eleicao.presidentes[0],eleicao.totalEleitores);

                printf("- PRESIDENTE ELEITO: ");
                ImprimeCandidato(eleicao.presidentes[0],resultado);
            }
        }
      /////////////////////////////////////////////////////////////////////////////////////////////////////
      
      

         if(eleicao.totalGovernadores>1){
            if(ObtemVotos(eleicao.governadores[0])==ObtemVotos(eleicao.governadores[1])){

                printf("- GOVERNADOR ELEITO: EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
            }
            else if(ObtemVotos(eleicao.governadores[0])<eleicao.votosBrancosGovernador+eleicao.votosNulosGovernador){

                printf("- GOVERNADOR ELEITO: SEM DECISAO\n");
            }

            else{

                float resultado=CalculaPercentualVotos(eleicao.governadores[0],eleicao.totalEleitores);
                printf("- GOVERNADOR ELEITO: ");
                ImprimeCandidato(eleicao.governadores[0],resultado);
            }
        }
        else{

            if(ObtemVotos(eleicao.governadores[0])<eleicao.votosBrancosGovernador+eleicao.votosNulosGovernador){

                printf("- GOVERNADOR ELEITO: SEM DECISAO\n");
            }

            else{

                float resultado=CalculaPercentualVotos(eleicao.governadores[0],eleicao.totalEleitores);
                printf("- GOVERNADOR ELEITO: ");
                ImprimeCandidato(eleicao.governadores[0],resultado);
            }
        }


        printf("- NULOS E BRANCOS: %d, %d",eleicao.votosNulosGovernador+eleicao.votosNulosPresidente,eleicao.votosBrancosGovernador+eleicao.votosBrancosPresidente);
    }
}