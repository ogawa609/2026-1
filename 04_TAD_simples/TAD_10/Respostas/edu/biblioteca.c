#include <stdio.h>
#include <string.h>
#include "biblioteca.h"

/**
 * Inicializa uma biblioteca vazia.
 *
 * @return A biblioteca inicializada.
 */
tBiblioteca inicializarBiblioteca()
{
    tBiblioteca b;
    b.tamanho=0;

    return b;
}

/**
 * Adiciona um livro à biblioteca.
 * Se estiver dentro do tamanho máximo de livros, imprime "Livro adicionado com sucesso!"
 * Senão, imprime "A biblioteca está cheia. Não é possível adicionar mais livros."
 *
 * @param biblioteca A biblioteca onde o livro será adicionado.
 * @param livro O livro a ser adicionado.
 * @return A biblioteca atualizada com o livro adicionado.
 */
tBiblioteca adicionarLivroNaBiblioteca(tBiblioteca biblioteca, tLivros livro)
{
    if(biblioteca.tamanho<MAX_LIVROS)
    {
        biblioteca.livros[biblioteca.tamanho] = livro;
        biblioteca.tamanho++;
        printf("Livro adicionado com sucesso!\n\n");
    }
    else 
        printf("A biblioteca esta cheia. Nao eh possivel adicionar mais livros.\n\n");

    
    return biblioteca;
}

/**
 * Remove um livro da biblioteca pelo título. 
 * Se o título for encontrado, imprime "Livro removido com sucesso!",
 * Senão, imprime "Livro não encontrado na biblioteca."
 *
 * @param biblioteca A biblioteca da qual o livro será removido.
 * @param titulo O título do livro a ser removido.
 * @return A biblioteca atualizada após a remoção do livro.
 */
tBiblioteca removerLivroDaBiblioteca(tBiblioteca biblioteca, char *titulo)
{
    int check = 1;
    for(int i=0;i<biblioteca.tamanho;i++)
    {
        if(verificaTituloDoLivroNaBiblioteca(biblioteca.livros[i],titulo))
        {
            printf("Livro removido com sucesso!\n\n");

            for(int j=i+1;j<biblioteca.tamanho;j++)
            {
                biblioteca.livros[j-1] = biblioteca.livros[j];
            }

            biblioteca.tamanho--;
            check = 0;
        }
    }

    if(check)
        printf("Livro nao encontrado na biblioteca.\n\n");

    return biblioteca;
}

/**
 * Verifica se o título digitado é igual ao título do livro.
 * 
 * @param livro O livro cujo título será verificado.
 * @param titulo O título digitado pelo usuário.
 * @return se o título for igual, retorna 0.
*/
int verificaTituloDoLivroNaBiblioteca(tLivros livro, char* titulo)
{
    if(strcmp(livro.titulo,titulo)==0)
        return 1;

    return 0;
}

/**
 * Lista todos os livros presentes na biblioteca.
 * Se não houver livros na biblioteca, imprime "A biblioteca esta vazia!"
 *
 * @param biblioteca A biblioteca cujos livros serão listados.
 */
void listarLivrosDaBiblioteca(tBiblioteca biblioteca)
{
    if(biblioteca.tamanho<1)
        printf("A biblioteca esta vazia!\n\n");
    else
    {
        printf("Lista de Livros na Biblioteca:\n");

        for(int i=0;i<biblioteca.tamanho;i++)
        {
            imprimeLivro(biblioteca.livros[i]);
            printf("\n");
        }
    }


}