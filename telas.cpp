#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "destinador.h"

void tela_login_funcionario(){
	system("cls");
	int ID;
	char password[8];
	printf("Digite seu ID: ");
	scanf("%d", &ID);
	printf("\nDigite sua senha: ");
	scanf("%s", &password);
}

void tela_login_cliente(){
	system("cls");
	int ID;
	char password[8];
	printf("Digite sua conta: ");
	scanf("%d", &ID);
	printf("\nDigite sua senha: ");
	scanf("%s", &password);
};

void tela_administrador(){
	int opc;
	system("cls");
	printf("ADMINISTRADOR\n\n\n");
	printf("1 - Criar conta de funcionario\n");
	printf("2 - Criar conta de cliente\n");
	printf("3 - Excluir conta de funcionario\n");
	printf("4 - Excluir conta de cliente\n");
	printf("5 - Sair");
	
	
	switch(opc){
		case 1:
			
		case 2:
			
		case 3:
			
		case 4:
		
		case 5:			
	}
	
}


void menu_principal() {
	int opc;
	printf("MENU PRINCIPAL\n\n\n");
	printf("Digite a opcao desejada\n\n");
	printf("1 - FUNCIONARIO\n");
	printf("2 - CLIENTE\n");
	printf("3 - SAIR DO PROGRAMA\n");
	scanf("%d", &opc);
	
	
	switch(opc){
		case 1:
			tela_login_funcionario();
			break;
		case 2: 
			tela_login_cliente();
			break;
		case 3: 
			exit(0);
			break;
		case 123456:
			tela_administrador();
		default:
			printf("Opcao invalida");
			break;
	}
}


