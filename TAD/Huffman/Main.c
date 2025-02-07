# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "Huffman.h"


char *le_texto_original(void) {
    return "ABRACADABRA!";
}

int main(){

    char *buffer_bits = calloc(1, sizeof(char));
    char *texto_original = le_texto_original();

    printf("%s\n", texto_original);
    printStringAsBitArray(texto_original);

    Hash tabela_frequencia = monta_tabela_frequencia(texto_original);
    // printHash(tabela_frequencia);

    NO_Arvore arvore_huffman = montaArvoreHuffman(tabela_frequencia);
    calcula_codigos_compactacao(arvore_huffman,"");

    // printHash(tabela_frequencia);

    char *texto_compactado_bits = compacta_texto(texto_original, tabela_frequencia);
    printStringBits(texto_compactado_bits);
    char* texto_compactado = converter_para_bytes(texto_compactado_bits);
    printf("%s\n", texto_compactado);

    char* texto_DEscompactado = descompacta_texto(texto_compactado_bits, arvore_huffman);
    printf("%s\n", texto_DEscompactado);

    printf("fim");

    liberaHash(tabela_frequencia);
    libera_ArvBin(arvore_huffman);
}
