#include <stdio.h>

int main() {

  int n;
  scanf("%d", &n);

  int soma = 0;

  for (int i = 0; i< n;i++) {
    int num;
    scanf("%d", &num);
    soma+=num;
  }

  long somaGauss = (long)(n*(n+1)/2);

  printf("%d\n", somaGauss-soma);
}

