#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>// necessário p/ as funções rand() e srand()
#include<time.h>//necessário p/ função time()


#define TF1 1000
#define TF10 50000
#define TF25 25000
#define TF50 25000

void insertSort(int vetor[], int tam) {

    int esq, elemento, dir;
    printf("\n<<Inicio Ordenacao insertSort>>");
    for (dir = 1; dir < tam; dir++) {
        elemento = vetor[dir];
        esq = dir - 1;
        while (esq >= 0 && vetor[esq] > elemento) {
            vetor[esq + 1] = vetor[esq];
            esq--;
        }
        vetor[esq + 1] = elemento;
    }
    printf("\n<<Fim Ordenacao insertSort>>");
}

void selectSort(int vetor[], int tam) {

    int elemento, esq, dir;

    for (esq = 0; esq < tam; esq++) {
        for (dir = esq + 1; dir < tam; dir++) {
            if (vetor[esq] > vetor[dir]) {
                elemento = vetor[esq];
                vetor[esq] = vetor[dir];     
                vetor[dir] = elemento;      
            }
        }
    }
}


void bubbleSort(int vetor[], int tam) {
    int elemento, houveTroca, indice;
    int tamanho = tam;
    do {
        houveTroca = 0;
        for (indice = 0; indice < tamanho - 1; indice++) {
            if (vetor[indice] > vetor[indice + 1]) {
                elemento = vetor[indice];
                vetor[indice] = vetor[indice + 1];
                vetor[indice + 1] = elemento;
                houveTroca = 1;
            }
        }
        tamanho--;
    }
    while (houveTroca == 1);
}

void carregar_vetor(int vet[], int tam){
	int i, num;
	double tempoExecucao;
	clock_t tempoInicial = clock(); // armazena o tempo inicial de clock
	printf("\n<<Carregando Vetor>>");
	srand(time(NULL));
	for(i=0;i<tam;i++){
		vet[i] = rand() % tam;
		//sleep(1);
	}
	printf("\n<<Fim Carregando Vetor>>");
	tempoExecucao =  ((double)clock() - tempoInicial) / CLOCKS_PER_SEC;
	printf("\nTempo de execução: %f segundos\n",tempoExecucao);	
}

void main(){
	int i, vet1[TF1], vet25[TF25], vet50[TF50];
	int vet10[TF10], vet10s[TF10], vet10b[TF10];
	carregar_vetor(vet10, TF10);
	vet10s = vet10;
	vet10b = vet10;
        
	insertSort(vet10, TF10);
	selectSort(vet10s, TF10);
	bubbleSort(vet10b, TF10);
	/*for (i = 0; i < TF10; i++)
        printf("\n[%d]",vet10[i]);
    */  
    printf("\n\n\n\n\n");
}
