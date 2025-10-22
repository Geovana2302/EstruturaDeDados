#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void gravar_arquivo(){
  	FILE *arq; // criando a vari�vel ponteiro para o arquivo
  	char palavra[20]; // vari�vel do tipo string
  	int continuar, numero;
  	
  	printf("<<<<Gravar Arquivo>>>>\n\n");
  	
  	arq = fopen("aulaed.txt", "a"); //abrindo/criando o arquivo matendo o conte�do
  	
	if(arq == NULL) //testando se o arquivo foi realmente criado
	{
		printf("Erro na abertura do arquivo!");
	}
	else{
		continuar = 1;
		while(continuar == 1){
			printf("Escreva uma palavra para testar gravacao de arquivo: ");
			fflush(stdin);
			gets(palavra);
			printf("Escreva um Numero: ");
			scanf("%d", &numero);
			
			fprintf(arq, "%s %d\n", palavra, numero); //usando fprintf para armazenar a string no arquivo \n para pular linha
			
			
			printf("Deseja continuar? (1-sim; 2-n�o): ");
			scanf("%d", &continuar);
			system("cls");
		}
	  	  
		fclose(arq); // fechando arquivo
	  	printf("O arquivo foi criado com sucesso!"); //mensagem para o usu�rio
	}	  
}

void ler_arquivo(){
  	FILE *arq; // criando a vari�vel ponteiro para o arquivo
  	char palavra[100]; // vari�vel do tipo string
  	int linhas = 0;
  	system("cls");
  	printf("<<<<Ler Arquivo>>>>\n\n");
  	arq = fopen("aulaed.txt", "r"); //abrindo somente leitura
	if(arq == NULL) //testando se o arquivo foi realmente criado
	{
		printf("Erro na abertura do arquivo!");
	}
	
	else{
		linhas = 0;
		while (fgets(palavra, sizeof(palavra), arq) != NULL){
			printf("%s", palavra);
			linhas++;
		}
		printf("\nQuantidade de Linhas Arquivo: %d", linhas);
		fclose(arq); // fechando arquivo
	  	printf("\n\nO fechado com sucesso!"); //mensagem para o usu�rio
	}	
}

void main(){
	gravar_arquivo();
	ler_arquivo();
}
