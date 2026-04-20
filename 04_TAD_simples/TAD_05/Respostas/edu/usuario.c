#include <stdio.h>
#include <string.h>
#include "usuario.h"

/**
 * @brief Cria um novo usuário.
 * @param nome Nome do usuário.
 * @param cpf CPF do usuário.
 * @return O novo usuário criado.
 */
tUsuario CriaUsuario(char nome[20], char cpf[15])
{
    tUsuario u;
    strcpy(u.cpf,cpf);
    strcpy(u.nome,nome);

    return u;
}

/**
 * @brief Imprime os dados de um usuário.
 * @param user Usuário a ser impresso.
 */
void ImprimeUsuario(tUsuario user)
{
    printf("Nome: %s\n",user.nome);
    printf("CPF: %s\n",user.cpf);
}