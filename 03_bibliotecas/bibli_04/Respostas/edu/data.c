#include <stdio.h>
#include "data.h"

/**
 * @brief Verifica se uma data é válida.
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 * @return Retorna 1 se a data é válida e 0 caso contrário.
 */
int verificaDataValida(int dia, int mes, int ano){
    if(mes>=1&&mes<=12){
        
        if(mes==4||mes==6||mes==9||mes==11){
            if(dia>=1&&dia<=30){
                return 1;
            }

            return 0;

        }
        else if(mes==2){
            if(verificaBissexto(ano)){
                if(dia>=1&&dia<=29){
                    return 1;
                }
                return 0;
            }
            else{
                if(dia>=1&&dia<=28){
                    return 1;
                }
                return 0;
            }
        }
        else{
            if(dia>=1&&dia<=31){
                return 1;
            }
            return 0;
        }
    }
    return 0;
}

/**
 * @brief Imprime uma data no formato DD/MM/AAAA.
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 */
void imprimeData(int dia, int mes, int ano){

    printf("%02d/%02d/%d",dia,mes,ano);
}

/**
 * @brief Imprime o nome do mês por extenso.
 * 
 * @param mes Mês da data.
 */
void imprimeMesExtenso(int mes){
    if(mes==1){
        printf("Janeiro");
    }
    else if(mes==2){
        printf("Fevereiro");
    }
     else if(mes==3){
        printf("Marco");
    }
     else if(mes==4){
        printf("Abril");
    }
     else if(mes==5){
        printf("Maio");
    }
     else if(mes==6){
        printf("Junho");
    }
     else if(mes==7){
        printf("Julho");
    }
     else if(mes==8){
        printf("Agosto");
    }
     else if(mes==9){
        printf("Setembro");
    }
     else if(mes==10){
        printf("Outubro");
    }
     else if(mes==11){
        printf("Novembro");
    }
    else{
        printf("Dezembro");
    }
}

/**
 * @brief Imprime uma data por extenso no formato "DD de NOME_DO_MES de AAAA".
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 */
void imprimeDataExtenso(int dia, int mes, int ano){
    printf("%02d de ",dia);
    imprimeMesExtenso(mes);
    printf(" de %d\n",ano);

}

/**
 * @brief Verifica se um ano é bissexto.
 * 
 * @param ano Ano a ser verificado.
 * @return Retorna 1 se o ano é bissexto e 0 caso contrário.
 */
int verificaBissexto(int ano){
    if((ano%4==0&&ano%100!=0)||(ano%400==0)){
        return 1;
    }
    return 0;
}

/**
 * @brief Retorna o número de dias de um determinado mês.
 * 
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return Retorna o número de dias do mês.
 */
int numeroDiasMes(int mes, int ano){

    if(mes==4||mes==6||mes==9||mes==11)
        return 30;
    
    else if(mes==2)
    {
        if(verificaBissexto(ano))
            return 29;
        
        else
            return 28;

    }
    else
        return 31;
}

/**
 * @brief Compara duas datas.
 * 
 * @param dia1 Dia da primeira data.
 * @param mes1 Mês da primeira data.
 * @param ano1 Ano da primeira data.
 * @param dia2 Dia da segunda data.
 * @param mes2 Mês da segunda data.
 * @param ano2 Ano da segunda data.
 * @return Retorna 1 se a primeira data é maior que a segunda, -1 se a primeira data é menor que a segunda e 0 se as datas são iguais.
 */
int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{

    if(ano1>ano2)
        return 1;
    else if(ano1<ano2)
        return -1;
    
    else
    {
        if(mes1>mes2)
            return 1;
        else if(mes1<mes2)
            return -1;
        else
        {
            if(dia1>dia2)
                return 1;
            else if(dia1<dia2)
                return -1;
            else
                return 0;
        }

    }
}

/**
 * @brief Calcula o número de dias até o início de um determinado mês.
 * 
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return Retorna o número de dias até o início do mês.
 */
int calculaDiasAteMes(int mes, int ano)
{
    int soma=0;

    for(int i=1;i<mes;i++)
        soma+=numeroDiasMes(mes,ano);

    return soma;
        
    
}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 * 
 * @param dia1 Dia da primeira data.
 * @param mes1 Mês da primeira data.
 * @param ano1 Ano da primeira data.
 * @param dia2 Dia da segunda data.
 * @param mes2 Mês da segunda data.
 * @param ano2 Ano da segunda data.
 * @return Retorna o número de dias de diferença entre as datas.
 */
int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    int diferenca=0;
    int comp=comparaData(dia1,mes1,ano1,dia2,mes2,ano2);

    if(comp==0)
        return 0;

    else if(comp==1)
    {
        if(ano1==ano2)
        {
            if(mes1==mes2)
                diferenca=dia1-dia2;

            else
            {
                for(int i=mes2+1;i<mes1;i++)
                    diferenca+=numeroDiasMes(i,ano1);

                diferenca+= numeroDiasMes(mes2,ano2)-dia2;
                diferenca+=dia1;
            }
        }
        else 
        {
            for(int i=ano2+1;i<ano1;i++)
            {

                if(verificaBissexto(i))
                    diferenca+=366;
                
                else
                    diferenca+=365;
            }

            for(int i=mes2+1;i<13;i++)
                diferenca+=numeroDiasMes(i,ano2);

            diferenca+= numeroDiasMes(mes2,ano2)-dia2;

            diferenca+=calculaDiasAteMes(mes1,ano1);
            diferenca+=dia1;
            
        }
    }
    else if(comp==-1)
    {
         if(ano1==ano2)
        {
            if(mes1==mes2)
                diferenca=dia2-dia1;

            else
            {
                for(int i=mes1+1;i<mes2;i++)
                    diferenca+=numeroDiasMes(i,ano2);

                diferenca+= numeroDiasMes(mes1,ano1)-dia1;
                diferenca+=dia2;
            }
        }
        else 
        {
            for(int i=ano1+1;i<ano2;i++)
            {

                if(verificaBissexto(i))
                    diferenca+=366;
                
                else
                    diferenca+=365;
            }

            for(int i=mes1+1;i<13;i++)
                diferenca+=numeroDiasMes(i,ano1);

            diferenca+= numeroDiasMes(mes1,ano1)-dia1;

            diferenca+=calculaDiasAteMes(mes2,ano2);
            diferenca+=dia2;
            
        }
    }

    return diferenca;
}

/**
 * @brief Imprime a próxima data no formato DD/MM/AAAA.
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 */
void imprimeProximaData(int dia, int mes, int ano)
{
    if(dia<numeroDiasMes(mes,ano))
        dia+=1;
    else if(mes<12)
    {
        mes+=1;
        dia=1;
    }
        
    else
    {
        ano+=1;
        mes=1;
        dia=1;
    }

    printf("%02d/%02d/%d",dia,mes,ano);
}