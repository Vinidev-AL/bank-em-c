#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "destinador.h"

void criar_conta_cliente(){
	system("cls");
	Cliente cliente;
	Data vencimento;
	printf("\nDigite a agencia: ");
	scanf("%s", cliente.cpf);
	
	printf("\nDigite o numero da conta: ");
	scanf("%s", cliente.n_conta);
	
	printf("\nDigite o limite da conta: ");
	scanf("%d", cliente.limite);
	
	printf("\nDigite a data de vencimento da conta\n\n");
	printf("Digite o dia: ");
	scanf("%d", vencimento.dia);
	printf("Digite o mes: ");
	scanf("%d", vencimento.mes);
	printf("Digite o ano: ");
	scanf("%d", vencimento.ano);
	
	
	FILE *file;
	file = fopen("contas.txt", "a");
	
	fprintf(file, "%s", cliente.cpf);
}

void criar_conta_funcionario(){
	
}

void excluir_conta_cliente(){
	
}

void excluir_conta_funcionario(){
	
}
