#include <stdio.h>
#include <stdlib.h>
#include "base_alunos.h"

int main()
{
    tBaseAlunos* b = CriarBaseAlunos();
    char caminho[100];
    scanf("%s",caminho);

    LerBaseAlunos(b,caminho);
    printf("Coeficiente de Rendimento Medio da base de alunos: %.2f\n",GetCoeficienteRendimentoMedioBaseAlunos(b));

    DestruirBaseAlunos(b);
    return 0;

}