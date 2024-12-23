#include <stdlib.h>
#include <stdio.h>
#include "Pilha.h"

int main() {

  Pilha* pilha = Stack();

  push(pilha, 10);
  push(pilha, 20);
  push(pilha, 30);
  push(pilha, 40);

  printf("Tamanho da pilha: %d\n",pilha->tamanho);

  printf("%d\n", peak(pilha));
  imprimePilha(pilha);

  int valor = pop(pilha);
  printf("Valor removido: %d\n", valor);

  imprimePilha(pilha);

  return 0;
}