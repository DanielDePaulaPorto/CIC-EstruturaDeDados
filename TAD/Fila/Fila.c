#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

Fila* queue() {
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    if (fila) {
        fila->inicio = NULL;
        fila->tamanho = 0;
    }
    return fila;
}

// Insere um item novo no início da fila
void enqueue(Fila* l, int item) {
    No* novo = (No*) malloc(sizeof(No));
    if (novo) {
        novo->dado = item;
        novo->prox = NULL;
        if (l->tamanho == 0) {
            l->inicio = novo;
        } else {
            l->fim->prox = novo;
        }
        l->fim = novo;
        l->tamanho++;
    }
}


// Remove um item da fila
int front(Fila* f) {
    return f->inicio->dado;
}

// Remove o primeiro elemento da fila
int dequeue(Fila* f) {
    if (f->inicio == NULL) return 0;

    No* primeiro = f->inicio;
    No* segundo = primeiro->prox;

    f->inicio = segundo;
    free(primeiro); // Não pode esquecer de dar o free!!!!!
    f->tamanho--;
    return 1;
}

// Verifica se a lista está vazia
int isEmpty(Fila* f) {
    return f->tamanho == 0;
}

// Retorna o tamanho da fila
int size(Fila* f) {
    return f->tamanho;
}

// Imprime todos os elementos da lista
void imprimeFila(Fila* f) {
    No* atual = f->inicio;
    printf("Fila: ");
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->prox;
    }
    printf("\n");
}

// Remove a memória ocupada pela lista
int liberaFila(Fila* f) {
    No* atual = f->inicio;
    while (atual != NULL) {
        No* proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    free(f);
    return 1;
}

