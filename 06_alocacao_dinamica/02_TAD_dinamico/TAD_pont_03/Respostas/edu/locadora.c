#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locadora.h"

/**
 * @brief Cria uma nova instância de tLocadora e inicializa filme como NULL, numFilmes como 0 e lucro como 0.
 * 
 * @return tLocadora* Ponteiro para a nova instância de tLocadora criada ou encerra o programa caso não haja memória suficiente.
 */
tLocadora* CriarLocadora ()
{
    tLocadora* loc = (tLocadora*) malloc(sizeof(tLocadora));
    loc->filme = (tFilme**) malloc(sizeof(tFilme*));

    loc->lucro = 0;
    loc->numFilmes = 0;

    return loc;
}

/**
 * @brief Destrói uma instância de tLocadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser destruída.
 */
void DestruirLocadora (tLocadora* locadora)
{
    for(int i = 0;i<locadora->numFilmes;i++)
    {
        DestruirFilme(locadora->filme[i]);
    }

    free(locadora->filme);
    free(locadora);
}

/**
 * @brief Verifica se um filme está cadastrado na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser verificada.
 * @param codigo Código do filme a ser verificado.
 * @return int 1 se o filme está cadastrado, 0 caso contrário.
 */
int VerificarFilmeCadastrado (tLocadora* locadora, int codigo)
{
    for(int i =0;i<locadora->numFilmes;i++)
    {
        if(EhMesmoCodigoFilme(locadora->filme[i],codigo))
            return 1;
    }

    return 0;

}

/**
 * @brief Cadastra um novo filme na locadora caso ele não esteja cadastrado.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param filme Ponteiro para o filme a ser cadastrado.
 */
void CadastrarFilmeLocadora (tLocadora *locadora, tFilme *filme)
{
    if(VerificarFilmeCadastrado(locadora,ObterCodigoFilme(filme))==0)
    {
        if(locadora->numFilmes<100)
        {
            locadora->filme[locadora->numFilmes] = filme;
            locadora->numFilmes++;

            printf("Filme cadastrado %d - ",ObterCodigoFilme(filme));
            ImprimirNomeFilme(filme);
            printf("\n");

            locadora->filme = realloc(locadora->filme,(locadora->numFilmes+1)*sizeof(tLocadora*));
           return;
        }

    }

    printf("Filme ja cadastrado no estoque\n");
    DestruirFilme(filme);
}

/**
 * @brief Lê os dados de cadastro de um filme e o cadastra na locadora.
 * 
 * @param Locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerCadastroLocadora (tLocadora* Locadora)
{
    int id;

   while(scanf("%d,",&id)==1)
   {

    tFilme* filme = CriarFilme();
    
    LeFilme(filme,id);

    CadastrarFilmeLocadora(Locadora,filme);
   }
   scanf("%*c");
}

/**
 * @brief Aluga um ou mais filmes da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param codigos Vetor contendo os códigos dos filmes a serem alugados.
 * @param quantidadeCodigos Número de códigos de filmes a serem alugados.
 */
void AlugarFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos)
{
    int alugado = 0;
    int preco=0;

    for(int i=0;i<quantidadeCodigos;i++)
    {
        if(VerificarFilmeCadastrado(locadora,codigos[i]))
        {
            int indice;
            for(int j=0;j<locadora->numFilmes;j++)
            {
                if(EhMesmoCodigoFilme(locadora->filme[j],codigos[i])) 
                {
                    indice = j;
                    break;
                }
                               
            }
            if(ObterQtdEstoqueFilme(locadora->filme[indice])>0)
            {
                AlugarFilme(locadora->filme[indice]);
                alugado++;
                preco+= ObterValorFilme(locadora->filme[indice]);
            }
            else
            {
                printf("Filme %d - ",ObterCodigoFilme(locadora->filme[indice]));
                ImprimirNomeFilme(locadora->filme[indice]);
                printf(" nao disponivel no estoque. Volte mais tarde.\n");
            }
            
        }
        else
            printf("Filme %d nao cadastrado.\n",codigos[i]);
    }
    if(alugado>0)
        printf("Total de filmes alugados: %d com custo de R$%d\n",alugado,preco);
}

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerAluguelLocadora (tLocadora* locadora)
{
     int* codigos = malloc(sizeof(int));
     int qnt = 0;
    int t;
     while(scanf("%d",&t)==1)
     {
            codigos[qnt] = t;
            qnt++;
            codigos = realloc(codigos,(qnt+1)*sizeof(int));
     }
     scanf("%*c");

     AlugarFilmesLocadora(locadora,codigos,qnt);

     
     free(codigos);


}

/**
 * @brief Devolve um ou mais filmes alugados da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param codigos Vetor contendo os códigos dos filmes a serem devolvidos.
 * @param quantidadeCodigos Número de códigos de filmes a serem devolvidos.
 */
void DevolverFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos)
{
    for(int i=0;i<quantidadeCodigos;i++)
    {
        if(VerificarFilmeCadastrado(locadora,codigos[i]))
        {
            int indice;
            for(int j=0;j<locadora->numFilmes;j++)
            {
                if(EhMesmoCodigoFilme(locadora->filme[j],codigos[i])) 
                {
                    indice = j;
                    break;
                }
                               
            }
            if(ObterQtdAlugadaFilme(locadora->filme[indice])>0)
            {
                DevolverFilme(locadora->filme[indice]);
                printf("Filme %d - ",ObterCodigoFilme(locadora->filme[indice]));
                ImprimirNomeFilme(locadora->filme[indice]);
                printf(" Devolvido!\n");

                locadora->lucro+= ObterValorFilme(locadora->filme[indice]);
            }
            else
            {
                printf("Nao e possivel devolver o filme %d - ",ObterCodigoFilme(locadora->filme[indice]));
                ImprimirNomeFilme(locadora->filme[indice]);
                printf(".\n");
            }
            
        }
        else
            printf("Filme %d nao cadastrado.\n",codigos[i]);
    }
}

/**
 * @brief Lê os dados de devolução de um ou mais filmes e os devolve na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerDevolucaoLocadora (tLocadora* locadora)
{
    int* codigos = malloc(sizeof(int));
     int qnt = 0;
    int t;
     while(scanf("%d",&t)==1)
     {
            codigos[qnt] = t;
            qnt++;
            codigos = realloc(codigos,(qnt+1)*sizeof(int));
     }
     scanf("%*c");

     DevolverFilmesLocadora(locadora,codigos,qnt);

     
     free(codigos);


}

/**
 * @brief Ordena os filmes cadastrados na locadora por ordem alfabética.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void OrdenarFilmesLocadora (tLocadora* locadora)
{
    for(int i=0;i<locadora->numFilmes;i++)
    {
        for(int j=i+1;j<locadora->numFilmes;j++)
        {
            if(CompararNomesFilmes(locadora->filme[i],locadora->filme[j])>0)
            {
                tFilme *temp= locadora->filme[i];
                locadora->filme[i]=locadora->filme[j];
                locadora->filme[j]=temp;
            }
        }
    }
}

/**
 * @brief Consulta o estoque de filmes da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarEstoqueLocadora (tLocadora* locadora)
{
     printf("~ESTOQUE~\n");

    for(int i=0;i<locadora->numFilmes;i++)
    {

        printf("%d - ",ObterCodigoFilme(locadora->filme[i]));
        ImprimirNomeFilme(locadora->filme[i]);
        printf(" Fitas em estoque: %d\n",ObterQtdEstoqueFilme(locadora->filme[i]));

    }
}

/**
 * @brief Consulta o lucro da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarLucroLocadora (tLocadora* locadora)
{
    if(locadora->lucro>0){
        printf("\n");
        printf("Lucro total R$%d\n",locadora->lucro);
    }
}
