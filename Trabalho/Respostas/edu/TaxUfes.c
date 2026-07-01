#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TaxUfes.h"

#include "motorista.h"
#include "usuario.h"
#include "veiculo.h"



struct Gerenciador{

    tMotorista** motoristas;
    int qntMotoristas;

    tUsuario** usuarios;
    int qntUsuarios;
};

tGerenciador* CriaTaxUfes()
{
    tGerenciador* manager = malloc(sizeof(tGerenciador));

    manager->qntMotoristas = 0;
    manager->qntUsuarios = 0;

    manager->motoristas = malloc(sizeof(tMotorista*));
    manager->usuarios = malloc(sizeof(tUsuario*));

    return manager;
}

void LiberaGerenciador(tGerenciador* g)
{
    for(int i=0;i<g->qntMotoristas;i++)
        liberaMotorista(g->motoristas[i]);
    
    free(g->motoristas);

    for(int i=0;i<g->qntUsuarios;i++)
        LiberaUsuario(g->usuarios[i]);

    free(g->usuarios);

    free(g);
}

void CadastrarUsuario(tGerenciador*g,tUsuario* user)
{
    g->usuarios[g->qntUsuarios] = user;

    g->qntUsuarios++;
    g->usuarios = realloc(g->usuarios,(g->qntUsuarios+1)*sizeof(tUsuario*));

}

void CadastrarMotorista(tGerenciador*g,tMotorista* driver)
{
    g->motoristas[g->qntMotoristas] = driver;

    g->qntMotoristas++;
    g->motoristas = realloc(g->motoristas,(g->qntMotoristas+1) * sizeof(tMotorista*));
}

void LeCadastroAtor(tGerenciador* g)
{
    char tipo[20];

    scanf(" %[^\n]",tipo);

    if((strcmp(tipo,"USUARIO PADRAO")==0)||(strcmp(tipo,"USUARIO INFANTIL")==0)||(strcmp(tipo,"USUARIO PREMIUM")==0))
    {
        tUsuario* user = LeUsuario(tipo);

        if(user==NULL)
        {
            return;
        }
        

        if(strcmp(tipo,"USUARIO INFANTIL")==0)
        {
            char* cpf = getCartaoUsuario(user);
            

            //verifica se cadastro ja existe
            for(int i=0;i<g->qntUsuarios;i++)
            {
                char* cpfSistema = getCpfUsuario(g->usuarios[i]);

                if(ComparaCpfUsuario(cpfSistema,user))
                {
                    printf("CPF JA EXISTENTE! OPERACAO NAO PERMITIDA!\n");
                    LiberaUsuario(user);
                    return;

                }
            }

            //verifica se o cpf do adulto está cadastrado
            for(int i=0;i<g->qntUsuarios;i++)
            {
                char* adulto = getCpfUsuario(g->usuarios[i]);
                TipoUsuario deMaior = getRestricaoIdadeUsuario(g->usuarios[i]);

                if(strcmp(cpf,adulto)==0 && deMaior==1)
                {
                    
                        CadastrarUsuario(g,user);
                        printf("USUARIO CADASTRADO COM SUCESSO!\n");
                        
                        return;
                    
                }
            }

            
            
                printf("CPF NAO CADASTRADO! OPERACAO NAO PERMITIDA!\n");
                LiberaUsuario(user);
                return;
            
                
        }
        else
        {
            char* cpf = getCpfUsuario(user);

            for(int i=0;i<g->qntUsuarios;i++)
            {
                if(ComparaCpfUsuario(cpf,g->usuarios[i]))
                {
                    printf("CPF JA EXISTENTE! OPERACAO NAO PERMITIDA!\n");
                    LiberaUsuario(user);
                    return;
                }
            }

            CadastrarUsuario(g,user);
            printf("USUARIO CADASTRADO COM SUCESSO!\n");
        }
    }
    else if(strcmp(tipo,"CONDUTOR")==0)
    {
        tMotorista* driver = LeMotorista();

        if(driver==NULL)
        {
            return;
        }

        char* cnpj = getCnpjMotorista(driver);

        for(int i=0;i<g->qntMotoristas;i++)
        {
            if(ComparaCnpjMotorista(g->motoristas[i],cnpj))
            {
                printf("CNPJ JA EXISTENTE! OPERACAO NAO PERMITIDA!\n");
                liberaMotorista(driver);
                return;
            }
        }

        CadastrarMotorista(g,driver);
        printf("CONDUTOR CADASTRADO COM SUCESSO!\n");
    }
}

tMotorista* BuscarMotoristaGerenciador(tGerenciador* g, char* cnpj)
{
    for(int i=0;i<g->qntMotoristas;i++)
    {
        if(ComparaCnpjMotorista(g->motoristas[i],cnpj))
        {
            return g->motoristas[i];
        }
    }

    return NULL;
}

void CadastrarVeiculo(tGerenciador* g)
{
    char cnpj[MAX_CNPJ];
    scanf("%s",cnpj);

    tMotorista* driver = BuscarMotoristaGerenciador(g, cnpj);

    if(driver==NULL) //verifica se cnpj existe
        {
            printf("CONDUTOR SEM CADASTRO!\n");
            return;
        }

    char tipoVeiculo;
    scanf(" %c; ",&tipoVeiculo);

    char linha[1000];
    scanf(" %[^\n]",linha);

    

    if(tipoVeiculo=='C')
    {
        tCarro* car = criaCarro(linha);
        tVeiculo* data = criaVeiculo(car,getAnoCarro,getCodCarro,getNotaMediaCarro,getNomeCarro,getAssentosCarro,getKmCarro,getMarcaCarro,printaCarro,getRestricaoAssinaturaCarro,getLetraTipoCarro,getRestricaoIdadeCarro,liberaCarro);
        
        //verifica se veiculo ja esta cadastrado
        
            char* placa = getCodVeiculo(data);
            int flag = 0;
            
           
            for(int i = 0;i<g->qntMotoristas;i++)
            {
                 tVeiculo* dataS = BuscaVeiculoemMotorista(g->motoristas[i],placa);

                 if(dataS != NULL)
                 {
                    flag = 1;
                    break;
                 }
            }

                if(flag)
                {
                    printf("VEICULO JA CADASTRADO! OPERACAO NAO PERMITIDA!\n");
                    liberaVeiculo(data);
                    return;
                }

                AdicionaVeiculoEmMotorista(driver,data);
                printf("VEICULO CADASTRADO COM SUCESSO!\n");
        
    }
    else if(tipoVeiculo=='M')
    {
        tMoto* moto = criaMoto(linha);
        tVeiculo* data = criaVeiculo(moto,getAnoMoto,getCodMoto,getNotaMediaMoto,getNomeMoto,getAssentosMoto,getKmMoto,getMarcaMoto,printaMoto,getRestricaoAssinaturaMoto,getLetraTipoMoto,getRestricaoIdadeMoto,liberaMoto);


         char* placa = getCodVeiculo(data);
            int flag = 0;
            
           
            for(int i = 0;i<g->qntMotoristas;i++)
            {
                 tVeiculo* dataS = BuscaVeiculoemMotorista(g->motoristas[i],placa);

                 if(dataS != NULL)
                 {
                    flag = 1;
                    break;
                 }
            }

                if(flag)
                {
                    printf("VEICULO JA CADASTRADO! OPERACAO NAO PERMITIDA!\n");
                    liberaVeiculo(data);
                    return;
                }

                AdicionaVeiculoEmMotorista(driver,data);
                printf("VEICULO CADASTRADO COM SUCESSO!\n");

    }
    else if(tipoVeiculo=='V')
    {
        tVan* van = criaVan(linha);
        tVeiculo* data = criaVeiculo(van,getAnoVan,getCodVan,getNotaMediaVan,getNomeVan,getAssentosVan,getKmVan,getMarcaVan,printaVan,getRestricaoAssinaturaVan,getLetraTipoVan,getRestricaoIdadeVan,liberaVan);

        char* placa = getCodVeiculo(data);
        int flag = 0;
            
        tVeiculo* dataS;
        int indice=-1;
           
            for(int i = 0;i<g->qntMotoristas;i++) //verifica se veiculo esta cadastrado no sistema
            {
                dataS = BuscaVeiculoemMotorista(g->motoristas[i],placa);

                 if(dataS != NULL)
                 {
                    indice = i;
                    flag = 1;
                    break;
                 }
            }

            if(flag) //se veiculo ja estiver cadastrado
            {
                
                if(ComparaCnpjMotorista(g->motoristas[indice],cnpj)) //checa se cnpj do motorista em posse do veiculo eh o msm que o digitado
                {
                    int assentos = getAssentosVeiculo(data);
                    atualizaNumeroAssentosVan(dataS,assentos);
                    liberaVeiculo(data);
                    printf("VAN ATUALIZADA COM SUCESSO!\n");
                    
                }
                else //caso nao for
                {
                    printf("CONDUTOR NAO PODE ALTERAR ESTE VEICULO!\n");
                    liberaVeiculo(data);
                    
                }

                return;
            }

            AdicionaVeiculoEmMotorista(driver,data);
            printf("VEICULO CADASTRADO COM SUCESSO!\n");
    }
}

void BuscaVeiculosGerenciador(tGerenciador* g, char* comando)

{
    char cpf[MAX_CPF+1];
    scanf("%s", cpf);

    char nome[MAX_NOME+1];
    scanf("%s", nome);

    int assentos;
    scanf("%d", &assentos);

    tUsuario* user = NULL;

    for(int i = 0; i < g->qntUsuarios; i++)
    {
        if(ComparaCpfUsuario(cpf, g->usuarios[i]))
        {
            user = g->usuarios[i];
            break;
        }
    }

    if(user == NULL)
    {
        printf("USUARIO SEM CADASTRO\n");
        return;
    }

    TipoUsuario restricaoUsuario = getRestricaoIdadeUsuario(user);

    // COMANDOS NORMAIS 
    int encontrou = 0;

    if(strcmp(comando,"COC")==0 ||
       strcmp(comando,"COM")==0 ||
       strcmp(comando,"COV")==0)
    {
        int indice = 1;
        

        printf("# - TIPO; ID; NOME; ASSENTOS; QUILOMETRAGEM; ANO; FABRICANTE; CONDUTOR; AVALIACAO MEDIA\n");

        for(int i = 0; i < g->qntMotoristas; i++)
        {
            OrdenarVeiculosPeloIdMotorista(g->motoristas[i]);

            for(int j=0;j<getQtdVeiculosMotorista(g->motoristas[i]);j++)
            {
                tVeiculo* v = BuscaNomeVeiculoemMotorista(g->motoristas[i], nome,j);

                if(v != NULL && getAssentosVeiculo(v) >= assentos)
                {
                    TipoUsuario restricaoVeiculo = getRestricaoIdadeVeiculo(v);

                    TipoAssinatura assinaturaVeiculo = getRestricaoAssinaturaVeiculo(v);

                    if(UsuarioPodeUsarVeiculo(restricaoUsuario,restricaoVeiculo) && assinaturaVeiculo == PADRAO)
                    {
                        printf("%d - ", indice);
                        indice++;

                        char tip = getTipoVeiculoLetra(v);
                        if(tip=='C')
                            printf("CARRO #%s; %s; ",getCodVeiculo(v),getNomeVeiculo(v));
                        else if(tip=='M')
                            printf("MOTO #%s; %s; ",getCodVeiculo(v),getNomeVeiculo(v));
                        else if(tip=='V')
                            printf("VAN #%s; %s; ",getCodVeiculo(v),getNomeVeiculo(v));

                        printf("%d; %.2f; %d; %s; %s (%s); ",
                           getAssentosVeiculo(v),
                           getKmVeiculo(v),
                           getAnoVeiculo(v),
                           getMarcaVeiculo(v),
                           getCnpjMotorista(g->motoristas[i]),
                           getNomeMotorista(g->motoristas[i]));
                           imprimeFloatBr2(getNotaMediaVeiculo(v));
                           printf("\n");

                        encontrou = 1;
                    }
                }
            }
        }

        if(!encontrou)
            printf("NENHUM VEICULO ENCONTRADO!\n");
    }

    /* COMANDOS PREMIUM */

    else if(strcmp(comando,"COCP")==0 ||
            strcmp(comando,"COMP")==0 ||
            strcmp(comando,"COVP")==0)
    {
        TipoAssinatura assinaturaUsuario =
            getRestricaoAssinaturaUsuario(user);

        if(assinaturaUsuario != PREMIUM)
        {
            printf("A CONTA DE CPF %s NAO POSSUI PERMISSAO PARA EXECUTAR ESSE COMANDO!\n",
                   cpf);
            return;
        }

        int indice = 1;
        int encontrou = 0;

        printf("# - TIPO; ID; NOME; ASSENTOS; QUILOMETRAGEM; ANO; FABRICANTE; CONDUTOR; AVALIACAO MEDIA\n");

        for(int i = 0; i < g->qntMotoristas; i++)
        {
            OrdenarVeiculosPeloIdMotorista(g->motoristas[i]);

            for(int j=0;j< getQtdVeiculosMotorista(g->motoristas[i]);j++)
            {
                tVeiculo* v = BuscaNomeVeiculoemMotorista(g->motoristas[i], nome,j);

                if(v != NULL && getAssentosVeiculo(v) >= assentos)
                {
                    TipoAssinatura assinaturaVeiculo = getRestricaoAssinaturaVeiculo(v);

                    if(assinaturaVeiculo == PREMIUM)
                    {
                        printf("%d - ", indice);
                        indice++;

                        char tip = getTipoVeiculoLetra(v);
                        if(tip=='C')
                        {
                            printf("CARRO #%s; %s; ",getCodVeiculo(v),getNomeVeiculo(v));
                        }
                        else if(tip=='M')
                        {
                            printf("MOTO #%s; %s; ",getCodVeiculo(v),getNomeVeiculo(v));
                        }
                        else if(tip=='V')
                        {
                            printf("VAN #%s; %s; ",getCodVeiculo(v),getNomeVeiculo(v));
                        }

                        printf("%d; %.2f; %d; %s; %s (%s); %.2f\n",
                           getAssentosVeiculo(v),
                           getKmVeiculo(v),
                           getAnoVeiculo(v),
                           getMarcaVeiculo(v),
                           getCnpjMotorista(g->motoristas[i]),
                           getNomeMotorista(g->motoristas[i]),
                           getNotaMediaVeiculo(v));

                        encontrou = 1;
                    }
                }
            }
        }

        if(!encontrou)
            printf("NENHUM VEICULO ENCONTRADO!\n");
    }

    // BUSCA POR CONDUTOR 

    else if(strcmp(comando,"COCD")==0)
    {
        int indice = 1;
        int encontrou = 0;

        printf("# - TIPO; ID; NOME; ASSENTOS; QUILOMETRAGEM; ANO; FABRICANTE; CONDUTOR; AVALIACAO MEDIA\n");

        for(int i = 0; i < g->qntMotoristas; i++)
        {
            if(strcmp(nome,
                      getNomeMotorista(g->motoristas[i])) == 0)
            {
                for(int j = 0;
                    j < getQtdVeiculosMotorista(g->motoristas[i]);
                    j++)
                {
                    tVeiculo* v =
                        getVeiculoMotorista(g->motoristas[i], j);

                    if(v != NULL &&
                       getAssentosVeiculo(v) >= assentos)
                    {
                        TipoAssinatura assinaturaVeiculo =
                            getRestricaoAssinaturaVeiculo(v);

                        TipoUsuario restricaoVeiculo =
                            getRestricaoIdadeVeiculo(v);

                        if(assinaturaVeiculo == PADRAO &&
                           UsuarioPodeUsarVeiculo(restricaoUsuario,restricaoVeiculo))
                        {
                            printf("%d - ", indice++);

                            char tip = getTipoVeiculoLetra(v);
                        if(tip=='C')
                        {
                            printf("CARRO #%s; %s; ",getCodVeiculo(v),getNomeVeiculo(v));
                        }
                        else if(tip=='M')
                        {
                            printf("MOTO #%s; %s; ",getCodVeiculo(v),getNomeVeiculo(v));
                        }
                        else if(tip=='V')
                        {
                            printf("VAN #%s; %s; ",getCodVeiculo(v),getNomeVeiculo(v));
                        }

                            printf("%d; %.2f; %d; %s; %s (%s); %.2f\n",
                                   getAssentosVeiculo(v),
                                   getKmVeiculo(v),
                                   getAnoVeiculo(v),
                                   getMarcaVeiculo(v),
                                   getCnpjMotorista(g->motoristas[i]),
                                   getNomeMotorista(g->motoristas[i]),
                                   getNotaMediaVeiculo(v));

                            encontrou = 1;
                        }
                    }
                }
            }
        }

        if(!encontrou)
            printf("NENHUM VEICULO ENCONTRADO!\n");
    }

    // BUSCA POR CONDUTOR PREMIUM 

    else if(strcmp(comando,"COCDP")==0)
    {
        TipoAssinatura assinaturaUsuario =
            getRestricaoAssinaturaUsuario(user);

        if(assinaturaUsuario != PREMIUM)
        {
            printf("A CONTA DE CPF %s NAO POSSUI PERMISSAO PARA EXECUTAR ESSE COMANDO!\n",
                   cpf);
            return;
        }

        int indice = 1;
        int encontrou = 0;

        printf("# - TIPO; ID; NOME; ASSENTOS; QUILOMETRAGEM; ANO; FABRICANTE; CONDUTOR; AVALIACAO MEDIA\n");

        for(int i = 0; i < g->qntMotoristas; i++)
        {
            if(strcmp(nome,
                      getNomeMotorista(g->motoristas[i])) == 0)
            {
                for(int j = 0;
                    j < getQtdVeiculosMotorista(g->motoristas[i]);
                    j++)
                {
                    tVeiculo* v =
                        getVeiculoMotorista(g->motoristas[i], j);

                    if(v != NULL &&
                       getAssentosVeiculo(v) >= assentos)
                    {
                        TipoAssinatura assinaturaVeiculo =
                            getRestricaoAssinaturaVeiculo(v);

                        TipoUsuario restricaoVeiculo =
                            getRestricaoIdadeVeiculo(v);

                        if(assinaturaVeiculo == PREMIUM &&
                           UsuarioPodeUsarVeiculo(restricaoUsuario,restricaoVeiculo))
                        {
                            printf("%d - ", indice++);

                            char tip = getTipoVeiculoLetra(v);
                        if(tip=='C')
                        {
                            printf("CARRO #%s; %s; ",getCodVeiculo(v),getNomeVeiculo(v));
                        }
                        else if(tip=='M')
                        {
                            printf("MOTO #%s; %s; ",getCodVeiculo(v),getNomeVeiculo(v));
                        }
                        else if(tip=='V')
                        {
                            printf("VAN #%s; %s; ",getCodVeiculo(v),getNomeVeiculo(v));
                        }

                            printf("%d; %.2f; %d; %s; %s (%s); %.2f\n",
                                   getAssentosVeiculo(v),
                                   getKmVeiculo(v),
                                   getAnoVeiculo(v),
                                   getMarcaVeiculo(v),
                                   getCnpjMotorista(g->motoristas[i]),
                                   getNomeMotorista(g->motoristas[i]),
                                   getNotaMediaVeiculo(v));

                            encontrou = 1;
                        }
                    }
                }
            }
        }

        if(!encontrou)
            printf("NENHUM VEICULO ENCONTRADO!\n");
    }
    else
    {
        printf("COMANDO INVALIDO\n");
    }
}

void ImprimirListaCorridasUsuario(tGerenciador* g,tUsuario* user)
{
    if(getQtdCorridasUsuario(user)==0)
    {
        printf("LISTA DE CORRIDAS VAZIA!\n");
         printf("(TOTAL ");
        imprimeDuracaoCorrida(getMinutosTotaisUsuario(user));
        printf(" horas)\n");
        return;
    }

    printf("LISTA DE CORRIDA:\n");

    int tempo = 0;
    for(int i = 0;i<getQtdCorridasUsuario(user);i++)
    {
        ImprimeCorrida(getCorridaUsuario(user,i),i+1);
        tempo += getTempoCorrida(getCorridaUsuario(user,i));
        
    }

    printf("(TOTAL ");
    imprimeDuracaoCorrida(tempo);
    printf(" horas)\n");

}

void RelatorioListaCorridasUsuario(tGerenciador* g)
{
    char cpf[MAX_CPF];
    scanf("%s",cpf);
    tUsuario* user = NULL;

    for(int i=0;i<g->qntUsuarios;i++)
    {
        if(ComparaCpfUsuario(cpf,g->usuarios[i]))
        {
            user = g->usuarios[i];
            break;
        }
            
    }

    if(user==NULL)
    {
        printf("CPF NAO CADASTRADO! OPERACAO NAO PERMITIDA!\n");
        return;
    }

    ImprimirListaCorridasUsuario(g,user);

    
}

void RealizacaoSelecaoCorridaUsuario(tGerenciador* g)
{
    char cpf[MAX_CPF+1];
    char cod[MAX_COD_VEICULO+1];
    scanf("%s %s",cpf,cod);
   


    char origem[MAX_ENDERECO+1];
    char destino[MAX_ENDERECO+1];
    int duracao;
    int assentos;

    scanf(" %[^\n]",origem);
    scanf(" %[^\n]",destino);
    scanf("%d",&duracao);
    scanf("%d",&assentos);

    tVeiculo* veic = NULL;

    tUsuario* user = NULL;

    for(int i=0;i<g->qntUsuarios;i++)
    {
        if(ComparaCpfUsuario(cpf,g->usuarios[i]))
        {
            user = g->usuarios[i];
            break;
        }
    }

    if(user==NULL)
    {
        printf("O USUARIO %s NAO ESTA CADASTRADO\n",cpf);
        return;
    }

    tMotorista* driver = NULL;
    for(int i=0;i<g->qntMotoristas;i++)
    {
        veic = BuscaVeiculoemMotorista(g->motoristas[i],cod);
         if(veic!=NULL)
         {
            driver = g->motoristas[i];
            break;
         }
            
    }

    if(veic==NULL)
    {
        printf("O VEICULO %s NAO ESTA CADASTRADO!\n",cod);
        ImprimirListaCorridasUsuario(g,user);
        return;
    }

    

    TipoUsuario idade = getRestricaoIdadeUsuario(user);
    TipoAssinatura assinatura = getRestricaoAssinaturaUsuario(user);
    TipoAssinatura assinVeic = getRestricaoAssinaturaVeiculo(veic);

    if(!UsuarioPodeUsarVeiculo(idade,getRestricaoIdadeVeiculo(veic)))
    {
        printf("NAO EH POSSIVEL ADICIONAR O VEICULO %s A CONTA INFANTIL DO CPF %s!\n",cod,getCartaoUsuario(user));
        ImprimirListaCorridasUsuario(g,user);
        return;
    }

    int assentosVeic = getAssentosVeiculo(veic);

    if(assentos>assentosVeic)
    {
        printf("O VEICULO %s NAO ADMITE A QUANTIDADE DE ASSENTOS REQUISITADA!\n",cod);
        ImprimirListaCorridasUsuario(g,user);
        return;
    }

    if(assinatura==PADRAO && assinVeic == PREMIUM)
    {
        printf("NAO EH POSSIVEL ADICIONAR O VEICULO PREMIUM %s A CONTA PADRAO DO CPF %s!\n",cod,cpf);
        ImprimirListaCorridasUsuario(g,user);
        return;
    }

    tData* data = CriaData(10,5,2026);
    tCorrida* c = CriaCorrida(veic,driver,duracao,origem,destino,data,assentos);

    AdicionaCorridaUsuario(user,c);
    ImprimirListaCorridasUsuario(g,user);
}

void RemoveCorridasLista(tGerenciador* g)
{
    char cpf[MAX_CPF];
    char cod[MAX_COD_VEICULO];
    scanf("%s",cpf);
    scanf("%s",cod);

    tVeiculo* veiculo = NULL;
    tUsuario* user = NULL;

    for(int i=0;i<g->qntUsuarios;i++)
    {
        if(ComparaCpfUsuario(cpf,g->usuarios[i]))
        {
            user = g->usuarios[i];
            break;
        }
    }

    if(user==NULL)
    {
        printf("O USUARIO %s NAO ESTA CADASTRADO!\n",cpf);
        return;
    }

    for(int i=0;i<g->qntMotoristas;i++)
    {
        veiculo = BuscaVeiculoemMotorista(g->motoristas[i],cod);
        if(veiculo!=NULL)
            break;
    }

    if(veiculo==NULL)
    {
        printf("O VEICULO NAO ESTA CADASTRADO!\n");
        ImprimirListaCorridasUsuario(g,user);
        return;
    }

    if(VerificaVeiculoExisteCorridaUsuario(user,cod))
    {
        printf("O VEICULO %s FOI REMOVIDO DA LISTA DE CORRIDAS DO USUARIO %s!\n",cod,cpf);
        RemoveCorridaUsuario(user,cod,0);
        ImprimirListaCorridasUsuario(g,user);
        return;
    }
    else
    {
        printf("O VEICULO NAO ESTA PRESENTE NA LISTA DE CORRIDAS DO USUARIO %s!\n",cpf);
        ImprimirListaCorridasUsuario(g,user);
        return;
    }
}

void RealizarCorridaeAvaliar(tGerenciador* g)
{
    char cpf[MAX_CPF];
    scanf("%s",cpf);

    tUsuario* user = NULL;
    for(int i=0;i<g->qntUsuarios;i++)
    {
        if(ComparaCpfUsuario(cpf,g->usuarios[i]))
        {
            user = g->usuarios[i];
            break;
        }
    }

    if(user == NULL)
    {
        printf("CPF NAO CADASTRADO! OPERACAO NAO PERMITIDA!\n");
        return;
    }

    if(getQtdCorridasUsuario(user)==0)
    {
        printf("LISTA DO USUARIO %s ESTA VAZIA! OPERACAO NAO PERMITIDA!\n",cpf);
        return;
    }

    tCorrida* realizar = getCorridaUsuario(user,0);
    tMotorista* motoristaCorrida = getMotoristaCorrida(realizar);
    tVeiculo* veicCorrida = getVeiculoCorrida(realizar);

    char* codVeicCorr = getCodVeiculo(veicCorrida);

    printf("CORRIDA %s REALIZADA POR %s DE %s ATE %s FOI CONSUMIDA PELO USUARIO %s!\n",codVeicCorr,
        getNomeMotorista(motoristaCorrida),getOrigemCorrida(realizar),getDestinoCorrida(realizar),cpf);

    if(getRestricaoIdadeUsuario(user)==ADULTO)
    {
        int nota;
        scanf("%d",&nota);

        if(nota>0&&nota<6)
        {

            tAvaliacao* aval = criaAvaliacao(cpf,nota);
            inserirAvaliacaoVeiculo(veicCorrida,aval);
            IncrementarNumeroAvaliacoesUsuario(user);
            printf("CORRIDA %s AVALIADA COM NOTA %d!\n",codVeicCorr,nota);
        }
        
    }
    IncrementarServicosUsuario(user);
    int tempo = getTempoCorrida(realizar);
    IncrementarMinutosGastosUsuario(user,tempo);

    RemoveCorridaUsuario(user,codVeicCorr,1);
}

//CORRIDA <#ID_VEICULO> REALIZADA POR <NOME_CONDUTOR> DE <ORIGEM> ATE <DESTINO> FOI CONSUMIDA PELO USUARIO #CPF!

void GerarRelatorioUsuario(tGerenciador* g)
{
    char cpf[MAX_CPF];
    scanf("%s",cpf);
    tUsuario* user = NULL;
    for(int i = 0;i<g->qntUsuarios;i++)
    {
        if(ComparaCpfUsuario(cpf,g->usuarios[i]))
        {
            user = g->usuarios[i];
            break;
        }
    }

    if(user==NULL)
    {
        printf("CPF NAO CADASTRADO! OPERACAO NAO PERMITIDA!\n");
        return;
    }

    char* senha = getSenhaUsuario(user);
    char senhaDigitada[MAX_SENHA];
    scanf("%s",senhaDigitada);

    if(strcmp(senha,senhaDigitada)!=0)
    {
        printf("SENHA INCORRETA! OPERACAO NAO PERMITIDA!\n");
        return;
    }

    for(int i=0;senhaDigitada[i]!='\0';i++)
        senhaDigitada[i] = '*';

    printf("RELATORIO USUARIO DE CPF %s\n",getCpfUsuario(user));
    printf("NOME: %s\n",getNomeUsuario(user));
    printf("TELEFONE: %s\n",getTelefoneUsuario(user));
    printf("ENDERECO: %s\n",getEnderecoUsuario(user));
    printf("NOME DE USUARIO: %s\n",getUserUsuario(user));
    printf("SENHA: %s\n",senhaDigitada);
    printf("EMAIL: %s\n",getEmailUsuario(user));
    printf("DATA NASCIMENTO: ");
    ImprimeData(getNascimentoUsuario(user));
    printf("\n");
    printf("NUM. CORRIDAS REALIZADAS: %d\n",getCorridasRealizadasUsuario(user));
    printf("TOTAL HORAS PERCORRIDAS ");
    imprimeDuracaoCorrida(getMinutosTotaisUsuario(user));
    printf("\n");
    printf("NUM. AVALIACOES REALIZADAS: %d\n",getNumAvaliacoesFeitasUsuario(user));
    printf("USUARIO ");
    TipoUsuario idade = getRestricaoIdadeUsuario(user);
    TipoAssinatura assinatura = getRestricaoAssinaturaUsuario(user);
    if(idade==ADULTO)
    
        printf("18+ ");
      
    else
        printf("INFANTIL ");
    
    if(assinatura==PADRAO)
        printf("PADRAO\n");
    else
        printf("PREMIUM\n");

    if(idade==ADULTO)
        printf("CARTAO NUM.: %s\n",getCartaoUsuario(user));
    else
        printf("CPF RESPONSAVEL: %s\n",getCartaoUsuario(user));

    ImprimirListaCorridasUsuario(g,user);

    ImprimeCorridasRealizadasUsuario(user);

}

/*
RELATORIO USUARIO DE CPF 111.111.111-11
NOME: PEDRO DA SILVA
TELEFONE: (00)0000-0000
ENDERECO: RUA CURVA DE RIO
NOME DE USUARIO: CLIENTE_PEDRO
SENHA: *********
EMAIL: pedroDaSilva@ufoodes.com
DATA NASCIMENTO: 01/01/2001
NUM. CORRIDAS REALIZADAS: 1
TOTAL HORAS PERCORRIDAS: 0:27
NUM. AVALIACOES REALIZADAS: 1
USUARIO 18+ PADRAO
CARTAO NUM.: 555555555555
LISTA DE CORRIDAS VAZIA!
(TOTAL 0:00 horas)
LISTA DE CORRIDAS REALIZADAS:
1 - CARRO #ABCDEF123; GOL G5; 00:27; AVENIDA FERNANDO FERRARRI 001;
AVENIDA DANTE MICHELIN 002; 10/04/2025; 2
(TOTAL 0:27 horas)
*/


void GerarRelatorioVeiculos(tGerenciador* g)
{
    char cpf[MAX_CPF];
    scanf("%s",cpf);

    tUsuario* user = NULL;
    for(int i=0;i<g->qntUsuarios;i++)
    {
        if(ComparaCpfUsuario(cpf,g->usuarios[i]))
        {
            user = g->usuarios[i];
            break;
        }
    }

    if(user==NULL)
    {
        printf("O USUARIO NAO ESTA CADASTRADO\n");
        return;
    }

    int totalVeic = 0;
    for(int i=0;i<g->qntMotoristas;i++)
    {
        totalVeic+= getQtdVeiculosMotorista(g->motoristas[i]);
    }

    printf("RELATORIO GERAL DE VEICULOS\n");
    if(totalVeic==0)
    {
        printf("NENHUM VEICULO ENCONTRADO!\n");
        return;
    }

    int indice = 1;
    for(int i=0;i<g->qntMotoristas;i++)
    {
        indice = ImprimeVeiculosMotorista(g->motoristas[i],indice,getRestricaoAssinaturaUsuario(user),getRestricaoIdadeUsuario(user));
    }
}

void GerarRelatorioAvaliacao(tGerenciador* g)
{
    char cpf[MAX_CPF];
    scanf("%s",cpf);

    char id[MAX_COD_VEICULO];
    scanf("%s",id);

    tUsuario* user = NULL;
    for(int i=0;i<g->qntUsuarios;i++)
    {
        if(ComparaCpfUsuario(cpf,g->usuarios[i]))
        {
            user = g->usuarios[i];
            break;
        }
    }

    if(user==NULL)
    {
        printf("CPF NAO CADASTRADO! OPERACAO NAO PERMITIDA!\n");
        return;
    }

    tVeiculo* veiculo = NULL;
    int indiceMotorista = -1;

    for(int i=0;i<g->qntMotoristas;i++)
    {
        veiculo = BuscaVeiculoemMotorista(g->motoristas[i],id);
        if(veiculo!=NULL)
        {
            indiceMotorista = i;
            break;
        }
    }

    if(veiculo==NULL)
    {
        printf("NENHUM VEICULO ENCONTRADO!\n");
        return;
    }

    TipoAssinatura au = getRestricaoAssinaturaUsuario(user);
    TipoAssinatura av = getRestricaoAssinaturaVeiculo(veiculo);

    if(au==PADRAO&&av==PREMIUM)
    {
        printf("USUARIO DE CPF %s NAO TEM ACESSO AO VEICULO %s! OPERACAO NAO PERMITIDA\n",cpf,id);
        return;
    }

    printf("LISTA DE AVALIACOES DO VEICULO %s - %s - CONDUTOR %s (%s): %.1f\n",getCodVeiculo(veiculo),
    getNomeVeiculo(veiculo),getCnpjMotorista(g->motoristas[indiceMotorista]),getNomeMotorista(g->motoristas[indiceMotorista]),getNotaMediaVeiculo(veiculo));

    for(int i=0;i<getQtdAvaliacoesVeiculo(veiculo);i++)
    {
        tAvaliacao* temp = getAvaliacaoPosicaoVeiculo(veiculo,i);
        char* cpfP = getCpfAvaliacao(temp);
        char* nome;

        for(int j=0;j<g->qntUsuarios;j++)
        {
            if(ComparaCpfUsuario(cpfP,g->usuarios[j]))
            {
                nome = getNomeUsuario(g->usuarios[j]);
                break;
            }
        }
        printf("%d - %s - %d\n",i+1,nome,getNotaAvaliacao(temp));
    }
    

}