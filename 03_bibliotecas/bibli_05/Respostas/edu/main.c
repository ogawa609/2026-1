#include <stdio.h>
#include <string.h>
#include "string_utils.h"


/** 
1 - Tamanho da string
2 - Copiar string
3 - Converter string para letras maiusculas
4 - Converter string para letras minusculas
5 - Imprimir string ao contrario
6 - Encerrar o programa
Opcao escolhida: 
**/

int main()
{
    char str[1000];

    scanf("%999[^\n]",str);

    while(1)
    {
        printf("1 - Tamanho da string\n");
        printf("2 - Copiar string\n");
        printf("3 - Converter string para letras maiusculas\n");
        printf("4 - Converter string para letras minusculas\n");
        printf("5 - Imprimir string ao contrario\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida:\n");
        int op;
        scanf("%d",&op);

        if(op==1)
        {
            int tam=string_length(str);
            printf("Tamanho da string: %d\n",tam);
        }
        else if(op==2)
        {
            char strcopy[1000];
            string_copy(str,strcopy);
            printf("String copiada: %s\n",strcopy);
        }
        else if(op==3)
        {
            string_upper(str);
            printf("String convertida para maiusculas: %s\n",str);
        }
        else if(op==4)
        {
            string_lower(str);
            printf("String convertida para minusculas: %s\n",str);
        }
        else if(op==5)
        {
            string_reverse(str);
            printf("String invertida: %s\n",str);
        }
        else
        {
                break;
        }
        printf("\n");
    }

    return 0;
}