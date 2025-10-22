#include <stdio.h>
#include <stdlib.h>

struct no {
    int valor;
    struct no *prox;
};
typedef struct no Lista;

// ---- FUNÇÕES BASE ----
Lista* criarLista() { return NULL; }

int listaVazia(Lista *lista) { return lista == NULL; }

int totalElementosLista(Lista *lista) {
    int total = 0;
    while (lista != NULL) {
        total++;
        lista = lista->prox;
    }
    return total;
}

void exibirLista(Lista *lista) {
    if (listaVazia(lista)) {
        printf("\nLista vazia.\n");
        return;
    }

    printf("\nLista: ");
    while (lista != NULL) {
        printf("%d -> ", lista->valor);
        lista = lista->prox;
    }
    printf("NULL\n");
}

// ---- INSERÇÃO ORDENADA ----
Lista* inserirOrdenado(Lista *lista, int valor) {
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    novo->valor = valor;
    novo->prox = NULL;

    if (lista == NULL || valor < lista->valor) {
        novo->prox = lista;
        return novo;
    }

    Lista *atual = lista;
    while (atual->prox != NULL && atual->prox->valor < valor)
        atual = atual->prox;

    novo->prox = atual->prox;
    atual->prox = novo;
    return lista;
}

// ---- PESQUISAR ELEMENTO ----
Lista* localizarElemento(Lista *lista, int valor) {
    while (lista != NULL) {
        if (lista->valor == valor)
            return lista;
        lista = lista->prox;
    }
    return NULL;
}

// ---- EXCLUIR ELEMENTO ----
Lista* excluirElemento(Lista *lista, int valor) {
    if (listaVazia(lista)) return lista;

    Lista *atual = lista;
    Lista *anterior = NULL;

    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("\nValor não encontrado!\n");
        return lista;
    }

    if (anterior == NULL) // primeiro nó
        lista = atual->prox;
    else
        anterior->prox = atual->prox;

    free(atual);
    printf("\nValor %d removido com sucesso!\n", valor);
    return lista;
}

// ---- ALTERAR ELEMENTO ----
void alterarElemento(Lista *lista, int valorAntigo, int novoValor) {
    Lista *no = localizarElemento(lista, valorAntigo);
    if (no == NULL) {
        printf("\nElemento %d não encontrado!\n", valorAntigo);
        return;
    }
    no->valor = novoValor;
    printf("\nElemento alterado de %d para %d!\n", valorAntigo, novoValor);
}

// ---- MENU ----
void menu() {
    printf("\n=== MENU LISTA ENCADEADA ===\n");
    printf("1 - Inserir elemento (ordenado)\n");
    printf("2 - Alterar elemento\n");
    printf("3 - Excluir elemento\n");
    printf("4 - Localizar elemento\n");
    printf("5 - Exibir todos os elementos\n");
    printf("6 - Exibir quantidade de elementos\n");
    printf("0 - Sair\n");
    printf("Escolha: ");
}

// ---- PROGRAMA PRINCIPAL ----
int main() {
    Lista *lista = criarLista();
    int opcao, valor, novoValor;

    do {
        menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a inserir: ");
                scanf("%d", &valor);
                lista = inserirOrdenado(lista, valor);
                printf("Inserido com sucesso!\n");
                break;

            case 2:
                printf("Digite o valor a alterar: ");
                scanf("%d", &valor);
                printf("Digite o novo valor: ");
                scanf("%d", &novoValor);
                alterarElemento(lista, valor, novoValor);
                break;

            case 3:
                printf("Digite o valor a excluir: ");
                scanf("%d", &valor);
                lista = excluirElemento(lista, valor);
                break;

            case 4:
                printf("Digite o valor a localizar: ");
                scanf("%d", &valor);
                if (localizarElemento(lista, valor))
                    printf("Elemento %d encontrado!\n", valor);
                else
                    printf("Elemento %d não encontrado!\n", valor);
                break;

            case 5:
                exibirLista(lista);
                break;

            case 6:
                printf("\nTotal de elementos: %d\n", totalElementosLista(lista));
                break;

            case 0:
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\nOpção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}
