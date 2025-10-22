#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TF1 1000
#define TF2 10000
#define TF3 25000
#define TF4 50000

// Função para carregar vetor aleatório
void carregarAleatorio(int v[], int n) {
	int i;
    for (i = 0; i < n; i++){
    	 v[i] = rand() % 100; // valores de 0 a 99
	}
       
}

// Função para carregar vetor já ordenado
void carregarOrdenado(int v[], int n) {
	int i;
    for ( i = 0; i < n; i++){
    	v[i] = i;
	}
        
}

// Função simples para InsertionSort
void insertionSort(int v[], int n) {
    int i, j, chave;
    for (i = 1; i < n; i++) {
        chave = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
}

int main() {
    srand(time(NULL));
    int opcao, tipo, tamanho;
    int *vetor;

    // Escolha do tamanho
    printf("Escolha o tamanho do vetor:\n");
    printf("1 - 1000\n2 - 10000\n3 - 25000\n4 - 50000\nOpcao: ");
    if (scanf("%d", &opcao) != 1) {
        printf("Entrada invalida!\n");
        return 1;
    }

    switch (opcao) {
        case 1: tamanho = TF1; break;
        case 2: tamanho = TF2; break;
        case 3: tamanho = TF3; break;
        case 4: tamanho = TF4; break;
        default: 
            printf("Opcao invalida!\n"); 
            return 1;
    }

    // Alocação de memória
    vetor = (int*) malloc(tamanho * sizeof(int));
    if (!vetor) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    // Escolha do tipo de vetor
    printf("Deseja vetor:\n1 - Aleatorio\n2 - Crescente\nOpcao: ");
    if (scanf("%d", &tipo) != 1) {
        printf("Entrada invalida!\n");
        free(vetor);
        return 1;
    }

    if (tipo == 1)
        carregarAleatorio(vetor, tamanho);
    else if (tipo == 2)
        carregarOrdenado(vetor, tamanho);
    else {
        printf("Opcao invalida!\n");
        free(vetor);
        return 1;
    }

    // Ordenação e medição de tempo
    clock_t inicio = clock();
    insertionSort(vetor, tamanho);
    clock_t fim = clock();

    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Ordenacao concluida!\nTamanho: %d | Tempo: %.4f segundos\n", tamanho, tempo);

    free(vetor);
    return 0;
}

