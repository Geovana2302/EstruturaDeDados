#include <stdio.h>
#include <conio.h>

//4.Faça uma função recursiva que permita somar os elementos de um vetor de inteiros.

#define TF 5

void ler_vet (int vet[TF]){
	int i;
	for(i=0;i<TF;i++){
		printf("Vet[%d]: ",i);
		scanf("%d",&vet[i]);
	}	
	
}
void somar_vetor(int vet[TF]){
	int i;
	int soma=0;
	int op;
	printf("\nDeseja somar:\n\n 1 = Sim \n\n 2 = Nao \n\n ");
	scanf("%d", &op);
	if (op == 1){	
		for(i=0;i<TF;i++){
			soma = soma + vet[i];	
		}
		printf("Soma = %d \n\n", soma);
	}			
	if (op == 2){
		system("pause");
	}
}	

void leitura_vet(){
	int vet[TF];
	system("cls");
	printf("<<Vetor>>\n");
	ler_vet(vet);
	somar_vetor(vet);
	printf("\n\n");
	system("pause");
}
