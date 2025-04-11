#ifndef PONTO_H
#define PONTO_H

typedef struct{
  int x;
  int y;
}Ponto;

Ponto cria_ponto(int x, int y);

void imprime_ponto(Ponto p);

int get_quadrante(Ponto p);

float get_distancia_entre_pontos(Ponto p1, Ponto p2);

#endif //PONTO_H
