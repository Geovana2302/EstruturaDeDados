#include <stdio.h>
#include <time.h>

void main () {
	double tempoExecucao;
	
	printf("Medir Tempo: \n");
	clock_t tempoInicial = clock(); // armazena o tempo inicial de clock
	//printf("Tempo Inicial: %d", tempoInicial);
	sleep(10);
	tempoExecucao =  ((double)clock() - tempoInicial) / CLOCKS_PER_SEC;
	//printf("Tempo Inicial: %d", tempoInicial);
	
	printf("\nTempo de execução: %f segundos\n",tempoExecucao);
}

