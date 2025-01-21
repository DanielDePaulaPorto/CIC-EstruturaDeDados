#ifndef LISTA_H
#define LISTA_H

typedef struct {
    int dado;
    struct No* prox;
} No;

typedef struct {
    No* inicio;  // Ponteiro para o início da lista
    int tamanho; // Número de elementos na lista
} Lista;

// Criação de uma lista nova e vazia
Lista* criaLista();

// Insere um item novo no início da lista
void add(Lista* l, int item);

// Remove um item da lista
int removeItem(Lista* l, int item);

// Procura um item na lista
int search(Lista* l, int item);

// Verifica se a lista está vazia
int isEmpty(Lista* l);

// Adiciona um item ao final da lista
void append(Lista* l, int item);

// Retorna a posição de um item na lista
int index(Lista* l, int item);

// Insere um item em uma posição específica da lista
int insert(Lista* l, int pos, int item);

int insereOrdenado(Lista* l, int item);

// Remove e retorna o último item da lista
int pop(Lista* l);

// Remove e retorna o item na posição especificada
int popPos(Lista* l, int pos);

// Imprime todos os elementos da lista
void imprimeLista(Lista* l);

#endif //LISTA_H
