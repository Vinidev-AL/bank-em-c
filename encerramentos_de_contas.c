#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "destinador.h"

void encerrar_conta_funcionario(){
	int contan;
	printf("Digite o numero da conta que deseja encerrar: ");
	scanf("%d", &contan);

	Funcionario conta;
	FILE *file = fopen("contas_funcionario.bin", "r+b");
	    if (file == NULL) {
	        printf("ERRO, ARQUIVO NAO EXISTE\n");
	        return;
	    }

	    fseek(file, (contan - 1) * sizeof(Funcionario), SEEK_SET);
	
	    if (fread(&conta, sizeof(Funcionario), 1, file) != 1) {
	        if (feof(file)) {
	            printf("ERRO, CONTA NAO ENCONTRADA\n");
	        } else {
	            printf("ERRO AO LER A CONTA\n");
	        }
	        fclose(file);
	    }

		conta.codigo = 0;
		strcpy(conta.cargo, "");
		strcpy(conta.nome.nome, "");
		strcpy(conta.nome.sobrenome, "");
		strcpy(conta.cpf, "");
		conta.nascimento.dia = 0;
		conta.nascimento.mes = 0;
		conta.nascimento.ano = 0;
		strcpy(conta.telefone.DDD , "");
		strcpy(conta.telefone.numero , "");
		strcpy(conta.endereco.cep , "");
		strcpy(conta.endereco.logradouro , "");
		conta.endereco.n_casa = 0;
		strcpy(conta.endereco.bairro , "");
		strcpy(conta.endereco.cidade , "");
		strcpy(conta.endereco.estado , "");
		strcpy(conta.senha , "");

		if (fwrite(&conta, sizeof(Funcionario), 1, file) != 1) {
        printf("Erro ao encerrar a conta!\n");
        fclose(file);
    }

    fclose(file);

    if (conta.codigo == 0) {
        printf("Conta encerrada com sucesso!\n\n");
        system("pause");
    } else {
        printf("Erro ao encerrar a conta!\n");
        system("pause");
    }

    return;
}







void encerrar_conta_corrente(){
	int contan;
	printf("Digite o numero da conta que deseja encerrar: ");
	scanf("%d", &contan);

	Cliente conta;
	FILE *file = fopen("contas_corrente.bin", "r+b");
	    if (file == NULL) {
	        printf("ERRO, ARQUIVO NAO EXISTE\n");
	        return;
	    }
	    
	    fseek(file, (contan - 1) * sizeof(Cliente), SEEK_SET);
	
	    if (fread(&conta, sizeof(Cliente), 1, file) != 1) {
	        if (feof(file)) {
	            printf("ERRO, CONTA NAO ENCONTRADA\n");
	        } else {
	            printf("ERRO AO LER A CONTA\n");
	        }
	        fclose(file);
	    }

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
		strcpy(conta.senha ,"");

		 fseek(file, (contan - 1) * sizeof(Cliente), SEEK_SET);

    if (fwrite(&conta, sizeof(Cliente), 1, file) != 1) {
        printf("Erro ao encerrar a conta!\n");
        fclose(file);
    }

    fclose(file);

    if (conta.n_conta == 0) {
        printf("Conta encerrada com sucesso!\n\n");
        system("pause");
    } else {
        printf("Erro ao encerrar a conta!\n");
        system("pause");
    }

    return;

}






void encerrar_conta_poupanca(){
	int contan;
	printf("Digite o numero da conta que deseja encerrar: ");
	scanf("%d", &contan);

	Cliente conta;
	FILE *file = fopen("contas_poupanca.bin", "r+b");
	    if (file == NULL) {
	        printf("ERRO, ARQUIVO NAO EXISTE\n");
	        return;
	    }
	  
	    fseek(file, (contan - 1) * sizeof(Cliente), SEEK_SET);
	
	    if (fread(&conta, sizeof(Cliente), 1, file) != 1) {
	        if (feof(file)) {
	            printf("ERRO, CONTA NAO ENCONTRADA\n");
	        } else {
	            printf("ERRO AO LER A CONTA\n");
	        }
	        fclose(file);
	    }

		strcpy(conta.agencia ,"");
		conta.n_conta = 0;
		conta.saldo = 0.0;
		conta.limite = 0.0;
		conta.vencimento.dia = 0;
		conta.vencimento.mes = 0;
		conta.vencimento.ano = 0;
		strcpy(conta.nome.nome, "");
		strcpy(conta.nome.sobrenome, "");
		strcpy(conta.cpf, "");
		conta.nascimento.dia = 0;
		conta.nascimento.mes = 0;
		conta.nascimento.ano = 0;
		strcpy(conta.telefone.DDD, "");
		strcpy(conta.telefone.numero, "");
		strcpy(conta.endereco.cep ,"");
		strcpy(conta.endereco.logradouro, "");
		conta.endereco.n_casa = 0;
		strcpy(conta.endereco.bairro, "");
		strcpy(conta.endereco.cidade ,"");
		strcpy(conta.endereco.estado, "");
		strcpy(conta.senha ,"");

		 fseek(file, (contan - 1) * sizeof(Cliente), SEEK_SET);

    if (fwrite(&conta, sizeof(Cliente), 1, file) != 1) {
        printf("Erro ao encerrar a conta!\n");
        fclose(file);
    }

    fclose(file);

    if (conta.n_conta == 0) {
        printf("Conta encerrada com sucesso!\n\n");
        system("pause");
    } else {
        printf("Erro ao encerrar a conta!\n");
        system("pause");
    }

    return;
}
