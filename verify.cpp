#include <stdio.h>
#include <stdlib.h>

int verifyfuncionario(int a,  int b) {
	FILE *file;	
	file = fopen("funcionarios.txt", "r");
	
		if(file == NULL) {
		printf("Nao foi possivel abrir o arquivo");
		return 3;
		}
		
	return 0;
		
}

void criarconta(){
	FILE *file;
	
	file = fopen("contas.txt", "w");
	
	if(file == NULL) {
		printf("Nao foi possivel abrir o arquivo");
		getchar();
		exit(0);
	}
}
