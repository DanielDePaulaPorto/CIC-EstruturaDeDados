#include <stdio.h>
#include "Pilha.h"

int main() {
  Pilha* minhaPilha = stack();

  // Adiciona elementos
  push(minhaPilha, 10);
  push(minhaPilha, 20);
  push(minhaPilha, 30);
  push(minhaPilha, 25);

  // Imprime a Pilha
  imprimePilha(minhaPilha);

  // Remove e verifica elementos
  printf("Removendo 25: %s\n", pop(minhaPilha) ? "Removido" : "Não encontrado");
  imprimePilha(minhaPilha);

  // Verifica se a Pilha está vazia
  printf("Pilha está vazia: ");
  if (isEmpty(minhaPilha)) {
    printf("Sim");
  } else {
    printf("Não (Tamanho: %d )",minhaPilha->tamanho);
  }

  // Libera a Pilha
  liberaPilha(minhaPilha);

  return 0;
}


