#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "destinador.h"

void verificar_conta(){
  int contan;
    printf("Digite o número da sua conta: ");
    scanf("%d", &contan);
    limpar_buffer();

    FILE *file = fopen("contas.bin", "rb");
    if (file == NULL) {
        printf("ERRO, ARQUIVO NÃO EXISTE\n");
        return;
    }

    Cliente conta;
    fseek(file, (contan - 1) * sizeof(Cliente), SEEK_SET);

    if (fread(&conta, sizeof(Cliente), 1, file) != 1) {
        if (feof(file)) {
            printf("ERRO, CONTA NÃO ENCONTRADA\n");
        } else {
            printf("ERRO AO LER A CONTA\n");
        }
        fclose(file);
        return;
    }

    fclose(file);

    printf("\nDados da conta:\n");
    printf("Agência: %s\n", conta.agencia);
    printf("Número da conta: %d\n", conta.n_conta);
    printf("Limite da conta: %.2f\n", conta.limite);
    printf("Data de vencimento: %02d/%02d/%04d\n", conta.vencimento.dia, conta.vencimento.mes, conta.vencimento.ano);
    printf("Nome: %s %s\n", conta.nome.nome, conta.nome.sobrenome);
    printf("CPF: %s\n", conta.cpf);
    printf("Data de nascimento: %02d/%02d/%04d\n", conta.nascimento.dia, conta.nascimento.mes, conta.nascimento.ano);
    printf("Telefone: (%s) %s\n", conta.telefone.DDD, conta.telefone.numero);
    printf("Endereço:\n");
    printf("CEP: %s\n", conta.endereco.cep);
    printf("Logradouro: %s\n", conta.endereco.logradouro);
    printf("Número da casa: %d\n", conta.endereco.n_casa);
    printf("Bairro: %s\n", conta.endereco.bairro);
    printf("Cidade: %s\n", conta.endereco.cidade);
    printf("Estado: %s\n", conta.endereco.estado);
    printf("Senha: %s\n", conta.senha);
}
