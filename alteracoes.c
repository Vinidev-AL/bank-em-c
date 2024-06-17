#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "destinador.h"

int contador_conta_poupanca;
int contador_conta_corrente;

void carregar_contador_conta_poupanca_alt() {
    FILE *arquivo = fopen("contador_conta_poupanca.bin", "rb");
    if (arquivo != NULL) {
        fread(&contador_conta_poupanca, sizeof(int), 1, arquivo);
        fclose(arquivo);
    } else {
        contador_conta_poupanca = 0; // Inicializa contador se o arquivo não existir
    }
}

void salvar_contador_conta_poupanca_alt() {
    FILE *arquivo = fopen("contador_conta_poupanca.bin", "wb");
    if (arquivo != NULL) {
        fwrite(&contador_conta_poupanca, sizeof(int), 1, arquivo);
        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para salvar o contador.\n");
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

void carregar_contador_conta_corrente_alt() {
    FILE *arquivo = fopen("contador_conta_corrente.bin", "rb");
    if (arquivo != NULL) {
        fread(&contador_conta_corrente, sizeof(int), 1, arquivo);
        fclose(arquivo);
    } else {
        contador_conta_corrente = 0; // Inicializa contador se o arquivo não existir
    }
}

void salvar_contador_conta_corrente_alt() {
    FILE *arquivo = fopen("contador_conta_corrente.bin", "wb");
    if (arquivo != NULL) {
        fwrite(&contador_conta_corrente, sizeof(int), 1, arquivo);
        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para salvar o contador.\n");
    }
}







void alterar_dados_funcionario() {
 	int codigo_funcionario;
 	Funcionario conta;
 	tabela_style();
    printf("ALTERAR FUNCIONARIO\n\n");
    
    tabela_style();
    printf("CODIGO FUNCIONARIO: ");
    scanf("%d", &codigo_funcionario);
    
    tabela_style();
    printf("Digite o cargo do funcionário: ");
    fgets(conta.cargo, sizeof(conta.cargo), stdin);
    remover_nova_linha(conta.cargo);
    fflush(stdin);
    tabela_style();
    printf("Telefone\n\nDDD - exemplo 61: ");
    fgets(conta.telefone.DDD, sizeof(conta.telefone.DDD), stdin);
    remover_nova_linha(conta.telefone.DDD);
    fflush(stdin);
    tabela_style();
    printf("Número - exemplo 000000000: ");
    fgets(conta.telefone.numero, sizeof(conta.telefone.numero), stdin);
    remover_nova_linha(conta.telefone.numero);
    fflush(stdin);
    //-------------------------------------------------------------------------------------------------------------------
    tabela_style();
    printf("Endereco\n\nDigite o CEP (sem pontos e tracos): ");
    fgets(conta.endereco.cep, sizeof(conta.endereco.cep), stdin);
    remover_nova_linha(conta.endereco.cep);
    fflush(stdin);
    tabela_style();
    printf("Digite o logradouro: ");
    fgets(conta.endereco.logradouro, sizeof(conta.endereco.logradouro), stdin);
    remover_nova_linha(conta.endereco.logradouro);
    fflush(stdin);
    tabela_style();
    printf("Digite o numero da casa: ");
    scanf("%d", &conta.endereco.n_casa);
    limpar_buffer();
    tabela_style();
    printf("Digite o nome do bairro: ");
    fgets(conta.endereco.bairro, sizeof(conta.endereco.bairro), stdin);
    remover_nova_linha(conta.endereco.bairro);
    fflush(stdin);
    tabela_style();
    printf("Digite o nome da cidade: ");
    fgets(conta.endereco.cidade, sizeof(conta.endereco.cidade), stdin);
    remover_nova_linha(conta.endereco.cidade);
    fflush(stdin);
    tabela_style();
    printf("Digite o nome do estado: ");
    fgets(conta.endereco.estado, sizeof(conta.endereco.estado), stdin);
    remover_nova_linha(conta.endereco.estado);
    fflush(stdin);
    
    tabela_style();
    printf("Digite a nova senha do funcionário: ");
    fgets(conta.senha, sizeof(conta.senha), stdin);
    
    	FILE *file = fopen("contas_funcionario.bin", "r+b");
	    if (file == NULL) {
	    	tabela_style();
	        printf("ERRO, ARQUIVO NÃO EXISTE\n");
	        return;
	    }
	
	    fseek(file, (codigo_funcionario - 1) * sizeof(Funcionario), SEEK_SET);
	
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
	    
	    if (fwrite(&conta, sizeof(Funcionario), 1, file) != 1) {
	    	tabela_style();
	        printf("Erro ao atualizar dados!\n");
	        fclose(file);
    	} else {
    		tabela_style();
    		printf("Dados alterados com sucesso!!!");
		}

    fclose(file);


	}
    


void alterar_conta_corrente(){
	int opc;
	int opc_case1;
	int contan;
	float limite_temporario;
	int dia;
	int mes;
	int ano;

	
 	Cliente conta;

 	tabela_style();
 	printf("DIGITE A OPCAO QUE DESEJA ALTERAR  \n");
 	tabela_style();
 	printf("[1] - TIPO DE CONTA\n");
 	tabela_style();
	printf("[2] - LIMITE\n");
	tabela_style();
	printf("[3] - DATA DE VENCIMENTO\n");
	tabela_style();
	printf("[4] - ALTERAR CLIENTE\n");
	tabela_style();
	printf("[5] - VOLTAR\n");
	tabela_style();
	printf("OPCAO: ");	
 	scanf("%d", &opc);
	
 	if(opc == 5){
 		tabela_style();
 		printf("Voltando...\n");
 		tabela_style();
 		system("pause");
 		return;
 	}

	tabela_style();
 	printf("DIGITE O NUMERO DA CONTA: ");
 	scanf("%d", &contan);
 	
 	FILE *file = fopen("contas_corrente.bin", "r+b");
    if (file == NULL) {
    	tabela_style();
        printf("ERRO, ARQUIVO NÃO EXISTE\n");
        return;
    }
    
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


        if(conta.n_conta == 0){
	        tabela_style();
	    	printf("Essa conta nao existe, portanto nao e possivel alterar, retornando...\n");
	    	system("pause");
	    	return;
    }
 
 	
   switch(opc){
   	
   	
   	case 1:	
   		tabela_style();
   	 	printf("DESEJA REALMENTE ALTERAR A CONTA PARA POUPANCA?\n");
   	 	tabela_style();
   	 	printf("[1] - SIM\n");
   	 	tabela_style();
		printf("[2] - NAO\n");
		tabela_style();
		printf("OPCAO:");
		scanf("%d", &opc_case1);
		
		switch(opc_case1){
			
			case 1:
				carregar_contador_conta_poupanca_alt();
				contador_conta_poupanca++;
				FILE *arquivo_poup = fopen("contas_poupanca.bin", "ab");
    
			    if (arquivo_poup != NULL) {
			        fwrite(&conta, sizeof(Cliente), 1, arquivo_poup);
			        fclose(arquivo_poup);
			    } else {
			    	tabela_style();
			        printf("Erro ao abrir o arquivo para salvar a conta.\n");
			    }

    			salvar_contador_conta_poupanca_alt();
    			tabela_style();
    			printf("Conta movida com sucesso!!!\n\n");
				
				tabela_style();
				printf("Conta corrente movida, o numero da sua conta e: %d\n\n", contador_conta_poupanca);
				
		
	
					strcpy(conta.agencia, "");
					conta.n_conta = 0;
					conta.saldo = 0.0;
					conta.limite = 0.0;
					conta.vencimento.dia = 0;
					conta.vencimento.mes = 0;
					conta.vencimento.ano = 0;
					strcpy(conta.nome.nome, "");
					strcpy(conta.nome.sobrenome, "");
					strcpy(conta.cpf , "");
					conta.nascimento.dia = 0;
					conta.nascimento.mes = 0;
					conta.nascimento.ano = 0;
					strcpy(conta.telefone.DDD, "");
					strcpy(conta.telefone.numero, "");
					strcpy(conta.endereco.cep, "");
					strcpy(conta.endereco.logradouro ,"");
					conta.endereco.n_casa = 0;
					strcpy(conta.endereco.bairro, "");
					strcpy(conta.endereco.cidade, "");
					strcpy(conta.endereco.estado, "");
					strcpy(conta.senha, "");
			
					fseek(file, (contan - 1) * sizeof(Cliente), SEEK_SET);
			

					fwrite(&conta, sizeof(Cliente), 1, file);
			    	if (fwrite(&conta, sizeof(Cliente), 1, file) != 1) {
			    	
			    	tabela_style();
			        printf("Erro ao zerar conta corrente!\n");
			        fclose(file);
			        tabela_style();
			        system("pause");
			    	}
			    	fclose(file);
			    	tabela_style();
			    	system("pause");
					
				break;
					
			case 2:
				tabela_style();
				printf("Ok retornando...");
				tabela_style();
				system("pause");
				break;
		}

		break;


	case 2:
		tabela_style();
		printf("O LIMITE DO CLIENTE %s E: R$%.2f\n\n", conta.nome.nome, conta.limite);
		tabela_style();
		printf("DIGITE O NOVO VALOR DO LIMITE: ");
		scanf("%f", &limite_temporario);


		conta.limite = limite_temporario;
		fseek(file, (contan - 1) * sizeof(Cliente), SEEK_SET);
		fwrite(&conta, sizeof(Cliente), 1, file);
		fclose(file);

				FILE *file_read = fopen("contas_corrente.bin", "rb");
			    if (file_read == NULL) {
			    	tabela_style();
			        printf("ERRO, ARQUIVO NÃO EXISTE\n");
			    }
			    
			    fseek(file_read, (contan - 1) * sizeof(Cliente), SEEK_SET);

			    if (fread(&conta, sizeof(Cliente), 1, file_read) != 1) {
			        if (feof(file_read)) {
			        	tabela_style();
			            printf("ERRO, CONTA NÃO ENCONTRADA\n");
			        } else {
			        	tabela_style();
			            printf("ERRO AO LER A CONTA\n");
			        }
			    }


			if(conta.limite != limite_temporario){
				tabela_style();
				printf("Erro ao alterar limite");
				tabela_style();
				system("pause");
			} else {
				tabela_style();
				printf("Limite alterado com sucesso! Seu novo limite e: R$%.2f", conta.limite);
				tabela_style();
				system("pause");
			}

			fclose(file_read);

		break;

	case 3:
		tabela_style();
		printf("A data de vencimento atual e: %d/%d/%d\n\n", conta.vencimento.dia, conta.vencimento.mes, conta.vencimento.ano);
		tabela_style();
		system("pause");
		tabela_style();
		printf("Digite a nova data de vencimento\n");
		tabela_style();
		printf("Dia: ");
		scanf("%d", &dia);
		tabela_style();
		printf("Mes: ");
		scanf("%d", &mes);
		tabela_style();
		printf("Ano: ");
		scanf("%d", &ano);

		conta.vencimento.dia = dia;
		conta.vencimento.mes = mes;
		conta.vencimento.ano = ano;

				fseek(file, (contan - 1) * sizeof(Cliente), SEEK_SET);
				fwrite(&conta, sizeof(Cliente), 1, file);
				fclose(file);


				FILE *file_read_data_vencimento = fopen("contas_corrente.bin", "rb");
			    if (file_read_data_vencimento == NULL) {
			    	tabela_style();
			        printf("ERRO, ARQUIVO NÃO EXISTE\n");
			    }
			    
			    fseek(file_read_data_vencimento, (contan - 1) * sizeof(Cliente), SEEK_SET);

			    if (fread(&conta, sizeof(Cliente), 1, file_read_data_vencimento) != 1) {
			        if (feof(file_read_data_vencimento)) {
			        	tabela_style();
			            printf("ERRO, CONTA NÃO ENCONTRADA\n");
			        } else {
			        	tabela_style();
			            printf("ERRO AO LER A CONTA\n");
			        }
			    }


		if((dia + mes + ano) != (conta.vencimento.dia + conta.vencimento.mes + conta.vencimento.ano)){
			tabela_style();
			printf("Erro ao alterar data de vencimento");
			tabela_style();
			system("pause");
		} else {
			tabela_style();
			printf("Data de vencimento alterada, a data atual e: %d/%d/%d\n\n", conta.vencimento.dia, conta.vencimento.mes, conta.vencimento.ano);
			tabela_style();
			system("pause");
		}

		fclose(file_read_data_vencimento);

		break;


	case 4:
		limpar_tela();
		tabela_style();
		printf("Alteracao de dados da conta do cliente %s\n\n", conta.nome.nome);
		tabela_style();

		printf("Telefone atual: (%s) %s\n", conta.telefone.DDD, conta.telefone.numero);
		tabela_style();
		printf("Endereço atual: CEP %s, Logradouro: %s, Casa: %d, Bairro: %s, Cidade: %s, Estado: %s\n\n", conta.endereco.cep, conta.endereco.logradouro, conta.endereco.n_casa, conta.endereco.bairro, conta.endereco.cidade, conta.endereco.estado);
		limpar_buffer();
		tabela_style();

		printf("Novo telefone\n\n");
	    tabela_style();
	    printf("DDD - exemplo 61: ");
	    fgets(conta.telefone.DDD, sizeof(conta.telefone.DDD), stdin);
	    remover_nova_linha(conta.telefone.DDD);
	    fflush(stdin);
	    tabela_style();
	    printf("Numero - exemplo 000000000: ");
	    fgets(conta.telefone.numero, sizeof(conta.telefone.numero), stdin);
	    remover_nova_linha(conta.telefone.numero);
	    fflush(stdin);
	    tabela_style();

	 	printf("Novo endereco\n\n");
	    tabela_style();
	    printf("Digite o CEP (sem pontos e tracos): ");
	    fgets(conta.endereco.cep, sizeof(conta.endereco.cep), stdin);
	    remover_nova_linha(conta.endereco.cep);
	    fflush(stdin);
	    tabela_style();
	    printf("Digite o logradouro: ");
	    fgets(conta.endereco.logradouro, sizeof(conta.endereco.logradouro), stdin);
	    remover_nova_linha(conta.endereco.logradouro);
	    fflush(stdin);
	    tabela_style();
	    printf("Digite o numero da casa: ");
	    scanf("%d", &conta.endereco.n_casa);
	    limpar_buffer();
	    tabela_style();
	    printf("Digite o nome do bairro: ");
	    fgets(conta.endereco.bairro, sizeof(conta.endereco.bairro), stdin);
	    remover_nova_linha(conta.endereco.bairro);
	    fflush(stdin);
	    tabela_style();
	    printf("Digite o nome da cidade: ");
	    fgets(conta.endereco.cidade, sizeof(conta.endereco.cidade), stdin);
	    remover_nova_linha(conta.endereco.cidade);
	    fflush(stdin);
	    tabela_style();
	    printf("Digite o nome do estado: ");
	    fgets(conta.endereco.estado, sizeof(conta.endereco.estado), stdin);
	    remover_nova_linha(conta.endereco.estado);
	    fflush(stdin);
	    tabela_style();		
		system("pause");


		fseek(file, (contan - 1) * sizeof(Cliente), SEEK_SET);
		fwrite(&conta, sizeof(Cliente), 1, file);
		fclose(file);

				FILE *file_read_cliente_dados = fopen("contas_corrente.bin", "rb");
			    if (file_read_cliente_dados == NULL) {
			    	tabela_style();
			        printf("ERRO, ARQUIVO NÃO EXISTE\n");
			    }
			    
			    fseek(file_read_cliente_dados, (contan - 1) * sizeof(Cliente), SEEK_SET);

			    if (fread(&conta, sizeof(Cliente), 1, file_read_cliente_dados) != 1) {
			        if (feof(file_read_cliente_dados)) {
			        	tabela_style();
			            printf("ERRO, CONTA NÃO ENCONTRADA\n");
			        } else {
			        	tabela_style();
			            printf("ERRO AO LER A CONTA\n");
			        }
			    }
		tabela_style();
		printf("Cliente atualizado\n\n");
		tabela_style();
		printf("Telefone atual: (%s) (%s)\n", conta.telefone.DDD, conta.telefone.numero);
		tabela_style();
		printf("Endereço atual: CEP %s, Logradouro: %s, Casa: %d, Bairro: %s, Cidade: %s, Estado: %s\n", conta.endereco.cep, conta.endereco.logradouro, conta.endereco.n_casa, conta.endereco.bairro, conta.endereco.cidade, conta.endereco.estado);
		tabela_style();
		system("pause");

		fclose(file_read_cliente_dados);

		break;

	case 5:
		tabela_style();
		printf("Voltando...\n");
		system("pause");
		break;

	default:
		tabela_style();
		printf("OPCAO INVALIDA\n");
		tabela_style();
		system("pause");
		break;
	}
			
}  


void alterar_conta_poupanca(){
	int opc;
	int opc_case1;
	int contan;
	int dia;
	int mes;
	int ano;

	
 	Cliente conta;
 	tabela_style();
 	printf("DIGITE A OPCAO QUE DESEJA ALTERAR  \n");
 	tabela_style();
 	printf("[1] - TIPO DE CONTA\n");
 	tabela_style();
	printf("[2] - DATA DE VENCIMENTO\n");
	tabela_style();
	printf("[3] - ALTERAR CLIENTE\n");	
	tabela_style();
	printf("[4] - VOLTAR\n");
 	scanf("%d", &opc);
		
 	printf("DIGITE O NUMERO DA CONTA: ");
 	scanf("%d", &contan);
 	
 	FILE *file = fopen("contas_poupanca.bin", "r+b");
    if (file == NULL) {
    	tabela_style();
        printf("ERRO, ARQUIVO NÃO EXISTE\n");
        return;
    }
    
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

    if(conta.n_conta == 0){
    	tabela_style();
    	printf("Essa conta nao existe, portanto nao e possivel alterar, retornando...\n");
    	tabela_style();
    	system("pause");
    	return;
    }

 
 	
   switch(opc){
   	
   	
   	case 1:	
   		tabela_style();
   	 	printf("DESEJA REALMENTE ALTERAR A CONTA PARA CORRENTE?\n");
   	 	tabela_style();
   	 	printf("[1] - SIM\n");
   	 	tabela_style();
		printf("[2] - NAO\n");
		tabela_style();
		printf("OPCAO: ");
		scanf("%d", &opc_case1);
		
		switch(opc_case1){
			
			case 1:
				carregar_contador_conta_corrente_alt();
				contador_conta_corrente++;
				FILE *arquivo_corrente = fopen("contas_corrente.bin", "ab");
    
			    if (arquivo_corrente != NULL) {
			        fwrite(&conta, sizeof(Cliente), 1, arquivo_corrente);
			        fclose(arquivo_corrente);
			    } else {
			    	tabela_style();
			        printf("Erro ao abrir o arquivo para salvar a conta.\n");
			    }

    			salvar_contador_conta_corrente_alt();
    			tabela_style();
    			printf("Conta movida com sucesso!!!\n\n");
				
				tabela_style();
				printf("Conta poupanca movida, o numero da sua conta e: %d\n\n", contador_conta_corrente);
				
		
	
					strcpy(conta.agencia, "");
					conta.n_conta = 0;
					conta.saldo = 0.0;
					conta.limite = 0.0;
					conta.vencimento.dia = 0;
					conta.vencimento.mes = 0;
					conta.vencimento.ano = 0;
					strcpy(conta.nome.nome, "");
					strcpy(conta.nome.sobrenome, "");
					strcpy(conta.cpf , "");
					conta.nascimento.dia = 0;
					conta.nascimento.mes = 0;
					conta.nascimento.ano = 0;
					strcpy(conta.telefone.DDD, "");
					strcpy(conta.telefone.numero, "");
					strcpy(conta.endereco.cep, "");
					strcpy(conta.endereco.logradouro ,"");
					conta.endereco.n_casa = 0;
					strcpy(conta.endereco.bairro, "");
					strcpy(conta.endereco.cidade, "");
					strcpy(conta.endereco.estado, "");
					strcpy(conta.senha, "");
			
					fseek(file, (contan - 1) * sizeof(Cliente), SEEK_SET);
			

					fwrite(&conta, sizeof(Cliente), 1, file);
			    	if (fwrite(&conta, sizeof(Cliente), 1, file) != 1) {
			    	
			    	tabela_style();
			        printf("Erro ao remover conta da poupanca!\n");
			        fclose(file);
			        tabela_style();
			        system("pause");
			    	}

			    	fclose(file);
			    	tabela_style();
			    	system("pause");
					
				break;
					
			case 2:
				tabela_style();
				printf("Ok retornando...");
				tabela_style();
				system("pause");
				break;
		}

	case 2:

		if(conta.n_conta == 0){
			tabela_style();
			printf("Essa conta não existe\n");
			tabela_style();
			system("pause");
		} else {

		tabela_style();
		printf("A data de vencimento atual e: %d/%d/%d\n\n", conta.vencimento.dia, conta.vencimento.mes, conta.vencimento.ano);
		tabela_style();
		system("pause");
		tabela_style();
		printf("Digite a nova data de vencimento\n");
		tabela_style();
		printf("Dia: ");
		scanf("%d", &dia);
		tabela_style();
		printf("Mes: ");
		scanf("%d", &mes);
		tabela_style();
		printf("Ano: ");
		scanf("%d", &ano);

		conta.vencimento.dia = dia;
		conta.vencimento.mes = mes;
		conta.vencimento.ano = ano;

				fseek(file, (contan - 1) * sizeof(Cliente), SEEK_SET);
				fwrite(&conta, sizeof(Cliente), 1, file);
				fclose(file);


				FILE *file_read_data_vencimento = fopen("contas_poupanca.bin", "rb");
			    if (file_read_data_vencimento == NULL) {
			    	tabela_style();
			        printf("ERRO, ARQUIVO NÃO EXISTE\n");
			    }
			    
			    fseek(file_read_data_vencimento, (contan - 1) * sizeof(Cliente), SEEK_SET);

			    if (fread(&conta, sizeof(Cliente), 1, file_read_data_vencimento) != 1) {
			        if (feof(file_read_data_vencimento)) {
			        	tabela_style();
			            printf("ERRO, CONTA NÃO ENCONTRADA\n");
			        } else {
			        	tabela_style();
			            printf("ERRO AO LER A CONTA\n");
			        }
			    }


		if((dia + mes + ano) != (conta.vencimento.dia + conta.vencimento.mes + conta.vencimento.ano)){
			tabela_style();
			printf("Erro ao alterar data de vencimento");
			tabela_style();
			system("pause");
		} else {
			tabela_style();
			printf("Data de vencimento alterada, a data atual e: %d/%d/%d\n\n", conta.vencimento.dia, conta.vencimento.mes, conta.vencimento.ano);
			tabela_style();
			system("pause");
		}

		fclose(file_read_data_vencimento);

	}

		break;

	case 3:
		limpar_tela();
		tabela_style();
		printf("Alteracao de dados da conta do cliente %s\n\n", conta.nome.nome);
		tabela_style();

		printf("Telefone atual: (%s) %s\n", conta.telefone.DDD, conta.telefone.numero);
		tabela_style();
		printf("Endereço atual: CEP %s, Logradouro: %s, Casa: %d, Bairro: %s, Cidade: %s, Estado: %s\n\n", conta.endereco.cep, conta.endereco.logradouro, conta.endereco.n_casa, conta.endereco.bairro, conta.endereco.cidade, conta.endereco.estado);
		limpar_buffer();
		tabela_style();

		printf("Novo telefone\n\n");
	    tabela_style();
	    printf("DDD - exemplo 61: ");
	    fgets(conta.telefone.DDD, sizeof(conta.telefone.DDD), stdin);
	    remover_nova_linha(conta.telefone.DDD);
	    fflush(stdin);
	    tabela_style();
	    printf("Numero - exemplo 000000000: ");
	    fgets(conta.telefone.numero, sizeof(conta.telefone.numero), stdin);
	    remover_nova_linha(conta.telefone.numero);
	    fflush(stdin);
	    tabela_style();

	 	printf("Novo endereco\n\n");
	    tabela_style();
	    printf("Digite o CEP (sem pontos e tracos): ");
	    fgets(conta.endereco.cep, sizeof(conta.endereco.cep), stdin);
	    remover_nova_linha(conta.endereco.cep);
	    fflush(stdin);
	    tabela_style();
	    printf("Digite o logradouro: ");
	    fgets(conta.endereco.logradouro, sizeof(conta.endereco.logradouro), stdin);
	    remover_nova_linha(conta.endereco.logradouro);
	    fflush(stdin);
	    tabela_style();
	    printf("Digite o numero da casa: ");
	    scanf("%d", &conta.endereco.n_casa);
	    limpar_buffer();
	    tabela_style();
	    printf("Digite o nome do bairro: ");
	    fgets(conta.endereco.bairro, sizeof(conta.endereco.bairro), stdin);
	    remover_nova_linha(conta.endereco.bairro);
	    fflush(stdin);
	    tabela_style();
	    printf("Digite o nome da cidade: ");
	    fgets(conta.endereco.cidade, sizeof(conta.endereco.cidade), stdin);
	    remover_nova_linha(conta.endereco.cidade);
	    fflush(stdin);
	    tabela_style();
	    printf("Digite o nome do estado: ");
	    fgets(conta.endereco.estado, sizeof(conta.endereco.estado), stdin);
	    remover_nova_linha(conta.endereco.estado);
	    fflush(stdin);
	    tabela_style();		
		system("pause");


		fseek(file, (contan - 1) * sizeof(Cliente), SEEK_SET);
		fwrite(&conta, sizeof(Cliente), 1, file);
		fclose(file);

				FILE *file_read_cliente_dados = fopen("contas_poupanca.bin", "rb");
			    if (file_read_cliente_dados == NULL) {
			    	tabela_style();
			        printf("ERRO, ARQUIVO NÃO EXISTE\n");
			    }
			    
			    fseek(file_read_cliente_dados, (contan - 1) * sizeof(Cliente), SEEK_SET);

			    if (fread(&conta, sizeof(Cliente), 1, file_read_cliente_dados) != 1) {
			        if (feof(file_read_cliente_dados)) {
			        	tabela_style();
			            printf("ERRO, CONTA NÃO ENCONTRADA\n");
			        } else {
			        	tabela_style();
			            printf("ERRO AO LER A CONTA\n");
			        }
			    }
		tabela_style();
		printf("Cliente atualizado\n\n");
		tabela_style();
		printf("Telefone atual: (%s) (%s)\n", conta.telefone.DDD, conta.telefone.numero);
		tabela_style();
		printf("Endereço atual: CEP %s, Logradouro: %s, Casa: %d, Bairro: %s, Cidade: %s, Estado: %s\n", conta.endereco.cep, conta.endereco.logradouro, conta.endereco.n_casa, conta.endereco.bairro, conta.endereco.cidade, conta.endereco.estado);
		tabela_style();
		system("pause");

		fclose(file_read_cliente_dados);

		break;


	case 4:
		tabela_style();
		printf("Voltando...\n");
		tabela_style();
		system("pause");
		break;

	default:
		tabela_style();
		printf("OPCAO INVALIDA\n");
		tabela_style();
		system("pause");
		break;
	}
			
}  






