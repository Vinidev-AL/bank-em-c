#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "destinador.h"
#include <locale.h>

int contador_conta_corrente;
int contador_conta_poupanca;
int contador_funcionario;
Funcionario conta_funcionario[100];


/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

//Contador de contas corrente

void carregar_contador_conta_corrente() {
    FILE *arquivo = fopen("contador_conta_corrente.bin", "rb");
    if (arquivo != NULL) {
        fread(&contador_conta_corrente, sizeof(int), 1, arquivo);
        fclose(arquivo);
    } else {
        contador_conta_corrente = 0; // Inicializa contador se o arquivo não existir
    }
}

void salvar_contador_conta_corrente() {
    FILE *arquivo = fopen("contador_conta_corrente.bin", "wb");
    if (arquivo != NULL) {
        fwrite(&contador_conta_corrente, sizeof(int), 1, arquivo);
        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para salvar o contador.\n");
    }
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

//Contador de contas poupança

void carregar_contador_conta_poupanca() {
    FILE *arquivo = fopen("contador_conta_poupanca.bin", "rb");
    if (arquivo != NULL) {
        fread(&contador_conta_poupanca, sizeof(int), 1, arquivo);
        fclose(arquivo);
    } else {
        contador_conta_poupanca = 0; // Inicializa contador se o arquivo não existir
    }
}

void salvar_contador_conta_poupanca() {
    FILE *arquivo = fopen("contador_conta_poupanca.bin", "wb");
    if (arquivo != NULL) {
        fwrite(&contador_conta_poupanca, sizeof(int), 1, arquivo);
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
        contador_funcionario = 0; // Inicializa contador se o arquivo não existir
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

void criar_conta_cliente_corrente(){
    Cliente conta;
    carregar_contador_conta_corrente();
    setlocale(LC_ALL, "portuguese");
    contador_conta_corrente++;
    
    //-------------------------------------------------------------------------------------------------------------------
	limpar_buffer();   
    limpar_tela();
    style_bank();
    printf("Digite a agência: ");
    fgets(conta.agencia, sizeof(conta.agencia), stdin);
    remover_nova_linha(conta.agencia);
    fflush(stdin);
    tabela_style();
    //-------------------------------------------------------------------------------------------------------------------
    printf("Numero da conta: %d\n", contador_conta_corrente);
    tabela_style();
    //-------------------------------------------------------------------------------------------------------------------
    printf("Digite o limite da conta: ");
    scanf("%f", &conta.limite);
    limpar_buffer();
    tabela_style();
    //-------------------------------------------------------------------------------------------------------------------
    printf("Data de vencimento da conta\n\n");
    tabela_style();
    printf("Dia: ");
    scanf("%d", &conta.vencimento.dia);
    limpar_buffer();
    tabela_style();
    printf("Mes: ");
    scanf("%d", &conta.vencimento.mes);
    limpar_buffer();
    tabela_style();
    printf("Ano - ex 0000: ");
    scanf("%d", &conta.vencimento.ano);
    limpar_buffer();
    tabela_style();
    //-------------------------------------------------------------------------------------------------------------------

    printf("Digite seu primeiro nome: ");
    fgets(conta.nome.nome, sizeof(conta.nome.nome), stdin);
    remover_nova_linha(conta.nome.nome);
    fflush(stdin);
    tabela_style();
    printf("Digite seu sobrenome: ");
    fgets(conta.nome.sobrenome, sizeof(conta.nome.sobrenome), stdin);
    remover_nova_linha(conta.nome.sobrenome);
    fflush(stdin);
    tabela_style();
    //-------------------------------------------------------------------------------------------------------------------

    printf("Digite seu CPF (so numeros): ");
    fgets(conta.cpf, sizeof(conta.cpf), stdin);
    remover_nova_linha(conta.cpf);
    fflush(stdin);
    tabela_style();
    //-------------------------------------------------------------------------------------------------------------------

    printf("Data de nascimento\n");
    tabela_style();
    
    printf("Dia: ");
    scanf("%d", &conta.nascimento.dia);
    limpar_buffer();
    tabela_style();
    printf("Mês: ");
    scanf("%d", &conta.nascimento.mes);
    limpar_buffer();
    tabela_style();
    printf("Ano - ex 0000: ");
    scanf("%d", &conta.nascimento.ano);
    limpar_buffer();
    tabela_style();
    //-------------------------------------------------------------------------------------------------------------------

    printf("Telefone\n\n");
    tabela_style();
    printf("DDD - exemplo 61: ");
    fgets(conta.telefone.DDD, sizeof(conta.telefone.DDD), stdin);
    remover_nova_linha(conta.telefone.DDD);
    fflush(stdin);
    tabela_style();
    printf("Numero - exemplo 000000000: ");
    fgets(conta.telefone.numero, sizeof(conta.telefone.numero), stdin);
    remover_nova_linha(conta.telefone.numero);
    fflush(stdin);
    tabela_style();
    //-------------------------------------------------------------------------------------------------------------------

    printf("Endereco\n\n");
    tabela_style();
    printf("Digite o CEP (sem pontos e tracos): ");
    fgets(conta.endereco.cep, sizeof(conta.endereco.cep), stdin);
    remover_nova_linha(conta.endereco.cep);
    fflush(stdin);
    tabela_style();
    printf("Digite o logradouro: ");
    fgets(conta.endereco.logradouro, sizeof(conta.endereco.logradouro), stdin);
    remover_nova_linha(conta.endereco.logradouro);
    fflush(stdin);
    tabela_style();
    printf("Digite o numero da casa: ");
    scanf("%d", &conta.endereco.n_casa);
    limpar_buffer();
    tabela_style();
    printf("Digite o nome do bairro: ");
    fgets(conta.endereco.bairro, sizeof(conta.endereco.bairro), stdin);
    remover_nova_linha(conta.endereco.bairro);
    fflush(stdin);
    tabela_style();
    printf("Digite o nome da cidade: ");
    fgets(conta.endereco.cidade, sizeof(conta.endereco.cidade), stdin);
    remover_nova_linha(conta.endereco.cidade);
    fflush(stdin);
    tabela_style();
    printf("Digite o nome do estado: ");
    fgets(conta.endereco.estado, sizeof(conta.endereco.estado), stdin);
    remover_nova_linha(conta.endereco.estado);
    fflush(stdin);
    tabela_style();
    printf("Crie sua senha: ");
    fgets(conta.senha, sizeof(conta.senha), stdin);
    fflush(stdin);
    remover_nova_linha(conta.senha);

    conta.n_conta = contador_conta_corrente;
    conta.saldo = 0;
    //-------------------------------------------------------------------------------------------------------------------
    limpar_tela();
    FILE *file = fopen("contas_corrente.bin", "ab");
    
    if (file != NULL) {
        fwrite(&conta, sizeof(Cliente), 1, file);
        fclose(file);
    } else {
        tabela_style();
        printf("Erro ao abrir o arquivo para salvar a conta.\n");
    }

    salvar_contador_conta_corrente();

    tabela_style();
    printf("Conta criada com sucesso!!!\n\n");
    system("pause");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////

void criar_conta_cliente_poupanca(){
    Cliente conta;
    carregar_contador_conta_poupanca();
    setlocale(LC_ALL, "portuguese");
    contador_conta_corrente++;
    
    //-------------------------------------------------------------------------------------------------------------------
	limpar_buffer();   
    limpar_tela();
    style_bank();
    printf("Digite a agência: ");
    fgets(conta.agencia, sizeof(conta.agencia), stdin);
    remover_nova_linha(conta.agencia);
    fflush(stdin);
    tabela_style();
    //-------------------------------------------------------------------------------------------------------------------
    printf("Numero da conta: %d\n", contador_conta_poupanca);
    tabela_style();
    //-------------------------------------------------------------------------------------------------------------------
    printf("Digite seu primeiro nome: ");
    fgets(conta.nome.nome, sizeof(conta.nome.nome), stdin);
    remover_nova_linha(conta.nome.nome);
    fflush(stdin);
    tabela_style();
    printf("Digite seu sobrenome: ");
    fgets(conta.nome.sobrenome, sizeof(conta.nome.sobrenome), stdin);
    remover_nova_linha(conta.nome.sobrenome);
    fflush(stdin);
    tabela_style();
    //-------------------------------------------------------------------------------------------------------------------

    printf("Digite seu CPF (so numeros): ");
    fgets(conta.cpf, sizeof(conta.cpf), stdin);
    remover_nova_linha(conta.cpf);
    fflush(stdin);
    tabela_style();
    //-------------------------------------------------------------------------------------------------------------------

    printf("Data de nascimento\n");
    tabela_style();
    
    printf("Dia: ");
    scanf("%d", &conta.nascimento.dia);
    limpar_buffer();
    tabela_style();
    printf("Mês: ");
    scanf("%d", &conta.nascimento.mes);
    limpar_buffer();
    tabela_style();
    printf("Ano - ex 0000: ");
    scanf("%d", &conta.nascimento.ano);
    limpar_buffer();
    tabela_style();
    //-------------------------------------------------------------------------------------------------------------------

    printf("Telefone\n\n");
    tabela_style();
    printf("DDD - exemplo 61: ");
    fgets(conta.telefone.DDD, sizeof(conta.telefone.DDD), stdin);
    remover_nova_linha(conta.telefone.DDD);
    fflush(stdin);
    tabela_style();
    printf("Numero - exemplo 000000000: ");
    fgets(conta.telefone.numero, sizeof(conta.telefone.numero), stdin);
    remover_nova_linha(conta.telefone.numero);
    fflush(stdin);
    tabela_style();
    //-------------------------------------------------------------------------------------------------------------------
    printf("Endereco\n\n");
    tabela_style();
    printf("Digite o CEP (sem pontos e tracos): ");
    fgets(conta.endereco.cep, sizeof(conta.endereco.cep), stdin);
    remover_nova_linha(conta.endereco.cep);
    fflush(stdin);
    tabela_style();
    printf("Digite o logradouro: ");
    fgets(conta.endereco.logradouro, sizeof(conta.endereco.logradouro), stdin);
    remover_nova_linha(conta.endereco.logradouro);
    fflush(stdin);
    tabela_style();
    printf("Digite o numero da casa: ");
    scanf("%d", &conta.endereco.n_casa);
    limpar_buffer();
    tabela_style();
    printf("Digite o nome do bairro: ");
    fgets(conta.endereco.bairro, sizeof(conta.endereco.bairro), stdin);
    remover_nova_linha(conta.endereco.bairro);
    fflush(stdin);
    tabela_style();
    printf("Digite o nome da cidade: ");
    fgets(conta.endereco.cidade, sizeof(conta.endereco.cidade), stdin);
    remover_nova_linha(conta.endereco.cidade);
    fflush(stdin);
    tabela_style();
    printf("Digite o nome do estado: ");
    fgets(conta.endereco.estado, sizeof(conta.endereco.estado), stdin);
    remover_nova_linha(conta.endereco.estado);
    fflush(stdin);
    tabela_style();
    printf("Crie sua senha: ");
    fgets(conta.senha, sizeof(conta.senha), stdin);
    remover_nova_linha(conta.senha);
    fflush(stdin);

    conta.n_conta = contador_conta_corrente;
    conta.saldo = 0;
    //-------------------------------------------------------------------------------------------------------------------
    limpar_tela();
    FILE *file = fopen("contas_poupanca.bin", "ab");
    
    if (file != NULL) {
        fwrite(&conta, sizeof(Cliente), 1, file);
        fclose(file);
    } else {
        tabela_style();
        printf("Erro ao abrir o arquivo para salvar a conta.\n");
    }

    salvar_contador_conta_poupanca();

    tabela_style();
    printf("Conta criada com sucesso!!!\n\n");
    system("pause");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
void criar_conta_funcionario(){
	Funcionario conta;
    carregar_contador_funcionario();
    setlocale(LC_ALL, "portuguese");
    contador_funcionario++;
    
    //-------------------------------------------------------------------------------------------------------------------
	limpar_buffer();   
    limpar_tela();
    style_bank();

    printf("Digite o cargo do funcionário: ");
    fgets(conta.cargo, sizeof(conta.cargo), stdin);
    remover_nova_linha(conta.cargo);
    fflush(stdin);

    tabela_style();
    //-------------------------------------------------------------------------------------------------------------------
    printf("Código do funcionario: %d\n", contador_funcionario);
    //-------------------------------------------------------------------------------------------------------------------
    //-------------------------------------------------------------------------------------------------------------------
    tabela_style();
    printf("Digite o primeiro nome: ");
    fgets(conta.nome.nome, sizeof(conta.nome.nome), stdin);
    remover_nova_linha(conta.nome.nome);
    fflush(stdin);
    tabela_style();
    printf("Digite o sobrenome: ");
    fgets(conta.nome.sobrenome, sizeof(conta.nome.sobrenome), stdin);
    remover_nova_linha(conta.nome.sobrenome);
    fflush(stdin);
    //-------------------------------------------------------------------------------------------------------------------

    tabela_style();
    printf("Digite seu CPF (so numeros): ");
    fgets(conta.cpf, sizeof(conta.cpf), stdin);
    remover_nova_linha(conta.cpf);
    fflush(stdin);
    //-------------------------------------------------------------------------------------------------------------------

    tabela_style();
    printf("Data de nascimento\n");
    tabela_style();
    printf("Dia: ");
    scanf("%d", &conta.nascimento.dia);
    limpar_buffer();
    tabela_style();
    printf("Mês: ");
    scanf("%d", &conta.nascimento.mes);
    limpar_buffer();
    tabela_style();
    printf("Ano - ex 0000: ");
    scanf("%d", &conta.nascimento.ano);
    limpar_buffer();
    //-------------------------------------------------------------------------------------------------------------------

    tabela_style();
    printf("Telefone\n\n");
    tabela_style();
    printf("DDD - exemplo 61: ");
    fgets(conta.telefone.DDD, sizeof(conta.telefone.DDD), stdin);
    remover_nova_linha(conta.telefone.DDD);
    fflush(stdin);
    tabela_style();
    printf("Numero - exemplo 000000000: ");
    fgets(conta.telefone.numero, sizeof(conta.telefone.numero), stdin);
    remover_nova_linha(conta.telefone.numero);
    fflush(stdin);
    tabela_style();
    //-------------------------------------------------------------------------------------------------------------------
    limpar_buffer();
    printf("Endereco\n\n");
    tabela_style();
    printf("Digite o CEP (sem pontos e tracos): ");
    fgets(conta.endereco.cep, sizeof(conta.endereco.cep), stdin);
    remover_nova_linha(conta.endereco.cep);
    fflush(stdin);
    tabela_style();
    printf("Digite o logradouro: ");
    fgets(conta.endereco.logradouro, sizeof(conta.endereco.logradouro), stdin);
    remover_nova_linha(conta.endereco.logradouro);
    fflush(stdin);
    tabela_style();
    printf("Digite o numero da casa: ");
    scanf("%d", &conta.endereco.n_casa);
    limpar_buffer();
    fflush(stdin);
    tabela_style();
    printf("Digite o nome do bairro: ");
    fgets(conta.endereco.bairro, sizeof(conta.endereco.bairro), stdin);
    remover_nova_linha(conta.endereco.bairro);
    fflush(stdin);
    tabela_style();
    printf("Digite o nome da cidade: ");
    fgets(conta.endereco.cidade, sizeof(conta.endereco.cidade), stdin);
    remover_nova_linha(conta.endereco.cidade);
    fflush(stdin);
    tabela_style();
    printf("Digite o nome do estado: ");
    fgets(conta.endereco.estado, sizeof(conta.endereco.estado), stdin);
    remover_nova_linha(conta.endereco.estado);
    fflush(stdin);
    
    tabela_style();
    printf("Crie a senh do funcionário: ");
    fgets(conta.senha, sizeof(conta.senha), stdin);
    remover_nova_linha(conta.senha);
    fflush(stdin);

    conta.codigo = contador_funcionario;
    //-------------------------------------------------------------------------------------------------------------------
    limpar_tela();
    FILE *file = fopen("contas_funcionario.bin", "ab");

    if (file != NULL) {
        fwrite(&conta, sizeof(Funcionario), 1, file);
        fclose(file);
    } else {
        tabela_style();
        printf("Erro ao abrir o arquivo para salvar a conta.\n");
    }

    salvar_contador_funcionario();


    tabela_style();
    printf("Conta criada com sucesso!!!\n\n");

    tabela_style();
    system("pause");
}
	


void excluir_conta_cliente(){

}

void excluir_conta_funcionario(){

}



