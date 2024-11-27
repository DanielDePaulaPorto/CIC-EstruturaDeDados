#include "ponto.h"
#include <stdio.h>

Ponto_R2 cria_ponto(double x, double y){
    Ponto_R2 ponto;
    ponto.coordenada_x = x;
    ponto.coordenada_y = y;
    return ponto;
}

void print(Ponto_R2 ponto){
    printf("X: %lf, Y:%lf\n\n",ponto.coordenada_x,ponto.coordenada_y);
}

Ponto_R2 produto(Ponto_R2 ponto, int valor){
    ponto.coordenada_y*=valor;
    ponto.coordenada_x*=valor;
    return ponto;
}

