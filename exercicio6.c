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

void estatisticas(No *inicio, int *qtd, int *maior, int *menor, int *soma, float *media) {
    *qtd = 0;
    *soma = 0;
    *media = 0;

    if (inicio == NULL) {
        return;
    }

    *maior = inicio->dado;
    *menor = inicio->dado;

    No *aux = inicio;
    while (aux != NULL) {
        (*qtd)++;
        *soma += aux->dado;
        if (aux->dado > *maior) {
            *maior = aux->dado;
        }
        if (aux->dado < *menor) {
            *menor = aux->dado;
        }
        aux = aux->proximo;
    }
    *media = (float)*soma / *qtd;
}

int main() {
    No *lista = NULL;
    int n, valor, i;
    int qtd, maior, menor, soma;
    float media;

    printf("Quantos elementos? ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Valor: ");
        scanf("%d", &valor);
        inserirFinal(&lista, valor);
    }

    estatisticas(lista, &qtd, &maior, &menor, &soma, &media);

    if (qtd == 0) {
        printf("Lista vazia\n");
    } else {
        printf("Quantidade: %d\n", qtd);
        printf("Maior: %d\n", maior);
        printf("Menor: %d\n", menor);
        printf("Soma: %d\n", soma);
        printf("Media: %.2f\n", media);
    }

    while (lista != NULL) {
        No *temp = lista;
        lista = lista->proximo;
        free(temp);
    }
    return 0;
}
