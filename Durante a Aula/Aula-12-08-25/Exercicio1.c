#include <stdio.h>
#include <conio.h>
//1.Fa�a uma rotina recursiva para calcular a somat�ria de todos os 
//n�meros de 1 a N (N ser� lido do teclado).

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


