#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "destinador.h"

void consultar_funcionario(){
		int contan;
		tabela_style();
		printf("Digite o numero da conta que deseja consultar os dados: ");
		scanf("%d", &contan);



		FILE *file = fopen("contas_funcionario.bin", "r+b");

	    if (file == NULL) {
	    	tabela_style();
	        printf("ERRO, ARQUIVO NÃO EXISTE\n");
	        return;
	    }

	    Funcionario conta; 

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

	    tabela_style();
	    printf("Consultando conta do funcionario %s %s\n", conta.nome.nome, conta.nome.sobrenome);
	    tabela_style();
	    printf("Cargo: %s\n", conta.cargo);
	    tabela_style();
	    printf("CPF: %s\n", conta.cpf);
	    tabela_style();
	    printf("Codigo do funcionario: %d\n", conta.codigo);
	    tabela_style();
	    printf("Data de nascimento: %d/%d/%d\n", conta.nascimento.dia, conta.nascimento.mes, conta.nascimento.ano);
	    tabela_style();
	    printf("Telefone: (%s) %s\n", conta.telefone.DDD, conta.telefone.numero);
	    tabela_style();
	    printf("Endereco: CEP %s, Logradouro: %s, Casa: %d, Bairro: %s, Cidade: %s, Estado: %s\n", conta.endereco.cep, conta.endereco.logradouro, conta.endereco.n_casa, conta.endereco.bairro, conta.endereco.cidade, conta.endereco.estado);
	    quebrar_linha();
	    tabela_style();
	    printf("Consulta realizada!\n");
	    tabela_style();
	    system("pause");
}

void consultar_conta_corrente(){
		int contan;
		tabela_style();
		printf("Digite o numero da conta que deseja consultar os dados: ");
		scanf("%d", &contan);



		FILE *file = fopen("contas_corrente.bin", "r+b");

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

	    tabela_style();
	    printf("Consultando conta do cliente %s %s\n", conta.nome.nome, conta.nome.sobrenome);
	    tabela_style();
	    printf("Conta do tipo: Corrente\n");
	    tabela_style();
	    printf("CPF: %s\n", conta.cpf);
	    tabela_style();
	    printf("Saldo: %.2f\n", conta.saldo);
	    tabela_style();
	    printf("Limite: %.2f\n", conta.limite);
	    tabela_style();
	    printf("Data de vencimento: %d/%d/%d\n", conta.vencimento.dia, conta.vencimento.mes, conta.vencimento.ano);
	    tabela_style();
	    quebrar_linha();
	    tabela_style();
	    printf("Consulta realizada!\n");
	    tabela_style();
	    system("pause");
}

void consultar_conta_poupanca(){
		int contan;
		tabela_style();
		printf("Digite o numero da conta que deseja consultar os dados: ");
		scanf("%d", &contan);

		FILE *file = fopen("contas_poupanca.bin", "r+b");
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

	    tabela_style();
	    printf("Consultando conta do cliente %s %s\n", conta.nome.nome, conta.nome.sobrenome);
	    tabela_style();
	    printf("Conta do tipo: Corrente\n");
	    tabela_style();
	    printf("CPF: %s\n", conta.cpf);
	    tabela_style();
	    printf("Saldo: %.2f\n", conta.saldo);
	    tabela_style();
	    printf("Limite: %.2f\n", conta.limite);
	    tabela_style();
	    printf("Data de vencimento: %d/%d/%d\n", conta.vencimento.dia, conta.vencimento.mes, conta.vencimento.ano);
	    tabela_style();
	    quebrar_linha();
	    tabela_style();
	    printf("Consulta realizada!\n");
	    tabela_style();
	    system("pause");
}


void consultar_cliente(){
	int opc;
	char nome[200] = "";
	int verificador = 0;
	int i = 0;
	int n_conta;
	tabela_style();
	printf("Digite o tipo de conta que esse cliente possui\n");
	tabela_style();
	printf("[1] - CORRENTE\n");
	tabela_style();
	printf("[2] - POUPANCA\n");
	tabela_style();
	printf("[3] - VOLTAR\n");
	tabela_style();
	printf("OPCAO: ");
	scanf("%d", &opc);
	limpar_buffer();
	quebrar_linha();
	tabela_style();
	printf("Digite o nome de quem procura - certifique-se de nao digitar errado: ");
	fgets(nome, sizeof(nome), stdin);

	remover_nova_linha(nome);
	removeEspacos(nome);
	fflush(stdin);
	Cliente conta; 


switch (opc) {
        case 1: {
            FILE *file_read_cor = fopen("contas_corrente.bin", "r+b");
            if (file_read_cor == NULL) {
            	tabela_style();
                printf("ERRO, ARQUIVO NAO EXISTE\n");
                return;
            }

            while (verificador == 0) {
                fseek(file_read_cor, i * sizeof(Cliente), SEEK_SET);

                if (fread(&conta, sizeof(Cliente), 1, file_read_cor) != 1) {
                    if (feof(file_read_cor)) {
                        tabela_style();
                        printf("ERRO, CONTA NAO ENCONTRADA\n");
                        break;
                    } else {
                    	tabela_style();
                        printf("ERRO AO LER A CONTA\n");
                        fclose(file_read_cor);
                        return;
                    }
                }

                char nome_recebido[500] = "";
                strcat(nome_recebido, conta.nome.nome);
                strcat(nome_recebido, conta.nome.sobrenome);
                removeEspacos(nome_recebido);

                if (strcmp(nome, nome_recebido) == 0) {
                    verificador = 1;
                } else {
                    i++;
                }
            }

            if (verificador == 1) {
            	n_conta = i;
            	FILE *file_read_correntes = fopen("contas_corrente.bin", "r+b");
            	if (file_read_correntes == NULL) {
	            	tabela_style();
	                printf("ERRO, ARQUIVO NAO EXISTE\n");
	                return;
            	}

            	fseek(file_read_correntes, i * sizeof(Cliente), SEEK_SET);

                if (fread(&conta, sizeof(Cliente), 1, file_read_correntes) != 1) {
                    if (feof(file_read_correntes)) {
                        tabela_style();
                        printf("ERRO, CONTA NAO ENCONTRADA\n");
                        break;
                    } else {
                    	tabela_style();
                        printf("ERRO AO LER A CONTA\n");
                        fclose(file_read_correntes);
                        return;
                    }
                }

                tabela_style();
                printf("Consultando a conta do cliente: %s\n", conta.nome.nome, conta.nome.sobrenome);
                tabela_style();
                printf("CPF: %s\n", conta.cpf);
                tabela_style();
                printf("Data de nascimento: %d/%d/%d\n", conta.nascimento.dia, conta.nascimento.mes, conta.nascimento.ano);
                tabela_style();
                printf("Telefone: (%s) %s\n", conta.telefone.DDD, conta.telefone.numero);
                tabela_style();
                printf("Endereco: CEP %s, Logradouro: %s, Casa: %d, Bairro: %s, Cidade: %s, Estado: %s\n", conta.endereco.cep, conta.endereco.logradouro, conta.endereco.n_casa, conta.endereco.bairro, conta.endereco.cidade, conta.endereco.estado);
                quebrar_linha();
                tabela_style();
                printf("Consulta realizada!\n");
                tabela_style();
                system("pause");
           		 } else {
                tabela_style();
                printf("ERRO, CONTA NAO ENCONTRADA\n");
            	}

	            fclose(file_read_cor);
	            tabela_style();
	            system("pause");
	            break;
	            
	        }
        case 2:
        	
        	{
        	FILE *file_read_poup = fopen("contas_poupanca.bin", "r+b");
            if (file_read_poup == NULL) {
            	tabela_style();
                printf("ERRO, ARQUIVO NAO EXISTE\n");
                return;
            }

            while (verificador == 0) {
                fseek(file_read_poup, i * sizeof(Cliente), SEEK_SET);


                if (fread(&conta, sizeof(Cliente), 1, file_read_poup) != 1) {
                    if (feof(file_read_poup)) {
                        tabela_style();
                        printf("ERRO, CONTA NAO ENCONTRADA\n");
                        break;
                    } else {
                    	tabela_style();
                        printf("ERRO AO LER A CONTA\n");
                        fclose(file_read_poup);
                        return;
                    }
                }

                char nome_recebido[500] = "";
                strcat(nome_recebido, conta.nome.nome);
                strcat(nome_recebido, conta.nome.sobrenome);
                removeEspacos(nome_recebido);

                if (strcmp(nome, nome_recebido) == 0) {
                    verificador = 1;
                } else {
                    i++;
                }
            }

            if (verificador == 1) {
            	n_conta = i;
            	FILE *file_read_poupanca = fopen("contas_poupanca.bin", "r+b");
            	if (file_read_poupanca == NULL) {
	            	tabela_style();
	                printf("ERRO, ARQUIVO NAO EXISTE\n");
	                return;
            	}

            	fseek(file_read_poupanca, i * sizeof(Cliente), SEEK_SET);

                if (fread(&conta, sizeof(Cliente), 1, file_read_poupanca) != 1) {
                    if (feof(file_read_poupanca)) {
                        tabela_style();
                        printf("ERRO, CONTA NAO ENCONTRADA\n");
                        break;
                    } else {
                    	tabela_style();
                        printf("ERRO AO LER A CONTA\n");
                        fclose(file_read_poupanca);
                        return;
                    }
                }

                tabela_style();
                printf("Consultando a conta do cliente: %s\n", conta.nome.nome, conta.nome.sobrenome);
                tabela_style();
                printf("CPF: %s\n", conta.cpf);
                tabela_style();
                printf("Data de nascimento: %d/%d/%d\n", conta.nascimento.dia, conta.nascimento.mes, conta.nascimento.ano);
                tabela_style();
                printf("Telefone: (%s) %s\n", conta.telefone.DDD, conta.telefone.numero);
                tabela_style();
                printf("Endereco: CEP %s, Logradouro: %s, Casa: %d, Bairro: %s, Cidade: %s, Estado: %s\n", conta.endereco.cep, conta.endereco.logradouro, conta.endereco.n_casa, conta.endereco.bairro, conta.endereco.cidade, conta.endereco.estado);
                quebrar_linha();
                tabela_style();
                printf("Consulta realizada!\n");
                tabela_style();
                system("pause");
		            } else {
		                tabela_style();
		                printf("ERRO, CONTA NAO ENCONTRADA\n");
		            }

		            fclose(file_read_poup);
		            tabela_style();
		            system("pause");
		            break;
		        }
        case 3:
            break;
        default:
            break;
    }



}


