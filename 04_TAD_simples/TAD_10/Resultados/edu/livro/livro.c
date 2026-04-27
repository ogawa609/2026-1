#include <stdio.h>
#include <string.h>
#include "livro.h"

/**
 * Lê os atributos de um livro a partir da entrada padrão (teclado).
 *
 * @return Um livro com os atributos lidos.
 */
tLivros lerLivro()
{
    char titulo[100];
    char autor[50];
    int anoPubli;

    scanf(" %[^\n]",titulo);
    scanf(" %[^\n]",autor);
    scanf("%d",&anoPubli);

    tLivros livro;
    livro.anoPublicacao=anoPubli;
    strcpy(livro.autor,autor);
    strcpy(livro.titulo,titulo);

    return livro;
}

/**
 * Imprime os atributos da TAD tLivros (título, autor e ano de publicação).
 * Titulo: Prisao
Autor: John
Ano de Publicacao: 2003
 * @param livro O livro cujos atributos serão impressos
*/
void imprimeLivro(tLivros livro)
{
    printf("Titulo: %s\n",livro.titulo);
    printf("Autor: %s\n",livro.autor);
    printf("Ano de Publicacao: %d\n",livro.anoPublicacao);

}