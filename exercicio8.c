#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contato {
    char nome[50];
    char telefone[20];
    struct Contato *proximo;
} Contato;

void cadastrar(Contato **inicio) {
    Contato *novo = malloc(sizeof(Contato));
    if (novo == NULL) {
        printf("Sem memoria\n");
        return;
    }

    printf("Nome: ");
    scanf(" %49[^\n]", novo->nome);
    printf("Telefone: ");
    scanf(" %19[^\n]", novo->telefone);
    novo->proximo = NULL;

    if (*inicio == NULL) {
        *inicio = novo;
        return;
    }
    Contato *aux = *inicio;
    while (aux->proximo != NULL) {
        aux = aux->proximo;
    }
    aux->proximo = novo;
    printf("Contato cadastrado!\n");
}

void buscar(Contato *inicio) {
    char nome[50];
    printf("Nome para buscar: ");
    scanf(" %49[^\n]", nome);

    Contato *aux = inicio;
    while (aux != NULL) {
        if (strcmp(aux->nome, nome) == 0) {
            printf("Encontrado: %s - %s\n", aux->nome, aux->telefone);
            return;
        }
        aux = aux->proximo;
    }
    printf("Contato nao encontrado\n");
}

void remover(Contato **inicio) {
    char nome[50];
    printf("Nome para remover: ");
    scanf(" %49[^\n]", nome);

    Contato *anterior = NULL;
    Contato *atual = *inicio;

    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Contato nao encontrado\n");
        return;
    }

    if (anterior == NULL) {
        *inicio = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }
    free(atual);
    printf("Contato removido!\n");
}

void listar(Contato *inicio) {
    if (inicio == NULL) {
        printf("Agenda vazia\n");
        return;
    }
    Contato *aux = inicio;
    while (aux != NULL) {
        printf("%s - %s\n", aux->nome, aux->telefone);
        aux = aux->proximo;
    }
}

int main() {
    Contato *agenda = NULL;
    int op;

    do {
        printf("\n--- AGENDA ---\n");
        printf("1 - Cadastrar\n");
        printf("2 - Buscar\n");
        printf("3 - Remover\n");
        printf("4 - Listar\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        if (op == 1) {
            cadastrar(&agenda);
        } else if (op == 2) {
            buscar(agenda);
        } else if (op == 3) {
            remover(&agenda);
        } else if (op == 4) {
            listar(agenda);
        }
    } while (op != 0);

    while (agenda != NULL) {
        Contato *temp = agenda;
        agenda = agenda->proximo;
        free(temp);
    }
    return 0;
}
