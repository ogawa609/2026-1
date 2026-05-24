#include <stdio.h>
#include <stdlib.h>
#include "empresa.h"



/**
 * @brief Cria uma empresa "vazia"
 * 
 * Seus atributos devem ser inicializados com NULL (ponteiros), ou -1 caso contrário
 * @return TEmpresa* Ponteiro para empresa criada a partir do Id fornecido.
 */
tEmpresa* CriaEmpresa()
{
    tEmpresa* e = malloc(sizeof(tEmpresa));
    e->qtdFuncionarios=0;
    e->funcionarios = NULL;

    return e;
}

/**
 * @brief Le os dados de uma empresa da entrada padrao.
 * @param *empresa - ponteiro para empresa que terá seus dados preenchidos
 */
void LeEmpresa(tEmpresa* empresa)
{
    int id, fun;
    scanf("%d %d",&id,&fun);

    empresa->funcionarios = malloc(fun*sizeof(tFuncionario*));
    empresa->id = id;
    
    

    for(int i=0;i<fun;i++)
    {
        int check = 1;
        tFuncionario* temp = CriaFuncionario();
        LeFuncionario(temp);

        for(int j=0;j<empresa->qtdFuncionarios;j++)
        {
             if(GetIdFuncionario(temp)==GetIdFuncionario(empresa->funcionarios[j]))
             {
                 printf("A empresa %d ja possui um funcionario com o id %d\n",empresa->id,GetIdFuncionario(temp));
                 ApagaFuncionario(temp);
                 check = 0;
                 break;
             }
        }

        if(check)
        {

            empresa->funcionarios[empresa->qtdFuncionarios] = temp;
            empresa->qtdFuncionarios++;
        }

    }
}

/**
 * @brief Libera toda a memória alocada dinamicamente para uma empresa
 * @param *empresa - ponteiro para empresa que terá seus dados apagados e memória liberada
 */
void ApagaEmpresa(tEmpresa* empresa)
{
    for(int i=0;i<empresa->qtdFuncionarios;i++)
    {
        ApagaFuncionario(empresa->funcionarios[i]);
    }

    free(empresa->funcionarios);
    free(empresa);
}


/**
 * @brief Adiciona um funcionario a uma empresa caso o id do funcionario ainda nao esteja registrado na empresa.
 * 
 * @param empresa Ponteiro para Empresa em que o funcionario deve ser adicionado.
 * @param funcionario Ponteiro para Funcionario que deve ser adicionado a empresa.
  */
void ContrataFuncionarioEmpresa(tEmpresa* empresa, tFuncionario* funcionario)
{
    int check = 1;
    for(int i= 0;i<empresa->qtdFuncionarios;i++)
    {
        if(GetIdFuncionario(empresa->funcionarios[i])==GetIdFuncionario(funcionario))
            check = 0;
    }

    if(check)
    {
        printf("A empresa %d ja possui um funcionario com o id %d\n",empresa->id,GetIdFuncionario(funcionario));
        ApagaFuncionario(funcionario);
        return;
    }

    empresa->qtdFuncionarios++;
    empresa->funcionarios = realloc(empresa->funcionarios,(empresa->qtdFuncionarios+1)*sizeof(tFuncionario*));

    empresa->funcionarios[empresa->qtdFuncionarios] = funcionario;
    


}

/**
 * @brief Imprime todos os dados de um empresa.
 * 
 * @param empresa Ponteiro para Empresa a ser impressa no terminal.
 */
void ImprimeEmpresa(tEmpresa *empresa)
{
    printf("Empresa %d:\n",empresa->id);

    for(int i=0;i<empresa->qtdFuncionarios;i++)
        ImprimeFuncionario(empresa->funcionarios[i]);
}