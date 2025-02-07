#include "Huffman.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



#define BITS_PER_BYTE 8
#define HUFFMAN_TABLE_SIZE 127

void printByteAsBits(unsigned char byte) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (byte >> i) & 1);
    }
}

void printStringAsBitArray(const char *str) {
    int tamanho = strlen(str);
    for (int i = 0; i < tamanho; i++) {
        printByteAsBits(str[i]);
        printf(" ");
    }
    printf("\n%d bits\n\n",tamanho*8);
}

void add_bits(const char *nova_string, char **buffer_bits) {
    int buffer_size = strlen(*buffer_bits) + strlen(nova_string);
    *buffer_bits = realloc(*buffer_bits, buffer_size + 1);
    if (!*buffer_bits) {
        perror("Erro ao alocar memória");
        exit(1);
    }
    strcat(*buffer_bits, nova_string);  // Concatena a nova string ao buffer
}

void printStringBits(char *buffer_bits) {
    int tamanho = strlen(buffer_bits);
    for (int i = 0; i < tamanho; i++) {
        printf("%c", buffer_bits[i] );
        if (i % BITS_PER_BYTE == BITS_PER_BYTE - 1) {
            printf(" ");
        }
    }
    printf("\n%d bits\n\n",tamanho);
}

char *converter_para_bytes(char *buffer_bits) {
    int num_bytes = (strlen(buffer_bits) + BITS_PER_BYTE - 1) / BITS_PER_BYTE;
    char *byte_array = calloc(num_bytes, sizeof(char));

    if (!byte_array) {
        perror("Erro ao alocar memória");
        exit(1);
    }

    // Percorre o buffer de bits e converte para bytes
    for (int i = 0; i < strlen(buffer_bits); i++) {
        if (buffer_bits[i] == '1') { //Só armazenamos os bits 1. Os zeros já estão lá por causa do calloc.
            int byte_pos = i / BITS_PER_BYTE; //Posição do byte para inserir o bit
            int bit_pos = 7 - (i % BITS_PER_BYTE); //Posição do bit dentro do byte
            byte_array[byte_pos] |= (1 << bit_pos); //Cria uma máscara onde apenas o bit desejado está ativado.
            //Depois aplica essa máscara ao byte correspondente, ativando o bit sem alterar os outros.
        }
    }
    return byte_array;
}



Hash criaHash(int TABLE_SIZE){
    Hash ha = (Hash) malloc(sizeof(struct hash));
    if(ha != NULL){
        int i;
        ha->TABLE_SIZE = TABLE_SIZE;
        ha->itens = (Frequencia) malloc(TABLE_SIZE * sizeof(struct frequencia_caracter));
        if(ha->itens == NULL){
            free(ha);
            return NULL;
        }
        ha->qtd = 0;
        for(i=0; i < ha->TABLE_SIZE; i++)
            ha->itens[i] = NULL;
    }
    return ha;
}

void liberaHash(Hash ha){
    if(ha != NULL){
        int i;
        for(i=0; i < ha->TABLE_SIZE; i++){
            if(ha->itens[i] != NULL) {
                Frequencia freq = ha->itens[i];
                if(freq != NULL) {
                    free(freq->codigo);
                    freq->codigo = NULL;
                }
                free(ha->itens[i]);
            }
        }
        free(ha->itens);
        free(ha);
    }
}

//==============================================

int chaveCaracter(const char chave, int TABLE_SIZE){
    int inteiro = chave-'!';
    int posicao = inteiro % TABLE_SIZE;
    return posicao;
}

int insereHash_SemColisao(Hash ha, Frequencia fc){
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE)
        return 0;

    int pos = chaveCaracter(fc->caracter,ha->TABLE_SIZE);

    // printf("Caracter: %c - Posicao: %d\n", fc->caracter,pos);

    ha->itens[pos] = fc;
    ha->qtd++;
    return 1;
}

int buscaHash_SemColisao(Hash ha, char caracter, Frequencia *fc){
    if(ha == NULL)
        return 0;

    int pos = chaveCaracter(caracter,ha->TABLE_SIZE);
    if(ha->itens[pos] == NULL)
        return 0;
    *fc = ha->itens[pos];
    return 1;
}

void printHash(Hash ha) {
    int tamanho = HUFFMAN_TABLE_SIZE;
    for(int i = 0; i < tamanho; i++) {
        if(ha->itens[i] != NULL) {
            Frequencia letra=ha->itens[i];
            printf("%c: %d - %s\n", letra->caracter,letra->frequencia,letra->codigo);
        } else {
            // printf("ha->itens[%d] = NULL\n",i);
        }
    }
}

Hash monta_tabela_frequencia(char* texto_original) {
    int tamanho = strlen(texto_original);
    Hash ha = criaHash(HUFFMAN_TABLE_SIZE);
    if(ha == NULL) {
        return NULL;
    }

    for(int i = 0; i < tamanho; i++) {
        char caracter = texto_original[i];
        Frequencia fc;

        if (buscaHash_SemColisao(ha, caracter,&fc)) {
            fc->frequencia +=1;
        } else {
            fc = (Frequencia) malloc(sizeof(struct frequencia_caracter));
            fc->caracter = caracter;
            fc->frequencia = 1;
            insereHash_SemColisao(ha,fc);
        }

    }
    return ha;
}

NO_Arvore cria_ArvHuffman(){
    NO_Arvore raiz = (NO_Arvore) malloc(sizeof(struct no_arvore));
    if(raiz != NULL)
        raiz->info = NULL;
        raiz->esq = NULL;
        raiz->dir = NULL;
    return raiz;
}


void libera_NO(NO_Arvore no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);

    free(no);
}

void libera_ArvBin(NO_Arvore raiz){
    if(raiz == NULL)
        return;
    libera_NO(raiz);//libera cada no
}

NO_Arvore montaArvoreHuffman(Hash tabela_frequancia) {
    Lista lista_frequencia_caracteres = criaLista();

    for (int i = 0; i < HUFFMAN_TABLE_SIZE; ++i) {
        if (tabela_frequancia->itens[i] != NULL) {
            NO_Arvore no_arvore_novo = (NO_Arvore) calloc(1,sizeof(struct no_arvore));
            no_arvore_novo->info = tabela_frequancia->itens[i];
            no_arvore_novo->dir = NULL;
            no_arvore_novo->esq = NULL;
            insereOrdenado(lista_frequencia_caracteres, no_arvore_novo);
        }
    }

    // printList(lista_frequencia_caracteres);

    while(lista_frequencia_caracteres->tamanho > 1) {
        NO_Lista item1 = popItem(lista_frequencia_caracteres);
        NO_Lista item2 = popItem(lista_frequencia_caracteres);

        // Cria um novo nó que será pai desses dois itens
        Frequencia pai = (Frequencia) malloc(sizeof(struct frequencia_caracter));
        pai->frequencia = item1->no_arvore_caracter->info->frequencia + item2->no_arvore_caracter->info->frequencia;
        pai->caracter = ' ';

        NO_Arvore no_arvore_novo = (NO_Arvore) malloc(sizeof(struct no_arvore));
        no_arvore_novo->info = pai;
        no_arvore_novo->dir = item2->no_arvore_caracter;
        no_arvore_novo->esq = item1->no_arvore_caracter;

        insereOrdenado(lista_frequencia_caracteres, no_arvore_novo);

        // printList(lista_frequencia_caracteres);
    }
    return lista_frequencia_caracteres->inicio->no_arvore_caracter;
}

Lista criaLista() {
    Lista l = (Lista) malloc(sizeof(struct lista));
    l->inicio = NULL;
    l->tamanho = 0;
    return l;
}

void liberaLista(Lista l) {
    if (l == NULL) return;

    NO_Lista atual = l->inicio;
    while (atual != NULL) {
        NO_Lista temp = atual;
        atual = atual->prox;

        free(temp);
    }

    free(l);
}

int insereOrdenado(Lista l, NO_Arvore item) {
    NO_Lista novo = (NO_Lista) malloc(sizeof(struct no_lista));
    if(novo == NULL)
        return 0;

    novo->no_arvore_caracter = item;
    novo->prox = NULL;

    l->tamanho++;

    if (l->tamanho == 1){
        l->inicio = novo;
        return 1;
    }

    NO_Lista atual = l->inicio;
    NO_Lista proximo = atual->prox;

    if(atual->no_arvore_caracter->info->frequencia > item->info->frequencia) {
        novo->prox = atual;
        l->inicio = novo;
        return 1;
    }

    while (proximo != NULL){
        if (proximo->no_arvore_caracter->info->frequencia >= item->info->frequencia){
            atual->prox = novo;
            novo->prox = proximo;
            return 1;
        }
        atual = proximo;
        proximo = atual->prox;
    }
    atual->prox = novo;
}
NO_Lista popItem(Lista l){
    NO_Lista primeiro = l->inicio;
    l->inicio = l->inicio->prox;
    l->tamanho--;
    return primeiro;
}

void printList(Lista l) {
    printf("Lista:\n");
    NO_Lista no_lista =l->inicio;
    for(int i = 0; i < l->tamanho; i++) {
        char letra = no_lista->no_arvore_caracter->info->caracter;
        int freq = no_lista->no_arvore_caracter->info->frequencia;
        printf("%c - %d\tesq:%d dir:%d\n",letra,freq,no_lista->no_arvore_caracter->esq,no_lista->no_arvore_caracter->dir);
        no_lista = no_lista->prox;
    }
    printf("--\n\n");
}


void calcula_codigos_compactacao(NO_Arvore arvore_huffman, char* prefixo) {
    if(arvore_huffman == NULL)
        return;

    int tamanho_prefixo = strlen(prefixo);
    char* prefixo_codigo = malloc(tamanho_prefixo+ 1);
    strcpy(prefixo_codigo, prefixo);

    if (arvore_huffman->esq != NULL && arvore_huffman->dir != NULL) {
        prefixo_codigo[tamanho_prefixo] = '0';
        prefixo_codigo[tamanho_prefixo+1] = '\0';
        calcula_codigos_compactacao(arvore_huffman->esq, prefixo_codigo);
        prefixo_codigo[tamanho_prefixo] = '1';
        calcula_codigos_compactacao(arvore_huffman->dir, prefixo_codigo);
    } else {
        arvore_huffman->info->codigo = prefixo_codigo;
        // printf("Letra: %c - %s - %d\n",arvore_huffman->info->caracter,arvore_huffman->info->codigo,arvore_huffman->info);
    }
}

char* compacta_texto(char * texto_original, Hash tabela_frequencia) {
    char *buffer_bits = calloc(1, sizeof(char));
    buffer_bits[0] = '\0';

    Frequencia fc = (Frequencia) malloc(sizeof(struct frequencia_caracter));
    for(int i = 0; i < strlen(texto_original); i++) {
        buscaHash_SemColisao(tabela_frequencia, texto_original[i], &fc);
        char* codigo = fc->codigo;
        add_bits(codigo, &buffer_bits);
    }
    return buffer_bits;
}


char* descompacta_texto(char * texto_compactado_bits, NO_Arvore arvore_huffman) {
    char* buffer_descompactado_texto = calloc(1, sizeof(char));
    int buffer_size = 0;
    NO_Arvore no_arvore_caracter = arvore_huffman;
    for(int i = 0; i < strlen(texto_compactado_bits); i++) {
        if (no_arvore_caracter->esq == NULL || no_arvore_caracter->dir == NULL) { //Descompactamos uma letra
            buffer_size++;
            buffer_descompactado_texto = realloc(buffer_descompactado_texto, buffer_size);
            if (!buffer_descompactado_texto) {
                perror("Erro ao alocar memória");
                exit(1);
            }
            strcat(buffer_descompactado_texto, &(no_arvore_caracter->info->caracter));  // Concatena a nova string ao buffer
            no_arvore_caracter = arvore_huffman;
        }
        if(texto_compactado_bits[i] == '0') {
            no_arvore_caracter = no_arvore_caracter->esq;
        }else {
            no_arvore_caracter = no_arvore_caracter->dir;
        }
    }
    return buffer_descompactado_texto;
}