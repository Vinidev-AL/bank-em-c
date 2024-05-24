#ifndef OPERACOES_H
#define OPERACOES_H

// funções

void menu_principal();
void criar_conta_funcionario();
void criar_conta_cliente(); 
void excluir_conta_funcionario();
void excluir_conta_cliente();
void menu_principal();


// structs

typedef struct Data{
	int dia,
		mes,
		ano;
} Data;

typedef struct Endereco{
	int cep;
	char logradouro[50];
	int n_casa[20];
	char bairro[20];
	char cidade[20];
	char estado[20];

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
	int limite;
	Data vencimento;
	Nome nome;
	char cpf[11];
	Data nascimento;
	Telefone telefone;
	Endereco endereco;
	char senha[32];
} Cliente;
#endif
