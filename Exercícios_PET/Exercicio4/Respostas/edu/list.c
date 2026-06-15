#include "list.h"

    struct List{

        Media** dados;
        int qntDados;
    };
/**
 * @brief Constrói e inicializa uma nova lista vazia.
 * @return Ponteiro para a estrutura List instanciada.
 */
List *list_construct()
{
    List* list = malloc(sizeof(List));

    list->dados = malloc(sizeof(Media*));
    list->qntDados = 0;

    return list;
}

/**
 * @brief Insere um novo item genérico na lista.
 * Se o limite máximo da lista for atingido, a função gerenciará a inserção adequadamente baseada na implementação interna.
 * @param r Ponteiro para a lista onde o dado será inserido.
 * @param data Ponteiro genérico contendo a mídia específica.
 * @param print_fn Função utilizada para imprimir o dado inserido.
 * @param free_fn Função utilizada para desalocar o dado inserido.
 */
void list_media_insert(List *r, void *data, PrintFunction print_fn, FreeFunction free_fn)
{
    Media* p = media_construct(data,print_fn,free_fn);

    r->dados[r->qntDados] = p;
    r->qntDados++;
    r->dados = realloc(r->dados,(r->qntDados+1)*sizeof(Media*));
}

/**
 * @brief Percorre a lista iterativamente e chama a impressão de todos os seus elementos formatados.
 * @param r Ponteiro para a estrutura List a ser impressa.
 */
void list_print(List *r)
{
    if(r->qntDados>0)
    {
        printf("IMPRIMINDO MIDIAS FAVORITAS\n\n");
        
        for(int i=0;i<r->qntDados;i++)
        {
            printf("MIDIA %d: ",i+1);
            media_print(r->dados[i]);
        }
            
    }
    else
        printf("SEM MIDIAS PARA IMPRIMIR\n");
    
}

/**
 * @brief Libera a memória de toda a lista e aciona o destrutor de todos os elementos armazenados nela.
 * @param r Ponteiro para a estrutura List a ser destruída.
 */
void list_free(List *r)
{
    for(int i=0;i<r->qntDados;i++)
        media_free(r->dados[i]);

    free(r->dados);
    free(r);
}

