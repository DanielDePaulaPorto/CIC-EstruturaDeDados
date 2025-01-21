#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

// Criação de uma nova lista
Lista* criaLista() {
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->tamanho = 0;
    return lista;
}

// Insere um item no início da lista
void add(Lista* l, int item) {
    No* novo = (No*) malloc(sizeof(No));
    novo->dado = item;
    novo->prox = l->inicio;
    l->inicio = novo;
    l->tamanho++;
}

// Remove o primeiro nó com o valor especificado
int removeItem(Lista* l, int item) {
    if (l->inicio == NULL) return 0;

    No* atual = l->inicio;
    No* anterior = NULL;

    while (atual != NULL) {
        if (atual->dado == item) {
            if (anterior == NULL) {
                l->inicio = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual); // Não pode esquecer de dar o free!!!!!
            l->tamanho--;
            return 1;
        }
        anterior = atual;
        atual = atual->prox;
    }
    return 0; // Item não encontrado
}

// Procura um item na lista
int search(Lista* l, int item) {
    No* atual = l->inicio;
    while (atual != NULL) {
        if (atual->dado == item) return 1;
        atual = atual->prox;
    }
    return 0; // Item não encontrado
}

// Verifica se a lista está vazia
int isEmpty(Lista* l) {
    return l->tamanho == 0;
}

// Adiciona um item ao final da lista
void append(Lista* l, int item) {
    No* novo = (No*) malloc(sizeof(No));
    novo->dado = item;
    novo->prox = NULL;

    if (l->inicio == NULL) {
        l->inicio = novo;
    } else {
        No* atual = l->inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
    l->tamanho++;
}

// Retorna a posição de um item na lista
int index(Lista* l, int item) {
    No* atual = l->inicio;
    int pos = 0;

    while (atual != NULL) {
        if (atual->dado == item) return pos;
        atual = atual->prox;
        pos++;
    }
    return -1; // Item não encontrado
}

int insereOrdenado(Lista* l, int item){
    No* novo = (No*) malloc(sizeof(No));
    novo->dado = item;
    novo->prox = NULL;

    if (l->tamanho == 0){
      l->inicio = novo;
      l->tamanho++;
      return 1;
    }

    No* atual = l->inicio;
    No* proximo = atual->prox;
    while (proximo != NULL){
      if (proximo != NULL && proximo->dado >= item){
        atual->prox = novo;
        novo->prox = proximo;
          return 1;
      }
      atual = proximo;
        proximo = proximo->prox;
    }
    atual->prox = novo;
}

// Insere um item em uma posição específica
int insert(Lista* l, int pos, int item) {
    if (pos < 0 || pos > l->tamanho) return 0;

    No* novo = (No*) malloc(sizeof(No));
    novo->dado = item;

    if (pos == 0) {
        novo->prox = l->inicio;
        l->inicio = novo;
    } else {
        No* atual = l->inicio;
        for (int i = 0; i < pos - 1; i++) {
            atual = atual->prox;
        }
        novo->prox = atual->prox;
        atual->prox = novo;
    }
    l->tamanho++;
    return 1;
}

// Remove e retorna o último item da lista
int pop(Lista* l) {
    if (l->inicio == NULL) return -1; // Lista vazia

    No* atual = l->inicio;
    No* anterior = NULL;

    while (atual->prox != NULL) {
        anterior = atual;
        atual = atual->prox;
    }

    int valor = atual->dado;

    if (anterior == NULL) {
        l->inicio = NULL; // Lista tinha apenas um elemento
    } else {
        anterior->prox = NULL;
    }

    free(atual);
    l->tamanho--;
    return valor;
}

// Remove e retorna o item de uma posição específica
int popPos(Lista* l, int pos) {
    if (pos < 0 || pos >= l->tamanho) return -1;

    No* atual = l->inicio;
    No* anterior = NULL;

    for (int i = 0; i < pos; i++) {
        anterior = atual;
        atual = atual->prox;
    }

    int valor = atual->dado;

    if (anterior == NULL) {
        l->inicio = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
    l->tamanho--;
    return valor;
}

// Imprime todos os elementos da lista
void imprimeLista(Lista* l) {
    No* atual = l->inicio;
    printf("Lista: ");
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->prox;
    }
    printf("\n");
}