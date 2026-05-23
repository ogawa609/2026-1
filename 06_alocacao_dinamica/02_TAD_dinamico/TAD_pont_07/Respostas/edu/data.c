#include <stdio.h>
#include <stdlib.h>
#include "data.h"


/**
 * @brief Aloca dinamicamente uma estrutura do tipo tData, e a retorna. 
 * Os campos dessa estrutura devem ser preenchidos inicialmente com -1.
 * 
 * @return tData - Data "Vazia"
 */
tData* CriaData()
{
    tData* data = malloc(sizeof(tData));
    return data;

}

/**
 * @brief Lê o dia, mês e ano e armazena em uma estrutura tData alocada dinamicamente.
 * 
 * @param data - Ponteiro para a estrutura onde os dados serão armazenados. Lembre-se: Não pode ter valor NULL.
 */
void LeData(tData* data)
{
    scanf("%d/%d/%d\n",&data->dia,&data->mes,&data->ano);
}

/**
 * @brief Libera a memória alocada dinamicamente para uma estrutura do tipo tData, passada como parâmetro
 * @param data - Ponteiro para a estrutura onde os dados estão armazenados. 
*/
void LiberaData(tData* data)
{
    free(data);
}

/**
 * @brief Verifica se uma data é válida.
 * 
 * @param data Data a ser verificada.
 * @return int 1 se a data é válida, 0 caso contrário.
 */
int VerificaDataValida(tData* data)
{
    int d =data->dia;
    int m = data->mes;

    if(m>0&&m<13)
    {
        if(d>0&&d<=NumeroDiasMes(data))
            return 1;
    }

    return 0;

}

/**
 * @brief Imprime o mês de uma data em formato extenso.
 * 
 * @param data Data cujo mês será impresso em formato extenso.
 */
void ImprimeMesExtenso(tData* data)
{
    int m = data->mes;
    if(m==1)
    
        printf("Janeiro");
    
    else if(m==2)

        printf("Fevereiro");
    
    else if(m==3)

        printf("Marco");

    else if(m==4)

        printf("Abril");
    
    else if(m==5)

        printf("Maio");

    else if(m==6)

        printf("Junho");

    else if(m==7)

        printf("Julho");

    else if(m==8)

        printf("Agosto");

    else if(m==9)

        printf("Setembro");

    else if(m==10)

        printf("Outubro");

    else if(m==11)

        printf("Novembro");

    else if(m==12)

        printf("Dezembro");
}

/**
 * @brief Imprime uma data em formato extenso.
 * 
 * @param data Data a ser impressa em formato extenso.
 */
void ImprimeDataExtenso(tData* data)
{
    printf("%02d de ",data->dia);
    ImprimeMesExtenso(data);
    printf(" de %d\n",data->ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 * 
 * @param data Data cujo ano será verificado.
 * @return int 1 se o ano é bissexto, 0 caso contrário.
 */
int VerificaBissexto(tData* data)
{
    int a = data->ano;

    return (a%4==0 && a%100!=0)||(a%400==0);
}

/**
 * @brief Retorna o número de dias de um determinado mês.
 * 
 * @param data Data cujo mês terá o número de dias retornado.
 * @return int Número de dias do mês da data.
 */
int NumeroDiasMes(tData* data)
{
    int a = data->mes;
    if(a==4||a==6||a==9||a==11)
        return 30;
    else if(a==2)
    {
        if(VerificaBissexto(data))
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
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int 1 se data1 é maior que data2, -1 se data1 é menor que data2, 0 se as datas são iguais.
 * A data ser maior significa que ela é mais recente.
 */
int ComparaData(tData* data1, tData* data2)
{
    if(data1->ano > data2->ano)
        return 1;
    else if(data1->ano < data2->ano)
        return -1;
    

    else
    {
        if(data1->mes > data2->mes)
            return 1;
        else if(data1->mes < data2->mes)
            return -1;


        else
        {
            if(data1->dia > data2->dia)
                return 1;
            else if(data1->dia < data2->dia)
                return -1;
            
            else 
                return 0;
        }
    }
}

/**
 * @brief Calcula o número de dias até o início do mês de uma determinada data.
 * 
 * @param data Data cujo número de dias até o início do mês será calculado.
 * @return int Número de dias até o início do mês da data.
 */
int CalculaDiasAteMes(tData* data)
{
    int total =0;
    for(int i=1;i<data->mes;i++)
    {
        tData temp = {01,i,2000};
        total += NumeroDiasMes(&temp);
    }

    return total;
}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 * 
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int Número de dias entre as duas datas.
 */
int CalculaDiferencaDias(tData* data1, tData* data2)
{
    int compara = ComparaData(data1,data2);
    tData *maior;
    tData*menor;

    if(compara==1)
    {
        maior = data1;
        menor = data2;
    }
    else if(compara==-1)
    {
        maior = data2;
        menor = data1;
    }


    if(data1->ano==data2->ano)
    {
        if(data1->mes==data2->mes)
        {
            if(compara==1)
                return data1->dia - data2->dia;
            else if(compara==-1)
                return data2->dia-data1->dia;
            else
                return 0;
        }
        else
        {
            int dias=0;
            

            for(int i=menor->mes+1;i<maior->mes;i++)
            {
                tData temp = {01,i,2000};
                dias += NumeroDiasMes(&temp);
            }

            dias+= maior->dia;
            dias += (NumeroDiasMes(menor) - menor->dia);
            return dias; 
        
        }
    }

    else
    {
        int dias = 0;

        for(int i=menor->ano+1;i<maior->ano;i++)
        {
            tData temp = {02,03,i};

            if(VerificaBissexto(&temp))
                dias+= 366;
            else
                dias+=365;
        }

         for(int i=menor->mes+1;i<13;i++)
            {
                tData temp = {01,i,2000};
                dias += NumeroDiasMes(&temp);
            }

           
            dias += (NumeroDiasMes(menor) - menor->dia);

            for(int i=1;i<maior->mes;i++)
            {
                tData temp = {01,i,2000};
                dias += NumeroDiasMes(&temp);
            }

            dias+= maior->dia-1;

            return dias; 


    }
}

