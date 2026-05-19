#include "playlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Playlist *criaPlaylist(char *name)
{
    if (name == NULL) return NULL;

    Playlist *p = malloc(sizeof(Playlist));
    if (p == NULL) return NULL;

    p->qtdMusicas = 0;
    p->nome = malloc((strlen(name) + 1) * sizeof(char));

    if (p->nome == NULL){
        free(p);
        return NULL;
    }

    strcpy(p->nome, name);
    p->musicas = malloc(TAM_MAX_MUSICAS * sizeof(Musica *));

    if (p->musicas == NULL){
        free(p->nome);
        free(p);
        return NULL;
    }

    for (int i = 0; i < TAM_MAX_MUSICAS; i++){
        p->musicas[i] = NULL;
    }

    return p;
}

void adicionaMusica(Playlist *playlist)
{
    if (playlist == NULL) return;

    if (playlist->qtdMusicas >= TAM_MAX_MUSICAS){
        char c[MAX_TAM_STRING];
        scanf(" %[^\n]", c);   
        scanf(" %[^\n]", c);   
        scanf(" %[^\n]", c);   
        scanf(" %[^\n]", c);   
        
        printf("PLAYLIST CHEIA!\n");
        return;
    }

    Musica *musica = criaMusica();
    if (musica == NULL) return;

    leMusica(musica);

    for (int i = 0; i < playlist->qtdMusicas; i++){
        if (playlist->musicas[i] != NULL &&
            comparaMusicas(playlist->musicas[i], musica) == 1){
            printf("A MÚSICA JÁ ESTÁ NA PLAYLIST!\n"); 
            apagaMusica(musica);
            return;
        }
    }

    playlist->musicas[playlist->qtdMusicas] = musica;
    playlist->qtdMusicas++;
}

int removeMusica(Playlist *playlist, char *music, compara comparador, tipoImpressaoMusica impMus){
    if (playlist == NULL || music == NULL || comparador == NULL){
        return 0;
    }

    for (int i = 0; i < playlist->qtdMusicas; i++){
        if (playlist->musicas[i] != NULL && comparador(playlist->musicas[i], music) == 1) {
            printf("MUSICA REMOVIDA: "); 
            
            if (impMus != NULL) {
                impMus(playlist->musicas[i]);
            } else {
                printf("\n");
            }

            apagaMusica(playlist->musicas[i]);

            for (int j = i; j < playlist->qtdMusicas - 1; j++){
                playlist->musicas[j] = playlist->musicas[j + 1];
            }

            playlist->musicas[playlist->qtdMusicas - 1] = NULL;
            playlist->qtdMusicas--;
            return 1;
        }
    }

    printf("A MUSICA NAO ESTA NA PLAYLIST\n"); 
    return 0;
}

void impressFunction(Playlist *playlist, char *key, compara comparador, tipoImpressaoMusica impMus)
{
    if (playlist == NULL || impMus == NULL) return;

    printf("---------------------------------------\n");

    if (comparador == NULL) printf("%s\n", playlist->nome);
    else printf("%s\n", key);
    
    for (int i = 0; i < playlist->qtdMusicas; i++){
        if (playlist->musicas[i] != NULL){
            if (comparador == NULL){
                impMus(playlist->musicas[i]);
            }
            else if (key != NULL && comparador(playlist->musicas[i], key) == 1){
                impMus(playlist->musicas[i]);
            }
        }
    }

    printf("---------------------------------------\n");
}

void apagaPlaylist(Playlist *playlist){
    if (playlist == NULL) return;

    if (playlist->musicas != NULL){
        for (int i = 0; i < playlist->qtdMusicas; i++){
            if (playlist->musicas[i] != NULL){
                apagaMusica(playlist->musicas[i]);
            }
        }
        free(playlist->musicas);
    }
    free(playlist->nome);
    free(playlist);
}