#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "destinador.h"
#include <locale.h>

int contador;
Cliente conta[500];


void scanner_fgets(char *buffer, int tamanho) {
    if (fgets(buffer, tamanho, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
    } else {
        buffer[0] = '\0';
    }
}

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void carregar_contador() {
    FILE *arquivo = fopen("contador.bin", "rb");
    if (arquivo != NULL) {
        fread(&contador, sizeof(int), 1, arquivo);
        fclose(arquivo);
    } else {
        contador = 0; // Inicializa contador se o arquivo não existir
    }
}

void salvar_contador() {
    FILE *arquivo = fopen("contador.bin", "wb");
    if (arquivo != NULL) {
        fwrite(&contador, sizeof(int), 1, arquivo);
        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para salvar o contador.\n");
    }
}


void criar_conta_cliente(){
    carregar_contador();
    setlocale(LC_ALL, "portuguese");
    contador++;
    printf("Digite o número da agência: ");
    scanf("%d", &conta[contador].agencia);
    limpar_buffer();
    printf("Numero da conta é: %d\n", contador + 1);
    printf("Digite o limite da conta: ");
    scanf("%f", &conta[contador].limite);
    limpar_buffer();
    printf("Data de vencimento da conta\n\n");
    printf("Dia: ");
    scanf("%d", &conta[contador].vencimento.dia);
    limpar_buffer();
    printf("Mês: ");
    scanf("%d", &conta[contador].vencimento.mes);
    limpar_buffer();
    printf("Ano - ex 0000: ");
    scanf("%d", &conta[contador].vencimento.ano);
    limpar_buffer();
    printf("Digite seu primeiro nome: ");
    scanf("%s", conta[contador].nome.nome);
    limpar_buffer();
    printf("Digite seu sobrenome: ");
    scanf("%s", conta[contador].nome.sobrenome);
    limpar_buffer();
    printf("Digite seu CPF (só numeros)");
    scanner_fgets(conta[contador].cpf, sizeof(conta[contador].cpf));
    limpar_buffer();
    printf("Data de nascimento\n\n");
    printf("Dia: ");
    scanf("%d", &conta[contador].nascimento.dia);
    limpar_buffer();
    printf("Mês: ");
    scanf("%d", &conta[contador].nascimento.mes);
    limpar_buffer();
    printf("Ano - ex 0000: ");
    scanf("%d", &conta[contador].nascimento.ano);
    limpar_buffer();
    printf("Telefone\n\n");
    printf("DDD -  exemplo 061: ");
    scanf("%d", &conta[contador].telefone.DDD);
    limpar_buffer();
    printf("Número - exemplo 000000000: ");
    scanf("%d", &conta[contador].telefone.numero);
    limpar_buffer();
    printf("Endereço\n\n");
    printf("Digite o CEP (sem pontos e traços): ");
    scanf("%d", &conta[contador].endereco.cep);
    limpar_buffer();
    printf("Digite o logradouro: ");
    scanner_fgets(conta[contador].endereco.logradouro, 100);
    limpar_buffer();
    printf("Digite o número da casa: ");
    scanf("%d", &conta[contador].endereco.n_casa);
    limpar_buffer();
    printf("Digite o nome do bairro: ");
    scanner_fgets(conta[contador].endereco.bairro, sizeof(conta[contador].endereco.bairro));
    limpar_buffer();
    printf("Digite o nome da cidade: ");
    scanner_fgets(conta[contador].endereco.cidade, sizeof(conta[contador].endereco.cidade));
    limpar_buffer();
    printf("Digite o nome do estado: ");
    scanner_fgets(conta[contador].endereco.estado, sizeof(conta[contador].endereco.estado));
    limpar_buffer();
    printf("Crie sua senha: ");
    scanner_fgets(conta[contador].senha, sizeof(conta[contador].senha));

    FILE *file;
    file = fopen("contas.bin", "ab");

    fwrite(&conta[contador], sizeof(Cliente), 1, file);

    salvar_contador();
}

void criar_conta_funcionario(){

}

void excluir_conta_cliente(){

}

void excluir_conta_funcionario(){

}
