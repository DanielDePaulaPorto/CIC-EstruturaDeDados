#include "ponto.h"
#include <stdio.h>

int main() {

  int x, y;
  Ponto p1;
  p1 = cria_ponto(1, 1);
  imprime_ponto(p1);
  printf("Quadrante: %d\n",get_quadrante(p1));

  Ponto p2 = cria_ponto(4, 5);
  imprime_ponto(p2);
  printf("Quadrante: %d\n",get_quadrante(p2));

  printf("Distância entre P1 e P2: %.2f",get_distancia_entre_pontos(p1,p2));

}