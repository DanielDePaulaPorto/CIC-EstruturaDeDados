#include "ponto.h"
#include <stdio.h>
#include <math.h>

Ponto cria_ponto(int x, int y){
  Ponto p;
  p.x = x;
  p.y = y;
  return p;
}

void imprime_ponto(Ponto p){
  printf("Ponto: (%d, %d)\n", p.x, p.y);
}

int get_quadrante(Ponto p) {
  if (p.x > 0) {
    if (p.y > 0) {
      return 1;
    } else {
      return 4;
    }
  } else {
    if (p.y > 0) {
      return 2;
    } else {
      return 3;
    }
  }
}

float get_distancia_entre_pontos(Ponto p1, Ponto p2) {
  return (sqrt( pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2)));
}