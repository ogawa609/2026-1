#include <stdio.h>
#include "data.h"

#define ANO 365
/**
 * @brief Verifica se uma data é válida.
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 * @return int Retorna 1 se a data é válida e 0 caso contrário.
 */
int verificaDataValida(int dia, int mes, int ano){

    if(mes>0&&mes<13){

        if(mes==4||mes==6||mes==9||mes==11){

            if(dia>0&&dia<31){

                return 1;
            }
            return 0;
        }
        else if(mes==2){

            if(verificaBissexto(ano)){

                if(dia>0&&dia<30){

                    return 1;
                }

                return 0;
            }
            else{

                if(dia>0&&dia<29){

                    return 1;
                }
                return 0;
            }
        }
        else{
            if(dia>0&&dia<32){

                return 1;
            }
            return 0;
        }
    }
    return 0;
}

/**
 * @brief Imprime o nome do mês por extenso.
 * 
 * @param mes Mês a ser impresso.
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
    else if(mes==12){

        printf("Dezembro");
    }
}

/**
 * @brief Imprime a data por extenso.
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
 * @return int Retorna 1 se o ano é bissexto e 0 caso contrário.
 */
int verificaBissexto(int ano){

    if((ano%4==0&&ano%100!=0)||(ano%400==0)){
        return 1;
    }

    return 0;
}

/**
 * @brief Calcula o número de dias de um mês.
 * 
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return int Retorna o número de dias do mês.
 */
int numeroDiasMes(int mes, int ano){

    if(mes==4||mes==6||mes==9||mes==11){
        return 30;
    }
    else if(mes==2){

        if(verificaBissexto(ano)){
            return 29;
        }
        return 28;
    }
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
 * @return int Retorna 1 se a primeira data é maior que a segunda, -1 se a primeira data é menor que a segunda
 * e 0 se as datas são iguais.
 * A data ser "maior" significa que ela está mais no futuro.
 */
int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){

    if(ano1>ano2){
        return 1;
    }
    else if(ano1<ano2){
        return -1;
    }
    else{
        if(mes1>mes2){
            return 1;
        }
        else if(mes1<mes2){
            return -1;
        }
        else{
            if(dia1>dia2){
                return 1;
            }
            else if(dia1<dia2){
                return -1;
            }
            else{
                return 0;
            }
        }
    }
}


/**
 * @brief Calcula o número de dias até o mês.
 * 
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return int Retorna o número de dias até o mês.
*/
int calculaDiasAteMes(int mes, int ano){
    int dias=0;

    for(int i=1;i<mes;i++){
        dias+=numeroDiasMes(i,ano);
    }

    return dias;
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
 * @return int Retorna o número de dias de diferença entre as datas.
 */
int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){

    int soma=0;

    if(comparaData(dia1,mes1,ano1,dia2,mes2,ano2)==0){
         return 0;
    }
    else if(comparaData(dia1,mes1,ano1,dia2,mes2,ano2)==1){

    if(ano1==ano2){///////////////////////////////////////////////////////////////////

        if(mes1==mes2){
            soma+=(dia1-dia2);
        }
        else{
            for(int i=mes2+1;i<mes1;i++){
                soma+= numeroDiasMes(i,ano1);
            }
            soma+=dia1;
            soma+=numeroDiasMes(mes2,ano2)-dia2;
        }
    }////////////////////////////////////////////////////////////////////////////
    else{
        for(int i=ano2+1;i<ano1;i++){
            if(verificaBissexto(i)){
                soma+= ANO+1;
            }
            else{
                soma+= ANO;
            }
        }

        soma+=calculaDiasAteMes(mes1,ano1);

        for(int i=mes2+1;i<13;i++){
            soma+=numeroDiasMes(i,ano2);
        }
        soma+=dia1;
        soma+= numeroDiasMes(mes2,ano2)-dia2;
    }
}
else{

    if(ano1==ano2){////////////////////////////////////////////////////////////////////

        if(mes1==mes2){
            soma+=(dia2-dia1);
        }
        else{
            for(int i=mes1+1;i<mes2;i++){
                soma+= numeroDiasMes(i,ano2);
            }
            soma+=dia2;
            soma+=numeroDiasMes(mes1,ano1)-dia1;
        }
    }
    else{///////////////////////////////////////////////////////////////////////////////
        for(int i=ano1+1;i<ano2;i++){
            if(verificaBissexto(i)){
                soma+= ANO+1;
            }
            else{
                soma+= ANO;
            }
        }

        soma+=calculaDiasAteMes(mes2,ano2);
        soma+=dia2;

        for(int i=mes1+1;i<13;i++){
            soma+=numeroDiasMes(i,ano1);
        }
        
        soma+= (numeroDiasMes(mes1,ano1)-dia1);
        }
}

    return soma;
}