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
	char logradouro[50];
	char n_casa[20];
	char bairro[20];
	char cidade[20];
	char estado[20];

}Endereco;

typedef struct{
	int DDD;
	int numero;
	
}Telefone;

typedef struct{
	int Nome,
	Sobrenome;
}Nome;

typedef struct{
	Data data;
	char cpf[11];
	Endereco endereco;
	Telefone telefone;
	Nome nome;
} Cliente;
#endif
