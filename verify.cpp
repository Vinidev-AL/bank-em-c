#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verifyfuncionario(int a,  int b) {
	FILE *file;	
	file = fopen("funcionarios.txt", "r");
	
		if(file == NULL) {
		printf("Nao foi possivel abrir o arquivo");
		}
		
	return 0;
		
}

void criar_Conta_funcionario(int *ID, int *idade){
	struct Registro{
		int ID;
		int idade;
	};
	FILE *file;
	
	file = fopen("contas.txt", "w");
	
	if(file == NULL) {
		printf("Nao foi possivel abrir o arquivo");
		getchar();
		exit(0);
	}

	
	
}
