#include<stdio.h>

void ajusta_nota(float *nota, float incremento);
void print_Media(float *notas, int qtd_Alunos);

int main() {
  int qtd_Alunos = 0;
  float notas[20];

  float nota;
  scanf("%f",&notas[0]);

  scanf("%f",&notas[1]);
  qtd_Alunos = 2;
  print_Media(notas,qtd_Alunos);

  float aumento = 4.0;
  ajusta_nota(&notas[0],aumento);

  print_Media(notas,qtd_Alunos);
}

void ajusta_nota(float *nota, float incremento) {
  if (*nota + incremento > 10.0) {
    printf("Não é possível ter nota maior que 10.0\n");
    return;
  }
  *nota += incremento;
}

void print_Media(float *notas,int qtd_Alunos) {
  float media = 0;
  for (int i = 0; i < qtd_Alunos; i++) {
    media += notas[i];
  }
  printf("Media dos alunos: %.2f\n",(media/qtd_Alunos));
}