#include <stdio.h>
#include <conio.h>
#include <stdlib.h>// necess�rio p/ as fun��es rand() e srand()
#include<time.h>//necess�rio p/ fun��o time()

void main() {
	int i;
	
	printf("Gerando 100 valores aleatorios:\n\n");
	
	/* srand(time(NULL)) objetiva inicializar o gerador de n�meros aleat�rios
	com o valor da fun��o time(NULL). Este por sua vez, � calculado
	como sendo o total de segundos passados desde 1 de janeiro de 1970
	at� a data atual.
	Desta forma, a cada execu��o o valor da "semente" ser� diferente.
	*/
	srand(time(NULL));
	
	for (i=0; i < 5; i++)
	{
	// gerando valores aleat�rios na faixa de 0 a 100
		printf("\n%d ", rand() % 10);
	}
}

