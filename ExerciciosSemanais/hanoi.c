#include <stdio.h>

void torre_de_hanoi(int altura, char origem, char destino, char auxiliar) {
    if( altura > 0){
        torre_de_hanoi(altura-1,origem,auxiliar,destino);
        printf("Move o disco %d da torre %c para a torre %c.\n",altura,origem,destino);
        torre_de_hanoi(altura-1, auxiliar, destino,origem);
    }

}

int main() {
    int altura;
    char origem = 'A', destino = 'C', auxiliar = 'B';

    printf("Digite a altura da Torre de Hanoi: ");
    scanf("%d", &altura);

    printf("Os movimentos para resolver a Torre de Hanoi com altura %d são:\n", altura);
    torre_de_hanoi(altura, origem, destino, auxiliar);

    return 0;
}