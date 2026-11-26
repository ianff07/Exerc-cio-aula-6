#include <stdio.h>
#include <stdlib.h>

typedef struct Tarefa {
    int id;
    char descricao[100];
    int concluida;
    struct Tarefa *proximo;
} Tarefa;

void cadastrar(Tarefa **inicio, int *proximoId) {
    Tarefa *nova = malloc(sizeof(Tarefa));
    if (nova == NULL) {
        printf("Sem memoria\n");
        return;
    }

    nova->id = *proximoId;
    (*proximoId)++;
    printf("Descricao: ");
    scanf(" %99[^\n]", nova->descricao);
    nova->concluida = 0;
    nova->proximo = NULL;

    if (*inicio == NULL) {
        *inicio = nova;
    } else {
        Tarefa *aux = *inicio;
        while (aux->proximo != NULL) {
            aux = aux->proximo;
        }
        aux->proximo = nova;
    }
    printf("Tarefa cadastrada com id %d\n", nova->id);
}

void listar(Tarefa *inicio) {
    if (inicio == NULL) {
        printf("Nenhuma tarefa cadastrada\n");
        return;
    }
    Tarefa *aux = inicio;
    while (aux != NULL) {
        printf("[%d] %s - %s\n", aux->id, aux->descricao,
               aux->concluida ? "Concluida" : "Pendente");
        aux = aux->proximo;
    }
}

Tarefa *localizar(Tarefa *inicio, int id) {
    Tarefa *aux = inicio;
    while (aux != NULL) {
        if (aux->id == id) {
            return aux;
        }
        aux = aux->proximo;
    }
    return NULL;
}

void concluir(Tarefa *inicio) {
    int id;
    printf("Id da tarefa: ");
    scanf("%d", &id);

    Tarefa *t = localizar(inicio, id);
    if (t == NULL) {
        printf("Tarefa nao encontrada\n");
    } else {
        t->concluida = 1;
        printf("Tarefa marcada como concluida\n");
    }
}

void remover(Tarefa **inicio) {
    int id;
    printf("Id da tarefa: ");
    scanf("%d", &id);

    Tarefa *anterior = NULL;
    Tarefa *atual = *inicio;

    while (atual != NULL && atual->id != id) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Tarefa nao encontrada\n");
        return;
    }

    if (anterior == NULL) {
        *inicio = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }
    free(atual);
    printf("Tarefa removida\n");
}

void liberar(Tarefa **inicio) {
    while (*inicio != NULL) {
        Tarefa *temp = *inicio;
        *inicio = temp->proximo;
        free(temp);
    }
}

int main() {
    Tarefa *lista = NULL;
    int proximoId = 1;
    int op, id;

    do {
        printf("\n--- TAREFAS ---\n");
        printf("1 - Cadastrar\n");
        printf("2 - Listar\n");
        printf("3 - Localizar por id\n");
        printf("4 - Marcar como concluida\n");
        printf("5 - Remover\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        if (op == 1) {
            cadastrar(&lista, &proximoId);
        } else if (op == 2) {
            listar(lista);
        } else if (op == 3) {
            printf("Id: ");
            scanf("%d", &id);
            Tarefa *t = localizar(lista, id);
            if (t != NULL) {
                printf("[%d] %s - %s\n", t->id, t->descricao,
                       t->concluida ? "Concluida" : "Pendente");
            } else {
                printf("Tarefa nao encontrada\n");
            }
        } else if (op == 4) {
            concluir(lista);
        } else if (op == 5) {
            remover(&lista);
        }
    } while (op != 0);

    liberar(&lista);
    return 0;
}
