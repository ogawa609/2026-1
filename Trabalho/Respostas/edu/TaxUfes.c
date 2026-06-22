#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TaxUfes.h"

#include "motorista.h"
#include "usuario.h"



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
    scanf(" %s",cnpj);

    char tipoVeiculo;
    scanf(" %c; ",&tipoVeiculo);

    char linha[1000];
    scanf(" %[^\n]",linha);

    tMotorista* driver = BuscarMotoristaGerenciador(g, cnpj);

    if(driver==NULL) //verifica se cnpj existe
        {
            printf("CONDUTOR SEM CADASTRO!\n");
            return;
        }

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

void BuscaVeiculosGerenciador(tGerenciador* g, char* comando) //Busca lista veiculos baseado no nome e numero de assentos
{

    char cpf[MAX_CPF];
    scanf("%s",cpf);

    char nome[MAX_NOME];
    scanf("%s",nome);

    int assentos;
    scanf("%d",&assentos);

    tUsuario* user = NULL; //ponteiro para usuario buscado

    for(int i=0;i<g->qntUsuarios;i++) //procura usuario cujo cpf foi lido
    {
        if(ComparaCpfUsuario(cpf,g->usuarios[i]))
        {
            user = g->usuarios[i];
            break;
        }
    }

    if(user==NULL) //caso cpf n tiver cadastrado
    {
        printf("USUARIO SEM CADASTRO\n");
        return;
    }

   

    if(strcmp(comando,"COC")==0 || strcmp(comando,"COM")==0 || strcmp(comando,"COV")==0)
    {
        int indice = 1;
        int flag = 1;
        int bancos = 0;

        printf("# - TIPO; ID; NOME; ASSENTOS; QUILOMETRAGEM; ANO; FABRICANTE; CONDUTOR; AVALIACAO MEDIA\n");

        for(int i = 0;i<g->qntMotoristas;i++)
        {
            tVeiculo* v = BuscaNomeVeiculoemMotorista(g->motoristas[i],nome);

            if(v!=NULL)
                 bancos = getAssentosVeiculo(v);
            
            
                if(bancos==assentos && v!=NULL)
                {
                    printf("%d - ",indice);
                    printaVeiculo(v);
                    float km = getKmVeiculo(v);
                    int ano = getAnoVeiculo(v);
                    char* fab = getMarcaVeiculo(v);
                    char* condutor = getNomeMotorista(g->motoristas[i]);
                    float nota = getNotaMediaVeiculo(v);
                    flag = 0;

                    printf("%d; %.2f; %d; %s; (%s); %.2f\n",assentos,km,ano,fab,condutor,nota);
                }
            
        }

        if(flag)
        {
            printf("NENHUM VEICULO ENCONTRADO!\n");
            return;
        }
    }
    else if(strcmp(comando,"COCP")==0 || strcmp(comando,"COMP")==0 || strcmp(comando,"COVP")==0)
    {

        TipoAssinatura* userVip = getRestricaoAssinaturaUsuario(user);

        if(userVip!=PREMIUM)
        {
            printf("A CONTA DE CPF %s NAO POSSUI PERMISSAO PARA EXECUTAR ESSE COMANDO!\n",cpf);
            return;
        }

        printf("# - TIPO; ID; NOME; ASSENTOS; QUILOMETRAGEM; ANO; FABRICANTE; CONDUTOR; AVALIACAO MEDIA\n");

        int indice = 1;
        int flag = 1;

        for(int i = 0;i<g->qntMotoristas;i++)
        {
            tVeiculo* v = BuscaNomeVeiculoemMotorista(g->motoristas[i],nome);

            if(v!=NULL)
            {
                int bancos = getAssentosVeiculo(v);
                TipoAssinatura* vip = getRestricaoAssinaturaVeiculo(v);
                
                if(bancos==assentos && vip==PREMIUM)
                {
                    printf("%d - ",indice);
                    printaVeiculo(v);
                    float km = getKmVeiculo(v);
                    int ano = getAnoVeiculo(v);
                    char* fab = getMarcaVeiculo(v);
                    char* condutor = getNomeMotorista(g->motoristas[i]);
                    float nota = getNotaMediaVeiculo(v);
                    flag = 0;

                    printf("%d; %.2f; %d; %s; %s; %.2f\n",assentos,km,ano,fab,condutor,nota);
                }


            }
            
        }

        if(flag)
        {
            printf("NENHUM VEICULO ENCONTRADO!\n");
            return;
        }
    }
   
    else if(strcmp(comando,"COCD")==0)
    {

    }
    else if(strcmp(comando,"COCDP")==0)
    {

    }
   
}