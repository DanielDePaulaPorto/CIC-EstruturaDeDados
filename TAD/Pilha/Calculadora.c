// #include "pilha.h"
#include <stdio.h>




int main() {

  char linha[100];
  int valor = 0;
  char operador;
  while (operador != '/n') {

    if(scanf("%s", &linha)){
      printf("- %s\n", linha);
    }
    else {
      scanf("%d", &valor);
      printf("- %d\n", valor);
    }
  }




}

