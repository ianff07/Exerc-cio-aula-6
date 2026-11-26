#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *proximo;
} No;

void inserirInicio(No **inicio, int valor) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("Sem memoria\n");
        return;
    }
    novo->dado = valor;
    novo->proximo = *inicio;
    *inicio = novo;
}

void exibir(No *inicio) {
    No *aux = inicio;
    while (aux != NULL) {
        printf("%d -> ", aux->dado);
        aux = aux->proximo;
    }
    printf("NULL\n");
}

int main() {
    No *lista = NULL;
    int n, valor, i;

    printf("Quantos elementos deseja inserir? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Valor: ");
        scanf("%d", &valor);
        inserirInicio(&lista, valor);
        exibir(lista);
    }

    while (lista != NULL) {
        No *temp = lista;
        lista = lista->proximo;
        free(temp);
    }
    return 0;
}
