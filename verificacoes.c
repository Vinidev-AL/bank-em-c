#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "destinador.h"
#include <locale.h>

void verificar_conta_corrente(){
	setlocale(LC_ALL, "portuguese");
  	int contan;
  	char conta_cpf[12];
  	char conta_senha[32];
  	limpar_tela();
  	style_bank();
    printf("Digite o número da sua conta: ");
    scanf("%d", &contan);
    
    tabela_style();
    printf("Digite o seu CPF: ");
    scanf("%s", conta_cpf);
    
    tabela_style();
    printf("Digite a sua senha: ");
    scanf("%s", conta_senha);
    
    limpar_buffer();

    FILE *file = fopen("contas_corrente.bin", "rb");
    if (file == NULL) {
    	tabela_style();
        printf("ERRO, ARQUIVO NÃO EXISTE\n");
        return;
    }
    

    Cliente conta;
    
    
    fseek(file, (contan - 1) * sizeof(Cliente), SEEK_SET);

    if (fread(&conta, sizeof(Cliente), 1, file) != 1) {
        if (feof(file)) {
        	tabela_style();
            printf("ERRO, CONTA NÃO ENCONTRADA\n");
        } else {
        	tabela_style();
            printf("ERRO AO LER A CONTA\n");
        }
        fclose(file);
        return;
    }

    fclose(file);
    
    conta_cpf[strcspn(conta_cpf, "\n")] = 0;
    conta_senha[strcspn(conta_senha, "\n")] = 0;
    
    conta.cpf[strcspn(conta.cpf, "\n")] = 0;
    conta.senha[strcspn(conta.senha, "\n")] = 0;
    
    if (strcmp(conta_cpf, conta.cpf) == 0)

    {
    	
    	if (strcmp(conta_senha, conta.senha) == 0)
		{
            limpar_tela();
            printf("Login realizado!\n\n");
            menu_cliente_corrente(contan);
		}
 	   
 	    else
        {
      		printf("\033[31m");
        	printf("\n");
        	tabela_style();
            printf("Falha ao logar, senha ou cpf incorretos\n");  
            printf("\033[0m");
            tabela_style();		
		}
    }

    else
    {
    		printf("\033[31m");
        	printf("\n");
        	tabela_style();
            printf("Falha ao logar, senha ou cpf incorretos\n");  
            printf("\033[0m");
            tabela_style();	
    }

 
    
    system("pause");
}


void verificar_conta_poupanca(){
	setlocale(LC_ALL, "portuguese");
  	int contan;
  	char conta_cpf[12];
  	char conta_senha[32];
  	limpar_tela();
  	
  	style_bank();
    printf("Digite o número da sua conta: ");
    scanf("%d", &contan);
    
    tabela_style();
    printf("Digite o seu CPF: ");
    scanf("%s", conta_cpf);
    
    tabela_style();
    printf("Digite a sua senha: ");
    scanf("%s", conta_senha);
    
    limpar_buffer();

    FILE *file = fopen("contas_poupanca.bin", "rb");
    if (file == NULL) {
        printf("ERRO, ARQUIVO NÃO EXISTE\n");
        return;
    }
    

    Cliente conta;
    
    
    fseek(file, (contan - 1) * sizeof(Cliente), SEEK_SET);

    if (fread(&conta, sizeof(Cliente), 1, file) != 1) {
        if (feof(file)) {
        	tabela_style();
            printf("ERRO, CONTA NÃO ENCONTRADA\n");
        } else {
        	tabela_style();
            printf("ERRO AO LER A CONTA\n");
        }
        fclose(file);
        return;
    }

    fclose(file);
    
    conta_cpf[strcspn(conta_cpf, "\n")] = 0;
    conta_senha[strcspn(conta_senha, "\n")] = 0;
    
    conta.cpf[strcspn(conta.cpf, "\n")] = 0;
    conta.senha[strcspn(conta.senha, "\n")] = 0;
    
    if (strcmp(conta_cpf, conta.cpf) == 0)

    {
    	
    	if (strcmp(conta_senha, conta.senha) == 0)
		{
            printf("Login realizado!\n\n");
            menu_cliente_poupanca(contan);
		}
 	   
 	    else
        {
        	printf("\033[31m");
        	printf("\n");
        	tabela_style();
            printf("Falha ao logar, senha ou cpf incorretos\n");  
            printf("\033[0m");
            tabela_style();	
		}
    }

    else
    {
    		printf("\033[31m");
        	printf("\n");
        	tabela_style();
            printf("Falha ao logar, senha ou cpf incorretos\n");  
            printf("\033[0m");
            tabela_style();
    }

 
    
    system("pause");
}



void verificar_conta_funcionario(){
	
    setlocale(LC_ALL, "portuguese");
    int contan;
    char conta_cpf[12];
    char conta_senha[32];
    limpar_tela();
 	style_bank();
    printf("Digite o número da sua conta: ");
    scanf("%d", &contan);
    tabela_style();
    printf("Digite o seu CPF: ");
    scanf("%s", conta_cpf);
    tabela_style();
    printf("Digite a sua senha: ");
    scanf("%s", conta_senha);
    
    limpar_buffer();

    FILE *file = fopen("contas_funcionario.bin", "rb");
    if (file == NULL) {
        printf("ERRO, ARQUIVO NÃO EXISTE\n");
        return;
    }
    

    Funcionario conta;
    
    
    fseek(file, (contan - 1) * sizeof(Funcionario), SEEK_SET);

    if (fread(&conta, sizeof(Funcionario), 1, file) != 1) {
        if (feof(file)) {
        	tabela_style();
            printf("ERRO, CONTA NÃO ENCONTRADA\n");
        } else {
        	tabela_style();
            printf("ERRO AO LER A CONTA\n");
        }
        fclose(file);
        return;
    }

    fclose(file);
    
    conta_cpf[strcspn(conta_cpf, "\n")] = 0;
    conta_senha[strcspn(conta_senha, "\n")] = 0;
    
    conta.cpf[strcspn(conta.cpf, "\n")] = 0;
    conta.senha[strcspn(conta.senha, "\n")] = 0;
    
    if (strcmp(conta_cpf, conta.cpf) == 0)

    {
        
        if (strcmp(conta_senha, conta.senha) == 0)
        {
            limpar_tela();
            printf("Login realizado!\n\n");
            menu_funcionario();
        }
       
        else
        {	
        	printf("\033[31m");
        	printf("\n");
        	tabela_style();
            printf("Falha ao logar, senha ou cpf incorretos\n");  
            printf("\033[0m");
            tabela_style();
        }
    }

    else
    {
         	printf("\033[31m");
        	printf("\n");
        	tabela_style();
            printf("Falha ao logar, senha ou cpf incorretos\n");  
            printf("\033[0m");
            tabela_style();
    }

 
    
    system("pause");
}

