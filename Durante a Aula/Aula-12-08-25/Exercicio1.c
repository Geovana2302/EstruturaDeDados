#include <stdio.h>
#include <conio.h>
//1.Faça uma rotina recursiva para calcular a somatória de todos os 
//números de 1 a N (N será lido do teclado).

int somatoria(int n){
	if (n == 1){
		return 1;
	}
	else{
		return n + somatoria(n-1);
	}
}

void leitura_somatoria(){
	int n;
	system("cls");
	printf("<<Somatoria dos Numeros>>\n");
	printf("Informe um Numero: ");
	scanf("%d", &n);
	printf("Somatoria: %d", somatoria(n));
	printf("\n\n");
	system("pause");
}


