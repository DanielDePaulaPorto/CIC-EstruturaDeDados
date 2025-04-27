#include <iso646.h>
#include <stdio.h>

void resolve_torre_hanoi(int n, char origem, char destino, char aux) {
  if (n>0) {
    resolve_torre_hanoi(n-1, origem, aux,destino);
    printf("Move o disco %d da torre %c para a torre %c\n",n,origem,destino);
    resolve_torre_hanoi(n-1,aux,destino,origem);
  }


}

int main() {
  printf("Torre de Hanoi\n");
  int discos = 3;
  resolve_torre_hanoi(discos,'A','C','B');

}