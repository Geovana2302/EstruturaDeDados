#include <stdio.h>
#include <conio.h>
//2.Fa�a um algoritmo recursivo para c�lculo do fatorial
// de um n�mero positivo. Fazer antes um algoritmo n�o recursivo.

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


