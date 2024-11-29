#include "ponto.h"
#include <stdio.h>

int main () {

    Ponto *ponto1, *ponto2, *ponto3;

    ponto1 = cria_ponto(0,3);

    ponto2 = cria_ponto(4,0);

    printPonto(ponto1);
    printPonto(ponto2);

    ponto3 = produto(ponto1,2);

    printPonto(ponto3);

    double dis = distancia(ponto1,ponto2);
    printf("Distancia: %lf\n", dis);

    return 0;
}