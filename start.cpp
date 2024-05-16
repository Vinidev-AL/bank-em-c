#include <stdio.h>
#include <stdlib.h>
#include "destinador.h"

void tfuncionario(){
	system("cls");
	system("color 4");
	
	int pass;
	int ID;
	int validador;
	style_bank();
		
	printf("TELA PARA FUNCIONARIOS\n\t\t\t\t\t\t\t");
	
	printf("DIGITE SEU ID DE FUNCIONARIO: ");
	scanf("%d", &ID);
	printf("\t\t\t\t\t\t\t");
	printf("DIGITE A SUA SENHA: ");
	scanf("%d", &pass);
	
	validador = verifyfuncionario(ID, pass);
	
	if(validador == 3){
		printf("Erro");
	}
	
	else {
		printf("Sucesso");
	}
}





void tcliente(){
	system("cls");
	printf("Tela cliente");
}



void tela_Criar_Conta_Funcionario(){
	system("cls");
	style_bank();
	printf("DIGITE O NOME: \n\t\t\t\t\t\t\t");
	printf("DIGITE O SENHA: \n\t\t\t\t\t\t\t");
	printf("DIGITE O CPF: \n");
}



void tela_Criar_Conta_User(){
		system("cls");
	style_bank();
	printf("DIGITE O NOME: \n\t\t\t\t\t\t\t");
	printf("DIGITE O SENHA: \n\t\t\t\t\t\t\t");
	printf("DIGITE O CPF: \n");
}


void destinador(){
	int opc = 0;
	
	while(opc <= 0 || opc > 5){
			system("cls");
			system("color 4");
			logo_bank_malvader();

			printf("DIGITE A OPCAO DESEJADA:\n\n\t\t\t\t\t\t\t");
			printf("1 - FUNCIONARIO\n\t\t\t\t\t\t\t");
			printf("2 - CLIENTE\n\t\t\t\t\t\t\t");
			printf("3 - CRIAR CONTA FUNCIONARIO\n\t\t\t\t\t\t\t");
			printf("4 - CRIAR CONTA CLIENTE\n\n\t\t\t\t\t\t\t");
			printf("5- SAIR DO PROGRAMA\n\n\t\t\t\t\t\t\t");
			printf(": ");
			scanf("%d", &opc);	
			break;
		}
		
	switch(opc){
		
		
		case 1:	
			tfuncionario();
			break;
			
		case 2:
				
			tcliente();
			break;
			
		case 3:
			tela_Criar_Conta_Funcionario();
			break;
				
		case 4:
			tela_Criar_Conta_User();
			break;
		
			
		default: 
			system("cls");
			printf("Programa encerrado!");
			break;		
	}
}

