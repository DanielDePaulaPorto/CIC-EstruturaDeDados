#include <stdio.h>

void converter_base_recursivo(int n, int base) {
     if (n == 0) {
         return;
     }
    converter_base_recursivo(n / base, base);
    int digito = n % base;
    if (digito < 10) {
        printf("%d", digito);
    } else {
        printf("%c", 'A' + (digito - 10));
    }
}

int main(){

    converter_base_recursivo(4,2);
    return 0;
}