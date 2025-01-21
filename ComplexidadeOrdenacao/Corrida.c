#include <stdio.h>
#include <stdlib.h>
#include "../TAD/Lista/Lista.h"

int compare(const void *a, const void *b) {
  return (*(int*)a - *(int*)b);
}


int main() {
  int qtdElementos;

  Lista *lista = criaLista();


  scanf("%d", &qtdElementos);
  // int valores[qtdElementos];
  for (int i = 0; i < qtdElementos; i++) {
    // scanf("%d", &valores[i]);
    int valor;
    scanf("%d", &valor);
    insereOrdenado(lista, valor);
    imprimeLista(lista);
  }

  // qsort(valores, qtdElementos, sizeof(valores[0]), compare);


  // int menorDiferenca = valores[1] - valores[0];
  // for (int i = 1; i < qtdElementos; i++) {
  //   if (valores[i] - valores[i-1] < menorDiferenca) {
  //     menorDiferenca = valores[i] - valores[i-1];
  //   }
  // }

  // imprimeLista(lista);
  int menorDiferenca = 10000;
  No* elementoAtual = lista->inicio;
  for (int i = 0; i < qtdElementos-1; i++) {
    No* proximo = elementoAtual->prox;
    int diferenca = (proximo->dado) - (elementoAtual->dado);

    // printf("Diferença entre %d e %d = %d",i,i+1,diferenca);
    if (diferenca < menorDiferenca) {
      menorDiferenca = diferenca;
    }
    elementoAtual = proximo;
  }

  printf("Menor diferenca: %d", menorDiferenca);
  elementoAtual = lista->inicio;
  for (int i = 1; i < qtdElementos-1; i++) {
    int diferenca = (((No*)(elementoAtual->prox))->dado) - (elementoAtual->dado);
    if (diferenca == menorDiferenca) {
      printf(" (%d, %d)", elementoAtual->dado, ((No*)(elementoAtual->prox))->dado);
    }
    elementoAtual = elementoAtual->prox;
  }

  return 0;
}