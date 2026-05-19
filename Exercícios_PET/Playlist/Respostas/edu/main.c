#include <stdio.h>
#include <stdlib.h>
#include "playlist.h"
#include "musica.h"


int main()
{
    char nome[MAX_TAM_STRING];
    scanf(" %[^\n]\n",nome);
    
    char musica[MAX_TAM_STRING];

    Playlist *play = criaPlaylist(nome);

    int operacoes;
    scanf("%d\n",&operacoes);

    int op;

    for(int i=0;i<operacoes;i++)
    {

        scanf("%d\n",&op);
        
        if(op==1)
        {
            adicionaMusica(play);
        }

        else if(op==2)
        {
           
            scanf(" %[^\n]\n",musica);
            removeMusica(play,musica,comparaNomeMus,imprimeMusica_Album);
        }
        else if(op==3)
        {
            impressFunction(play,NULL,NULL,imprimeMusica);
        }
        else if(op==4)
        {
            scanf(" %[^\n]\n",musica);
            impressFunction(play,musica,comparaArtistaMus,imprimeMusica_Artista);
        }
        else if(op==5)
        {
            scanf(" %[^\n]\n",musica);
            impressFunction(play,musica,comparaAlbumMus,imprimeMusica_Album);
        }
        else if(op==6)
        {
            scanf(" %[^\n]\n",musica);
            impressFunction(play,musica,comparaGeneroMus,imprimeMusica_Genero);
        }
    }

    apagaPlaylist(play);

    return 0;
}