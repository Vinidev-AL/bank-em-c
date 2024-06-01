#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "destinador.h"



// Declaração da função verificarLogin
Cliente* verificarLogin(int conta, char *senha) {
    FILE *arquivo = fopen("contas.bin", "rb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return NULL;
    }

    Cliente *conta_cliente = (Cliente*) malloc(sizeof(Cliente));
    if (conta_cliente == NULL) {
        perror("Erro ao alocar memória");
        fclose(arquivo);
        return NULL;
    }

    while (fread(conta_cliente, sizeof(Cliente), 1, arquivo) == 1) {
        if (conta_cliente->n_conta == conta && strcmp(conta_cliente->senha, senha) == 0) {
            fclose(arquivo);
            return conta_cliente;
        }
    }

    fclose(arquivo);
    free(conta_cliente);
    return NULL;
}

// Função login_cliente utilizando verificarLogin
int login_cliente(int conta, char *password) {
    // Chama a função verificarLogin para tentar autenticar o cliente
    Cliente *cliente = verificarLogin(conta, password);

    if (cliente != NULL) {
        // Autenticação bem-sucedida
        free(cliente); // Liberar a memória alocada para cliente
        return 1;
    } else {
        // Autenticação falhou
        return 0;
    }
}
