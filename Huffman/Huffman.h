#ifndef HUFFMAN_H
#define HUFFMAN_H


#include "Huffman.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BITS_PER_BYTE 8

// Funções para manipulação de bits
void printByteAsBits(unsigned char byte);
void printStringAsBitArray(const char *str);
void add_bits(const char *nova_string, char **buffer_bits);
void printStringBits(char *buffer_bits);
char *converter_para_bytes(char *buffer_bits);

// Estrutura Hash para armazenar os caracteres, frequencias e códigos.
struct frequencia_caracter {
  char caracter;
  int frequencia;
  char* codigo;
};

struct hash{
  int qtd, TABLE_SIZE;
  struct frequencia_caracter **itens;
};

typedef struct hash* Hash;
typedef struct frequencia_caracter* Frequencia;

Hash criaHash(int TABLE_SIZE);
void liberaHash(Hash ha);
Hash monta_tabela_frequencia(char* texto_original);
void printHash(Hash ha);

// Estrutura para a árvore de códigos huffman
struct no_arvore{
  Frequencia info;
  struct no_arvore* esq;
  struct no_arvore* dir;
};
typedef struct no_arvore* NO_Arvore;

NO_Arvore cria_ArvHuffman();
void libera_ArvBin(NO_Arvore raiz);
NO_Arvore montaArvoreHuffman(Hash);

// Lista auxiliar de nós-folha para montar a árvore
struct no_lista{
  NO_Arvore no_arvore_caracter;
  struct no_lista* prox;
};
typedef struct no_lista* NO_Lista;

struct lista{
  NO_Lista inicio;  // Ponteiro para o início da lista
  int tamanho; // Número de elementos na lista
};
typedef struct lista* Lista;

Lista criaLista();
void liberaLista(Lista l);
int insereOrdenado(Lista l, NO_Arvore item);
NO_Lista popItem(Lista l);
void printList(Lista l);

void calcula_codigos_compactacao(NO_Arvore arvore_huffman, char* prefixo);
char* compacta_texto(char * texto_original, Hash tabela_frequencia);
char* descompacta_texto(char * texto_compactado_bits, NO_Arvore arvore_huffman);

#endif //HUFFMAN_H