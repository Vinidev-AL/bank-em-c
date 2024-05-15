#include <stdio.h>
#include <stdlib.h>
#include "destinador.h"

void destinador(int *a){
	int tela = 0;
	
	while(tela != 3){
		switch(tela) {
			case 0:
				printf("\n\n\nDIGITE A OPCAO DESEJADA:\n");
				printf("\t\n1 - FUNCIONARIO");
				printf("\t\n2 - CLIENTE");
				printf("\t\n3 - SAIR DO PROGRAMA\n");
				scanf("%d", &tela);	
				break;
			
			case 2:
				system("cls");
		}
	}
}
