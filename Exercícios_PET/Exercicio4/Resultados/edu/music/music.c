#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "music.h"

struct Music{
    char*titulo;
    char* artista;
    int feats;
    char** colaboradores;
    char* album;
    char* genero;

};

/**
 * @brief Lê os dados de uma música da entrada padrão e constrói a estrutura correspondente.
 * A ordem de leitura esperada é: Título, Artista, Quantidade de Feats, Lista com os nomes dos Feats, Álbum e Gênero.
 * @return Ponteiro para a estrutura Music recém-criada.
 */
Music *music_read_and_construct()
{
    Music* m = malloc(sizeof(Music));
    m->colaboradores = NULL;
    
    char titulo[MAX_TAM_STRING];
    char artista[MAX_TAM_STRING];
    char genero[MAX_TAM_STRING];
    char album[MAX_TAM_STRING];
    char col[MAX_TAM_STRING];
    int feats;

    scanf("%s %s %d ",titulo,artista,&feats);

    if(feats>0)
    {
        m->colaboradores = malloc(feats*sizeof(char*));

        for(int i=0;i<feats;i++)
        {
            scanf("%s ",col);

            int t = strlen(col) + 1;
            m->colaboradores[i] = malloc(t*sizeof(char));
            strcpy(m->colaboradores[i],col);
        }
    }

    scanf("%s %s\n",album,genero);

    int tam = strlen(titulo) + 1;
    m->titulo = malloc(tam*sizeof(char));
    strcpy(m->titulo,titulo);

    tam = strlen(artista) + 1;
    m->artista = malloc(tam*sizeof(char));
    strcpy(m->artista,artista);

    m->feats = feats;

    tam = strlen(album) + 1;
    m->album = malloc(tam*sizeof(char));
    strcpy(m->album,album);

    tam = strlen(genero) + 1;
    m->genero = malloc(tam*sizeof(char));
    strcpy(m->genero,genero);

    

    return m;
}

/**
 * @brief Imprime os dados formatados de uma música.
 * A formatação exibirá, linha por linha: o Nome, o Artista, os Feats (se a quantidade for maior que zero), o Álbum e o Gênero.
 * @param m Ponteiro genérico que aponta para a estrutura Music.
 */
/*
MIDIA 1: MUSICA
Titulo: All_Of_The_Lights
Artista: Kanye_West feat. Rihanna, Kid_Cudi
Album: My_Beautiful_Dark_Twisted_Fantasy
Genero: Hip-Hop*/
void music_print(void *m)
{
    Music* s = (Music*) m;

    printf("MUSICA\n");
    printf("Titulo: %s\n",s->titulo);
    printf("Artista: %s ",s->artista);
    if(s->feats>0)
    {
        printf("feat. ");

        for(int i=0;i<s->feats;i++)
        {
            if(i==s->feats-1)
                printf("%s\n",s->colaboradores[i]);
            else
                printf("%s, ",s->colaboradores[i]);
        }
    }
    else
        printf("\n");

    printf("Album: %s\n",s->album);
    printf("Genero: %s\n\n",s->genero);
    
    
}

/**
 * @brief Libera a memória alocada para a estrutura de uma música.
 * @param m Ponteiro genérico que aponta para a estrutura Music.
 */
void music_free(void *m)
{
    Music* s = (Music*) m;

    if(s->feats>0)
    {
        for(int i=0;i<s->feats;i++)
            free(s->colaboradores[i]);
        
        free(s->colaboradores);
    }

    free(s->album);
    free(s->artista);
    free(s->genero);
    free(s->titulo);

    free(s);
}