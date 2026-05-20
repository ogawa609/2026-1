#include<stdio.h>
#include "utils_char2.h"


int main()
{
    int tamanho = TAM_PADRAO;
    char *string = CriaVetorTamPadrao();

    string = LeVetor(string,&tamanho);
    ImprimeString(string);
    LiberaVetor(string);

    return 0;
}