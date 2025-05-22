#include <stdio.h>
#include "Fila.h"

int main() {
  Fila* minhaFila = queue();

  // Adiciona elementos
  enqueue(minhaFila, 10);
  enqueue(minhaFila, 20);
  enqueue(minhaFila, 30);
  enqueue(minhaFila, 25);

  // Imprime a Fila
  imprimeFila(minhaFila);

  // Remove e verifica elementos
  int dado = front(minhaFila);
  dequeue(minhaFila);
  printf("Removendo o primeiro da fila: %d\n", dado);
  imprimeFila(minhaFila);

  // Verifica se a lista está vazia
  printf("Fila está vazia: ");
  if (isEmpty(minhaFila)) {
    printf("Sim");
  } else {
    printf("Não (Tamanho: %d )",size(minhaFila));
  }

  // Libera a lista
  liberaFila(minhaFila);

  return 0;
}


