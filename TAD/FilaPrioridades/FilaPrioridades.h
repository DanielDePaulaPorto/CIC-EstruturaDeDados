
#ifndef FILAPRIORIDADES_H
#define FILAPRIORIDADES_H

#include "../Fila/Fila.h"

typedef struct {
    Fila* filaMais80;
    Fila* filaMais60;
    Fila* filaJovens;
    int tamanho; // Número de elementos na fila
} FilaPrioridades;

FilaPrioridades* NovaFilaPrioridades();

void addPessoa(FilaPrioridades* filaP, int idade);

int removePessoa(FilaPrioridades* filaP);

void imprimeFilaPrioridades(FilaPrioridades* filaP);

#endif //FILAPRIORIDADES_H
