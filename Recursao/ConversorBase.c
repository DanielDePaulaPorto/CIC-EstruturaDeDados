#include <stdio.h>

void imprime_outra_base(int numero_base10, int base) {
  if (numero_base10 < base) {
    numero_base10>9?printf("%c",'A'+(numero_base10-10)):printf("%d", numero_base10);
  } else {
    int div = numero_base10 / base;
    int resto = numero_base10 % base;

    imprime_outra_base(div,base);
    resto >9?printf("%c",'A'+(resto-10)):printf("%d", resto);
  }
}

int main() {
  printf("Conversor de Base\n");

  int numero_base10;
  scanf("%d", &numero_base10);

  int base;
  scanf("%d", &base);

  if (base <= 1) {
    printf("Informe uma base maior que 1");
  }

  imprime_outra_base(numero_base10,base);
}
