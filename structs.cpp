#include <stdio.h>
#include <stdlib.h>
#include "destinador.h"

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

typedef struct Telefone{
	int DDD;
	int numero;
	
}Telefone;

typedef struct Nome{
	int Nome,
	Sobrenome;
}Nome;

typedef struct Cliente{
	Data data;
	char cpf;
	Endereco endereco;
	Telefone telefone;
	Nome nome;
}Cliente;

                                                                                                             
