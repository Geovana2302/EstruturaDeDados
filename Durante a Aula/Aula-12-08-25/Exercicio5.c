#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//5.Crie um programa em C que receba um vetor 
//de números reais com 10 elementos. 
//Escreva uma função recursiva que inverta ordem dos 
//elementos presentes no vetor.

#define TF 5

void ler_vet(float vet[TF]){
	int i;
	for(i=0;i<TF;i++){
		printf("Vet[%d]: ",i);
		scanf("%f",&vet[i]);
	}	
	
}
void inverter_vetor(float vet[TF], int i, int j){
	float aux;
	if(i >= j) return;
		aux = vet[i];
		vet[i] = vet[j];
		vet[j] = aux;
		
		inverter_vetor(vet, i+1,j-1);
		
	}

void leitura_vetIn(){
	float vet[TF];
	int i;
	
	system("cls");
	printf("<<Vetor Invertido>>\n");
	ler_vet(vet);
	inverter_vetor(vet,0,TF-1);
	printf("vetor invertido:\n");
	for(i=0;i<TF,i++){
		printf("%.2f",vet[i]);
	}
	printf("\n\n");
	system("pause");
}

int menu(){
	leitura_vetIn();
	return 0;
}
