#ifndef ARVORE_H
#define ARVORE_H

typedef struct no {
  int valor;
  struct no* esq;
  struct no* dir;
}No;

typedef struct arvore {
  No* raiz;
  int tamanho;
}ArvoreBB;

ArvoreBB* cria_arvore();
void insere_elemento(int valor, ArvoreBB* arvore);
void imprime_arvore_pre_order(No* elemento);
void imprime_arvore_pos_order(No* elemento);
void imprime_arvore_in_order(No* elemento);
int busca_elemento(int valor, ArvoreBB* arvore);
void remove_elemento(int valor, ArvoreBB* arvore);
void libera_arvore(ArvoreBB* arvore);

#endif //ARVORE_H
