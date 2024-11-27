#include "ponto.h"
#include <stdio.h>

int main () {

    Ponto_R2 ponto1, ponto2, ponto3;

    ponto1 = cria_ponto(1.5,-3.7);

    ponto2 = cria_ponto(7.5,37);

    print(ponto1);
    print(ponto2);

    ponto3 = produto(ponto1,2);

    print(ponto3);

    return 0;
}