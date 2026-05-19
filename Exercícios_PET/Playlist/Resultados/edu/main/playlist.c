#include <stdio.h>
#include <string.h>
#include "playlist.h"

/**
 * @brief cria uma playlist vazia com todas as posicoes do array de musicas como NULL
 */
Playlist *criaPlaylist(char *name)
{
    Playlist *p = malloc(sizeof(Playlist));
    p->musicas = calloc(TAM_MAX_MUSICAS,sizeof(Musica*));
            
    p->qtdMusicas = 0 ;
    p->nome = malloc((strlen(name)+1)*sizeof(char));

    strcpy(p->nome,name);

    return p;
}

/**
 * @brief adiciona uma musica em uma playlist
 * @param playlist playlist onde a musica sera adiconada
 */
void adicionaMusica(Playlist *playlist)
{
   Musica *music = criaMusica();
    leMusica(music);

     if(playlist->qtdMusicas>=TAM_MAX_MUSICAS)
    {
        printf("PLAYLIST CHEIA!\n");
        apagaMusica(music);
        return;
    }

    for(int i=0;i<playlist->qtdMusicas;i++)
    {
        if(comparaMusicas(music,playlist->musicas[i]))
        {
            printf("A MUSICA JA ESTA NA PLAYLIST!\n");
            apagaMusica(music);
            return;
        }
    }

   

    playlist->musicas[playlist->qtdMusicas] = music;
    playlist->qtdMusicas++;
 

}

/**
 * @brief remove uma musica de uma playlist
 * @param playlist playlist a ter a musica removida
 * @param music nome da musica a ser removida
 * @param impMus ponteiro para funcao de impressao de musica
 * @return 1 caso a musica seja removida com sucesso e 0 caso o contrario
 */
int removeMusica(Playlist *playlist, char *music, compara comparador, tipoImpressaoMusica impMus)
{
    if (playlist->qtdMusicas > 0)
    {
        for (int i = 0; i < playlist->qtdMusicas; i++)
        {
            if (comparador(playlist->musicas[i], music))
            {
                Musica *musi = playlist->musicas[i];

                for (int j = i; j < playlist->qtdMusicas - 1; j++)
                {
                    playlist->musicas[j] = playlist->musicas[j + 1];
                }

                playlist->qtdMusicas--;
                playlist->musicas[playlist->qtdMusicas] = NULL;

                printf("MUSICA REMOVIDA: ");
                impMus(musi);

                apagaMusica(musi);

                return 1;
            }
        }

        printf("A MÚSICA NAO ESTA NA PLAYLIST\n");
    }

    return 0;
    
}

/**
 * @brief Função genérica que realiza impressões filtradas na playlist (todas as impressoes sao feitas por essa funcao)
 * @param playlist playlist a ser percorrida
 * @param key chave de busca (por exemplo: nome do artista)
 * @param modo função que implementa o modo de impressão/filtragem
 *             (ex.: `imprimePorArtista`).
 * @param impMus ponteiro para funcao de impressao de musica.
 *
 * Dica: ponteiros para função também podem ser NULL
 */
void impressFunction(Playlist *playlist, char *key, compara comparador, tipoImpressaoMusica impMus)
{
    printf("---------------------------------------\n");

    if(comparador == NULL)
        printf("%s\n\n",playlist->nome);
    
    else    
        printf("%s\n\n",key);

    for(int i=0;i<playlist->qtdMusicas;i++)
    {
        if(comparador==NULL)
            impMus(playlist->musicas[i]);

        else if(comparador(playlist->musicas[i],key))
            impMus(playlist->musicas[i]);
    }

    printf("---------------------------------------\n");
}

/**
 * @brief desaloca uma playlist da memoria
 * @param playlist playlist a ser deslocada
 */
void apagaPlaylist(Playlist *playlist)
{
    for(int i=0;i<TAM_MAX_MUSICAS;i++)
    {
        if(playlist->musicas[i]!=NULL)
            apagaMusica(playlist->musicas[i]);
    }

    free(playlist->musicas);
    free(playlist->nome);
    free(playlist);
}
