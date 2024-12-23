
#include "FilaPrioridades.h"

#include <stdio.h>

#include "../Fila/Fila.h"
#include <stdlib.h>

FilaPrioridades* NovaFilaPrioridades(){
  Fila* fila1 = Queue();
  Fila* fila2 = Queue();
  Fila* fila3 = Queue();

  FilaPrioridades* filaP = (FilaPrioridades*) malloc( sizeof(FilaPrioridades) );
  filaP->filaMais80 = fila1;
  filaP->filaMais60 = fila2;
  filaP->filaJovens = fila3;
  filaP->tamanho = 0;

  return filaP;
 }

void addPessoa(FilaPrioridades* filaP, int idade){
  if(idade < 60){
      enqueue(filaP->filaJovens, idade);
  }
  else if(idade < 80){
      enqueue(filaP->filaMais60, idade);
  }
  else{
      enqueue(filaP->filaMais80, idade);
  }
  filaP->tamanho++;
}

int removePessoa(FilaPrioridades* filaP){
  if(!isEmpty(filaP->filaMais80)){
      filaP->tamanho--;
      return dequeue(filaP->filaMais80);
  }

    if(!isEmpty(filaP->filaMais60)){
        filaP->tamanho--;
        return dequeue(filaP->filaMais60);
    }

    if(!isEmpty(filaP->filaJovens)){
        filaP->tamanho--;
        return dequeue(filaP->filaJovens);
    }

}

void imprimeFilaPrioridades(FilaPrioridades* filaP){

    printf("Fila de Prioridades - Tamanho: %d\n", filaP->tamanho);
    imprimeFila(filaP->filaMais80);
    printf("---\n");
    imprimeFila(filaP->filaMais60);
    printf("---\n");
    imprimeFila(filaP->filaJovens);
    printf("#########\n\n");
}