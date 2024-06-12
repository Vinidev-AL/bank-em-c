#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "destinador.h"


void alterar_dados_funcionario() {
 	int codigo_funcionario;
 	Funcionario conta;
    printf("ALTERAR FUNCIONARIO\n\n");
    
    printf("CODIGO FUNCIONARIO: ");
    scanf("%d", &codigo_funcionario);
    
    printf("Digite o cargo do funcionário: ");
    fgets(conta.cargo, sizeof(conta.cargo), stdin);
    remover_nova_linha(conta.cargo);
    fflush(stdin);
    printf("Telefone\n\nDDD - exemplo 61: ");
    fgets(conta.telefone.DDD, sizeof(conta.telefone.DDD), stdin);
    remover_nova_linha(conta.telefone.DDD);
    fflush(stdin);
    printf("Número - exemplo 000000000: ");
    fgets(conta.telefone.numero, sizeof(conta.telefone.numero), stdin);
    remover_nova_linha(conta.telefone.numero);
    fflush(stdin);
    //-------------------------------------------------------------------------------------------------------------------
	limpar_buffer();
    printf("Endereco\n\nDigite o CEP (sem pontos e tracos): ");
    fgets(conta.endereco.cep, sizeof(conta.endereco.cep), stdin);
    remover_nova_linha(conta.endereco.cep);
    fflush(stdin);
    printf("Digite o logradouro: ");
    fgets(conta.endereco.logradouro, sizeof(conta.endereco.logradouro), stdin);
    remover_nova_linha(conta.endereco.logradouro);
    fflush(stdin);
    printf("Digite o numero da casa: ");
    scanf("%d", &conta.endereco.n_casa);
    limpar_buffer();
    printf("Digite o nome do bairro: ");
    fgets(conta.endereco.bairro, sizeof(conta.endereco.bairro), stdin);
    remover_nova_linha(conta.endereco.bairro);
    fflush(stdin);
    printf("Digite o nome da cidade: ");
    fgets(conta.endereco.cidade, sizeof(conta.endereco.cidade), stdin);
    remover_nova_linha(conta.endereco.cidade);
    fflush(stdin);
    printf("Digite o nome do estado: ");
    fgets(conta.endereco.estado, sizeof(conta.endereco.estado), stdin);
    remover_nova_linha(conta.endereco.estado);
    fflush(stdin);
    
    printf("Digite a nova senha do funcionário: ");
    fgets(conta.senha, sizeof(conta.senha), stdin);
    
    	FILE *file = fopen("contas_funcionario.bin", "r+b");
	    if (file == NULL) {
	        printf("ERRO, ARQUIVO NÃO EXISTE\n");
	        return;
	    }
	    Cliente conta;   
	    fseek(file, (contan - 1) * sizeof(Funcionario), SEEK_SET);
	
	    if (fread(&conta, sizeof(Funcionario), 1, file) != 1) {
	        if (feof(file)) {
	            printf("ERRO, CONTA NÃO ENCONTRADA\n");
	        } else {
	            printf("ERRO AO LER A CONTA\n");
	        }
	        fclose(file);
	        return;
	    }
	    
	    if (fwrite(&conta, sizeof(Funcionario), 1, file) != 1) {
        printf("Erro ao atualizar dados!\n");
        fclose(file);
    	} else {
    		printf("Dados alterados com sucesso!!!");
		}

    fclose(file);


	}
    
}

void alterar_conta_corrente(){
	int opc;
	int opc_case1;
 	Funcionario conta;
 	printf("DIGITE A OPCAO QUE DESEJA ALTERAR  \n");
 	printf("[1] - TIPO DE CONTA\n");
	printf("[2] - LIMITE\n");
	printf("[3] - DATA DE VENCIMENTO\n");
	printf("[4] - VOLTAR\n");	
 	scanf("%d", &opc);
		
 	
   switch(opc){
   	case 1:
   	 	printf("DESEJA REALMENTE ALTERAR A CONTA PARA POUPANCA?");
   	 	printf("[1] - SIM\n");
		printf("[2] - NAO\n");
		scanf("%d", &opc_case1);
		
		switch(opc_case1){
			case 1:
				break;
			case 
		}
   }
    
   
    
 
    printf("Número - exemplo 000000000: ");
    fgets(conta.telefone.numero, sizeof(conta.telefone.numero), stdin);
    remover_nova_linha(conta.telefone.numero);
    fflush(stdin);
    //-------------------------------------------------------------------------------------------------------------------
    
    printf("Digite a nova senha do funcionário: ");
    fgets(conta.senha, sizeof(conta.senha), stdin);
    
    	FILE *file = fopen("contas_funcionario.bin", "r+b");
	    if (file == NULL) {
	        printf("ERRO, ARQUIVO NÃO EXISTE\n");
	        return;
	    }
	    
	    Cliente conta;   
	    fseek(file, (contan - 1) * sizeof(Funcionario), SEEK_SET);
	
	    if (fread(&conta, sizeof(Funcionario), 1, file) != 1) {
	        if (feof(file)) {
	            printf("ERRO, CONTA NÃO ENCONTRADA\n");
	        } else {
	            printf("ERRO AO LER A CONTA\n");
	        }
	        fclose(file);
	        return;
	    }
	    
	    if (fwrite(&conta, sizeof(Funcionario), 1, file) != 1) {
        printf("Erro ao atualizar dados!\n");
        fclose(file);
    	} else {
    		printf("Dados alterados com sucesso!!!");
		}

    fclose(file);


	}
}
