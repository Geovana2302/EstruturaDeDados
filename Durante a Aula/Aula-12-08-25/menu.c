#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void leitura_somatoria();
void leitura_fatorial();
void leitura_fib();
void leitura_vet();
void leitura_vetIn();


void menu(){
	int op;
	system("cls");
	printf("Menu de Opcoes");
	printf("\n1 - Soma de 1 ate N");
	printf("\n2 - Fatorial");
	printf("\n3 - Fibonacci");
	printf("\n4 - Vetor");
	printf("\n5 - Inverter Vetor");
	printf("\n0 - Finalizar");
	printf("\nInforme a Opcao: ");
	scanf("%d", &op);
	if (op == 1){
		leitura_somatoria();
	}
	if (op == 2){
		leitura_fatorial();
	}
	if (op == 3){
		leitura_fib();
	}
	if (op == 4){
		leitura_vet();
	}
	if (op == 5){
		leitura_vetIn();
	}
	if (op != 0){
		menu();
	}
}
