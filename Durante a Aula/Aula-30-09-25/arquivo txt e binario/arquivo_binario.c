#include <stdio.h>
#define TF 2

struct aluno{
	float media;
	char nome[100];
};

void carregar_registros(struct aluno reg_aluno[TF]){
	int i;
	printf("<<<Carregar Alunos>>>\n\n");
	for(i=0; i < TF; i++){
		printf("Registro[%d]: \n", i);
		printf("Informe o Nome: ");
		fflush(stdin);
		gets(reg_aluno[i].nome);
		printf("Informe a Media: ");
		scanf("%f", &reg_aluno[i].media);
	}
}

void exibir_registros(struct aluno reg_aluno[TF]){
	int i;
	system("cls");
	printf("<<<Exibir Registros>>>\n\n");
	for(i=0; i<TF; i++){
		printf("\nRegistro[%d]", i);
		printf("\nNome: %s", reg_aluno[i].nome);
		printf("\nMedia: %0.2f", reg_aluno[i].media);
		
		printf("\n\nPress 1 para alterar registro, ou qq tecla para continuar...");
		system("pause");
	}
}

void gravar_arquivo(struct aluno reg_aluno[TF]){
	FILE *arq;
	int i;
	system("cls");
	printf("<<Gravando Registros no Arquivo>>\n\n");
	arq = fopen("aluno.bin", "wb");
	if(arq == NULL){
		printf("Erro ao abrir o arquivo!!!");
	}
	else{
		for(i=0; i<TF; i++){
			fwrite(&reg_aluno[i], sizeof(struct aluno), 1, arq);
		}
		fclose(arq);
		printf("Registros Gravados com Sucesso!!!");
	}
	system("pause");
}

void ler_arquivo(struct aluno reg_aluno[TF]){
	int i;
	FILE *arq;
	printf("<<Lendo Arquivo de Registros>>\n\n");
	arq = fopen("aluno.bin", "rb");
	if (arq ==NULL){
		printf("Erro ao abrir o arquivo!!!");
	}
	else{
		i = 0;
		while(fread(&reg_aluno[i], sizeof(struct aluno), 1, arq) > 0){
			i++;
		}
		fclose(arq);
		printf("Registros Lidos com Sucesso!!!");
		system("pause");
	}
}
void main(){
	struct aluno reg_aluno[TF];
	//carregar_registros(reg_aluno);
	//gravar_arquivo(reg_aluno);
	ler_arquivo(reg_aluno);
	exibir_registros(reg_aluno);
}
