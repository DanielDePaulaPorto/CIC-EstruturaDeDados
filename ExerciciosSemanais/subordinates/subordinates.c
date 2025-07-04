#include <stdio.h>
#include <stdlib.h>

#define MAX_N 200001

typedef struct noArvore {
  int valor;
  int qtd_filhos;
  struct noArvore** filhos;
} NoArvore;

NoArvore* funcionarios[MAX_N]; // Acesso rápido por índice (Se não teríamos que percorrer toda a árvore cada vez que for inserir alguém)
int subordinados[MAX_N];       // Resultado final

NoArvore* criaNo(int valor) {
  NoArvore* no = (NoArvore*)malloc(sizeof(NoArvore));
  no->valor = valor;
  no->qtd_filhos = 0;
  no->filhos = NULL;
  return no;
}

void adicionaFilho(NoArvore* pai, NoArvore* filho) {
  pai->filhos = (NoArvore**)realloc(pai->filhos, (pai->qtd_filhos + 1) * sizeof(NoArvore*));
  pai->filhos[pai->qtd_filhos++] = filho;
}

int calculaSubordinados(NoArvore* no) {
  int total = 0;
  for (int i = 0; i < no->qtd_filhos; i++) {
    total += 1 + calculaSubordinados(no->filhos[i]); // +1 para o filho direto
  }
  subordinados[no->valor] = total;
  return total;
}

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    funcionarios[i] = criaNo(i);
  }

  for (int i = 2; i <= n; i++) {
    int chefe;
    scanf("%d", &chefe);
    adicionaFilho(funcionarios[chefe], funcionarios[i]);
  }

  calculaSubordinados(funcionarios[1]);

  for (int i = 1; i <= n; i++) {
    printf("%d ", subordinados[i]);
  }
  printf("\n");

  return 0;
}