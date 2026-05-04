#include <stdio.h>
#include <string.h>
#include "servidor.h"

/*
Função que lê todos os registros de brackets de um servidor a partir da entrada padrão e retorna um servidor
com todos os registros de brackets lidos. Conforme a especificação da atividade, a leitura é encerrada quando
um ID de bracket igual a -1 é lido.

@return Servidor: Servidor com todos os registros de brackets lidos
*/
tServidor leBracketsServidor()
{
    tServidor servidor;
    servidor.nBrackets = 0;
    int id;

    while(1)
    {
        scanf("%d",&id);

        if(id==-1)
            break;

        tBracket bra = leBracket(id);
        servidor.brackets[servidor.nBrackets] = bra;
        servidor.nBrackets++;
    }

    return servidor;
}

/*
Função que recebe um servidor já preenchido com os dados de todas as brackets e um ID de jogador.
A partir dessas informações, ela busca as estatísticas do jogador em todas as brackets que ele participou.
Se o jogar não for encontrado, um jogador com ID -1 é criado e retornado.
Se o jogador for encontrado em uma ou mais brackets, suas estatísticas são agregadas e o jogador é retornado.

@param s: Servidor
@param idJog: ID do jogador
*/
tJogador buscaDadosJogadorServidor(tServidor s, int idJog)
{
    int somenteUmaVez = 1;
    int repetido = 0;

    tJogador achado;

    for(int i=0;i<s.nBrackets;i++)
    {
        achado = buscaJogadorBracket(s.brackets[i],idJog); //verifica se jogador ta nessa bracket

        if(getIdJogador(achado)!=-1) //se tiver, ativa a busca na outras brackets pra ver se repete
            repetido = 1;
        
        if(repetido) //se repete busca os dados e atualiza;
        {
            for(int j=i+1;j<s.nBrackets;j++){

                tJogador temp;
                temp = buscaJogadorBracket(s.brackets[j],idJog);

                if(getIdJogador(temp)!=-1)
                {
                    int defeats = getDefeatsJogador(temp);
                    int wins = getWinsJogador(temp);
                    int draws = getDrawsJogador(temp);

                    achado = atualizaJogador(achado,idJog,wins,defeats,draws);
                }
            }
            break; //para o laço pra nao repetir
        }
    }

    return achado;
}

/*
Função que recebe um servidor já criado e preenchido e imprime um relatório com as estatísticas de um conjunto de jogadores
solicitados a partir da entrada padrão. O relatório é impresso conforme o formato especificado na descrição da atividade.
*/
void criaRelatorioServidor(tServidor s)
{
    int qnt;
    scanf("%d",&qnt);

    for(int i=0;i<qnt;i++)
    {
        int id;
        scanf("%d",&id);

        tJogador jog = buscaDadosJogadorServidor(s,id);
        if(getIdJogador(jog)!=-1)
            printaJogador(jog);
        else 
            printf("Jogador %d: -\n",id);

    }
}