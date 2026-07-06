#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_contato.h"
#include "contato.h"
#include "vector.h"

struct ListaContato {
    Vector *contatos;
};

tListaContato *CriarListaContato() {
    tListaContato *l = (tListaContato *) calloc(1, sizeof(tListaContato));
    if (l == NULL)
        exit(printf("Erro ao alocar memoria para a lista de contatos.\n"));

    l->contatos = VectorConstruct();
    return l;
}

void DestruirListaContato(tListaContato *l) {
    VectorDestroy(l->contatos, (DataType)DestruirContato);
    free(l);
}

void AdicionarContatoListaContato(tListaContato *l, tContato *contato) {
    for (int i = 0; i < VectorSize(l->contatos); i++) {
        tContato *c = VectorGet(l->contatos, i); 
        if (ComparaTelefoneContato(c, contato) || ComparaNomeContato(c, contato)) {
            DestruirContato(contato);
            printf("\nJa existe um contato com esse nome e/ou numero de telefone\n");
            return;
        }
    }
    VectorPushBack(l->contatos, contato);
}

void CarregarListaContato(tListaContato *l, char* nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "rb");
    
    if(arquivo == NULL) 
        return; //Arquivo binario não foi criado. Dessa forma retorna para o menu principal. Útil para o primeiro caso de teste, pois a lista está vazia.
            
    int quantidade;
    fread(&quantidade, sizeof(int), 1, arquivo);

    for(int i = 0; i < quantidade; i++) {
        tContato *contato = CarregarContato(arquivo);
        AdicionarContatoListaContato(l, contato);
    }
    fclose(arquivo);
}

void SalvarListaContato(tListaContato *l, char* nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "wb");
    if(arquivo == NULL)
        exit(printf("Erro ao abrir arquivo %s.\n", nomeArquivo));

    int quantidade = VectorSize(l->contatos);
    fwrite(&quantidade, sizeof(int), 1, arquivo);

    for (int i = 0; i < quantidade; i++) {
        SalvarContato((tContato *)VectorGet(l->contatos, i), arquivo);
    }
    fclose(arquivo);
}

void BuscarPorNumeroTelefoneListaContato(tListaContato *l) {
    unsigned long int telefone;

    scanf("\n%lu", &telefone);

    for (int i = 0; i < VectorSize(l->contatos); i++) {
        tContato *c = (tContato *) VectorGet(l->contatos, i);
        if (GetTelefoneContato(c) == telefone){
            ImprimirContato(c);
            return;
        }
    }

    printf("\nContato nao encontrado\n");
}

void BuscarPorNomeListaContato(tListaContato *l) {
    char nome[100];

    scanf("\n%s", nome);

    for (int i = 0; i < VectorSize(l->contatos); i++) {
        tContato *c = (tContato *) VectorGet(l->contatos, i);
        if (strcmp(GetNomeContato(c), nome) == 0) {
            ImprimirContato(c);
            return;
        }
    }
    
    printf("\nContato nao encontrado\n");
}

void ImprimirListaContato(tListaContato *l) {
    printf("\nLista de contatos cadastrados\n");
    for (int i = 0; i < VectorSize(l->contatos); i++) {
        tContato *c = (tContato *) VectorGet(l->contatos, i);
        ImprimirContato(c);
    }
}

void RemoverContatoListaContato(tListaContato *l) {
    unsigned long int telefone;
    scanf("\n%lu", &telefone);    

    for (int i = 0; i < VectorSize(l->contatos); i++) {
        tContato *c = (tContato *) VectorGet(l->contatos, i);
        if (GetTelefoneContato(c) == telefone){
            VectorRemove(l->contatos, i);
            DestruirContato(c);
            printf("\nContato removido com sucesso\n");
            return;
        }
    }
    printf("\nNao existe um contato cadastrado com esse numero de telefone\n");
}