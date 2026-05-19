#include <stdio.h>
#include "utils_char.h"


int main()
{
    int tam;
    scanf("%d\n",&tam);

    char *string = CriaVetor(tam);
    ImprimeString(string,tam);

    LeVetor(string,tam);
    ImprimeString(string,tam);

    LiberaVetor(string);

    return 0;
}