#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>

#define TF 10

struct funcionario {
    char nome[100], endereco[100], cpf[12]; // Aumentado para 12 para incluir '\0'
    int cargo, idade, sexo, status;
    float salario;
};

void carregar_registros(struct funcionario reg_funcionario[TF], int *qtd) {
    int i = *qtd; // Inicia a partir da quantidade atual
    char continuar = 'S';

    do {
        if (i >= TF) {
            printf("\nLimite de %d funcionarios atingido. Nao e possivel adicionar mais.\n", TF);
            break;
        }

        system("cls");
        printf("\n<<< Registrar Funcionarios >>>\n");
        printf("\n--- Funcionario [%d de %d] ---\n", i + 1, TF);
        
        printf("\nInforme CPF (11 digitos): ");
        fflush(stdin);
        fgets(reg_funcionario[i].cpf, 12, stdin);
        reg_funcionario[i].cpf[strcspn(reg_funcionario[i].cpf, "\n")] = 0;

        // Validação do CPF
        if (strlen(reg_funcionario[i].cpf) != 11) {
            printf("CPF invalido! Deve ter 11 digitos.\n");
            system("pause");
            continue;
        }

        printf("\nInforme o nome: ");
        fflush(stdin);
        fgets(reg_funcionario[i].nome, 100, stdin);
        reg_funcionario[i].nome[strcspn(reg_funcionario[i].nome, "\n")] = 0;
        
        do {
            printf("\nCargos Disponiveis:\n1-Estagiario\n2-RH\n3-Administracao\n4-Financeiro\n5-Atendimento\n6-TI\nEscolha o Cargo: ");
            scanf("%d", &reg_funcionario[i].cargo);
        } while (reg_funcionario[i].cargo < 1 || reg_funcionario[i].cargo > 6);
        
        printf("\nInforme o endereco: ");
        fflush(stdin);
        fgets(reg_funcionario[i].endereco, 100, stdin);
        reg_funcionario[i].endereco[strcspn(reg_funcionario[i].endereco, "\n")] = 0;
        
        printf("\nQual salario: ");
        scanf("%f", &reg_funcionario[i].salario);
        
        printf("\nInforme a idade: ");
        scanf("%d", &reg_funcionario[i].idade);
        
        reg_funcionario[i].status = 1;
        
        do {
            printf("\nInforme o sexo: 1-Masculino ou 2-Feminino: ");
            scanf("%d", &reg_funcionario[i].sexo);
        } while (reg_funcionario[i].sexo != 1 && reg_funcionario[i].sexo != 2);

        i++; (*qtd)++;

        if (i < TF) {
            printf("\nDeseja cadastrar outro funcionario? (S/N): ");
            fflush(stdin);
            scanf(" %c", &continuar);
        } else {
            printf("\nVoce atingiu o limite maximo de funcionarios.\n");
        }

    } while (toupper(continuar) == 'S' && i < TF);

    printf("\nFim do cadastro.\n");
    system("pause");
}

void localizar_funcionario(struct funcionario reg_funcionario[TF]) {
    int i, pos = -1;
    char cpf_busca[12];
    
    system("cls");
    printf("<<< Localizar Funcionario >>>\n\n");
    printf("Digite o CPF do funcionario a ser localizado: ");
    
    fflush(stdin); 
    fgets(cpf_busca, 12, stdin);
    cpf_busca[strcspn(cpf_busca, "\n")] = 0;

    for (i = 0; i < TF; i++) {
        if (strcmp(reg_funcionario[i].cpf, cpf_busca) == 0 && reg_funcionario[i].status == 1) {
            pos = i;
            break;    
        }
    }
    
    if (pos == -1) {
        printf("Registro nao encontrado ou funcionario inativo!\n");
    } else {
        printf("\nRegistro encontrado!\n");
        printf("\nFuncionario [%d]", pos + 1);
        printf("\nNome: %s", reg_funcionario[pos].nome);
        switch (reg_funcionario[pos].cargo) {
            case 1: printf("\nCargo: Estagiario"); break;
            case 2: printf("\nCargo: RH"); break;
            case 3: printf("\nCargo: Administracao"); break;
            case 4: printf("\nCargo: Financeiro"); break;
            case 5: printf("\nCargo: Atendimento"); break;
            case 6: printf("\nCargo: TI"); break;
            default: printf("\nCargo: nao identificado");
        }
        printf("\nEndereco: %s", reg_funcionario[pos].endereco);
        printf("\nSalario: %.2f", reg_funcionario[pos].salario);
        printf("\nCPF: %s", reg_funcionario[pos].cpf);
        printf("\nIdade: %d", reg_funcionario[pos].idade);
        printf("\nSexo: %s", reg_funcionario[pos].sexo == 1 ? "Masculino" : "Feminino");
        printf("\nStatus: %s", reg_funcionario[pos].status == 1 ? "Ativo" : "Inativo");
        printf("\n=============================\n");
    }
    system("pause");
}

void alterar_funcionario(struct funcionario reg_funcionario[TF]) {
    int i, pos = -1;
    char cpf_busca[12];

    system("cls");
    printf("<<< Alterar Funcionario >>>\n\n");
    printf("Digite o CPF do funcionario que deseja alterar: ");

    fflush(stdin);
    fgets(cpf_busca, 12, stdin);
    cpf_busca[strcspn(cpf_busca, "\n")] = 0;

    for (i = 0; i < TF; i++) {
        if (strcmp(reg_funcionario[i].cpf, cpf_busca) == 0 && reg_funcionario[i].status == 1) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("\nFuncionario com este CPF nao foi encontrado ou esta inativo.\n");
    } else {
        printf("\n--- Alterando dados do Funcionario: %s ---\n", reg_funcionario[pos].nome);

        printf("\nInforme o novo nome: ");
        fflush(stdin);
        fgets(reg_funcionario[pos].nome, 100, stdin);
        reg_funcionario[pos].nome[strcspn(reg_funcionario[pos].nome, "\n")] = 0;

        do {
            printf("\nCargos:\n1-Estagiario\n2-RH\n3-Administracao\n4-Financeiro\n5-Atendimento\n6-TI\nEscolha o novo Cargo: ");
            scanf("%d", &reg_funcionario[pos].cargo);
        } while (reg_funcionario[pos].cargo < 1 || reg_funcionario[pos].cargo > 6);

        printf("\nInforme o novo endereco: ");
        fflush(stdin);
        fgets(reg_funcionario[pos].endereco, 100, stdin);
        reg_funcionario[pos].endereco[strcspn(reg_funcionario[pos].endereco, "\n")] = 0;

        printf("\nQual o novo salario: ");
        scanf("%f", &reg_funcionario[pos].salario);

        printf("\nInforme a nova idade: ");
        scanf("%d", &reg_funcionario[pos].idade);

        do {
            printf("\nInforme o sexo (1-Masculino ou 2-Feminino): ");
            scanf("%d", &reg_funcionario[pos].sexo);
        } while (reg_funcionario[pos].sexo != 1 && reg_funcionario[pos].sexo != 2);
        
        printf("\n\nDados do funcionario alterados com sucesso!\n");
    }

    system("pause");
}

void excluir_funcionario(struct funcionario reg_funcionario[TF]) {
    int i, pos = -1;
    char cpf_busca[12], confirmacao;

    system("cls");
    printf("<<< Excluir Funcionario (Logicamente) >>>\n\n");
    printf("Digite o CPF do funcionario que deseja excluir: ");

    fflush(stdin);
    fgets(cpf_busca, 12, stdin);
    cpf_busca[strcspn(cpf_busca, "\n")] = 0;

    for (i = 0; i < TF; i++) {
        if (strcmp(reg_funcionario[i].cpf, cpf_busca) == 0 && reg_funcionario[i].status == 1) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("\nFuncionario com este CPF nao foi encontrado ou ja esta inativo.\n");
    } else {
        printf("\nFuncionario encontrado: %s", reg_funcionario[pos].nome);
        printf("\nTem certeza que deseja excluir? (S/N): ");
        fflush(stdin);
        scanf(" %c", &confirmacao);

        if (toupper(confirmacao) == 'S') {
            reg_funcionario[pos].status = 0;
            printf("\nFuncionario excluido com sucesso!\n");
        } else {
            printf("\nOperacao cancelada.\n");
        }
    }

    system("pause");
}

void ativar_funcionario(struct funcionario reg_funcionario[TF]) {
    int i, pos = -1;
    char cpf_busca[12], confirmacao;

    system("cls");
    printf("<<< Ativar Registro de Funcionario >>>\n\n");
    printf("Digite o CPF do funcionario que deseja reativar: ");

    fflush(stdin);
    fgets(cpf_busca, 12, stdin);
    cpf_busca[strcspn(cpf_busca, "\n")] = 0;

    for (i = 0; i < TF; i++) {
        if (strcmp(reg_funcionario[i].cpf, cpf_busca) == 0 && reg_funcionario[i].status == 0) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("\nFuncionario com este CPF nao foi encontrado ou ja esta ativo.\n");
    } else {
        printf("\nFuncionario inativo encontrado: %s", reg_funcionario[pos].nome);
        printf("\nTem certeza que deseja reativar este registro? (S/N): ");
        fflush(stdin);
        scanf(" %c", &confirmacao);

        if (toupper(confirmacao) == 'S') {
            reg_funcionario[pos].status = 1;
            printf("\nFuncionario reativado com sucesso!\n");
        } else {
            printf("\nOperacao cancelada.\n");
        }
    }

    system("pause");
}

void ordenar_funcionarios_por_nome(struct funcionario reg_funcionario[TF]) {
    struct funcionario temp;
    int i, j;

    system("cls");
    printf("<<< Ordenando Funcionarios por Nome >>>\n\n");

    for (i = 0; i < TF - 1; i++) {
        for (j = i + 1; j < TF; j++) {
            if (reg_funcionario[i].status == 1 && reg_funcionario[j].status == 1 &&
                strcmp(reg_funcionario[i].nome, reg_funcionario[j].nome) > 0) {
                temp = reg_funcionario[i];
                reg_funcionario[i] = reg_funcionario[j];
                reg_funcionario[j] = temp;
            }
        }
    }

    printf("Funcionarios ordenados por nome com sucesso!\n");
    system("pause");
}

void exibir_registro(struct funcionario reg_funcionario[TF], int qtd) {
    int i;
    system("cls");
    printf("\n<<< Exibir Funcionarios >>>\n");
    
    if (qtd == 0) {
        printf("\nNao ha cadastros\n");
    } else {
        for (i = 0; i < qtd; i++) {
            if (reg_funcionario[i].status == 1) {
                printf("\nFuncionario [%d]", i + 1);
                printf("\nNome: %s", reg_funcionario[i].nome);
                switch (reg_funcionario[i].cargo) {
                    case 1: printf("\nCargo: Estagiario"); break;
                    case 2: printf("\nCargo: RH"); break;
                    case 3: printf("\nCargo: Administracao"); break;
                    case 4: printf("\nCargo: Financeiro"); break;
                    case 5: printf("\nCargo: Atendimento"); break;
                    case 6: printf("\nCargo: TI"); break;
                    default: printf("\nCargo: nao identificado");
                }
                printf("\nEndereco: %s", reg_funcionario[i].endereco);
                printf("\nSalario: %.2f", reg_funcionario[i].salario);
                printf("\nCPF: %s", reg_funcionario[i].cpf);
                printf("\nIdade: %d", reg_funcionario[i].idade);
                printf("\nSexo: %s", reg_funcionario[i].sexo == 1 ? "Masculino" : "Feminino");
                printf("\nStatus: %s", reg_funcionario[i].status == 1 ? "Ativo" : "Inativo");
                printf("\n=============================\n");
            }
        }
    }
    system("pause");
}

void gravar_arquivo(struct funcionario reg_funcionario[TF], int qtd) {
    FILE *arq;
    int i;
    system("cls");
    printf("<<< Gravando Registros no Arquivo >>>\n\n");
    arq = fopen("funcionario.bin", "wb");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo: %s\n", strerror(errno));
        system("pause");
        return;
    }
    for (i = 0; i < qtd; i++) {
        fwrite(&reg_funcionario[i], sizeof(struct funcionario), 1, arq);
    }
    if (fclose(arq) != 0) {
        printf("Erro ao fechar o arquivo!\n");
    } else {
        printf("\nRegistros Gravados com Sucesso! (%d registros)\n", qtd);
    }
    system("pause");
}

void ler_arquivo(struct funcionario reg_funcionario[TF], int *qtd) {
    int i = 0;
    FILE *arq;
    system("cls");
    printf("<<Lendo Arquivo de Registros>>\n\n");
    arq = fopen("funcionario.bin", "rb");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo: %s\n", strerror(errno));
        printf("Verifique se o arquivo existe ou o caminho esta correto.\n");
    } else {
        while (fread(&reg_funcionario[i], sizeof(struct funcionario), 1, arq) > 0) {
            i++;
        }
        *qtd = i;
        if (fclose(arq) != 0) {
            printf("Erro ao fechar o arquivo!\n");
        } else {
            printf("Registros Lidos com Sucesso! (%d registros)\n", *qtd);
        }
    }
    system("pause");
}

void excluir_arquivo() {
    system("cls");
    printf("<<< Excluir Arquivo Fisico >>>\n\n");
    if (remove("funcionario.bin") == 0) {
        printf("Arquivo excluido com sucesso!\n");
    } else {
        printf("Erro ao excluir o arquivo ou arquivo nao encontrado: %s\n", strerror(errno));
    }
    system("pause");
}

char Menu(void) {
    system("cls");
    printf("\n<<< MENU DE OPERACOES >>>\n");
    printf("\n[A] Inserir Funcionario\n");
    printf("\n[B] Localizar Funcionario\n");
    printf("\n[C] Alterar Funcionario\n");
    printf("\n[D] Excluir Dados do Vetor (Exclusao Logica)\n");
    printf("\n[E] Ativar Registro Excluido (Ativacao Logica)\n");
    printf("\n[F] Ordenar Dados do Vetor\n");
    printf("\n[G] Exibir Dados do Vetor\n");
    printf("\n[H] Gravar em Arquivo\n");
    printf("\n[I] Recuperar do Arquivo\n");
    printf("\n[J] Excluir do Arquivo\n");
    printf("\n[ESC] SAIR\n");
    printf("\nOpcao Desejada: ");
    return toupper(getchar());
}

void executar(void) {
    int qtde = 0;
    char op;
    struct funcionario reg_funcionario[TF] = {0}; // Inicializa o vetor
    ler_arquivo(reg_funcionario, &qtde);
    
    do {
        op = Menu();
        switch (op) {
            case 'A': carregar_registros(reg_funcionario, &qtde); break;
            case 'B': localizar_funcionario(reg_funcionario); break;
            case 'C': alterar_funcionario(reg_funcionario); break;
            case 'D': excluir_funcionario(reg_funcionario); break;
            case 'E': ativar_funcionario(reg_funcionario); break;
            case 'F': ordenar_funcionarios_por_nome(reg_funcionario); break;
            case 'G': exibir_registro(reg_funcionario, qtde); break;
            case 'H': gravar_arquivo(reg_funcionario, qtde); break;
            case 'I': ler_arquivo(reg_funcionario, &qtde); break;
            case 'J': excluir_arquivo(); break;
        }
    } while (op != 27);
    gravar_arquivo(reg_funcionario, qtde);
}

int main() {
    executar();
    return 0;
}
