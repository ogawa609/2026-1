#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "game.h"
#include "movie.h"
#include "music.h"


int main()
{
    List* lista = list_construct();

    char op[50];

    while(1)
    {
        scanf("%s",op);

        if(strcmp(op,"IMPRIMIR")==0)
            break;

        else if(strcmp(op,"JOGO")==0)
        {
            Game* j = game_read_and_construct();
            list_media_insert(lista,j,game_print,game_free);
        }
        else if(strcmp(op,"FILME")==0)
        {
            Movie* m = movie_read_and_construct();
            list_media_insert(lista,m,movie_print,movie_free);
        }
        else if(strcmp(op,"MUSICA")==0)
        {
            Music* n = music_read_and_construct();
            list_media_insert(lista,n,music_print,music_free);
        }
        else
            printf("INVALIDO\n");
    }

    list_print(lista);
    list_free(lista);

    return 0;
}