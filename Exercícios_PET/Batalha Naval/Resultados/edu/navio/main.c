#include <stdio.h>
#include "grid.h"
#include "partida.h"


int main()
{
    char nome1[50], nome2[50];
    int tamanho;

    // Entrada inicial
    scanf("%s %s %d", nome1, nome2, &tamanho);

    // Criar partida
    Partida p = partida_criar(nome1, nome2, tamanho);

    printf("=== BATALHA NAVAL: %s vs %s ===\n\n", nome1, nome2);

    // POSICIONAR NAVIOS (5 para cada jogador)
    for (int jogador = 0; jogador < 2; jogador++)
    {
        for (int i = 0; i < 5; i++)
        {
            int linha, coluna, horizontal, tam;
            char nomeNavio[50];

            scanf("%d %d %d %d %s", &linha, &coluna, &horizontal, &tam, nomeNavio);

            Navio n = navio_criar(nomeNavio, tam);
            Posicao inicio = posicao_criar(linha, coluna);

            grid_posicionar(&p.grids[jogador], &n, inicio, horizontal);
        }
    }

    printf("Navios posicionados. Iniciando jogo...\n\n");

    int rodada = 1;

    // LOOP DE JOGADAS
    while (!partida_encerrada(p))
    {
        int linha, coluna, jogadorEntrada;

        // se não houver mais entrada, encerra
       if (scanf("%d %d %d", &linha, &coluna, &jogadorEntrada) != 3)
        break;

    // VERIFICACAO DE TURNO
    if (jogadorEntrada != p.turno)
    {
        printf("Aviso: jogador %d nao eh o turno atual (%d)\n",
               jogadorEntrada, p.turno);
               continue;
    }

        Posicao alvo = posicao_criar(linha, coluna);

        const char *jogadorAtual = partida_turno_atual(&p);

        ResultadoJogada r = partida_jogar(&p, alvo);

        printf("Rodada %d - %s atira em (%d, %d): ",
               rodada, jogadorAtual, linha, coluna);

        if (r == JOGADA_INVALIDA)
        {
            printf("Jogada invalida!\n");
        }
        else if (r == JOGADA_AGUA)
        {
            printf("Agua! Passa a vez.\n");
            rodada++;
        }
        else if (r == JOGADA_ACERTO)
        {
            printf("Acerto!\n");
            rodada++;
        }
        else if (r == JOGADA_AFUNDOU)
        {
            printf("Afundou um navio!\n");
            rodada++;
        }
        else if (r == JOGADA_VITORIA)
        {
            printf("VITORIA!\n");
            rodada++;
            break;
        }
    }


    const char *vencedor = partida_vencedor(&p);
    if (vencedor != NULL)
    {
         printf("\n*** PARTIDA ENCERRADA ***\n");
        printf("Vencedor: %s\n", vencedor);
    }

    return 0;
}