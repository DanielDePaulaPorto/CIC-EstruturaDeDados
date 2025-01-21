#ifndef FILA_H
#define FILA_H

typedef struct {
    int dado;
    struct No* prox;
} No;

typedef struct {
    No* inicio;
    No* fim;
    int tamanho;
} Fila;

// Criação de uma fila nova e vazia
Fila* Queue();

// Insere um item novo no final da fila
void enqueue(Fila* l, int item);

// Remove um item da fila
int dequeue(Fila* l);

// Retonra o início da fila, sem remover
int front(Fila* l);

// Verifica se a fila está vazia
int isEmpty(Fila* l);

// Imprime todos os elementos da lista
void imprimeFila(Fila* l);

#endif //LISTA_H
