#include <stdio.h>
#include <conio.h>
//2.Faça um algoritmo recursivo para cálculo do fatorial
// de um número positivo. Fazer antes um algoritmo não recursivo.

int fatorial (int n){
	 if (n == 0){
	 	return 1;
	}
	 	else{
	 		return n * fatorial(n - 1);
	 	}
	 }
 
 void leitura_fatorial(){
 	int n;
 	system("cls");
 	printf("<<Fatorial>>\n");
 	printf("Informe um numero: \n");
 	scanf("%d" ,&n);
 	
 	if (n > 0){
		printf("Fatorial: %d", fatorial(n));
	 }
	 else{
	 	printf("Numero negativo");
	 }
	printf("\n\n");
	system("pause");
 	
 }


