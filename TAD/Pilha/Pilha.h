#ifndef PILHA_H
#define PILHA_H

typedef struct No{
  int dado;
  struct No* anterior;
} No;

typedef struct Pilha{
  No* topo;  // Ponteiro para o topo da pilha
  int tamanho; // Número de elementos na pilha
} Pilha;

// Criação de uma pilha nova e vazia
Pilha* stack();

// Insere um item novo na pilha
void push(Pilha* p, int item);

// Remove um item da pilha
int pop(Pilha* p);

// Retorna o topo da pilha
No* peak(Pilha* p);

// Verifica se a pilha está vazia
int isEmpty(Pilha* p);

// Retorna o tamanho da pilha
int size(Pilha* p);

// Imprime todos os elementos da pilha
void imprimePilha(Pilha* p);

// Remove a memória ocupada pela pilha
int liberaPilha(Pilha* p);

#endif //PILHA_H
