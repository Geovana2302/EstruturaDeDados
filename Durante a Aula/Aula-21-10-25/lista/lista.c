#include <stdio.h>
#include <stdlib.h>

struct no {
    int valor;
    struct no *prox;
};

typedef struct no Lista;

Lista* criarLista() {
    return NULL;
}

int listaVazia(Lista *lista) {
    if (lista == NULL)
        return 1;

    return 0;
}

int totalElementosLista(Lista *lista) {
    if (listaVazia(lista))
        return 0;
    else {

        Lista *pont;
        int totalElementos = 0;
        for (pont = lista; pont != NULL; pont = pont->prox)
            totalElementos++;

        return totalElementos;
    }
}

void exibirLista(Lista *lista) {

    if (listaVazia(lista))
        printf("Lista vazia");
    else {
        Lista *pont;
        for (pont = lista; pont != NULL; pont = pont->prox)
            printf("%d -> ", pont->valor);
    }

    printf("\n");
}

Lista* inserirNoInicioLista(Lista *lista, int valor) {
    //reserva memória para o novo nó
    Lista* novoNo = (Lista*) malloc(sizeof(Lista));
    novoNo->valor = valor;
    novoNo->prox = lista;

    return novoNo;
}

Lista* inserirNoFinalLista (Lista* lista, int valor) {

    Lista* novoNo = (Lista*)malloc(sizeof(Lista));
    novoNo->prox = NULL;
    novoNo->valor = valor;

    if (listaVazia(lista))
        lista = novoNo;
    else {
        Lista *pont;
        for (pont = lista; pont != NULL; pont = pont->prox) {
            if (pont->prox == NULL) { //encontrou o último
                pont->prox = novoNo;
                break;
            }
        }
    }

    return lista;
}



int pesquisarElemento(Lista *lista, int valor) {

    if (listaVazia(lista))
        return 0;
    else {

        Lista* pont;
        for (pont = lista; pont != NULL; pont = pont->prox) {
            if (pont->valor == valor)
                return 1;
        }

        return 0; //se não achar
    }

}

Lista* removerInicioLista(Lista *lista) {

    if (listaVazia(lista))
        return NULL;
    else {
        Lista *removerNo = lista;

        if (lista->prox != NULL) //tem pelo menos 2 nós
            lista = lista->prox;
        else  //tem apenas um nós
            lista = NULL;

        free(removerNo);

        return lista;
    }
}

Lista* removerFinalLista(Lista *lista) {
	Lista *no;
	
    if (!listaVazia(lista)) {
        if (lista->prox == NULL) { //verifica se existe só 1 nó {
            free(lista);
            lista = NULL;
        }
        else {
           for (no = lista; no != NULL; no = no->prox) {
               if (no->prox->prox == NULL) { //identifica penúlt. nó
                    Lista *removeNo = no->prox;
                    no->prox = NULL;
                    free(removeNo);
                    break;
                }
            }
        }
    }
    return lista;
}

Lista* removerQualquerNo (Lista *lista, int valor) {
    Lista *no_atual, *no_anterior;
    for (no_atual=lista; no_atual != NULL; no_atual=no_atual->prox) {
        if (no_atual->valor == valor) {
            if (no_atual == lista) {
                //nó encontrado está no início da lista
                lista = removerInicioLista(lista);
                break;
            }
                if (no_atual->prox == NULL) {
                //nó encontrado está no fim da lista
                removerFinalLista(lista);
                break;
            }
            //nó encontrado está no meio da lista
            no_anterior ->prox = no_atual->prox;
            free(no_atual);
            break;
        }
        else
            no_anterior = no_atual;
    }
    return lista;
}

Lista* inserirNoOrdenado (Lista *lista, int valor) {
    if (lista == NULL) {
       lista = inserirNoInicioLista(lista, valor);
       return lista;
    }
    else if (lista->prox == NULL) { //só tem um nó
        if (lista->valor < valor)
            lista = inserirNoFinalLista(lista, valor);
        else
            lista = inserirNoInicioLista(lista, valor);

        return lista;
    }
    else {
        Lista *no_atual, *no_anterior;
        for (no_atual = lista; no_atual != NULL; no_atual = no_atual->prox) {

            if (no_atual->valor > valor) {
                if (no_atual == lista) //nó entra na frente
                    lista = inserirNoInicioLista(lista, valor);
                else {
                    // nó entra no meio na ordem certa
                    Lista *novo_no = (Lista*)malloc(sizeof(Lista));
                    novo_no->valor = valor;
                    novo_no->prox  = no_atual;
                    no_anterior->prox = novo_no;
                }
                return lista;
            }
            no_anterior = no_atual;
        }
        //o número é maior que todos valores dos nós existentes
        inserirNoFinalLista(lista, valor);
    }
    return lista;
}


void main() {

    printf("Criação da lista\n");
    Lista *lista1 = criarLista();

    Lista *lista2 = criarLista();

    exibirLista(lista1);

    printf("Inserção de um nó no Início\n");
    lista1 = inserirNoInicioLista(lista1, 10);
    exibirLista(lista1);


    printf("Inserção de um nó no Início\n");
    lista2 = inserirNoInicioLista(lista2, 333);
    exibirLista(lista2);

    printf("Inserção de um nó no Início\n");
    lista1 = inserirNoInicioLista(lista1, 15);
    exibirLista(lista1);

    printf("Inserção de um nó no Fim\n");
    inserirNoFinalLista(lista1, 30);
    exibirLista(lista1);

    printf("Total de elementos: %d\n",totalElementosLista(lista1));

    printf("Inserção de um nó no Fim\n");
    inserirNoFinalLista(lista1, 45);
    exibirLista(lista1);

    printf("Inserção de um nó no Fim\n");
    inserirNoFinalLista(lista2, 777);
    exibirLista(lista2);


    printf("Remover um nó do Início\n");
    lista1 = removerInicioLista(lista1);
    exibirLista(lista1);

    printf("Inserção de um nó no Início\n");
    lista1 = inserirNoInicioLista(lista1, 55);
    exibirLista(lista1);

    printf("Pesquisar o nó 30\n");
    if (pesquisarElemento(lista1, 30))
        printf("Encontrado\n");
    else
        printf("NÃO Encontrado\n");

    printf("Remover nó de valor 10\n");
    lista1 = removerQualquerNo(lista1, 10);
    exibirLista(lista1);

    printf("Inserção de um nó por ordem\n");
    lista1 = inserirNoOrdenado(lista1, 35);
    exibirLista(lista1);

    printf("Inserção de um nó por ordem\n");
    lista1 = inserirNoOrdenado(lista1, 3);
    exibirLista(lista1);

    printf("Inserção de um nó por ordem\n");
    lista1 = inserirNoOrdenado(lista1, 44);
    exibirLista(lista1);

    printf("Inserção de um nó por ordem\n");
    lista1 = inserirNoOrdenado(lista1, 70);
    exibirLista(lista1);


    printf("Remover um nó do Fim\n");
    lista1 = removerFinalLista(lista1);
    exibirLista(lista1);

    printf("Remover um nó do Fim\n");
    lista1 = removerFinalLista(lista1);
    exibirLista(lista1);

    printf("Remover um nó do Fim\n");
    lista1 = removerFinalLista(lista1);
    exibirLista(lista1);
}
