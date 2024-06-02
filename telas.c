#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "destinador.h"

void tela_login_funcionario(){

}

void tela_login_cliente(){
	verificar_conta();
};

void tela_administrador(){
	int opc;
	limpar_tela();
	printf("ADMINISTRADOR\n\n\n");
	printf("1 - Criar conta de funcionario\n");
	printf("2 - Criar conta de cliente\n");
	printf("3 - Excluir conta de funcionario\n");
	printf("4 - Excluir conta de cliente\n");
	printf("5 - Sair\n");
	scanf("%d", &opc);
	limpar_buffer();

	switch(opc){
		case 1:
			criar_conta_funcionario();
			break;
		case 2:
			criar_conta_cliente();
			break;
		case 3:
			excluir_conta_funcionario();
			break;
		case 4:
			excluir_conta_cliente();
			break;
		case 5:
			menu_principal();
			break;
	}

}


void menu_principal() {
	int opc;
	while(1){
        printf("MENU PRINCIPAL\n\n\n");
        printf("Digite a opcao desejada\n\n");
        printf("1 - FUNCIONARIO\n");
        printf("2 - CLIENTE\n");
        printf("3 - SAIR DO PROGRAMA\n");
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
            case 123456:
                tela_administrador();
                break;
            default:
                printf("Opcao invalida");
                break;
        }
	}
}


