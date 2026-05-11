#include <stdio.h>
#include<math.h>
#include <stdlib.h>


float Media(float *notas, int tamnho)
{
    float media = 0;
    for(int i=0; i<tamnho;i++)
    {
        media += notas[i];
    }

    return media/tamnho;
}

float  CalculaDesvioParao(float *notas, int tam)
{
    float media = Media(notas,tam);
    float desvio= 0;

    for(int i=0;i<tam;i++)
    {
        desvio += (notas[i] - media)*(notas[i] - media);
    }

    desvio = desvio/tam;

    return sqrt(desvio);

}


int main()
{

    int tamanho =0;
   
    scanf("%d",&tamanho);

     float *notas = calloc (tamanho,sizeof(float));

    for(int i=0;i<tamanho;i++)
    {
        scanf("%f",&notas[i]);
    }

    float desvio = CalculaDesvioParao(notas,tamanho);

    printf("DESVIO EH: %.2f\n", desvio);

    free(notas);

return 0;
    
}