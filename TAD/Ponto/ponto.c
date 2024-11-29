#include "ponto.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct implementacaoPonto{
    double coordenada_x;
    double coordenada_y;
};

Ponto* cria_ponto(double x, double y){
    Ponto* ponto = (Ponto*) malloc( sizeof(Ponto));
    if(ponto!=NULL){
        ponto->coordenada_x = x;
        ponto->coordenada_y = y;
    }
    return ponto;
}

void liberaPonto(Ponto* ponto){
    free(ponto);
}

void alteraPonto(Ponto* ponto, double novo_x, double novo_y){
    ponto->coordenada_x = novo_x;
    ponto->coordenada_y = novo_y;
}

void printPonto(Ponto *ponto){
    printf("X: %lf, Y:%lf\n\n",ponto->coordenada_x,ponto->coordenada_y);
}

Ponto* produto(Ponto* ponto, int valor){
    return cria_ponto(ponto->coordenada_y*valor, ponto->coordenada_x*valor);
}

double distancia(Ponto *p1, Ponto *p2){
    if( p1 == NULL || p2 == NULL){
        return -1;
    }
    double x = pow(p1->coordenada_x - p2->coordenada_x,2);
    double y = pow(p1->coordenada_y - p2->coordenada_y,2);
    printf("x: %lf\ny: %lf\nDist: %lf\n",x,y,sqrt(x+y));
    return sqrt(x+y);
}

