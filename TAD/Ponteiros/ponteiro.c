#include <stdio.h>


int main() {

  int a = 10;
  int *p = &a;
  int **pp = &p;
  int ***ppp = &pp;

  printf("Valor de variável a: %d\n",a);
  printf("endereço de A: %p\n",&a);

  printf("Valor da variável p: %p\n",p);
  printf("Valor onde o Ponteiro p aponta: %d\n",*p);
  printf("endereço do Ponteiro p: %p\n", &p);

  printf("Valor do Ponteiro pp: %p\n", pp);
  printf("Valor *pp: %p\n",*pp);
  printf("Valor **pp: %d\n",**pp);

  printf("Valor do PPP p: %d\n",***ppp);

}


