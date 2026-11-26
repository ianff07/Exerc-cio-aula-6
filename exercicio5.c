#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *proximo;
} No;

void inserirFinal(No **inicio, int valor) {
    No *novo = malloc(sizeof(No));
    novo->dado = valor;
    novo->proximo = NULL;

    if (*inicio == NULL) {
        *inicio = novo;
        return;
    }
    No *aux = *inicio;
    while (aux->proximo != NULL) {
        aux = aux->proximo;
    }
    aux->proximo = novo;
}

void exibir(No *inicio) {
    No *aux = inicio;
    while (aux != NULL) {
        printf("%d -> ", aux->dado);
        aux = aux->proximo;
    }
    printf("NULL\n");
}

void removerInicio(No **inicio) {
    if (*inicio == NULL) {
        printf("Lista vazia\n");
        return;
    }
    No *temp = *inicio;
    *inicio = temp->proximo;
    free(temp);
}

void removerFinal(No **inicio) {
    if (*inicio == NULL) {
        printf("Lista vazia\n");
        return;
    }
    if ((*inicio)->proximo == NULL) {
        free(*inicio);
        *inicio = NULL;
        return;
    }
    No *aux = *inicio;
    while (aux->proximo->proximo != NULL) {
        aux = aux->proximo;
    }
    free(aux->proximo);
    aux->proximo = NULL;
}

void removerValor(No **inicio, int valor) {
    No *anterior = NULL;
    No *atual = *inicio;

    while (atual != NULL && atual->dado != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Valor nao encontrado\n");
        return;
    }

    if (anterior == NULL) {
        *inicio = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }
    free(atual);
}

int main() {
    No *lista = NULL;
    int op, valor;

    do {
        printf("\n1 - Inserir no final\n");
        printf("2 - Remover do inicio\n");
        printf("3 - Remover do final\n");
        printf("4 - Remover por valor\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        if (op == 1) {
            printf("Valor: ");
            scanf("%d", &valor);
            inserirFinal(&lista, valor);
        } else if (op == 2) {
            removerInicio(&lista);
        } else if (op == 3) {
            removerFinal(&lista);
        } else if (op == 4) {
            printf("Valor: ");
            scanf("%d", &valor);
            removerValor(&lista, valor);
        }

        if (op >= 1 && op <= 4) {
            exibir(lista);
        }
    } while (op != 0);

    while (lista != NULL) {
        removerInicio(&lista);
    }
    return 0;
}
