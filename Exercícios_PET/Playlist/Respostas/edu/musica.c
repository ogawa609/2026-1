#include <stdio.h> 
#include "musica.h"

/**
 * @brief cria um dado do tipo musica, ponteiros devem receber NULL e atributos numericos 0
 * @return retorna a musica criada
 */
Musica *criaMusica()
{
    Musica *mus= malloc(sizeof(Musica));
    
    mus->album=NULL;
    mus->artista=NULL;
    mus->genero=NULL;
    mus->nome=NULL;

    return mus;
}

/**
 * @brief le os atributos de uma musica
 * @param music ponteiro para a musica
 */
void leMusica(Musica *music)
{
    music->nome=malloc(MAX_TAM_STRING*sizeof(char));
    music->album=malloc(MAX_TAM_STRING*sizeof(char));
    music->artista=malloc(MAX_TAM_STRING*sizeof(char));
    music->genero=malloc(MAX_TAM_STRING*sizeof(char));


    scanf(" %[^\n]",music->nome);
    scanf(" %[^\n]",music->artista);
    scanf(" %[^\n]",music->album);
    scanf(" %[\n]",music->genero);
}

/**
 * @brief compara duas musicas
 * @param music_1 primeira musica
 * @param music_2 segunda musica
 * @return 1 se forem iguais e qualquer outro valor caso contrario
 */
int comparaMusicas(Musica *music_1, Musica *music_2)
{
   if(strcmp(music_1->nome,music_2->nome)==0)
   {
        if(strcmp(music_1->artista,music_2->artista)==0)
        {
            if(strcmp(music_1->album,music_2->album)==0)
                return 1;
        }
   }

   return 0;
}

/**
 * @brief compara o nome de uma musica com a string fornecida
 * @return 1 se forem iguais, 0 caso contrario
 */
int comparaNomeMus(Musica *music, char *name)
{
    if(strcmp(music->nome,name)==0)
        return 1;

    return 0;
}

/**
 * @brief compara o artista de uma musica com a string fornecida
 * @return 1 se forem iguais, 0 caso contrario
 */
int comparaArtistaMus(Musica *music, char *artist)
{
    if(strcmp(music->artista,artist)==0)
        return 1;
    
    return 0;
}

/**
 * @brief compara o album de uma musica com a string fornecida
 * @return 1 se forem iguais, 0 caso contrario
 */
int comparaAlbumMus(Musica *music, char *album)
{
    if(strcmp(music->album,album)==0)
        return 1;
    
    return 0;
}

/**
 * @brief compara o genero de uma musica com a string fornecida
 * @return 1 se forem iguais, 0 caso contrario
 */
int comparaGeneroMus(Musica *music, char *genre)
{
    if(strcmp(music->genero,genre)==0)
        return 1;
    
    return 0;
}

/**
 * @brief imprime uma musica no formato [nome] - [artista] ............ [album]
 * @param music musica a ser impressa
 */
/*
FEEL GOOD INC. - Gorillaz ............ Demon Days*/
void imprimeMusica(Musica *music)
{
    printf("%s - %s ............ %s\n",music->nome,music->artista,music->album);
}

/**
 * @brief imprime uma musica no formato [nome]
 * @param musica a ser impressa
 */
void imprimeMusica_Album(Musica *music)
{
    printf("%s\n",music->nome);
}

/**
 * @brief imprime uma musica no formato [nome] - [album]
 * @param musica a ser impressa
 */
void imprimeMusica_Artista(Musica *music)
{
    printf("%s - %s\n",music->nome,music->album);
}

/**
 * @brief imprime uma musica no formato [nome] - [artista]
 * @param music musica a ser impressa
 */
void imprimeMusica_Genero(Musica *music)
{
    printf("%s - %s\n",music->nome,music->artista);
}

/**
 * @brief desaloca uma musica da memoria
 * @param music musica a ser desalocada
 */
void apagaMusica(Musica *music)
{
    free(music->album);
    free(music->artista);
    free(music->genero);
    free(music->nome);
    free(music);
}
