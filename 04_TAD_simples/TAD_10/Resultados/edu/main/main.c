#include <stdio.h>
#include <string.h>
#include "biblioteca.h"

/*
Lista de operacoes:
1 - Cadastrar livros.
2 - Remover livros.
3 - Listar todos os livros cadastrados.
*/

int main()
{
    tBiblioteca bibli = inicializarBiblioteca();
    int qnt;
    scanf("%d",&qnt);

    printf("Lista de operacoes:\n");
    printf("1 - Cadastrar livros.\n");
    printf("2 - Remover livros.\n");
    printf("3 - Listar todos os livros cadastrados.\n\n");


    for(int i=0;i<qnt;i++)
    {
        int op;
        
        scanf("%d",&op);

        if(op==1)
        {
            tLivros livro = lerLivro();
            bibli = adicionarLivroNaBiblioteca(bibli,livro);
        }
        else if(op==2)
        {
            char titulo[100];
            scanf(" %[^\n]",titulo);

           bibli =  removerLivroDaBiblioteca(bibli, titulo);
        }
        else if(op==3)
            listarLivrosDaBiblioteca(bibli);
        else
        {
            printf("Operacao invalida!\n");
            break;
        }
    }

    return 0;
}