#include <stdio.h>

int caminhos(int n, int m) {
  if(n == 0 && m == 0) {
    return 1;
  }

  int x=0;
  int y=0;
  if (n>0) {
    x = caminhos(n-1,m);
  }
  if (m>0) {
    y = caminhos(n,m-1);
  }
  return x+y;
}

int main() {
  int n,m;

  n = 20;
  m = 20;

  int qtd = caminhos(n,m);

  printf("%d\n",qtd);

  return 0;
}
