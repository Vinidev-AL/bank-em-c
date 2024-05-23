#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "destinador.h"

void criar_conta_cliente(){
	system("cls");
	Cliente cliente;
	printf("\nDigite a agencia: ");
	scanf("%s", cliente.cpf);
	
	FILE *file
	file = fopen("contas.txt", "a");
	
	fprintf(file, "%s", cliente);
}
