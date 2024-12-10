#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

// Criação de uma nova fila
Fila* Queue() {
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
    return fila;
}

// Insere um item no início da lista
void enqueue(Fila* l, int item) {
    No* novo = (No*) malloc(sizeof(No));
    novo->dado = item;
    novo->prox = NULL;
    if (l->fim != NULL) {
        l->fim->prox = novo;
    } else {
        l->inicio = novo;
    }
    l->fim = novo;
    l->tamanho++;
}

// Remove o primeiro nó da fila
int dequeue(Fila* l) {
    if (l->inicio == NULL) return 0;

    No* primeiro = l->inicio;
    l->inicio = l->inicio->prox;
    free(primeiro); // Não pode esquecer de dar o free!!!!!
    l->tamanho--;
    return 1;
}

// Retonra o início da fila, sem remover
int front(Fila* l) {
  if (l->inicio == NULL) return -1;

  return l->inicio->dado;
}

// Verifica se a lista está vazia
int isEmpty(Fila* l) {
    return l->tamanho == 0;
}

// Imprime todos os elementos da lista
void imprimeFila(Fila* l) {
    No* atual = l->inicio;
    printf("Fila: ");
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->prox;
    }
    printf("\n");
}