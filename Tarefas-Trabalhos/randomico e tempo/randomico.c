#include <stdio.h>
#include <conio.h>
#include <stdlib.h>// necessário p/ as funções rand() e srand()
#include<time.h>//necessário p/ função time()

void main() {
	int i;
	
	printf("Gerando 100 valores aleatorios:\n\n");
	
	/* srand(time(NULL)) objetiva inicializar o gerador de números aleatórios
	com o valor da função time(NULL). Este por sua vez, é calculado
	como sendo o total de segundos passados desde 1 de janeiro de 1970
	até a data atual.
	Desta forma, a cada execução o valor da "semente" será diferente.
	*/
	srand(time(NULL));
	
	for (i=0; i < 5; i++)
	{
	// gerando valores aleatórios na faixa de 0 a 100
		printf("\n%d ", rand() % 10);
	}
}

