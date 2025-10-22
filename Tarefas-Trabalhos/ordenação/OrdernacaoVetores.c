#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
  #include <windows.h>
#endif

#define TF1 1000
#define TF2 10000
#define TF3 25000
#define TF4 50000

typedef struct {
    double tempo;                 // segundos (alta resolução)
    long long movimentacoes;      // nº de escritas no vetor
} Resultado;

// ---------- Timer de alta resolução ----------
static double agora() {
#ifdef _WIN32
    static LARGE_INTEGER freq = {0};
    LARGE_INTEGER counter;
    if (freq.QuadPart == 0) {
        QueryPerformanceFrequency(&freq);
    }
    QueryPerformanceCounter(&counter);
    return (double)counter.QuadPart / (double)freq.QuadPart;
#else
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (double)ts.tv_sec + (double)ts.tv_nsec / 1e9;
#endif
}

// ---------- Utilidades ----------
void carregarVetor(int v[], int n, int ordenado) {
    int i;
    if (ordenado) {
        for (i = 0; i < n; i++) v[i] = i;                 // já ordenado
    } else {
        for (i = 0; i < n; i++) v[i] = rand() % 10000;    // aleatório
    }
}

// ---------- Algoritmos (movimentação = escrita) ----------
Resultado insertionSort(int v[], int n) {
    int i, j, chave;
    long long mov = 0;
    double t0 = agora();

    for (i = 1; i < n; i++) {
        chave = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];  // deslocamento (1 escrita)
            mov++;
            j--;
        }
        v[j + 1] = chave;     // inserção final (1 escrita)
        mov++;
    }

    Resultado r = { agora() - t0, mov };
    return r;
}

Resultado selectionSort(int v[], int n) {
    int i, j, min, temp;
    long long mov = 0;
    double t0 = agora();

    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (v[j] < v[min]) min = j;
        }
        if (min != i) {
            // troca = 3 escritas
            temp = v[i];   // 1
            v[i] = v[min]; // 2
            v[min] = temp; // 3
            mov += 3;
        }
    }

    Resultado r = { agora() - t0, mov };
    return r;
}

Resultado bubbleSort(int v[], int n) {
    int i, j, temp;
    long long mov = 0;
    double t0 = agora();

    for (i = 0; i < n - 1; i++) {
        int houveTroca = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                // troca = 3 escritas
                temp = v[j];        // 1
                v[j] = v[j + 1];    // 2
                v[j + 1] = temp;    // 3
                mov += 3;
                houveTroca = 1;
            }
        }
        // otimização: se nenhuma troca, já está ordenado
        if (!houveTroca) break;
    }

    Resultado r = { agora() - t0, mov };
    return r;
}

// ---------- Execuções ----------
void comparar_um_cenario(int n, int ordenado) {
    int *a = (int*)malloc(n * sizeof(int));
    int *b = (int*)malloc(n * sizeof(int));
    int *c = (int*)malloc(n * sizeof(int));

    carregarVetor(a, n, ordenado);
    carregarVetor(b, n, ordenado);
    carregarVetor(c, n, ordenado);

    printf("\n===== Comparando com vetor %s (%d elementos) =====\n",
           ordenado ? "ORDENADO" : "ALEATORIO", n);

    Resultado r;

    r = insertionSort(a, n);
    printf("InsertionSort -> Tempo: %.6f s | Movimentacoes: %lld\n", r.tempo, r.movimentacoes);

    r = selectionSort(b, n);
    printf("SelectionSort -> Tempo: %.6f s | Movimentacoes: %lld\n", r.tempo, r.movimentacoes);

    r = bubbleSort(c, n);
    printf("BubbleSort    -> Tempo: %.6f s | Movimentacoes: %lld\n", r.tempo, r.movimentacoes);

    free(a); free(b); free(c);
}

void comparar_ambos(int n) {
    comparar_um_cenario(n, 0); // aleatório
    comparar_um_cenario(n, 1); // ordenado
}

// ---------- Menu ----------
int escolher_tamanho() {
    int tam;
    printf("Digite o tamanho (1000 / 10000 / 25000 / 50000): ");
    scanf("%d", &tam);
    if (tam==TF1 || tam==TF2 || tam==TF3 || tam==TF4) return tam;
    printf("Tamanho invalido!\n");
    return 0;
}

int main() {
    int op, tam = 0;
    srand((unsigned)time(NULL));

    do {
        printf("\n====== MENU ======\n");
        printf("1 - Escolher tamanho do vetor\n");
        printf("2 - Comparar (vetor ALEATORIO)\n");
        printf("3 - Comparar (vetor ORDENADO)\n");
        printf("4 - Comparar (AMBOS os cenarios)\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                tam = escolher_tamanho();
                if (tam) printf("Tamanho %d selecionado!\n", tam);
                break;
            case 2:
                if (!tam) printf("Escolha o tamanho primeiro!\n");
                else comparar_um_cenario(tam, 0);
                break;
            case 3:
                if (!tam) printf("Escolha o tamanho primeiro!\n");
                else comparar_um_cenario(tam, 1);
                break;
            case 4:
                if (!tam) printf("Escolha o tamanho primeiro!\n");
                else comparar_ambos(tam);
                break;
        }
    } while (op != 0);

    return 0;
}

