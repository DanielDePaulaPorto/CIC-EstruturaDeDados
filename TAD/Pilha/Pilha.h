#ifndef PILHA_H
#define PILHA_H

typedef struct {
    int dado;
    struct No* prox;
}No;

typedef struct {
    No* topo;  // Ponteiro para o topo da pilha
    int tamanho; // Número de elementos na pilha
} Pilha;

// Criação de uma pilha nova e vazia
Pilha* Stack();

// Insere um item novo no final da pilha
void push(Pilha* p, int item);

// Remove um item da pilha
int pop(Pilha* p);

// Retonra o início da pilha, sem remover
int peak(Pilha* p);

// Verifica se a pilha está vazia
int isEmpty(Pilha* p);

// Imprime todos os elementos da pilha
void imprimePilha(Pilha* p);

#endif //PILHA_H
