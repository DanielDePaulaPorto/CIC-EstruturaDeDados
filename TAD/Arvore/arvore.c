#include "arvore.h"

#include <stdio.h>
#include <stdlib.h>

No* busca_folha(No* no_remover);

ArvoreBB* cria_arvore() {
  ArvoreBB* abb = malloc(sizeof(ArvoreBB));
  if (abb == NULL) {
    return NULL;
  }
  abb->raiz = NULL;
  abb->tamanho = 0;
  return abb;
}

void insere_elemento(int valor, ArvoreBB* arvore) {
  No* novoNo = malloc(sizeof(No));
  if (novoNo == NULL) {
    printf("Erro na alocacao de memoria\n");
    return;
  }
  novoNo->valor = valor;
  novoNo->esq = NULL;
  novoNo->dir = NULL;

  if (arvore->tamanho == 0) {
    arvore->raiz = novoNo;
  } else {
    No* pai = arvore->raiz;
    int nao_achei = 1;
    while (nao_achei) {
      if (valor < pai->valor) {
        if (pai->esq == NULL) {
          nao_achei = 0;
          pai->esq = novoNo;
        }
        pai = pai->esq;
      } else{
        if (pai->dir == NULL) {
          nao_achei = 0;
          pai->dir = novoNo;
        }
        pai = pai->dir;
      }
    }
  }
  arvore->tamanho++;
}


void imprime_arvore_pre_order(No* elemento) {
  if (elemento != NULL) {
    printf("%d ", elemento->valor);
    imprime_arvore_pre_order(elemento->esq);
    imprime_arvore_pre_order(elemento->dir);
  }
}
void imprime_arvore_pos_order(No* elemento) {
  if (elemento != NULL) {
    imprime_arvore_pos_order(elemento->esq);
    imprime_arvore_pos_order(elemento->dir);
    printf("%d ", elemento->valor);
  }
}

void imprime_arvore_in_order(No* elemento) {
  if (elemento != NULL) {
    imprime_arvore_in_order(elemento->esq);
    printf("%d ", elemento->valor);
    imprime_arvore_in_order(elemento->dir);
  }
}


int busca_elemento(int valor, ArvoreBB* arvore) {
  No* pai = arvore->raiz;
  while (pai != NULL) {
    if (valor < pai->valor) {
      pai = pai->esq;
    } else if (valor > pai->valor) {
      pai = pai->dir;
    } else {
      return 1;
    }
  }
  return 0;
}
void remove_elemento(int valor, ArvoreBB* arvore) {
  No* pai = arvore->raiz;
  while (pai != NULL) {
    // printf("-> %d",pai->valor);
    if (valor < pai->valor) {
      if (pai->esq != NULL) {
        if (pai->esq->valor == valor) {
          No* no_remover = pai->esq;
          No* no_folha = busca_folha(no_remover);
          if (no_folha != NULL) {
            pai->esq = no_folha;
            no_folha->esq = no_remover->esq;
            no_folha->dir = no_remover->dir;
          } else {
            pai->esq = NULL;
          }
          free(no_remover);
          return;
        }
        pai = pai->esq;
      }
    } else if (valor > pai->valor) {
      if (pai->dir != NULL ) {
        if (pai->dir->valor == valor) {
          No* no_remover = pai->dir;
          // printf("Achamos: %d" , no_remover->valor);
          No* no_folha = busca_folha(no_remover);
          if (no_folha != NULL) {
            pai->dir = no_folha;
            no_folha->esq = no_remover->esq;
            no_folha->dir = no_remover->dir;
          } else {
            pai->dir = NULL;
          }
          free(no_remover);
          return;
        }
        pai = pai->dir;
      }
    } else if (valor == pai->valor) {
      free(pai);
      pai = NULL;
      return;
    }
  }
  arvore->tamanho--;
}

No* busca_folha(No* no_remover) {
  No* pai_no_folha = no_remover;
  // printf("Vamos remover o no %d",no_remover->valor);
  if (no_remover->esq != NULL) {
    //retornar o no mais à direita da sub-arvore da esquera
    No* no_folha = no_remover->esq;
    while (no_folha->dir != NULL) {
      pai_no_folha = no_folha;
      no_folha = no_folha->dir;
    }
    pai_no_folha->esq = no_folha->dir;
    return no_folha;
  } else if (no_remover->dir != NULL) {
    //remover o nó mais à esquerda do nó da direita
    No* no_folha = no_remover->dir;
    while (no_folha->esq != NULL) {
      pai_no_folha = no_folha;
      no_folha = no_folha->esq;
    }
    pai_no_folha->dir = no_folha->esq;
    return no_folha;
  }
  // printf("Vai remover um nó folha!");
  return NULL;
}

void libera_arvore(ArvoreBB* arvore) {


}