#include <stdio.h>
#include <conio.h>

//3.Fa�a uma fun��o recursiva que calcule e retorne o N-�simo termo da sequ�ncia Fibonacci. 
//Alguns n�meros desta sequ�ncia s�o: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89...

int fib (int n){
	if (n < 2){
		return n;
	}
	else{
		return fib(n - 1) + fib(n - 2);
	}
		
}

void leitura_fib(){
	int n;
	system("cls");
	printf("<<Fibonacci>>\n");
	printf("Informe um Numero: ");
	scanf("%d", &n);
	printf("Fibonacci: %d", fib(6));
	printf("\n\n");
	system("pause");
}
