#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "destinador.h"
#include <locale.h>


void tela_login_funcionario(){
	verificar_conta_funcionario();
}

void tela_login_cliente(){
	
	verificar_conta();
};

void menu_principal() {
	int opc;
	setlocale(LC_ALL, "portuguese");
	while(1){
		limpar_tela();
		logo_bank_malvader();
        printf("MENU PRINCIPAL\n\n\n");
        tabela_style();
        printf("Digite a opcao desejada\n\n");
        tabela_style();
        printf("[1] - FUNCIONARIO\n");
        tabela_style();
        printf("[2] - CLIENTE\n");
        tabela_style();
        printf("[3] - SAIR DO PROGRAMA\n\n\n");
        tabela_style();
        printf("Opcao: ");
        scanf("%d", &opc);
        limpar_buffer();


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
            default:
                printf("Opcao invalida");
                break;
        }
	}
}

void menu_cliente(int contan){
	
	while(1)
	
	{
		limpar_tela();
		style_bank();
		setlocale(LC_ALL, "portuguese");
	
		FILE *file = fopen("contas.bin", "r+b");
	    if (file == NULL) {
	        printf("ERRO, ARQUIVO NÃO EXISTE\n");
	        return;
	    }
	    Cliente conta;   
	    fseek(file, (contan - 1) * sizeof(Cliente), SEEK_SET);
	
	    if (fread(&conta, sizeof(Cliente), 1, file) != 1) {
	        if (feof(file)) {
	            printf("ERRO, CONTA NÃO ENCONTRADA\n");
	        } else {
	            printf("ERRO AO LER A CONTA\n");
	        }
	        fclose(file);
	        return;
	    }
	
		int opc;
		printf("MENU CLIENTE\n\n");
		printf("[1] - SALDO\n");
		printf("[2] - DEPÓSITO\n");
		printf("[3] - SAQUE\n");
		printf("[4] - EXTRATO\n");
		printf("[5] - CONSULTAR LIMITE\n");
		printf("[6] - SAIR\n\n");
		printf("OPÇÃO: ");
		scanf("%d", &opc);
		
		float deposito;
		float saque;
		
		FILE *arqui;
		arqui = fopen("extratos.txt", "a");
	
		switch(opc){
		case 1:
			printf("O saldo da conta é: R$%.2f\n", conta.saldo);
			fclose(file);
			system("pause");
			break;
		case 2:
			printf("Digite quando deseja depositar: ");
			scanf("%f", &deposito);
			
 	 		
 	 		conta.saldo += deposito;
 	 		
 	 		fprintf(arqui, "Depositado R$%.2f da conta\n", deposito);
			fclose(arqui);
 	 		
 	 		fseek(file, -sizeof(Cliente), SEEK_CUR);
 	 		
 	 		fwrite(&conta, sizeof(Cliente), 1, file);
			fclose(file);
			break;
			
		case 3:
			printf("Digite quanto deseja sacar: ");
			scanf("%f", &saque);
			
			if(saque > conta.saldo)
			
			{
				printf("Saldo insuficiente, seu saldo atual é: %.2f\n\n", conta.saldo);
				
				system("pause");
			} 
			
			else
			{
				
				fprintf(arqui, "Sacados R$%.2f da conta do user %s\n", saque, conta.nome);
				fclose(arqui);
				conta.saldo -= saque;
				fseek(file, -sizeof(Cliente), SEEK_CUR);
 	 		
 	 			fwrite(&conta, sizeof(Cliente), 1, file);
				fclose(file);
				
				printf("Sacados R$%.2f da conta\n\n", saque);	
				
				system("pause");
			}
			
			break;
			
		case 4:
			system("extratos.xlsx");
			system("pause");
			break;
		case 5:
			printf("Seu limite atual é: R$%.2f\n\n", conta.limite);
			system("pause");
			fclose(file);
			break;
			
		case 6:
			printf("Saindo...");
			fclose(file);
			return;
			break;
		dafault:
			printf("OPÇÃO INVÁLIDA");
			system("pause");
		}
		
	}
}


void menu_funcionario(){
	int opc;
	setlocale(LC_ALL, "portuguese");
	limpar_tela();
	style_bank();
	printf("[1] - Abertura de conta\n");
	tabela_style();
	printf("[2] - Encerramento de conta\n");
	tabela_style();
	printf("[3] - Consultar dados\n");
	tabela_style();
	printf("[4] - Alterar dados\n");
	tabela_style();
	printf("[5] - Cadastro de funcionarios\n");
	tabela_style();
	printf("[6] - Gerar relatorios\n");
	tabela_style();
	printf("[7] - Sair\n");
	tabela_style();
	printf("Opção: ");
	scanf("%d", &opc);

	switch(opc){
		case 1:
			criar_conta_cliente();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			criar_conta_funcionario();
			break;
		case 6:
			break;
		case 7:
			break;
		default:
			printf("Opção inválida!\n");
			system("pause");
	}
}



