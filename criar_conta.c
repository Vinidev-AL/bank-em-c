#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "destinador.h"
#include <locale.h>

int contador;
int contador_funcionario;
Funcionario conta_funcionario[100];


///////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////


void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

//Contador de contas clientes

void carregar_contador(int *contador) {
    FILE *arquivo = fopen("contador.bin", "rb");
    if (arquivo != NULL) {
        fread(&contador, sizeof(int), 1, arquivo);
        fclose(arquivo);
    } else {
        *contador = 0; // Inicializa contador se o arquivo não existir
    }
}

void salvar_contador(int contador) {
    FILE *arquivo = fopen("contador.bin", "wb");
    if (arquivo != NULL) {
        fwrite(&contador, sizeof(int), 1, arquivo);
        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para salvar o contador.\n");
    }
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

//Contador de contas funcionarios

void carregar_contador_funcionario() {
    FILE *arquivo = fopen("contador_funcionario.bin", "rb");
    if (arquivo != NULL) {
        fread(&contador_funcionario, sizeof(int), 1, arquivo);
        fclose(arquivo);
    } else {
        contador = 0; // Inicializa contador se o arquivo não existir
    }
}

void salvar_contador_funcionario() {
    FILE *arquivo = fopen("contador_funcionario.bin", "wb");
    if (arquivo != NULL) {
        fwrite(&contador_funcionario, sizeof(int), 1, arquivo);
        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para salvar o contador.\n");
    }
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

void criar_conta_cliente(){
    Cliente conta;
    limpar_tela();
    carregar_contador(&contador);
    setlocale(LC_ALL, "portuguese");
    contador++;
    limpar_buffer();
    //-------------------------------------------------------------------------------------------------------------------
    limpar_tela();
    printf("Digite o número da agência: ");
    fgets(conta.agencia, sizeof(conta.agencia), stdin);
    //-------------------------------------------------------------------------------------------------------------------
    printf("Numero da conta é: %d\n", contador);
    //-------------------------------------------------------------------------------------------------------------------
    printf("Digite o limite da conta: ");
    scanf("%f", &conta.limite);
    limpar_buffer();
    //-------------------------------------------------------------------------------------------------------------------
    printf("Data de vencimento da conta\n\n");
    printf("Dia: ");
    scanf("%d", &conta.vencimento.dia);
    limpar_buffer();
    printf("Mês: ");
    scanf("%d", &conta.vencimento.mes);
    limpar_buffer();
    printf("Ano - ex 0000: ");
    scanf("%d", &conta.vencimento.ano);
    limpar_buffer();
    //-------------------------------------------------------------------------------------------------------------------

    printf("Digite seu primeiro nome: ");
    fgets(conta.nome.nome, sizeof(conta.nome.nome), stdin);
    printf("Digite seu sobrenome: ");
    fgets(conta.nome.sobrenome, sizeof(conta.nome.sobrenome), stdin);
    //-------------------------------------------------------------------------------------------------------------------

    printf("Digite seu CPF (só numeros): ");
    fgets(conta.cpf, sizeof(conta.cpf), stdin);
    //-------------------------------------------------------------------------------------------------------------------

    printf("Data de nascimento\n\n");
    printf("Dia: ");
    scanf("%d", &conta.nascimento.dia);
    limpar_buffer();
    printf("Mês: ");
    scanf("%d", &conta.nascimento.mes);
    limpar_buffer();
    printf("Ano - ex 0000: ");
    scanf("%d", &conta.nascimento.ano);
    limpar_buffer();
    //-------------------------------------------------------------------------------------------------------------------

    printf("Telefone\n\n");
    printf("DDD - exemplo 61: ");
    fgets(conta.telefone.DDD, sizeof(conta.telefone.DDD), stdin);
    printf("Número - exemplo 000000000: ");
    fgets(conta.telefone.numero, sizeof(conta.telefone.numero), stdin);
    //-------------------------------------------------------------------------------------------------------------------

    printf("Endereço\n\n");
    printf("Digite o CEP (sem pontos e traços): ");
    fgets(conta.endereco.cep, sizeof(conta.endereco.cep), stdin);
    printf("Digite o logradouro: ");
    fgets(conta.endereco.logradouro, sizeof(conta.endereco.logradouro), stdin);
    printf("Digite o número da casa: ");
    scanf("%d", &conta.endereco.n_casa);
    limpar_buffer();
    printf("Digite o nome do bairro: ");
    fgets(conta.endereco.bairro, sizeof(conta.endereco.bairro), stdin);
    printf("Digite o nome da cidade: ");
    fgets(conta.endereco.cidade, sizeof(conta.endereco.cidade), stdin);
    printf("Digite o nome do estado: ");
    fgets(conta.endereco.estado, sizeof(conta.endereco.estado), stdin);
    printf("Crie sua senha: ");
    fgets(conta.senha, sizeof(conta.senha), stdin);

    conta.n_conta = contador;
    //-------------------------------------------------------------------------------------------------------------------
    limpar_tela();
    FILE *file = fopen("contas.bin", "ab");
    if (file != NULL) {
        fwrite(&conta, sizeof(Cliente), 1, file);
        fclose(file);
    } else {
        printf("Erro ao abrir o arquivo para salvar a conta.\n");
    }

    salvar_contador(contador);

    printf("Conta criada com sucesso!!!\n\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////

void criar_conta_funcionario(){

}

void excluir_conta_cliente(){

}

void excluir_conta_funcionario(){

}


