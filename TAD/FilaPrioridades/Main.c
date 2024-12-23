#include "FilaPrioridades.h"


int main() {

  FilaPrioridades *filaP = NovaFilaPrioridades();

  addPessoa(filaP, 12);
  addPessoa(filaP,32);
  addPessoa(filaP,86);
  addPessoa(filaP,45);
  addPessoa(filaP,72);
  // addPessoa(filaP,93);
  addPessoa(filaP,102);
  addPessoa(filaP,26);
  addPessoa(filaP,65);
  addPessoa(filaP,79);
  // addPessoa(filaP,82);

  imprimeFilaPrioridades(filaP);

  removePessoa(filaP);
  imprimeFilaPrioridades(filaP);

  removePessoa(filaP);
  imprimeFilaPrioridades(filaP);


  removePessoa(filaP);
  imprimeFilaPrioridades(filaP);


  removePessoa(filaP);
  removePessoa(filaP);
  removePessoa(filaP);
  imprimeFilaPrioridades(filaP);


  return 0;
}