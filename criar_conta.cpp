#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "destinador.h"

void criar_conta_cliente(){
	system("cls");
	Cliente cliente;
	Data vencimento;
	printf("\nDigite o cpf: ");
	scanf("%s", cliente.cpf);
	
	printf("\nDigite o numero da conta: ");
	scanf("%d", &cliente.n_conta);
	
	printf("\nDigite o limite da conta: ");
	scanf("%d", &cliente.limite);
	
	printf("\nDigite a data de vencimento da conta\n\n");
	
	
	printf("Digite o dia: ");
	scanf("%d", &vencimento.dia);
	
	printf("Digite o mes: ");
	scanf("%d", &vencimento.mes);
	
	printf("Digite o ano: ");
	scanf("%d", &vencimento.ano);
	
	printf("Digite a senha: ");
	scanf("%s", cliente.senha);
	
	
	char li[3] = "\n";
	
	
	FILE *file;
	file = fopen("contas.bin", "ab");
	
	fwrite(cliente.cpf, sizeof(char), 11, file);
	fwrite(li, sizeof(char), 2, file);
	
	fwrite(&cliente.n_conta, sizeof(int), 5, file);
	fwrite(li, sizeof(char), 2, file);
	
	fwrite(&cliente.limite, sizeof(int), 11, file);
	fwrite(li, sizeof(char), 2, file);
	
	fwrite(&cliente.vencimento.dia, sizeof(int), 2, file);
	fwrite(li, sizeof(char), 2, file);
	
	fwrite(&cliente.vencimento.mes, sizeof(int), 2, file);
	fwrite(li, sizeof(char), 2, file);
	
	fwrite(&cliente.vencimento.ano, sizeof(int), 4, file);
	fwrite(li, sizeof(char), 2, file);
	
	fwrite(cliente.senha, sizeof(char), 32, file);
	fwrite(li, sizeof(char), 2, file);
	
	fclose(file);
	
	printf("Conta criada com sucesso!!!");
}

void criar_conta_funcionario(){
	
}

void excluir_conta_cliente(){
	
}

void excluir_conta_funcionario(){
	
}
