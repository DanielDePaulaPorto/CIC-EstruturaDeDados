#include <stdlib.h>
#include <stdio.h>
#include "Pilha.h"

Pilha* Stack(){
  Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));
  pilha->topo = NULL;
  pilha->tamanho = 0;
  return pilha;
}

void push(Pilha* p, int item){
  No* node = (No*) malloc(sizeof(No));
  node->dado = item;
  node->prox = p->topo;
  p->tamanho++;
  p->topo = node;
}

int pop(Pilha* p){
  if(p->tamanho == 0){
    return -1;
  }
  int valor = p->topo->dado;
  No* topoAnterior = p->topo;
  p->topo = p->topo->prox;
  free(topoAnterior);
  p->tamanho--;
  return valor;
}


int peak(Pilha* p){
  if(p->tamanho == 0){
    return -1;
  }
  return p->topo->dado;
}


int isEmpty(Pilha* p){
  if(p->tamanho == 0){
    return 1;
  }
  return 0;
}

void imprimePilha(Pilha* p){
  No* no = p->topo;
  while(no != NULL){
    printf("%d \n", no->dado);
    no = no->prox;
  }
}