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

No *buscar(No *inicio, int valor, int *posicao) {
    No *aux = inicio;
    int pos = 1;
    while (aux != NULL) {
        if (aux->dado == valor) {
            *posicao = pos;
            return aux;
        }
        aux = aux->proximo;
        pos++;
    }
    *posicao = -1;
    return NULL;
}

int main() {
    No *lista = NULL;
    int n, valor, i, pos;

    printf("Quantos elementos na lista? ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Valor: ");
        scanf("%d", &valor);
        inserirFinal(&lista, valor);
    }

    printf("Valor a buscar: ");
    scanf("%d", &valor);

    No *achado = buscar(lista, valor, &pos);
    if (achado != NULL) {
        printf("Encontrado no endereco %p, posicao %d\n", (void *)achado, pos);
    } else {
        printf("Valor nao encontrado (NULL)\n");
    }

    while (lista != NULL) {
        No *temp = lista;
        lista = lista->proximo;
        free(temp);
    }
    return 0;
}
