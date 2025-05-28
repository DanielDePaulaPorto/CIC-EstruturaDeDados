#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"


// Criação de uma pilha nova e vazia
Pilha* stack() {
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));
    if (pilha) {
        pilha->topo = NULL;
        pilha->tamanho = 0;
    }
    return pilha;
}

// Insere um item novo na pilha
void push(Pilha* p, int item) {
    No* novo = (No*) malloc(sizeof(No));
    if (novo) {
        novo->dado = item;
        novo->anterior = p->topo;
        p->topo = novo;
        p->tamanho++;
    }


}



// Remove um item da pilha
int pop(Pilha* p) {
    if (p->tamanho == 0) return 0;

    No* topoAtual = p->topo;
    p->topo = topoAtual->anterior;
    free(topoAtual);
    p->tamanho--;
    return 1;
}


// Retorna o topo da pilha
No* peak(Pilha* p) {
    return p->topo;
}

// Verifica se a pilha está vazia
int isEmpty(Pilha* p) {
    return p->tamanho == 0;
}

// Retorna o tamanho da pilha
int size(Pilha* p) {
    return p->tamanho;
}


// Imprime todos os elementos da pilha
void imprimePilha(Pilha* p) {
    No* atual = p->topo;
    printf("Pilha: \n");
    while (atual != NULL) {
        printf("%d \n", atual->dado);
        atual = atual->anterior;
    }
    printf("---\n");
}

// Remove a memória ocupada pela pilha
int liberaPilha(Pilha* p) {
    No* atual = p->topo;
    while (atual != NULL) {
        No* anterior = atual->anterior;
        free(atual);
        atual = anterior;
    }
    free(p);
    return 1;
}
