#include <stdio.h>
#include <stdlib.h>
#include "destinador.h"

void tfuncionario(){
	system("cls");
	system("color 4");
	
	int pass;
	int ID;
	int validador;
	printf("\n\n\n\n\t\t\t\t\t\t\t");
	
			printf(" ########        ##       ####     #### ####   ####\n\t\t\t\t\t\t\t");
			printf("  ##   ###      ####       ####     ##   ##    ##\n\t\t\t\t\t\t\t");
			printf("  ##   ###     ##  ##      ## ##    ##   ##   ##\n\t\t\t\t\t\t\t");
			printf("  #######     ##    ##     ##  ##   ##   ######\n\t\t\t\t\t\t\t");
			printf("  ##   ###   ##########    ##   ##  ##   ##   ##\n\t\t\t\t\t\t\t");
			printf("  ##   ###  ###      ###   ##    ## ##   ##    ##\n\t\t\t\t\t\t\t");
			printf(" ########  #####    ##### ####    ##### ####   ####\n\n\t\t\t\t\t\t\t");
		
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



void criarcontafuncionario(){
	system("cls");
	printf("DIGITE O NOME: ");
	printf("DIGITE O SENHA: ");
	printf("DIGITE O CPF: ");
}



void criarcontauser(){
	
}









void destinador(){
	int op = 0;
	
	while(op <= 0 || op > 5){
			system("cls");
			system("color 4");
			printf("\n\t\t");
			printf("######          ######           ##          #####        ######          ######       ##           #######       ##########   ######## \n\t\t");
			printf(" ######        ######           ####          ###           ###            ###        ####          ###    ###    ##########   ###    ###\n\t\t");
			printf(" ### ###      ### ###          ######         ###            ###          ###        ######         ###     ###   ####         ###    ### \n\t\t");
			printf(" ###  ###    ###  ###         ###  ###        ###             ###        ###        ###  ###        ###      ###  ####         ###    ## \n\t\t");
			printf(" ###   ###  ###   ###        ###    ###       ###              ###      ###        ###    ###       ###      ###  ########     #######  \n\t\t");
			printf(" ###    ######    ###       ############      ###               ###    ###        ############      ###      ###  ########     ######  \n\t\t");
			printf(" ###     ####     ###      ##############     ###                ###  ###        ##############     ###      ###  ####         ###  ### \n\t\t");
			printf(" ###      ##      ###     ###          ###    ###       ###       ######        ###          ###    ###     ###   ####         ###   ###\n\t\t");
			printf(" ###              ###    ###            ###   #############        ####        ###            ###   ###    ###    ##########   ###    ### \n\t\t");
			printf("#####           #####  ######         ####### #############         ##       ######         ####### #######       ##########  #####   #####\n\n\n\t\t\t\t\t\t\t");




			printf(" ########        ##       ####     #### ####   ####\n\t\t\t\t\t\t\t");
			printf("  ##   ###      ####       ####     ##   ##    ##\n\t\t\t\t\t\t\t");
			printf("  ##   ###     ##  ##      ## ##    ##   ##   ##\n\t\t\t\t\t\t\t");
			printf("  #######     ##    ##     ##  ##   ##   ######\n\t\t\t\t\t\t\t");
			printf("  ##   ###   ##########    ##   ##  ##   ##   ##\n\t\t\t\t\t\t\t");
			printf("  ##   ###  ###      ###   ##    ## ##   ##    ##\n\t\t\t\t\t\t\t");
			printf(" ########  #####    ##### ####    ##### ####   ####\n\n\t\t\t\t\t\t\t");
	
			
				printf("DIGITE A OPCAO DESEJADA:\n\n\t\t\t\t\t\t\t");
				printf("1 - FUNCIONARIO\n\t\t\t\t\t\t\t");
				printf("2 - CLIENTE\n\t\t\t\t\t\t\t");
				printf("3 - CRIAR CONTA FUNCIONARIO\n\n\t\t\t\t\t\t\t");
				printf("4 - CRIAR CONTA CLIENTE\n\n\t\t\t\t\t\t\t");
				printf("5- SAIR DO PROGRAMA\n\n\t\t\t\t\t\t\t");
				printf(": ");
				scanf("%d", &op);	
				break;
		}
		
		if(op == 1){
		
			tfuncionario();
		}
		
		else if (op == 2){
			
			tcliente();
		}
		
		else if(op == 3){
			criarcontafuncionario();
		}
		
		else if(op == 4){
			criarcontauser();
			
		}
	
		
		else {
			system("cls");
			printf("Programa encerrado!");
		}
	}

