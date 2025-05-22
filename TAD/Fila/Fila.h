#ifndef FILA_H
#define FILA_H

typedef struct No{
  int dado;
  struct No* prox;
} No;

typedef struct {
  No* inicio;  // Ponteiro para o início da fila
  No* fim;  // Ponteiro para o final da fila
  int tamanho; // Número de elementos na fila
} Fila;

// Criação de uma fila nova e vazia
Fila* queue();

// Insere um item novo no início da fila
void enqueue(Fila* l, int item);

// Remove um item da fila
int front(Fila* f);

// Remove o primeiro elemento da fila
int dequeue(Fila* f);

// Retorna o tamanho da fila
int size(Fila* f);

// Verifica se a fila está vazia
int isEmpty(Fila* f);

// Imprime todos os elementos da fila
void imprimeFila(Fila* f);

// Remove a memória ocupada pela fila
int liberaFila(Fila* f);

#endif //FILA_H
