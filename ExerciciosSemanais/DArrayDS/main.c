#include <stdio.h>

int main() {
  int matriz[6][6];
  int maior = -63;
  for(int linha = 0; linha < 6; linha++) {
    for(int coluna = 0; coluna < 6; coluna++) {
      scanf("%d", &matriz[linha][coluna]);
    }
  }

  for(int linha = 0; linha < 4; linha++) {
    for(int coluna = 0; coluna < 4; coluna++) {
      int soma = matriz[linha][coluna]+
                  matriz[linha][coluna+1]+
                  matriz[linha][coluna+2]+
                  matriz[linha+1][coluna+1]+
                  matriz[linha+2][coluna]+
                  matriz[linha+2][coluna+1]+
                  matriz[linha+2][coluna+2];
      if(soma > maior) {
        maior = soma;
      }
    }
  }
  printf("%d\n", maior);

}




