#include <stdio.h>
#include <string.h>
#include "locadora.h"


/**
 * @brief Cria uma nova locadora.
 * @return Locadora criada.
 */
tLocadora criarLocadora ()
{
    tLocadora l;
    l.lucro=0;
    l.numFilmes=0;
    return l;
}

/**
 * @brief Verifica se um filme está cadastrado na locadora.
 * @param locadora Locadora a ser consultada.
 * @param codigo Código do filme a ser verificado.
 * @return 1 se o filme está cadastrado, 0 caso contrário.
 */
int verificarFilmeCadastrado (tLocadora locadora, int codigo)
{
    for(int i=0; i<locadora.numFilmes;i++)
    {
        if(ehMesmoCodigoFilme(locadora.filme[i],codigo))
            return 1;
    }

    return 0;
}

/**
 * @brief Cadastra um filme na locadora, desde que ele não esteja cadastrado.
 * @param locadora Locadora a ser atualizada.
 * @param filme Filme a ser cadastrado.
 * @return Locadora atualizada.
 * Filme cadastrado 1 - Donnie Darko
*/
tLocadora cadastrarFilmeLocadora (tLocadora locadora, tFilme filme)
{
    if(verificarFilmeCadastrado(locadora, obterCodigoFilme(filme))==0)
    {
        locadora.filme[locadora.numFilmes]=filme;
        locadora.numFilmes++;
        printf("Filme cadastrado %d - ",obterCodigoFilme(filme));
        imprimirNomeFilme(filme);
        printf("\n");
    }
    else
        printf("Filme ja cadastrado no estoque\n");
    

    return locadora;

}

/**
 * @brief Lê o cadastro de um ou mais filmes a partir da entrada padrão e o cadastra na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerCadastroLocadora (tLocadora locadora)
{
    int codigo;

    while(scanf("%d,",&codigo)==1)
    {
        tFilme f=leFilme(codigo);


        locadora=cadastrarFilmeLocadora(locadora,f);
    }
    scanf("%*c");
    return locadora;
}

/**
 * @brief Aluga um conjunto de filmes da locadora.
 * @param locadora Locadora a ser atualizada.
 * @param codigos Array com os códigos dos filmes a serem alugados.
 * @param quantidadeCodigos Quantidade de códigos no array.
 * @return Locadora atualizada.
 */
tLocadora alugarFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos)
{
    int soma=0;
    int alugados=0;
    
    for(int i=0;i<quantidadeCodigos;i++)
    {
        int cadastrado=1;

        for(int j=0;j<locadora.numFilmes;j++)
        {
            if(ehMesmoCodigoFilme(locadora.filme[j],codigos[i]))
            {
                if(obterQtdEstoqueFilme(locadora.filme[j])>0)
                {
                    locadora.filme[j]= alugarFilme(locadora.filme[j]);
                    cadastrado=0;
                    alugados++;
                    soma+=obterValorFilme(locadora.filme[j]);
                    break;
                }
                else
                {
                    printf("Filme %d - ",obterCodigoFilme(locadora.filme[j]));
                    imprimirNomeFilme(locadora.filme[j]);
                    cadastrado=0;
                    printf(" nao disponivel no estoque. Volte mais tarde.\n");
                }
            }
            
        }

        if(cadastrado)
            printf("Filme %d nao cadastrado.\n",codigos[i]);
    }


    if(alugados>0)
        printf("Total de filmes alugados: %d com custo de R$%d\n",alugados,soma);
    

    return locadora;
}

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerAluguelLocadora (tLocadora locadora)
{
    int qntAlugada=0;
    int codigos[500];
    int code;

    while(scanf("%d",&code)==1)
    {
        codigos[qntAlugada]=code;
        qntAlugada++;
    }
    scanf("%*c");

    locadora= alugarFilmesLocadora(locadora,codigos,qntAlugada);

    return locadora;
}

/**
 * @brief Devolve um conjunto de filmes alugados da locadora.
 * @param locadora Locadora a ser atualizada.
 * @param codigos Array com os códigos dos filmes a serem devolvidos.
 * @param quantidadeCodigos Quantidade de códigos no array.
 * @return Locadora atualizada.
 */
tLocadora devolverFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos)
{
    for(int i=0;i<quantidadeCodigos;i++)
    {
        int cadastro=1;
        for(int j=0;j< locadora.numFilmes;j++){

            if(ehMesmoCodigoFilme(locadora.filme[j],codigos[i]))
            {
                cadastro=0;
                if(obterQtdAlugadaFilme(locadora.filme[j])>0){
                    locadora.filme[j]= devolverFilme(locadora.filme[j]);

                    printf("Filme %d - ",obterCodigoFilme(locadora.filme[j]));
                    locadora.lucro+=obterValorFilme(locadora.filme[j]);
                    imprimirNomeFilme(locadora.filme[j]);
                    printf(" Devolvido!\n");
                    break;
                }
                else
                    printf("Nao e possivel devolver o filme %d - ",obterCodigoFilme(locadora.filme[j]));
                    imprimirNomeFilme(locadora.filme[j]);
                    printf(".\n");
                    break;
            }
        }

        if(cadastro)
            printf("Filme %d nao cadastrado.\n",codigos[i]);
    }

    return locadora;
}

/**
 * @brief Lê a devolução de um conjunto de filmes a partir da entrada padrão e os devolve na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerDevolucaoLocadora (tLocadora locadora)
{
     int qntdevolvida=0;
    int codigos[500];
    int code;

    while(scanf("%d",&code)==1)
    {
        codigos[qntdevolvida]=code;
        qntdevolvida++;
    }
    scanf("%*c");

    locadora=devolverFilmesLocadora(locadora,codigos,qntdevolvida);

    return locadora;
}

/**
 * @brief Ordena os filmes da locadora por nome.
 * @param locadora Locadora a ser ordenada.
 * @return Locadora ordenada.
 */
tLocadora ordenarFilmesLocadora (tLocadora locadora)
{
    for(int i=0;i<locadora.numFilmes;i++)
    {
        for(int j=i+1;j<locadora.numFilmes;j++)
        {
            if(compararNomesFilmes(locadora.filme[i],locadora.filme[j])>0)
            {
                tFilme temp= locadora.filme[i];
                locadora.filme[i]=locadora.filme[j];
                locadora.filme[j]=temp;
            }
        }
    }

    return locadora;
}

/**
 * @brief Imprime o estoque da locadora.
 * @param locadora Locadora a ser consultada.
 * ~ESTOQUE~
1 - Final Fantasy Fitas em estoque: 0
2 - Shrek Fitas em estoque: 0
 */
void consultarEstoqueLocadora (tLocadora locadora)
{
    printf("~ESTOQUE~\n");

    for(int i=0;i<locadora.numFilmes;i++)
    {

        printf("%d - ",obterCodigoFilme(locadora.filme[i]));
        imprimirNomeFilme(locadora.filme[i]);
        printf(" Fitas em estoque: %d\n",obterQtdEstoqueFilme(locadora.filme[i]));

    }

    
}

/**
 * @brief Imprime o lucro da locadora.
 * @param locadora Locadora a ser consultada.
 */
void consultarLucroLocadora (tLocadora locadora)
{
    
    if(locadora.lucro>0){
        printf("\n");
        printf("Lucro total R$%d\n",locadora.lucro);
    }
    
}
