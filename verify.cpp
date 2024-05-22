#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "destinador.h"

void verifyfuncionario(char *id) {
	struct Registro{
		char nome[32];
		char ID[5];
		char idade[5];
		char senha[32];
	};
	Registro registro;
	FILE *file;	
	file = fopen("contas.txt", "r");
	
		if(file == NULL) {
		printf("Nao foi possivel abrir o arquivo");
		}
	
	while(fscanf(file, "%s", registro.ID) != EOF){
		if(strcmp(registro.ID, id) == 0){
			fclose(file);
			printf("Encontrado");
		}
	}	
}

void criar_Conta_funcionario(){
	system("cls");
	struct Registro{
		char nome[32];
		char ID[5];
		char idade[5];
		char senha[32];
	};
	
	Registro registro;
	
	printf("Digite o nome do funcionario: ");
	scanf("%s", registro.nome);
	
	printf("Digite o nome ID do funcionario: ");
	scanf("%s", registro.ID);
	
	printf("Digite a idade do funcionario: ");
	scanf("%s", registro.idade);
	
	printf("Digite a senha: ");
	scanf("%s", registro.senha);
	
	
	FILE *file;
	
	file = fopen("contas.txt", "a");
	
	if(file == NULL) {
		printf("Nao foi possivel abrir o arquivo");
		getchar();
		exit(0);
		}
		
	fprintf(file,"Nome: %s\n ID: %s\n Idade: %s\n Senha: %s\n\n\n", registro.nome, registro.ID, registro.idade, registro.senha);
	fclose(file);
	printf("Registro realizado com sucesso!\n\n");
	
	system("pause");
	destinador();
	
}
