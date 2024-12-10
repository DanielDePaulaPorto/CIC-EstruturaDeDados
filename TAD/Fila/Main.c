#include <stdio.h>
#include "Fila.h"

int main() {
  Fila* minhaFila = Queue();

  // Adiciona elementos
  enqueue(minhaFila, 10);
  enqueue(minhaFila, 20);
  enqueue(minhaFila, 30);
  enqueue(minhaFila, 45);

  // Imprime a fila
  imprimeFila(minhaFila);

  int primeiro = front(minhaFila);
  printf("O primeiro item da fila é %d\n",primeiro);

  // Remove e verifica elementos
  dequeue(minhaFila);
  imprimeFila(minhaFila);

  // Insere mais um elemento na fila
  enqueue(minhaFila, 55);
  imprimeFila(minhaFila);

  // Remove e verifica elementos
  dequeue(minhaFila);
  imprimeFila(minhaFila);

  // Verifica se a fila está vazia
  printf("Fila está vazia: ");
  if (isEmpty(minhaFila)) {
    printf("Sim");
  } else {
    printf("Não (Tamanho: %d )",minhaFila->tamanho);
  }
  return 0;
}


