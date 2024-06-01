#ifndef OPERACOES_H
#define OPERACOES_H

// funções

void menu_principal();
void criar_conta_funcionario();
void criar_conta_cliente();
void excluir_conta_funcionario();
void excluir_conta_cliente();
void menu_principal();
int login_cliente(int conta, char *password);
void scanner_fgets(char *buffer, int tamanho);



// structs

typedef struct {
	int dia,
		mes,
		ano;
} Data;

typedef struct {
	int cep;
	char logradouro[100];
	int n_casa;
	char bairro[100];
	char cidade[100];
	char estado[100];


}Endereco;

typedef struct{
	int DDD;
	int numero;

}Telefone;

typedef struct{
	char nome[32];
	char sobrenome[100];
}Nome;

typedef struct{
	int agencia;
	int n_conta;
	float limite;
	Data vencimento;
	Nome nome;
	char cpf[12];
	Data nascimento;
	Telefone telefone;
	Endereco endereco;
	char senha[32];
} Cliente;
#endif
