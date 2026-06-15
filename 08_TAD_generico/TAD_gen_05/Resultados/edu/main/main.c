#include <stdio.h>
#include <stdlib.h>
#include "agendatarefas.h"
#include "tarefaimprime.h"
#include "tarefamultiplica.h"
#include "tarefasoma.h"

int main()
{

    printf("Digite o numero de tarefas:\n");
    int num;
    scanf("%d\n",&num);
    tAgendaTarefas* agenda = CriaAgendaDeTarefas(num);

    for(int i=0;i<num;i++)
    {
        int prioridade;
        char tarefa; 
        scanf("%d %c ",&prioridade,&tarefa);

        if(tarefa=='I')
        {
            char str[100];
            scanf("%[^\n]\n",str);
            tImpr* i = CriaTarefaImprimir(str);

            CadastraTarefaNaAgenda(agenda,prioridade,i,ExecutaTarefaImprimir,DestroiTarefaImprimir);
        }
        else if(tarefa == 'S')
        {
            float n1,n2;
            scanf("%f %f\n",&n1,&n2);
            tSoma* s = CriaTarefaSoma(n1,n2);

            CadastraTarefaNaAgenda(agenda,prioridade,s,ExecutaTarefaSoma,DestroiTarefaSoma);
        }
        else if(tarefa=='M')
        {
            float n1,n2;
            scanf("%f %f\n",&n1,&n2);
            tMult* m = CriaTarefaMultiplicar(n1,n2);

            CadastraTarefaNaAgenda(agenda,prioridade,m,ExecutaTarefaMultiplicar,DestroiTarefaMultiplicar);
        }
        else
        {
            printf("Digite um tipo de tarefa suportado (I/S/M))");
            scanf("%*[^\n]\n");
            i--;
        }
    }

    ExecutarTarefasDaAgenda(agenda);
    DestroiAgendaDeTarefas(agenda);

    return 0;
}