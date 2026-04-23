#include <stdio.h>
#include "data.h"

/**
 * @brief Cria uma data a partir de valores de dia, mês e ano.
 * 
 * @param dia Dia da data a ser criada.
 * @param mes Mês da data a ser criada.
 * @param ano Ano da data a ser criada.
 * @return tData Data criada a partir dos valores de dia, mês e ano.
 */
tData CriaData(int dia, int mes, int ano)
{
    tData d;
    d.ano=ano;
    d.dia=dia;
    d.mes=mes;

    return d;
}

/**
 * @brief Verifica se uma data é válida.
 * 
 * @param data Data a ser verificada.
 * @return int 1 se a data é válida, 0 caso contrário.
 */
int VerificaDataValida(tData data)
{
    if(data.mes>=1&&data.mes<=12)
    {
        if(data.mes==4||data.mes==6||data.mes==9||data.mes==11)
        {
            if(data.dia>=1&&data.dia<=30)
                return 1;
            else
                return 0;
        }
        else if(data.mes==2)
        {
            if(VerificaBissexto(data))
            {
                if(data.dia>=1&&data.dia<=29)
                    return 1;
                else
                    return 0;
            }
            else
            {
                if(data.dia>=1&&data.dia<=28)
                    return 1;
                else
                    return 0;
            }
        }
        else
        {
            if(data.dia>=1&&data.dia<=31)
                return 1;
            else
                return 0;
        }
    }

    return 0;
}

/**
 * @brief Imprime o mês de uma data em formato extenso.
 * 
 * @param data Data cujo mês será impresso em formato extenso.
 */
void ImprimeMesExtenso(tData data)
{
    if(data.mes==1)
        printf("Janeiro");
    else if(data.mes==2)
        printf("Fevereiro");
    else if(data.mes==3)
        printf("Marco");
    else if(data.mes==4)
        printf("Abril");
    else if(data.mes==5)
        printf("Maio");
    else if(data.mes==6)
        printf("Junho");
    else if(data.mes==7)
        printf("Julho");
    else if(data.mes==8)
        printf("Agosto");
    else if(data.mes==9)
        printf("Setembro");
    else if(data.mes==10)
        printf("Outubro");
    else if(data.mes==11)
        printf("Novembro");
    else if(data.mes==12)
        printf("Dezembro");
    
}

/**
 * @brief Imprime uma data em formato extenso.
 * 
 * @param data Data a ser impressa em formato extenso.
 */
void ImprimeDataExtenso(tData data)
{
    printf("%02d de ",data.dia);
    ImprimeMesExtenso(data);
    printf(" de %d\n",data.ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 * 
 * @param data Data cujo ano será verificado.
 * @return int 1 se o ano é bissexto, 0 caso contrário.
 */
int VerificaBissexto(tData data)
{
    if(data.ano%4==0&&data.ano%100!=0)
        return 1;
    else if(data.ano%400==0)
        return 1;

    return 0;
}

/**
 * @brief Retorna o número de dias de um determinado mês.
 * 
 * @param data Data cujo mês terá o número de dias retornado.
 * @return int Número de dias do mês da data.
 */
int NumeroDiasMes(tData data)
{
    if(data.mes==4||data.mes==6||data.mes==9||data.mes==11)
           return 30;
        
        else if(data.mes==2)
        {
            if(VerificaBissexto(data))
            {
                return 29;
            }
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
int ComparaData(tData data1, tData data2)
{
    if(data1.ano>data2.ano)
        return 1;
    else if(data1.ano<data2.ano)
        return -1;
    else
    {
        if(data1.mes>data2.mes)
            return 1;
        else if(data1.mes<data2.mes)
            return -1;
        else
        {
            if(data1.dia>data2.dia)
                return 1;
            else if(data1.dia<data2.dia)
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
int CalculaDiasAteMes(tData data)
{
    int dias=0;
    tData date= CriaData(data.dia,1,data.ano);

    while(date.mes<data.mes)
    {
        dias+= NumeroDiasMes(date);
        date.mes++;
    }

    return dias;
}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 * 
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int Número de dias entre as duas datas.
 */
int CalculaDiferencaDias(tData data1, tData data2)
{
       int soma=0;

       int verifica= ComparaData(data1,data2);

       if(verifica==0)
        return 0;
    
        else if(verifica==1)
        {
            if(data1.ano!=data2.ano)
            {

                tData d = data2;
                d.ano++;

                while(d.ano<data1.ano)
                {
                    if(VerificaBissexto(d))
                        soma+= 366;
                    else
                        soma+= 365;
                    
                    d.ano++;
                }

                d=data2;
                d.mes++;

                while(d.mes<=12)
                {
                    soma+= NumeroDiasMes(d);
                    d.mes++;
                }
                
                soma+= NumeroDiasMes(data2)-data2.dia;
                soma+= CalculaDiasAteMes(data1);
                soma+= data1.dia;
            }
            else
            {

                if(data1.mes!=data2.mes)
                {
                    tData d = data2;
                    d.mes++;

                    while(d.mes<data1.mes)
                    {
                        soma+= NumeroDiasMes(d);
                        d.mes++;
                    }

                    soma+= data1.dia;
                    soma+= NumeroDiasMes(data2)-data2.dia;
                }
                else
                    soma+= data1.dia-data2.dia;
            }
        }
        else
        {
            if(data1.ano!=data2.ano)
            {

                tData d = data1;
                d.ano++;

                while(d.ano<data2.ano)
                {
                    if(VerificaBissexto(d))
                        soma+= 366;
                    else
                        soma+= 365;
                    
                    d.ano++;
                }

                d=data1;
                d.mes++;

                while(d.mes<=12)
                {
                    soma+= NumeroDiasMes(d);
                    d.mes++;
                }
                
                soma+= NumeroDiasMes(data1)-data1.dia;
                soma+= CalculaDiasAteMes(data2);
                soma+= data2.dia;
            }
            else
            {

                if(data1.mes!=data2.mes)
                {
                    tData d = data1;
                    d.mes++;

                    while(d.mes<data2.mes)
                    {
                        soma+= NumeroDiasMes(d);
                        d.mes++;
                    }

                    soma+= data2.dia;
                    soma+= NumeroDiasMes(data1)-data1.dia;
                }
                else
                    soma+= data2.dia-data1.dia;
            }
        }

        return soma;
}