#include <stdio.h>
#include <stdlib.h>

#include "playlist.h"
#include "musica.h"

int main (){
    char nome[MAX_TAM_STRING];
    int quant;
    int comando;
    char key[MAX_TAM_STRING];            

    if (scanf(" %[^\n]", nome) != 1) return 1;
    if (scanf("%d", &quant) != 1) return 1;

    Playlist *playlist = criaPlaylist(nome);
    if (playlist == NULL) return 1;

    for (int i = 0; i < quant; i++)
    {
        if (scanf("%d", &comando) != 1) break;

        if (comando == 1)
        {
            adicionaMusica(playlist);
        }
        else if (comando == 2)
        {
            scanf(" %[^\n]", key);
            removeMusica(playlist, key, comparaNomeMus, imprimeMusica_Album);
        }
        else if (comando == 3)
        {
            impressFunction(playlist, NULL, NULL, imprimeMusica);
        }
        else if (comando == 4)
        {
            scanf(" %[^\n]", key);
            impressFunction(playlist, key, comparaArtistaMus, imprimeMusica_Artista);
        }
        else if (comando == 5)
        {
            scanf(" %[^\n]", key);
            impressFunction(playlist, key, comparaAlbumMus, imprimeMusica_Album);
        }
        else if (comando == 6)
        {
            scanf(" %[^\n]", key);
            impressFunction(playlist, key, comparaGeneroMus, imprimeMusica_Genero);
        }
    }

    apagaPlaylist(playlist);

    return 0;
}