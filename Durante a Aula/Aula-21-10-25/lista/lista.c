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
    //reserva mem�ria para o novo n�
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
            if (pont->prox == NULL) { //encontrou o �ltimo
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

        return 0; //se n�o achar
    }

}

Lista* removerInicioLista(Lista *lista) {

    if (listaVazia(lista))
        return NULL;
    else {
        Lista *removerNo = lista;

        if (lista->prox != NULL) //tem pelo menos 2 n�s
            lista = lista->prox;
        else  //tem apenas um n�s
            lista = NULL;

        free(removerNo);

        return lista;
    }
}

Lista* removerFinalLista(Lista *lista) {
	Lista *no;
	
    if (!listaVazia(lista)) {
        if (lista->prox == NULL) { //verifica se existe s� 1 n� {
            free(lista);
            lista = NULL;
        }
        else {
           for (no = lista; no != NULL; no = no->prox) {
               if (no->prox->prox == NULL) { //identifica pen�lt. n�
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
                //n� encontrado est� no in�cio da lista
                lista = removerInicioLista(lista);
                break;
            }
                if (no_atual->prox == NULL) {
                //n� encontrado est� no fim da lista
                removerFinalLista(lista);
                break;
            }
            //n� encontrado est� no meio da lista
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
    else if (lista->prox == NULL) { //s� tem um n�
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
                if (no_atual == lista) //n� entra na frente
                    lista = inserirNoInicioLista(lista, valor);
                else {
                    // n� entra no meio na ordem certa
                    Lista *novo_no = (Lista*)malloc(sizeof(Lista));
                    novo_no->valor = valor;
                    novo_no->prox  = no_atual;
                    no_anterior->prox = novo_no;
                }
                return lista;
            }
            no_anterior = no_atual;
        }
        //o n�mero � maior que todos valores dos n�s existentes
        inserirNoFinalLista(lista, valor);
    }
    return lista;
}


void main() {

    printf("Cria��o da lista\n");
    Lista *lista1 = criarLista();

    Lista *lista2 = criarLista();

    exibirLista(lista1);

    printf("Inser��o de um n� no In�cio\n");
    lista1 = inserirNoInicioLista(lista1, 10);
    exibirLista(lista1);


    printf("Inser��o de um n� no In�cio\n");
    lista2 = inserirNoInicioLista(lista2, 333);
    exibirLista(lista2);

    printf("Inser��o de um n� no In�cio\n");
    lista1 = inserirNoInicioLista(lista1, 15);
    exibirLista(lista1);

    printf("Inser��o de um n� no Fim\n");
    inserirNoFinalLista(lista1, 30);
    exibirLista(lista1);

    printf("Total de elementos: %d\n",totalElementosLista(lista1));

    printf("Inser��o de um n� no Fim\n");
    inserirNoFinalLista(lista1, 45);
    exibirLista(lista1);

    printf("Inser��o de um n� no Fim\n");
    inserirNoFinalLista(lista2, 777);
    exibirLista(lista2);


    printf("Remover um n� do In�cio\n");
    lista1 = removerInicioLista(lista1);
    exibirLista(lista1);

    printf("Inser��o de um n� no In�cio\n");
    lista1 = inserirNoInicioLista(lista1, 55);
    exibirLista(lista1);

    printf("Pesquisar o n� 30\n");
    if (pesquisarElemento(lista1, 30))
        printf("Encontrado\n");
    else
        printf("N�O Encontrado\n");

    printf("Remover n� de valor 10\n");
    lista1 = removerQualquerNo(lista1, 10);
    exibirLista(lista1);

    printf("Inser��o de um n� por ordem\n");
    lista1 = inserirNoOrdenado(lista1, 35);
    exibirLista(lista1);

    printf("Inser��o de um n� por ordem\n");
    lista1 = inserirNoOrdenado(lista1, 3);
    exibirLista(lista1);

    printf("Inser��o de um n� por ordem\n");
    lista1 = inserirNoOrdenado(lista1, 44);
    exibirLista(lista1);

    printf("Inser��o de um n� por ordem\n");
    lista1 = inserirNoOrdenado(lista1, 70);
    exibirLista(lista1);


    printf("Remover um n� do Fim\n");
    lista1 = removerFinalLista(lista1);
    exibirLista(lista1);

    printf("Remover um n� do Fim\n");
    lista1 = removerFinalLista(lista1);
    exibirLista(lista1);

    printf("Remover um n� do Fim\n");
    lista1 = removerFinalLista(lista1);
    exibirLista(lista1);
}
