#include "pilha.h"
#include <stdio.h>

char restos[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

void imprimeBase2(int numeroDecimal, int base){
  Pilha* pilha = Stack();
  while(numeroDecimal>0){
    int resto = numeroDecimal%base;
    push(pilha, restos[resto]);
    numeroDecimal /=base;
  }
  while(!isEmpty(pilha)){
    printf("%c", pop(pilha));
  }
 }



int main() {
  int base = 16;
  int numeroDecimal = 233;
  imprimeBase2(numeroDecimal,base);

}

