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

void unir(No **lista1, No *lista2) {
    if (*lista1 == NULL) {
        *lista1 = lista2;
        return;
    }
    No *aux = *lista1;
    while (aux->proximo != NULL) {
        aux = aux->proximo;
    }
    aux->proximo = lista2;
}

int main() {
    No *lista1 = NULL;
    No *lista2 = NULL;
    int n, valor, i;

    printf("Quantos elementos na lista 1? ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Valor: ");
        scanf("%d", &valor);
        inserirFinal(&lista1, valor);
    }

    printf("Quantos elementos na lista 2? ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Valor: ");
        scanf("%d", &valor);
        inserirFinal(&lista2, valor);
    }

    printf("\nLista 1: ");
    exibir(lista1);
    printf("Lista 2: ");
    exibir(lista2);

    unir(&lista1, lista2);
    lista2 = NULL;

    printf("\nLista unida: ");
    exibir(lista1);

    while (lista1 != NULL) {
        No *temp = lista1;
        lista1 = lista1->proximo;
        free(temp);
    }
    return 0;
}
