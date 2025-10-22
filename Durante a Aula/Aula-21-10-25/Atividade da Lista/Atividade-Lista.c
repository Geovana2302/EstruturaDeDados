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



Lista* alterarElementoOrdenado(Lista* lista, int valorAntigo, int valorNovo) {
    
    if (pesquisarElemento(lista, valorAntigo)) {
        lista = removerQualquerNo(lista, valorAntigo);
        
        lista = inserirNoOrdenado(lista, valorNovo);
        printf("Elemento %d alterado para %d com sucesso!\n", valorAntigo, valorNovo);
    } else {
        printf("Elemento %d nao encontrado na lista. Nada foi alterado.\n", valorAntigo);
    }
    
    return lista;
}


void main() {
	Lista *lista1 = criarLista();
	int opcao = -1;
	int valor, valorAntigo, valorNovo;
	
	while (opcao != 0) {
		printf("\n--- MANIPULACAO DE LISTA ENCADEADA ---\n");
		printf("1. Inserir elemento (ordenado)\n");
		printf("2. Alterar elemento\n");
		printf("3. Excluir elemento\n");	
		printf("4. Localizar elemento\n");
		printf("5. Exibir todos os elementos\n");
		printf("6. Exibir quantidade de elementos\n");
		printf("0. Sair\n");
		printf("----------------------------------------\n");
		printf("Escolha uma opcao: ");
		
		scanf("%d", &opcao);
		
		switch (opcao) {
			case 1:
				printf("Digite o valor a ser INSERIDO: ");
				scanf("%d", &valor);
				lista1 = inserirNoOrdenado(lista1, valor);
				exibirLista(lista1);
				break;
				
			case 2:
			    printf("Digite o valor que deseja ALTERAR: ");
			    scanf("%d", &valorAntigo);
			    printf("Digite o NOVO valor: ");
			    scanf("%d", &valorNovo);
			    lista1 = alterarElementoOrdenado(lista1, valorAntigo, valorNovo);
			    exibirLista(lista1);
			    break;
				
			case 3:
                printf("Digite o valor a ser EXCLUIDO: ");
                scanf("%d", &valor);
                if (pesquisarElemento(lista1, valor)) {
                    lista1 = removerQualquerNo(lista1, valor);
                    printf("Elemento %d removido com sucesso!\n", valor);
                    exibirLista(lista1); 
                } else {
                    printf("Elemento %d NAO ENCONTRADO na lista. Nada foi removido.\n", valor);
                }
                
                break;
            case 4: 
             	printf("Digite o valor a ser LOCALIZADO: ");
                scanf("%d", &valor);
                if (pesquisarElemento(lista1, valor)) {
                    printf("Elemento %d ENCONTRADO na lista.\n", valor);
                } else {
                    printf("Elemento %d NAO ENCONTRADO na lista.\n", valor);
                }
                break;

            case 5:
                printf("Elementos da lista:\n");
                exibirLista(lista1);
                break;

            case 6:
                printf("Total de elementos na lista: %d\n", totalElementosLista(lista1));
                break;

            case 0:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
            	
		}
	}
}

