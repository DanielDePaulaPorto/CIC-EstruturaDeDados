#include <stdio.h>
#include "arvore.h"

int main() {
  ArvoreBB* a = cria_arvore();
  insere_elemento(50,a);
  insere_elemento(20,a);
  insere_elemento(40,a);
  insere_elemento(90,a);
  insere_elemento(10,a);
  insere_elemento(30,a);
  insere_elemento(60,a);
  printf("Tamanho da arvore: %d\n\n",a->tamanho);
  imprime_arvore_in_order(a->raiz);
  printf("\n\n");
  imprime_arvore_pre_order(a->raiz);

  printf("\n\n");

  if (busca_elemento(10,a)) {
    printf("Tem o elemento 10\n");
  }
  if (busca_elemento(100,a)) {
    printf("Tem o elemento 100\n");
  }

  remove_elemento(20, a);
  imprime_arvore_in_order(a->raiz);

  printf("\n");
  imprime_arvore_pre_order(a->raiz);
}
